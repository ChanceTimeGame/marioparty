#include "common.h"

extern omObjData* D_800F2AF8[];

void func_800F738C_GrabBag(omObjData*);
void func_800F7470_GrabBag(omObjData*);

void func_800F7260_GrabBag(void) {
    omObjData* obj;
    u16 index;

    D_800ED440 = 0;
    func_800090B8(0);
    obj = omAddObj(1, 3, 0, -1, func_800F738C_GrabBag);
    index = D_800ED440;
    D_800ED440 = index + 1;
    D_800F2AF8[index] = obj;
    omAddObj(1, 2, 0, -1, func_800F7470_GrabBag);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184450", func_800F72E8_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184450", func_800F738C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184450", func_800F7470_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184450", func_800F7538_GrabBag);
