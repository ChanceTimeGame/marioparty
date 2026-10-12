#include "common.h"

typedef struct unk_ovl_2BStruct {
/* 0x000 */ char unk_00[4];
/* 0x004 */ s16 unk_04;
/* 0x006 */ char unk_06[0x146];
/* 0x14C */ s16 unk_14C;
} unk_ovl_2BStruct; //unknown size

typedef struct unk_ovl_2BStruct2 {
/* 0x00 */ char unk_00[0x4C];
/* 0x4C */ s32 unk_4C;
/* 0x50 */ char unk_50[0x70];
} unk_ovl_2BStruct2; //unknown size

typedef struct CastAwaysLightParams {
    u16 unk_00;
    u16 unk_02;
} CastAwaysLightParams;

/* One fish/item spawner (the work of the three func_800F73AC_CastAways objects). */
typedef struct CastAwaysItemSet {
    /* 0x00 */ s16 id;
    /* 0x02 */ u16 interval;
    /* 0x04 */ u16 count;
    /* 0x06 */ s16 models[3][8];
    /* 0x36 */ s16 spriteIds[8];
    /* 0x46 */ char unk_46[0x20];
    /* 0x66 */ u8 slots[3][8];
    /* 0x7E */ char unk_7E[2];
    /* 0x80 */ f32 speed;
    /* 0x84 */ u16 spawned;
    /* 0x86 */ u16 timer;
    /* 0x88 */ f32 x;
    /* 0x8C */ f32 z;
    /* 0x90 */ f32 y;
    /* 0x94 */ f32 angle;
} CastAwaysItemSet; /* sizeof 0x98 */

/* D_800FB960_CastAways[3]: one spawner definition per spawner id. */
typedef struct CastAwaysItemSetDef {
    /* 0x00 */ u16 interval;
    /* 0x02 */ u16 count;
    /* 0x04 */ f32 speed;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 z;
    /* 0x10 */ s8 stickY; /* CPU stick value that casts to this spawner (+5) */
    /* 0x11 */ char unk_11[3];
} CastAwaysItemSetDef; /* sizeof 0x14 */

extern CastAwaysItemSetDef D_800FB960_CastAways[];

typedef struct CastAwaysAnimData {
    s16 frameCount;
    s16 unk_02;
    void* unk_04;
    void* unk_08;
} CastAwaysAnimData;

/* Work of the lure animation object (func_800FB668_CastAways). */
typedef struct CastAwaysLureWork {
    omObjData* playerObj;
    s16 model;
    char unk_06[2];
    f32 frame;
    f32 step;
    u16 flags;
    char unk_12[2];
    CastAwaysAnimData* animData;
} CastAwaysLureWork; /* sizeof 0x18 */

typedef struct CastAwaysSpriteData {
    s16 model;
    s8 unk_02;
    s8 unk_03;
    s8 unk_04;
    char unk_05[3];
    void* buffersA[8];
    void* buffersB[8];
} CastAwaysSpriteData;

#define CASTAWAYS_LINE_SAMPLES 21

/* Work of the four player objects (func_800F8194_CastAways). */
typedef struct CastAwaysPlayerWork {
    /* 0x000 */ s16 seat;
    /* 0x002 */ u16 playerNo;
    /* 0x004 */ s16 power;
    /* 0x006 */ u16 state;
    /* 0x008 */ omObjData* rodObj;
    /* 0x00C */ u16 lastPower;
    /* 0x00E */ u16 repeat;
    /* 0x010 */ s16 motionIdx;
    /* 0x012 */ u8 castState;
    /* 0x013 */ char unk_13;
    /* 0x014 */ u16 sampleCount;
    /* 0x016 */ char unk_16[0x10];
    /* 0x026 */ u16 savedSpeed[4];
    /* 0x02E */ char unk_2E[6];
    /* 0x034 */ CastAwaysSpriteData* spriteData;
    /* 0x038 */ Vec samples[CASTAWAYS_LINE_SAMPLES];
    /* 0x134 */ void* animDataA;
    /* 0x138 */ void* animDataB;
    /* 0x13C */ omObjData* lureObj;
    /* 0x140 */ s16 unk_140;
    /* 0x142 */ u16 catches;
    /* 0x144 */ s16 sound;
    /* 0x146 */ u16 flags;
    /* 0x148 */ u16 unk_148;
    /* 0x14A */ s16 fishType;
    /* 0x14C */ s16 unk_14C;
    /* 0x14E */ u16 unk_14E;
    /* 0x150 */ f32 unk_150;
    /* 0x154 */ f32 unk_154;
    /* 0x158 */ u16 targetSet;
    /* 0x15A */ char unk_15A[2];
} CastAwaysPlayerWork; /* sizeof 0x15C */

/* Work of the rod/hook objects (func_800F92FC_CastAways). */
typedef struct CastAwaysRodWork {
    /* 0x00 */ omObjData* playerObj;
    /* 0x04 */ omObjData* fishObj;
    /* 0x08 */ s16 playerNo;
    /* 0x0A */ s16 state;
    /* 0x0C */ u16 group;
    /* 0x0E */ u16 steps;
    /* 0x10 */ u16 counter;
    /* 0x12 */ u16 timer;
    /* 0x14 */ f32 targetZ;
    /* 0x18 */ f32 velY;
    /* 0x1C */ f32 stepZ;
    /* 0x20 */ f32 stepY;
    /* 0x24 */ f32 startZ;
    /* 0x28 */ f32 startY;
    /* 0x2C */ f32 gravity;
    /* 0x30 */ f32 slope;
    /* 0x34 */ f32 baseZ;
} CastAwaysRodWork; /* sizeof 0x38 */

/* Work of the fish/item objects (func_800F7A38_CastAways). */
typedef struct CastAwaysFishWork {
    /* 0x00 */ struct CastAwaysItemSet* set;
    /* 0x04 */ u16 state;
    /* 0x08 */ f32 speed;
    /* 0x0C */ f32 angle;
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ f32 dist;
    /* 0x18 */ Vec start;
    /* 0x24 */ Vec step;
    /* 0x30 */ u16 steps;
    /* 0x32 */ u16 timer;
    /* 0x34 */ s16 type;
    /* 0x36 */ s16 slot;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ omObjData* rodObj;
} CastAwaysFishWork; /* sizeof 0x40 */

/* objmain.c's omGrpData (D_800ED618: one per object group). */
typedef struct CastAwaysGrpData {
    /* 0x00 */ u16 next;
    /* 0x02 */ u16 max;
    /* 0x04 */ u16 num;
    /* 0x08 */ u16* nextIdx;
    /* 0x0C */ omObjData** obj;
} CastAwaysGrpData; /* sizeof 0x10 */

extern CastAwaysGrpData D_800ED618[];

/* D_800FBB10/20/30_CastAways[4]: one sprite per player. */
typedef struct CastAwaysPlayerSprite {
    u16 model;
    s16 id;
} CastAwaysPlayerSprite;

extern CastAwaysPlayerSprite D_800FBB10_CastAways[4];
extern CastAwaysPlayerSprite D_800FBB20_CastAways[4];
extern CastAwaysPlayerSprite D_800FBB30_CastAways[4];

//extern unk_ovl_2BStruct2* D_800F2B7C;
extern f32 D_800FBA30_CastAways[];
extern s32 D_800FB9A4_ovl2B[];
extern s16 D_800FBB04_ovl2B[];
extern s16 D_800FBB40_ovl2B;
extern s16 D_800FBB42_ovl2B;
extern s16 D_800FBB44_ovl2B;
extern s16 D_800FBB46_ovl2B;
extern omObjData* D_800FBB48_ovl2B[];
extern s16 D_800FBB50_ovl2B[];
extern Vec3f D_800FBB70_ovl2B;
extern u16 D_800FBB7C_ovl2B;
extern Vec3f D_800FBB80_ovl2B;
extern u16 D_800FBB98_ovl2B;
extern Vec3f D_800FBB9C_ovl2B[];
extern s16 D_800F3778_ovl2B;
extern u16 D_800FBB58_ovl2B;
extern u16 D_800FBB5A_ovl2B;
extern u16 D_800FBB5C_ovl2B;
extern u16 D_800FBB5E_ovl2B;
extern s32 D_800FBB60_ovl2B;
extern f32 D_800FBB64_ovl2B;
extern f32 D_800FBB68_ovl2B;
extern u16 D_800FBB78_ovl2B[];
extern s16 D_800FBB6C_ovl2B;
extern s16 D_800FBB8C_ovl2B;
extern s32 D_800FBA64_ovl2B;
extern CastAwaysLightParams D_800FBB60_CastAways;
extern u16 D_800FB9E0_CastAways[];

void func_800FB5B4_CastAways(s32);
void func_800F8194_CastAways(omObjData*, s32);
void func_800F7308_CastAways(omObjData*);
void func_800F73AC_CastAways(omObjData*, s32);
void func_800F76B8_CastAways(omObjData*);
void func_800FA198_CastAways(void);
void func_800FA410_CastAways(void);
void func_800F70C4_CastAways(void);
void func_800F7014_CastAways(void);
void func_800F704C_CastAways(omObjData*);
void func_800F71AC_CastAways(omObjData*);
void func_800F761C_CastAways(omObjData*);
void func_800F7650_CastAways(omObjData*);
void func_800F7684_CastAways(omObjData*);
void func_800F8AAC_CastAways(omObjData*);
void func_800F8AC8_CastAways(omObjData*);
void func_800F8AE4_CastAways(omObjData*);
void func_800F8B00_CastAways(omObjData*);
void func_800FACA8_CastAways(void);
void func_800FB884_CastAways(void);

void func_8001E268(s16, u8, u8);
void func_8001E2A8(s16, u16);
void func_80060440(s16, s16);
void func_80025BB8(s16, s16);
void func_8002859C(s16, s16, char*);
s16 func_80028784(u8*, s16);
void func_800370D4(s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
CastAwaysAnimData* func_800202E8(s16, s16);
s16 func_80009E4C(s16, s16, s8, s8);
#ifdef TARGET_PC
void func_80060F04(s16, s16, s16, s16); /* host: matches the definition */
#else
void func_80060F04(s16, s32, s32, s32);
#endif
s16 func_800FABE4_CastAways(u16);
s32 func_800F75BC_CastAways(CastAwaysItemSet*, s32);
void func_800F7A38_CastAways(omObjData*);
void func_800F92FC_CastAways(omObjData*);
void func_800F8B1C_CastAways(omObjData*);
void func_800FAD2C_CastAways(omObjData*);
s32 func_800FACEC_CastAways(CastAwaysPlayerWork*);
void func_800F6A24_CastAways(omObjData*, s8*, s8*, s8*);
s16 func_800FB404_CastAways(s8, s8);
void func_800FB668_CastAways(omObjData*, s16, CastAwaysAnimData*, f32, f32, u16, s32);
CastAwaysSpriteData* func_800FAFF0_CastAways(s8, s8, s8);
s32 func_800FB4D4_CastAways(f32, f32, f32, u16, f32, f32, f32);
s32 func_800FB53C_CastAways(f32, f32, f32, u16, f32, f32, f32);
void func_800F9E2C_CastAways(omObjData*, CastAwaysPlayerWork*, CastAwaysRodWork*);
void func_800F9EAC_CastAways(CastAwaysPlayerWork*, f32);
void func_800FB0C8_CastAways(CastAwaysSpriteData*, Vec*, u16);

extern s16 D_800FBB00_CastAways;
extern s16 D_800FBB04_CastAways;
extern s16 D_800FBB06_CastAways;
extern s16 D_800FBB54_CastAways;
f64 func_8009B618(f64, f64); /* fmod */
