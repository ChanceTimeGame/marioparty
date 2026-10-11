#include "common.h"

extern s16 D_800F3778;
extern omObjData* D_800FB1C8_BumperBallMaze;

typedef struct BumperBallMazeCameraWork {
    u16 frames;
    u16 pad_02;
    f32 zoomStep;
    Vec3f rotStep;
    Vec3f centerStep;
} BumperBallMazeCameraWork;

void func_800F9890_BumperBallMaze(omObjData*);

void func_800F96B0_BumperBallMaze(f32 cameraValue, f32 zoom, f32 rotX, f32 rotY, f32 rotZ,
                                 f32 centerX, f32 centerY, f32 centerZ) {
    func_800178A0(1);
    func_800178E8();
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = centerX;
    Center.y = centerY;
    Center.z = centerZ;
    D_800C3110->unk_40 = cameraValue;
}

void func_800F9768_BumperBallMaze(void) {
    D_800FB1C8_BumperBallMaze = omAddObj(0x3C, 0, 0, -1, NULL);
    D_800FB1C8_BumperBallMaze->unk_50 = func_80023684(0x20, 0x7918);
}

void func_800F97B4_BumperBallMaze(s16 frames, f32 zoom, f32 rotX, f32 rotY, f32 rotZ,
                                 f32 centerX, f32 centerY, f32 centerZ) {
    BumperBallMazeCameraWork* work = D_800FB1C8_BumperBallMaze->unk_50;
    f32 duration;

    work->frames = frames;
    work->zoomStep = (zoom - CZoom) / (duration = (u16) frames);
    work->rotStep.x = (rotX - CRot.x) / duration;
    work->rotStep.y = (rotY - CRot.y) / duration;
    work->rotStep.z = (rotZ - CRot.z) / duration;
    work->centerStep.x = (centerX - Center.x) / duration;
    work->centerStep.y = (centerY - Center.y) / duration;
    work->centerStep.z = (centerZ - Center.z) / duration;
    D_800FB1C8_BumperBallMaze->func_ptr = func_800F9890_BumperBallMaze;
}

void func_800F9890_BumperBallMaze(omObjData* object) {
    BumperBallMazeCameraWork* work = object->unk_50;

    CZoom += work->zoomStep;
    CRot.x += work->rotStep.x;
    CRot.y += work->rotStep.y;
    CRot.z += work->rotStep.z;
    Center.x += work->centerStep.x;
    Center.y += work->centerStep.y;
    Center.z += work->centerStep.z;
    if (--work->frames == 0) {
        object->func_ptr = NULL;
    }
}

void func_800F993C_BumperBallMaze(void) {
    s32 i;

    for (i = 0; i < D_800F3778; i++) {
    }
}

void func_800F9974_BumperBallMaze(s32 arg0) {
    omOvlReturnEx(1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/240010", func_800F9990_BumperBallMaze);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/240010", func_800FA010_BumperBallMaze);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/240010", func_800FA620_BumperBallMaze);
