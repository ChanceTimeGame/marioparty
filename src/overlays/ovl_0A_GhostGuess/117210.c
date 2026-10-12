#include "common.h"
#include "GhostGuess.h"

void func_800F65E0_GhostGuess(void) {
    u8 temp_s0;
    s16 i;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    D_800FBC10_GhostGuess = 0;
    D_800FBC12_GhostGuess = 3600;
    D_800ED430 = 1;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    D_800FBC08_GhostGuess = i;
    D_800B895C = 15.0f;
    D_800B8960 = 0.5f;
    D_800B8964 = 1.47f;
    D_800B8968 = 0.15f;
    D_800B896C = 7.0f;
    D_800B8970 = 30.0f;
    D_800B897C = 3.3333333f;
    D_800B8980 = 18.0f;
    D_800B8984 = 13.5f;
    D_800B8988 = 9.0f;
    D_800B898C = 4.5f;
    D_800B8990 = 0.0f;
    D_800B8994 = 1.7f;
    D_800B8998 = 0.5f;
    D_800B899C = 0.147f;
    D_800FB678_GhostGuess = _CheckFlag(0x2B);
    D_800FB6AC_GhostGuess = GwPlayer[D_800FBC08_GhostGuess].cpu_difficulty;
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800090B8(0);
    D_800FBBE0_GhostGuess = omAddObj(1, 0, 0, -1, func_800F69DC_GhostGuess);
    D_800F2AF8[D_800ED440++] = omAddObj(2, 1, 0, -1, func_800F6AE0_GhostGuess);
    D_800FBBE8_GhostGuess = omAddObj(5, 4, 0, -1, &func_800F6BA4_GhostGuess);
    D_800FBBE4_GhostGuess = D_800F3FB0[D_800F2BC0++] = omAddObj(3, 9, 0x3C, -1, &func_800F6FF4_GhostGuess);
    omAddObj(4, 1, 0, -1, &func_800F6E78_GhostGuess);
    D_800FBBEC_GhostGuess = omAddObj(2, 0, 0, -1, &func_800F73E0_GhostGuess);
}
void func_800F69DC_GhostGuess(omObjData* arg0) {
    s32 temp_s1;
    void* temp_s0;

    arg0->func_ptr = &func_800F79D4_GhostGuess;
    temp_s0 = DataRead(0x1C000A);
    temp_s1 = func_800678A4(temp_s0);
    DataClose(temp_s0);
    D_800FBEC0_GhostGuess = func_80064EF4(1, 0);
    func_80067208(D_800FBEC0_GhostGuess, 0, temp_s1, 0);
    func_800674BC(D_800FBEC0_GhostGuess, 0, 0x9000);
    func_80067354(D_800FBEC0_GhostGuess, 0, 1.0f, 1.0f);
    func_80066DC4(D_800FBEC0_GhostGuess, 0, 160, 120);
    func_800FB3B0_GhostGuess();
}

void func_800F6AAC_GhostGuess(void) {
    if (func_80072718() == 0) {
        func_800FB21C_GhostGuess();
        omOvlReturnEx(1);
    }
}

void func_800F6AE0_GhostGuess(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;

    arg0->func_ptr = NULL;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 5.0f;
    arg0->model[0] = func_800174C0(0x1C0000, 0x2DD);
    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 31000);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 0;
    func_80009000(arg0, 4, 1.0f);
    func_80008FC4(arg0, 20.0f);
    func_80008FB8(arg0, 1.0f);
}

void func_800F6BA4_GhostGuess(omObjData* arg0) {
    unkGlobalStruct_02* work;
    s16 i;

    arg0->func_ptr = NULL;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
    for (i = 0; i < 2; i++) {
        arg0->model[i] = func_800174C0(D_800FB6D8_GhostGuess[i] | 0x1C0000, 0x2D9);
        func_80025798(arg0->model[i], arg0->trans.x, arg0->trans.y, arg0->trans.z);
        func_80025830(arg0->model[i], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    }
    func_80025EB4(arg0->model[1], 2, 2);
    D_800F2B7C[arg0->model[1]].unk_4C = 0.2f;
    arg0->model[2] = func_80023FC8(arg0->model[1]);
    func_80025EB4(arg0->model[2], 2, 2);
    D_800F2B7C[arg0->model[2]].unk_4C = 0.2f;
    func_800257E4(arg0->model[2], 0.0f, 180.0f, 0.0f);
    func_80025CA8(arg0->model[2], func_80025D40(arg0->model[1]) * 0.66);
    arg0->model[3] = func_80023FC8(arg0->model[1]);
    func_80025EB4(arg0->model[3], 2, 2);
    D_800F2B7C[arg0->model[3]].unk_4C = 0.2f;
    func_80025CA8(arg0->model[3], func_80025D40(arg0->model[1]) * 0.33);
    work = func_80023684(sizeof(unkGlobalStruct_02), 31000);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(unkGlobalStruct_02));
    work->unk_04 = 1;
    work->unk_05 = 0;
    D_800EE9A0.def[0].col[0] = D_800EE9A0.def[0].col[1] = D_800EE9A0.def[0].col[2] = 0;
    D_800EE9A0.def[1].col[0] = D_800EE9A0.def[1].col[1] = D_800EE9A0.def[1].col[2] = 0xC0;
    D_800EE9A0.def[1].dir[0] = 1;
    D_800EE9A0.def[1].dir[1] = 0x40;
    D_800EE9A0.def[1].dir[2] = 0x40;
    SetFadeInTypeAndTime(0, 0x10);
}
// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800F6E78_GhostGuess(omObjData* arg0) {
    GGRec* r;
    s32 i;

    D_800FBEDC_GhostGuess = arg0;
    D_800FBEDA_GhostGuess = 1;
    D_800FBED2_GhostGuess = 0;
    arg0->func_ptr = &func_800F80E4_GhostGuess;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.5f;
    arg0->model[0] = func_800174C0(0x180006, 0x9D);
    D_800F2B7C[arg0->model[0]].unk_4C = 0.0f;
    D_800FBF10_GhostGuess = ReadImgPackand(0x21, 0x284, 8);
    for (i = 1; i < 11; i++) {
        r = &D_800FBED0_GhostGuess[i];
        r->unk_40 = D_800ECDE0[func_8001E1D0(D_800FBED0_GhostGuess[0].unk_40, 8)].unk_00;
        func_80025930(r->unk_40, 0x70000000, 0x70000000);
        r->unk_0A = 1;
        r->unk_08 = 0;
        r->unk_02 = 0;
        r->scale.x = r->scale.y = r->scale.z = 3.0f;
        func_80025830(r->unk_40, r->scale.x, r->scale.y, r->scale.z);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F6E78_GhostGuess);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F6FF4_GhostGuess);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", D_800FB720_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F73E0_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F789C_GhostGuess);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", D_800FB760_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F79D4_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F7FD8_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F80E4_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F86CC_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F8888_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F9400_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F948C_GhostGuess);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800FA764_GhostGuess);

void func_800FB21C_GhostGuess(void) {
}

void func_800FB224_GhostGuess(omObjData* arg0, u32 arg1) { //construct pointer into u8s
    arg0->work[0] = arg1 >> 24;
    arg0->work[1] = arg1 >> 16;
    arg0->work[2] = arg1 >> 8;
    arg0->work[3] = arg1;
}

s32 func_800FB244_GhostGuess(omObjData* arg0) { //deconstruct u8s in struct into a pointer
    return  (arg0->work[0] << 24) |
            (arg0->work[1] << 16) |
            (arg0->work[2] << 8) |
            arg0->work[3];
}

void func_800FB270_GhostGuess(s16 arg0, s16 arg1) {
    unk_ovl_2D_struct* m = &D_800F2B7C[arg0];

    m->unk_6C->unk_66--;
    m->unk_6C = D_800F2B7C[arg1].unk_6C;
    m->unk_6C->unk_66++;
}

/* Sets the alpha byte of every RGBA32 texel of the texture model[arg0] uses. */
void func_800FB2D0_GhostGuess(s32 arg0, s32 arg1) {
    unk2C0C0Struct70* tex;
    unk2C0C0StructC0* target;
    u32* px;
    s32 i;
    s32 j;
    s32 a;
    u32 hi;

    target = D_800F2B7C[arg0].unk_6C;
    i = -1;
    do { /* retail visits records 0..128: one past the 128 */
        i++;
        if ((D_800F37AC + i)->unk_28 == target) {
            tex = D_800F37AC + i;
            px = (u32*)tex->unk_24;
            for (j = 0; j < tex->unk_1A * tex->unk_1B; j++, px++) {
                hi = *px >> 8;
                a = arg1;
                if ((u8)a >= 0xFF) {
                    a = 0xFF;
                }
#ifdef TARGET_PC
                ((u8*)px)[3] = a; /* texel bytes are big-endian in memory */
#else
                *px = (hi << 8) | (u8)a;
#endif
            }
        }
    } while (i != 128);
}
