#include "engine/process.h"

#ifdef TARGET_PC
/*
 * PartyBoard host: processes are libco fibers. The N64 switches with its own setjmp/longjmp on a
 * stack carved from the process heap (prc_jump = {sp, func = the ra slot, saved registers}); that
 * cannot run on the host. Each process gets a fiber instead, and every longjmp of the original
 * becomes a switch with the same value, so HuPrcCall below is the N64 loop with the same order,
 * sleep/watch/kill rules and frees. Switches go through the ultra layer (ultra_fiber_switch) so a
 * process that blocks in libultra (osRecvMesg) is resumed in its own fiber.
 *
 * - Stack: the fiber owns it (malloc), 2 x the request + PRC_HOST_STACK_EXTRA, as MP5's process.c
 *   (CLAUDE.md "Architecture and linking"): host frames are larger and the process also runs host
 *   code the N64 never ran (the C library, the runtime layers). The process heap holds only the
 *   Process and its extra data, so base_sp and prc_jump are unused here.
 * - Guard: libco keeps the fiber context at the bottom of the block and the stack grows down toward
 *   it, so a band above the context is filled with PRC_GUARD_BYTE and checked every time the
 *   process gives control back and when it is freed. An overflow is reported through
 *   HuPrcHostGuardHook (tests) or stderr and abort().
 * - Kill: the N64 sets prc_jump.func = HuPrcEnd and longjmps, so HuPrcEnd runs on the process's
 *   stack where it last stopped (or at the start of one that never ran). Here the scheduler sets
 *   `end` and switches in; the process side calls HuPrcEnd on its own fiber, and its destructor
 *   runs there as on the N64.
 * - Return: the N64 longjmp enters func with ra = func (the jmp_buf has no other ra slot), so a
 *   process function that returns runs again from the top on the same stack; prc_entry loops the
 *   same way (MP5's GameCube process.c relies on the same behaviour).
 * - Retail quirk kept: HuPrcChildKill does not clear the children's `relative`, so when a killed
 *   parent ends before its children (it is earlier in the list), each child's HuPrcChildUnlink
 *   writes into the parent's freed heap. The host uses the same game heap, which leaves freed
 *   contents in place, so it behaves as on the N64.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libco.h"
#include "ultra_host.h"

#define PRC_HOST_STACK_EXTRA 0x20000
#define PRC_GUARD_OFFSET 1024u
#define PRC_GUARD_SIZE 1024u
#define PRC_GUARD_BYTE 0xA5u

typedef struct PbPrcHost {
    UltraFiber fiber;
    u8* mem;
    u32 size;
    process_func func;
    s32 end; /* the scheduler's longjmp with prc_jump.func = HuPrcEnd */
} PbPrcHost;

/* Called instead of abort() when a process fiber has written its guard band (tests). */
void (*HuPrcHostGuardHook)(Process* process);

static UltraFiber prc_sched; /* HuPrcCall's context: the N64 process_jmp_buf */
static s32 prc_ret;          /* the value of longjmp(&process_jmp_buf, v) */

void HuPrcEnd(void);

static void prc_check_guard(Process* process) {
    PbPrcHost* host = process->host;
    u32 i;

    for (i = 0; i < PRC_GUARD_SIZE; i++) {
        if (host->mem[PRC_GUARD_OFFSET + i] != PRC_GUARD_BYTE) {
            memset(host->mem + PRC_GUARD_OFFSET, PRC_GUARD_BYTE, PRC_GUARD_SIZE);
            if (HuPrcHostGuardHook != NULL) {
                HuPrcHostGuardHook(process);
                return;
            }
            fprintf(stderr, "process: fiber stack overflow (process %p, host stack %u bytes)\n",
                    (void*)process, (unsigned)host->size);
            abort();
        }
    }
}

/* longjmp(&process_jmp_buf, val) from the running process. Returns when the scheduler switches
   back in (the N64 setjmp returning nonzero), and runs HuPrcEnd there if it was killed. */
static void prc_yield(s32 val, s32 dying) {
    PbPrcHost* host = processcur->host;

    prc_ret = val;
    ultra_fiber_switch(&host->fiber, &prc_sched, dying);
    if (host->end) {
        host->end = 0;
        HuPrcEnd();
    }
}

static void prc_entry(void) {
    PbPrcHost* host = processcur->host;

    ultra_fiber_started(&prc_sched);
    if (host->end) {
        host->end = 0;
        HuPrcEnd();
    }
    while (1) {
        host->func();
    }
}

/* longjmp(&process->prc_jump, 1) from the scheduler; returns the process's longjmp value. */
static s32 prc_run(Process* process) {
    PbPrcHost* host = process->host;

    prc_ret = 0;
    ultra_fiber_switch(&prc_sched, &host->fiber, 0);
    prc_check_guard(process);
    return prc_ret;
}

/* Tests: the guard band of a process's fiber. */
u8* HuPrcHostStackGuard(Process* process, u32* size) {
    *size = PRC_GUARD_SIZE;
    return ((PbPrcHost*)process->host)->mem + PRC_GUARD_OFFSET;
}

static void prc_free_fiber(Process* process) {
    PbPrcHost* host = process->host;

    prc_check_guard(process);
    free(host->mem);
    free(host);
    process->host = NULL;
}
#endif

void HuPrcInit(void) {
    processcnt = 0; //processcnt
    processtop = NULL;
}

#ifdef TARGET_PC
/* PartyBoard host: when a run ends (the host unloads mp1.dll), frees the fiber of every process
 * still alive; their Process blocks are in the game heap, which the host frees with it. */
void HuPrcHostReleaseAll(void) {
    Process* process;

    for (process = processtop; process != NULL; process = process->next) {
        PbPrcHost* host = process->host;
        if (host != NULL) {
            free(host->mem);
            free(host);
            process->host = NULL;
        }
    }
    processtop = NULL;
    processcnt = 0;
}
#endif

void HuLinkProcess(Process** root, Process* process) {
    Process* src_process = *root;

    if (src_process != NULL && (src_process->priority >= process->priority)) {
        while (src_process->next != NULL) {
            if (src_process->next->priority < process->priority) {
                break;
            }
            src_process = src_process->next;
        }

        process->next = src_process->next;
        process->youngest_child = src_process;
        src_process->next = process;
        if (process->next) {
            process->next->youngest_child = process;
        }
    } else {
        process->next = (*root);
        process->youngest_child = NULL;
        *root = process;
        if (src_process != NULL) {
            src_process->youngest_child = process;
        }
    }
}

void HuUnlinkPrc(Process **root, Process *process) {
    if (process->next) {
        process->next->youngest_child = process->youngest_child;
    }

    if (process->youngest_child) {
        process->youngest_child->next = process->next;
    }

    else {
        *root = process->next;
    }
}

Process* HuPrcCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size) {
    HeapNode* process_heap;
    Process* process;
    s32 alloc_size;

    if (stack_size == 0) {
        stack_size = 2048;
    }

#ifdef TARGET_PC
    PbPrcHost* host;
    u32 host_size;

    alloc_size = HuMemMemoryAllocSizeGet(sizeof(Process))
        + HuMemMemoryAllocSizeGet(extra_data_size);
#else
    alloc_size = HuMemMemoryAllocSizeGet(sizeof(Process))
        + HuMemMemoryAllocSizeGet(stack_size)
        + HuMemMemoryAllocSizeGet(extra_data_size);
#endif

    process_heap = (HeapNode*)HuMemDirectMalloc(alloc_size);

    if (process_heap == NULL) {
        return NULL;
    }

#ifdef TARGET_PC
    host_size = ((u32)stack_size * 2 + PRC_HOST_STACK_EXTRA + 15) & ~15u;
    host = (PbPrcHost*)calloc(1, sizeof(PbPrcHost));
    if (host != NULL) {
        host->mem = (u8*)malloc(host_size);
    }
    if (host == NULL || host->mem == NULL) {
        free(host);
        HuMemDirectFree(process_heap);
        return NULL;
    }
    memset(host->mem + PRC_GUARD_OFFSET, PRC_GUARD_BYTE, PRC_GUARD_SIZE);
    host->size = host_size;
    host->func = func;
    host->fiber.co = co_derive(host->mem, host_size, prc_entry);
    host->fiber.stack = host->mem;
    host->fiber.size = host_size;
#endif

    HuMemHeapInit(process_heap, alloc_size);

    process = (Process*)HuMemMemoryAlloc(process_heap, sizeof(Process));
    process->heap = process_heap;
    process->exec_mode = EXEC_PROCESS_DEFAULT;
    process->stat = 0;
    process->priority = priority;
    process->sleep_time = 0;
#ifdef TARGET_PC
    process->host = host;
    process->base_sp = NULL;
    process->prc_jump.func = func;
    process->prc_jump.sp = NULL;
#else
    process->base_sp = HuMemMemoryAlloc(process_heap, stack_size) + stack_size - 8;
    process->prc_jump.func = func;
    process->prc_jump.sp = process->base_sp;
#endif
    process->destructor = NULL;
    process->user_data = NULL;
    process->dtor_idx = 0;
    HuLinkProcess(&processtop, process);
    process->oldest_child = NULL;
    process->relative = NULL;
    processcnt++;
    return process;
}

void HuPrcChildLink(Process* process, Process* child) {
    HuPrcChildUnlink(child);

    if (process->oldest_child) {
        process->oldest_child->new_process = child;
    }

    child->parent_oldest_child = process->oldest_child;
    child->new_process = NULL;
    process->oldest_child = child;
    child->relative = process;
}

void HuPrcChildUnlink(Process* process) {
    if (process->relative) {
        if (process->parent_oldest_child) {
            process->parent_oldest_child->new_process = process->new_process;
        }

        if (process->new_process) {
            process->new_process->parent_oldest_child = process->parent_oldest_child;
        } else {
            process->relative->oldest_child = process->parent_oldest_child;
        }

        process->relative = NULL;
    }
}

Process* HuPrcChildCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, Process* parent) {
    Process* child = HuPrcCreate(func, priority, stack_size, extra_data_size);
    HuPrcChildLink(parent, child);
    return child;
}

void HuPrcChildWatch(void) {
    Process* process = HuPrcCurrentGet();
    if (process->oldest_child) {
        process->exec_mode = EXEC_PROCESS_WATCH;
        
#ifdef TARGET_PC
        prc_yield(1, 0);
#else
        if (!setjmp(&process->prc_jump)) {
            longjmp(&process_jmp_buf, 1);
        }
#endif
    }
}

Process* HuPrcCurrentGet(void) {
    return processcur;
}

Process* GetChildProcess(Process* process) {
    Process* curr_child = process->oldest_child;

    while(curr_child) {
        curr_child = curr_child->parent_oldest_child;
    }

    return curr_child;
}

s32 SetKillStatusProcess(Process* process) {
    if (process->exec_mode != EXEC_PROCESS_DEAD) {
        HuPrcWakeup(process);
        process->exec_mode = EXEC_PROCESS_DEAD;
        return 0;
    } else {
        return -1;
    }
}

s32 HuPrcKill(Process* process) {
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    return SetKillStatusProcess(process);
}

void HuPrcChildKill(Process* process) {
    Process* curr_child = process->oldest_child;

    while (curr_child != NULL) {
        if (curr_child->oldest_child != NULL) {
            HuPrcChildKill(curr_child);
        }

        SetKillStatusProcess(curr_child);

        curr_child = curr_child->parent_oldest_child;
    }

    process->oldest_child = NULL;
}

void HuPrcTerminate(Process* process) {
    if (process->destructor) {
        process->destructor();
    }

    HuUnlinkPrc(&processtop, process);
    processcnt--;
#ifdef TARGET_PC
    prc_yield(2, 1);
#else
    longjmp(&process_jmp_buf, 2);
#endif
}

void HuPrcEnd(void) {
    Process* process = HuPrcCurrentGet();
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    HuPrcTerminate(process);
}

void HuPrcSleep(s32 time) {
    Process* process = HuPrcCurrentGet();
    if (time != 0 && process->exec_mode != EXEC_PROCESS_DEAD) {
        process->exec_mode = EXEC_PROCESS_SLEEPING;
        process->sleep_time = time;
    }

#ifdef TARGET_PC
    prc_yield(1, 0);
#else
    if (!setjmp(&process->prc_jump)) {
        longjmp(&process_jmp_buf, 1);
    }
#endif
}

void HuPrcVSleep(void) {
    HuPrcSleep(0);
}

void HuPrcWakeup(Process* process) {
    process->sleep_time = 0;
}

void HuPrcDestructorSet2(Process* process, process_func destructor) {
    process->destructor = destructor;
}

void HuPrcDestructorSet(process_func destructor) {
    Process* process = HuPrcCurrentGet();
    HuPrcDestructorSet2(process, destructor);
}

#ifdef TARGET_PC
void HuPrcCall(s32 time) {
    Process* cur_proc_local;
    s32 ret;

    processcur = processtop;
    ret = 0;
    while (1) {
        switch (ret) {
            case 2: {
                /* The N64 reads ->next from the Process after freeing the heap that holds it (its
                   heap leaves the contents); take it first. */
                Process* dead = processcur;
                Process* next = dead->next;

                prc_free_fiber(dead);
                HuMemDirectFree(dead->heap);
                processcur = next;
                break;
            }
            case 1:
                processcur = processcur->next;
                break;
        }

        cur_proc_local = processcur;

        if (cur_proc_local == 0) {
            break;
        }
         
        if ((cur_proc_local->stat & 0x1)) {
            if (cur_proc_local->exec_mode != 3) {
                ret = 1;
                continue;
            }
        }

        switch (cur_proc_local->exec_mode) {
            case EXEC_PROCESS_SLEEPING:
                if (cur_proc_local->sleep_time > 0 && (cur_proc_local->sleep_time -= time) <= 0) {
                    cur_proc_local->sleep_time = 0;
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                }

                ret = 1;
                break;

            case EXEC_PROCESS_WATCH:
                if (cur_proc_local->oldest_child != 0) {
                    ret = 1;
                } else {
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                    ret = 0;
                }

                break;

            case EXEC_PROCESS_DEAD:
                cur_proc_local->prc_jump.func = HuPrcEnd;
                ((PbPrcHost*)cur_proc_local->host)->end = 1;

            case 0:
                ret = prc_run(cur_proc_local);
                break;
        }
    }
}

#else
void HuPrcCall(s32 time) {
    Process* cur_proc_local;
    s32 ret;

    processcur = processtop;
    ret = setjmp(&process_jmp_buf);
    while (1) {
        switch (ret) {
            case 2:
                HuMemDirectFree(processcur->heap);
                processcur = processcur->next;
                break;
            case 1:
                processcur = processcur->next;
                break;
        }

        cur_proc_local = processcur;

        if (cur_proc_local == 0) {
            break;
        }
         
        if ((cur_proc_local->stat & 0x1)) {
            if (cur_proc_local->exec_mode != 3) {
                ret = 1;
                continue;
            }
        }

        switch (cur_proc_local->exec_mode) {
            case EXEC_PROCESS_SLEEPING:
                if (cur_proc_local->sleep_time > 0 && (cur_proc_local->sleep_time -= time) <= 0) {
                    cur_proc_local->sleep_time = 0;
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                }

                ret = 1;
                break;

            case EXEC_PROCESS_WATCH:
                if (cur_proc_local->oldest_child != 0) {
                    ret = 1;
                } else {
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                    ret = 0;
                }

                break;

            case EXEC_PROCESS_DEAD:
                cur_proc_local->prc_jump.func = HuPrcEnd;

            case 0:
                longjmp(&cur_proc_local->prc_jump, 1);
                break;
        }
    }
}

#endif

void* HuPrcMemAlloc(s32 size) {
    Process* process = HuPrcCurrentGet();
    return (void*)HuMemMemoryAlloc((HeapNode*)process->heap, size);
}

void HuPrcMemFree(void* ptr) {
    HuMemMemoryFree(ptr);
}