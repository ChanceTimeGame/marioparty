#include "common.h"

/* D_800FAE10's work (func_800F6C7C, 0x48 bytes): the player's ball. */
typedef struct BumperBallMazeBallWork {
    /* 0x00 */ u16 unk_00; /* state */
    /* 0x02 */ s16 character;
    /* 0x04 */ u16 player;
    /* 0x06 */ char pad_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 unk_3E;
    /* 0x40 */ u8 unk_40[2];
    /* 0x42 */ char pad_42[2];
    /* 0x44 */ f32 unk_44;
} BumperBallMazeBallWork; /* size = 0x48 */

/* D_800FAE14's work (func_800F9050, 0x20 bytes): the timer display. */
typedef struct BumperBallMazeTimerWork {
    /* 0x00 */ s16 digits[7];
    /* 0x0E */ s16 bestDigits[7];
    /* 0x1C */ u16 time;
    /* 0x1E */ u16 best;
} BumperBallMazeTimerWork; /* size = 0x20 */

typedef struct BumperBallMazeColVtx {
    s16 x;
    s16 y;
    s16 z;
} BumperBallMazeColVtx;

typedef struct BumperBallMazeHitProbe {
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
} BumperBallMazeHitProbe;

/* Floor heights under the ball: eight points 55 units around pos, then pos itself (func_800F8AFC). */
typedef struct BumperBallMazeFloorProbe {
    /* 0x00 */ f32 height[8];
    /* 0x20 */ f32 centerHeight;
    /* 0x24 */ u16 attr[8];
    /* 0x34 */ u16 centerAttr;
    /* 0x36 */ char pad_36[2];
    /* 0x38 */ Vec3f pos;
} BumperBallMazeFloorProbe; /* size = 0x44 */

typedef struct BumperBallMazeFallingWork {
    char unk_00[0x44];
    f32 angle;
} BumperBallMazeFallingWork;

extern omObjData* D_800FAE10_BumperBallMaze;
extern omObjData* D_800FAE14_BumperBallMaze;
extern u16 D_800FACC0_BumperBallMaze;
extern s16 D_800FADF6_BumperBallMaze;
extern u16 D_800FADF8_BumperBallMaze;
extern s32 D_800FAB00_BumperBallMaze[];
extern u16 D_800FB1C0_BumperBallMaze;
extern omObjData* D_800FAE08_BumperBallMaze;
extern omObjData* D_800FAE0C_BumperBallMaze;
extern u16 D_800FADF0_BumperBallMaze;
extern u16 D_800FADF2_BumperBallMaze;
extern u16 D_800FADF4_BumperBallMaze;
extern f32 D_800FAE18_BumperBallMaze;
extern Vec3f D_800FAC7C_BumperBallMaze[];

typedef struct BumperBallMazeCameraPreset {
    f32 cameraValue;
    f32 zoom;
    Vec3f rot;
    Vec3f center;
} BumperBallMazeCameraPreset;

extern BumperBallMazeCameraPreset D_800FAB5C_BumperBallMaze[];
extern u8 D_800FAD28_BumperBallMaze[];
extern s16 D_800FADFC_BumperBallMaze;
extern s16 D_800FADFE_BumperBallMaze;
extern s16 D_800FAE00_BumperBallMaze;
extern s16 D_800FAE02_BumperBallMaze;
extern omObjData* D_800FAE04_BumperBallMaze;
extern s16 D_800FB1C4_BumperBallMaze;
extern u16 D_800FAB3C_BumperBallMaze[];
extern u16 D_800FADFA_BumperBallMaze;
extern u16 D_800FB1C2_BumperBallMaze;
extern Vec3f D_800FAB0C_BumperBallMaze[];
extern f32 D_800FAB30_BumperBallMaze[];
extern u8* D_800FACA0_BumperBallMaze[];

/* objmain.c's objmainChr (D_800C59A8[6]); the (chr << 16 | unk06) word is D_800C59AC[c].unk_00. */
typedef struct BumperBallMazeChr {
    /* 0x00 */ s16 index;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 chr;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 file0;
    /* 0x0C */ s32 file1;
    /* 0x10 */ f32 scale;
} BumperBallMazeChr; /* size = 0x14 */
extern BumperBallMazeChr D_800C59A8[6];

void func_800FA620_BumperBallMaze(void);
void func_800F9990_BumperBallMaze(void);
void func_800F6C28_BumperBallMaze(void);
void func_800F69F4_BumperBallMaze(omObjData*);
void func_800F9974_BumperBallMaze(s32);
void func_800F6C7C_BumperBallMaze(omObjData*);
s32 func_800F8E1C_BumperBallMaze(BumperBallMazeHitProbe*, u16*, BumperBallMazeColVtx*);
void func_800F928C_BumperBallMaze(u16, s16*);
void func_800F8220_BumperBallMaze(omObjData*);
void func_800594E4(s16, u16);
void func_8001897C(s16, f32, f32, f32);
void func_800F96B0_BumperBallMaze(f32, f32, f32, f32, f32, f32, f32, f32);
void func_800F9768_BumperBallMaze(void);
void func_800F6994_BumperBallMaze(omObjData*);
void func_800F6BB8_BumperBallMaze(omObjData*);
void func_800F6C44_BumperBallMaze(s32);
void func_800F8184_BumperBallMaze(omObjData*);
void func_800F8AB8_BumperBallMaze(void);
void func_800F9050_BumperBallMaze(omObjData*);
void func_800F827C_BumperBallMaze(omObjData*);
void func_800F8468_BumperBallMaze(omObjData*);
u16 func_800F9278_BumperBallMaze(void);
s32 func_800F9034_BumperBallMaze(void);
void func_800F943C_BumperBallMaze(void);
void func_800F7240_BumperBallMaze(omObjData*);
void func_8001E268(s16, u8, u8);
f32 func_800296FC(f32, f32, BumperBallMazeColVtx*, BumperBallMazeColVtx*);
f32 func_80029764(f32, f32, f32, void*, u16*);
void func_8002AE24(s16, s32*, void*, void*);
u16* func_8002B3A8(s32*);
s32 func_800F8DFC_BumperBallMaze(s32, u16*, BumperBallMazeColVtx*, BumperBallMazeHitProbe*);
u16 func_800F8AFC_BumperBallMaze(BumperBallMazeFloorProbe*);
void func_80025BB8(s16, s16);
void func_80027AC8(s16, u8*, u8*);
f32 func_80025D18(s16);
f32 func_80025D40(s16);

void func_800F65E0_BumperBallMaze(void) {
    BumperBallMazeCameraPreset* cam;
    void* data;
    s16 sprite;

    omInitObjMan(0x14, 0);
    func_80060088();
    switch (GwSystem.unk_1E) {
    case 0x24:
        D_800FADF8_BumperBallMaze = 1;
        break;
    case 0x35:
        D_800FADF8_BumperBallMaze = 2;
        break;
    case 0x23:
    default:
        D_800FADF8_BumperBallMaze = 0;
        break;
    }
    func_80029090(2);
    func_8001DE70(0xC);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8002890C(0, 0x20, 0x80);
    func_8002578C(1);
    cam = &D_800FAB5C_BumperBallMaze[D_800FADF8_BumperBallMaze];
    func_800F96B0_BumperBallMaze(cam->cameraValue, cam->zoom, cam->rot.x, cam->rot.y, cam->rot.z,
                                 cam->center.x, cam->center.y, cam->center.z);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_80023448(3);
    func_800234B8(0, 0x2C, 0x2C, 0x40);
    func_800234B8(1, 0x60, 0x60, 0x10);
    func_80023504(1, 100.0f, 80.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 100.0f, 80.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 80.0f, 100.0f);
    D_800FAE10_BumperBallMaze = omAddObj(0x14, 9, 6, -1, func_800F6C44_BumperBallMaze);
    omAddObj(0x28, 1, 0, -1, func_800F8184_BumperBallMaze);
    omAddObj(0, 0, 0, -1, func_800F6994_BumperBallMaze);
    D_800FAE04_BumperBallMaze = omAddObj(6, 2, 0, -1, func_800F6BB8_BumperBallMaze);
    omAddObj(0x2710, 0, 0, -1, func_800F8AB8_BumperBallMaze);
    D_800FAE14_BumperBallMaze = omAddObj(0x28, 0, 0, -1, func_800F9050_BumperBallMaze);
    func_800F9768_BumperBallMaze();
    data = DataRead(0x25);
    D_800FADFC_BumperBallMaze = func_80039084(data);
    HuMemDirectFree(data);
    data = DataRead(0x24);
    D_800FADFE_BumperBallMaze = func_80039084(data);
    HuMemDirectFree(data);
    func_8007B168(D_800FAD28_BumperBallMaze, 1);
    D_800FAE00_BumperBallMaze = InitSprite(0x87);
    D_800FAE02_BumperBallMaze = sprite = InitSprite(0x87);
    func_8001897C(sprite, 0.0f, 1.0f, 0.0f);
    D_800FB1C4_BumperBallMaze = 0;
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6994_BumperBallMaze(omObjData* object) {
    D_800FB1C0_BumperBallMaze = 0;
    D_800FAE0C_BumperBallMaze = NULL;
    D_800FAE08_BumperBallMaze = NULL;
    D_800FADF0_BumperBallMaze = 0;
    D_800FADF2_BumperBallMaze = 1;
    D_800FADF4_BumperBallMaze = 0;
    D_800FADF6_BumperBallMaze = 0;
    D_800FAE18_BumperBallMaze = 0.96f;
    object->func_ptr = func_800F69F4_BumperBallMaze;
}

void func_800F69F4_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* state;

    switch (D_800FB1C0_BumperBallMaze) {
    case 0:
        if (D_800FAE08_BumperBallMaze == NULL) {
            D_800FAE08_BumperBallMaze = omAddObj(4, 0, 0, -1, func_800F827C_BumperBallMaze);
        }
        break;
    case 1:
        D_800FADFA_BumperBallMaze = func_800F9278_BumperBallMaze();
        if (D_800FADF2_BumperBallMaze == 0
            || D_800FADFA_BumperBallMaze >= D_800FAB3C_BumperBallMaze[D_800FADF8_BumperBallMaze]
            || D_800FADF4_BumperBallMaze == 1) {
            func_800601D4(0x28);
            if ((u16) func_800F9034_BumperBallMaze() == 1) {
                D_800FB1C0_BumperBallMaze = 2;
                D_800FB1C2_BumperBallMaze = 4;
                D_800FAE14_BumperBallMaze->work[0] = 0;
            }
            if (D_800FADF4_BumperBallMaze == 1) {
                D_800FB1C0_BumperBallMaze = 2;
                D_800FB1C2_BumperBallMaze = 0xA;
                func_800F943C_BumperBallMaze();
                D_800FAE14_BumperBallMaze->work[0] = 0;
                state = D_800FAE10_BumperBallMaze->unk_50;
                if (state->unk_00 != 3 && state->unk_00 != 4 && state->unk_00 != 5) {
                    state->unk_00 = 6;
                }
            }
        }
        break;
    case 2:
        if (D_800FAE0C_BumperBallMaze == NULL) {
            D_800FAE0C_BumperBallMaze = omAddObj(4, 0, 0, -1, func_800F8468_BumperBallMaze);
        }
        break;
    }
}

void func_800F6BB8_BumperBallMaze(omObjData* object) {
    object->model[0] = LoadFormFile(D_800FAB00_BumperBallMaze[D_800FADF8_BumperBallMaze], 0x289);
    object->model[1] = LoadFormFile(0x380003, 0x48D);
    func_800F9990_BumperBallMaze();
    object->func_ptr = func_800F6C28_BumperBallMaze;
}

void func_800F6C28_BumperBallMaze(void) {
    func_800FA620_BumperBallMaze();
}

void func_800F6C44_BumperBallMaze(s32 arg0) {
    LoadFormFile(0x310002, 0x69D);
    func_800F6C7C_BumperBallMaze(arg0);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", D_800FACE0_BumperBallMaze);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", D_800FACEC_BumperBallMaze);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", D_800FACF8_BumperBallMaze);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", D_800FAD04_BumperBallMaze);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", D_800FAD10_BumperBallMaze);

const char D_800FAD1C_BumperBallMaze[] = "38mt001_DEF";

void func_800F6C7C_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* work;
    s32 i;
    s16 player;
    s32 chrBase;
    s8 chr;
    f32 zero;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    player = ((u16) i < 4) ? i : 0;
    work = object->unk_50 = func_80023684(0x48, 0x7918);
    work->unk_00 = 0;
    work->player = player;
    work->unk_20 = 50.0f;
    work->unk_1C = 0.0f;
    zero = work->unk_1C;
    work->unk_30 = work->unk_34 = work->unk_38 = work->unk_24 = work->unk_2C = zero;
    work->unk_3C = 0;
    work->unk_44 = zero;
    work->unk_3E = 0;
    for (i = 0; i < 2; i++) {
        work->unk_40[i] = 0;
    }
    chr = GwPlayer[(u16) player].character;
    work->character = chr;
    chrBase = D_800C59AC[chr].unk_00;
    object->model[0] = LoadFormFile(chrBase | D_800C59A8[chr].file0, 0x20699);
    omSetTra(object, D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].x,
             D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].y,
             D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].z);
    if ((u16) D_800C59A8[chr].index == 5) {
        work->unk_08 = 10.0f;
        omSetSca(object, 0.95f, 0.95f, 0.95f);
        omSetTra(object, D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].x,
                 D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].y - 10.0f,
                 D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].z);
    } else {
        work->unk_08 = 0.0f;
        omSetSca(object, 1.0f, 1.0f, 1.0f);
    }
    object->model[1] = func_800174F4(0x20, 0x689);
    func_80025830(object->model[1], 1.25f, 1.25f, 1.25f);
    func_80025798(object->model[1], object->trans.x, 125.0f, object->trans.z);
    object->model[5] = LoadFormFile(0x1A, 0x68D);
    for (i = 0; i < 2; i++) {
        if ((u16) player == 0 && i == 0) {
            object->model[6 + i] = LoadFormFile(0x19, 0x68D);
        } else {
            object->model[6 + i] = func_80023FC8(D_800FAE10_BumperBallMaze->model[6]);
        }
    }
    func_8001775C(object, 0, chrBase);
    func_8001775C(object, 1, chrBase | 1);
    func_8001775C(object, 2, chrBase | 3);
    if (rand8() & 1) {
        func_8001775C(object, 3, chrBase | 0xF);
    } else {
        func_8001775C(object, 3, chrBase | 0x38);
    }
    func_8001775C(object, 4, chrBase | 0x17);
    func_8001775C(object, 5, chrBase | 0x10);
    object->model[4] = func_8001E00C((void*) -1, 0x68D, 8);
    D_800ECDE0[object->model[4]].unk_02 = D_800FADFE_BumperBallMaze;
    func_80025930(D_800ECDE0[object->model[4]].unk_00, 0x40000000, 0x40000000);
    func_8001E268(object->model[4], 4, 4);
    object->model[3] = func_8001E00C((void*) -1, 0x68D, 8);
    D_800ECDE0[object->model[3]].unk_02 = D_800FADFC_BumperBallMaze;
    func_80025930(D_800ECDE0[object->model[3]].unk_00, 0x40000000, 0x40000000);
    func_8001E268(object->model[3], 4, 4);
    object->model[2] = LoadFormFile(0x310001, 0x20689);
    func_80027AC8(object->model[2], (u8*) D_800FAD1C_BumperBallMaze, D_800FACA0_BumperBallMaze[chr]);
    func_80025AD4(object->model[2]);
    work->unk_0C = D_800FAB30_BumperBallMaze[D_800FADF8_BumperBallMaze];
    if (work->unk_0C < 0.0f) {
        work->unk_0C += 360.0f;
    }
    work->unk_34 = work->unk_14 = work->unk_10 = work->unk_0C;
    omSetRot(object, 0.0f, work->unk_0C, 0.0f);
    func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_80025798(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08,
                  object->trans.z);
    func_80025BB8(object->model[0], object->motion[0]);
    func_80025EB4(object->model[0], 2, 2);
    object->func_ptr = func_800F7240_BumperBallMaze;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", D_800FAD28_BumperBallMaze);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F7240_BumperBallMaze);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F7BB8_BumperBallMaze);

void func_800F7ED0_BumperBallMaze(omObjData* object) {
    BumperBallMazeFallingWork* work = object->unk_50;

    omSetTra(object, object->trans.x,
             func_800AEAC0(work->angle) * 2.0f + object->trans.y,
             object->trans.z);
    work->angle += 8.0f;
    if (work->angle >= 360.0f) {
        work->angle -= 360.0f;
    }
}

void func_800F7F60_BumperBallMaze(omObjData* object) {
    omSetTra(object, object->trans.x, object->trans.y - 20.0f, object->trans.z);
    if (object->trans.y < -3000.0f) {
        func_800258EC(object->model[0], 4, 4);
        omDelObj(object);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F7FE0_BumperBallMaze);

void func_800F8108_BumperBallMaze(omObjData* object) {
    f32 time = func_80025D18(object->work[0]);

    if (func_80025D40(object->work[0]) <= time) {
        ((BumperBallMazeBallWork*) D_800FAE10_BumperBallMaze->unk_50)->unk_40[object->work[2]] = 0;
        func_800258EC(object->work[0], 4, 4);
        omDelObj(object);
    }
}

void func_800F8184_BumperBallMaze(omObjData* object) {
    object->model[0] = LoadFormFile(0xA00FF, 0x20699);
    func_80025EB4(object->model[0], 2, 2);
    omSetTra(object,
             D_800FAC7C_BumperBallMaze[D_800FADF8_BumperBallMaze].x,
             D_800FAC7C_BumperBallMaze[D_800FADF8_BumperBallMaze].y,
             D_800FAC7C_BumperBallMaze[D_800FADF8_BumperBallMaze].z);
    object->func_ptr = func_800F8220_BumperBallMaze;
}

void func_800F8220_BumperBallMaze(omObjData* object) {
    omSetRot(object, 0.0f,
             func_800B0CD8(D_800FAE10_BumperBallMaze->trans.x - object->trans.x,
                           D_800FAE10_BumperBallMaze->trans.z - object->trans.z),
             0.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F827C_BumperBallMaze);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F8468_BumperBallMaze);

void func_800F8AB8_BumperBallMaze(void) {
    if (D_800FACC0_BumperBallMaze != 0 || D_800F5144 != 0) {
        func_800F9974_BumperBallMaze(0x83);
        func_800601D4(0x28);
    }
}

u16 func_800F8AFC_BumperBallMaze(BumperBallMazeFloorProbe* out) {
    BumperBallMazeHitProbe probe;
    unk2C0C0StructA0* verts;
    u16* tri;
    f32 x;
    f32 y;
    f32 z;
    f32 best;
    f32 h;
    f32 angle;
    u16 i;
    u16 misses;

    verts = D_800F2B7C[D_800FAE04_BumperBallMaze->model[0]].unk_6C->unk_78;
    misses = 0;
    for (i = 0; i < 8; i++) {
        angle = i * 45.0f;
        x = func_800AEAC0(angle) * 55.0f + out->pos.x;
        y = out->pos.y;
        z = func_800AEFD0(angle) * 55.0f + out->pos.z;
        best = out->height[i] = -10000.0f;
        out->attr[i] = 0xFFFF;
        probe.x = x;
        probe.y = y;
        probe.z = z;
        func_8002AE24(D_800FAE04_BumperBallMaze->model[0], &D_800EDEC0, func_800F8DFC_BumperBallMaze, &probe);
        for (tri = func_8002B3A8(&D_800EDEC0); tri != NULL; tri = func_8002B3A8(&D_800EDEC0)) {
            h = func_80029764(x, y, z, verts, tri);
            if (best < h) {
                best = h;
                out->height[i] = h;
                out->attr[i] = *tri & 0x3FFF;
            }
        }
        if (best == -10000.0f) {
            misses++;
        }
    }
    x = out->pos.x;
    y = out->pos.y;
    z = out->pos.z;
    best = out->centerHeight = -10000.0f;
    out->centerAttr = 0xFFFF;
    probe.x = x;
    probe.y = y;
    probe.z = z;
    func_8002AE24(D_800FAE04_BumperBallMaze->model[0], &D_800EDEC0, func_800F8DFC_BumperBallMaze, &probe);
    goto next;
    do {
        h = func_80029764(x, y, z, verts, tri);
        if (best < h) {
            best = h;
            out->centerHeight = h;
            out->centerAttr = *tri & 0x3FFF;
        }
    next:
        tri = func_8002B3A8(&D_800EDEC0);
    } while (tri != NULL);
    if (best == -10000.0f) {
        misses++;
    }
    return misses;
}

s32 func_800F8DFC_BumperBallMaze(s32 arg0, u16* polygon, BumperBallMazeColVtx* vertices,
                                BumperBallMazeHitProbe* probe) {
    return func_800F8E1C_BumperBallMaze(probe, polygon - 1, vertices);
}

s32 func_800F8E1C_BumperBallMaze(BumperBallMazeHitProbe* probe, u16* poly, BumperBallMazeColVtx* verts) {
    f32 x = probe->x;
    f32 z = probe->z;
    s32 cnt = (poly[0] >> 14) + 2;
    s32 i;
    s32 j;

    poly++;
    if (func_800296FC(x, z, &verts[(s16) poly[0]], &verts[(s16) poly[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[(s16) poly[i]], &verts[(s16) poly[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[(s16) poly[i]], &verts[(s16) poly[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_800F9034_BumperBallMaze(void) {
    return ((BumperBallMazeBallWork*) D_800FAE10_BumperBallMaze->unk_50)->unk_00 != 3;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F9050_BumperBallMaze);

void func_800F923C_BumperBallMaze(omObjData* object) {
    BumperBallMazeTimerWork* state = object->unk_50;

    if (object->work[0] == 1) {
        state->time += 2;
        func_800F928C_BumperBallMaze(state->time, state->digits);
    }
}

u16 func_800F9278_BumperBallMaze(void) {
    return ((BumperBallMazeTimerWork*) D_800FAE14_BumperBallMaze->unk_50)->time;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F928C_BumperBallMaze);

void func_800F943C_BumperBallMaze(void) {
    BumperBallMazeTimerWork* state = D_800FAE14_BumperBallMaze->unk_50;

    if (state->best > state->time) {
        state->best = state->time;
        func_800594E4(D_800FADF8_BumperBallMaze + 5, state->best);
        D_800FADF6_BumperBallMaze = 1;
    }
}

void func_800F94A0_BumperBallMaze(omObjData* object) {
    BumperBallMazeFloorProbe probe;
    f32 angle;
    f32 dx;
    f32 dz;
    u16 i;
    u16 misses;
    u16 tries;

    tries = 0;
    do {
        probe.pos.x = object->trans.x;
        probe.pos.y = object->trans.y + -100.0f;
        probe.pos.z = object->trans.z;
        func_800F8AFC_BumperBallMaze(&probe);
        misses = 0;
        for (i = 0; i < 8; i++) {
            if (probe.height[i] == -10000.0f) {
                misses++;
                continue;
            }
            angle = ((u16) (i + 4) & 7) * 45.0f;
            dx = func_800AEAC0(angle) * 5.0f;
            dz = func_800AEFD0(angle) * 5.0f;
            object->trans.x = dx + object->trans.x;
            object->trans.z = dz + object->trans.z;
        }
        if (misses == 8) {
            break;
        }
    } while (++tries < 4);
}

void func_800F9610_BumperBallMaze(s32 player) {
    u16 remaining = 0xE10 - func_800F9278_BumperBallMaze();
    u16 q = remaining / 60;
    u16 reward = q;

    if ((u16) (remaining % 60) != 0) {
        reward = q + 1;
    }
    GwPlayer[(u16) player].coins_mg += reward + 10;
}
