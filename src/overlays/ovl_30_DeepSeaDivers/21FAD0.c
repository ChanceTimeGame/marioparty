#include "DeepSeaDivers.h"

Gfx D_800FFCC0_DeepSeaDivers[] = {
    gsSPSegment(0x00, 0x00000000),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
Gfx D_800FFD78_DeepSeaDivers[] = {
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPEndDisplayList(),
};
Gfx D_800FFDB8_DeepSeaDivers[] = {
    gsSPDisplayList(D_800FFD78_DeepSeaDivers),
    gsSPDisplayList(D_800FFCC0_DeepSeaDivers),
    gsSPEndDisplayList(),
};
Gfx D_800FFDD0_DeepSeaDivers[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_800FFDB8_DeepSeaDivers),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};
Gfx D_800FFE10_DeepSeaDivers[] = {
    gsDPPipeSync(),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 319, 239),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_LINE, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
s32 D_800FFE60_DeepSeaDivers[3] = { 0, 100, 220 };
s32 D_800FFE6C_DeepSeaDivers[5] = { 30, 30, 30, 0, 0 };

void func_800FDBA0_DeepSeaDivers(void) {
    func_800FDBC4_DeepSeaDivers();
}
void func_800FDBBC_DeepSeaDivers(void) {
}

void func_800FDBC4_DeepSeaDivers(void) {
    func_8009B770(D_80100610_DeepSeaDivers, 0, sizeof(D_80100610_DeepSeaDivers));
}
s16 func_800FDBEC_DeepSeaDivers(void) {
    DSDRope* r;
    DSDRopeNode* node;
    s32 j;
    s32 k;
    f32 len;
    u8 hi;
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
    hi = rand8();
    r->unk6 = ((hi << 8) | rand8()) / 2048;
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
    for (j = r->n, k = 0; j >= 0; j--, k++) {
        node = &r->nodes[j];
        node->unk0 = 1;
        if (k != 0) {
            node->unk4 = 200.0f;
        }
        len -= node->unk4;
        node->pos.y = len;
    }
    return i;
}
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
void func_800FDE04_DeepSeaDivers(s16 idx, f32 speed, Vec* top) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];

    r->unkC = speed;
    r->top.x = top->x;
    r->top.y = top->y;
    r->top.z = top->z;
}
void func_800FDE44_DeepSeaDivers(s16 idx, Vec* bottom, Vec* out) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];
    DSDRopeNode* first;
    DSDRopeNode* last;
    f32 d;
    f32 dist;
    f32 cur;
    f32 slack;
    f32 t;

    r->bottom.x = bottom->x;
    r->bottom.y = bottom->y;
    r->bottom.z = bottom->z;
    d = r->top.x - r->bottom.x;
    dist = d * d;
    d = r->top.y - r->bottom.y;
    dist += d * d;
    d = r->top.z - r->bottom.z;
    dist += d * d;
    dist = sqrtf(dist);
    first = r->nodes;
    last = &r->nodes[r->n];
    d = r->top.x - first->pos.x;
    cur = d * d;
    d = r->top.y - first->pos.y;
    cur += d * d;
    d = r->top.z - first->pos.z;
    cur += d * d;
    cur = sqrtf(cur);
    slack = dist - cur;
    if (slack < 0.0) {
        slack = 0.0f;
    }
    d = r->unk8 - r->unkC;
    if (d < 200.0) {
        d = 200.0f;
    }
    r->unk8 = d;
    if (d < dist) {
        cur = r->unk8 = slack + d;
    } else {
        cur = dist;
    }
    if (r->unkC != 0.0f && dist + 10.0 > r->unk8) {
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
    t = 1.0 / dist * cur;
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
void func_800FE170_DeepSeaDivers(s16 idx, Vec* top, Vec* bottom) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];
    DSDRopeNode* first = r->nodes;
    DSDRopeNode* last = &r->nodes[r->n];
    f32 dist;
    f32 d;

    d = top->x - bottom->x;
    dist = d * d;
    d = top->y - bottom->y;
    dist += d * d;
    d = top->z - bottom->z;
    dist += d * d;
    dist = sqrtf(dist);
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
s16 func_800FE2C0_DeepSeaDivers(s16 idx) {
    unk2C0C0StructC0* m;
    s32 model;
    s32 i;

    model = func_8002451C(0x1080, func_800FE378_DeepSeaDivers, 2);
    m = D_800F2B7C[model].unk_6C;
    for (i = 0; i < D_800F37DA; i++) {
        m->unk_08[i] = func_80023684(40 * sizeof(Vtx), m->unk_68);
        func_8009B770(m->unk_08[i], 0, 40 * sizeof(Vtx));
    }
    return model;
}
// float register allocation (masked 1, raw 45: s (sag, then slack) in f10 not f22, t/ang swapped, one bnezl); tried
// merging sag into s, u8 col, k reused as the colour temp
#ifdef NON_MATCHING
void func_800FE378_DeepSeaDivers(Gfx** gfx) {
    DSDRope* r;
    DSDRopeNode* first;
    DSDRopeNode* last;
    Vtx* v;
    unk2C0C0StructC0* m;
    f32 p[9];
    Vec mid;
    Vec d;
    f32 len;
    f32 s;
    f32 t;
    f32 u;
    f32 a;
    f32 b;
    f32 c;
    f32 ang;
    f32 amp;
    u8 col;
    s32 i;
    s32 k;

    for (i = 0; i < 4; i++) {
        if (D_80100610_DeepSeaDivers[i].model == D_800ED728) {
            break;
        }
    }
    if (i < 4) {
        r = &D_80100610_DeepSeaDivers[i];
        if (!(r->active & 0x80)) {
            r->active |= 0x80;
            return;
        }
        gSPDisplayList((*gfx)++, osVirtualToPhysical(D_800FFDD0_DeepSeaDivers));
        func_8001D658(0, gfx);
        gSPDisplayList((*gfx)++, osVirtualToPhysical(D_800FFE10_DeepSeaDivers));
        m = D_800F2B7C[D_800ED728].unk_6C;
        first = r->nodes;
        last = &r->nodes[r->n];
        v = (Vtx*)m->unk_08[D_800F37F0];
        d.x = last->pos.x - first->pos.x;
        d.y = last->pos.y - first->pos.y;
        d.z = last->pos.z - first->pos.z;
        s = (-func_800AEAC0(func_800B0CD8(d.y, sqrtf(d.x * d.x + d.z * d.z))) + 1.0) * 0.5;
        mid.x = s * d.x + first->pos.x;
        mid.y = s * d.y + first->pos.y;
        mid.z = s * d.z + first->pos.z;
        len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        s = r->unk8 - len;
        if (s < 0.0) {
            s = 0.0f;
        }
        mid.y = mid.y - s - 50.0;
        gSPSegment((*gfx)++, 1, osVirtualToPhysical(v));
        gSPVertex((*gfx)++, 0x01000000, 17, 0);
        p[0] = (first->pos.x - mid.x) + first->pos.x;
        p[1] = (first->pos.y - mid.y) + first->pos.y;
        p[2] = (first->pos.z - mid.z) + first->pos.z;
        p[3] = mid.x;
        p[4] = mid.y;
        p[5] = mid.z;
        p[6] = (last->pos.x - mid.x) + last->pos.x;
        p[7] = (last->pos.y - mid.y) + last->pos.y;
        p[8] = (last->pos.z - mid.z) + last->pos.z;
        t = 0.0f;
        ang = (r->unk6 & 0x7F) * 360.0 / 128.0;
        for (i = 0; i < 17; i++) {
            u = 1.0 - t;
            a = u * u * 0.5;
            b = u * t + 0.5;
            c = t * t * 0.5;
            for (k = 0; k < 3; k++) {
                v->v.ob[k] = a * p[k] + b * p[k + 3] + c * p[k + 6];
                if (k == 0) {
                    amp = func_800AEAC0(i * 180.0 / 16.0) * (r->unk8 / 3000.0);
                    v->v.ob[0] = v->v.ob[0] + func_800AEAC0(ang) * 100.0 * amp * r->unk10;
                }
            }
            col = 0xFF;
            if (v->v.ob[1] < 1250) {
                k = (1.0 - ((func_800AEAC0(ang) < 0.0f) ? -func_800AEAC0(ang) : func_800AEAC0(ang))) * 127.0;
                if (k < 72) {
                    k = k * 0.25 + 24.0;
                }
                col = k - 128;
            }
            v->v.cn[0] = v->v.cn[1] = col;
            v->v.cn[3] = 0xFF;
            v->v.cn[2] = 0xFF;
            v++;
            t = t + 0.0625;
            ang = ang + 15.0;
            if (i < 16) {
                gSPLine3D((*gfx)++, i, i + 1, 0);
            }
        }
        gDPPipeSync((*gfx)++);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/21FAD0", func_800FE378_DeepSeaDivers);
#endif
void func_800FEA00_DeepSeaDivers(omObjData* obj) {
    s16 i;

    for (i = 0; i < 5; i++) {
        obj->model[i + 1] = func_80023FC8(obj->model[0]);
    }
    func_800258EC(obj->model[2], 4, 4);
    func_800258EC(obj->model[5], 4, 4);
    for (i = 0; i < 2; i++) {
        func_800FED88_DeepSeaDivers(obj, i);
    }
    D_80100C50_DeepSeaDivers = 0;
}
void func_800FEAC4_DeepSeaDivers(s16 idx, s16 dir) {
    if (dir != 0) {
        D_801006D8_DeepSeaDivers[idx].pos.x = 2990.0f;
        D_801006D8_DeepSeaDivers[idx].vx =
            -((f32)(((u32)(func_800FC1F4_DeepSeaDivers() * 5) >> 16) + 8) + D_80100C54_DeepSeaDivers[idx] * 10.0f);
        D_801006D8_DeepSeaDivers[idx].rot.y = 0.0f;
    } else {
        D_801006D8_DeepSeaDivers[idx].pos.x = -2990.0f;
        D_801006D8_DeepSeaDivers[idx].vx =
            (f32)(((u32)(func_800FC1F4_DeepSeaDivers() * 5) >> 16) + 8) + D_80100C54_DeepSeaDivers[idx] * 10.0f;
        D_801006D8_DeepSeaDivers[idx].rot.y = 180.0f;
    }
    D_801006D8_DeepSeaDivers[idx].pos.y = 550.0f - (f32)((u32)(func_800FC1F4_DeepSeaDivers() * 1650) >> 16) - 100.0;
    D_80100C54_DeepSeaDivers[idx] = (f32)(((u32)(func_800FC1F4_DeepSeaDivers() * 3) >> 16) + 5) / 10.0f * 1.5;
    D_801006D8_DeepSeaDivers[idx].pos.z = -50.0 - D_80100C54_DeepSeaDivers[idx] * 50.0;
}
void func_800FED88_DeepSeaDivers(omObjData* obj, s16 idx) {
    s16 j;

    func_800FEAC4_DeepSeaDivers(idx, idx);
    D_801006D8_DeepSeaDivers[idx].rot.x = D_801006D8_DeepSeaDivers[idx].rot.z = 0.0f;
    for (j = 0; j < 10; j++) {
        D_80100758_DeepSeaDivers[idx][j].pos.x = D_801006D8_DeepSeaDivers[idx].pos.x;
        D_80100758_DeepSeaDivers[idx][j].pos.y = D_801006D8_DeepSeaDivers[idx].pos.y;
        D_80100758_DeepSeaDivers[idx][j].pos.z = D_801006D8_DeepSeaDivers[idx].pos.z;
        D_80100758_DeepSeaDivers[idx][j].rot.x = D_801006D8_DeepSeaDivers[idx].rot.x;
        D_80100758_DeepSeaDivers[idx][j].rot.y = D_801006D8_DeepSeaDivers[idx].rot.y;
        D_80100758_DeepSeaDivers[idx][j].rot.z = D_801006D8_DeepSeaDivers[idx].rot.z;
    }
    if ((u32)(func_800FC1F4_DeepSeaDivers() * 2) >> 16) {
        func_800258EC(obj->model[idx * 3 + 2], 4, 0);
    } else {
        func_800258EC(obj->model[idx * 3 + 2], 4, 4);
    }
}
void func_800FEF34_DeepSeaDivers(omObjData* obj) {
    s16 i;
    s16 j;
    s16 k;
    s16 n;

    for (i = 0; i < 2; i++) {
        if ((f32)D_800FFE6C_DeepSeaDivers[i] < D_801006D8_DeepSeaDivers[i].vx) {
            D_800FFE6C_DeepSeaDivers[i]++;
        }
        if ((f32)D_800FFE6C_DeepSeaDivers[i] > D_801006D8_DeepSeaDivers[i].vx) {
            D_800FFE6C_DeepSeaDivers[i]--;
        }
        D_80100758_DeepSeaDivers[i][D_80100C50_DeepSeaDivers].pos.x = D_801006D8_DeepSeaDivers[i].pos.x;
        D_80100758_DeepSeaDivers[i][D_80100C50_DeepSeaDivers].pos.y = D_801006D8_DeepSeaDivers[i].pos.y;
        D_80100758_DeepSeaDivers[i][D_80100C50_DeepSeaDivers].pos.z = D_801006D8_DeepSeaDivers[i].pos.z;
        D_80100758_DeepSeaDivers[i][D_80100C50_DeepSeaDivers].rot.y = D_801006D8_DeepSeaDivers[i].rot.y;
        D_80100758_DeepSeaDivers[i][D_80100C50_DeepSeaDivers].rot.z = D_801006D8_DeepSeaDivers[i].rot.z;
        D_800FFE60_DeepSeaDivers[i] += 2 + ((u32)(func_800FC1F4_DeepSeaDivers() * 3) >> 16);
        if (D_800FFE60_DeepSeaDivers[i] >= 361) {
            D_800FFE60_DeepSeaDivers[i] = 0;
        }
        D_801006D8_DeepSeaDivers[i].pos.x =
            (func_800AEAC0(D_800FFE60_DeepSeaDivers[i]) + 1.0f) * D_801006D8_DeepSeaDivers[i].vx +
            D_801006D8_DeepSeaDivers[i].pos.x;
        if (D_800FFE60_DeepSeaDivers[i] < 180) {
            D_801006D8_DeepSeaDivers[i].pos.y = D_801006D8_DeepSeaDivers[i].pos.y + 3.0f;
        } else {
            D_801006D8_DeepSeaDivers[i].pos.y = D_801006D8_DeepSeaDivers[i].pos.y - 3.0f;
        }
        if ((D_800FFE60_DeepSeaDivers[i] == 180) | (D_800FFE60_DeepSeaDivers[i] == 0)) {
            func_800FC1F4_DeepSeaDivers();
        }
        if (D_801006D8_DeepSeaDivers[i].pos.y > 550.0f) {
            D_801006D8_DeepSeaDivers[i].pos.y = 540.0f;
        } else if (D_801006D8_DeepSeaDivers[i].pos.y < -1200.0f) {
            D_801006D8_DeepSeaDivers[i].pos.y = -1190.0f;
        }
        if (D_801006D8_DeepSeaDivers[i].pos.x > 3000.0f || D_801006D8_DeepSeaDivers[i].pos.x < -3000.0f) {
            func_800FEAC4_DeepSeaDivers(i, (s32)(func_800FC1F4_DeepSeaDivers() * 2) >> 16);
            if (((u32)(func_800FC1F4_DeepSeaDivers() * 2) >> 16) == 0) {
                func_800258EC(obj->model[i * 3 + 2], 4, 0);
            } else {
                func_800258EC(obj->model[i * 3 + 2], 4, 4);
            }
        }
        if (i == 0) {
            obj->scale.x = D_80100C54_DeepSeaDivers[i];
            obj->scale.y = D_80100C54_DeepSeaDivers[i];
            obj->scale.z = D_80100C54_DeepSeaDivers[i];
            obj->rot.x = D_801006D8_DeepSeaDivers[i].rot.x;
            obj->rot.y = D_801006D8_DeepSeaDivers[i].rot.y;
            obj->rot.z = D_801006D8_DeepSeaDivers[i].rot.z;
            obj->trans.x = D_801006D8_DeepSeaDivers[i].pos.x;
            obj->trans.y = D_801006D8_DeepSeaDivers[i].pos.y;
            obj->trans.z = D_801006D8_DeepSeaDivers[i].pos.z;
        } else {
            func_80025830(obj->model[i * 3], D_80100C54_DeepSeaDivers[i], D_80100C54_DeepSeaDivers[i],
                          D_80100C54_DeepSeaDivers[i]);
            func_800257E4(obj->model[i * 3], D_801006D8_DeepSeaDivers[i].rot.x, D_801006D8_DeepSeaDivers[i].rot.y,
                          D_801006D8_DeepSeaDivers[i].rot.z);
            func_80025798(obj->model[i * 3], D_801006D8_DeepSeaDivers[i].pos.x, D_801006D8_DeepSeaDivers[i].pos.y,
                          D_801006D8_DeepSeaDivers[i].pos.z);
        }
    }
    if (++D_80100C50_DeepSeaDivers >= 10) {
        D_80100C50_DeepSeaDivers = 0;
    }
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            k = i + (s16)(j * 3 + 1);
            if (i == 0) {
                n = D_80100C50_DeepSeaDivers - 5;
            } else {
                n = D_80100C50_DeepSeaDivers - 7;
            }
            if (n < 0) {
                n += 10;
            }
            func_80025830(obj->model[k], D_80100C54_DeepSeaDivers[j], D_80100C54_DeepSeaDivers[j],
                          D_80100C54_DeepSeaDivers[j]);
            func_800257E4(obj->model[k], D_80100758_DeepSeaDivers[j][n].rot.x, D_80100758_DeepSeaDivers[j][n].rot.y,
                          D_80100758_DeepSeaDivers[j][n].rot.z);
            if (i == 0) {
                func_80025798(obj->model[k], (f32)(D_800FFE6C_DeepSeaDivers[j] * 3) + D_80100758_DeepSeaDivers[j][n].pos.x,
                              (f32)(D_800FFE6C_DeepSeaDivers[j] * 3) + D_80100758_DeepSeaDivers[j][n].pos.y,
                              (f32)(D_800FFE6C_DeepSeaDivers[j] * 3) + D_80100758_DeepSeaDivers[j][n].pos.z);
            } else {
                func_80025798(obj->model[k], D_80100758_DeepSeaDivers[j][n].pos.x - (f32)(D_800FFE6C_DeepSeaDivers[j] * 3),
                              D_80100758_DeepSeaDivers[j][n].pos.y - (f32)(D_800FFE6C_DeepSeaDivers[j] * 3),
                              D_80100758_DeepSeaDivers[j][n].pos.z - (f32)(D_800FFE6C_DeepSeaDivers[j] * 3));
            }
        }
    }
}
void func_800FF6E0_DeepSeaDivers(omObjData* obj) {
    func_80026040(obj->model[1]);
    D_80100C5C_DeepSeaDivers = 0.0f;
    func_80039C48("dmy_I8", &D_80100C60_DeepSeaDivers);
    D_80100C64_DeepSeaDivers = D_80100C68_DeepSeaDivers = 0.0f;
}
void func_800FF730_DeepSeaDivers(omObjData* obj) {
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16 flip = 0;
    s16 row = 0;
    s16 i;

    m = D_800F2B7C[obj->model[1]].unk_6C;
    D_80100C64_DeepSeaDivers -= 0.1f;
    func_80027E48(obj->model[1], D_80100C64_DeepSeaDivers, D_80100C68_DeepSeaDivers, D_80100C60_DeepSeaDivers[0],
                  D_80100C60_DeepSeaDivers[1], "yura_1_1", 1);
    src = m->unk_04;
    dst = m->unk_08[D_800F37F0];
    for (i = 0; i < m->unk_72; i++) {
        if (!(i & 3)) {
            flip = row ^ 1;
            if (!(i & 4)) {
                flip = row;
            }
        }
        if (flip == 0) {
            dst->unk_00 = src->unk_00 + func_800AEAC0(D_80100C5C_DeepSeaDivers) * 40.0;
        } else {
            dst->unk_00 = src->unk_00 - func_800AEAC0(D_80100C5C_DeepSeaDivers) * 40.0;
        }
        flip ^= 1;
        if ((i + 1) % 40 == 0) {
            row ^= 1;
        }
        src++;
        dst++;
    }
    D_80100C5C_DeepSeaDivers = func_8009B618(D_80100C5C_DeepSeaDivers + 4.0, 360.0);
}
