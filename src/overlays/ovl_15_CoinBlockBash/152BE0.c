#include "CoinBlockBash.h"

void func_800F65E0_CoinBlockBash(void) {
    D_801024F8_CoinBlockBash = _CheckFlag(0x2B) != 0;
    func_80029090(50);
    omInitObjMan(50, 0);
    func_80060088();
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800F6CC8_CoinBlockBash();
    D_801024F0_CoinBlockBash.state = 0;
    D_801024F0_CoinBlockBash.timer = 0;
    D_801024F0_CoinBlockBash.unk_02 = 0;
    D_801024F0_CoinBlockBash.time = 1800;
    D_801025AC_CoinBlockBash = -1;
    func_800FAA7C_CoinBlockBash();
    func_800FDC5C_CoinBlockBash();
    func_800F78E8_CoinBlockBash();
    func_800FE650_CoinBlockBash();
    D_800F2AF8[D_800ED440++] = omAddObj(0x14, 0, 0, -1, func_800F66F8_CoinBlockBash);
}
void func_800F66F8_CoinBlockBash(omObjData* obj) {
    s32 i;

    func_800F8CD0_CoinBlockBash();
    for (i = 0; i < 9; i++) {
        D_8010320E_CoinBlockBash[i] = 0;
    }
    obj->func_ptr = func_800F6770_CoinBlockBash;
    omSetStatBit(obj, 0xA0);
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
    func_8007B168((u8*)"\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58", 0);
}


void func_800F6770_CoinBlockBash(omObjData* obj) {
    s32 i;
    s32 mask;
    s16 msg;
    s32 wait;

    if (func_8005FD5C() + D_800F64F8 != 0) {
        func_800F8014_CoinBlockBash();
        return;
    }
    switch (D_801024F0_CoinBlockBash.state) {
    case 0:
        if (D_801024F0_CoinBlockBash.timer == 2) {
            SetFadeInTypeAndTime(0, 16);
        } else if (D_801024F0_CoinBlockBash.timer == 0x56) {
            GMesCreate(0);
        } else if (D_801024F0_CoinBlockBash.timer == 0x28) {
            func_80060128(0x1B);
        } else if (D_801024F0_CoinBlockBash.timer == 0x8E) {
            GMesCreate(8, D_801024F0_CoinBlockBash.time / 30, 0xA0, 0x20);
            D_801024F0_CoinBlockBash.state = 1;
            D_801024F0_CoinBlockBash.timer = -1;
        }
        if (D_801024F0_CoinBlockBash.timer >= 0x3D) {
            D_80102534_CoinBlockBash += 0.03;
            if (D_80102534_CoinBlockBash > 1.0) {
                D_80102534_CoinBlockBash = 1.0f;
            }
        }
        func_800F6EA0_CoinBlockBash();
        break;
    case 1:
        D_801024F0_CoinBlockBash.time--;
        if ((func_800FFD60_CoinBlockBash() == 0 && func_800FFD6C_CoinBlockBash() == 0) ||
            D_801024F0_CoinBlockBash.time <= 0) {
            D_801024F0_CoinBlockBash.state = 2;
            D_801024F0_CoinBlockBash.timer = -1;
            msg = 0x10;
            if (D_801024F0_CoinBlockBash.time != 0) {
                msg = 2;
            }
            GMesCreate(msg);
            func_800601D4(0x5A);
            func_800790C0();
        }
        func_80079078((D_801024F0_CoinBlockBash.time + 29) / 30);
        func_800F99A0_CoinBlockBash();
        func_800F9A98_CoinBlockBash();
        func_800F9FE4_CoinBlockBash();
        break;
    case 2:
        if (GMesStatAllGet() == 2) {
            D_801024F0_CoinBlockBash.timer = 500;
        }
        if (D_801024F0_CoinBlockBash.timer >= 500) {
            mask = 0;
            for (i = 0; i < D_801031FC_CoinBlockBash; i++) {
                if (D_801025B0_CoinBlockBash[i].state != 0xF) {
                    break;
                }
                mask |= D_801025B0_CoinBlockBash[i].unk_62;
            }
            if (i >= D_801031FC_CoinBlockBash) {
                if (D_801024F8_CoinBlockBash == 0) {
                    if (mask == 0) {
                        func_80060128(0x34);
                    } else {
                        func_80060128(D_801024F0_CoinBlockBash.time != 0 ? 0x36 : 0x3C);
                    }
                }
                D_801024F0_CoinBlockBash.state = 3;
                D_801024F0_CoinBlockBash.timer = -1;
                func_800FFBA8_CoinBlockBash();
            }
        }
        break;
    case 3:
        if (D_801024F8_CoinBlockBash != 0) {
            wait = GMesWait() != 0 ? 0x3C : 0;
        } else {
            wait = D_801024F0_CoinBlockBash.time != 0 ? 0x69 : 0x78;
        }
        if (D_801024F0_CoinBlockBash.timer >= wait) {
            if (D_801024F8_CoinBlockBash == 0) {
                func_800601D4(0x28);
            }
            if (D_801024F8_CoinBlockBash != 0) {
                func_80060398(0x28);
            }
            func_800726AC(0, 0x14);
            obj->func_ptr = func_800F6C20_CoinBlockBash;
            return;
        }
        break;
    }
    if (++D_801024F0_CoinBlockBash.timer >= 0x7800) {
        D_801024F0_CoinBlockBash.timer -= 0x800;
    }
    func_800FEE04_CoinBlockBash();
    func_800F7A5C_CoinBlockBash();
    func_800F8014_CoinBlockBash();
    func_800F8D98_CoinBlockBash();
    if (D_800F5144 == 1) {
        func_800F6C54_CoinBlockBash();
        omOvlReturnEx(1);
    }
}
void func_800F6C20_CoinBlockBash(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F6C54_CoinBlockBash();
        omOvlReturnEx(1);
    }
}
void func_800F6C54_CoinBlockBash(void) {
    func_800FB490_CoinBlockBash();
    func_80060198();
    func_800FFE30_CoinBlockBash();
}
s16 func_800F6C80_CoinBlockBash(s32 id) {
    void* file;
    s16 sprite;

    file = DataRead(id);
    sprite = func_800678A4(file);
    DataClose(file);
    return sprite;
}
void func_800F6CC8_CoinBlockBash(void) {
    u8 cam;

    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 20.0f, 80.0f, 4500.0f);
    Center.x = -65.0f;
    Center.y = -100.0f;
    Center.z = -75.0f;
    CRot.x = -42.0f;
    CRot.y = 29.0f;
    CRot.z = 0.0f;
    CZoom = 3650.0f;
    D_801024FC_CoinBlockBash.x = D_80102508_CoinBlockBash.x = Center.x;
    D_801024FC_CoinBlockBash.y = D_80102508_CoinBlockBash.y = Center.y;
    D_801024FC_CoinBlockBash.z = D_80102508_CoinBlockBash.z = Center.z;
    D_80102514_CoinBlockBash.x = D_80102520_CoinBlockBash.x = CRot.x;
    D_80102514_CoinBlockBash.y = D_80102520_CoinBlockBash.y = CRot.y;
    D_80102514_CoinBlockBash.z = D_80102520_CoinBlockBash.z = CRot.z;
    D_8010252C_CoinBlockBash = D_80102530_CoinBlockBash = CZoom;
    D_80102534_CoinBlockBash = CRot.z;
    func_800234B8(0, 100, 100, 100);
    func_800234B8(1, 255, 255, 255);
    func_80023504(1, 200.0f, 200.0f, 500.0f);
}
void func_800F6EA0_CoinBlockBash(void) {
    f32 k;
    f32 near;

    Center.x = (D_80102508_CoinBlockBash.x - D_801024FC_CoinBlockBash.x) * D_80102534_CoinBlockBash + D_801024FC_CoinBlockBash.x;
    Center.y = (D_80102508_CoinBlockBash.y - D_801024FC_CoinBlockBash.y) * D_80102534_CoinBlockBash + D_801024FC_CoinBlockBash.y;
    Center.z = (D_80102508_CoinBlockBash.z - D_801024FC_CoinBlockBash.z) * D_80102534_CoinBlockBash + D_801024FC_CoinBlockBash.z;
    CRot.x = (D_80102520_CoinBlockBash.x - D_80102514_CoinBlockBash.x) * D_80102534_CoinBlockBash + D_80102514_CoinBlockBash.x;
    CRot.y = (D_80102520_CoinBlockBash.y - D_80102514_CoinBlockBash.y) * D_80102534_CoinBlockBash + D_80102514_CoinBlockBash.y;
    CRot.z = (D_80102520_CoinBlockBash.z - D_80102514_CoinBlockBash.z) * D_80102534_CoinBlockBash + D_80102514_CoinBlockBash.z;
    CZoom = (D_80102530_CoinBlockBash - D_8010252C_CoinBlockBash) * D_80102534_CoinBlockBash + D_8010252C_CoinBlockBash;
    k = 2.0 - D_80102534_CoinBlockBash;
    near = CZoom - k * 10.0 * 100.0;
    if (near < 80.0) {
        near = 80.0f;
    }
    func_8001D494(0, 20.0f, near, CZoom + k * 8.0 * 100.0);
}

const CBBQuad D_80101D18_CoinBlockBash = { { 29.0f, 0.0f, 90.0f, 29.0f } };

void func_800F7048_CoinBlockBash(omObjData* obj) {
    CBBQuad rot = D_80101D18_CoinBlockBash;
    s32 i;

    i = 1;
    if (!(obj->trans.x > 0.0)) {
        i = 0;
    }
    if (obj->trans.z > 0.0) {
        i |= 2;
    }
    D_801024FC_CoinBlockBash.x = obj->trans.x;
    D_801024FC_CoinBlockBash.y = obj->trans.y + 100.0;
    D_801024FC_CoinBlockBash.z = obj->trans.z;
    D_80102514_CoinBlockBash.x = -5.0f;
    D_80102514_CoinBlockBash.y = rot.v[i];
    D_8010252C_CoinBlockBash = 800.0f;
    D_80102534_CoinBlockBash = 0.0f;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F7148_CoinBlockBash);

CBBPlayer* func_800F7644_CoinBlockBash(omObjData* obj) {
    return &D_801025B0_CoinBlockBash[obj->work[0]];
}
void* func_800F766C_CoinBlockBash(omObjData* obj) {
    return obj->unk_50;
}
s8 func_800F7674_CoinBlockBash(omObjData* obj) {
    return ((CBBPlayerWork*)obj->unk_50)->unk_56;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F7680_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F77BC_CoinBlockBash);

void func_800F78DC_CoinBlockBash(void) {
    s32 pad[4]; /* retail's frame */
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F78E8_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F7A5C_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F8014_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F8184_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F81E0_CoinBlockBash);

void func_800F8CD0_CoinBlockBash(void) {
    s16* blk = (s16*)&D_80102538_CoinBlockBash;
    s32 i;

    func_8009B770(blk, 0, 0x74);
    *blk = LoadFormFile(0x270001, 0xB9);
    D_8010253A_CoinBlockBash = func_800174C0(6, 0x89);
    D_8010253C_CoinBlockBash = -1;
    D_80102548_CoinBlockBash = 0.0f;
    D_8010254C_CoinBlockBash = 0.0f;
    D_80102550_CoinBlockBash = 0.0f;
    i = D_801025AC_CoinBlockBash;
    i = (~i >> 31) & i;
    func_800FBF70_CoinBlockBash(D_801025B0_CoinBlockBash[i].obj);
    func_800F7048_CoinBlockBash(D_801025B0_CoinBlockBash[i].obj);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F8D98_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F96A0_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F9814_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F99A0_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F9A98_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F9CF0_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F9FE4_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FA388_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FA600_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FA7AC_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FA944_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FAA7C_CoinBlockBash);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", D_80101FF0_CoinBlockBash);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", D_80102010_CoinBlockBash);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", D_80102024_CoinBlockBash);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", D_80102038_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FACEC_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FB490_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FB4F4_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FB71C_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FB900_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FBF70_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FC054_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FC2AC_CoinBlockBash);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", D_80102280_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FD8CC_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FDC5C_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FDCB4_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FDCF8_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FDD50_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FDDEC_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FDEA0_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FDF20_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FE0AC_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FE284_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FE294_CoinBlockBash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FE470_CoinBlockBash);
