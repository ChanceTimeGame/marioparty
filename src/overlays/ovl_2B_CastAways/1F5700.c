#include "CastAways.h"

typedef struct CastAwaysLureWork {
    char unk_00[8];
    f32 unk_08;
} CastAwaysLureWork;

typedef struct CastAwaysSpriteData {
    s16 model;
    s8 unk_02;
    s8 unk_03;
    s8 unk_04;
    char unk_05[3];
    void* buffersA[8];
    void* buffersB[8];
} CastAwaysSpriteData;

typedef struct CastAwaysPlayerWork {
    char unk_00[0x34];
    CastAwaysSpriteData* spriteData;
    char unk_38[0xFC];
    void* animDataA;
    void* animDataB;
    omObjData* lureObj;
    s16 unk_140;
} CastAwaysPlayerWork;

typedef struct CastAwaysCameraView {
    f32 rot;
    f32 x;
    f32 z;
    f32 fov;
    f32 far;
    f32 near;
} CastAwaysCameraView;

typedef struct CastAwaysCameraViewFromX {
    f32 x;
    f32 z;
    f32 fov;
    f32 far;
    f32 near;
} CastAwaysCameraViewFromX;

void func_80023888(void*);
void func_80020CC4(void*);
extern CastAwaysCameraView D_800EE738;
extern CastAwaysCameraViewFromX D_800EE73C;

void func_800FAF40_CastAways(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    func_800178A0(1);
    CZoom = arg1;
    CRot.x = arg2;
    CRot.y = arg3;
    CRot.z = arg4;
    Center.x = arg5;
    Center.y = arg6;
    Center.z = arg7;
    D_800C3110->unk_40 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FAFF0_CastAways);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB0C8_CastAways);

void func_800FB374_CastAways(CastAwaysSpriteData* arg0) {
    s16 i = 0;

    func_8002456C(arg0->model);
    if (D_800F37DA != 0) {
        do {
            func_80023888(arg0->buffersA[i]);
            func_80023888(arg0->buffersB[i]);
            i++;
        } while (i < D_800F37DA);
    }
    func_80023888(arg0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB404_CastAways);

s32 func_800FB4D4_CastAways(f32 arg0, f32 arg1, f32 arg2, u16 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_f0, temp_f2, temp_f12;
    f32 temp = 18.0f;
    
    temp_f2 = D_800FBA30_CastAways[arg3];
    temp_f12 = (arg0 - arg4) * (arg0 - arg4);
    temp_f0 = (arg2 - arg6) * (arg2 - arg6);
    
    if ( (temp_f12 + temp_f0) <= ((temp_f2 + temp) * (temp_f2 + temp))) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_800FB53C_CastAways(f32 arg0, f32 arg1, f32 arg2, u16 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_f0, temp_f2, temp_f12;
    f32 temp = 18.0f;
    
    temp_f2 = D_800FBA30_CastAways[arg3] - 6.0f;
    temp_f12 = (arg0 - arg4) * (arg0 - arg4);
    temp_f0 = (arg2 - arg6) * (arg2 - arg6);
    
    if ( (temp_f12 + temp_f0) <= ((temp_f2 + temp) * (temp_f2 + temp))) {
        return 1;
    } else {
        return 0;
    }
}

void func_800FB5B4_CastAways(s32 arg0) {
    omObjData** players = func_8005DB44(4);
    s32 i = 0;

    do {
        CastAwaysPlayerWork* work = players[i]->unk_50;

        func_800FB374_CastAways(work->spriteData);
        if (work->animDataA != NULL) {
            func_80020CC4(work->animDataA);
        }
        if (work->animDataB != NULL) {
            func_80020CC4(work->animDataB);
        }
        i++;
    } while (i < 4);
    omOvlReturnEx(1);
}

void func_800FB644_CastAways(u16 arg0, f32 arg1) {
    D_800F2B7C[arg0].unk_4C = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB668_CastAways);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB778_CastAways);

f32 func_800FB858_CastAways(omObjData* arg0) {
    omObjData* lureObj = ((CastAwaysPlayerWork*)arg0->unk_50)->lureObj;
    f32 result;

    if (lureObj != NULL) {
        result = ((CastAwaysLureWork*)lureObj->unk_50)->unk_08;
    } else {
        result = -1.0f;
    }
    return result;
}

void func_800FB884_CastAways(void) {
#ifdef TARGET_PC
    f32* view = &D_800EE738.x;

    view[0] = 0.0f;
    view[1] = 900.0f;
    view[-1] = 0.0f;
    D_800C3110->unk_40 = 45.0f;
    view[2] = 45.0f;
    view[3] = 20000.0f;
    view[4] = 10000.0f;
#else
    D_800EE73C.x = 0.0f;
    D_800EE73C.z = 900.0f;
    ((f32*)&D_800EE73C)[-1] = 0.0f;
    D_800C3110->unk_40 = 45.0f;
    D_800EE73C.fov = 45.0f;
    D_800EE73C.far = 20000.0f;
    D_800EE73C.near = 10000.0f;
#endif
    func_8001D420(0, &D_800FBB80_ovl2B, &D_800FBB70_ovl2B, D_800FBB9C_ovl2B);
    func_8001D57C(0);
}
