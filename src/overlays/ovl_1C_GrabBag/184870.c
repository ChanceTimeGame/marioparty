#include "GrabBag.h"

extern f32 D_800FB250_GrabBag;


extern s32 D_800FB294_GrabBag;


f32 func_800FA780_GrabBag(f32 arg0, f32 arg1, f32 arg2, f32 arg3);



extern s32 D_800FB104_GrabBag[4];
extern s32 D_800FB254_GrabBag;
extern s32 D_800FB290_GrabBag;
f32 func_800F97E8_GrabBag(omObjData*, omObjData*);
extern f32 D_800B8960;
extern f32 D_800B8984;
extern u8 D_800F64F8;
extern u16 D_800FB11C_GrabBag[4];
extern u16 D_800FB244_GrabBag[4];
extern u16 D_800FB258_GrabBag[];
extern u16 D_800FB25A_GrabBag[];
extern u16 D_800FB25C_GrabBag[];
extern u8 D_800FB270_GrabBag[];
extern u8 D_800FB278_GrabBag[];
extern omObjData* D_800FB280_GrabBag;
extern u16 ContBtn[4];

void func_800F776C_GrabBag(omObjData*);
void func_800F859C_GrabBag(omObjData*);
void func_800F8984_GrabBag(void);
void func_800F8A18_GrabBag(omObjData*);
void func_800F8BDC_GrabBag(void);
void func_800F903C_GrabBag(omObjData*);
void func_800FA424_GrabBag(omObjData*);
void func_800FAED8_GrabBag(void);
void func_800FAFA0_GrabBag(void);
void func_800FA8F4_GrabBag(omObjData*);
void func_800FB064_GrabBag(s32, s32);

void func_800F7680_GrabBag(void) {
    omObjData* obj;
    s32 i;
    u16 index;

    D_800FB254_GrabBag = rand8() & 3;
    i = 0;
    func_80009500();
    D_800B8960 = 0.2f;
    D_800F2BC0 = 0;
    do {
        obj = omAddObj(2, 11, 50, -1, func_800F776C_GrabBag);
        index = D_800F2BC0;
        D_800F2BC0 = index + 1;
        D_800F3FB0[index] = obj;
        omSetStatBit(D_800F3FB0[i], 0xA0);
        i++;
    } while (i < 4);
    omAddObj(2, 0, 0, -1, func_800FA8F4_GrabBag);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F776C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F7EDC_GrabBag);

void func_800F8484_GrabBag(omObjData* arg0) {
    GrabBagPlayerWork* work;

    work = arg0->unk_50;
    func_800FA424_GrabBag(arg0);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        if (D_800ED430 == 0) {
            func_800FAFA0_GrabBag();
            func_800F859C_GrabBag(arg0);
            return;
        }
        if ((u32)(D_800ED430 - 2) < 2U) {
            func_800FAFA0_GrabBag();
            func_800F8984_GrabBag();
            if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
                func_800F8A18_GrabBag(arg0);
            }
            work->speed = 0.0f;
            func_80005A28(arg0);
            return;
        }
        if (D_800ED430 == 1) {
            func_800FB064_GrabBag(work->player, work->score);
            func_800FAED8_GrabBag();
            func_800F903C_GrabBag(arg0);
            if (work->port == 3) {
                func_800F8BDC_GrabBag();
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F859C_GrabBag);

// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800F8984_GrabBag(void) {
    s32 i;
    s32 gained;
    s32 even;
    GrabBagPlayerWork* work;

    gained = 0;
    even = 0;
    for (i = 0; i < 4; i++) {
        work = GB_PLAYER(D_800F3FB0[i]);
        if (work->score - work->start_score > 0) {
            gained++;
        } else {
            even += work->score == work->start_score;
        }
    }
    if (gained == 1) {
        D_800FB290_GrabBag = 0;
    } else if (even == 4) {
        D_800FB290_GrabBag = 2;
    } else {
        D_800FB290_GrabBag = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8984_GrabBag);
#endif
// scheduling: retail keeps the second angle store out of the delay slot (2 instructions)
#ifdef NON_MATCHING
void func_800F8A18_GrabBag(omObjData* arg0) {
    GrabBagPlayerWork* work;
    s16 coins;

    work = GB_PLAYER(arg0);
    func_800258EC(D_800EDE70[D_800FB294_GrabBag]->model[0], 4, 4);
    func_800258EC(D_800EDE70[D_800FB294_GrabBag]->model[1], 4, 4);
    if (work->unk_F1 == 0) {
        coins = work->score - work->start_score;
        GwPlayer[work->player].coins_mg = coins;
        work->unk_F1 = 1;
    }
    if (arg0->trans.y <= 3.0f) {
        if (D_800FB290_GrabBag == 2) {
            work->angle = 0.0f;
            if (_CheckFlag(0x2B) == 0) {
                func_800184BC(arg0, 0xE);
            } else {
                func_800184BC(arg0, 0);
            }
        } else if (work->start_total < work->total) {
            work->angle = 0.0f;
            if (_CheckFlag(0x2B) == 0) {
                func_800184BC(arg0, 0xD);
            } else {
                func_800184BC(arg0, 0);
            }
        } else {
            work->angle = 0.0f;
            if (work->start_total > work->total) {
                if (_CheckFlag(0x2B) == 0) {
                    func_800184BC(arg0, 0xE);
                } else {
                    func_800184BC(arg0, 0);
                }
            } else {
                func_800184BC(arg0, 0);
            }
        }
        func_80017DB0(arg0);
        return;
    }
    arg0->trans.y -= 25.0f;
    if (arg0->trans.y < 3.0f) {
        arg0->trans.y = 3.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8A18_GrabBag);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8BDC_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F903C_GrabBag);

void func_800F975C_GrabBag(GrabBagPlayerWork* arg0, s32 arg1) {
    s32 first_offset;
    s32 second_offset;
    s32 pad[6];

    first_offset = arg0->port * 2;
    *(u16*)((u8*)D_800FB244_GrabBag + first_offset) =
        *(u16*)((u8*)ContBtn + first_offset) & ~*(u16*)((u8*)D_800FB11C_GrabBag + first_offset);
    second_offset = arg0->port * 2;
    *(u16*)((u8*)D_800FB11C_GrabBag + second_offset) = *(u16*)((u8*)ContBtn + second_offset);
    if (*(u16*)((u8*)D_800FB244_GrabBag + (arg0->port * 2)) & arg1) {
        arg0->button_press_count++;
    }
}

f32 func_800F97E8_GrabBag(omObjData* arg0, omObjData* arg1) {
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f0;
    GrabBagPlayerWork* work;

    work = arg0->unk_50;
    temp_f20 = work->radius + work->radius_offset;
    temp_f22 = (func_800AEAC0(work->angle) * temp_f20) + arg0->trans.x;
    temp_f24 = arg0->trans.y;
    temp_f0 = (func_800AEFD0(work->angle) * temp_f20) + arg0->trans.z;
    temp_f12 = arg1->trans.x - temp_f22;
    temp_f2 = arg1->trans.y - temp_f24;
    temp_f4 = arg1->trans.z - temp_f0;
    return func_800B1750((temp_f12 * temp_f12) + (temp_f2 * temp_f2) + (temp_f4 * temp_f4));
}

f32 func_800F98A4_GrabBag(omObjData* arg0) {
    f32 targetX;
    f32 targetZ;
    f32 angle;
    f32 diff;
    GrabBagPlayerWork* self;
    u8 best;
    s32 i;
    omObjData* obj;
    GrabBagPlayerWork* work;

    targetZ = 0.0f;
    targetX = 0.0f;
    self = GB_PLAYER(arg0);
    best = 0;
    for (i = 0; i < 4; i++) {
        obj = D_800F3FB0[i];
        work = GB_PLAYER(obj);
        if (arg0 == obj) {
            continue;
        }
        if (work->unk_E9 != 0) {
            continue;
        }
        if (best < work->total) {
            best = work->total;
            targetX = obj->trans.x - func_800AEAC0(work->angle) * 60.0f;
            targetZ = obj->trans.z - func_800AEFD0(work->angle) * 60.0f;
        }
    }
    angle = func_800FA780_GrabBag(self->angle, targetX - arg0->trans.x, targetZ - arg0->trans.z, 15.0f);
    diff = angle - work->angle;
    if (diff > 150.0f) {
        if (diff < 210.0f) {
            angle += 45.0f;
        }
    }
    return angle;
}
// register allocation: float temporaries (masked 0)
#ifdef NON_MATCHING
f32 func_800F9A1C_GrabBag(omObjData* arg0) {
    f32 targetZ;
    f32 targetX;
    f32 best;
    f32 dist;
    f32 dz;
    f32 dx;
    f32 angle;
    f32 diff;
    GrabBagPlayerWork* self;
    s32 i;
    omObjData* obj;
    GrabBagPlayerWork* work;

    targetZ = 0.0f;
    targetX = 0.0f;
    self = GB_PLAYER(arg0);
    best = 128000.0f;
    for (i = 0; i < 4; i++) {
        obj = D_800F3FB0[i];
        work = GB_PLAYER(obj);
        if (arg0 != obj && work->unk_E9 == 0) {
            dx = arg0->trans.x - obj->trans.x;
            dz = arg0->trans.z - obj->trans.z;
            dist = dx * dx + dz * dz;
            if (dist < best) {
                best = dist;
                targetX = obj->trans.x - func_800AEAC0(work->angle) * 60.0f;
                targetZ = obj->trans.z - func_800AEFD0(work->angle) * 60.0f;
            }
        }
    }
    angle = func_800FA780_GrabBag(self->angle, targetX - arg0->trans.x, targetZ - arg0->trans.z, 15.0f);
    diff = angle - work->angle;
    if (diff > 150.0f) {
        if (diff < 210.0f) {
            angle += 45.0f;
        }
    }
    return -angle;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9A1C_GrabBag);
#endif
void func_800F9BC4_GrabBag(omObjData* arg0, omObjData* arg1) {
    GrabBagPlayerWork* work0;
    GrabBagPlayerWork* work1;
    f32 dot;
    s32 btn;

    work0 = GB_PLAYER(arg0);
    work1 = GB_PLAYER(arg1);
    if (work0->unk_ED == 1 || work1->unk_ED == 1) {
        work0->unk_50 |= 0x200;
        work1->unk_50 |= 0x200;
        return;
    }
    dot = func_8000A72C(func_800AEAC0(work0->angle), func_800AEFD0(work0->angle), func_800AEAC0(work1->angle),
                        func_800AEFD0(work1->angle));
    if (((func_800F97E8_GrabBag(arg0, arg1) < work0->radius + work0->radius_offset + 25.0f) & (dot > -0.75f)) &&
        !(work0->unk_5C & 0x20) && !(work1->unk_5C & 0x20) && work0->unk_EA == -1 && work1->unk_EA == work0->unk_EA) {
        if (work0->unk_EF == 0 && work1->unk_EF == 0) {
            btn = ContBtnTrg[work0->port];
            /* Separate tests: GCC would merge them into (btn & 0xC000) == 0x4000. */
            if (!(btn & 0x4000)) {
                return;
            }
            if (btn & 0x8000) {
                return;
            }
            work1->unk_ED = 1;
            work0->unk_ED = 1;
            work0->unk_EA = work1->player;
            work1->unk_EA = work0->player;
            work0->unk_EF++;
            work1->unk_EF++;
            work0->unk_E9 = 1;
            work1->unk_E9 = 2;
            work1->unk_FE = 0;
            work0->unk_FE = 0;
        }
    } else {
        work1->unk_E9 = 0;
        work0->unk_E9 = 0;
        work1->unk_EA = -1;
        work0->unk_EA = -1;
        work1->unk_EF = 0;
        work0->unk_EF = 0;
    }
}
void func_800F9DF0_GrabBag(omObjData* arg0, omObjData* arg1) {
    f32 dx;
    f32 dz;
    f32 base_z;
    f32 distance_sq;
    f32 threshold_sq;
    GrabBagPlayerWork* work0;
    GrabBagPlayerWork* work1;

    work0 = arg0->unk_50;
    work1 = arg1->unk_50;
    func_800AEAC0(work1->angle);
    func_800AEFD0(work1->angle);
    base_z = arg0->trans.z;
    dx = arg1->trans.x - arg0->trans.x;
    dz = arg1->trans.z - base_z;
    distance_sq = (dx * dx) + (dz * dz);
    threshold_sq = D_800B8984 * D_800B8984;
    if (threshold_sq < distance_sq) {
        work1->angle = func_800B0CD8(dx, dz);
        work1->speed = -D_800B8984;
    }
    work1->unk_38 = 1000.0f;
    work0->unk_38 = 1000.0f;
    func_80025798(arg1->model[0], arg1->trans.x, 3.0f, arg1->trans.z);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9ED0_GrabBag);

// control flow: GCC if-converts the ±1 returns (masked 39)
#ifdef NON_MATCHING
s32 func_800FA184_GrabBag(omObjData* arg0, omObjData* arg1) {
    GrabBagPlayerWork* work0;
    GrabBagPlayerWork* work1;

    work0 = GB_PLAYER(arg0);
    work1 = GB_PLAYER(arg1);
    if (work1->total <= 0) {
        return -1;
    }
    if (work0->unk_E8 == -1) {
        if (GwPlayer[work0->player].cpu_difficulty == 0) {
            if (rand8() >> 6) {
                return -1;
            }
            return 1;
        }
        if (GwPlayer[work0->player].cpu_difficulty == 1) {
            if (rand8() >> 7) {
                return -1;
            }
            return 1;
        }
        if (GwPlayer[work0->player].cpu_difficulty == 2) {
            if ((u32)(rand8() * 5) >> 7 < 8) {
                return 1;
            }
            return -1;
        }
        if (GwPlayer[work0->player].cpu_difficulty == 3) {
            if ((rand8() * 255) >> 8 < 0xFE) {
                return 1;
            }
            return -1;
        }
    }
    /* Retail returns 1 either way. */
    if (work0->button_press_count < work1->button_press_count) {
        return 1;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA184_GrabBag);
#endif
// register allocation: bag/model-table base registers (masked 6)
#ifdef NON_MATCHING
u8 func_800FA304_GrabBag(omObjData* arg0, omObjData* arg1) {
    GrabBagPlayerWork* work0;
    GrabBagPlayerWork* work1;
    u8 kind;
    s32 amount;

    work0 = GB_PLAYER(arg0);
    work1 = GB_PLAYER(arg1);
    kind = 0;
    if (work1->total >= 5) {
        if ((u8)(rand8() % 10) < 4) {
            amount = 1;
        } else {
            kind = 1;
            amount = 5;
        }
    } else {
        amount = 1;
    }
    work0->score = amount + work0->score;
    work1->score -= amount;
    work0->total = amount + work0->total;
    work1->total -= amount;
    if (!(D_800F2B7C[D_800EDE70[kind]->model[0]].unk_20 & 4) || GB_BAG(D_800EDE70[kind])->unk_5C != 0) {
        kind += 3;
    }
    return kind;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA304_GrabBag);
#endif
void func_800FA424_GrabBag(omObjData* arg0) {
    GrabBagPlayerWork* work;

    work = GB_PLAYER(arg0);
    if (work->unk_EC == 1 && D_800ED430 == work->unk_EC && work->unk_EF != 0 &&
        (work->total == 0 || work->total == 1 || work->total == 4 || work->total == 8 || work->total == 12 ||
         work->total == 16 || work->total == 20)) {
        if (func_8005FD5C() + D_800F64F8 == 0) {
            D_800FB250_GrabBag = func_800AEAC0(work->unk_EF * 10);
        }
        if (D_800FB250_GrabBag < 0.0f) {
            D_800FB250_GrabBag = -D_800FB250_GrabBag;
        }
    } else if (work->total <= 0) {
        D_800FB250_GrabBag = 1.0f;
    } else if (work->total >= 20) {
        D_800FB250_GrabBag = 0.0f;
    } else if (work->total >= 16) {
        D_800FB250_GrabBag = 0.2f;
    } else if (work->total >= 12) {
        D_800FB250_GrabBag = 0.4f;
    } else if (work->total >= 8) {
        D_800FB250_GrabBag = 0.6f;
    } else if (work->total >= 4) {
        D_800FB250_GrabBag = 0.7f;
    } else if (work->total >= 2) {
        D_800FB250_GrabBag = 0.8f;
    } else if (work->total == 1) {
        D_800FB250_GrabBag = 0.9f;
    }
    func_80026174(arg0->model[9], arg0->model[10], D_800FB250_GrabBag);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA658_GrabBag);

// float register allocation at the shared return (masked 3)
#ifdef NON_MATCHING
f32 func_800FA780_GrabBag(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 target;
    f32 diff;

    target = func_800B0CD8(arg1, arg2);
    diff = target - arg0;
    if ((-arg3 < diff) & (diff < arg3)) {
        return target;
    }
    if (diff <= -180.0f) {
        return arg0 + arg3;
    }
    if ((diff <= 180.0f) & (diff >= 0.0f)) {
        return arg0 + arg3;
    }
    if (diff > 180.0f) {
        return arg0 - arg3;
    }
    if ((diff > -180.0f) & (diff < 0.0f)) {
        return arg0 - arg3;
    }
    return target;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA780_GrabBag);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA8F4_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FAC0C_GrabBag);

void func_800FAED8_GrabBag(void) {
    s32 sprite_offset;
    PB_PTR32 player_offset;
    s32 i;
    u16 sprite;
    u8* fourth_sprites;
    u8* fifth_sprites;

    D_800FB280_GrabBag->work[1] = 1;
    i = 0;
    fourth_sprites = D_800FB270_GrabBag;
    fifth_sprites = D_800FB278_GrabBag;
    for (; i < 4; i++) {
        player_offset = i << 1;
        sprite_offset = (player_offset + i) * 2;
        sprite = *(u16*)((u8*)D_800FB258_GrabBag + sprite_offset);
        ShowBasicSprite(sprite);
        ShowBasicSprite(*(u16*)((u8*)D_800FB25A_GrabBag + sprite_offset));
        ShowBasicSprite(*(u16*)((u8*)D_800FB25C_GrabBag + sprite_offset));
        ShowBasicSprite(*(u16*)(player_offset + (PB_PTR32)fourth_sprites));
        player_offset += (PB_PTR32)fifth_sprites;
        ShowBasicSprite(*(u16*)player_offset);
    }
}

void func_800FAFA0_GrabBag(void) {
    s32 sprite_offset;
    PB_PTR32 player_offset;
    s32 i;
    u16 sprite;
    u8* fourth_sprites;
    u8* fifth_sprites;

    D_800FB280_GrabBag->work[1] = 0;
    i = 0;
    fourth_sprites = D_800FB270_GrabBag;
    fifth_sprites = D_800FB278_GrabBag;
    for (; i < 4; i++) {
        player_offset = i << 1;
        sprite_offset = (player_offset + i) * 2;
        sprite = *(u16*)((u8*)D_800FB258_GrabBag + sprite_offset);
        func_80018C90(sprite);
        func_80018C90(*(u16*)((u8*)D_800FB25A_GrabBag + sprite_offset));
        func_80018C90(*(u16*)((u8*)D_800FB25C_GrabBag + sprite_offset));
        func_80018C90(*(u16*)(player_offset + (PB_PTR32)fourth_sprites));
        player_offset += (PB_PTR32)fifth_sprites;
        func_80018C90(*(u16*)player_offset);
    }
}

void func_800FB064_GrabBag(s32 arg0, s32 arg1) {
    arg1 = arg1 < 0 ? 0 : arg1;
    if (arg1 >= 1000) {
        arg1 = 999;
    }
    D_800FB104_GrabBag[arg0] = arg1;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", D_800FB1F8_GrabBag);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", D_800FB208_GrabBag);
