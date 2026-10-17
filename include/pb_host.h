#ifndef PB_HOST_H
#define PB_HOST_H

/*
 * PartyBoard host-port types (https://github.com/Taylor8484/partyboard4, games/mp1).
 *
 * Every type here expands to the exact original N64 type when TARGET_PC is undefined, so the
 * matching build is unchanged by construction. On the host (TARGET_PC, LP64/LLP64) they widen
 * integers that the game uses to hold addresses.
 *
 *   PB_PTR32   s32 on N64, intptr_t on the host: a signed 32-bit integer that holds a pointer.
 *   PB_UPTR32  u32 on N64, uintptr_t on the host: the unsigned counterpart.
 *   PB_ROM_ADDR(a)  host only: a ROM offset that the N64 links as a symbol (see below).
 *   PB_N64_ADDR(T, a)  an N64 address kept as data that the host never dereferences (the
 *              overlay segment table): ((T)(a)) on N64, through uintptr_t on the host.
 *   PB_N64_RAM(a, s)  a fixed N64 RAM region the game uses as a buffer (heaps at 0x80120000...):
 *              (void *)(a) on N64; on the host a zeroed block of PB_N64_RAM_SIZE(s) = 2 * s bytes
 *              (host structures are wider), the same block for the same address every time.
 *   PB_HOSTCAST(T, x)  ((T)(x)) on the host, (x) on N64: a conversion the N64 code performs
 *              implicitly (an int passed where a pointer is expected, or back), made explicit
 *              for the host only.
 */

#include "PR/ultratypes.h"

#ifdef TARGET_PC
/* The C library the game calls without prototypes on the N64 (sprintf, bcopy, strlen, sinf...).
 * Included here, ahead of PR/os.h, which #undefs the CRT's errno macro for its struct fields. */
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* libultra's libc (os_libc.h); the host build provides them where the C library does not. */
void bcopy(const void *src, void *dst, size_t len);
void bzero(void *dst, size_t len);
int bcmp(const void *a, const void *b, size_t len);
/* Host (games/mp1/host, host_main.c): stops the run on an unrecoverable error and parks the
 * calling game thread; mp1.dll then returns to the PartyBoard host instead of ending the process. */
void pb_layer_fatal(const char *what);
typedef intptr_t PB_PTR32;
typedef uintptr_t PB_UPTR32;
#if defined(_MSC_VER) && !defined(__clang__)
/* MSVC has no GNU attributes; the decomp uses aligned(4) on GW_PLAYER only, which x86-64 does
 * not need for correctness. */
#define __attribute__(x)
#endif
#define PB_HOSTCAST(T, x) ((T)(x))
/* A ROM offset the N64 links as a symbol address (an Addr label in undefined_syms.txt or
   ld_addrs.h): an lvalue of type Addr at that numeric address, so &sym and its decay give the
   offset, as on the N64. Never dereferenced: ROM reads go through PI DMA. */
#define PB_ROM_ADDR(a) (*(u8 (*)[])(uintptr_t)(a))
#define PB_N64_ADDR(T, a) ((T)(uintptr_t)(a))
void *pb_n64_ram(u32 addr, u32 size); /* host runtime (games/mp1/host/src/host_data.c) */
void pb_ovl_load(s32 index);          /* host overlay loader (games/mp1/host/src/host_ovl.c) */
#define PB_N64_RAM(a, s) pb_n64_ram((u32)(a), (u32)(s))
/* Graphics-bridge memory provenance (games/mp1/host/src/host_gfxmem.c): a decoded file is raw
   N64-format data, a CPU-built image holds native u16 texels; a freed heap block forgets both. */
void pb_gfx_raw(const void *p, size_t n);
void pb_gfx_native16(const void *p, size_t n);
void pb_gfx_forget(const void *p);
/* Development overrides (games/mp1/host/src/host_ovl.c; mp1host --dev-built-minigames and
   --dev-turns N): whether minigame index mg (GwSystem.unk_1E numbering) may be picked, and a new
   game's turn count (-1: the game's own). */
int pb_dev_minigame_allowed(s32 mg);
int pb_dev_minigame_forced(void); /* --dev-minigame: one minigame overlay only */
s32 pb_dev_minigame_type(s32 mg); /* 1 = 1v3, 2 = 2v2, 0 = other (src/43760.c) */
void pb_dev_minigame_teams(s32 type); /* teams of that shape for a forced minigame */
s32 pb_dev_turns(void);
s32 pb_dev_board(void); /* --dev-board N: the board a new game uses (GwSystem.curBoardIndex), or -1 */
s32 pb_dev_overworld(void); /* --dev-overworld N: the overworld's first selection (0 Adventure ... 5 Mini-Game Island), or -1 */
s32 pb_widescreen(void); /* config.json video.aspectRatio "expand" (RT64 widens the 3D view) */
/* --autoplay: nonzero makes events that steer a human with the stick (Chance Time walks under
   each block) drive player 1 with the game's own CPU logic, as autoplay presses buttons only. */
int pb_autoplay_steer(void);
/* Frame interpolation (games/mp1/host/src/host_interp.c): nonzero when a 2D sprite should be
   drawn as a quad under a matrix instead of texture rectangles, which RT64 cannot interpolate.
   The host answers yes for sprites that moved or scaled since they were last drawn while frame
   interpolation is on (mp1host --sprite-quad overrides). */
int pb_sprite_quad(const void *sprite, s32 x, s32 y, f32 scaleX, f32 scaleY, s32 box0, s32 box1);
int pb_sprite_quad_budget(void); /* nonzero: size the quad buffer for every sprite (65770.c) */
/* Nonzero while frame interpolation is on: func_8001D658 (1DE40.c) moves a camera's viewport
   offset into its projection, because the boards scroll by moving the viewport and RT64 cannot
   interpolate a viewport (mp1host --interp-viewport overrides). */
int pb_interp_fold_viewport(void);
#define PB_N64_RAM_SIZE(s) ((s) * 2)
/* The depth buffer at N64 RAM 0x803D0800 (320 x 240 x 16 bits, up to the RSP buffers at
   0x803F6000); display lists name it by its physical address 0x3D0800. */
#define PB_N64_ZBUFFER PB_N64_RAM(0x803D0800, 0x25800)
/* Big-endian ROM data read into host memory: swap in place after the DMA. Host only; the N64
   code paths never call these. */
static inline u32 pb_bswap32(u32 x) { return (x >> 24) | ((x >> 8) & 0xFF00) | ((x << 8) & 0xFF0000) | (x << 24); }
static inline u16 pb_bswap16(u16 x) { return (u16)((x >> 8) | (x << 8)); }
static inline void pb_swap32_array(void *p, size_t n) { u32 *w = (u32 *)p; while (n--) { *w = pb_bswap32(*w); w++; } }
static inline void pb_swap16_array(void *p, size_t n) { u16 *h = (u16 *)p; while (n--) { *h = pb_bswap16(*h); h++; } }
#else
typedef s32 PB_PTR32;
typedef u32 PB_UPTR32;
#define PB_HOSTCAST(T, x) (x)
#define PB_N64_ADDR(T, a) ((T)(a))
#define PB_N64_RAM(a, s) ((void *)(a))
#define PB_N64_RAM_SIZE(s) (s)
#endif

#endif /* PB_HOST_H */
