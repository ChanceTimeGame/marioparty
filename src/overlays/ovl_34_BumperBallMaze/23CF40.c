#include "common.h"

typedef struct BumperBallMazeModelState {
    u16 unk_00;
    char unk_02[0x1A];
    u16 unk_1C;
    u16 unk_1E;
    char unk_20[0x20];
    u8 unk_40[4];
} BumperBallMazeModelState;

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

void func_800FA620_BumperBallMaze(void);
void func_800F9990_BumperBallMaze(void);
void func_800F6C28_BumperBallMaze(void);
void func_800F69F4_BumperBallMaze(omObjData*);
void func_800F9974_BumperBallMaze(s32);
void func_800F6C7C_BumperBallMaze(s32);
s32 func_800F8E1C_BumperBallMaze(BumperBallMazeHitProbe*, u16*, BumperBallMazeColVtx*);
void func_800F928C_BumperBallMaze(u16);
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F69F4_BumperBallMaze);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F6C7C_BumperBallMaze);

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
        ((BumperBallMazeModelState*) D_800FAE10_BumperBallMaze->unk_50)->unk_40[object->work[2]] = 0;
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F8AFC_BumperBallMaze);

s32 func_800F8DFC_BumperBallMaze(s32 arg0, u16* polygon, BumperBallMazeColVtx* vertices,
                                BumperBallMazeHitProbe* probe) {
    return func_800F8E1C_BumperBallMaze(probe, polygon - 1, vertices);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F8E1C_BumperBallMaze);

s32 func_800F9034_BumperBallMaze(void) {
    return ((BumperBallMazeModelState*) D_800FAE10_BumperBallMaze->unk_50)->unk_00 != 3;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F9050_BumperBallMaze);

void func_800F923C_BumperBallMaze(omObjData* object) {
    BumperBallMazeModelState* state = object->unk_50;

    if (object->work[0] == 1) {
        state->unk_1C += 2;
        func_800F928C_BumperBallMaze(state->unk_1C);
    }
}

u16 func_800F9278_BumperBallMaze(void) {
    return ((BumperBallMazeModelState*) D_800FAE14_BumperBallMaze->unk_50)->unk_1C;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F928C_BumperBallMaze);

void func_800F943C_BumperBallMaze(void) {
    BumperBallMazeModelState* state = D_800FAE14_BumperBallMaze->unk_50;

    if (state->unk_1E > state->unk_1C) {
        state->unk_1E = state->unk_1C;
        func_800594E4(D_800FADF8_BumperBallMaze + 5, state->unk_1E);
        D_800FADF6_BumperBallMaze = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F94A0_BumperBallMaze);

void func_800F9610_BumperBallMaze(s32 player) {
    u16 remaining = 0xE10 - func_800F9278_BumperBallMaze();
    u16 q = remaining / 60;
    u16 reward = q;

    if ((u16) (remaining % 60) != 0) {
        reward = q + 1;
    }
    GwPlayer[(u16) player].coins_mg += reward + 10;
}
