#include "HammerDrop.h"

void func_800F65E0_HammerDrop(void) {
    func_800F67BC_HammerDrop();
    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_80009500();
    func_8001DE70(0x42);
    omInitObjMan(0x28, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800F6848_HammerDrop(2370.0f, 324.0f, 0.0f, 0.0f, 0.0f, 205.0f, 0.0f);
    func_8005D98C(4, 4);
    omAddObj(0xA, 0, 0, -1, &func_800F6814_HammerDrop);
    omAddObj(2, 2, 0, -1, &func_800F690C_HammerDrop);
    omAddObj(2, 3, 0, -1, &func_800F6A54_HammerDrop);
    omAddObj(4, 0xA, 0x32, -1, &func_800F7488_HammerDrop);
    omAddObj(4, 0xA, 0x32, -1, &func_800F74A4_HammerDrop);
    omAddObj(4, 0xA, 0x32, -1, &func_800F74C0_HammerDrop);
    omAddObj(4, 0xA, 0x32, -1, &func_800F74DC_HammerDrop);
    func_8007B168(D_800FB5C0_HammerDrop, 1);
    func_800F7D28_HammerDrop();
    func_800F9350_HammerDrop();
    func_800F8508_HammerDrop();
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F67BC_HammerDrop(void) {
    D_800ED440 = 0;
    D_800F2BC0 = 0;
    D_800EE984 = 0;
    D_800FB6C4_HammerDrop = 4;
    D_800FB98C_HammerDrop = 0;
    D_800FB988_HammerDrop = 0;
    D_800FB6C8_HammerDrop = _CheckFlag(MINIGAME_ISLAND_ENDING);
}

void func_800F6814_HammerDrop(void) {
    if (D_800F5144 != 0) {
        func_800601D4(40);
        omOvlReturnEx(1);
    }
}

void func_800F6848_HammerDrop(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    func_800178A0(1);
    CZoom = arg0;
    CRot.x = arg1;
    CRot.y = arg2;
    CRot.z = arg3;
    Center.x = arg4;
    Center.y = arg5;
    Center.z = arg6;
    D_800FB6CC_HammerDrop = 25.0f;
    func_8001D494(0, 25.0f, D_800C3110->unk_44, D_800C3110->unk_48);
}

void func_800F690C_HammerDrop(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    arg0->model[0] = func_800174C0(0x330001, 0x69D);
    arg0->model[1] = func_800174C0(0x170000, 0x699);
    arg0->model[2] = func_800174C0(0x170006, 0x699);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = arg0;
    func_8009B770(arg0->unk_50, 0, sizeof(unkGlobalStruct_02));
    temp_s1->unk_04 = 1;
    temp_s1->unk_05 = 0;
    arg0->func_ptr = &func_800FA2D8_HammerDrop;
}

void func_800F6A54_HammerDrop(omObjData* arg0) {
    arg0->unk_50 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->model[0] = LoadFormFile(0x380002, 0x48D);
    arg0->model[1] = LoadFormFile(0x380003, 0x48D);
    omSetTra(arg0, 0.0f, 1000.0f, 1000.0f);
    func_800FA2E0_HammerDrop();
    arg0->func_ptr = &func_800F6ADC_HammerDrop;
}

void func_800F6ADC_HammerDrop(void) {
    func_800FB050_HammerDrop();
}

// Logic-equivalent player construction; retail copies three position tables to the stack.
#ifdef NON_MATCHING
void func_800F6AF8_HammerDrop(omObjData* arg0, s32 arg1) {
    unkGlobalStruct_00* work;
    HammerDropPlayerState* state;
    s32 characterBase;
    s32 animation;

    D_800FB994_HammerDrop = GwPlayer[arg1].character;
    D_800FB6B0_HammerDrop[arg1] = 0;
    characterBase = D_800C59AC[D_800FB994_HammerDrop].unk_00;
    func_8000979C(arg0, characterBase,
        D_800C59AC[D_800FB994_HammerDrop].unk_04, arg1, 0x699, 0x699);
    work = arg0->unk_50;
    state = func_80023684(sizeof(HammerDropPlayerState), 0x7918);
    work->unk_E4 = (unk_Struct01*) state;
    state->unk_44 = work->unk_56;
    arg0->model[3] = LoadFormFile(0x19, 0x68D);
    arg0->model[4] = LoadFormFile(0x1A, 0x68D);
    func_800187D0(arg0, 0, characterBase, 1, 0);
    func_800187D0(arg0, 1, characterBase | 1, 1, 0);
    func_800187D0(arg0, 2, characterBase | 3, 1, 0);
    func_800187D0(arg0, 6, characterBase | 5, 1, 0x13);
    func_800187D0(arg0, 8, characterBase | 9, 1, 0x1D);
    if (rand8() & 1) {
        animation = characterBase | 0xF;
    } else {
        animation = characterBase | 0x38;
    }
    func_800187D0(arg0, 0xD, animation, 1, 0x78);
    if (rand8() & 1) {
        animation = characterBase | 0x10;
    } else {
        animation = characterBase | 0x3C;
    }
    func_800187D0(arg0, 0xE, animation, 1, 0x78);
    func_800187D0(arg0, 0x12, characterBase | 0x1C, 2, 0);
    func_800187D0(arg0, 0x13, characterBase | 0x1D, 2, 0);
    func_800187D0(arg0, 0x15, characterBase | 0x62, 0, 0);
    func_800187D0(arg0, 0x20, characterBase | 0x67, 0, 0);
    func_800187D0(arg0, 0x21, characterBase | 0x68, 2, 0);
    func_800187D0(arg0, 0x22, characterBase | 0x69, 2, 0);
    arg0->trans.x = D_800FB5C8_HammerDrop[arg1];
    arg0->trans.y = 0.0f;
    arg0->trans.z = D_800FB5D8_HammerDrop[arg1];
    work->unk_48 = 50.0f;
    work->unk_38 = 1000.0f;
    work->unk_50 = 0;
#ifdef TARGET_PC
    /* Retail treats the low big-endian byte of unk_B0 as the byte at offset 0xB1. */
    work->unk_B0 = (work->unk_B0 & 0x00FF) | 0xFF00;
#else
    ((s8*) &work->unk_B0)[1] = -1;
#endif
    work->unk_DC = func_800F9C1C_HammerDrop;
    work->unk_3C = D_800FB5E8_HammerDrop[arg1];
    func_80008FE8(arg0, 25.0f);
    state->unk_24 = arg1;
    state->unk_28 = 1000.0f;
    state->unk_0C = 0;
    state->unk_10 = 0;
    state->unk_14 = 0;
    state->unk_4C = -1;
    state->unk_54 = 0.0f;
    state->unk_58 = 30;
    state->unk_2C = 1;
    state->unk_5C = 0;
    if (!(GwPlayer[arg1].flags & 1)) {
        state->unk_50 = 1;
    } else {
        switch (GwPlayer[arg1].cpu_difficulty) {
            case 0:
                state->unk_50 = 0;
                break;
            case 1:
                state->unk_50 = 1;
                break;
            case 2:
                state->unk_50 = 2;
                break;
            case 3:
                state->unk_50 = 3;
                break;
        }
    }
    D_800FB998_HammerDrop[arg1] = arg0;
    func_800090C4(arg0, 0, 2);
    D_800F3FB0[D_800F2BC0++] = arg0;
    func_800184BC(arg0, 0);
    D_800ED430 = 0;
    arg0->func_ptr = func_800F6F9C_HammerDrop;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F6AF8_HammerDrop);
#endif

// Logic-equivalent player update state machine; register allocation differs.
#ifdef NON_MATCHING
void func_800F6F9C_HammerDrop(omObjData* arg0) {
    unkGlobalStruct_00* work = arg0->unk_50;
    HammerDropPlayerState* state = (HammerDropPlayerState*) work->unk_E4;
    s32* flags = &D_800FB6B0_HammerDrop[state->unk_24];
    f32 animationTime;

    state->unk_28 = work->unk_38;
    func_80017A60(arg0);
    if ((func_800F9E68_HammerDrop(*flags, 1) != 0) ||
        (func_800F9E68_HammerDrop(*flags, 2) != 0)) {
        return;
    }
    if (GwPlayer[state->unk_24].flags & 1) {
        ContStkX[work->unk_56] = 0;
        ContStkY[work->unk_56] = 0;
        ContBtn[work->unk_56] = 0;
        ContBtnTrg[work->unk_56] = 0;
        func_800F77E4_HammerDrop(arg0);
    }
    if ((work->unk_38 != 1000.0f) &&
        ((func_800F9E68_HammerDrop(*flags, 0x400) != 0) ||
         (func_800F9E68_HammerDrop(*flags, 0x1000) != 0))) {
        func_800F736C_HammerDrop(arg0);
    }
    func_80005A28(arg0);
    if ((arg0->trans.y < -500.0f) && (state->unk_5C == 0)) {
        func_80060618(0x45F, (s16) state->unk_24);
        state->unk_5C++;
    }
    if (arg0->trans.y < -2000.0f) {
        func_800F9E74_HammerDrop(flags, 1, 1);
        D_800FB6C4_HammerDrop--;
        PlaySound(0x294);
        if ((D_800FB6C8_HammerDrop != 0) && (state->unk_24 == 0) &&
            (D_800FB980_HammerDrop == 2)) {
            D_800FB980_HammerDrop = 3;
        }
    }
    if (work->unk_38 == 1000.0f) {
        if (func_800F9E68_HammerDrop(*flags, 0x200) != 0) {
            work->unk_3C = 0.0f;
            animationTime = func_80025D18(arg0->model[0]);
            if (func_80025D40(arg0->model[0]) <= animationTime) {
                func_800F9E74_HammerDrop(flags, 0x200, 0);
                func_800F9E74_HammerDrop(flags, 2, 1);
            }
        } else if (func_800F9E68_HammerDrop(*flags, 0x400) != 0) {
            work->unk_40 = D_800B8990;
            if (GwPlayer[state->unk_24].coins_mg != 0) {
                func_800185A4(arg0, 0xD);
            } else {
                func_800185A4(arg0, 0xE);
            }
            func_800F9E74_HammerDrop(flags, 0x400, 0);
            func_800F9E74_HammerDrop(flags, 0x200, 1);
        }
    }
    if (D_800ED430 == 2) {
        work->unk_50 |= 0x200;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F6F9C_HammerDrop);
#endif

void func_800F736C_HammerDrop(omObjData* arg0) {
    unkGlobalStruct_00* work = arg0->unk_50;
    HammerDropPlayerState* state = (HammerDropPlayerState*) work->unk_E4;
    f32 stickMagnitude = 60.0f;
    f32 angle;
    f32 wrappedAngle;

    ContStkX[work->unk_56] = (s8) (s32) (func_800AEAC0(state->unk_54) * stickMagnitude);
    ContStkY[work->unk_56] = (s8) (s32) (func_800AEFD0(state->unk_54) * -stickMagnitude);
    state->unk_58--;
    if (state->unk_58 == 0) {
        angle = state->unk_54 + 30.0f;
        if (angle >= 360.0f) {
            wrappedAngle = angle - 360.0f;
        } else {
            wrappedAngle = state->unk_54 + 30.0f;
            if (wrappedAngle < 0.0f) {
                wrappedAngle += 360.0f;
            }
        }
        state->unk_54 = wrappedAngle;
        state->unk_58 = 30;
    }
}

void func_800F7488_HammerDrop(omObjData* arg0) {
    func_800F6AF8_HammerDrop(arg0, 0);
}

void func_800F74A4_HammerDrop(omObjData* arg0) {
    func_800F6AF8_HammerDrop(arg0, 1);
}

void func_800F74C0_HammerDrop(omObjData* arg0) {
    func_800F6AF8_HammerDrop(arg0, 2);
}

void func_800F74DC_HammerDrop(omObjData* arg0) {
    func_800F6AF8_HammerDrop(arg0, 3);
}

// Logic-equivalent CPU target selection; retail copies the height table to the stack.
#ifdef NON_MATCHING
void func_800F74F8_HammerDrop(omObjData* arg0) {
    HammerDropPlayerState* state = (HammerDropPlayerState*) ((unkGlobalStruct_00*) arg0->unk_50)->unk_E4;
    HammerDropItemState* item;
    omObjData* candidate;
    f32 distance;
    s32 activeCount = 0;
    s32 findTarget = 0;
    s32 target = -1;
    s32 i;

    if (D_800ED430 == 1) {
        if (state->unk_4C == -1) {
            distance = 0.0f;
            findTarget = 1;
        } else {
            candidate = D_800EDE70[state->unk_4C];
            distance = sqrtf((candidate->trans.x * candidate->trans.x) +
                (candidate->trans.z * candidate->trans.z));
            item = HAMMER_ITEM_WORK(candidate)->item;
            if ((distance >= 400.0f) ||
                (func_800F9E68_HammerDrop(item->unk_44, 1) == 0)) {
                findTarget = 1;
            }
        }
        if (findTarget != 1) {
            goto done;
        }
        for (i = 0; i < 6; i++) {
            item = HAMMER_ITEM_WORK(D_800EDE70[i])->item;
            if (distance < 400.0f) {
                activeCount += func_800F9E68_HammerDrop(item->unk_44, 1);
            } else {
                func_800F9E68_HammerDrop(item->unk_44, 1);
            }
        }
        if (activeCount == 0) {
            goto store_target;
        } else {
            target = ((rand8() & 0xFF) % 6) & 0xFF;
            candidate = D_800EDE70[target];
            item = HAMMER_ITEM_WORK(candidate)->item;
            if (D_800FB5F8_HammerDrop[state->unk_50] < candidate->trans.y) {
                target = -1;
            }
            if ((item->unk_38 == 2) &&
                ((rand8() & 3) < (state->unk_50 + 1))) {
                target = -1;
            }
            if ((target == -1) ||
                (func_800F9E68_HammerDrop(item->unk_44, 1) == 0)) {
                target = -1;
            } else {
                candidate = D_800EDE70[target];
                distance = sqrtf((candidate->trans.x * candidate->trans.x) +
                    (candidate->trans.z * candidate->trans.z));
                if (distance >= 400.0f) {
                    target = -1;
                }
            }
        }
    }
store_target:
    state->unk_4C = target;
done:
    return;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F74F8_HammerDrop);
#endif

// Logic-equivalent CPU movement/attack controller; local-vector scheduling differs.
#ifdef NON_MATCHING
void func_800F77E4_HammerDrop(omObjData* arg0) {
    unkGlobalStruct_00* work = arg0->unk_50;
    HammerDropPlayerState* state = (HammerDropPlayerState*) work->unk_E4;
    Vec start;
    Vec target;
    Vec direction;
    s16 offsetX;
    s16 offsetZ;
    s32 range;
    s32 player;

    func_800F74F8_HammerDrop(arg0);
    if (state->unk_4C == -1) {
        return;
    }
    start = arg0->trans;
    range = state->unk_50 + 1;
    offsetX = (((rand8() & 0xFF) % range) * 30) - (range * 15);
    range = state->unk_50 + 1;
    offsetZ = (((rand8() & 0xFF) % range) * 30) - (range * 15);
    target.x = D_800EDE70[state->unk_4C]->trans.x + offsetX;
    target.y = start.y;
    target.z = D_800EDE70[state->unk_4C]->trans.z + offsetZ;
    func_800F9E98_HammerDrop(&start, &target, &direction);
    if ((D_800EDE70[state->unk_4C]->trans.y < 600.0f) ||
        (direction.x >= 150.0f) || (rand8() & 0xF)) {
        if (work->unk_38 == 1000.0f) {
            state->unk_2C--;
            if (state->unk_2C != 0) {
                direction.z = state->unk_54;
            } else {
                state->unk_2C = D_800FB590_HammerDrop[state->unk_50];
            }
            work->unk_3C = direction.z;
            func_800F7AD4_HammerDrop(arg0);
            state->unk_54 = direction.z;
        }
    } else {
        func_800F7B6C_HammerDrop(arg0);
    }
    if (work->unk_38 != 1000.0f) {
        player = func_800F7BFC_HammerDrop(arg0, 100.0f);
        if ((player != -1) &&
            (D_800FB998_HammerDrop[player]->trans.y < arg0->trans.y) &&
            !(rand8() & 0x7F)) {
            func_800F7BB4_HammerDrop(arg0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F77E4_HammerDrop);
#endif

void func_800F7AD4_HammerDrop(omObjData *arg0) {
    f32 temp_f22;
    f32 temp;
    unkGlobalStruct_00* temp_s0 = arg0->unk_50;
    HammerDropPlayerState* test2 = (HammerDropPlayerState*) temp_s0->unk_E4;
    temp_f22 = temp_s0->unk_3C;
    (void) test2->unk_50;
    if (test2->unk_50 && temp_s0->unk_E4) {}
    rand8();
    temp = 70.0f;
    ContStkX[temp_s0->unk_56] = func_800AEAC0(temp_f22) * temp;
    ContStkY[temp_s0->unk_56] = func_800AEFD0(temp_f22) * -temp;
}

void func_800F7B6C_HammerDrop(omObjData* arg0) {
    unkGlobalStruct_00* temp_a0;
    s32 tempVar = 0x8000;

    temp_a0 = arg0->unk_50;
    ContBtnTrg[temp_a0->unk_56] |= tempVar;
    ContBtn[temp_a0->unk_56] |= tempVar;
}

void func_800F7BB4_HammerDrop(omObjData* arg0) {
    unkGlobalStruct_00* temp_a0;

    temp_a0 = arg0->unk_50;
    ContBtnTrg[temp_a0->unk_56] |= 0x2000;
    ContBtn[temp_a0->unk_56] |= 0x2000;
}

s32 func_800F7BFC_HammerDrop(omObjData* arg0, f32 arg1) {
    omObjData* temp_v0;
    f32 temp_f0, temp_f12, temp_f4, phi_f20;
    s32 phi_v0, phi_v1;
    s32 i;
    HammerDropPlayerState* temp;

    D_800FB6A0_HammerDrop = -1;
    phi_f20 = 50000.0f;
    temp = (HammerDropPlayerState*) ((unkGlobalStruct_00*) arg0->unk_50)->unk_E4;
    
    for (i = 0; i < 4; i++) {
         if (i != temp->unk_24) {
            temp_v0 = D_800FB998_HammerDrop[i];
            temp_f4 = (arg0->trans.x - temp_v0->trans.x) * (arg0->trans.x - temp_v0->trans.x);
            temp_f0 = (arg0->trans.z - temp_v0->trans.z) * (arg0->trans.z - temp_v0->trans.z);
            temp_f12 = sqrtf(temp_f4  + temp_f0);
             
            if (!(temp_f12 < arg1)) {
                phi_v0 = 0;
            } else {
                phi_v0 = 1;
            }
            
            if (!(temp_f12 < phi_f20)) {
                phi_v1 = 0;
            } else {
                phi_v1 = 1;
            }
             
            if (phi_v0 & phi_v1) {
                phi_f20 = temp_f12;
                D_800FB6A0_HammerDrop = i;
            }
        }       
    }
    return D_800FB6A0_HammerDrop;
}

void func_800F7D28_HammerDrop(void) {
    omAddObj(0, 0, 0, -1, func_800F7D64_HammerDrop);
    D_800FB980_HammerDrop = 0;
}

// The compiler-owned jump table duplicates the still-assembly data table (masked 2).
#ifdef NON_MATCHING
void func_800F7D64_HammerDrop(void) {
    switch (D_800FB980_HammerDrop) {
        case 0:
            func_800F7EF4_HammerDrop();
            D_800ED430 = 0;
            break;
        case 1:
            func_800F7F90_HammerDrop();
            break;
        case 2:
            func_800F7E28_HammerDrop();
            break;
        case 3:
            func_800F8080_HammerDrop();
            break;
        case 4:
            func_800F82E0_HammerDrop();
            break;
        case 5:
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F7D64_HammerDrop);
#endif

void func_800F7DEC_HammerDrop(void) {
    D_800FB6A8_HammerDrop = 30;
    D_800FB6AA_HammerDrop = 30;
    GMesCreate(8, 30, 160, 32);
}

void func_800F7E28_HammerDrop(void) {
    D_800FB6AA_HammerDrop--;
    if (D_800FB6AA_HammerDrop == 0) {
        D_800FB6AA_HammerDrop = 30;
        D_800FB6A8_HammerDrop--;
    }
    if ((D_800FB6A8_HammerDrop == 0) && (D_800FB980_HammerDrop == 2)) {
        if (D_800FB6C4_HammerDrop != 0) {
            func_800790C0();
            D_800FB980_HammerDrop = 3;
        }
    }
    if ((D_800FB6C4_HammerDrop == 0) && (D_800FB980_HammerDrop == 2)) {
        D_800FB980_HammerDrop = 4;
    }
    func_80079078((s16) D_800FB6A8_HammerDrop);
}

void func_800F7EF4_HammerDrop(void) {
    omObjData* obj = omAddObj(16, 0, 0, -1, func_800F7F58_HammerDrop);
    s32* timer = func_80023684(sizeof(s32), 0x7918);

    obj->unk_50 = timer;
    *timer = 60;
    D_800FB980_HammerDrop = -1;
}

void func_800F7F58_HammerDrop(omObjData* arg0) {
    s32* timer = arg0->unk_50;

    (*timer)--;
    if (*timer == 0) {
        D_800FB980_HammerDrop = 1;
        omDelObj(arg0);
    }
}

void func_800F7F90_HammerDrop(void) {
    omObjData* obj;
    s32* timer;

    GMesCreate(0);
    obj = omAddObj(16, 0, 0, -1, func_800F7FFC_HammerDrop);
    timer = func_80023684(sizeof(s32), 0x7918);
    obj->unk_50 = timer;
    *timer = 30;
    D_800FB980_HammerDrop = -1;
}

void func_800F7FFC_HammerDrop(omObjData* arg0) {
    s32* timer = arg0->unk_50;

    if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
        (*timer)--;
        if (*timer == 0) {
            func_800F7DEC_HammerDrop();
            D_800FB980_HammerDrop = 2;
            D_800ED430 = 1;
            omDelObj(arg0);
        }
    }
}

void func_800F8080_HammerDrop(void) {
    omObjData* obj;
    s32* timer;

    GMesCreate(2);
    func_800601D4(40);
    obj = omAddObj(16, 0, 0, -1, func_800F813C_HammerDrop);
    timer = func_80023684(sizeof(s32), 0x7918);
    obj->unk_50 = timer;
    *timer = 30;
    D_800ED430 = 2;
    D_800FB980_HammerDrop = -1;
    HAMMER_ITEM_WORK(D_800FB990_HammerDrop)->item->unk_30 = -15.0f;
    func_800601D4(40);
    D_800FB988_HammerDrop++;
}

// Register allocation only after retaining both flag-array bases (masked 2).
#ifdef NON_MATCHING
void func_800F813C_HammerDrop(omObjData* arg0) {
    omObjData* obj = arg0;
    s32* timer = obj->unk_50;
    s32* flagBase;
    s32* flags;
    s32 readyCount;
    s32 i;

    if (*timer > 0) {
        (*timer)--;
        if ((*timer == 0) && (D_800FB6C8_HammerDrop == 0)) {
            func_80060128(0x36);
        }
    }
    if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
        readyCount = 0;
        if (D_800FB6C8_HammerDrop != 0) {
            if (GMesWait() == 0) {
                func_800726AC(0, 20);
                *timer = 2;
                obj->func_ptr = func_800F84A0_HammerDrop;
            }
        } else {
            flagBase = D_800FB6B0_HammerDrop;
            for (i = 0; i < 4; i++) {
                readyCount += func_800F9E68_HammerDrop(flagBase[i], 2);
            }
            if (readyCount != D_800FB6C4_HammerDrop) {
                timer = D_800FB6B0_HammerDrop;
                for (i = 0; i < 4; i++) {
                    flags = &timer[i];
                    if ((func_800F9E68_HammerDrop(*flags, 1) == 0) &&
                        (func_800F9E68_HammerDrop(*flags, 0x400) == 0) &&
                        (func_800F9E68_HammerDrop(*flags, 0x200) == 0)) {
                        func_800F9E74_HammerDrop(flags, 0x400, 1);
                    }
                }
            } else {
                D_800FB980_HammerDrop = 4;
                *timer = 0;
                omDelObj(obj);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F813C_HammerDrop);
#endif

// Result-register move is scheduled before the object-work store (masked 2).
#ifdef NON_MATCHING
void func_800F82E0_HammerDrop(void) {
    omObjData* obj;
    s32* timer;

    obj = omAddObj(16, 0, 0, -1, func_800F8394_HammerDrop);
    timer = func_80023684(sizeof(s32), 0x7918);
    obj->unk_50 = timer;
    if ((D_800FB6C4_HammerDrop == 0) && (D_800FB988_HammerDrop == 0)) {
        *timer = 60;
        GMesCreate(14);
        func_800601D4(40);
    } else {
        if (D_800FB98C_HammerDrop == 0) {
            *timer = 84;
        } else {
            *timer = 105;
        }
    }
    D_800FB980_HammerDrop = -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F82E0_HammerDrop);
#endif

// Addition operand order only (masked 0).
#ifdef NON_MATCHING
void func_800F8394_HammerDrop(omObjData* arg0) {
    s32* timer = arg0->unk_50;
    s32 total;
    s16 i;

    if (*timer > 0) {
        (*timer)--;
        if (*timer == 0) {
            if (D_800FB6C4_HammerDrop == 0) {
                total = 0;
                for (i = 0; i < 4; i++) {
                    total = (u16) GwPlayer[i].coins_mg + total;
                }
                if ((total << 16) != 0) {
                    func_80060128(0x35);
                } else {
                    func_80060128(0x34);
                }
            } else {
                func_800726AC(0, 20);
                *timer = 2;
                arg0->func_ptr = func_800F84A0_HammerDrop;
            }
        }
    }
    if (GMesWait() == 0) {
        func_800726AC(0, 20);
        *timer = 2;
        arg0->func_ptr = func_800F84A0_HammerDrop;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F8394_HammerDrop);
#endif

void func_800F84A0_HammerDrop(omObjData* arg0) {
    s32* timer = arg0->unk_50;

    if (*timer > 0) {
        (*timer)--;
    }
    if ((*timer == 0) && (func_80072718() == 0)) {
        func_800601D4(40);
        omDelObj(arg0);
        omOvlReturnEx(1);
    }
}

// Logic-equivalent hammer construction; local angle wrapping differs.
#ifdef NON_MATCHING
void func_800F8508_HammerDrop(void) {
    omObjData* obj;
    HammerDropItemWork* work;
    HammerDropTargetState* state;
    f32 angle;

    obj = omAddObj(5, 3, 3, -1, func_800F896C_HammerDrop);
    D_800FB990_HammerDrop = obj;
    work = func_80023684(sizeof(HammerDropItemWork), 0x7918);
    obj->unk_50 = work;
    obj->model[0] = LoadFormFile(0x2E0002, 0x699);
    obj->model[1] = LoadFormFile(0x2E0000, 0x699);
    obj->model[2] = LoadFormFile(6, 0x699);
    obj->trans.x = 0.0f;
    obj->trans.y = 2330.0f;
    obj->trans.z = 0.0f;
    obj->rot.x = 0.0f;
    obj->rot.y = 0.0f;
    obj->rot.z = 0.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    state = func_80023684(sizeof(HammerDropTargetState), 0x7918);
    work->item = (HammerDropItemState*) state;
    work->unk_48 = 40.0f;
    work->unk_34 = 40.0f;
    work->unk_38 = 1000.0f;
    work->unk_3C = 180.0f;
    work->unk_58 = 0.8f;
    work->unk_4C = 0.5f;
    work->unk_40 = 0.0f;
    state->unk_08 = 12.0f;
    angle = obj->rot.y + 180.0f;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    state->unk_04 = angle;
    state->unk_0C = 0;
    state->unk_10 = 1.0f;
    state->unk_14 = ((rand8() & 0xFF) * 2) % 350;
    state->unk_18 = 0;
    state->unk_1C = 5.0f;
    angle = (f32) (((rand8() & 0xFF) * 2) % 360) + obj->rot.y;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    state->unk_20 = angle;
    state->unk_28 = angle + 180.0f;
    state->unk_24 = 0;
    omSetTra(obj, obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], obj->trans.x - 50.0f, obj->trans.y + 50.0f,
        obj->trans.z + 100.0f);
    func_80025830(obj->model[1], 0.4f, 0.4f, 0.4f);
    func_800370D4(obj->model[2]);
    func_80025830(obj->model[2], 2.0f, 2.0f, 2.0f);
    func_80025798(obj->model[2], obj->trans.x, 0.0f, obj->trans.z);
    D_800FB6C0_HammerDrop = 0;
    func_8001775C(obj, 0, 0x2E0002);
    func_8001775C(obj, 1, 0x2E0003);
    func_8001775C(obj, 2, 0x2E0004);
    func_80025BB8(obj->model[0], obj->motion[0]);
    func_80025EB4(obj->model[0], 2, 2);
    state->unk_00 = 0;
    state->unk_30 = -60.0f;
    func_800F9E74_HammerDrop(&D_800FB6C0_HammerDrop, 2, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F8508_HammerDrop);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F896C_HammerDrop);

// Two register/scheduling differences; the retry count increment moves before the second test (masked 2).
#ifdef NON_MATCHING
void func_800F9228_HammerDrop(void) {
    omObjData* item;
    s32 attempts = 0;
    s32 roll;
    s32 choice;

    while (1) {
        roll = (rand8() & 0xFF) % 40;
        if (roll < 21) {
            choice = 0;
        } else {
            choice = 2;
            if (roll < 30) {
                choice = 1;
            }
        }
        item = D_800EDE70[choice];
        if (func_800F9E68_HammerDrop(HAMMER_ITEM_WORK(item)->item->unk_44, 1) != 0) {
            item = D_800EDE70[choice + 3];
            attempts++;
            if (func_800F9E68_HammerDrop(HAMMER_ITEM_WORK(item)->item->unk_44, 1) != 0) {
                if (attempts > 0xFFFE) {
                    osSyncPrintf(D_800FB620_HammerDrop);
                    while (1) {}
                }
                continue;
            }
        }
        break;
    }
    func_800F95E8_HammerDrop(item);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F9228_HammerDrop);
#endif

// Logic-equivalent item construction; retail copies the two data tables to packed stack locals.
#ifdef NON_MATCHING
void func_800F9350_HammerDrop(void) {
    HammerDropItemWork* work;
    HammerDropItemState* item;
    omObjData* obj;
    u16 sharedModel = 0;
    s32 type;
    s32 i;

    D_800EE984 = 0;
    for (i = 0; i < 6; i++) {
        obj = omAddObj(12, 4, 0, -1, func_800F9794_HammerDrop);
        work = func_80023684(sizeof(HammerDropItemWork), 0x7918);
        obj->unk_50 = work;
        item = func_80023684(sizeof(HammerDropItemState), 0x7918);
        work->item = item;
        D_800EDE70[D_800EE984++] = obj;
        type = i % 3;
        if (type < 2) {
            func_800091BC(obj, D_800FB634_HammerDrop[type], 0xA89, 8);
            func_80009340(obj, 3, 0x2A, 0x68D, 8);
            func_8001E2F8(work->unk_24, 0xF0);
            func_8001E360(work->unk_24, 0xFF, 0xFF, 0xBE);
        } else {
            obj->model[0] = LoadFormFile(D_800FB634_HammerDrop[type], 0x69D);
        }
        if (i == 0) {
            obj->model[2] = LoadFormFile(6, 0x69D);
            sharedModel = obj->model[2];
        } else {
            obj->model[2] = func_80023FC8((s16) sharedModel);
        }
        func_800370D4(obj->model[2]);
        omSetTra(obj, 1000.0f, 5000.0f, 0.0f);
        work->unk_48 = 30.0f;
        work->unk_34 = 30.0f;
        work->unk_52 = (u8) D_800FB640_HammerDrop[type];
        work->unk_50 = 0;
        work->unk_54 = 1;
        if (type < 2) {
            omSetSca(obj, 3.0f, 3.0f, 3.0f);
            item->unk_3C = 0.0f;
        } else {
            omSetSca(obj, 1.0f, 1.0f, 1.0f);
            item->unk_3C = work->unk_48;
        }
        item->unk_38 = type;
        item->unk_44 = 0;
        item->unk_4C = i;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F9350_HammerDrop);
#endif

// Logic-equivalent item reset; retail first copies the packed kind table to the stack.
#ifdef NON_MATCHING
void func_800F95E8_HammerDrop(omObjData* arg0) {
    HammerDropItemWork* work = HAMMER_ITEM_WORK(arg0);
    HammerDropItemState* item = work->item;
    HammerDropTargetState* targetItem;
    s32* flags;

    omSetTra(arg0, D_800FB990_HammerDrop->trans.x, D_800FB990_HammerDrop->trans.y,
        D_800FB990_HammerDrop->trans.z);
    arg0->trans.x = D_800FB990_HammerDrop->trans.x;
    arg0->trans.y = D_800FB990_HammerDrop->trans.y;
    arg0->trans.z = D_800FB990_HammerDrop->trans.z;
    func_80025798(arg0->model[2], arg0->trans.x, 0.0f, arg0->trans.z);
    func_800258EC(arg0->model[2], 4, 0);
    work->unk_3C = D_800FB990_HammerDrop->rot.y;
    work->unk_40 = 5.0f;
    work->unk_48 = 30.0f;
    work->unk_34 = 30.0f;
    work->unk_52 = (u8) D_800FB648_HammerDrop[item->unk_38];
    item->unk_34 = 4.9f;
    item->unk_30 = 50.0f;
    item->unk_2C = 50.0f;
    item->unk_48 = 0;
    item->unk_50 = 0;
    if (item->unk_38 < 2) {
        work->unk_54 = 1;
    }
    func_800258EC(arg0->model[0], 4, 0);
    flags = &item->unk_44;
    func_800F9E74_HammerDrop(flags, 1, 1);
    func_800F9E74_HammerDrop(flags, 2, 1);
    targetItem = (HammerDropTargetState*) HAMMER_ITEM_WORK(D_800FB990_HammerDrop)->item;
    targetItem->itemIndex = item->unk_4C;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F95E8_HammerDrop);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F9794_HammerDrop);

s32 func_800F9C1C_HammerDrop(omObjData* arg0, omObjData* arg1) {
    unkGlobalStruct_00* temp_s0;
    unkHammerDropStruct* temp_s2;
    HammerDropPlayerState* temp_a1;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;

    D_800FB6A4_HammerDrop = 0;
    temp_s0 = arg0->unk_50;
    temp_a1 = (HammerDropPlayerState*) temp_s0->unk_E4;
    temp_s2 = (unkHammerDropStruct*) ((unkGlobalStruct_00*) arg1->unk_50)->unk_68; // probably not an unkGlobalStruct_00*

    if (temp_s0->unkAE != 0) {
        return 0;
    }

    if (temp_s2->unk_38 == 2) {
        func_80060540(0x296, temp_a1->unk_24);

        if (arg0->trans.y < arg1->trans.y - temp_s2->unk_3C) {
            func_80018450(arg0, 1);
        }

        if (temp_s0->unkAE != 0) {
            D_800F370C++;
            return 1;
        }

        temp_f24 = arg1->trans.x - (arg0->trans.x + D_800ED6B8);
        temp_f22 = arg1->trans.z - (arg0->trans.z + D_800F5254);

        if (temp_s0->unk_50 & 0x200) {
            return 1;
        }

        temp_f20 = func_8000A72C(func_800AEAC0(temp_s0->unk_3C), func_800AEFD0(temp_s0->unk_3C), temp_f24, temp_f22);

        if (temp_s0->unk_50 & 0x20) {
            func_8000A534(arg0, D_800B8988);
        }

        if (temp_f20 > 0.0f) {
            func_800184BC(arg0, 9);
            temp_s0->unk_40 = -D_800B8980;
        } else {
            func_800184BC(arg0, 10);
            temp_s0->unk_40 = D_800B8980;
        }

        temp_s0->unk_38 = -D_800B8964 * 0.7f;
        temp_s0->unkAE = 105;

        func_80017C0C(arg0, 5, arg1->trans.x, arg0->trans.y, arg1->trans.z, 0, func_800B0CD8(temp_f24, temp_f22) + 180.0f);
        func_80060F04(temp_s0->unk_58, 2, 2, 20);
    }

    return D_800FB6A4_HammerDrop;
}

s32 func_800F9E68_HammerDrop(s32 arg0, s32 arg1) {
    return (arg0 & arg1) != 0;
}

void func_800F9E74_HammerDrop(s32* arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        *arg0 |= arg1;
    } else {
        *arg0 &= ~arg1;
    }
}

// Logic-equivalent spherical displacement conversion; stack/register allocation differs.
#ifdef NON_MATCHING
void func_800F9E98_HammerDrop(Vec* from, Vec* to, Vec* out) {
    Vec fromCopy;
    Vec toCopy;
    Vec delta;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 length;
    s32 nearPositive;
    s32 nearNegative;

    fromCopy = *from;
    toCopy = *to;
    delta.x = toCopy.x - fromCopy.x;
    delta.y = toCopy.y - fromCopy.y;
    delta.z = toCopy.z - fromCopy.z;
    horizontal = sqrtf((delta.x * delta.x) + (delta.z * delta.z));
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        pitch = 180.0f;
        yaw = 0.0f;
        if (!(delta.y > 0.0001f) && (delta.y < 0.0001f)) {
            pitch = 0.0f;
        }
    } else {
        yaw = (f32) ((f64) func_800FA1AC_HammerDrop(delta.x / delta.z) * D_800FB650_HammerDrop);
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        pitch = (f32) ((f64) func_800FA1AC_HammerDrop(delta.y / horizontal) * D_800FB658_HammerDrop);
        if (yaw >= 360.0f) {
            yaw -= 360.0f;
        } else if (yaw < 0.0f) {
            yaw += 360.0f;
        }
        pitch += 90.0f;
        if (pitch >= 360.0f) {
            pitch -= 360.0f;
        } else if (pitch < 0.0f) {
            pitch += 360.0f;
        }
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    length = sqrtf((delta.y * delta.y) + (horizontal * horizontal));
    out->z = yaw;
    out->x = length;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800F9E98_HammerDrop);
#endif

// Logic-equivalent arctangent continued fraction; register allocation remains.
#ifdef NON_MATCHING
f32 func_800FA1AC_HammerDrop(f32 arg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f12;
    f32 var_f4;
    f64 var_f0;
    f64 var_f2;
    s32 var_a0;
    s32 var_v1;

    var_f12 = arg0;
    var_a0 = 1;
    if (var_f12 > 1.0f) {
        var_f12 = 1.0f / var_f12;
    } else {
        var_a0 = -1;
        if (var_f12 < -1.0f) {
            var_f12 = 1.0f / var_f12;
        } else {
            var_a0 = 0;
        }
    }
    var_f4 = 0.0f;
    var_v1 = 6;
    do {
        temp_f2 = (f32) (var_v1 * var_v1) * var_f12 * var_f12;
        temp_f0 = (f32) ((var_v1 * 2) + 1) + var_f4;
        var_v1--;
        var_f4 = temp_f2 / temp_f0;
    } while (var_v1 > 0);
    if (var_a0 > 0) {
        var_f0 = D_800FB660_HammerDrop;
        var_f2 = (f64) (var_f12 / (var_f4 + 1.0f));
        goto done;
    }
    if (var_a0 >= 0) {
        return var_f12 / (var_f4 + 1.0f);
    }
    var_f2 = (f64) (var_f12 / (var_f4 + 1.0f));
    var_f0 = D_800FB668_HammerDrop;
done:
    return (f32) (var_f0 - var_f2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800FA1AC_HammerDrop);
#endif

void func_800FA2D8_HammerDrop(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800FA2E0_HammerDrop);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800FAA30_HammerDrop);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_HammerDrop/17E710", func_800FB050_HammerDrop);
