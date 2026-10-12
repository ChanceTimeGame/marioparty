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
void func_800F6FF4_GhostGuess(omObjData* arg0) {
    s32 idle[5] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
    s32 dir;
    s32 file1;
    u8 chr;

    chr = GwPlayer[D_800FBC08_GhostGuess].character;
    dir = D_800C59AC[chr].unk_00;
    file1 = D_800C59AC[chr].unk_08;
    func_8000979C(arg0, dir, file1, (s16)D_800FBC08_GhostGuess, 0x6D9, 0x6D9);
    arg0->func_ptr = &func_800F8888_GhostGuess;
    arg0->work[0] = arg0->work[1] = arg0->work[2] = 0;
    arg0->work[3] = 0x2D;
    ((unkGlobalStruct_00*)arg0->unk_50)->unk_DC = &func_800F86CC_GhostGuess;
    arg0->model[3] = LoadFormFile(0x19, 0x68D);
    arg0->model[4] = LoadFormFile(0x1A, 0x68D);
    arg0->model[6] = LoadFormFile(0x1B, 0x68D);
    arg0->model[5] = LoadFormFile(0x1C, 0x68D);
    arg0->model[7] = LoadFormFile(0x1E, 0x68D);
    arg0->model[8] = LoadFormFile(0x1D, 0x68D);
    func_800187D0(arg0, 0, dir, 1, 0);
    func_800187D0(arg0, 1, dir | 1, 1, 0);
    func_800187D0(arg0, 2, dir | 3, 1, 0);
    func_800187D0(arg0, 5, dir | 4, 0, 0);
    func_800187D0(arg0, 6, dir | 5, 1, 0x13);
    func_800187D0(arg0, 7, dir | 6, 1, 0x22);
    func_800187D0(arg0, 8, dir | 9, 1, 0x1D);
    func_800187D0(arg0, 9, dir | 0xA, 1, 0x27);
    func_8001874C(arg0, 0xD, dir | idle[rand8() & 1], 1, 0x78);
    func_800187D0(arg0, 0x11, dir | 0x18, 0, 0);
    func_800187D0(arg0, 0x12, dir | 0x1C, 2, 0);
    func_800187D0(arg0, 0x13, dir | 0x1D, 2, 0);
    func_800187D0(arg0, 0xA, dir | 0x1E, 1, 0x27);
    func_8001874C(arg0, 3, dir | 0x60, 1, 0);
    func_8001874C(arg0, 4, dir | 0x61, 1, 0);
    func_8001874C(arg0, 0x15, dir | 0x62, 0, 0);
    func_8001874C(arg0, 0x1E, dir | 0x63, 0, 0);
    func_8001874C(arg0, 0x1F, dir | 0x64, 0, 0);
    func_8001874C(arg0, 0x20, dir | 0x67, 0, 0);
    func_8001874C(arg0, 0x21, dir | 0x68, 2, 0);
    func_8001874C(arg0, 0x22, dir | 0x69, 2, 0);
    func_8001874C(arg0, 0x23, dir | 0x93, 1, 0);
    func_800093FC(arg0, 0.0f, 0.0f, 0.0f);
    omSetTra(arg0, 0.0f, 0.0f, 0.0f);
    func_800090C4(arg0, 0, 2);
}
void func_800F73E0_GhostGuess(omObjData* arg0) {
    GGGhost* g;
    omObjData* obj;
    void* file;
    f64 angle;
    f32 a;
    f32 r;
    s32 ghostSpr;
    s32 spr1;
    s32 spr2;
    s32 i;

    D_800FBBF0_GhostGuess[0] = LoadFormFile(0x1C0004, 0x6DD);
    D_800FBBF0_GhostGuess[1] = LoadFormFile(0x1C0005, 0x6DD);
    D_800FBBF0_GhostGuess[2] = LoadFormFile(0x1C0006, 0x6DD);
    D_800FBBF0_GhostGuess[3] = LoadFormFile(0x1C0003, 0x6DD);
    D_800FBC00_GhostGuess = LoadFormFile(0x1C0007, 0x25D);
    D_800FBC04_GhostGuess = LoadFormFile(0x1C0008, 0x25D);
    file = DataRead(0x1C0009);
    ghostSpr = func_800678A4(file);
    DataClose(file);
    D_800FBEB8_GhostGuess = func_80064EF4(8, 0);
    file = DataRead(0x21);
    spr1 = func_800678A4(file);
    DataClose(file);
    file = DataRead(0x2A);
    spr2 = func_800678A4(file);
    DataClose(file);
    D_800FBEBC_GhostGuess = func_80064EF4(2, 0);
    func_80067208((s16)D_800FBEBC_GhostGuess, 0, spr1, 0);
    func_800674BC((s16)D_800FBEBC_GhostGuess, 0, 0x9000);
    func_800672B0((s16)D_800FBEBC_GhostGuess, 0, 1);
    for (i = 1; i < 2; i++) {
        func_80067208((s16)D_800FBEBC_GhostGuess, i, spr2, 0);
        func_800674BC((s16)D_800FBEBC_GhostGuess, i, 0x9000);
        func_800672B0((s16)D_800FBEBC_GhostGuess, i, 0);
        func_800674F4((s16)D_800FBEBC_GhostGuess, (s16)i, 0xFF, 0xFF, 0xBE);
    }
    arg0->func_ptr = &func_800F948C_GhostGuess;
    D_800FB69C_GhostGuess = rand8() & 7;
    for (i = 0; i < 8; i++) {
        g = &D_800FBC18_GhostGuess[i];
        if (i == D_800FB69C_GhostGuess) {
            g->unk_04 = 1;
        } else {
            g->unk_04 = 0;
        }
        g->unk_05 = i;
        angle = i * 45.0;
        a = angle;
        g->pos.x = func_800AEAC0(a) * D_800FB674_GhostGuess;
        g->pos.y = -200.0f;
        g->pos.z = func_800AEFD0(a) * D_800FB674_GhostGuess;
        g->rot.x = g->rot.z = 0.0f;
        g->rot.y = g->unk_44 = r = func_8009B618(angle + 180.0, 360.0);
        if (r <= 90.0 || r >= 270.0) {
            g->rot.y = 0.0f;
        }
        g->rot.x = 6.0f;
        g->scale.x = g->scale.y = g->scale.z = 1.0f;
        g->unk_34.x = g->unk_34.y = g->unk_34.z = 0.0f;
        g->unk_4C = 0.05f;
        g->unk_48 = g->unk_50 = 0.0001f;
        g->unk_06 = 1;
        g->unk_08 = 0;
        g->unk_0A = 0;
        obj = omAddObj(4, 1, 0, -1, &func_800F789C_GhostGuess);
        D_800EDE70[D_800EE984++] = obj;
        GG_GHOST_SET(obj, g);
        func_80067208((s16)D_800FBEB8_GhostGuess, i, ghostSpr, 0);
        func_800674BC((s16)D_800FBEB8_GhostGuess, i, 0x9000);
        func_800672B0((s16)D_800FBEB8_GhostGuess, i, 0);
        func_80067558((s16)D_800FBEB8_GhostGuess, (s16)i, 0xFF, 0xFF, 0xFF, 0xFF);
    }
}
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
