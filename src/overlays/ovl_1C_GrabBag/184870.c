#include "GrabBag.h"

extern s32 D_800FB104_GrabBag[4];
extern s32 D_800FB254_GrabBag;
extern f32 D_800B8960;
extern f32 D_800B8984;
extern u8 D_800F64F8;
extern u16 D_800FB11C_GrabBag[4];
extern u16 D_800FB244_GrabBag[4];
extern u16 D_800FB258_GrabBag[];
extern u16 D_800FB25A_GrabBag[];
extern u16 D_800FB25C_GrabBag[];
extern u8 D_800FB270_GrabBag[];
extern u8 D_800FB278_GrabBag[];
extern omObjData* D_800FB280_GrabBag;
extern u16 ContBtn[4];

void func_800F776C_GrabBag(omObjData*);
void func_800F859C_GrabBag(omObjData*);
void func_800F8984_GrabBag(void);
void func_800F8A18_GrabBag(omObjData*);
void func_800F8BDC_GrabBag(void);
void func_800F903C_GrabBag(omObjData*);
void func_800FA424_GrabBag(void);
void func_800FAED8_GrabBag(void);
void func_800FAFA0_GrabBag(void);
void func_800FA8F4_GrabBag(omObjData*);
void func_800FB064_GrabBag(s32, s32);

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

void func_800F8484_GrabBag(omObjData* arg0) {
    GrabBagPlayerWork* work;

    work = arg0->unk_50;
    func_800FA424_GrabBag();
    if (func_8005FD5C() + D_800F64F8 == 0) {
        if (D_800ED430 == 0) {
            func_800FAFA0_GrabBag();
            func_800F859C_GrabBag(arg0);
            return;
        }
        if ((u32)(D_800ED430 - 2) < 2U) {
            func_800FAFA0_GrabBag();
            func_800F8984_GrabBag();
            if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
                func_800F8A18_GrabBag(arg0);
            }
            work->speed = 0.0f;
            func_80005A28(arg0);
            return;
        }
        if (D_800ED430 == 1) {
            func_800FB064_GrabBag(work->player, work->score);
            func_800FAED8_GrabBag();
            func_800F903C_GrabBag(arg0);
            if (work->port == 3) {
                func_800F8BDC_GrabBag();
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F859C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8984_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8A18_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F8BDC_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F903C_GrabBag);

void func_800F975C_GrabBag(GrabBagPlayerWork* arg0, s32 arg1) {
    s32 first_offset;
    s32 second_offset;
    s32 pad[6];

    first_offset = arg0->port * 2;
    *(u16*)((u8*)D_800FB244_GrabBag + first_offset) =
        *(u16*)((u8*)ContBtn + first_offset) & ~*(u16*)((u8*)D_800FB11C_GrabBag + first_offset);
    second_offset = arg0->port * 2;
    *(u16*)((u8*)D_800FB11C_GrabBag + second_offset) = *(u16*)((u8*)ContBtn + second_offset);
    if (*(u16*)((u8*)D_800FB244_GrabBag + (arg0->port * 2)) & arg1) {
        arg0->button_press_count++;
    }
}

void func_800F97E8_GrabBag(omObjData* arg0, omObjData* arg1) {
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f0;
    GrabBagPlayerWork* work;

    work = arg0->unk_50;
    temp_f20 = work->radius + work->radius_offset;
    temp_f22 = (func_800AEAC0(work->angle) * temp_f20) + arg0->trans.x;
    temp_f24 = arg0->trans.y;
    temp_f0 = (func_800AEFD0(work->angle) * temp_f20) + arg0->trans.z;
    temp_f12 = arg1->trans.x - temp_f22;
    temp_f2 = arg1->trans.y - temp_f24;
    temp_f4 = arg1->trans.z - temp_f0;
    func_800B1750((temp_f12 * temp_f12) + (temp_f2 * temp_f2) + (temp_f4 * temp_f4));
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F98A4_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9A1C_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9BC4_GrabBag);

void func_800F9DF0_GrabBag(omObjData* arg0, omObjData* arg1) {
    f32 dx;
    f32 dz;
    f32 base_z;
    f32 distance_sq;
    f32 threshold_sq;
    GrabBagPlayerWork* work0;
    GrabBagPlayerWork* work1;

    work0 = arg0->unk_50;
    work1 = arg1->unk_50;
    func_800AEAC0(work1->angle);
    func_800AEFD0(work1->angle);
    base_z = arg0->trans.z;
    dx = arg1->trans.x - arg0->trans.x;
    dz = arg1->trans.z - base_z;
    distance_sq = (dx * dx) + (dz * dz);
    threshold_sq = D_800B8984 * D_800B8984;
    if (threshold_sq < distance_sq) {
        work1->angle = func_800B0CD8(dx, dz);
        work1->speed = -D_800B8984;
    }
    work1->unk_38 = 1000.0f;
    work0->unk_38 = 1000.0f;
    func_80025798(arg1->model[0], arg1->trans.x, 3.0f, arg1->trans.z);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800F9ED0_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA184_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA304_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA424_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA658_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA780_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FA8F4_GrabBag);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", func_800FAC0C_GrabBag);

void func_800FAED8_GrabBag(void) {
    s32 sprite_offset;
    PB_PTR32 player_offset;
    s32 i;
    u16 sprite;
    u8* fourth_sprites;
    u8* fifth_sprites;

    D_800FB280_GrabBag->work[1] = 1;
    i = 0;
    fourth_sprites = D_800FB270_GrabBag;
    fifth_sprites = D_800FB278_GrabBag;
    for (; i < 4; i++) {
        player_offset = i << 1;
        sprite_offset = (player_offset + i) * 2;
        sprite = *(u16*)((u8*)D_800FB258_GrabBag + sprite_offset);
        ShowBasicSprite(sprite);
        ShowBasicSprite(*(u16*)((u8*)D_800FB25A_GrabBag + sprite_offset));
        ShowBasicSprite(*(u16*)((u8*)D_800FB25C_GrabBag + sprite_offset));
        ShowBasicSprite(*(u16*)(player_offset + (PB_PTR32)fourth_sprites));
        player_offset += (PB_PTR32)fifth_sprites;
        ShowBasicSprite(*(u16*)player_offset);
    }
}

void func_800FAFA0_GrabBag(void) {
    s32 sprite_offset;
    PB_PTR32 player_offset;
    s32 i;
    u16 sprite;
    u8* fourth_sprites;
    u8* fifth_sprites;

    D_800FB280_GrabBag->work[1] = 0;
    i = 0;
    fourth_sprites = D_800FB270_GrabBag;
    fifth_sprites = D_800FB278_GrabBag;
    for (; i < 4; i++) {
        player_offset = i << 1;
        sprite_offset = (player_offset + i) * 2;
        sprite = *(u16*)((u8*)D_800FB258_GrabBag + sprite_offset);
        func_80018C90(sprite);
        func_80018C90(*(u16*)((u8*)D_800FB25A_GrabBag + sprite_offset));
        func_80018C90(*(u16*)((u8*)D_800FB25C_GrabBag + sprite_offset));
        func_80018C90(*(u16*)(player_offset + (PB_PTR32)fourth_sprites));
        player_offset += (PB_PTR32)fifth_sprites;
        func_80018C90(*(u16*)player_offset);
    }
}

void func_800FB064_GrabBag(s32 arg0, s32 arg1) {
    arg1 = arg1 < 0 ? 0 : arg1;
    if (arg1 >= 1000) {
        arg1 = 999;
    }
    D_800FB104_GrabBag[arg0] = arg1;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", D_800FB1F8_GrabBag);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_1C_GrabBag/184870", D_800FB208_GrabBag);
