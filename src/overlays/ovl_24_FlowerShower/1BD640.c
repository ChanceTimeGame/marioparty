#include "common.h"

typedef struct FlowerShowerBodyWork {
    /* 0x00 */ u8 unk_00[0x23];
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ s8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55;
    /* 0x56 */ s8 unk_56;
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[3];
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

typedef struct FlowerShowerNpcWork {
    /* 0x00 */ u8 unk_00[0x3C];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ u8 unk_40[0x13];
    /* 0x53 */ u8 unk_53;
} FlowerShowerNpcWork;

FlowerShowerBodyWork* func_800F7A28_FlowerShower(omObjData*, s32, f32, f32, s32, s32, s32, s32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
f32 func_80029518(f32);
f32 func_800FA5B8_FlowerShower(omObjData*);
f32 func_800FA92C_FlowerShower(omObjData*);
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);
void func_800090D8(omObjData*, u8, u8);
void func_800090C4(omObjData*, u8, u8);
void func_800091BC(omObjData*, s32, s32, s32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_80060F04(s16, s16, s16, s16);
void func_800FACA0_FlowerShower(omObjData*);
void func_800F7348_FlowerShower(omObjData*, s32, s32, s32);
void func_800F761C_FlowerShower(omObjData*, s32, s32, s32, f32, f32, f32);
void func_800F8280_FlowerShower(omObjData*);
void func_800F870C_FlowerShower(Matrix4f, Vec3f*, omObjData*);
void func_800F898C_FlowerShower(omObjData*, u16*);
void func_800F9ACC_FlowerShower(omObjData*);
void func_800FA2B0_FlowerShower(omObjData*, f32);
void func_800FA4EC_FlowerShower(omObjData*);

extern f32 D_800FAE50_FlowerShower;
extern f32 D_800FAE54_FlowerShower;
extern u16 D_800FAE60_FlowerShower[];
extern u16 ContBtn[];
extern s8 ContStkY[];
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern f32 D_800B8964;
extern f32 D_800B8984;
extern f32 D_800FADCC_FlowerShower;
extern u8 D_800F64F8;
extern s32 D_800FAD64_FlowerShower;
extern s32 D_800FAD4C_FlowerShower;
extern s32 D_800FAD60_FlowerShower;
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

void func_800F712C_FlowerShower(omObjData* arg0) {
    FlowerShowerModelWork* work;

    arg0->model[0] = func_800174C0(0x380002, 0x499);
    arg0->model[1] = func_800174C0(0x380003, 0x499);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], 0.0f, arg0->trans.y, arg0->trans.z);
    work = func_80023684(sizeof(FlowerShowerModelWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(FlowerShowerModelWork));
    arg0->func_ptr = func_800FA4EC_FlowerShower;
    work->unk_04 = 2;
    func_80008FB8(arg0, 0.5f);
    func_80009000(arg0, 2, 0.0f);
    work->unk_05 = 1;
    omSetStatBit(arg0, 0xA0);
    func_80039C48("47mt003_DEF", D_800FAE60_FlowerShower);
    func_80026040(arg0->model[0]);
    func_80026040(arg0->model[1]);
    func_80025798(arg0->model[1], 0.0f, -5.0f, 0.0f);
}

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

void func_800F7348_FlowerShower(omObjData* arg0, s32 arg1, s32 arg2, s32 arg3) {
    FlowerShowerBodyWork* work;
    s32 motion;
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = 0x699;
    temp_v1 = 0x289;
    func_8000979C(arg0, arg1, arg2, arg3 & 0xFFFF, temp_v0, temp_v1);
    func_80025930(arg0->model[1], 0x80000000, 0);
    motion = 0x38;
    func_80025AD4(arg0->model[1]);
    func_80025B34(arg0->model[1]);
    func_8009EA40(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 15.0f, 0.0f);
    func_80009340(arg0, 2, 0x25, 0x289, 0);
    arg0->model[3] = LoadFormFile(0x19, 0x289);
    arg0->model[4] = LoadFormFile(0x1A, 0x289);
    if ((rand8() & 0xFF) >= 0x80U) {
        motion = 0xF;
    }
    func_8001874C(arg0, 0, arg1, 1, 0);
    func_8001874C(arg0, 1, arg1 | 1, 1, 0);
    func_8001874C(arg0, 2, arg1 | 3, 1, 0);
    func_8001874C(arg0, 6, arg1 | 5, 1, 0x13);
    func_8001874C(arg0, 0x10, arg1 | 0x17, 1, 0);
    func_8001874C(arg0, 0x11, arg1 | 0x18, 0, 0);
    func_8001874C(arg0, 0x15, arg1 | 0x62, 0, 0);
    func_8001874C(arg0, 3, arg1 | 0x60, 1, 0);
    func_8001874C(arg0, 4, arg1 | 0x61, 1, 0);
    func_8001874C(arg0, 0x20, arg1 | 0x67, 0, 0);
    func_8001874C(arg0, 0xD, arg1 | motion, 1, 0x78);
    arg0->func_ptr = func_800F8280_FlowerShower;
    func_800093FC(arg0, 80.0f, 640.0f, 5.0f);
    func_800090C4(arg0, 0, 2);
    func_800090C4(arg0, 1, 2);
    func_800090C4(arg0, 2, 2);
    work = arg0->unk_50;
    work->unk_50 |= 0x8000;
    func_800258EC(arg0->model[3], 4, 4);
    func_800258EC(arg0->model[4], 4, 4);
    D_800FAD60_FlowerShower = arg3 & 0xFFFF;
    func_8001E2F8(work->unk_23, 0xFF);
    func_8001E360(work->unk_23, 0xFF, 0xFF, 0xFF);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F761C_FlowerShower);

FlowerShowerBodyWork* func_800F7A28_FlowerShower(omObjData* arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    FlowerShowerBodyWork* work;

    arg0->unk_50 = func_80023684(sizeof(FlowerShowerBodyWork), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(FlowerShowerBodyWork));
    arg0->func_ptr = NULL;
    work = arg0->unk_50;
    work->unk_68 = func_80023684(sizeof(s32), 0x7918);
    func_800091BC(arg0, arg1, 0x689, 8);
    arg0->model[1] = func_800174F4(0x20, 0x299);
    func_80009340(arg0, 2, 0x25, 0x289, 8);
    func_80009340(arg0, 3, 0x2A, 0x689, 8);
    func_8001E2F8(work->unk_24, 0xF0);
    func_8001E360(work->unk_24, 0xFF, 0xFF, 0x86);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    work->unk_44 = 0.1f;
    work->unk_48 = 20.0f;
    work->unk_34 = 50.0f;
    work->unk_3C = arg3;
    work->unk_5C = arg4;
    work->unk_52 = arg6;
    work->unk_60 = arg5;
    work->unk_50 = arg7;
    func_8000941C(arg0, arg2, arg2, arg2);
    return work;
}

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

void func_800F870C_FlowerShower(Matrix4f m, Vec3f* pos, omObjData* obj) {
    f32 rx = obj->rot.x;
    f32 ry = obj->rot.y;
    f32 rz = obj->rot.z;
    f32 tx = obj->trans.x;
    f32 ty = obj->trans.y;
    f32 tz = obj->trans.z;
    f32 x = pos->x;
    f32 y = pos->y;
    f32 z = pos->z;

    if (((tx != 0.0f) | (ty != 0.0f)) || tz != 0.0f) {
        func_8009EA40(m, tx, ty, tz);
    } else {
        func_800A2A50(m);
    }
    if (((rx != 0.0f) | (ry != 0.0f)) || rz != 0.0f) {
        MtxRotate(m, rx, ry, rz);
    }
    pos->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    pos->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    pos->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

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

void func_800F90AC_FlowerShower(omObjData* arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s3;
    s32 temp_s4;
    u16* temp_a0;
    u16* temp_a1;
    u16* temp_v0;
    u16 temp_s5;
    u16 temp_s6;
    FlowerShowerBodyWork* temp_s2;

    temp_s2 = arg0->unk_50;
    temp_s0 = temp_s2->unk_56;
    temp_v0 = ContBtnTrg;
    temp_a1 = &temp_v0[temp_s0];
    temp_s5 = *temp_a1;
    temp_a0 = &ContBtn[temp_s0];
    temp_s6 = *temp_a0;
    temp_s4 = ContStkX[temp_s0];
    temp_s3 = ContStkY[temp_s0];
    if (GwPlayer[temp_s2->unk_58].flags & 1) {
        ContStkY[temp_s0] = 0;
        ContStkX[temp_s0] = 0;
        *temp_a0 = 0;
        *temp_a1 = 0;
        func_800F898C_FlowerShower(arg0, temp_a1);
    }
    func_80005A28(arg0);
    ContBtnTrg[temp_s0] = temp_s5;
    ContBtn[temp_s0] = temp_s6;
    ContStkX[temp_s0] = temp_s4;
    ContStkY[temp_s0] = temp_s3;
    temp_s0_2 = temp_s2->unk_53;
    if (temp_s0_2 == 1) {
        func_800258EC(arg0->model[1], 4, 4);
        if (D_800FAD64_FlowerShower == 0) {
            func_80060540(0x2CD, temp_s2->unk_58);
            D_800FAD64_FlowerShower = temp_s0_2;
            func_80060F04(temp_s2->unk_58, 20, 0, 20);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F9224_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F95F4_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F9ACC_FlowerShower);

void func_800FA178_FlowerShower(omObjData* arg0) {
    FlowerShowerBodyWork* work = arg0->unk_50;
    f32 speed;

    if (work->unk_54 == 0) {
        if (D_800ED430 == 1) {
            if (work->unk_5C > work->unk_60) {
                func_800093FC(arg0, 0.0f, 1000.0f, 0.0f);
                work->unk_3C = func_80029518(work->unk_3C);
                speed = work->unk_50;
                work->unk_40 = speed;
                if (speed > 3.3f) {
                    work->unk_40 = 3.3f;
                }
                work->unk_38 = 0.0f;
                work->unk_54 = 1;
                work->unk_5C = 0;
                func_800090D8(arg0, 0, 1);
                func_800090D8(arg0, 1, 1);
                func_800F9ACC_FlowerShower(arg0);
                work->unk_60--;
                if (work->unk_60 < 10) {
                    work->unk_60 = 10;
                }
            }
            work->unk_5C++;
            work->unk_3C -= work->unk_50;
        }
    } else {
        func_800F9ACC_FlowerShower(arg0);
    }
}

void func_800FA2B0_FlowerShower(omObjData* arg0, f32 arg1) {
    FlowerShowerModelWork* model_work = arg0->unk_50;
    FlowerShowerBodyWork* body_work;
    FlowerShowerNpcWork* npc_work;
    omObjData* obj;
    f32 dx;
    f32 dz;
    f32 distance;
    f32 angle;
    s16 i;

    arg0->rot.y += arg1;
    i = 0;
    if (D_800F2BC0 != 0) {
        do {
            obj = D_800F3FB0[i];
            body_work = obj->unk_50;
            if (body_work->unk_53 == model_work->unk_05) {
                dx = arg0->trans.x - obj->trans.x;
                dz = arg0->trans.z - obj->trans.z;
                distance = func_800B1750(dx * dx + dz * dz);
                angle = func_800B0CD8(obj->trans.x, obj->trans.z) + arg1;
                if (arg1 != 0.0f) {
                    obj->trans.x = func_800AEAC0(angle) * distance;
                    obj->trans.z = func_800AEFD0(angle) * distance;
                    body_work->unk_3C += arg1;
                }
            }
            i++;
        } while (i < D_800F2BC0);
    }
    i = 0;
    if (D_800EE984 != 0) {
        do {
            obj = D_800EDE70[i];
            npc_work = obj->unk_50;
            if (npc_work->unk_53 == model_work->unk_05) {
                dx = arg0->trans.x - obj->trans.x;
                dz = arg0->trans.z - obj->trans.z;
                distance = func_800B1750(dx * dx + dz * dz);
                angle = func_800B0CD8(obj->trans.x, obj->trans.z) + arg1;
                if (arg1 != 0.0f) {
                    obj->trans.x = func_800AEAC0(angle) * distance;
                    obj->trans.z = func_800AEFD0(angle) * distance;
                    npc_work->unk_3C += arg1;
                }
            }
            i++;
        } while (i < D_800EE984);
    }
}

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

f32 func_800FA5B8_FlowerShower(omObjData* arg0) {
    Matrix4f matrix;
    Vec3f pos;
    FlowerShowerModelWork* model_work;
    FlowerShowerBodyWork* body_work;
    omObjData* obj;
    f32 result = 0.0f;
    f32 original_rot;
    f32 dx;
    f32 dz;
    f32 distance;
    f32 angle;
    s16 i;
    u8 team;

    model_work = arg0->unk_50;
    team = model_work->unk_05;
    original_rot = arg0->rot.x;
    i = 0;
    if (D_800F2BC0 != 0) {
        do {
            obj = D_800F3FB0[i];
            body_work = obj->unk_50;
            if (body_work->unk_53 == team) {
                pos.x = arg0->trans.x;
                pos.y = 310.0f;
                pos.z = arg0->trans.z;
                func_800F870C_FlowerShower(matrix, &pos, arg0);
                dx = pos.x - obj->trans.x;
                dz = pos.z - obj->trans.z;
                distance = func_800B1750(dx * dx + dz * dz);
                if (distance != 0.0f) {
                    angle = func_800B0CD8(obj->trans.x, -obj->trans.z);
                    if (distance > 360.0f) {
                        body_work->unk_38 = -D_800B8964 * 0.5f;
                        body_work->unk_3C = func_800B0CD8(obj->trans.x, obj->trans.z);
                        func_800184BC(obj, 6);
                        body_work->unk_40 = D_800B8984;
                        body_work->unk_50 |= 0x10;
                    }
                    if ((angle > 120.0f) | (angle < -120.0f)) {
                        result += distance / 400.0f;
                        break;
                    }
                    if ((angle < 60.0f) & (angle > -60.0f)) {
                        result += -distance / 400.0f;
                        break;
                    }
                }
            }
            i++;
        } while (i < D_800F2BC0);
    }
    if ((fabs((f64)original_rot) > 20.0) & (result != 0.0f)) {
        result = 0.0f;
        goto done;
    }
    if ((original_rot != 0.0f) & (result == 0.0f)) {
        result = -original_rot / 20.0f;
    }
done:
    return result;
}

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
