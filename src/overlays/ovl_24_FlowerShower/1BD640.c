#include "common.h"

typedef struct FlowerShowerBodyWork {
    /* 0x00 */ u8 unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s8 unk_52;
    /* 0x53 */ char unk_53[9];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ s32* unk_68;
} FlowerShowerBodyWork;

typedef struct FlowerShowerModelWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} FlowerShowerModelWork;

FlowerShowerBodyWork* func_800F7A28_FlowerShower(omObjData*, s32, f32, f32, s32, s32, s32, s32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
f32 func_800FA5B8_FlowerShower(omObjData*);
f32 func_800FA92C_FlowerShower(omObjData*);
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);
void func_800FACA0_FlowerShower(omObjData*);
void func_800F7348_FlowerShower(omObjData*, s32, s32, s32);
void func_800F761C_FlowerShower(omObjData*, s32, s32, s32, f32, f32, f32);

extern f32 D_800FAE50_FlowerShower;
extern f32 D_800FAE54_FlowerShower;
extern u16 D_800FAE60_FlowerShower[];
extern f32 D_800FADCC_FlowerShower;
extern u8 D_800F64F8;
extern s32 D_800FAD64_FlowerShower;
extern s32 D_800FAD4C_FlowerShower;
extern f32 D_800FAD50_FlowerShower[];

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F65E0_FlowerShower);

void func_800F6A64_FlowerShower(void) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F6A90_FlowerShower);

void func_800F6FF4_FlowerShower(omObjData* arg0) {
    FlowerShowerModelWork* work;

    arg0->model[0] = func_800174C0(0x380001, 0x99);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], 0.0f, arg0->trans.y, arg0->trans.z);
    work = func_80023684(sizeof(FlowerShowerModelWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(FlowerShowerModelWork));
    arg0->func_ptr = NULL;
    work->unk_04 = 1;
    Center.x = 8.0f;
    Center.y = 310.0f;
    Center.z = 23.0f;
    CRot.x = 322.9f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 1000.0f;
    func_80008FB8(arg0, 2.0f);
    func_80008FC4(arg0, 20.0f);
    work->unk_05 = 0;
    SetFadeInTypeAndTime(0, 0x10);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", D_800FADD0_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F712C_FlowerShower);

void func_800F726C_FlowerShower(omObjData* arg0) {
    FlowerShowerModelWork* work;

    arg0->model[0] = func_800174C0(0x380000, 0x99);
    arg0->trans.x = 0.0f;
    arg0->trans.y = 80.0f;
    arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    work = func_80023684(sizeof(FlowerShowerModelWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(FlowerShowerModelWork));
    arg0->func_ptr = func_800FACA0_FlowerShower;
    work->unk_04 = 1;
    func_80009000(arg0, 4, 0.0f);
    func_80008FB8(arg0, 0.5f);
    func_8000941C(arg0, 1.0f, 1.0f, 1.0f);
    work->unk_05 = 2;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7348_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F761C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7A28_FlowerShower);

void func_800F7BD0_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[0].character].unk_04;
    dir = D_800C59AC[GwPlayer[0].character].unk_00;
    if (GwPlayer[0].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 0);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 0, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F7CE0_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[1].character].unk_04;
    dir = D_800C59AC[GwPlayer[1].character].unk_00;
    if (GwPlayer[1].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 1);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 1, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F7DF0_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[2].character].unk_04;
    dir = D_800C59AC[GwPlayer[2].character].unk_00;
    if (GwPlayer[2].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 2);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 2, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F7F00_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[3].character].unk_04;
    dir = D_800C59AC[GwPlayer[3].character].unk_00;
    if (GwPlayer[3].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 3);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 3, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F8010_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 0.0f, 0, 0x3C, 3, 1)->unk_68 = 0;
}

void func_800F8058_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 120.0f, 0x14, 0x3C, 3, 2)->unk_68 = 1;
}

void func_800F80A8_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 240.0f, 0x28, 0x3C, 3, 3)->unk_68 = 2;
}

void func_800F80F4_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 90.0f, 0x1E, 0x3C, 3, 4)->unk_68 = 3;
}

void func_800F8148_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 270.0f, 0x3B, 0x3C, 3, 5)->unk_68 = 4;
}

void func_800F8198_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 180.0f, 0xA, 0x3C, 3, 6)->unk_68 = 5;
}

void func_800F81E8_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x22, 3.0f, 90.0f, 0, 0xB4, 4, 7)->unk_68 = 6;
}

void func_800F8234_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x23, 2.0f, 180.0f, 0, 0xB4, 5, 8)->unk_68 = 7;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8280_FlowerShower);

void func_800F8620_FlowerShower(void) {
    GMesCreate(8, 0x1E, 0xA0, 0x18);
}

void func_800F8648_FlowerShower(omObjData* arg0, u8 arg1, u32 arg2) {
    switch (arg1) {
        case 0:
            if (arg2 == 0) {
                GMesCreate(0);
            }
            break;
        case 1:
            func_80079078(arg2 / 60);
            break;
        case 2:
            if (arg2 == 0) {
                if (_CheckFlag(0x2B) == 0 && D_800FAD64_FlowerShower != 0) {
                    GMesCreate(0xE);
                } else {
                    GMesCreate(2);
                }
                func_800790C0();
            }
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F870C_FlowerShower);

f32 func_800F8918_FlowerShower(omObjData* arg0, f32 arg1, f32 arg2, f32 arg3, Vec3f* arg4) {
    Vec4f sp18;
    f32 temp_f0;
    f32 var_f20 = -10000.0f;

    sp18.x = arg1;
    sp18.y = arg2;
    sp18.z = arg3;
    sp18.w = 10.0f;
    temp_f0 = func_800051D4(arg0, arg1, arg2, arg3, arg4);
    if (temp_f0 > -10000.0f) {
        var_f20 = temp_f0;
    }
    return var_f20;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F898C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F90AC_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F9224_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F95F4_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F9ACC_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA178_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA2B0_FlowerShower);

void func_800FA4EC_FlowerShower(omObjData* arg0) {
    if (((func_8005FD5C() & 0xFFFF) + D_800F64F8) == 0) {
        D_800FADCC_FlowerShower += 0.2f;
    }
    func_80027E48(arg0->model[0], D_800FADCC_FlowerShower, 0.0f, D_800FAE60_FlowerShower[0],
                  D_800FAE60_FlowerShower[1], "No47happy-47m_002", 1);
}

void func_800FA58C_FlowerShower(omObjData* arg0, f32 arg1, f32 arg2) {
    arg0->rot.x += arg1;
    arg0->rot.z += arg2;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA5B8_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA92C_FlowerShower);

void func_800FACA0_FlowerShower(omObjData* arg0) {
    f32 temp_f0;

    if (D_800ED430 == 1) {
        func_80008FC4(arg0, 30.0f);
        D_800FAE50_FlowerShower = func_800FA5B8_FlowerShower(arg0);
        temp_f0 = func_800FA92C_FlowerShower(arg0);
        D_800FAE54_FlowerShower = temp_f0;
        func_800FA58C_FlowerShower(arg0, D_800FAE50_FlowerShower, temp_f0);
        return;
    }
    func_80008FC4(arg0, 0.0f);
}
