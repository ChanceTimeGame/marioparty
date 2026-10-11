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

FlowerShowerBodyWork* func_800F7A28_FlowerShower(omObjData*, s32, f32, f32, s32, s32, s32, s32);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F65E0_FlowerShower);

void func_800F6A64_FlowerShower(void) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F6A90_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F6FF4_FlowerShower);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", D_800FADD0_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F712C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F726C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7348_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F761C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7A28_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7BD0_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7CE0_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7DF0_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F7F00_FlowerShower);

void func_800F8010_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 0.0f, 0, 0x3C, 3, 1)->unk_68 = 0;
}

void func_800F8058_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 120.0f, 0x14, 0x3C, 3, 2)->unk_68 = 1;
}

void func_800F80A8_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 240.0f, 0x28, 0x3C, 3, 3)->unk_68 = 2;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F80F4_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8148_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8198_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F81E8_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8234_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8280_FlowerShower);

void func_800F8620_FlowerShower(void) {
    GMesCreate(8, 0x1E, 0xA0, 0x18);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8648_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F870C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8918_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F898C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F90AC_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F9224_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F95F4_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F9ACC_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA178_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA2B0_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA4EC_FlowerShower);

void func_800FA58C_FlowerShower(omObjData* arg0, f32 arg1, f32 arg2) {
    arg0->rot.x += arg1;
    arg0->rot.z += arg2;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA5B8_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FA92C_FlowerShower);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800FACA0_FlowerShower);
