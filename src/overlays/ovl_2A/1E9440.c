#include "common.h"
#include "engine/pad.h"

/* ovl_2A (name_2A): a 2 vs 2 ball minigame. Two teams (GwPlayer[].group) chase one ball (D_800FE040)
   and score by putting it through the hoop object D_800FE048 (at its position + (0, 350, -560)).
   Types come from the asm's accesses; N64 offsets are in the comments. Work blocks are allocated
   with sizeof: the host strides pointers 8 bytes. */

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player object's work (func_8000979C allocates a MgWork, 0xE8). MgWork's layout (src/99E0.c)
   with the fields this overlay touches; its pointers sit where MgWork's do (0xB8, 0xD8, 0xE4). */
typedef struct N2APlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60; /* camera yaw */
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ char unk_68[0x3C];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[9];
    /* 0xB1 */ s8 unk_B1; /* player the ball was passed to, -1 none */
    /* 0xB2 */ char unk_B2[6];
    /* 0xB8 */ void* unk_B8; /* MgWork's held item: a pointer in every view of this work */
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* motion table, one pair per motion */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ s32 unk_E0;
    /* 0xE4 */ struct N2APlayerExt* unk_E4;
} N2APlayerWork; /* size = 0xE8 */

/* The overlay's per-player extension (N2APlayerWork.unk_E4; func_80023684(0xE8) in
   func_800F8940). No pointers. */
typedef struct N2APlayerExt {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C; /* last position */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ char unk_18[0xC];
    /* 0x24 */ f32 unk_24; /* CPU target x */
    /* 0x28 */ f32 unk_28; /* CPU target z */
    /* 0x2C */ s32 player;
    /* 0x30 */ char unk_30[4];
    /* 0x34 */ f32 unk_34; /* stick angle */
    /* 0x38 */ f32 unk_38; /* N2APlayerWork.unk_38 this frame */
    /* 0x3C */ s32 unk_3C; /* CPU timer */
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ f32 unk_44; /* N2APlayerWork.unk_38 last frame */
    /* 0x48 */ f32 unk_48; /* home x */
    /* 0x4C */ f32 unk_4C; /* home z */
    /* 0x50 */ s32 unk_50; /* controller port */
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ f32 unk_58[31]; /* unk_38 history; func_800FB878 shifts [29] into [30] = unk_D0 */
    /* 0xD4 */ s32 unk_D4; /* CPU action frames */
    /* 0xD8 */ s32 unk_D8; /* CPU level 0..3 */
    /* 0xDC */ s32 unk_DC; /* CPU action flags */
    /* 0xE0 */ f32 unk_E0; /* CPU heading */
    /* 0xE4 */ s32 unk_E4; /* slot within the team */
} N2APlayerExt; /* size = 0xE8 */

#define unk_D0 unk_58[30]

/* The ball's extension (N2ABallWork.unk_68; func_80023684(0x68) in func_800FC098). No pointers. */
typedef struct N2ABallExt {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char unk_24[0xC];
    /* 0x30 */ f32 unk_30; /* demo target x */
    /* 0x34 */ f32 unk_34; /* demo target z */
    /* 0x38 */ char unk_38[8];
    /* 0x40 */ f32 unk_40; /* vertical speed */
    /* 0x44 */ f32 unk_44; /* demo speed */
    /* 0x48 */ s32 unk_48; /* holder, -1 none */
    /* 0x4C */ s32 unk_4C; /* last frame's holder */
    /* 0x50 */ f32 unk_50; /* gravity */
    /* 0x54 */ f32 unk_54; /* bounce speed */
    /* 0x58 */ s32 unk_58; /* rest timer */
    /* 0x5C */ f32 unk_5C; /* last position */
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
} N2ABallExt; /* size = 0x68 */

/* The ball's (and the hoop's) work: main code's PlayerWork layout to 0x64 (func_80004D1C reads
   it), then the overlay's extension pointer. */
typedef struct N2ABallWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C; /* heading */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44; /* friction */
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ char unk_52[6];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ char unk_5C[0xC];
    /* 0x68 */ N2ABallExt* unk_68;
} N2ABallWork;

/* The camera objects' work (func_800F7760, func_800F7C00: 0x20). */
typedef struct N2ACamWork {
    /* 0x00 */ s32 unk_00; /* timer / bounce count */
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14; /* state */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
} N2ACamWork; /* size = 0x20 */

#define N2A_PLAYER(obj) ((N2APlayerWork*)(obj)->unk_50)
#define N2A_BALL(obj) ((N2ABallWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Bss
   --------------------------------------------------------------------------------------------- */
extern s32 D_800FDF40_name_2A;
extern f32 D_800FDF44_name_2A;
extern f32 D_800FDF48_name_2A;
extern f32 D_800FDF4C_name_2A;
extern f32 D_800FDF50_name_2A;
extern f32 D_800FDF54_name_2A; /* throw speed */
extern u16 D_800FDF58_name_2A; /* seconds left */
extern u16 D_800FDF5A_name_2A; /* frames to the next second */
extern s32 D_800FDF60_name_2A[4]; /* per-player flags; 1 = team 0 */
extern s32 D_800FDF70_name_2A; /* ball flags */
extern s32 D_800FDF74_name_2A; /* 1 = scored */
extern s32 D_800FDF78_name_2A; /* camera flags */
extern s32 D_800FDF7C_name_2A;
extern s16 D_800FDF82_name_2A; /* never written: model 0 */
extern s32 D_800FDF90_name_2A;
extern s32 D_800FDF94_name_2A;
extern s32 D_800FDF98_name_2A; /* last holder */
extern s32 D_800FDF9C_name_2A;
extern s32 D_800FDFA0_name_2A;
extern s32 D_800FDFA4_name_2A[2]; /* players placed at each basket end */
extern f32 D_800FDFAC_name_2A;
extern f32 D_800FDFB0_name_2A; /* Mini-Game Island */
extern PB_PTR32 D_800FDFC0_name_2A;
extern s16 D_800FDFC4_name_2A;
extern f32 D_800FDFC8_name_2A;
extern f32 D_800FDFD0_name_2A;
extern omObjData* D_800FDFD4_name_2A;
extern omObjData* D_800FDFD8_name_2A;
extern f32 D_800FE020_name_2A;
extern s32 D_800FE024_name_2A; /* game state */
extern s16 D_800FE028_name_2A;
extern u8 D_800FE02A_name_2A;
extern omObjData* D_800FE02C_name_2A; /* ball shadow */
extern omObjData* D_800FE030_name_2A[4]; /* players */
extern omObjData* D_800FE040_name_2A; /* ball */
extern PB_PTR32 D_800FE044_name_2A;
extern omObjData* D_800FE048_name_2A; /* hoop */
extern f32 D_800FE04C_name_2A;
extern s32 D_800FE050_name_2A;

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;
extern f32 D_800ED6B8;
extern f32 D_800F5254;
extern f32 D_800B8990;

void* func_80014614(s32);
void DataCloseTemp(void*);
void func_80004D1C(omObjData*, Vec4f*, f32);
void func_8000A534(omObjData*, s32);
void func_8000A634(omObjData*, omObjData*);
void func_8000A6F4(omObjData*);
void func_80008FAC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80009E20(omObjData*);
s32 func_80017A60(omObjData*);
s32 func_800185A4(omObjData*, u16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
s16 func_80025E48(s16);
void func_80025BB8(s16, s16);
void func_80028498(s16, s16, s32);
void func_800284E4(s16);
void func_800370D4(s16);
void func_80021E58(void);
void func_80021EC0(s32, f32, f32, f32);
#ifdef TARGET_PC
void func_80060F04(s16, s16, s16, s16); /* host: matches the definition */
#else
void func_80060F04(s16, s32, s32, s32);
#endif
void func_8006B9B0(PB_PTR32, s32, f32, f32);
void func_8006B9C0(PB_PTR32, s32, s32, s32);
void func_8006B9D0(PB_PTR32, f32, f32, f32);
void func_8006BAD0(PB_PTR32, s32);
void func_8006BB08(PB_PTR32, s32);
void func_8006BADC(PB_PTR32, f32, f32, f32);
void func_8006BAF0(PB_PTR32, s32);
s32 func_8006BAFC(PB_PTR32);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
void func_800F6810_name_2A(void);
void func_800F6880_name_2A(void);
void func_800F68E0_name_2A(omObjData* obj);
void func_800F69D8_name_2A(void);
void func_800F6A3C_name_2A(omObjData* obj);
void func_800F6AA0_name_2A(void);
void func_800F6B10_name_2A(omObjData* obj);
void func_800F6B94_name_2A(void);
void func_800F6CCC_name_2A(omObjData* obj);
void func_800F6DB8_name_2A(void);
void func_800F6DF8_name_2A(void);
void func_800F6E74_name_2A(omObjData* obj);
void func_800F6EDC_name_2A(void);
void func_800F7030_name_2A(omObjData* obj);
void func_800F7094_name_2A(void);
void func_800F7144_name_2A(omObjData* obj);
void func_800F7190_name_2A(omObjData* obj);
void func_800F71D4_name_2A(void);
void func_800F728C_name_2A(omObjData* obj);
void func_800F731C_name_2A(void);
void func_800F7350_name_2A(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z);
void func_800F7440_name_2A(omObjData* obj);
void func_800F7760_name_2A(s32 player);
void func_800F79E8_name_2A(omObjData* obj);
void func_800F7C00_name_2A(void);
void func_800F7C84_name_2A(omObjData* obj);
void func_800F81B8_name_2A(omObjData* obj);
void func_800F836C_name_2A(omObjData* obj);
void func_800F8438_name_2A(omObjData* obj);
void func_800F84B0_name_2A(omObjData* obj);
void func_800F8530_name_2A(omObjData* obj);
void func_800F85C0_name_2A(omObjData* obj);
void func_800F878C_name_2A(omObjData* obj);
void func_800F8830_name_2A(omObjData* obj);
void func_800F8940_name_2A(omObjData* obj, s32 player);
void func_800F9050_name_2A(omObjData* obj);
void func_800F9E20_name_2A(omObjData* obj);
void func_800F9E3C_name_2A(omObjData* obj);
void func_800F9E58_name_2A(omObjData* obj);
void func_800F9E74_name_2A(omObjData* obj);
s32 func_800F9E90_name_2A(s32 player);
void func_800F9F1C_name_2A(omObjData* obj);
void func_800FA088_name_2A(omObjData* obj);
void func_800FA124_name_2A(void);
void func_800FA1CC_name_2A(omObjData* obj);
void func_800FA614_name_2A(omObjData* obj);
void func_800FA8EC_name_2A(omObjData* obj);
void func_800FAEEC_name_2A(omObjData* obj);
f32 func_800FB280_name_2A(omObjData* a, omObjData* b);
void func_800FB2DC_name_2A(N2APlayerExt* ext, s32 arg1);
void func_800FB334_name_2A(N2APlayerExt* ext);
void func_800FB3FC_name_2A(omObjData* obj);
void func_800FB6A8_name_2A(omObjData* obj);
void func_800FB6F0_name_2A(omObjData* obj);
f32 func_800FB718_name_2A(omObjData* obj);
f32 func_800FB79C_name_2A(omObjData* obj);
void func_800FB878_name_2A(N2APlayerExt* ext);
void func_800FB8BC_name_2A(void);
void func_800FBB50_name_2A(omObjData* obj);
void func_800FBFC8_name_2A(omObjData* obj);
void func_800FC098_name_2A(void);
void func_800FC364_name_2A(omObjData* obj);
void func_800FC70C_name_2A(omObjData* obj);
void func_800FC7A4_name_2A(omObjData* obj);
void func_800FC8C8_name_2A(N2ABallExt* ext);
void func_800FC990_name_2A(omObjData* obj, Vec* out);
void func_800FC9EC_name_2A(omObjData* obj, s32 player);
void func_800FCB5C_name_2A(omObjData* obj);
void func_800FD1B4_name_2A(omObjData* obj);
void func_800FD20C_name_2A(omObjData* obj);
void func_800FD254_name_2A(omObjData* obj);
void func_800FD428_name_2A(void);
void func_800FD54C_name_2A(void);
void func_800FD670_name_2A(omObjData* obj);
f32 func_800FD7D8_name_2A(omObjData* obj);
s32 func_800FD850_name_2A(s32 flags, s32 mask);
void func_800FD85C_name_2A(s32* flags, s32 mask, s32 set);
void func_800FD880_name_2A(Vec* from, Vec* to, Vec* out);
f32 func_800FDBF4_name_2A(f32 x);
void func_800FDD44_name_2A(void);

/* ---------------------------------------------------------------------------------------------
   Code
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_name_2A(void) {
    func_800F6810_name_2A();
    func_80029090(5);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_80009500();
    func_8001DE70(0x3C);
    omInitObjMan(0x1E, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800F7350_name_2A(2130.0f, 339.0f, 0.0f, 0.0f, 0.0f, 0.0f, -560.0f);
    func_8005D98C(4, 4);
    omAddObj(0xA, 0, 0, -1, &func_800F731C_name_2A);
    omAddObj(2, 3, 0, -1, &func_800F81B8_name_2A);
    omAddObj(2, 3, 0, -1, &func_800F836C_name_2A);
    omAddObj(2, 1, 0, -1, &func_800F84B0_name_2A);
    omAddObj(2, 1, 0, -1, &func_800F8530_name_2A);
    D_800FDF90_name_2A = 0;
    D_800FDF94_name_2A = 0;
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E20_name_2A);
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E3C_name_2A);
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E58_name_2A);
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E74_name_2A);
    func_800F6880_name_2A();
    func_800FC098_name_2A();
    func_800F7C00_name_2A();
    func_8007B168((u8*)"\x82\x60\x82\x61\x82\x62", 1); /* "ＡＢＣ" (Shift-JIS) */
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6810_name_2A(void) {
    D_800ED440 = 0;
    D_800F2BC0 = 0;
    D_800EE984 = 0;
    D_800FE050_name_2A = 0;
    D_800FDF9C_name_2A = 0;
    D_800FDFA0_name_2A = 0;
    D_800FDFA4_name_2A[0] = 0;
    D_800FDFA4_name_2A[1] = 0;
    D_800FDFB0_name_2A = _CheckFlag(MINIGAME_ISLAND_ENDING);
}

void func_800F6880_name_2A(void) {
    omObjData* obj;

    obj = omAddObj(0, 0, 0, -1, &func_800F68E0_name_2A);
    D_800FDFD8_name_2A = obj;
    obj->unk_50 = func_80023684(sizeof(s32), 0x7918);
    D_800FE024_name_2A = 0;
}

/* Called as an object function: retail passes its object on to func_800F6E74 in a0. */
void func_800F68E0_name_2A(omObjData* obj) {
    switch (D_800FE024_name_2A) {
        case 0:
            func_800F69D8_name_2A();
            D_800ED430 = 0;
            break;
        case 1:
            func_800F6AA0_name_2A();
            break;
        case 2:
            func_800F6DF8_name_2A();
            break;
        case 3:
            func_800FD254_name_2A(D_800FE040_name_2A);
            break;
        case 6:
            func_800F6E74_name_2A(obj);
            break;
        case 4:
            func_800F6B94_name_2A();
            break;
        case 5:
            func_800F6EDC_name_2A();
            break;
        case 7:
            func_800F71D4_name_2A();
            break;
        case 8:
            func_800FD85C_name_2A(&D_800FDF7C_name_2A, 2, 1);
            break;
        case 9:
            func_800FD54C_name_2A();
            break;
        case 10:
            func_800F7094_name_2A();
            break;
    }
}

void func_800F69D8_name_2A(void) {
    omObjData* obj;
    s32* timer;

    obj = omAddObj(0x10, 0, 0, -1, &func_800F6A3C_name_2A);
    timer = func_80023684(sizeof(s32), 0x7918);
    obj->unk_50 = timer;
    *timer = 1;
    D_800FE024_name_2A = -1;
}

void func_800F6A3C_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    (*timer)--;
    if (*timer == 0) {
        func_800FD428_name_2A();
    }
    if (func_800FD850_name_2A(D_800FDF78_name_2A, 2) == 0) {
        D_800FE024_name_2A = 1;
        omDelObj(obj);
    }
}

void func_800F6AA0_name_2A(void) {
    omObjData* obj;

    GMesCreate(0);
    obj = omAddObj(0x10, 0, 0, -1, &func_800F6B10_name_2A);
    obj->unk_50 = func_80023684(sizeof(s32), 0x7918);
    D_800FE024_name_2A = -1;
    *(s32*)obj->unk_50 = 20;
}

void func_800F6B10_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
        (*timer)--;
        if (*timer == 0) {
            D_800FE024_name_2A = 2;
            D_800ED430 = 1;
            omDelObj(obj);
            func_800F6DB8_name_2A();
        }
    }
}

void func_800F6B94_name_2A(void) {
    s32 i;

    if ((D_800FDFB0_name_2A == 0.0f) && (func_800FD850_name_2A(D_800FDF74_name_2A, 1) == 0)) {
        GMesCreate(0x11);
    } else {
        GMesCreate(2);
        func_800790C0();
        if (func_800FD850_name_2A(D_800FDF74_name_2A, 1) != 0) {
            for (i = 0; i < 4; i++) {
                if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
                    GwPlayer[i].coins_mg += 10;
                } else {
                    GwPlayer[i].coins_mg -= 10;
                }
            }
        }
    }
    omAddObj(0x10, 0, 0, -1, &func_800F6CCC_name_2A);
    D_800FE024_name_2A = -1;
}

void func_800F6CCC_name_2A(omObjData* obj) {
    s32* timer = D_800FDFD8_name_2A->unk_50;

    if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
        if (D_800FDF58_name_2A == 0 && D_800FDFB0_name_2A == 0.0f) {
            D_800FE024_name_2A = 10;
        } else {
            if (D_800FDFB0_name_2A == 0.0f) {
                D_800FE024_name_2A = 6;
                func_80060128(0x36);
            } else {
                D_800FE024_name_2A = 5;
            }
            *timer = 60;
        }
        omDelObj(obj);
    }
}

void func_800F6DB8_name_2A(void) {
    D_800FDF58_name_2A = 60;
    D_800FDF5A_name_2A = 30;
    GMesCreate(8, 60, 160, 32);
}

void func_800F6DF8_name_2A(void) {
    D_800FDF5A_name_2A--;
    if (D_800FDF5A_name_2A == 0) {
        D_800FDF5A_name_2A = 30;
        D_800FDF58_name_2A--;
    }
    func_80079078(D_800FDF58_name_2A);
    if (D_800FDF58_name_2A == 0) {
        D_800FE024_name_2A = 3;
        func_800790C0();
    }
}

void func_800F6E74_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    (*timer)--;
    if ((func_800FD850_name_2A(D_800FDF60_name_2A[D_800FDF98_name_2A], 0x20) != 0) || (*timer == 0)) {
        D_800FE024_name_2A = 5;
    }
}

void func_800F6EDC_name_2A(void) {
    s32 chr[2];
    s32 i;

    omAddObj(0x10, 0, 0, -1, &func_800F7030_name_2A);
    if ((D_800FDFB0_name_2A == 0.0f) && (func_800FD850_name_2A(D_800FDF74_name_2A, 1) != 0)) {
        for (i = 0; i < 4; i++) {
            if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
                if (N2A_PLAYER(D_800FE030_name_2A[i])->unk_E4->unk_48 == -78.0f) {
                    chr[0] = GwPlayer[i].character;
                } else {
                    chr[1] = GwPlayer[i].character;
                }
            }
        }
        GMesCreate(0xF, chr[0], chr[1]);
    }
    D_800FE024_name_2A = -1;
}

void func_800F7030_name_2A(omObjData* obj) {
    if (((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) && (GMesWait() == 0)) {
        func_800726AC(0, 20);
        obj->func_ptr = &func_800F7190_name_2A;
    }
}

void func_800F7094_name_2A(void) {
    omObjData* obj;
    s32* timer;
    s32 i;

    obj = omAddObj(0x10, 0, 0, -1, &func_800F7144_name_2A);
    timer = obj->unk_50 = func_80023684(sizeof(s32), 0x7918);
    for (i = 0; i < 4; i++) {
        func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x1000, 1);
    }
    func_80060128(0x34);
    D_800FE024_name_2A = -1;
    *timer = 90;
}

void func_800F7144_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    (*timer)--;
    if (*timer == 0) {
        func_800726AC(0, 20);
        obj->func_ptr = &func_800F7190_name_2A;
    }
}

void func_800F7190_name_2A(omObjData* obj) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
        func_800601D4(40);
        omDelObj(obj);
    }
}

void func_800F71D4_name_2A(void) {
    omObjData* obj;
    s32* timer;
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 4; i++) {
        n += func_800FD850_name_2A(D_800FDF60_name_2A[i], 0x80);
    }
    if (n == 0) {
        D_800FE024_name_2A = -1;
        obj = omAddObj(0x10, 0, 0, -1, &func_800F728C_name_2A);
        timer = func_80023684(sizeof(s32), 0x7918);
        obj->unk_50 = timer;
        *timer = 30;
        D_800ED430 = 0;
    }
}

void func_800F728C_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    fontcolor = 0xE;
    sprintf(pfStrBuf, "READY!");
    print8(0x88, 0x70, pfStrBuf);
    (*timer)--;
    if (*timer == 0) {
        D_800FE024_name_2A = 2;
        D_800ED430 = 1;
        omDelObj(obj);
    }
}

void func_800F731C_name_2A(void) {
    if (D_800F5144 != 0) {
        func_800601D4(40);
        omOvlReturnEx(1);
    }
}

void func_800F7350_name_2A(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = x;
    Center.y = y;
    Center.z = z;
    D_800FDFD0_name_2A = x;
    D_800FDFC8_name_2A = y;
    D_800FE04C_name_2A = z;
    D_800FE020_name_2A = rotX;
    D_800FDFAC_name_2A = 45.0f;
    omAddObj(0xE, 0, 0, -1, &func_800F7440_name_2A);
}

void func_800F7440_name_2A(omObjData* obj) {
    f32 dist;
    f32 d;
    f32 dx;
    f32 dz;
    f32 zoom;
    f32 rot;
    f32 cx;
    f32 cz;
    s32 i;

    if (func_800FD850_name_2A(D_800FDF78_name_2A, 1) != 0) {
        omDelObj(obj);
        return;
    }
    if (func_800FD850_name_2A(D_800FDF78_name_2A, 2) == 0) {
        if ((func_800FD850_name_2A(D_800FDF70_name_2A, 8) != 0) && (func_800FD850_name_2A(D_800FDF74_name_2A, 1) == 0)) {
            Center.x = D_800FE048_name_2A->trans.x + 0.0f;
            Center.y = D_800FE048_name_2A->trans.y + 350.0f + 100.0f;
            Center.z = D_800FE048_name_2A->trans.z + -560.0f;
            CZoom = 400.0f;
            return;
        }
        dist = 0.0f;
        cx = 650.0f;
        cz = -650.0f;
        for (i = 0; i < 4; i++) {
            dx = D_800FE030_name_2A[i]->trans.x;
            dz = D_800FE030_name_2A[i]->trans.z;
            d = sqrtf((dx - cx) * (dx - cx) + (dz - cz) * (dz - cz));
            if (dist < d) {
                dist = d;
            }
        }
        dx = D_800FE040_name_2A->trans.x;
        dz = D_800FE040_name_2A->trans.z;
        d = sqrtf((dx - cx) * (dx - cx) + (dz - cz) * (dz - cz));
        if (dist < d) {
            dist = d;
        }
        zoom = dist * 1.03f + 657.0f;
        if (zoom > 2105.0f) {
            zoom = 2105.0f;
        }
        if (zoom < 1480.0f) {
            zoom = 1480.0f;
        }
        rot = dist * -0.051 + 72.93000030517578;
        if (rot < 0.0f) {
            rot = 0.0f;
        }
        if (rot > 32.0f) {
            rot = 32.0f;
        }
        CZoom = zoom;
        CRot.y = rot;
        CRot.x = D_800FE020_name_2A;
        Center.x = D_800FDFD0_name_2A;
        Center.y = D_800FDFC8_name_2A;
        Center.z = D_800FE04C_name_2A;
    }
}

void func_800F7760_name_2A(s32 player) {
    Vec from;
    Vec to;
    Vec out;
    omObjData* obj;
    N2ACamWork* work;

    obj = omAddObj(0xE, 0, 0, -1, &func_800F79E8_name_2A);
    work = func_80023684(sizeof(N2ACamWork), 0x7918);
    obj->unk_50 = work;
    work->unk_00 = 0;
    Center.x = 0.0f;
    Center.y = 60.0f;
    Center.z = -300.0f;
    func_800FD85C_name_2A(&D_800FDF78_name_2A, 1, 1);
    from.x = D_800FE030_name_2A[player]->trans.x;
    from.y = D_800FE030_name_2A[player]->trans.y;
    from.z = D_800FE030_name_2A[player]->trans.z;
    to.x = func_800AEAC0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.x;
    to.y = from.y;
    to.z = func_800AEFD0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.z;
    func_800FD880_name_2A(&from, &to, &out);
    D_800FE030_name_2A[player]->rot.y = out.z;
    N2A_PLAYER(D_800FE030_name_2A[player])->unk_3C = 0.0f;
    to.x = func_800AEAC0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.x;
    to.y = -func_800AEAC0(CRot.x) * CZoom + Center.y;
    to.z = func_800AEFD0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.z;
    func_800FD880_name_2A(&from, &to, &out);
    work->unk_04 = -out.x / 15.0f;
    work->unk_08 = (360.0f - CRot.x) / 25.0f;
    work->unk_0C = -CRot.y / 25.0f;
    work->unk_10 = 0.0f;
}

void func_800F79E8_name_2A(omObjData* obj) {
    N2ACamWork* work = obj->unk_50;
    f32 minZoom;
    s32 i;

    minZoom = 400.0f;
    for (i = 0; i < 4; i++) {
        if ((func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) && (GwPlayer[i].character == 5)) {
            minZoom = 470.0f;
        }
    }
    CZoom += work->unk_04;
    CRot.y += work->unk_0C;
    CRot.z += work->unk_10;
    if (CZoom < minZoom && !(work->unk_00 & 1)) {
        if (work->unk_00 == 0) {
            work->unk_04 = -126.3f;
        }
        work->unk_00++;
        work->unk_04 = -work->unk_04;
    }
    if (minZoom + 252.6f - 1.0f < CZoom && (work->unk_00 & 1)) {
        work->unk_00++;
        work->unk_04 = -work->unk_04;
    }
    if (work->unk_00 == 5) {
        D_800FE024_name_2A = 4;
        for (i = 0; i < 4; i++) {
            if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
                func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x400, 1);
            } else {
                func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x1000, 1);
            }
        }
        omDelObj(obj);
    }
}

void func_800F7C00_name_2A(void) {
    omObjData* obj;
    N2ACamWork* work;

    obj = omAddObj(0xE, 0, 0, -1, &func_800F7C84_name_2A);
    work = func_80023684(sizeof(N2ACamWork), 0x7918);
    obj->unk_50 = work;
    work->unk_00 = 1;
    work->unk_14 = 0;
    work->unk_18 = 1.0f;
    work->unk_1C = 0.0f;
    func_800FD85C_name_2A(&D_800FDF78_name_2A, 2, 1);
}

/* Intro camera: a close-up of player 1's character, then a pull back to the court. */
void func_800F7C84_name_2A(omObjData* obj) {
    f32 x[6] = { 35.0f, 35.0f, 35.0f, 35.0f, 35.0f, 35.0f };
    f32 y[6] = { 78.0f, 85.0f, 80.0f, 79.0f, 83.0f, 80.0f };
    f32 z[6] = { -20.0f, -20.0f, -20.0f, -20.0f, -20.0f, -20.0f };
    f32 zoom[6] = { 200.0f, 220.0f, 220.0f, 200.0f, 230.0f, 230.0f };
    N2ACamWork* work = obj->unk_50;

    switch (work->unk_14) {
        case 0:
            if (--work->unk_00 == 0) {
                D_800FE02A_name_2A = GwPlayer[0].character;
                work->unk_14++;
                work->unk_00 = 22;
                Center.x = x[D_800FE02A_name_2A] + -200.0f;
                Center.y = y[D_800FE02A_name_2A];
                Center.z = z[D_800FE02A_name_2A] + 500.0f;
                CRot.x = 360.0f;
                CRot.y = 180.0f;
                CZoom = zoom[D_800FE02A_name_2A];
            }
            break;
        case 1:
            if (--work->unk_00 == 0) {
                D_800FDFC4_name_2A = PlaySound(0x30B);
                work->unk_14++;
                work->unk_00 = 8;
            }
            break;
        case 2:
            if (--work->unk_00 == 0) {
                func_80060128(0x1F);
                work->unk_14++;
                work->unk_00 = 60;
            }
            break;
        case 3:
            if (--work->unk_00 == 0) {
                work->unk_14++;
                work->unk_00 = 75;
            }
            break;
        case 4:
            CRot.y += 2.4f;
            if (CRot.y > 360.0f) {
                CRot.y = 0.0f;
            }
            CRot.x -= 0.28f;
            if (CRot.x < 339.0f) {
                CRot.x = 339.0f;
            }
            if (CZoom < 2130.0f) {
                CZoom += work->unk_18;
                work->unk_18 += work->unk_1C;
                work->unk_1C += 0.03f;
                if (CZoom > 2130.0f) {
                    CZoom = 2130.0f;
                }
            }
            Center.x += (0.0f - (x[D_800FE02A_name_2A] + -200.0f)) / 75.0f;
            if (Center.x > 0.0f) {
                Center.x = 0.0f;
            }
            Center.y += (0.0f - y[D_800FE02A_name_2A]) / 75.0f;
            if (Center.y < 0.0f) {
                Center.y = 0.0f;
            }
            Center.z += (z[D_800FE02A_name_2A] + -1060.0f) / 75.0f;
            if (Center.z < -560.0f) {
                Center.z = -560.0f;
            }
            if (--work->unk_00 == 0) {
                CZoom = 2130.0f;
                CRot.x = 339.0f;
                CRot.y = 0.0f;
                CRot.z = 0.0f;
                Center.x = 0.0f;
                Center.y = 0.0f;
                Center.z = -560.0f;
                func_800FD85C_name_2A(&D_800FDF78_name_2A, 2, 0);
                omDelObj(obj);
            }
            break;
    }
}

void func_800F81B8_name_2A(omObjData* obj) {
    unkGlobalStruct_02* work;
    void* data;

    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    obj->unk_50 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    D_800FDFD4_name_2A = obj;
    work = obj->unk_50;
    obj->model[0] = func_800174C0(0x3E0000, 0x699);
    obj->model[1] = func_800174C0(0x3E0008, 0x689);
    data = func_80014614(0x27);
    func_80038A9C(D_800F2B7C[obj->model[1]].unk_6C, data, 0, "00mt001s_IA44");
    func_80025AD4(obj->model[1]);
    func_80025B34(obj->model[1]);
    DataCloseTemp(data);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = obj;
    func_8009B770(obj->unk_50, 0, sizeof(unkGlobalStruct_02));
    work->unk_04 = 1;
    work->unk_05 = 0;
    func_800F878C_name_2A(obj);
    func_80009090(obj);
    obj->func_ptr = &func_800FDD44_name_2A;
}

void func_800F836C_name_2A(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x3E0002, 0x299);
    obj->model[1] = LoadFormFile(0x3E0003, 0x29D);
    obj->model[2] = LoadFormFile(0x3E0007, 0x29D);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    func_80025798(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_80025798(obj->model[2], 0.0f, 0.0f, 0.0f);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    obj->func_ptr = &func_800F8438_name_2A;
}

void func_800F8438_name_2A(omObjData* obj) {
    if (func_800FD850_name_2A(D_800FDF74_name_2A, 1) != 0) {
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 0);
        func_800258EC(obj->model[2], 4, 0);
        omDelObj(obj);
    }
}

void func_800F84B0_name_2A(omObjData* obj) {
    obj->unk_50 = func_80023684(sizeof(N2ABallWork), 0x7918);
    obj->model[0] = LoadFormFile(0x3E0004, 0x699);
    obj->func_ptr = NULL;
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    obj->func_ptr = &func_800FDD44_name_2A;
}

void func_800F8530_name_2A(omObjData* obj) {
    D_800FE048_name_2A = obj;
    obj->unk_50 = func_80023684(sizeof(N2ABallWork), 0x7918);
    obj->model[0] = LoadFormFile(0x3E0005, 0x699);
    obj->func_ptr = NULL;
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    D_800FDF74_name_2A = 0;
    obj->func_ptr = &func_800F85C0_name_2A;
}

/* The hoop: a ball coming down through the ring scores. */
void func_800F85C0_name_2A(omObjData* obj) {
    N2ABallExt* ball;
    f32 dx;
    f32 dy;
    f32 dz;

    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) == 0) {
        ball = N2A_BALL(D_800FE040_name_2A)->unk_68;
        if (ball->unk_48 == -1) {
            dx = obj->trans.x + 0.0f - D_800FE040_name_2A->trans.x;
            dy = obj->trans.y + 350.0f - D_800FE040_name_2A->trans.y;
            dz = obj->trans.z + -560.0f - D_800FE040_name_2A->trans.z;
            if (func_800B1750(dx * dx + dy * dy + dz * dz) < 115.0 && func_800FD850_name_2A(D_800FDF74_name_2A, 1) == 0) {
                if (dy <= -10.0f) {
                    func_800258EC(obj->model[0], 4, 4);
                    func_800FD85C_name_2A(&D_800FDF74_name_2A, 1, 1);
                    func_800258EC(D_800FDF82_name_2A, 4, 0);
                    func_800FD1B4_name_2A(D_800FE040_name_2A);
                    if (func_800FD850_name_2A(D_800FDF70_name_2A, 8) != 0) {
                        func_80060F04((s16)D_800FDF98_name_2A, 10, 0, 10);
                    }
                    func_800FB8BC_name_2A();
                } else if (ball->unk_40 >= 0.0f) {
                    ball->unk_40 = -ball->unk_40;
                }
            }
        }
    }
}

void func_800F878C_name_2A(omObjData* obj) {
    omObjData* shadow;

    shadow = omAddObj(0xF, 2, 0, -1, &func_800F8830_name_2A);
    shadow->model[0] = LoadFormFile(0x210001, 0x699);
    shadow->model[1] = func_80023FC8(shadow->model[0]);
    D_800FE02C_name_2A = shadow;
    func_80025798(shadow->model[0], 0.0f, 4.0f, 0.0f);
    func_80025798(shadow->model[1], 0.0f, 4.0f, 0.0f);
}

void func_800F8830_name_2A(omObjData* obj) {
    s32 team[2];
    s32 n;
    s32 i;

    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) != 0) {
        func_8002456C(obj->model[0]);
        omDelObj(obj);
        return;
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            team[n] = i;
            n++;
        }
    }
    omSetTra(obj, D_800FE030_name_2A[team[0]]->trans.x, 4.0f, D_800FE030_name_2A[team[0]]->trans.z);
    func_80025798(obj->model[1], D_800FE030_name_2A[team[1]]->trans.x, 4.0f, D_800FE030_name_2A[team[1]]->trans.z);
}

void func_800F8940_name_2A(omObjData* obj, s32 player) {
    f32 posX[4] = { -200.0f, 200.0f, -200.0f, 200.0f };
    f32 posZ[4] = { 500.0f, 500.0f, 200.0f, 200.0f };
    f32 rotY[4] = { 180.0f, 180.0f, 0.0f, 0.0f };
    N2APlayerWork* work;
    N2APlayerExt* ext;
    s32 dir;
    s32 file;
    s32 slot;
    s32 i;

    D_800FE02A_name_2A = GwPlayer[player].character;
    D_800FDF60_name_2A[player] = 0;
    if (GwPlayer[player].group == 0) {
        func_800FD85C_name_2A(&D_800FDF60_name_2A[player], 1, 1);
    }
    dir = D_800C59AC[D_800FE02A_name_2A].unk_00;
    file = D_800C59AC[D_800FE02A_name_2A].unk_08;
    func_8000979C(obj, dir, file, player, 0x699, 0x699);
    slot = 0;
    if (func_800FD850_name_2A(D_800FDF60_name_2A[player], 1) != 0) {
        slot = D_800FDF90_name_2A;
    } else {
        slot += 2 + D_800FDF94_name_2A;
    }
    omSetTra(obj, posX[slot], 0.0f, posZ[slot]);
    if (func_800FD850_name_2A(D_800FDF60_name_2A[player], 1) != 0) {
        D_800FDF90_name_2A++;
    } else {
        D_800FDF94_name_2A++;
    }
    work = obj->unk_50;
    ext = work->unk_E4 = func_80023684(sizeof(N2APlayerExt), 0x7918);
    ext->unk_50 = work->unk_56;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    func_800187D0(obj, 0, dir, 1, 0);
    func_800187D0(obj, 1, dir | 1, 1, 0);
    func_800187D0(obj, 2, dir | 3, 1, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    if (rand8() & 1) {
        func_800187D0(obj, 0xD, dir | 0xF, 1, 0x78);
    } else {
        func_800187D0(obj, 0xD, dir | 0x38, 1, 0x78);
    }
    if (rand8() & 1) {
        func_800187D0(obj, 0xE, dir | 0x10, 1, 0x78);
    } else {
        func_800187D0(obj, 0xE, dir | 0x3C, 1, 0x78);
    }
    func_800187D0(obj, 5, dir | 4, 0, 0);
    func_800187D0(obj, 0x15, dir | 0x62, 0, 0);
    func_800187D0(obj, 0x14, dir | 0x5F, 2, 0);
    func_800187D0(obj, 0x1E, dir | 0x63, 0, 0);
    func_800187D0(obj, 0x1F, dir | 0x64, 0, 0);
    func_800187D0(obj, 0x23, dir | 0x4F, 1, 0);
    func_800187D0(obj, 0x24, dir | 0x72, 1, 0);
    func_800187D0(obj, 0x25, dir | 0x73, 1, 0);
    func_800187D0(obj, 0x26, dir | 0x24, 2, 0);
    func_800187D0(obj, 0x28, dir | 0x50, 2, 0);
    func_800187D0(obj, 0x29, dir | 0x51, 2, 0);
    work->unk_48 = 60.0f;
    work->unk_38 = 1000.0f;
    work->unk_50 = 0;
    work->unk_60 = 0.0f;
    work->unk_B1 = -1;
    work->unk_3C = rotY[slot];
    func_80008FE8(obj, 20.0f);
    ext->player = player;
    ext->unk_44 = 1000.0f;
    ext->unk_3C = 0;
    ext->unk_0C = 0.0f;
    ext->unk_10 = 0.0f;
    ext->unk_14 = 0.0f;
    ext->unk_D4 = 0;
    ext->unk_DC = 0;
    ext->unk_E0 = 0.0f;
    ext->unk_34 = 0.0f;
    ext->unk_D0 = ext->unk_34;
    if (func_800FD850_name_2A(D_800FDF60_name_2A[player], 1) != 0) {
        ext->unk_E4 = D_800FDF9C_name_2A;
        D_800FDF9C_name_2A++;
    } else {
        ext->unk_E4 = D_800FDFA0_name_2A;
        D_800FDFA0_name_2A++;
    }
    if (!(GwPlayer[player].flags & 1)) {
        ext->unk_D8 = 1;
    } else {
        switch (GwPlayer[player].cpu_difficulty) {
            case 0:
                ext->unk_D8 = 0;
                break;
            case 1:
                ext->unk_D8 = 1;
                break;
            case 2:
                ext->unk_D8 = 2;
                break;
            case 3:
                ext->unk_D8 = 3;
                break;
        }
    }
    func_800FB2DC_name_2A(ext, 0);
    func_800FB334_name_2A(ext);
    D_800FE030_name_2A[player] = obj;
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    D_800F3FB0[D_800F2BC0++] = obj;
    func_800184BC(obj, 0);
    ContStkX[work->unk_56] = ContStkY[work->unk_56] = 0;
    ContBtn[work->unk_56] &= 0x7FFF;
    ContBtnTrg[work->unk_56] &= 0x7FFF;
    switch (GwPlayer[player].cpu_difficulty) {
        case 0:
            ext->unk_D8 = 0;
            break;
        case 1:
            ext->unk_D8 = 1;
            break;
        case 2:
            ext->unk_D8 = 2;
            break;
        case 3:
            ext->unk_D8 = 3;
            break;
    }
    D_800ED430 = 0;
    obj->func_ptr = &func_800F9050_name_2A;
    for (i = 0; i < 30; i++) {
        ext->unk_58[i] = 0.0f;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800F9050_name_2A);

void func_800F9E20_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 0);
}

void func_800F9E3C_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 1);
}

void func_800F9E58_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 2);
}

void func_800F9E74_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 3);
}

/* The other member of `player`'s team. */
s32 func_800F9E90_name_2A(s32 player) {
    s32 i;

    D_800FDF40_name_2A = -1;
    for (i = 0; i < 4; i++) {
        if (i != player && func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            D_800FDF40_name_2A = i;
            break;
        }
    }
    return D_800FDF40_name_2A;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800F9F1C_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FA088_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FA124_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FA1CC_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FA614_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FA8EC_name_2A);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2A/1E9440", D_800FDE68_name_2A);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2A/1E9440", D_800FDE78_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FAEEC_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB280_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB2DC_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB334_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB3FC_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB6A8_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB6F0_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB718_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB79C_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB878_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB8BC_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FBB50_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FBFC8_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FC098_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FC364_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FC70C_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FC7A4_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FC8C8_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FC990_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FC9EC_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FCB5C_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD1B4_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD20C_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD254_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD428_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD54C_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD670_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD7D8_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD850_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD85C_name_2A);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2A/1E9440", D_800FDEA0_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD880_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FDBF4_name_2A);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FDD44_name_2A);
