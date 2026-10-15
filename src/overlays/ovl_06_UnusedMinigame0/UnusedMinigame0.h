#ifndef UNUSEDMINIGAME0_H
#define UNUSEDMINIGAME0_H

/* ovl_06 UnusedMinigame0: a 1P minigame left in the ROM but never launched (its overlay-table
   entry points at 0x25). The player walks a 8 x 6 board of 10-unit cells (x -350..350,
   z -250..250); 105EA0.c owns the board. FF570.c: setup, flow, the player. 103D80.c: camera
   keyframes, the per-object work, the board's collision outline. Types come from the asm's
   accesses; N64 offsets are in the comments. */

#include "common.h"
#include "PR/gu.h"
#include "engine/math.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* An object's extra work (func_800FB568_UnusedMinigame0: 0x60 bytes, kept in D_801098C0[]).
   omObjData::work[0..3] holds a big-endian pointer to it on the N64; the host keeps the
   D_801098C0 index there (func_800FB6D0_UnusedMinigame0). */
typedef struct UM0Work {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ char unk4[4];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ char unkA[2];
    /* 0x0C */ omObjData* obj;
    /* 0x10 */ Vec pos;
    /* 0x1C */ Vec unk1C;
    /* 0x28 */ Vec unk28;
    /* 0x34 */ char unk34[0xC];
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E;
} UM0Work; /* size = 0x60 */

/* What a board cell's entry points at first (105EA0.c owns it; only these fields are read here). */
typedef struct UM0CellState {
    /* 0x00 */ char unk0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ char unkC[4];
    /* 0x10 */ s32 unk10;
} UM0CellState;

typedef struct UM0Cell {
    /* 0x00 */ UM0CellState* state;
} UM0Cell;

/* A point of the board's collision outline (D_80103E28_UnusedMinigame0). */
typedef struct UM0Point {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 z;
} UM0Point;

/* A 2D point (func_800FC29C_UnusedMinigame0's list). */
typedef struct UM0Vec2 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 z;
} UM0Vec2;

/* The camera view at D_800EE73C (its rotation is the word before), as ovl_2B. */
typedef struct UM0CameraView {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 z;
    /* 0x08 */ f32 fov;
    /* 0x0C */ f32 far;
    /* 0x10 */ f32 near;
} UM0CameraView;

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

f64 func_8009B618(f64, f64); /* fmod */
#ifdef TARGET_PC
extern s32 D_800EE738; /* the rotation word before D_800EE73C */
#else
extern UM0CameraView D_800EE73C;
#endif

/* ---------------------------------------------------------------------------------------------
   Overlay .bss (shared by the units)
   --------------------------------------------------------------------------------------------- */

extern s16 D_80108B80_UnusedMinigame0;              /* D_801098C0 entries */
extern UM0Cell* D_80108B88_UnusedMinigame0[8][6];   /* the board, [x][z] (105EA0.c) */
extern omObjData* D_80108C4C_UnusedMinigame0[];      /* D_8010B450 entries */
extern omObjData* D_801098A0_UnusedMinigame0;        /* the camera object */
extern s16 D_801098B4_UnusedMinigame0[];
extern UM0Work* D_801098C0_UnusedMinigame0[256];     /* every UM0Work allocated */
extern u8 D_8010B450_UnusedMinigame0;

/* 103D80.c's .bss */
extern s16 D_80103E20_UnusedMinigame0;           /* outline points */
extern s16 D_80103E22_UnusedMinigame0;           /* outline index-list length */
extern UM0Point D_80103E28_UnusedMinigame0[0xC0];
extern s8 D_80104128_UnusedMinigame0[0x120];     /* point indices, 0xFF ends a loop */
extern UM0Point* D_80104248_UnusedMinigame0;     /* next free point */
extern s8* D_8010424C_UnusedMinigame0;           /* next free index */
extern f32 D_80104250_UnusedMinigame0[8][3];        /* camera keys: centre */
extern f32 D_801042B0_UnusedMinigame0[8][3];        /* camera keys: rotation */
extern f32 D_80104310_UnusedMinigame0[8];        /* camera keys: zoom */
extern s16 D_80104330_UnusedMinigame0;           /* keys */
extern s16 D_80104332_UnusedMinigame0;           /* frame */
extern s16 D_80104334_UnusedMinigame0;           /* length in frames, -1 none */

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

/* FF570.c */
f32 func_800F7320_UnusedMinigame0(f32 cur, f32 target, f32 step);

/* 103D80.c */
void func_800FADF0_UnusedMinigame0(omObjData* obj);
void func_800FAE84_UnusedMinigame0(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_800FAEC4_UnusedMinigame0(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames);
void func_800FB190_UnusedMinigame0(s32 i, f32 t);
void func_800FB3B4_UnusedMinigame0(omObjData* obj);
UM0Work* func_800FB568_UnusedMinigame0(omObjData* obj);
void func_800FB650_UnusedMinigame0(void);
UM0Work* func_800FB6D0_UnusedMinigame0(omObjData* obj);
u32 func_800FB6FC_UnusedMinigame0(void);
s32 func_800FB734_UnusedMinigame0(omObjData* obj);
s16 func_800FB810_UnusedMinigame0(f32 x, f32 z, s32 mask);
s16 func_800FB904_UnusedMinigame0(s16* x, s16* z);
s32 func_800FBAA0_UnusedMinigame0(s16 x, s16 z);
void func_800FBB18_UnusedMinigame0(f32 x, f32 z);
void func_800FBFE4_UnusedMinigame0(omObjData* obj);
void func_800FC29C_UnusedMinigame0(f32* x, f32* z, f32 dist, UM0Vec2* pts, s16 n);
s16 func_800FC564_UnusedMinigame0(f32* x, f32* z, f32 radius);
f32 func_800FC944_UnusedMinigame0(f32 x, f32 z);
s16 func_800FCA40_UnusedMinigame0(omObjData* obj, f32 dx, f32 dz, f32 radius);
void func_800FCD68_UnusedMinigame0(void);

/* 105EA0.c */
void func_801025B8_UnusedMinigame0(u8 board[8][6]);

#endif
