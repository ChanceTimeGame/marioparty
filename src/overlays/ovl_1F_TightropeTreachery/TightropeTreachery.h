#ifndef TIGHTROPETREACHERY_H
#define TIGHTROPETREACHERY_H

/* ovl_1F TightropeTreachery (1 vs 3): declarations shared by its units (197E20, 19A360, 19ACC0,
   19D510). D_800FE8A0_TightropeTreachery[0] is the player of group 0 (the one on the rope),
   [1..3] the other three, in player order. */

#include "common.h"

/* A player object's work (func_80023684(0xE8)): src/99E0.c's MgWork layout; its pointers sit
   where MgWork's do (0xB8, 0xD8, 0xDC, 0xE4) so main code reads the same fields on the host. */
typedef struct TTPlayerWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[3];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 angle; /* facing angle (degrees) */
    /* 0x40 */ f32 speed;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 radius;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 port;   /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 player; /* player index */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C[6];
    /* 0x84 */ char unk_84[0xC];
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ char unk_9C[4];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[6];
    /* 0xAE */ u16 unk_AE; /* stun timer after a hit */
    /* 0xB0 */ char unk_B0;
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ void* unk_DC;     /* collision callback */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} TTPlayerWork; /* size = 0xE8 on the N64 */

#define TT_WORK(obj) ((TTPlayerWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800F2AF8[];
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern u16 ContBtn[];
extern s8 ContStkY[];
extern u16 D_800F338C[];
extern f32 D_800B895C;
extern f32 D_800B8960;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B896C;
extern f32 D_800B8970;
extern f32 D_800B897C;
extern f32 D_800B8980;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800B898C;
extern u16 D_800B89A4[][14];

void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_8000940C(omObjData*, f32, f32, f32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_8001E268(s16, u8, u8);
void func_8001E2A8(s16, u16);
void func_800185A4(omObjData*, s32);
void GMesSprClose(void);
extern int guRandom(void);
void func_80060F04(s16, s16, s16, s16);
void func_800AF2E0(f32, f32*, f32*);
/* func_80009028 with its s32 argument given as a float: retail passed an f32 there (O32 puts it in
   a1); the host passes the same bits as the s32 the definition takes. */
#ifdef TARGET_PC
#define FUNC_80009028_F(obj, y, x0, z0, x1, z1)                                                  \
    do {                                                                                          \
        union { f32 f; s32 i; } u_;                                                               \
        u_.f = (y);                                                                               \
        func_80009028((obj), u_.i, (x0), (z0), (x1), (z1));                                       \
    } while (0)
#else
#define FUNC_80009028_F(obj, y, x0, z0, x1, z1)                                                  \
    ((void (*)(omObjData*, f32, f32, f32, f32, f32))(void*)func_80009028)((obj), (y), (x0), (z0), (x1), (z1))
#endif

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

/* 197E20.c */
void func_800F65E0_TightropeTreachery(void);
void func_800F6BC8_TightropeTreachery(omObjData*);
s32 func_800F6C44_TightropeTreachery(omObjData*, omObjData*);
void func_800F6E80_TightropeTreachery(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_800F7450_TightropeTreachery(omObjData*);
void func_800F7818_TightropeTreachery(omObjData*);
void func_800F83E0_TightropeTreachery(void);

/* 19A360.c */
void func_800F8B20_TightropeTreachery(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_800F8BA0_TightropeTreachery(void);
void func_800F8CA8_TightropeTreachery(void);
void func_800F8D20_TightropeTreachery(omObjData*);
f32 func_800F8DA4_TightropeTreachery(void);
void func_800F8F70_TightropeTreachery(Vec3f* pos, Vec3f* axis, f32 angle, Mat4 m);
void func_800F9168_TightropeTreachery(TTPlayerWork*);
void func_800F9204_TightropeTreachery(omObjData*, f32);
void func_800F927C_TightropeTreachery(omObjData*, f32*, f32*);
s32 func_800F937C_TightropeTreachery(u32);
void func_800F9450_TightropeTreachery(void);

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

/* 19A360.c */
extern s8 D_800FE300_TightropeTreachery;
extern s8 D_800FE301_TightropeTreachery;
extern s16 D_800FE302_TightropeTreachery;
extern f32 D_800FE304_TightropeTreachery;
extern s8 D_800FE328_TightropeTreachery;
extern s8 D_800FE32C_TightropeTreachery[8];
extern s8 D_800FE334_TightropeTreachery[8];
extern s8 D_800FE33C_TightropeTreachery;
extern u16 D_800FE33E_TightropeTreachery;
extern s32 D_800FE340_TightropeTreachery;

/* ---------------------------------------------------------------------------------------------
   .bss (0x800FE6A0..0x800FE8D0)
   --------------------------------------------------------------------------------------------- */

extern f32 D_800FE7C0_TightropeTreachery;
extern f32 D_800FE7C4_TightropeTreachery;
extern f32 D_800FE8A4_TightropeTreachery;
extern f32 D_800FE8A8_TightropeTreachery;
extern f32 D_800FE8B0_TightropeTreachery;
extern f32 D_800FE8B4_TightropeTreachery;
extern f32 D_800FE8C4_TightropeTreachery;

#endif
