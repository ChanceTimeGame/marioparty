#include "common.h"

typedef struct unkCrazyCutter_00 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[0x24];
    /* 0x30 */ s32 unk_30;
} unkCrazyCutter_00;

void func_800FBB2C_CrazyCutter(void);
void func_800FA880_CrazyCutter(void);
void func_800FA56C_CrazyCutter(void);
void func_800F68C4_CrazyCutter(omObjData*);
void func_800F978C_CrazyCutter(void);
void func_800F97C8_CrazyCutter(omObjData*);
s32 func_800FAAB0_CrazyCutter(s32, s32);
void func_800FAACC_CrazyCutter(s32, s32, s32);
void func_800FA9D8_CrazyCutter(void);
void func_800F686C_CrazyCutter(omObjData*);
void func_800F6B04_CrazyCutter(void);
void func_800F94C0_CrazyCutter(s32);
void func_800F94DC_CrazyCutter(s32);
void func_800F94F8_CrazyCutter(s32);
void func_800F9514_CrazyCutter(s32);
void func_800F731C_CrazyCutter(s32, s32);
u8* func_800FC4F0_CrazyCutter(s16 grpIdx, s16 idx, s32* width, s32* height);
s32 func_800FC70C_CrazyCutter(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask);
s32 func_800FC8C0_CrazyCutter(s16 grpIdx, s16 idx, s32 x, s32 y);
s32 func_800FC998_CrazyCutter(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4);
s32 func_800FC9F4_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4);
s32 func_800FCA20_CrazyCutter(u8* pal, u16 fmt);
s32 func_800FCAAC_CrazyCutter(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask);
s32 func_800FCC64_CrazyCutter(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4);
s32 func_800FCCC8_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4);
#ifdef TARGET_PC
#define CC_FUNC_800FCCC4 func_800FCCC8_CrazyCutter
#else
s32 D_800FCCC4_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4); /* a nop before func_800FCCC8 */
#define CC_FUNC_800FCCC4 D_800FCCC4_CrazyCutter
#endif
void func_800FBB94_CrazyCutter(void);
extern s16 D_800FD5C0_CrazyCutter;
extern u8* D_800FD51C_CrazyCutter;
extern s32 D_800FD528_CrazyCutter;
extern s32 D_800FD52C_CrazyCutter;
extern s32 D_800FD538_CrazyCutter;
extern u8* D_800FD518_CrazyCutter;
extern s32 D_800FD520_CrazyCutter;
extern s32 D_800FD524_CrazyCutter;
extern s32 D_800FD530_CrazyCutter;
extern s32 D_800FD4D8_CrazyCutter[];
extern u16 D_800FD590_CrazyCutter;
extern f32 D_800FCCF0_CrazyCutter[];
extern f32 D_800FCD00_CrazyCutter[];
extern s32 D_800FD488_CrazyCutter[];
extern f32 D_800FD558_CrazyCutter[];
extern f32 D_800FD568_CrazyCutter[];
extern f32 D_800FD578_CrazyCutter[];
extern s16 D_800FD5C8_CrazyCutter;
extern u16 D_800FD14E_CrazyCutter;
extern u16 D_800FD150_CrazyCutter;
extern s16 D_800FD5C6_CrazyCutter;
extern s16 D_800FD544_CrazyCutter;
extern s32 D_800FD554_CrazyCutter;
extern s32 D_800FD460_CrazyCutter;
extern s32 D_800FD464_CrazyCutter;
extern s32 D_800FD468_CrazyCutter;
extern s32 D_800FD4B0_CrazyCutter;
