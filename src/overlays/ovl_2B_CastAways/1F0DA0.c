#include "CastAways.h"

/* Lets the fishing line sag: lowers every sample by drop and clamps it to the water or rod line. */


extern u16 D_800FBA06_CastAways;
extern u16 D_800FBA08_CastAways;


extern u8 D_800FBA0C_CastAways[][3];
extern u8 D_800FBA18_CastAways[][3];




extern u8 D_800F64F8;
extern char D_800FBA64_CastAways[];
extern char D_800FBA70_CastAways[];
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);

void func_800F65E0_CastAways(void) {
    s32 i;
    void* filePtr;

    omInitObjMan(0x35, 0);
    func_80060088();
    func_80029090(1);
    func_8001DE70(0x64);
    func_8002890C(0x21, 0x42, 0xD6);
    func_800178A0(1);
    D_800FBB80_ovl2B.x = 0;
    D_800FBB80_ovl2B.y = 3072.0f;
    D_800FBB80_ovl2B.z = -200.0f;
    D_800FBB70_ovl2B.x = 0;
    D_800FBB70_ovl2B.y = 0;
    D_800FBB70_ovl2B.z = -300.0f;
    D_800FBB9C_ovl2B[0].x = 0;
    D_800FBB9C_ovl2B[0].y = 1.0f;
    D_800FBB9C_ovl2B[0].z = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &func_800FB884_CastAways), 0xA0);
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, -100.0f, 100.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, -100.0f, 100.0f, 100.0f);
    func_8005D98C(0, 0xA);
    func_8005D98C(1, 0xC);
    func_8005D98C(2, 0xA);
    func_8005D98C(4, 4);
    omAddObj(0x64, 0, 0, -1, &func_800F7014_CastAways);
    omAddObj(0, 0, 0, -1, &func_800F704C_CastAways);
    omSetStatBit(omAddObj(4, 4, 0, -1, &func_800F71AC_CastAways), 0xA0);
    D_800FBB48_ovl2B[0] = omAddObj(6, 0, 0, -1, &func_800F761C_CastAways);
    D_800FBB48_ovl2B[1] = omAddObj(6, 0, 0, -1, &func_800F7650_CastAways);
    D_800FBB48_ovl2B[2] = omAddObj(6, 0, 0, -1, &func_800F7684_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8AAC_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8AC8_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8AE4_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8B00_CastAways);
    omAddObj(0x2710, 0, 0, -1, &func_800FACA8_CastAways);

    for (i = 0; i < 2; i++) {
        filePtr = DataRead(D_800FB9A4_ovl2B[i]);
        D_800FBB04_ovl2B[i] = func_80039084(filePtr);
        HuMemDirectFree(filePtr);
    }

    D_800FBB46_ovl2B = LoadFormFile(0x35, 0x2009D);
    filePtr = DataRead(0x2A);
    D_800FBB40_ovl2B = func_80039084(filePtr);
    HuMemDirectFree(filePtr);
    filePtr = DataRead(0x25);
    D_800FBB42_ovl2B = func_80039084(filePtr);
    HuMemDirectFree(filePtr);
    filePtr = DataRead(0x24);
    D_800FBB44_ovl2B = func_80039084(filePtr);
    HuMemDirectFree(filePtr);
    D_800FBB50_ovl2B[3] = _CheckFlag(0x2B);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FBB98_ovl2B = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F6A24_CastAways);

void func_800F7014_CastAways(void) {
    s32 i;
    for (i = 0; i < D_800F3778_ovl2B; i++) {}
}

void func_800F704C_CastAways(omObjData* arg0) {
    D_800FBB78_ovl2B[2] = 0;
    D_800FBB58_ovl2B = 60;
    D_800FBB5A_ovl2B = 30;
    D_800FBB64_ovl2B = D_800FBB68_ovl2B = 0.0f;
    D_800FBB50_ovl2B[2] = 0;
    D_800FBB6C_ovl2B = PlaySound(0x1AA);
    arg0->func_ptr = &func_800F70C4_CastAways;
}

void func_800F70C4_CastAways(void) {
    func_80079078(D_800FBB58_ovl2B);
    switch (D_800FBB78_ovl2B[2]) {
    case 0:
        func_800FA198_CastAways();
        return;
    case 1:
        D_800FBB5A_ovl2B--;
        if (D_800FBB5A_ovl2B == 0) {
            D_800FBB58_ovl2B--;
            D_800FBB5A_ovl2B = 30;
        }
        if (D_800FBB58_ovl2B == 0) {
            D_800FBB78_ovl2B[2] = 2;
            D_800FBB8C_ovl2B = 0;
            func_800601D4(40);
            return;
        }
        return;
    case 2:
        func_800FA410_CastAways();
        break;
    }
}

void func_800F71AC_CastAways(omObjData* arg0) {
    s16 sprite;

    sprite = InitSprite(0x3F0002);
    D_800FBB5C_ovl2B = sprite;
    D_800FBB5E_ovl2B = func_80019060(sprite, 0, 1);
    func_80018D44(D_800FBB5E_ovl2B, 0x4008);
    SetBasicSpritePos(D_800FBB5E_ovl2B, 0xA0, 0x82);
    ShowBasicSprite(D_800FBB5E_ovl2B);
    SetBasicSpriteSize(D_800FBB5E_ovl2B, 2.0f, 2.0f);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    arg0->model[0] = LoadFormFile(0x3F0000, 0x499);
    arg0->model[3] = func_800174C0(0x3F0001, 0x1499);
    func_80039C48(D_800FBA64_CastAways, &D_800FBB60_CastAways);
    func_80026040(arg0->model[3]);
    arg0->func_ptr = &func_800F7308_CastAways;
}

void func_800F7308_CastAways(omObjData* arg0) {
    if (((func_8005FD5C() & 0xFFFF) + D_800F64F8) == 0) {
        D_800FBB64_ovl2B += 0.4f;
    }
    func_80027E48(arg0->model[3], D_800FBB64_ovl2B, D_800FBB68_ovl2B,
        D_800FBB60_CastAways.unk_00, D_800FBB60_CastAways.unk_02,
        D_800FBA70_CastAways, 1);
}

// scheduling: the result store and one index multiply are ordered differently (masked 6)
#ifdef NON_MATCHING
void func_800F73AC_CastAways(omObjData* arg0, s32 arg1) {
    CastAwaysItemSet* set;
    unk_800ECDE0* sprite;
    s16 id;
    s32 i;

    arg0->unk_50 = set = func_80023684(sizeof(CastAwaysItemSet), 0x7918);
    set->id = arg1;
    set->interval = D_800FB960_CastAways[(u16)arg1].interval;
    set->count = D_800FB960_CastAways[(u16)arg1].count;
    set->speed = D_800FB960_CastAways[(u16)arg1].speed;
    set->spawned = 0;
    set->timer = rand8() % 20;
    set->x = D_800FB960_CastAways[(u16)arg1].x;
    set->y = -25.0f;
    set->z = D_800FB960_CastAways[(u16)arg1].z;
    set->angle = 0;
    for (i = 0; i < set->count; i++) {
        id = func_8001E00C((void*)-1, 0x68D, 8);
        sprite = D_800ECDE0 + id;
        sprite->unk_02 = D_800FBB04_ovl2B[0];
        func_80025930(sprite->unk_00, 0x40000000, 0x40000000);
        set->models[0][i] = D_800ECDE0[id].unk_00;
        set->spriteIds[i] = id;
        set->slots[0][i] = 0;
    }
    for (i = 0; i < set->count; i++) {
        set->models[2][i] = func_80023FC8(D_800FBB46_ovl2B);
        set->slots[2][i] = 0;
        func_80025830(set->models[2][i], 1.5f, 1.5f, 1.5f);
        func_80025EB4(set->models[2][i], 1, 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F73AC_CastAways);
#endif
s32 func_800F75BC_CastAways(CastAwaysItemSet* arg0, s32 arg1) {
    s32 slotIndex;
    s32 pad[1]; // Original function has an otherwise-unused 8-byte stack frame.

    for (slotIndex = 0; slotIndex < arg0->count; slotIndex++) {
        u8* slots = (u8*)(((arg1 & 0xFF) * 8) + (PB_UPTR32)arg0 + 0x66);
        if (slots[slotIndex] == 0) {
            slots[slotIndex] = 1;
            return (s16)slotIndex;
        }
    }
    return -1;
}

void func_800F761C_CastAways(omObjData* arg0) {
    func_800F73AC_CastAways(arg0, 0);
    arg0->func_ptr = &func_800F76B8_CastAways;
}

void func_800F7650_CastAways(omObjData* arg0) {
    func_800F73AC_CastAways(arg0, 1);
    arg0->func_ptr = &func_800F76B8_CastAways;
}

void func_800F7684_CastAways(omObjData* arg0) {
    func_800F73AC_CastAways(arg0, 2);
    arg0->func_ptr = &func_800F76B8_CastAways;
}

// register allocation and block order of the switch arms
#ifdef NON_MATCHING
void func_800F76B8_CastAways(omObjData* arg0) {
    CastAwaysItemSet* set;
    omObjData* fish;
    CastAwaysFishWork* work;
    s16 type;
    s16 slot;
    f32 angle;

    if (D_800FBB7C_ovl2B != 2) {
        set = arg0->unk_50;
        if (set->timer == 0) {
            if (set->spawned != set->count) {
                set->timer = (u8)(rand8() % 20) + set->interval;
                fish = omAddObj(0xC, 1, 0, set->id, &func_800F7A38_CastAways);
                work = func_80023684(sizeof(CastAwaysFishWork), 0x7918);
                fish->unk_50 = work;
                type = func_800FABE4_CastAways(set->id);
                switch (type) {
                case 0:
                    slot = func_800F75BC_CastAways(set, 0);
                    D_800ECDE0[set->spriteIds[slot]].unk_02 = D_800FBB04_CastAways;
                    func_8001E268(set->spriteIds[slot], 1, 0);
                    func_8001E2A8(set->spriteIds[slot], 0);
                    fish->model[0] = set->models[0][slot];
                    omSetTra(fish, set->x, func_800AEAC0(set->angle) + set->y, set->z);
                    omSetSca(fish, 4.0f, 4.0f, 4.0f);
                    break;
                case 1:
                    slot = func_800F75BC_CastAways(set, 0);
                    D_800ECDE0[set->spriteIds[slot]].unk_02 = D_800FBB06_CastAways;
                    func_8001E268(set->spriteIds[slot], 1, 0);
                    func_8001E2A8(set->spriteIds[slot], 0);
                    fish->model[0] = set->models[0][slot];
                    omSetTra(fish, set->x, func_800AEAC0(set->angle) + set->y, set->z);
                    omSetSca(fish, 4.0f, 4.0f, 4.0f);
                    break;
                case 2:
                    slot = func_800F75BC_CastAways(set, type);
                    fish->model[0] = set->models[type][slot];
                    omSetTra(fish, set->x, func_800AEAC0(set->angle) + set->y + 30.0f, set->z + -150.0f);
                    omSetSca(fish, 1.5f, 1.5f, 1.5f);
                    break;
                }
                func_800258EC(fish->model[0], 4, 0);
                work->state = 0;
                work->type = type;
                work->slot = slot;
                work->set = set;
                work->speed = set->speed;
                work->angle = set->angle;
                set->spawned++;
            }
        } else {
            set->timer--;
        }
        angle = set->angle + 45.0f;
        set->angle = angle;
        if (angle >= 360.0f) {
            set->angle = angle - 360.0f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F76B8_CastAways);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F7A38_CastAways);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F8194_CastAways);

void func_800F8AAC_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 0);
}

void func_800F8AC8_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 1);
}

void func_800F8AE4_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 2);
}

void func_800F8B00_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 3);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F8B1C_CastAways);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F92FC_CastAways);

void func_800F9E2C_CastAways(omObjData* arg0, CastAwaysPlayerWork* arg1, CastAwaysRodWork* arg2) {
    u16 timer = arg2->timer - 1;

    arg2->timer = timer;
    if (!(timer & 0xFFFF)) {
        arg2->timer = 3;
        arg1->sampleCount++;
    }
    arg1->samples[arg1->sampleCount].x = arg0->trans.x;
    arg1->samples[arg1->sampleCount].y = arg0->trans.y;
    arg1->samples[arg1->sampleCount].z = arg0->trans.z;
}

// float register allocation only
#ifdef NON_MATCHING
void func_800F9EAC_CastAways(CastAwaysPlayerWork* arg0, f32 drop) {
    f32 k = 0.6f;
    s32 i;
    s32 clamped;
    u16 j;
    f32 surface;
    f32 limit;
    f32 slope;

    clamped = 0;
    for (i = 1; i < arg0->sampleCount; i++) {
        arg0->samples[i].y -= drop;
        if (i == 4) {
            if (arg0->samples[4].y < 0.0f) {
                arg0->samples[4].y = 0.0f;
                clamped++;
            }
        } else if (i >= 5) {
            surface = arg0->samples[4].y;
            if (0.0f < surface) {
                surface = 0.0f;
            }
            if ((arg0->samples[arg0->sampleCount].y == 0.0f) & (surface == 0.0f)) {
                limit = 0.0f;
            } else {
                slope = (surface - arg0->samples[arg0->sampleCount].y)
                      / (arg0->samples[arg0->sampleCount].z - arg0->samples[4].z);
                limit = fabs(arg0->samples[4].z - arg0->samples[i].z) * slope;
            }
            if (arg0->samples[i].y <= limit && arg0->samples[i].y <= 0.0f) {
                arg0->samples[i].y = limit;
                clamped++;
            }
        } else {
            j = 3;
            if (arg0->sampleCount < 3) {
                j = arg0->sampleCount;
            }
            if (i > 0) {
                if (arg0->sampleCount >= 4) {
                    limit = k * arg0->samples[0].y;
                    k -= 0.25f - (f32)i * 0.01f;
                    if (arg0->samples[i].y < limit) {
                        arg0->samples[i].y = limit;
                        clamped++;
                    }
                } else {
                    slope = (arg0->samples[0].y - arg0->samples[j].y) / (arg0->samples[0].z - arg0->samples[j].z);
                    k -= 0.25f - (f32)i * 0.01f;
                    if (arg0->samples[i].y < slope * arg0->samples[i].z) {
                        arg0->samples[i].y = slope * (arg0->samples[i].z - arg0->samples[0].z) + arg0->samples[0].y;
                        clamped++;
                    }
                }
            }
        }
    }
    if ((u16)clamped == arg0->sampleCount - 1 && arg0->sampleCount != 1) {
        arg0->castState = 4;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F9EAC_CastAways);
#endif
// rodata order (C floats) and register allocation
#ifdef NON_MATCHING
void func_800FA198_CastAways(void) {
    Vec3f pos;
    Vec2f scr;

    switch (D_800FBB98_ovl2B) {
    case 0:
        pos.x = 0;
        pos.y = 0;
        pos.z = -2300.0f;
        Convert3DTo2D(0, &pos, &scr);
        SetBasicSpritePos(D_800FBB5E_ovl2B, 0xA0, (s32)((scr.y + 120.0f + 10.0f) - 68.0f));
        if (D_800FBA06_CastAways >= 0x1F) {
            D_800FBB80_ovl2B.z += 44.533333f;
            D_800FBB70_ovl2B.z += 19.88889f;
        } else {
            D_800FBB80_ovl2B.x += 0.0f;
            D_800FBB80_ovl2B.y += -81.7f;
            D_800FBB80_ovl2B.z += -6.6666665f;
            D_800FBB70_ovl2B.x += 0.0f;
            D_800FBB70_ovl2B.y += 0.0f;
            D_800FBB70_ovl2B.z += -6.6666665f;
        }
        if (--D_800FBA06_CastAways == 0) {
            D_800FBB98_ovl2B = 2;
            func_8006071C(D_800FBB6C_ovl2B);
        }
        break;
    case 2:
        if (func_80072718() == 0) {
            D_800FBB98_ovl2B = 3;
            GMesCreate(0);
        }
        break;
    case 3:
        if (GMesStatAllGet() == 0) {
            D_800FBB7C_ovl2B = 1;
            GMesCreate(8, D_800FBB58_ovl2B, 0xA0, 0x20);
        }
        break;
    }
    if (D_800FBA08_CastAways == 0) {
        func_80060128(0x19);
        return;
    }
    D_800FBA08_CastAways--;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800FA198_CastAways);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800FA410_CastAways);

// register allocation: retail keeps a u16 copy of the weight (masked 2)
#ifdef NON_MATCHING
s16 func_800FABE4_CastAways(u16 arg0) {
    u16 r;
    u16 i;
    u8 w;

    r = (u8)(rand8() % 10);
    for (i = 0; i < 3; i++) {
        w = D_800FBA0C_CastAways[arg0][i];
        if (r < w) {
            break;
        }
        r -= w;
    }
    return D_800FBA18_CastAways[arg0][i];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800FABE4_CastAways);
#endif
void func_800FACA8_CastAways(void) {
    if ((D_800FB9E0_CastAways[2] != 0) || (D_800F5144 != 0)) {
        func_800FB5B4_CastAways(131);
        func_800601D4(40);
    }
}

s32 func_800FACEC_CastAways(CastAwaysPlayerWork* arg0) {
    if (arg0->power == 0) {
        return -1;
    }
    if (arg0->power < 0x22) {
        return 0;
    }
    
    if (arg0->power < 0x39) {
        return 1;
    } else {
        return 2;
    }
}

extern f32 D_800FBA24_CastAways[];

// retail shares one clamp block between the two direction tests (masked 29)
#ifdef NON_MATCHING
void func_800FAD2C_CastAways(omObjData* arg0) {
    CastAwaysPlayerWork* work;
    CastAwaysLureWork* lure;
    s16 prev;
    s16 type;
    s16 dir;
    f32 frame;
    f32 target;

    work = arg0->unk_50;
    prev = work->fishType;
    if (prev == -1) {
        type = func_800FACEC_CastAways(work);
        work->fishType = type;
        if (type != prev) {
            func_800FB668_CastAways(arg0, arg0->model[0], work->animDataA, 0.0f, 1.0f, 2, 0xE);
            func_80025BB8(arg0->model[3], arg0->motion[0xB]);
            func_80025EB4(arg0->model[3], 1, 1);
            work->unk_14C = 1;
        }
    } else {
        type = func_800FACEC_CastAways(work);
        lure = work->lureObj->unk_50;
        if (work->fishType != type) {
            if (D_800FBA24_CastAways[type] < lure->frame) {
                work->unk_14C = -1;
            } else if (lure->frame < D_800FBA24_CastAways[type]) {
                work->unk_14C = 1;
            } else {
                work->unk_14C = 0;
            }
            work->unk_14E = 0;
            work->fishType = type;
        }
        lure->frame = (f32)work->unk_14C + lure->frame;
        dir = work->unk_14C;
        frame = func_80025D18(arg0->model[3]) + (f32)dir;
        if (dir > 0) {
            target = D_800FBA24_CastAways[work->fishType];
            if (target <= lure->frame) {
                lure->frame = target;
                work->unk_14C = 0;
                work->unk_14E = 1;
            }
        } else {
            target = D_800FBA24_CastAways[work->fishType];
            if (lure->frame <= target) {
                lure->frame = target;
                work->unk_14C = 0;
                work->unk_14E = 1;
            }
        }
        func_80025CA8(arg0->model[3], frame);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800FAD2C_CastAways);
#endif
