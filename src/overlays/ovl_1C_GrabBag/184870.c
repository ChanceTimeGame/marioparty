#include "common.h"

extern s32 D_800FB104_GrabBag[4];
extern s32 D_800FB254_GrabBag;
extern f32 D_800B8960;
extern u16 D_800FB11C_GrabBag[4];
extern u16 D_800FB244_GrabBag[4];
extern u16 ContBtn[4];

typedef struct GrabBagInputWork {
    char unk_00[0x56];
    s8 player_index;
    char unk_57[0x97];
    u8 button_press_count;
} GrabBagInputWork;

void func_800F776C_GrabBag(omObjData*);
void func_800FA8F4_GrabBag(omObjData*);

void func_800F7680_GrabBag(void) {
    omObjData* obj;
    s32 i;
    u16 index;

    D_800FB254_GrabBag = rand8() & 3;
    i = 0;
    func_80009500();
    D_800B8960 = 0.2f;
    D_800F2BC0 = 0;
    do {
        obj = omAddObj(2, 11, 50, -1, func_800F776C_GrabBag);
        index = D_800F2BC0;
        D_800F2BC0 = index + 1;
        D_800F3FB0[index] = obj;
        omSetStatBit(D_800F3FB0[i], 0xA0);
        i++;
    } while (i < 4);
    omAddObj(2, 0, 0, -1, func_800FA8F4_GrabBag);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F776C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F7EDC_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8484_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F859C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8984_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8A18_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8BDC_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F903C_GrabBag);

void func_800F975C_GrabBag(GrabBagInputWork* arg0, s32 arg1) {
    s32 first_offset;
    s32 second_offset;
    s32 pad[6];

    first_offset = arg0->player_index * 2;
    *(u16*)((u8*)D_800FB244_GrabBag + first_offset) =
        *(u16*)((u8*)ContBtn + first_offset) & ~*(u16*)((u8*)D_800FB11C_GrabBag + first_offset);
    second_offset = arg0->player_index * 2;
    *(u16*)((u8*)D_800FB11C_GrabBag + second_offset) = *(u16*)((u8*)ContBtn + second_offset);
    if (*(u16*)((u8*)D_800FB244_GrabBag + (arg0->player_index * 2)) & arg1) {
        arg0->button_press_count++;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F97E8_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F98A4_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9A1C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9BC4_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9DF0_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9ED0_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA184_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA304_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA424_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA658_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA780_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA8F4_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FAC0C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FAED8_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FAFA0_GrabBag);

void func_800FB064_GrabBag(s32 arg0, s32 arg1) {
    arg1 = arg1 < 0 ? 0 : arg1;
    if (arg1 >= 1000) {
        arg1 = 999;
    }
    D_800FB104_GrabBag[arg0] = arg1;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", D_800FB1F8_GrabBag);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", D_800FB208_GrabBag);
