#include "DeepSeaDivers.h"

#ifdef NON_MATCHING
void func_800F65E0_DeepSeaDivers(void) {
    omObjData* obj;
    u8 cam;
    s16 i;
    s16 j;
    s16 n;

    func_80029090(50);
    func_8001DE70(32);
    omInitObjMan(50, 0);
    i = 0;
    func_80060088();
    omSetStatBit(omAddObj(32730, 0, 0, -1, omOutView), 160);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 10.0f, 2000.0f, 32000.0f);
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_801003FC_DeepSeaDivers = 0;
    D_801003FE_DeepSeaDivers = 45;
    D_80100402_DeepSeaDivers = 0;
    D_80100400_DeepSeaDivers = 1;
    D_80100404_DeepSeaDivers = 2700;
    D_80100408_DeepSeaDivers = _CheckFlag(0x2B);
    do {
        D_801017B0_DeepSeaDivers[i] = NULL;
        i++;
    } while (i < 256);
    D_8010040E_DeepSeaDivers = 0;
    D_8010040C_DeepSeaDivers = 0;
    D_8010040A_DeepSeaDivers = 0;
    D_80100406_DeepSeaDivers = -1;
    D_80101BD4_DeepSeaDivers = 0;
    D_801017A0_DeepSeaDivers = 0;
    DataClose(DataRead(0x160014));
    i = 0;
    func_800FB860_DeepSeaDivers();
    func_800FD494_DeepSeaDivers();
    D_80100464_DeepSeaDivers = func_80076FF4(124);
    D_80101BD0_DeepSeaDivers = omAddObj(10, 0, 0, -1, func_800F6B1C_DeepSeaDivers);
    D_800F2AF8[D_800ED440++] = obj = omAddObj(0, 9, 0, -1, func_800F70F4_DeepSeaDivers);
    omSetStatBit(obj, 160);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 6, 0, -1, func_800F791C_DeepSeaDivers);
    D_80100C70_DeepSeaDivers[1] = 0;
    D_80100C70_DeepSeaDivers[2] = 0;
    for (n = 0, j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group == j) {
                D_8010046A_DeepSeaDivers[n++] = i;
            }
        }
        i = 0;
    }
    do {
        D_800F3FB0[D_800F2BC0++] = D_80101780_DeepSeaDivers[i].diver =
            omAddObj(2, 3, 50, -1, func_800F7968_DeepSeaDivers);
        D_800F3FB0[D_800F2BC0++] = D_80101780_DeepSeaDivers[i].pumper =
            omAddObj(3, 1, 50, -1, func_800F8680_DeepSeaDivers);
        i++;
    } while (i < 2);
    for (i = 0; i < 8; i++) {
        D_80101BB0_DeepSeaDivers[D_801017A0_DeepSeaDivers++] = omAddObj(4, 2, 0, -1, func_800F9AF4_DeepSeaDivers);
    }
    D_80100460_DeepSeaDivers = omAddObj(0, 0, 0, -1, func_800F7000_DeepSeaDivers);
    func_800FB964_DeepSeaDivers();
    func_800FB984_DeepSeaDivers();
    func_800234B8(0, 128, 128, 128);
    func_800234B8(1, 255, 255, 255);
    func_80023504(1, 0.0f, 128.0f, 128.0f);
    D_801004A8_DeepSeaDivers[1] = 0;
    D_801004A8_DeepSeaDivers[0] = 0;
    D_80101798_DeepSeaDivers = 0.075f;
    func_800FDBA0_DeepSeaDivers();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F65E0_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F6B1C_DeepSeaDivers(omObjData* obj) {
    obj->func_ptr = func_800F6BDC_DeepSeaDivers;
    SetFadeInTypeAndTime(0, 16);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F6B1C_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F6B48_DeepSeaDivers(void) {
    s16 i;

    for (i = 0; i < 2; i++) {
        func_800FE170_DeepSeaDivers(D_80100466_DeepSeaDivers[i], &D_80100478_DeepSeaDivers[i].top,
                                    &D_80100478_DeepSeaDivers[i].bottom);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F6B48_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F6BDC_DeepSeaDivers(omObjData* obj) {
    switch (D_801003FC_DeepSeaDivers) {
        case 0:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers++;
                D_801003FE_DeepSeaDivers = 45;
                func_80060128(25);
            }
            break;
        case 1:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers++;
                D_801003FE_DeepSeaDivers = 60;
                GMesCreate(0);
            }
            break;
        case 2:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers++;
                D_80100400_DeepSeaDivers = 0;
                D_80101798_DeepSeaDivers = 0.5f;
            }
            break;
        case 3:
            if (D_80100402_DeepSeaDivers == 0) {
                if ((D_80100410_DeepSeaDivers | D_80100438_DeepSeaDivers) == 0) {
                    D_80100402_DeepSeaDivers = 1;
                    D_80100400_DeepSeaDivers = 1;
                    D_801003F0_DeepSeaDivers = 10;
                }
                if (D_80100402_DeepSeaDivers == 0 && D_80100404_DeepSeaDivers != 0) {
                    D_80100404_DeepSeaDivers--;
                }
            }
            if (D_80100404_DeepSeaDivers == 0 || D_80100402_DeepSeaDivers != 0) {
                D_80100400_DeepSeaDivers = 1;
                if (D_80100408_DeepSeaDivers == 0) {
                    D_801003FC_DeepSeaDivers++;
                    GMesCreate(D_80100404_DeepSeaDivers == 0 ? 16 : 2);
                } else {
                    D_801003FC_DeepSeaDivers = 6;
                    GMesCreate(2);
                }
                func_800601D4(40);
            }
            break;
        case 4:
            if (GMesStatAllGet() == 2) {
                D_801003FC_DeepSeaDivers++;
                if (D_80100402_DeepSeaDivers != 0) {
                    func_80060128(54);
                } else {
                    func_80060128(60);
                }
            }
            break;
        case 5:
            if (func_8000C144() != 0x200 && func_8000C144() != 1) {
                D_801003FC_DeepSeaDivers = -1;
                D_80100402_DeepSeaDivers = -1;
                func_800726AC(0, 20);
            }
            break;
        case 6:
            if (GMesStatAllGet() == 2) {
                D_801003FC_DeepSeaDivers++;
                D_801003FE_DeepSeaDivers = 60;
            }
            break;
        case 7:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers = -1;
                D_80100402_DeepSeaDivers = -1;
                func_80060398(40);
                func_800726AC(0, 20);
            }
            break;
    }
    func_800FB130_DeepSeaDivers();
    if (D_800F5144 != 0) {
        D_80100402_DeepSeaDivers = -1;
    }
    if (D_801004A8_DeepSeaDivers[0] == 0 && D_801003FC_DeepSeaDivers != 0) {
        func_800FBB30_DeepSeaDivers();
    }
    func_800F6B48_DeepSeaDivers();
    func_800FD8C8_DeepSeaDivers();
    func_800F6F7C_DeepSeaDivers();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F6BDC_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F6F7C_DeepSeaDivers(void) {
    if (D_80100402_DeepSeaDivers < 0 && func_80072718() == 0) {
        HuMemDirectFree(D_801003F8_DeepSeaDivers);
        HuMemDirectFree(D_801003F4_DeepSeaDivers);
        func_800FDD84_DeepSeaDivers(D_80100466_DeepSeaDivers[0]);
        func_800FDD84_DeepSeaDivers(D_80100466_DeepSeaDivers[1]);
        func_800FC148_DeepSeaDivers();
        func_80060198();
        omOvlReturnEx(1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F6F7C_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F7000_DeepSeaDivers(omObjData* obj) {
    GMesCreate(8, (s16)(D_80100404_DeepSeaDivers / 30), 160, 24);
    obj->func_ptr = func_800F7074_DeepSeaDivers;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F7000_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F7074_DeepSeaDivers(omObjData* obj) {
    func_80079078((s16)((D_80100404_DeepSeaDivers + 29) / 30));
    if (D_80100404_DeepSeaDivers == 0 || D_80100402_DeepSeaDivers != 0) {
        obj->func_ptr = NULL;
        func_800790C0();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F7074_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F70F4_DeepSeaDivers(omObjData* obj) {
    s16 sprite;
    s16 m;
    u16 i;

    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    for (i = 0; i < 2; i++) {
        obj->model[(s16)i] = func_800174C0(D_800FF960_DeepSeaDivers[(s16)i], 0x2D9);
        func_80025798(obj->model[(s16)i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(obj->model[(s16)i], obj->scale.x, obj->scale.y, obj->scale.z);
        if ((s16)i == 0) {
            func_80025EB4(obj->model[0], 2, 2);
            D_800F2B7C[obj->model[0]].unk_4C = 0.5f;
        }
    }
    func_800FF6E0_DeepSeaDivers(obj);
    sprite = InitSprite(0x440007);
    D_801003F8_DeepSeaDivers = HuMemDirectMalloc(21 * 5 * sizeof(Vtx));
    func_800F72EC_DeepSeaDivers();
    D_801003F4_DeepSeaDivers = HuMemDirectMalloc(0x200 * sizeof(Gfx));
    func_800F7470_DeepSeaDivers(D_801003F4_DeepSeaDivers, sprite);
    m = func_80024198(0xC0, D_801003F4_DeepSeaDivers, 4);
    func_80025830(m, 2.0f, 2.0f, 2.0f);
    func_80025798(m, 0.0f, 0.0f, -2000.0f);
    obj->func_ptr = func_800F72D0_DeepSeaDivers;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F70F4_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F72D0_DeepSeaDivers(omObjData* obj) {
    func_800FF730_DeepSeaDivers();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F72D0_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F72EC_DeepSeaDivers(void) {
    Vtx* v;
    s16 i;
    s16 k;
    s16 y;

    for (i = 0; i < 21; i++) {
        k = i * 5;
        v = &D_801003F8_DeepSeaDivers[k];
        v[0].v.ob[0] = -1900;
        v[1].v.ob[0] = -950;
        v[2].v.ob[0] = 0;
        v[3].v.ob[0] = 950;
        v[4].v.ob[0] = 1900;
        v[0].v.ob[2] = v[1].v.ob[2] = v[2].v.ob[2] = v[3].v.ob[2] = v[4].v.ob[2] = -2000;
        y = (140.0 - i * 20) * 5.0;
        v[0].v.ob[1] = v[1].v.ob[1] = v[2].v.ob[1] = v[3].v.ob[1] = v[4].v.ob[1] = y;
        v[0].v.tc[0] = 0;
        v[1].v.tc[0] = 0xA00;
        v[2].v.tc[0] = 0x1400;
        v[3].v.tc[0] = 0x1E00;
        v[4].v.tc[0] = 0x2800;
        v[0].v.tc[1] = v[1].v.tc[1] = v[2].v.tc[1] = v[3].v.tc[1] = v[4].v.tc[1] = i * 0x300;
        v[0].v.cn[0] = v[1].v.cn[0] = v[2].v.cn[0] = v[3].v.cn[0] = v[0].v.cn[0] = 0;
        v = &D_801003F8_DeepSeaDivers[k];
        v[0].v.cn[1] = v[1].v.cn[1] = v[2].v.cn[1] = v[3].v.cn[1] = v[0].v.cn[1] = 0;
        v = &D_801003F8_DeepSeaDivers[k];
        v[0].v.cn[2] = v[1].v.cn[2] = v[2].v.cn[2] = v[3].v.cn[2] = v[4].v.cn[2] = 0;
        v = &D_801003F8_DeepSeaDivers[k];
        v[0].v.cn[3] = v[1].v.cn[3] = v[2].v.cn[3] = v[3].v.cn[3] = v[4].v.cn[3] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F72EC_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F7470_DeepSeaDivers(Gfx* gfx, s16 sprite) {
    unk65770Anim* a = func_80067310(sprite);
    s16 i;
    s16 cur;
    s16 next;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    gDPSetRenderMode(gfx++, 0x443078, 0);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, a->unkC);
    gSPVertex(gfx++, D_801003F8_DeepSeaDivers, 5, 0);
    cur = 0;
    for (i = 0; i < 20; i++) {
        gDPLoadTextureTile(gfx++, a->unk8, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 0, 0, i * 12, 159, i * 12 + 11, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        next = cur + 5;
        if (next >= 30) {
            next = 0;
        }
        gSPVertex(gfx++, &D_801003F8_DeepSeaDivers[(i + 1) * 5], 5, next);
        gSP2Triangles(gfx++, cur, next, cur + 1, 0, cur + 1, next, next + 1, 0);
        gSP2Triangles(gfx++, cur + 1, next + 1, cur + 2, 0, cur + 2, next + 1, next + 2, 0);
        gSP2Triangles(gfx++, cur + 2, next + 2, cur + 3, 0, cur + 3, next + 2, next + 3, 0);
        gSP2Triangles(gfx++, cur + 3, next + 3, cur + 4, 0, cur + 4, next + 3, next + 4, 0);
        cur = next;
    }
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F7470_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F791C_DeepSeaDivers(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x16000E, 0x299);
    func_800FEA00_DeepSeaDivers(obj);
    obj->func_ptr = func_800FEF34_DeepSeaDivers;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F791C_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800F7968_DeepSeaDivers(omObjData* obj) {
    DSDPlayerWork* w;
    DSDWork* dw;
    s16 player;
    s32 dir;
    u8 chr;

    player = D_8010046A_DeepSeaDivers[D_80100C70_DeepSeaDivers[1] * 2];
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    obj->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x299);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    func_800093FC(obj, D_800FF968_DeepSeaDivers[D_80100C70_DeepSeaDivers[1]], 650.0f, -325.0f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    obj->unk_50 = w = func_80023684(sizeof(DSDPlayerWork), 0x7918);
    func_8009B770(w, 0, sizeof(DSDPlayerWork));
    w->unk_50 = 0;
    w->unk_52 = 0;
    w->unk_56 = GwPlayer[player].port;
    w->unk_C0 = 0xFFFF;
    w->unk_D8 = func_80023684(obj->mtncnt * 0xE8, 0x7918);
    func_8009B770(w->unk_D8, 0, obj->mtncnt * 0xE8);
    func_8001874C(obj, 0, dir | 0x31, 1, 0);
    func_800184BC(obj, 0);
    func_80025BB8(obj->model[0], obj->motion[0]);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    obj->model[1] = LoadFormFile(0x3F0004, 0x499);
    D_800F2B7C[obj->model[1]].unk_4C = 0.0f;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 25.0, obj->trans.z + 20.0);
    func_800257E4(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_80025830(obj->model[1], 1.0f, 1.0f, 1.0f);
    obj->model[2] = func_800174C0(D_800FF96C_DeepSeaDivers[D_80100C70_DeepSeaDivers[1]], 0x2D9);
    func_80025830(obj->model[2], 1.0f, 1.0f, 1.0f);
    obj->func_ptr = func_800F7C9C_DeepSeaDivers;
    dw = func_800FC058_DeepSeaDivers(obj);
    dw->unkC = D_80100C70_DeepSeaDivers[1];
    dw->unk44 = player;
    D_80100C70_DeepSeaDivers[1]++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F7968_DeepSeaDivers);
#endif
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", D_800FFEC0_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F7C9C_DeepSeaDivers);

#ifdef NON_MATCHING
void func_800F8680_DeepSeaDivers(omObjData* obj) {
    DSDPlayerWork* w;
    DSDWork* dw;
    s16 player;
    s32 dir;
    u8 chr;

    player = D_8010046A_DeepSeaDivers[D_80100C70_DeepSeaDivers[2] * 2 + 1];
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    obj->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x299);
    func_800093FC(obj, D_800FF968_DeepSeaDivers[D_80100C70_DeepSeaDivers[2]], 325.0f, -200.0f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    obj->unk_50 = w = func_80023684(sizeof(DSDPlayerWork), 0x7918);
    func_8009B770(w, 0, sizeof(DSDPlayerWork));
    w->unk_50 = 0;
    w->unk_52 = 0;
    w->unk_56 = GwPlayer[player].port;
    w->unk_C0 = 0xFFFF;
    w->unk_58 = GwPlayer[player].character;
    w->unk_AE = 0;
    obj->func_ptr = func_800F88E0_DeepSeaDivers;
    w->unk_D8 = func_80023684(obj->mtncnt * 0xE8, 0x7918);
    func_8009B770(w->unk_D8, 0, obj->mtncnt * 0xE8);
    func_8001874C(obj, 0, dir | 0xC, 1, 0);
    func_8001874C(obj, 1, dir | 0x13, 1, 0);
    func_8001874C(obj, 2, dir | 0x14, 1, 0);
    func_8001874C(obj, 3, dir | 0x16, 2, 0);
    func_8001874C(obj, 4, dir | 0x17, 1, 0);
    func_8001874C(obj, 5, dir | 0x24, 2, 0);
    dw = func_800FC058_DeepSeaDivers(obj);
    dw->unkC = D_80100C70_DeepSeaDivers[2];
    dw->unk44 = player;
    D_80100C70_DeepSeaDivers[2]++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F8680_DeepSeaDivers);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F88E0_DeepSeaDivers);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", D_80100080_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F9AF4_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F9DD8_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FA62C_DeepSeaDivers);

#ifdef NON_MATCHING
void func_800FA9A4_DeepSeaDivers(s16 idx) {
    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8000;
        D_80100C80_DeepSeaDivers[idx].timer = 60;
        D_80100C80_DeepSeaDivers[idx].y = 665.0f;
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80101790_DeepSeaDivers[0], 3);
        D_80100C80_DeepSeaDivers[idx].sx = 0.75f;
        D_80100C80_DeepSeaDivers[idx].sy = 0.5f;
    }
    if (func_80067328(D_80100C80_DeepSeaDivers[idx].sprite, 0) & 2) {
        func_800FD870_DeepSeaDivers(idx);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FA9A4_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FAABC_DeepSeaDivers(s16 idx) {
    DSDWork* w;

    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8080;
        D_80100C80_DeepSeaDivers[idx].timer = 180;
        func_80067354(D_80100C80_DeepSeaDivers[idx].sprite, 0, 0.75f, 0.75f);
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80100464_DeepSeaDivers, 0);
    }
    func_800672DC(D_80100C80_DeepSeaDivers[idx].sprite, 0, (D_80100C80_DeepSeaDivers[idx].timer - 1) / 30, 0);
    w = D_801017B0_DeepSeaDivers[D_80100C80_DeepSeaDivers[idx].target];
    D_80100C80_DeepSeaDivers[idx].x = w->unk10;
    D_80100C80_DeepSeaDivers[idx].y = w->unk14 + 120.0;
    if (--D_80100C80_DeepSeaDivers[idx].timer == 0 || !(w->unk2 & 4)) {
        func_800FD870_DeepSeaDivers(idx);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FAABC_DeepSeaDivers);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FAC68_DeepSeaDivers);

#ifdef NON_MATCHING
void func_800FB010_DeepSeaDivers(s16 idx) {
    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8000;
        D_80100C80_DeepSeaDivers[idx].timer = 60;
        D_80100C80_DeepSeaDivers[idx].y = 725.0f;
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80101790_DeepSeaDivers[2], 0);
    }
    D_80100C80_DeepSeaDivers[idx].x = D_80101780_DeepSeaDivers[D_80100C80_DeepSeaDivers[idx].target].pumper->trans.x;
    if (func_80067328(D_80100C80_DeepSeaDivers[idx].sprite, 0) & 2) {
        func_800FD870_DeepSeaDivers(idx);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB010_DeepSeaDivers);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB130_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB27C_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB310_DeepSeaDivers);

#ifdef NON_MATCHING
void func_800FB860_DeepSeaDivers(void) {
    CZoom = 21000.0f;
    CRot.x = 2.9249f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = -580.0f;
    Center.z = -110.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB860_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FB8C8_DeepSeaDivers(Matrix4f m, f32 x, f32 y, f32 z, Vec* out) {
    f32* o = (f32*)out;

    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    o[0] = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    o[1] = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB8C8_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FB964_DeepSeaDivers(void) {
    D_801004B4_DeepSeaDivers = 0;
    D_801004B0_DeepSeaDivers = 0;
    D_801004B2_DeepSeaDivers = -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB964_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FB984_DeepSeaDivers(void) {
    Matrix4f m;
    Vec v;

    D_801004B0_DeepSeaDivers = 1;
    D_801004C4_DeepSeaDivers.x = D_801004EC_DeepSeaDivers.x = CRot.x;
    D_801004C4_DeepSeaDivers.y = D_801004EC_DeepSeaDivers.y = CRot.y;
    D_801004C4_DeepSeaDivers.z = D_801004EC_DeepSeaDivers.z = CRot.z;
    D_801004B8_DeepSeaDivers.x = D_801004E0_DeepSeaDivers.x = Center.x;
    D_801004B8_DeepSeaDivers.y = D_801004E0_DeepSeaDivers.y = Center.y;
    D_801004B8_DeepSeaDivers.z = D_801004E0_DeepSeaDivers.z = Center.z;
    D_801004D0_DeepSeaDivers = D_801004F8_DeepSeaDivers = CZoom;
    guTranslateF(m, Center.x, Center.y, Center.z);
    MtxRotate(m, CRot.x, CRot.y, CRot.z);
    func_800FB8C8_DeepSeaDivers(m, 0.0f, 0.0f, CZoom, &v);
    D_801004D4_DeepSeaDivers.x = D_801004FC_DeepSeaDivers.x = v.x;
    D_801004D4_DeepSeaDivers.y = D_801004FC_DeepSeaDivers.y = v.y;
    D_801004D4_DeepSeaDivers.z = D_801004FC_DeepSeaDivers.z = v.z;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB984_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FBABC_DeepSeaDivers(void) {
    D_801004B0_DeepSeaDivers = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FBABC_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FBAC8_DeepSeaDivers(f32 x, f32 y, f32 z, f32 w) {
    if (D_801004B4_DeepSeaDivers < 16) {
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].x = x;
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].y = y;
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].z = z;
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].w = w;
        D_801004B4_DeepSeaDivers++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FBAC8_DeepSeaDivers);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FBB30_DeepSeaDivers);

#ifdef NON_MATCHING
DSDWork* func_800FC058_DeepSeaDivers(omObjData* obj) {
    DSDWork* w = HuMemDirectMalloc(sizeof(DSDWork));

    D_801017B0_DeepSeaDivers[D_80101BD4_DeepSeaDivers] = w;
#ifdef TARGET_PC
    /* The host keeps the table index in work[]: a pointer does not fit in four bytes. */
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = (u16)D_80101BD4_DeepSeaDivers >> 8;
    obj->work[3] = D_80101BD4_DeepSeaDivers;
#else
    obj->work[0] = (u32)w >> 24;
    obj->work[1] = (u32)w >> 16;
    obj->work[2] = (u32)w >> 8;
    obj->work[3] = (u32)w;
#endif
    w->unk0 = 0;
    w->unk2 = 0;
    w->unk8 = 0;
    w->unkA = D_80101BD4_DeepSeaDivers;
    w->unkC = 0;
    w->unk10 = w->unk14 = w->unk18 = 0.0f;
    w->unk1C = w->unk20 = w->unk24 = 0.0f;
    w->unk28 = w->unk2C = w->unk30 = 0.0f;
    w->unk40 = w->unk42 = w->unk44 = w->unk46 = 0;
    w->unk48 = w->unk4A = w->unk4C = w->unk4E = 0;
    w->unk50 = w->unk52 = w->unk54 = w->unk56 = 0;
    w->unk58 = w->unk5A = w->unk5C = w->unk5E = 0;
    D_80101BD4_DeepSeaDivers++;
    return w;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC058_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FC148_DeepSeaDivers(void) {
    s16 i;

    for (i = 0; i < D_80101BD4_DeepSeaDivers; i++) {
        if (D_801017B0_DeepSeaDivers[i] != NULL) {
            HuMemDirectFree(D_801017B0_DeepSeaDivers[i]);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC148_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
DSDWork* func_800FC1C8_DeepSeaDivers(omObjData* obj) {
#ifdef TARGET_PC
    return D_801017B0_DeepSeaDivers[(obj->work[2] << 8) | obj->work[3]];
#else
    return (DSDWork*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
#endif
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC1C8_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
u16 func_800FC1F4_DeepSeaDivers(void) {
    u8 hi = rand8();

    return (hi << 8) | rand8();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC1F4_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FC22C_DeepSeaDivers(f32* x, f32* z) {
    if (*x < -2000.0) {
        *x = -2000.0f;
    }
    if (*x > 2000.0) {
        *x = 2000.0f;
    }
    if (*z > 625.0) {
        *z = 625.0f;
    }
    if (*z < -2000.0) {
        *z = -2000.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC22C_DeepSeaDivers);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC2F8_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC644_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FCAE8_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FCDC8_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FCF54_DeepSeaDivers);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", D_80100268_DeepSeaDivers);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", D_8010026C_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD28C_DeepSeaDivers);

#ifdef NON_MATCHING
s16 func_800FD450_DeepSeaDivers(s32 file) {
    void* data = DataRead(file);
    s16 ret = func_800678A4(data);

    DataClose(data);
    return ret & 0xFF;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD450_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FD494_DeepSeaDivers(void) {
    s16 i;

    D_80101790_DeepSeaDivers[0] = func_800FD450_DeepSeaDivers(0x160010);
    D_80101790_DeepSeaDivers[1] = func_800FD450_DeepSeaDivers(0x21);
    D_80101790_DeepSeaDivers[2] = func_800FD450_DeepSeaDivers(0x440008);
    D_80100C70_DeepSeaDivers[0] = func_800FD450_DeepSeaDivers(0x440006);
    D_8010179E_DeepSeaDivers = func_80064EF4(1, 0);
    func_80067208(D_8010179E_DeepSeaDivers, 0, D_80100C70_DeepSeaDivers[0], 0);
    func_800674BC(D_8010179E_DeepSeaDivers, 0, 0x4000);
    func_80066DC4(D_8010179E_DeepSeaDivers, 0, 160, 64);
    func_80067354(D_8010179E_DeepSeaDivers, 0, 2.0f, 1.0f);
    for (i = 0; i < 64; i++) {
        D_80100C80_DeepSeaDivers[i].flags = 0;
        D_80100C80_DeepSeaDivers[i].type = 0;
        D_80100C80_DeepSeaDivers[i].sprite = func_80064EF4(1, 0);
        func_80067480(D_80100C80_DeepSeaDivers[i].sprite, 0, -1);
        func_800674BC(D_80100C80_DeepSeaDivers[i].sprite, 0, 0xC000);
        D_80100C80_DeepSeaDivers[i].target = 0;
        D_80100C80_DeepSeaDivers[i].x = 0.0f;
        D_80100C80_DeepSeaDivers[i].y = 0.0f;
        D_80100C80_DeepSeaDivers[i].z = 0.0f;
        D_80100C80_DeepSeaDivers[i].unk1E = D_80100C80_DeepSeaDivers[i].unk20 = D_80100C80_DeepSeaDivers[i].unk22 = 0;
        D_80100C80_DeepSeaDivers[i].timer = 0;
        D_80100C80_DeepSeaDivers[i].unk26 = D_80100C80_DeepSeaDivers[i].unk28 = D_80100C80_DeepSeaDivers[i].unk2A = 0;
        D_80100C80_DeepSeaDivers[i].unk24 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD494_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
s16 func_800FD680_DeepSeaDivers(s16 type, f32 x, f32 y, f32 z, u16 target) {
    s16 i;

    for (i = 0; i < 64; i++) {
        if (D_80100C80_DeepSeaDivers[i].flags == 0) {
            D_80100C80_DeepSeaDivers[i].flags = 1;
            D_80100C80_DeepSeaDivers[i].type = type;
            D_80100C80_DeepSeaDivers[i].target = target;
            D_80100C80_DeepSeaDivers[i].x = x;
            D_80100C80_DeepSeaDivers[i].y = y;
            D_80100C80_DeepSeaDivers[i].z = z;
            D_80100C80_DeepSeaDivers[i].sx = 1.0f;
            D_80100C80_DeepSeaDivers[i].sy = 1.0f;
            if (D_80100C80_DeepSeaDivers[i].sprite >= 0) {
                func_8006752C(D_80100C80_DeepSeaDivers[i].sprite, 0, 0x100);
                func_80067480(D_80100C80_DeepSeaDivers[i].sprite, 0, 0xFFFF);
                func_800674BC(D_80100C80_DeepSeaDivers[i].sprite, 0, 0x1000);
                func_80067354(D_80100C80_DeepSeaDivers[i].sprite, 0, 1.0f, 1.0f);
                func_800672B0(D_80100C80_DeepSeaDivers[i].sprite, 0, 1);
                func_80067384(D_80100C80_DeepSeaDivers[i].sprite, 0, 0x8000);
            }
            D_80100C80_DeepSeaDivers[i].unk1E = D_80100C80_DeepSeaDivers[i].unk20 = D_80100C80_DeepSeaDivers[i].unk22 = 0;
            D_80100C80_DeepSeaDivers[i].timer = 0;
            D_80100C80_DeepSeaDivers[i].unk26 = D_80100C80_DeepSeaDivers[i].unk28 = D_80100C80_DeepSeaDivers[i].unk2A = 0;
            D_80100C80_DeepSeaDivers[i].unk24 = 0;
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD680_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FD870_DeepSeaDivers(s16 idx) {
    D_80100C80_DeepSeaDivers[idx].flags = 0;
    if (D_80100C80_DeepSeaDivers[idx].sprite >= 0) {
        func_800674BC(D_80100C80_DeepSeaDivers[idx].sprite, 0, 0x8000);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD870_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FD8C8_DeepSeaDivers(void) {
    Vec3f p;
    Vec2f s;
    unk65770Obj* o;
    s16 i;

    omOutView(NULL);
    for (i = 0; i < 64; i++) {
        if (D_80100C80_DeepSeaDivers[i].flags != 0) {
            switch (D_80100C80_DeepSeaDivers[i].type) {
                case 0:
                    func_800FA62C_DeepSeaDivers(i);
                    break;
                case 1:
                    func_800FA9A4_DeepSeaDivers(i);
                    break;
                case 2:
                    func_800FAABC_DeepSeaDivers(i);
                    break;
                case 3:
                    func_800FAC68_DeepSeaDivers(i);
                    break;
                case 4:
                    func_800FB010_DeepSeaDivers(i);
                    break;
            }
            if (D_80100C80_DeepSeaDivers[i].flags != 0 && D_80100C80_DeepSeaDivers[i].sprite >= 0) {
                o = func_800675F4(D_80100C80_DeepSeaDivers[i].sprite, 0);
                if (DSD_LO8(D_80100C80_DeepSeaDivers[i].flags) < 0) {
                    func_80066DF4(D_80100C80_DeepSeaDivers[i].sprite, 0, 0, D_80100C80_DeepSeaDivers[i].x, D_80100C80_DeepSeaDivers[i].y, D_80100C80_DeepSeaDivers[i].z);
                } else {
                    func_800670C4(D_80100C80_DeepSeaDivers[i].sprite, 0, 0, D_80100C80_DeepSeaDivers[i].x, D_80100C80_DeepSeaDivers[i].y, D_80100C80_DeepSeaDivers[i].z);
                    o->unk14 *= D_80100C80_DeepSeaDivers[i].sx * 4.0;
                    o->unk18 *= D_80100C80_DeepSeaDivers[i].sy * 4.0;
                }
            }
        }
    }
    o = func_800675F4(D_8010179E_DeepSeaDivers, 0);
    p.x = 0.0f;
    p.y = 625.0f;
    p.z = 0.0f;
    Convert3DTo2D(0, &p, &s);
    o->unk42 = s.y;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD8C8_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FDBA0_DeepSeaDivers(void) {
    func_800FDBC4_DeepSeaDivers();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FDBA0_DeepSeaDivers);
#endif
void func_800FDBBC_DeepSeaDivers(void) {
}

#ifdef NON_MATCHING
void func_800FDBC4_DeepSeaDivers(void) {
    func_8009B770(D_80100610_DeepSeaDivers, 0, sizeof(D_80100610_DeepSeaDivers));
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FDBC4_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
s16 func_800FDBEC_DeepSeaDivers(void) {
    DSDRope* r;
    DSDRopeNode* node;
    s32 j;
    s32 k;
    f32 len;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (D_80100610_DeepSeaDivers[i].active == 0) {
            break;
        }
    }
    if (i >= 4) {
        return -1;
    }
    r = &D_80100610_DeepSeaDivers[i];
    r->model = func_800FE2C0_DeepSeaDivers(i);
    r->nodes = func_80023668(5 * sizeof(DSDRopeNode));
    r->active = 1;
    r->unk6 = (s32)func_800FC1F4_DeepSeaDivers() / 2048;
    r->n = 1;
    r->unk8 = 600.0f;
    r->unk10 = 1.0f;
    node = r->nodes;
    func_8009B770(node, 0, 5 * sizeof(DSDRopeNode));
    for (j = 0; j < 5; j++) {
        node->unk2 = j;
        node++;
    }
    len = 0.0f;
    for (k = r->n, j = 0; k >= 0; k--, j++) {
        node = &r->nodes[k];
        node->unk0 = 1;
        if (j != 0) {
            node->unk4 = 200.0f;
        }
        len -= node->unk4;
        node->pos.y = len;
    }
    return i;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FDBEC_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FDD84_DeepSeaDivers(s16 idx) {
    DSDRope* r;

    if (idx >= 0) {
        r = &D_80100610_DeepSeaDivers[idx];
        if (r->active != 0) {
            r->active = 0;
            if (r->nodes != NULL) {
                func_80023728(r->nodes);
            }
            r->nodes = NULL;
            if (r->model != 0) {
                func_8002456C(r->model);
            }
            r->model = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FDD84_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FDE04_DeepSeaDivers(s16 idx, f32 speed, Vec* top) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];

    r->unkC = speed;
    r->top.x = top->x;
    r->top.y = top->y;
    r->top.z = top->z;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FDE04_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FDE44_DeepSeaDivers(s16 idx, Vec* bottom, Vec* out) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];
    DSDRopeNode* first;
    DSDRopeNode* last;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 cur;
    f32 slack;
    f32 len;
    f32 want;
    f32 t;

    r->bottom.x = bottom->x;
    r->bottom.y = bottom->y;
    r->bottom.z = bottom->z;
    dx = r->top.x - r->bottom.x;
    dy = r->top.y - r->bottom.y;
    dz = r->top.z - r->bottom.z;
    dist = sqrtf(dx * dx + dy * dy + dz * dz);
    first = r->nodes;
    dx = r->top.x - first->pos.x;
    dy = r->top.y - first->pos.y;
    dz = r->top.z - first->pos.z;
    cur = sqrtf(dx * dx + dy * dy + dz * dz);
    last = &first[r->n];
    slack = dist - cur;
    if (slack < 0.0) {
        slack = 0.0f;
    }
    len = r->unk8 - r->unkC;
    if (len < 200.0) {
        len = 200.0f;
    }
    r->unk8 = len;
    if (len < dist) {
        r->unk8 = want = slack + len;
    } else {
        want = dist;
    }
    if (r->unkC != 0.0f && r->unk8 < dist + 10.0) {
        r->unk10 -= 0.05;
        if (r->unk10 < 0.0) {
            r->unk10 = 0.0f;
        }
    } else {
        r->unk10 += 0.05;
        if (r->unk10 > 1.0) {
            r->unk10 = 1.0f;
        }
    }
    t = 1.0 / dist * want;
    first->pos.x = r->bottom.x = (r->bottom.x - r->top.x) * t + r->top.x;
    first->pos.y = r->bottom.y = (r->bottom.y - r->top.y) * t + r->top.y;
    first->pos.z = r->bottom.z = (r->bottom.z - r->top.z) * t + r->top.z;
    last->pos.x = r->top.x;
    last->pos.y = r->top.y;
    last->pos.z = r->top.z;
    out->x = first->pos.x;
    out->y = first->pos.y;
    out->z = first->pos.z;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FDE44_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FE170_DeepSeaDivers(s16 idx, Vec* top, Vec* bottom) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];
    DSDRopeNode* first = r->nodes;
    DSDRopeNode* last;
    f32 dx = top->x - bottom->x;
    f32 dy = top->y - bottom->y;
    f32 dz = top->z - bottom->z;
    f32 dist = sqrtf(dx * dx + dy * dy + dz * dz);

    last = &first[r->n];
    if (r->unk8 < dist) {
        r->unk8 = dist;
    }
    r->top.x = last->pos.x = top->x;
    r->top.y = last->pos.y = top->y;
    r->top.z = last->pos.z = top->z;
    r->bottom.x = first->pos.x = bottom->x;
    r->bottom.y = first->pos.y = bottom->y;
    r->bottom.z = first->pos.z = bottom->z;
    r->unk6++;
    if (r->unk6 >= 0x7000) {
        r->unk6 -= 0x800;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FE170_DeepSeaDivers);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FE2C0_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FE378_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FEA00_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FEAC4_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FED88_DeepSeaDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FEF34_DeepSeaDivers);

#ifdef NON_MATCHING
void func_800FF6E0_DeepSeaDivers(omObjData* obj) {
    func_80026040(obj->model[1]);
    D_80100C5C_DeepSeaDivers = 0.0f;
    func_80039C48("dmy_I8", &D_80100C60_DeepSeaDivers);
    D_80100C64_DeepSeaDivers = D_80100C68_DeepSeaDivers = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FF6E0_DeepSeaDivers);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FF730_DeepSeaDivers);
