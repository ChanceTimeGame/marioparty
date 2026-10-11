#include "common.h"

typedef struct unkHammerDropStruct {
    char unk_00[0x38];
    s32 unk_38;
    f32 unk_3C;
} unkHammerDropStruct;

typedef struct HammerDropPlayerState {
    char unk_00[0x24];
    s32 unk_24;
    char unk_28[0x4];
    s32 unk_2C;
    char unk_30[0x1C];
    s32 unk_4C;
    volatile s32 unk_50;
    f32 unk_54;
    s32 unk_58;
} HammerDropPlayerState;

typedef struct HammerDropItemState {
    /* 0x00 */ char unk_00[0x2C];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
} HammerDropItemState;

typedef struct HammerDropTargetState {
    /* 0x00 */ char unk_00[0x2C];
    /* 0x2C */ s32 itemIndex;
    /* 0x30 */ f32 unk_30;
} HammerDropTargetState;

/* Work for the six collision-list items. The fields through 0x64 are the main-code PlayerWork
 * layout; the overlay-owned extension at 0x68 is a pointer and therefore widens on the host. */
typedef struct HammerDropItemWork {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ char unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ HammerDropItemState* item;
} HammerDropItemWork;

#define HAMMER_ITEM_WORK(obj) ((HammerDropItemWork*)(obj)->unk_50)

void func_8000A534(omObjData*, s32);
void func_80017C0C(omObjData*, s32, f32, f32, f32, s32, f32);
void func_80018450(omObjData*, s32);
void func_80060F04(s16, s32, s32, s32);
void func_800091BC(omObjData*, s32, s32, s32);
void func_800370D4(s16);

void func_800F67BC_HammerDrop(void);
void func_800F7D28_HammerDrop(void);
void func_800F8508_HammerDrop(void);
void func_800F9350_HammerDrop(void);
void func_800F7488_HammerDrop(omObjData* arg0);
void func_800F74A4_HammerDrop(omObjData* arg0);
void func_800F74C0_HammerDrop(omObjData* arg0);
void func_800F74DC_HammerDrop(omObjData* arg0);
void func_800FA2D8_HammerDrop(void);
void func_800FA2E0_HammerDrop(void);
void func_800F6ADC_HammerDrop(void);
void func_800FB050_HammerDrop(void);
void func_800F6848_HammerDrop(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_800F6814_HammerDrop(void);
void func_800F690C_HammerDrop(omObjData* arg0);
void func_800F6A54_HammerDrop(omObjData* arg0);
void func_800F6AF8_HammerDrop(omObjData* arg0, s32 arg1);
void func_800F7D64_HammerDrop(void);
void func_800F7DEC_HammerDrop(void);
void func_800F7E28_HammerDrop(void);
void func_800F7EF4_HammerDrop(void);
void func_800F7F58_HammerDrop(omObjData* arg0);
void func_800F7F90_HammerDrop(void);
void func_800F7FFC_HammerDrop(omObjData* arg0);
void func_800F8080_HammerDrop(void);
void func_800F813C_HammerDrop(omObjData* arg0);
void func_800F82E0_HammerDrop(void);
void func_800F8394_HammerDrop(omObjData* arg0);
void func_800F84A0_HammerDrop(omObjData* arg0);
void func_800F95E8_HammerDrop(omObjData* arg0);
void func_800F9794_HammerDrop(omObjData* arg0);
f32 func_800FA1AC_HammerDrop(f32 arg0);
void func_800F9E98_HammerDrop(Vec* from, Vec* to, Vec* out);
s32 func_800F9E68_HammerDrop(s32 arg0, s32 arg1);
void func_800F9E74_HammerDrop(s32* arg0, s32 arg1, s32 arg2);

extern f32 D_800B8964;
extern f32 D_800B8980;
extern s32 D_800B8988;
extern omObjData* D_800FB998_HammerDrop[];
extern s32 D_800FB6A0_HammerDrop;
extern s16 ContBtn[];
//extern s8 ContStkX[];
extern s8 ContStkY[];
extern f32 D_800ED6B8;
extern s32 D_800EDEC0;
extern s16 D_800EE984;
extern u16 D_800F370C;
extern f32 D_800F5254;
extern u8 D_800FB5C0_HammerDrop[];
extern s32 D_800FB6A4_HammerDrop;
extern s32 D_800FB6C4_HammerDrop;
extern s32 D_800FB6C8_HammerDrop;
extern s32 D_800FB988_HammerDrop;
extern s32 D_800FB98C_HammerDrop;
extern u16 D_800F5144;
extern f32 D_800FB6CC_HammerDrop;
extern omObjData* D_800F2AF8[];
extern u16 D_800FB6A8_HammerDrop;
extern u16 D_800FB6AA_HammerDrop;
extern s32 D_800FB980_HammerDrop;
extern s32 D_800FB6B0_HammerDrop[4];
extern omObjData* D_800FB990_HammerDrop;
extern omObjData* D_800EDE70[];
extern char D_800FB620_HammerDrop[];
extern s32 D_800FB590_HammerDrop[4];
extern f32 D_800FB5A0_HammerDrop;
extern f32 D_800FB5A4_HammerDrop;
extern f32 D_800FB5A8_HammerDrop;
extern f32 D_800FB5AC_HammerDrop;
extern f32 D_800FB5B0_HammerDrop;
extern f32 D_800FB5B4_HammerDrop[3];
extern f32 D_800FB5C8_HammerDrop[4];
extern f32 D_800FB5D8_HammerDrop[4];
extern f32 D_800FB5E8_HammerDrop[4];
extern f32 D_800FB5F8_HammerDrop[4];
extern s32 D_800FB634_HammerDrop[3];
extern u16 D_800FB640_HammerDrop[4];
extern u16 D_800FB648_HammerDrop[4];
extern f64 D_800FB650_HammerDrop;
extern f64 D_800FB658_HammerDrop;
extern f64 D_800FB660_HammerDrop;
extern f64 D_800FB668_HammerDrop;
extern char D_800FB670_HammerDrop[];
extern char D_800FB67C_HammerDrop[20];
extern f64 D_800FB690_HammerDrop;
extern f64 D_800FB698_HammerDrop;
