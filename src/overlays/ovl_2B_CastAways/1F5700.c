#include "CastAways.h"

typedef struct CastAwaysPlayerWork {
    char unk_00[0x13C];
    omObjData* unk_13C;
} CastAwaysPlayerWork;

typedef struct CastAwaysLureWork {
    char unk_00[8];
    f32 unk_08;
} CastAwaysLureWork;

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB374_CastAways);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB5B4_CastAways);

void func_800FB644_CastAways(u16 arg0, f32 arg1) {
    D_800F2B7C[arg0].unk_4C = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB668_CastAways);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB778_CastAways);

f32 func_800FB858_CastAways(omObjData* arg0) {
    omObjData* lureObj = ((CastAwaysPlayerWork*)arg0->unk_50)->unk_13C;
    f32 result;

    if (lureObj != NULL) {
        result = ((CastAwaysLureWork*)lureObj->unk_50)->unk_08;
    } else {
        result = -1.0f;
    }
    return result;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F5700", func_800FB884_CastAways);
