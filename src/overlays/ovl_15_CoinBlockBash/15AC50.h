#ifndef COINBLOCKBASH_15AC50_H
#define COINBLOCKBASH_15AC50_H

/* ovl_15 CoinBlockBash, unit 15AC50.c: the nine coin blocks (models "bl00".."bl08" with shadows
   "kg00".."kg08"), the coins they drop, and the billboard library (ovl_2E HotRopeJump's HRJFx
   code with a model-segment variant). */

#include "CoinBlockBash.h"

/* A coin popped out of a block (D_80103290_CoinBlockBash[9]): the full layout. CoinBlockBash.h's
   CBBDrop pads 0x00-0x08 as bytes, but 0x00 and 0x04 are pointers: on the host every later field
   moves, so this unit reads drops through this type (same N64 offsets and field names). */
typedef struct CBBDropFull {
    /* 0x00 */ struct CBBCoinFull* coin; /* the block it came from */
    /* 0x04 */ omObjData* obj;           /* the player collecting it */
    /* 0x08 */ u8 state;  /* 0 none, 1 rising, 2 on the floor, 3 blinking, 4 collected, 5 gone */
    /* 0x09 */ u8 type;   /* 0 coin, 1 big coin, 2 .. (D_80103248 sprite) */
    /* 0x0A */ s8 active; /* can be collected */
    /* 0x0B */ char unk_0B;
    /* 0x0C */ s16 bb;     /* billboard */
    /* 0x0E */ s16 shadow; /* shadow billboard */
    /* 0x10 */ s32 timer;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 radius;
    /* 0x1C */ Vec pos;
    /* 0x28 */ f32 unk_28; /* scale x */
    /* 0x2C */ f32 unk_2C; /* scale y */
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ Vec vel;
    /* 0x40 */ f32 unk_40; /* angle while collected */
} CBBDropFull; /* size = 0x44 (N64) */

/* A coin block (D_80103294_CoinBlockBash[9]): the full layout (see CBBDropFull: CoinBlockBash.h's
   CBBCoin pads its three pointers at 0x00-0x0C as bytes). */
typedef struct CBBCoinFull {
    /* 0x00 */ unk2C0C0Struct50* blk;    /* model part "blNN" */
    /* 0x04 */ unk2C0C0Struct50* shadow; /* model part "kgNN" */
    /* 0x08 */ CBBDropFull* drop;
    /* 0x0C */ u8 state;  /* 0 idle, 1 hit, 2 settling, 3 broken (flying), 4 gone */
    /* 0x0D */ s8 hittable;
    /* 0x0E */ s16 bb;    /* effect billboard, -1 none */
    /* 0x10 */ s16 unk_10; /* hits left */
    /* 0x12 */ char unk_12[2];
    /* 0x14 */ s32 timer;
    /* 0x18 */ f32 angle; /* flight direction, -361 none */
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ Vec pos;
} CBBCoinFull; /* size = 0x2C (N64) */

#define CBB_DROPS ((CBBDropFull*)D_80103290_CoinBlockBash)
#define CBB_COINS ((CBBCoinFull*)D_80103294_CoinBlockBash)

/* A billboard D_80103298_CoinBlockBash[D_80103258_CoinBlockBash]: ovl_2E HotRopeJump's HRJFx, but
   0x04 is the model (func_80100160) whose per-frame segment list the draw loads. The pointer fields
   shift every later field on the host: use names, never offsets. */
typedef struct CBBBill {
    /* 0x00 */ Gfx* dl;      /* (Gfx*)-1 = free, NULL = nothing this frame */
    /* 0x04 */ unk2C0C0StructC0* model;
    /* 0x08 */ s8 unk_08;    /* 1: a model, not a sprite */
    /* 0x09 */ char unk_09;
    /* 0x0A */ u16 sprite;   /* D_800EC700 index */
    /* 0x0C */ s16 frame;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u8 flags;     /* 1 no animation, 2 hold, 4 hide at end, 0x10 hidden, 0x18 filter,
                                0x20 free at end */
    /* 0x11 */ u8 a;
    /* 0x12 */ u8 r;
    /* 0x13 */ u8 g;
    /* 0x14 */ u8 b;
    /* 0x15 */ char unk_15[3];
    /* 0x18 */ f32 timer;
    /* 0x1C */ f32 speed;
    /* 0x20 */ Vec pos;
    /* 0x2C */ Vec scale;
} CBBBill; /* size = 0x38 (N64) */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern unk65770Anim* D_800EC700[];
extern unk_Struct00* D_800C3110;
extern s16 D_800F3FA8;
extern u8 D_800F37F0;
extern s8 D_800F329C;

s32 func_80024198(u32, Gfx*, s32);
s32 func_8009B850(const void*, const void*);
unk2C0C0Struct50* func_80026A0C(s16, char*);
s16 func_8001CD00(u8*);
s16 func_800678A4(void*);
u16 func_800174C0(s32, s32);
s16 func_80060540(s16, s16);
f32 func_800B0CD8(f32, f32);

/* ---------------------------------------------------------------------------------------------
   Overlay data and bss
   --------------------------------------------------------------------------------------------- */

extern s32 D_80101C00_CoinBlockBash; /* frame buffer index, 0..2 */
extern s32 D_80101C04_CoinBlockBash; /* time up: 1.. */
extern char D_80101C08_CoinBlockBash[9][8];
extern char D_80101C50_CoinBlockBash[9][8];
extern s16 D_80101C98_CoinBlockBash[4][2]; /* [type][1]: collect sound per drop type */
extern s16 D_80101CA8_CoinBlockBash[4];    /* texture filter */

extern s32 D_80103220_CoinBlockBash;    /* block model */
extern s32 D_80103228_CoinBlockBash[5]; /* block textures by hits left */
extern s32 D_8010323C_CoinBlockBash;    /* blocks standing */
extern s32 D_80103240_CoinBlockBash;    /* drops left */
extern s32 D_80103244_CoinBlockBash;    /* drop shadow model */
extern s32 D_80103248_CoinBlockBash[4]; /* sprites: drop types 0..2, 3 sparkle */
extern s32 D_80103258_CoinBlockBash;    /* billboard slots */
extern Gfx* D_8010325C_CoinBlockBash[3];
extern Mtx* D_80103268_CoinBlockBash[3];
extern s32 D_80103274_CoinBlockBash; /* billboard model */
extern Gfx* D_80103278_CoinBlockBash[3];
extern Vtx* D_80103284_CoinBlockBash[3];
extern CBBBill* D_80103298_CoinBlockBash;

/* Retail reads the low halves of these words as their own symbols. */
#ifdef TARGET_PC
#define D_80103222_CoinBlockBash ((s16)D_80103220_CoinBlockBash)
#define D_8010323E_CoinBlockBash ((s16)D_8010323C_CoinBlockBash)
#define D_80103242_CoinBlockBash ((s16)D_80103240_CoinBlockBash)
#define D_80103246_CoinBlockBash ((s16)D_80103244_CoinBlockBash)
#define CBB_SPRITE(i) ((s16)D_80103248_CoinBlockBash[i])
#define D_80103252_CoinBlockBash ((s16)D_80103248_CoinBlockBash[2])
#define D_80103256_CoinBlockBash ((s16)D_80103248_CoinBlockBash[3])
#else
extern s16 D_80103222_CoinBlockBash;
extern s16 D_8010323E_CoinBlockBash;
extern s16 D_80103242_CoinBlockBash;
extern s16 D_80103246_CoinBlockBash;
extern s16 D_8010324A_CoinBlockBash;
extern s16 D_80103252_CoinBlockBash;
extern s16 D_80103256_CoinBlockBash;
#define CBB_SPRITE(i) ((&D_8010324A_CoinBlockBash)[(i) * 2])
#endif

/* ---------------------------------------------------------------------------------------------
   Unit functions
   --------------------------------------------------------------------------------------------- */

void func_800FE684_CoinBlockBash(void);
s16 func_800FE854_CoinBlockBash(unk2C0C0StructC0* model, char* name);
unk2C0C0Struct50* func_800FE8DC_CoinBlockBash(s16 model, char* name);
void func_800FEA5C_CoinBlockBash(void);
void func_800FEE90_CoinBlockBash(void);
void func_800FF2B0_CoinBlockBash(void);
s32 func_800FFBB8_CoinBlockBash(s32 time);
void func_800FFE64_CoinBlockBash(unk2C0C0Struct50* node, f32 x, f32 y, f32 z);
void func_800FFE74_CoinBlockBash(unk2C0C0Struct50* node, f32 x, f32 y, f32 z);
void func_800FFE84_CoinBlockBash(unk2C0C0Struct50* node, s32 tex);
void func_800FFE90_CoinBlockBash(unk2C0C0Struct50* node);
void func_800FFED0_CoinBlockBash(u8 count);
s16 func_801000B8_CoinBlockBash(s16 sprite, u8 flags);
s16 func_80100160_CoinBlockBash(s16 model, u8 flags);
void func_80100264_CoinBlockBash(s16 id, s16 sprite);
void func_801002CC_CoinBlockBash(s16 id, f32 speed);
void func_80100304_CoinBlockBash(s16 id, f32 x, f32 y, f32 z);
void func_8010034C_CoinBlockBash(s16 id, f32 x, f32 y, f32 z);
void func_80100394_CoinBlockBash(s16 id, u8 flags);
void func_801003D0_CoinBlockBash(s16 id, u8 flags);
void func_80100410_CoinBlockBash(s16 id, u8 r, u8 g, u8 b, s32 a);
void func_80100454_CoinBlockBash(s16 id);
void func_801004E8_CoinBlockBash(void);
void func_80101748_CoinBlockBash(void);
void func_80101A5C_CoinBlockBash(void);

#endif
