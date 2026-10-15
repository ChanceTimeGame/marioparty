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
// NON_MATCHING: register allocation of the two radii (masked ~40)
#ifdef NON_MATCHING
s16 func_800F7148_CoinBlockBash(s32 self, Vec* pos, s32 unused, f32 vy) {
    f32 rot[3];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 push;
    f32 rA;
    f32 rB;
    f32 angle;
    CBBPlayer* p;
    omObjData* o;
    s16 res;
    s16 i;

    res = 0;
    rA = rB = 50.0f;
    rB = 50.0f;
    rA = rB;
    rB = rA;
    for (i = 0; i < D_801031FC_CoinBlockBash; i++) {
        if (i == self) {
            continue;
        }
        if (i == D_801025B0_CoinBlockBash[self].unk_40) {
            continue;
        }
        p = &D_801025B0_CoinBlockBash[i];
        if (p->flags & 0x20) {
            continue;
        }
        o = p->obj;
        dx = o->trans.x - pos->x;
        dy = o->trans.y - pos->y;
        dz = o->trans.z - pos->z;
        if (abs((s32)dy) > 100.0) {
            continue;
        }
        dist = sqrtf(dx * dx + dz * dz);
        if (!(dist < rA + rB)) {
            continue;
        }
        if (vy < 0.0 && dy < 0.0 && dy + vy <= -100.0 && p->unk_44 == 0) {
            pos->y = rB + rB + o->trans.y;
            p->unk_40 = self;
            if (p->unk_44 == 0) {
                p->state = 8;
                p->unk_42 = 30;
                p->unk_50 = 0;
                rot[0] = -90.0f;
                rot[1] = rot[2] = 0.0f;
                func_80017C0C(o, 5, pos->x, pos->y, pos->z, rot[0], rot[1]);
            }
            res = -1;
            continue;
        }
        if (dist == 0.0) {
            dx = pos->x - -25.0;
            dz = pos->z - -14.999999999999972;
            if (dx == 0.0 && dz == 0.0) {
                angle = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 360 / 65536;
                dx = func_800AEAC0(angle);
                dz = func_800AEFD0(angle);
            } else if (dx == 0.0) {
                dz /= abs((s32)dz);
            } else if (dz == 0.0) {
                dx /= abs((s32)dx);
            } else {
                dist = sqrtf(dx * dx + dz * dz);
                dx /= dist;
                dz /= dist;
            }
            push = 100.0f;
        } else {
            dx /= dist;
            dz /= dist;
            push = rA + rB - dist;
        }
        pos->x -= dx * push;
        pos->z -= dz * push;
        res = 1;
    }
    D_801025B0_CoinBlockBash[self].unk_40 = -1;
    return res;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F7148_CoinBlockBash);
#endif
CBBPlayer* func_800F7644_CoinBlockBash(omObjData* obj) {
    return &D_801025B0_CoinBlockBash[obj->work[0]];
}
void* func_800F766C_CoinBlockBash(omObjData* obj) {
    return obj->unk_50;
}
s8 func_800F7674_CoinBlockBash(omObjData* obj) {
    return ((CBBPlayerWork*)obj->unk_50)->unk_56;
}
void func_800F7680_CoinBlockBash(omObjData* obj, s16 motion, char* name) {
    CBBMtxSet* set;
    CBBPlayer* p;
    Matrix4f* dst;
    Matrix4f* src;
    s32 i;
    s32 j;

    func_80025BB8(obj->model[0], obj->motion[motion]);
    set = func_8002040C(obj->model[0], 2, name);
    p = func_800F7644_CoinBlockBash(obj);
    for (i = 0; i < 2; i++) {
        if (p->mtxCount[i] == 0) {
            break;
        }
    }
    if (i < 2) {
        p->mtx[i] = dst = func_80023684((p->mtxCount[i] = set->count) * 64, 0x7918);
        src = set->mtx;
        for (j = 0; j < p->mtxCount[i]; j++) {
            func_8002C37C(*dst++, *src++);
        }
    }
    func_80020CC4(set);
}
void func_800F77BC_CoinBlockBash(omObjData* obj, s32 motion) {
    CBBPlayer* p;
    s16 id;
    u8 mdl;

    id = func_80017A50(obj);
    p = func_800F7644_CoinBlockBash(obj);
    if (p->unk_4A != id && p->unk_4C != id) {
        if (p->unk_48 != 0) {
            p->unk_4C = id;
        } else {
            p->unk_4A = id;
        }
        p->unk_48 = 1 - p->unk_48;
    }
    if (obj->motion[(u8)motion] >= 0) {
        mdl = obj->model[0];
        if (func_80018490(obj, (u8)motion) != 0) {
            D_800F2B7C[mdl].unk_0A |= 2;
        } else {
            D_800F2B7C[mdl].unk_0A &= ~2;
        }
        func_800184BC(obj, (u8)motion);
        p->unk_5E = (u8)motion;
    }
}
void func_800F78DC_CoinBlockBash(void) {
    s32 pad[4]; /* retail's frame */
}
void func_800F78E8_CoinBlockBash(void) {
    s32 i;

    D_801031E2_CoinBlockBash = 0;
    D_801031D0_CoinBlockBash[D_801031E2_CoinBlockBash++] = func_800F6C80_CoinBlockBash(0x270004);
    D_801031D0_CoinBlockBash[D_801031E2_CoinBlockBash++] = func_800F6C80_CoinBlockBash(0x390019);
    D_801031E2_CoinBlockBash++;
    D_801031E0_CoinBlockBash = func_80064EF4(40, 0);
    for (i = 0; i < 40; i++) {
        func_80067208(D_801031E0_CoinBlockBash, i, D_801031D0_CoinBlockBash[0], 0);
        func_80067354(D_801031E0_CoinBlockBash, i, 1.0f, 1.0f);
        func_8006752C(D_801031E0_CoinBlockBash, i, 0x100);
        func_800674BC(D_801031E0_CoinBlockBash, i, 0x9008);
        func_800672B0(D_801031E0_CoinBlockBash, i, 0);
    }
    func_8009B770(D_80102870_CoinBlockBash, 0, sizeof(D_80102870_CoinBlockBash));
    D_801031E4_CoinBlockBash = -1;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F7A5C_CoinBlockBash);

void func_800F8014_CoinBlockBash(void) {
    Vec v;
    CBBPlayer* p;
    omObjData* o;
    s32 i;

    for (i = 0; i < D_801031FC_CoinBlockBash; i++) {
        p = &D_801025B0_CoinBlockBash[i];
        o = p->obj;
        if (func_8005FD5C() + D_800F64F8 == 0) {
            if ((p->unk_44 & 1) && !(p->flags & 0x10) && D_801024F0_CoinBlockBash.state == 1) {
                func_80025798(o->model[0], 1500.0f, 500.0f, 1500.0f);
                func_80025798(o->model[1], 1500.0f, 500.0f, 1500.0f);
            }
            p->pos.x = o->trans.x;
            p->pos.y = o->trans.y;
            p->pos.z = o->trans.z;
        } else {
            v.x = o->trans.x;
            v.z = o->trans.z;
            v.y = func_800FE284_CoinBlockBash(&v);
            func_80025798(o->model[1], o->trans.x, v.y, o->trans.z);
        }
    }
}
void func_800F8184_CoinBlockBash(s16 type, f32 x, f32 y, f32 z, s16 arg) {
    Vec pos;
    Vec rot;

    pos.x = x;
    pos.y = y;
    pos.z = z;
    rot.x = rot.y = rot.z = 0.0f;
    func_800F81E0_CoinBlockBash(NULL, type, &pos, &rot, arg);
}
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
