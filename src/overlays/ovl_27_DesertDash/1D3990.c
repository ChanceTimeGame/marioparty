#include "common.h"
#include "DesertDash.h"

/* .data (0x800FC000..0x800FC030) */
s32 D_800FC000_DesertDash = 0;
s32 D_800FC004_DesertDash = 1;
s32 D_800FC008_DesertDash = 0;
s32 D_800FC00C_DesertDash = 1;
s32 D_800FC010_DesertDash = 0; /* unreferenced */
s32 D_800FC014_DesertDash = 210;
s32 D_800FC018_DesertDash = 9000;
s32 D_800FC01C_DesertDash = 0;
u8 D_800FC020_DesertDash = 0;

void func_800F65E0_DesertDash(void) {
    s16 i;
    s16 j;
    s32 slot;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    D_800FC2FC_DesertDash = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    omSetStatBit(D_800FC2FC_DesertDash, 0xA0);
    D_800FC2FC_DesertDash->work[0] = 2;
    func_80017940(2);
    func_800179C0(2);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80017660(1, 320.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    func_8001D494(1, 45.0f, 80.0f, 8000.0f);
    D_800FC3B0_DesertDash = 0;
    D_800FC3B2_DesertDash = 3600;
    D_800ED430 = 1;
    D_800FC3D4_DesertDash = _CheckFlag(0x2B);
    D_800FC3D0_DesertDash = 0;
    for (i = 0; i < 4; i++) {
        D_800FC308_DesertDash[i] = 0;
    }
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800090B8(0);
    D_800FC2F8_DesertDash = omAddObj(1, 0, 0, -1, func_800F6A9C_DesertDash);
    D_800F2AF8[D_800ED440++] = omAddObj(2, 0, 0, -1, func_800F9A80_DesertDash);
    omAddObj(2, 0, 0, -1, func_800F6B38_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6E34_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6E68_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6E9C_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6ED0_DesertDash);
    for (i = 0; i < 4; i++) {
        D_800FC3C0_DesertDash[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        slot = GwPlayer[i].group * 2 + (rand8() & 1);
        for (j = 0; j < 4; j++) {
            if (D_800FC3C0_DesertDash[j] == slot) {
                slot ^= 1;
            }
        }
        D_800FC3C0_DesertDash[i] = slot;
    }
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6A9C_DesertDash(omObjData* obj) {
    obj->func_ptr = func_800F7430_DesertDash;
    func_800F94F8_DesertDash(0, 415.0f, 0.0f, 500.0f, -6900.0f, 17.25f, 0.0f, 0.0f);
    func_800F94F8_DesertDash(1, 415.0f, 0.0f, 500.0f, -6900.0f, 17.25f, 0.0f, 0.0f);
}

void func_800F6B38_DesertDash(omObjData* obj) {
    u8 files[2];
    s32 anim0;
    s32 anim1;
    s32 i;
    void* data;
    DDTeam* team;

    files[0] = 7;
    files[1] = 8;
    obj->func_ptr = func_800F7C6C_DesertDash;
    data = DataRead(0x3B000D);
    anim0 = (s16)func_800678A4(data);
    DataClose(data);
    D_800FC3B4_DesertDash = func_80064EF4(2, 0);
    data = DataRead(0x3B000F);
    anim1 = (s16)func_800678A4(data);
    DataClose(data);
    D_800FC3B8_DesertDash = func_80064EF4(2, 0);
    for (i = 0; i < 2; i++) {
        team = &D_800FC318_DesertDash[i];
        team->unk14 = 0;
        team->unk18 = 0;
        team->unk8 = 0;
        team->unkE = func_800174C0(files[i] | 0x3B0000, 0x2D9);
        team->unk10 = func_80023FC8(team->unkE);
        team->unk12 = func_800174F4(0x3B0009, 0x2D9);
        func_80067208((s16)D_800FC3B4_DesertDash, i, anim0, 0);
        func_800672B0((s16)D_800FC3B4_DesertDash, i, 0);
        func_800674BC((s16)D_800FC3B4_DesertDash, i, 0x9800);
        func_80067208((s16)D_800FC3B8_DesertDash, i, anim1, 0);
        func_800672B0((s16)D_800FC3B8_DesertDash, i, 0);
        func_800674BC((s16)D_800FC3B8_DesertDash, i, 0x9000);
        func_80067558((s16)D_800FC3B8_DesertDash, (s16)i, 200, 0, 0, 0x100);
        func_80067354((s16)D_800FC3B8_DesertDash, i, 1.2f, 1.2f);
    }
    func_80025798(D_800FC318_DesertDash[0].unkE, -75.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[0].unk10, -125.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[1].unkE, 125.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[1].unk10, 75.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[0].unk12, -100.0f, 16.0f, 0.0f);
    func_800257E4(D_800FC318_DesertDash[0].unk12, 0.0f, 180.0f, 0.0f);
    func_80025798(D_800FC318_DesertDash[1].unk12, 100.0f, 16.0f, 0.0f);
    func_800257E4(D_800FC318_DesertDash[1].unk12, 0.0f, 180.0f, 0.0f);
}

void func_800F6E00_DesertDash(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F9434_DesertDash();
        omOvlReturnEx(1);
    }
}

void func_800F6E34_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 0);
    func_800F707C_DesertDash(obj, 0);
}

void func_800F6E68_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 1);
    func_800F707C_DesertDash(obj, 1);
}

void func_800F6E9C_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 2);
    func_800F707C_DesertDash(obj, 2);
}

void func_800F6ED0_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 3);
    func_800F707C_DesertDash(obj, 3);
}

/* Puts the player into its team slot (D_800FC3C0) and at its start position. */
void func_800F6F04_DesertDash(omObjData* obj, s32 player) {
    s32 member;
    s32 t;
    DDTeam* team;

    member = D_800FC3C0_DesertDash[player];
    t = member >> 1;
    member &= 1;
    team = &D_800FC318_DesertDash[t];
    func_800F9450_DesertDash(obj, team);
    team->obj[member] = obj;
    D_800FC318_DesertDash[t].player[member] = player;
    D_800FC318_DesertDash[t].unkB[member] = (u8)D_800C59A8[GwPlayer[player].character].index;
    switch (D_800FC3C0_DesertDash[player]) {
        case 0:
            func_800093FC(obj, -100.0f, 0.0f, 0.0f);
            break;
        case 1:
            func_800093FC(obj, -100.0f, 0.0f, 150.0f);
            break;
        case 2:
            func_800093FC(obj, 100.0f, 0.0f, 0.0f);
            break;
        case 3:
            func_800093FC(obj, 100.0f, 0.0f, 150.0f);
            break;
    }
}

void func_800F707C_DesertDash(omObjData* obj, s32 player) {
    s32 idle[5] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
    s32 win[5] = { 0x10, 0x3C, 0x3D, 0x3E, 0x3F };
    s32 dir;
    s32 file0;
    s32 file1;
    u8 chr;
    DDPlayerWork* work;

    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    file0 = D_800C59AC[chr].unk_04;
    file1 = D_800C59AC[chr].unk_08;
    obj->model[0] = LoadFormFile(dir | file0, 0x2D9);
    func_80025F10(obj->model[0], 1);
    obj->func_ptr = func_800F8C34_DesertDash;
    obj->rot.x = 0.0f;
    obj->rot.y = 180.0f;
    obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->unk_50 = func_80023684(sizeof(DDPlayerWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(DDPlayerWork));
    work = obj->unk_50;
    work->unk_D8 = func_80023684(obj->mtncnt * sizeof(DDPlayerWork), 0x7918);
    func_8009B770(work->unk_D8, 0, obj->mtncnt * sizeof(DDPlayerWork));
    work->unk_56 = GwPlayer[player].port;
    work->unk_58 = player;
    work->unk_C0 = 0xFFFF;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    obj->model[7] = LoadFormFile(0x1E, 0x68D);
    obj->model[8] = LoadFormFile(0x1D, 0x68D);
    func_80025830(obj->model[8], 1.0f, 1.0f, 2.0f);
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 0x5A, 0, 0);
    func_8001874C(obj, 2, dir | 0x5B, 0, 0);
    func_8001874C(obj, 5, dir | 0xA, 1, 0x27);
    func_8001874C(obj, 6, dir | 0x1E, 1, 0x27);
    func_8001874C(obj, 7, dir | 0x68, 2, 0);
    func_8001874C(obj, 8, dir | 0x69, 2, 0);
    func_8001874C(obj, 3, dir | idle[rand8() & 1], 1, 0x78);
    func_8001874C(obj, 4, dir | win[0], 1, 0x78);
    func_80008EF0(obj, 9, dir | file1, 0x2D9, 623.33f);
    func_800184BC(obj, 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F7430_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F7C6C_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F8A80_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F8C34_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F91C8_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F9434_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F9450_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F9470_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F949C_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F94F8_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F95E8_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F96C4_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F9780_DesertDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F983C_DesertDash);
