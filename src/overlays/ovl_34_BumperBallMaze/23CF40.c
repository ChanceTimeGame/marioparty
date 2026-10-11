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

extern omObjData* D_800FAE10_BumperBallMaze;
extern omObjData* D_800FAE14_BumperBallMaze;
extern u16 D_800FACC0_BumperBallMaze;
extern s16 D_800FADF6_BumperBallMaze;
extern u16 D_800FADF8_BumperBallMaze;
extern s32 D_800FAB00_BumperBallMaze[];

void func_800FA620_BumperBallMaze(void);
void func_800F9990_BumperBallMaze(void);
void func_800F6C28_BumperBallMaze(void);
void func_800F9974_BumperBallMaze(s32);
void func_800F6C7C_BumperBallMaze(s32);
s32 func_800F8E1C_BumperBallMaze(BumperBallMazeHitProbe*, u16*, BumperBallMazeColVtx*);
void func_800F928C_BumperBallMaze(u16);
void func_800594E4(s16, u16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F65E0_BumperBallMaze);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F6994_BumperBallMaze);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F7ED0_BumperBallMaze);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F8184_BumperBallMaze);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F9610_BumperBallMaze);
