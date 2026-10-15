#ifndef PIRANHASPURSUIT_H
#define PIRANHASPURSUIT_H

/* ovl_31 PiranhasPursuit (1 vs 3): the solo player runs right along a side-scrolling course
   (222320.c); a giant Piranha Plant chases from the left. The three others watch from the
   shore and throw coins at the end. 225DF0.c builds the course (obstacles, water, the plant).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "sprite65770.h"
#include "PR/gu.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player's state (D_80100CE0_PiranhasPursuit[4], 0x60 each). On the N64 the player object's
   omObjData::work holds a big-endian pointer to it; the host keeps the index there. No pointers. */
typedef struct PPPlayer {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u16 unk2; /* flags: 1 running, 2 on a log, 4 caught, 8 ... */
    /* 0x04 */ char unk4[0x18];
    /* 0x1C */ f32 unk1C; /* plant model position */
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ char unk28[0xC];
    /* 0x34 */ f32 unk34; /* plant model rotation */
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ char unk48[0x18];
} PPPlayer; /* size = 0x60 */

/* A player object's work (func_8000979C: 0xE8 bytes, MgWork's layout; main code reads it). */
typedef struct PPWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38; /* vertical speed */
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40; /* forward speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ char unk_52[4];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[0x59];
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3; /* sound handle */
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8; /* motion table */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} PPWork; /* size = 0xE8 */

#define PP_WORK(obj) ((PPWork*)(obj)->unk_50)

/* A coin thrown at the end (D_80100E68_PiranhasPursuit[15], 0x28 each). */
typedef struct PPCoin {
    /* 0x00 */ s16 sprite;
    /* 0x02 */ s16 state;
    /* 0x04 */ s16 timer;
    /* 0x06 */ s16 sound;
    /* 0x08 */ f32 vy;
    /* 0x0C */ f32 vx;
    /* 0x10 */ f32 x;
    /* 0x14 */ f32 y;
    /* 0x18 */ f32 z;
    /* 0x1C */ char unk1C[0xC];
} PPCoin; /* size = 0x28 */

/* A course piece (D_8010112C_PiranhasPursuit points at 25 of them, 0x3C each). */
typedef struct PPPiece {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2; /* type: 1..6 */
    /* 0x04 */ f32 unk4; /* half width */
    /* 0x08 */ s16 unk8;
    /* 0x0A */ char unkA[6];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char unk18[0x1C];
    /* 0x34 */ f32 unk34; /* x */
    /* 0x38 */ f32 unk38; /* y */
} PPPiece; /* size = 0x3C */

/* ---------------------------------------------------------------------------------------------
   Data (.data)
   --------------------------------------------------------------------------------------------- */
extern s32 D_801001F0_PiranhasPursuit; /* game state */
extern s16 D_801001F4_PiranhasPursuit;
extern s32 D_801001F8_PiranhasPursuit;
extern f32 D_801001FC_PiranhasPursuit; /* scroll x */
extern f32 D_80100200_PiranhasPursuit;
extern f32 D_80100204_PiranhasPursuit;
extern f32 D_80100208_PiranhasPursuit;
extern s32 D_8010020C_PiranhasPursuit; /* the solo player */
extern s32 D_80100210_PiranhasPursuit;
extern s32 D_80100214_PiranhasPursuit;
extern f32 D_80100218_PiranhasPursuit;
extern s32 D_8010021C_PiranhasPursuit; /* _CheckFlag(0x2B) */
extern f32 D_80100220_PiranhasPursuit;
extern s32 D_80100224_PiranhasPursuit; /* camera timer; retail also reads its low half */
extern const char* D_80100228_PiranhasPursuit[6];
extern s32 D_80100240_PiranhasPursuit;
extern s32 D_80100244_PiranhasPursuit;
extern s32 D_80100248_PiranhasPursuit;
extern f32 D_8010024C_PiranhasPursuit;
extern u32 D_80100250_PiranhasPursuit; /* random seed */

extern const char D_801004B0_PiranhasPursuit[];
extern const char D_801004BC_PiranhasPursuit[];
extern const char D_801004C8_PiranhasPursuit[];
extern const char D_801004D4_PiranhasPursuit[];
extern const char D_801004E0_PiranhasPursuit[];
extern const char D_801004EC_PiranhasPursuit[];

/* ---------------------------------------------------------------------------------------------
   Bss
   --------------------------------------------------------------------------------------------- */
extern PPPiece* D_80100CA0_PiranhasPursuit;
extern f32 D_80100CA4_PiranhasPursuit;
extern s32 D_80100CA8_PiranhasPursuit;
extern f32 D_80100CAC_PiranhasPursuit; /* saved D_800B89xx tuning, restored on exit */
extern f32 D_80100CB0_PiranhasPursuit;
extern f32 D_80100CB4_PiranhasPursuit;
extern f32 D_80100CB8_PiranhasPursuit;
extern f32 D_80100CBC_PiranhasPursuit;
extern f32 D_80100CC0_PiranhasPursuit;
extern f32 D_80100CC4_PiranhasPursuit;
extern f32 D_80100CC8_PiranhasPursuit;
extern f32 D_80100CCC_PiranhasPursuit;
extern f32 D_80100CD0_PiranhasPursuit;
extern f32 D_80100CD4_PiranhasPursuit;
extern omObjData* D_80100CD8_PiranhasPursuit;
extern s32 D_80100CDC_PiranhasPursuit;
extern PPPlayer D_80100CE0_PiranhasPursuit[4];
/* Labels inside D_80100CE0: [0].unk1C, and [n].unk40. */
#define D_80100CFC_PiranhasPursuit (D_80100CE0_PiranhasPursuit[0].unk1C)
#define D_80100D20_PiranhasPursuit (D_80100CE0_PiranhasPursuit[0].unk40)
#define D_80100D40_PiranhasPursuit (D_80100CE0_PiranhasPursuit[1])
#define D_80100D80_PiranhasPursuit (D_80100CE0_PiranhasPursuit[1].unk40)
#define D_80100DA0_PiranhasPursuit (D_80100CE0_PiranhasPursuit[2])
#define D_80100DE0_PiranhasPursuit (D_80100CE0_PiranhasPursuit[2].unk40)
#define D_80100E00_PiranhasPursuit (D_80100CE0_PiranhasPursuit[3])
#define D_80100E40_PiranhasPursuit (D_80100CE0_PiranhasPursuit[3].unk40)
extern s16 D_80100E60_PiranhasPursuit;
/* func_800174C0's u16 model kept as s32; retail reads its low half (D_80100E66). */
extern s32 D_80100E64_PiranhasPursuit;
#define D_80100E66_PiranhasPursuit ((s16)D_80100E64_PiranhasPursuit)
extern PPCoin D_80100E68_PiranhasPursuit[15];
extern Vec D_801010C0_PiranhasPursuit; /* camera move: center from */
extern Vec D_801010CC_PiranhasPursuit; /* center to */
extern Vec D_801010D8_PiranhasPursuit; /* rotation from */
extern Vec D_801010E4_PiranhasPursuit; /* rotation to */
extern f32 D_801010F0_PiranhasPursuit; /* zoom from */
extern f32 D_801010F4_PiranhasPursuit; /* zoom to */
extern s16 D_801010F8_PiranhasPursuit; /* frames left */
extern u16 D_801010FA_PiranhasPursuit; /* frames */
extern s16 D_801012F2_PiranhasPursuit[4];

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern s32 D_800EDEC0;
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern u16 ContBtn[];
extern s8 ContStkY[];
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
extern f32 D_800B8990;
extern f32 D_800B8994;

void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800093FC(omObjData*, f32, f32, f32);
s32 func_80017A60(omObjData*);
void func_80017BB0(omObjData*);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
s32 func_800185A4(omObjData*, u16);
void func_80027AC8(s16, u8*, u8*);
void func_80060F04(s16, s16, s16, s16);
void func_80066DF4(s16, s16, s16, f32, f32, f32);
void func_80067284(s16, s16, f32);
s32 func_80067328(s16, s16);
f64 func_8009B618(f64, f64);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
void func_800F6AA8_PiranhasPursuit(omObjData* obj);
void func_800F6B74_PiranhasPursuit(omObjData* obj);
void func_800F6BB0_PiranhasPursuit(omObjData* obj);
void func_800F6C78_PiranhasPursuit(f32 x);
void func_800F6C84_PiranhasPursuit(omObjData* obj);
void func_800F70D0_PiranhasPursuit(omObjData* obj);
void func_800F7158_PiranhasPursuit(omObjData* obj);
void func_800F71F0_PiranhasPursuit(omObjData* obj);
void func_800F7298_PiranhasPursuit(omObjData* obj);
void func_800F7320_PiranhasPursuit(omObjData* obj, s32 player);
void func_800F782C_PiranhasPursuit(omObjData* obj, s32 player);
void func_800F7AA0_PiranhasPursuit(omObjData* obj);
void func_800F8114_PiranhasPursuit(omObjData* obj);
void func_800F9854_PiranhasPursuit(omObjData* obj);
void func_800F9BF0_PiranhasPursuit(void);
void func_800F9CBC_PiranhasPursuit(omObjData* obj, PPPlayer* p);
PPPlayer* func_800F9CDC_PiranhasPursuit(omObjData* obj);
void func_800F9D08_PiranhasPursuit(void);
u32 func_800F9D40_PiranhasPursuit(void);
void func_800F9D78_PiranhasPursuit(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_800F9E00_PiranhasPursuit(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames);
void func_800F9E84_PiranhasPursuit(void);
void func_800F9EE8_PiranhasPursuit(void);
void func_800F9F4C_PiranhasPursuit(omObjData* obj); /* obj unused */

void func_800FA0B0_PiranhasPursuit(void);
void func_800FA1E4_PiranhasPursuit(void);
void func_800FA7C0_PiranhasPursuit(u16 frames);
void func_800FB5C8_PiranhasPursuit(f32 x);
PPPiece* func_800FC3F4_PiranhasPursuit(f32 x, f32 y);
s32 func_800FC5A8_PiranhasPursuit(omObjData* obj);
void func_800FD4BC_PiranhasPursuit(f32 x, f32 y);

#endif
