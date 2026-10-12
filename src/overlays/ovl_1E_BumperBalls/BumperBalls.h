#include "common.h"

typedef struct UnkBumberBallsStruct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[0x40];
    /* 0x42 */ u16 unk_42;
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ f32 unk_50;
} UnkBumberBallsStruct; //sizeof unknown

extern omObjData** D_800FCD2C_BumperBalls;

void func_800FC618_BumperBalls(void);
void func_800FB2EC_BumperBalls(void);
void func_800F6E10_BumperBalls(omObjData*);
void func_800F6EBC_BumperBalls(s32, s32);
void func_800F85A8_BumperBalls(s32, s32);
void func_800F9CC8_BumperBalls(s32, s32);
void func_800FA5A4_BumperBalls(void);
void func_800FA950_BumperBalls(void);
void func_800FAB54_BumperBalls(void);
void func_800FAE60_BumperBalls(void);
void func_800F6AB4_BumperBalls(omObjData*);
void func_800F9588_BumperBalls(void);
void func_800FB298_BumperBalls(void);

void func_800F6E2C_BumperBalls(s32 arg0);
void func_800F6E68_BumperBalls(s32 arg0);
void func_800F6E84_BumperBalls(s32 arg0);
void func_800F6EA0_BumperBalls (s32 arg0);
void func_800F8538_BumperBalls(s32 arg0);
void func_800F8554_BumperBalls(s32 arg0);
void func_800F8570_BumperBalls(s32 arg0);
void func_800F858C_BumperBalls(s32 arg0);
void func_800F6A60_BumperBalls(omObjData* arg0);
void func_800F6D98_BumperBalls(omObjData* arg0);


void func_800FB1E0_BumperBalls(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);

extern s16 D_800FCD0E_BumperBalls;
extern s16 D_800FCD10_BumperBalls;
extern s16 D_800FCD16_BumperBalls;
extern s32 D_800FCD24_BumperBalls;
extern s32 D_800FCD28_BumperBalls;
extern s16 D_800FCFF4_BumperBalls;
extern s16 D_800F3778;

extern s32 D_800EDEC0;
extern char D_800FCC28_BumperBalls[];
extern s16 D_800FCD12_BumperBalls;
extern s16 D_800FCD18_BumperBalls;
extern s16 D_800FCD1A_BumperBalls;
extern s16 D_800FCD1C_BumperBalls;
extern u16 D_800FCD1E_BumperBalls;
extern omObjData* D_800FCD20_BumperBalls;
extern omObjData** D_800FCD30_BumperBalls;
extern s16 D_800FCFF0_BumperBalls;

extern u16 D_800FCD14_BumperBalls;

/* Water mesh (196300.c). */
typedef struct BumperBallsAnglePair {
    f32 first;
    f32 second;
} BumperBallsAnglePair;

/* Wave phases of the 6 x 6 water mesh (bss): per row, the near edge's 6 pairs then the far
   edge's 6. Retail indexes it both as rows of 12 pairs and as half-rows of 6 (BB_WAVE_HALF, far
   edge of row r = half-row 2r + 1); its splat label D_800FCD70 is D_800FCD40 + 0x30. */
extern BumperBallsAnglePair D_800FCD40_BumperBalls[6][12];
#ifdef TARGET_PC
#define D_800FCD70_BumperBalls ((BumperBallsAnglePair(*)[6]) &D_800FCD40_BumperBalls[0][6])
#else
extern BumperBallsAnglePair D_800FCD70_BumperBalls[][6];
#endif
#define BB_WAVE_FAR ((BumperBallsAnglePair(*)[12]) &D_800FCD40_BumperBalls[0][6])
extern unk2C0C0Struct70* D_800FCF80_BumperBalls; /* 47mt003_DEF (water) */
extern unk2C0C0Struct70* D_800FCF84_BumperBalls; /* 47mt002_IA44 (under-layer) */
extern Gfx* D_800FCF88_BumperBalls[8];           /* per-screen display lists */
extern Vtx* D_800FCFA8_BumperBalls[8];           /* per-screen water vertices (6 x 24) */
extern Vtx* D_800FCFC8_BumperBalls[8];           /* per-screen under-layer vertices */
extern s32 D_800FCFE8_BumperBalls;

extern u16 D_800FCBC0_BumperBalls;
