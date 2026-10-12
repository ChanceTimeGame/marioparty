#include "GrabBag.h"

extern u16 D_800B89A4[][14];
extern u8 D_800FB0C0_GrabBag;
extern s8 D_800FB114_GrabBag;
extern s8 D_800FB115_GrabBag;
extern s8 D_800FB118_GrabBag[4];
extern u32 D_800FB240_GrabBag;


extern GrabBagBagWork* D_800FB24C_GrabBag;


void func_800FAC0C_GrabBag(omObjData*);
void func_80018E0C(u16, s16);


extern s32 D_800FB104_GrabBag[4];
extern f32 D_800FB250_GrabBag;
extern s32 D_800FB254_GrabBag;
extern s32 D_800FB290_GrabBag;
extern s32 D_800FB294_GrabBag;
extern f32 D_800B8960;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern u8 D_800F64F8;
extern u16 D_800FB11C_GrabBag[4];
extern u16 D_800FB244_GrabBag[4];
extern u16 D_800FB258_GrabBag[4][3]; /* score digit sprites per player */
extern u16 D_800FB270_GrabBag[4];    /* character face sprites */
extern u16 D_800FB278_GrabBag[4];    /* bag icon sprites */
extern GrabBagPos D_800FB0F4_GrabBag[4];
extern omObjData* D_800FB280_GrabBag;
extern u16 ContBtn[4];
extern s8 ContStkY[4];

void func_800F776C_GrabBag(omObjData*);
void func_800F859C_GrabBag(omObjData*);
void func_800F8984_GrabBag(void);
void func_800F8A18_GrabBag(omObjData*);
void func_800F8BDC_GrabBag(void);
void func_800F903C_GrabBag(omObjData*);
f32 func_800F97E8_GrabBag(omObjData*, omObjData*);
f32 func_800F98A4_GrabBag(omObjData*);
f32 func_800F9A1C_GrabBag(omObjData*);
s32 func_800FA184_GrabBag(omObjData*, omObjData*);
s32 func_800FA304_GrabBag(omObjData*, omObjData*);
void func_800FA424_GrabBag(omObjData*);
f32 func_800FA780_GrabBag(f32, f32, f32, f32);
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

void func_800F859C_GrabBag(omObjData* arg0) {
    unk_ovl_2D_struct* model;
    GrabBagPlayerWork* work;
    f32 angle;

    model = &D_800F2B7C[arg0->model[0]];
    work = GB_PLAYER(arg0);
    if (D_800FB118_GrabBag[work->player] == 0) {
        func_80060540(D_800B89A4[work->player][1], work->player);
        D_800FB118_GrabBag[work->player] = 1;
    }
    if (D_800FB240_GrabBag % 15 == 0 && !(work->unk_E9 & 8)) {
        D_800FB118_GrabBag[work->player] = 0;
    }
    D_800FB240_GrabBag++;
    if (D_800FB115_GrabBag == 1) {
        arg0->trans.y = 0.0f;
        model->unk_4C = 1.0f;
        return;
    }
    if (arg0->trans.x <= 150.0f && arg0->trans.z >= -150.0f) {
        work->unk_E9 |= 4;
    }
    if (work->unk_E9 & 4) {
        angle = func_800B0CD8(-arg0->trans.x, -arg0->trans.z) + 90.0f;
    } else {
        angle = func_800B0CD8(-arg0->trans.x, -arg0->trans.z);
    }
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    work->angle = angle;
    if (D_800FB0C0_GrabBag == 1) {
        if (!(work->unk_E9 & 8)) {
            work->unk_E9 |= 8;
            work->angle = func_800B0CD8(-arg0->trans.x, -arg0->trans.z);
            model->unk_4C = 0.5f;
            func_800184BC(arg0, 0x1E);
            func_80017DB0(arg0);
        } else {
            goto retreat;
        }
    } else if (!(work->unk_E9 & 8)) {
        arg0->trans.x += func_800AEAC0(work->angle) * 20.0f;
        arg0->trans.z += func_800AEFD0(work->angle) * 20.0f;
        func_800184BC(arg0, 2);
        func_80017DB0(arg0);
    } else {
    retreat:
        arg0->trans.x -= func_800AEAC0(work->angle) * 32.0f;
        arg0->trans.z -= func_800AEFD0(work->angle) * 32.0f;
        if (D_800FB114_GrabBag == 1) {
            arg0->trans.y -= 32.0f;
            if (arg0->trans.y < 0.0f) {
                D_800FB115_GrabBag = 1;
            }
        } else {
            arg0->trans.y += 32.0f;
            if (arg0->trans.y > 128.0f) {
                D_800FB114_GrabBag = 1;
            }
        }
    }
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, work->angle, 0.0f);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[1], arg0->trans.x, 0.0f, arg0->trans.z);
}
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

// register allocation: work0/work1 in s3/s2 (masked 0)
#ifdef NON_MATCHING
void func_800F9ED0_GrabBag(omObjData* arg0, omObjData* arg1) {
    GrabBagPlayerWork* work1;
    GrabBagPlayerWork* work0;

    work0 = GB_PLAYER(arg0);
    work1 = GB_PLAYER(arg1);
    func_80017C0C(arg0, 8, (arg0->trans.x + arg1->trans.x) / 2.0f, (arg0->trans.y + arg1->trans.y) / 2.0f,
                  (arg0->trans.z + arg1->trans.z) / 2.0f, 0.0f, 0.0f);
    if (func_800FA184_GrabBag(arg0, arg1) == 1) {
        work1->unk_EC = work0->unk_EC = 1;
        work1->speed = D_800B8988;
        func_800184BC(arg1, 0xC);
        work0->speed = -D_800B8988;
        func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
        func_800184BC(arg0, 9);
        D_800FB294_GrabBag = func_800FA304_GrabBag(arg0, arg1);
        D_800FB24C_GrabBag = GB_BAG(D_800EDE70[D_800FB294_GrabBag]);
        D_800FB24C_GrabBag->unk_6C = work0->unk_EA;
        D_800FB24C_GrabBag->unk_6D = work0->player;
        if (D_800FB294_GrabBag % 3 == 0) {
            D_800FB24C_GrabBag->unk_6E = 0;
        } else if (D_800FB294_GrabBag % 3 == 1) {
            D_800FB24C_GrabBag->unk_6E = 1;
            func_80060618(0x45F, work1->player);
        }
        D_800EDE70[D_800FB294_GrabBag]->trans.x = arg1->trans.x;
        D_800EDE70[D_800FB294_GrabBag]->trans.y = arg1->trans.y;
        D_800EDE70[D_800FB294_GrabBag]->trans.z = arg1->trans.z;
        func_800258EC(D_800EDE70[D_800FB294_GrabBag]->model[0], 4, 0);
        func_800258EC(D_800EDE70[D_800FB294_GrabBag]->model[1], 4, 0);
        func_800F6E90_GrabBag(D_800EDE70[D_800FB294_GrabBag]);
        work1->button_press_count = 0;
    } else {
        work0->speed = -D_800B8988;
        func_800184BC(arg0, 0x1E);
        work1->speed = D_800B8988;
        func_800184BC(arg1, 0x1F);
        work1->button_press_count = 0;
    }
    work0->button_press_count = 0;
    work1->unk_EB = 1;
    work0->unk_EB = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9ED0_GrabBag);
#endif
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
s32 func_800FA304_GrabBag(omObjData* arg0, omObjData* arg1) {
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
void func_800FA658_GrabBag(omObjData* arg0) {
    GrabBagPlayerWork* work;
    f32 angle;

    work = GB_PLAYER(arg0);
    if (work->unk_EF < 30) {
        ContStkX[work->port] = ContStkY[work->port] = 0;
    } else if (work->unk_E8 == -1) {
        if (work->unk_FE > 60) {
            angle = func_800F9A1C_GrabBag(arg0);
        } else {
            angle = func_800F98A4_GrabBag(arg0);
        }
        ContStkX[work->port] = func_800AEAC0(angle) * 32.0f;
        ContStkY[work->port] = -func_800AEFD0(angle) * 32.0f;
    }
    ContBtnTrg[work->port] &= 0x7FFF;
    ContBtnTrg[work->port] &= 0xBFFF;
}
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
void func_800FA8F4_GrabBag(omObjData* arg0) {
    GrabBagPos facePos[4] = { { 56, 24 }, { 264, 24 }, { 56, 202 }, { 264, 202 } };
    GrabBagPos bagPos[4] = { { 39, 38 }, { 247, 38 }, { 39, 216 }, { 247, 216 } };
    s16 i;
    s16 sprite;

    for (i = 0; i < 4; i++) {
        D_800FB270_GrabBag[i] = func_80019060((s16)InitSprite(GwPlayer[i].character + 0x6E), 0, 1);
        SetBasicSpritePos(D_800FB270_GrabBag[i], facePos[i].x, facePos[i].y);
    }
    sprite = InitSprite(0x74);
    for (i = 0; i < 4; i++) {
        D_800FB278_GrabBag[i] = func_80019060(sprite, 0, 1);
        SetBasicSpritePos(D_800FB278_GrabBag[i], bagPos[i].x, bagPos[i].y);
    }
    sprite = InitSprite(0x87);
    for (i = 0; i < 4; i++) {
        D_800FB258_GrabBag[i][0] = func_80019060(sprite, 0, 1);
        SetBasicSpritePos(D_800FB258_GrabBag[i][0], D_800FB0F4_GrabBag[i].x, D_800FB0F4_GrabBag[i].y);
        D_800FB258_GrabBag[i][1] = func_80019060(sprite, 0, 1);
        SetBasicSpritePos(D_800FB258_GrabBag[i][1], D_800FB0F4_GrabBag[i].x + 12, D_800FB0F4_GrabBag[i].y);
        D_800FB258_GrabBag[i][2] = func_80019060(sprite, 0, 1);
        SetBasicSpritePos(D_800FB258_GrabBag[i][2], D_800FB0F4_GrabBag[i].x + 24, D_800FB0F4_GrabBag[i].y);
    }
    D_800FB280_GrabBag = arg0;
    arg0->work[1] = 0;
    arg0->func_ptr = func_800FAC0C_GrabBag;
}
void func_800FAC0C_GrabBag(omObjData* arg0) {
    s32 i;
    s32 score;
    s32 digit;
    s32 x;

    switch (arg0->work[1]) {
    case 0:
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            score = D_800FB104_GrabBag[i];
            if (score >= 1000) {
                score = 999;
            }
            x = 0;
            ShowBasicSprite(D_800FB258_GrabBag[i][2]);
            digit = score / 100;
            if (digit == 0) {
                func_80018C90(D_800FB258_GrabBag[i][2]);
            }
            func_80018E0C(D_800FB258_GrabBag[i][2], digit);
            SetBasicSpritePos(D_800FB258_GrabBag[i][2], D_800FB0F4_GrabBag[i].x + x, D_800FB0F4_GrabBag[i].y);
            if (digit != 0) {
                x += 12;
            }
            ShowBasicSprite(D_800FB258_GrabBag[i][1]);
            digit = (score % 100) / 10;
            if (digit == 0 && score / 100 == 0) {
                func_80018C90(D_800FB258_GrabBag[i][1]);
            }
            func_80018E0C(D_800FB258_GrabBag[i][1], digit);
            SetBasicSpritePos(D_800FB258_GrabBag[i][1], D_800FB0F4_GrabBag[i].x + x, D_800FB0F4_GrabBag[i].y);
            if (digit != 0) {
                x += 12;
            } else if (score / 100 != 0) {
                x += 12;
            }
            func_80018E0C(D_800FB258_GrabBag[i][0], score % 10);
            SetBasicSpritePos(D_800FB258_GrabBag[i][0], D_800FB0F4_GrabBag[i].x + x, D_800FB0F4_GrabBag[i].y);
        }
        break;
    }
}
void func_800FAED8_GrabBag(void) {
    s32 i;

    D_800FB280_GrabBag->work[1] = 1;
    for (i = 0; i < 4; i++) {
        ShowBasicSprite(D_800FB258_GrabBag[i][0]);
        ShowBasicSprite(D_800FB258_GrabBag[i][1]);
        ShowBasicSprite(D_800FB258_GrabBag[i][2]);
        ShowBasicSprite(D_800FB270_GrabBag[i]);
        ShowBasicSprite(D_800FB278_GrabBag[i]);
    }
}

void func_800FAFA0_GrabBag(void) {
    s32 i;

    D_800FB280_GrabBag->work[1] = 0;
    for (i = 0; i < 4; i++) {
        func_80018C90(D_800FB258_GrabBag[i][0]);
        func_80018C90(D_800FB258_GrabBag[i][1]);
        func_80018C90(D_800FB258_GrabBag[i][2]);
        func_80018C90(D_800FB270_GrabBag[i]);
        func_80018C90(D_800FB278_GrabBag[i]);
    }
}

void func_800FB064_GrabBag(s32 arg0, s32 arg1) {
    arg1 = arg1 < 0 ? 0 : arg1;
    if (arg1 >= 1000) {
        arg1 = 999;
    }
    D_800FB104_GrabBag[arg0] = arg1;
}


