#include "common.h"
#ifdef TARGET_PC
#include "PR/gu.h"
void func_800A2B40(Mtx*); /* SDK-region asm unit A3650 (unprototyped on the N64) */
#endif

unk_Struct00* D_800C3110 = NULL;
/* Per-camera defaults for 1-4 views (InitCameras passes element 0 to every camera). */
Vec3f D_800C3114[5] = { { 640.0f, 480.0f, 511.0f }, { 320.0f, 240.0f, 511.0f }, { 320.0f, 240.0f, 511.0f }, { 320.0f, 240.0f, 511.0f }, { 320.0f, 240.0f, 511.0f } };
Vec3f D_800C3150[5] = { { 640.0f, 480.0f, 511.0f }, { 320.0f, 240.0f, 511.0f }, { 960.0f, 240.0f, 511.0f }, { 320.0f, 720.0f, 511.0f }, { 960.0f, 720.0f, 511.0f } };
Vec4f D_800C318C[5] = { { 0.0f, 0.0f, 320.0f, 240.0f }, { 0.0f, 0.0f, 160.0f, 120.0f }, { 160.0f, 0.0f, 320.0f, 120.0f }, { 0.0f, 120.0f, 160.0f, 240.0f }, { 160.0f, 120.0f, 320.0f, 240.0f } };

void InitCameras(s16 count) {
    s16 j;
    s16 i;

    D_800ECB00 = count;
    D_800F3FA8 = 0;
    if (D_800C3110 != NULL) {
        func_80023728(D_800C3110);
    }
    D_800C3110 = func_80023668(6 * sizeof(*D_800C3110));
    for (i = 0; i < 6; i++) {
        D_800C3110[i].unk_40 = 45.0f;
        D_800C3110[i].unk_44 = 80.0f;
        D_800C3110[i].unk_48 = 8000.0f;
        D_800C3110[i].unk4E = 0;
        func_8001D520(i, &D_800C3114[0], &D_800C3150[0]);
        func_8001D4D4(i, &D_800C318C[0]);
        D_800C3110[i].unkE8 = 0;
        D_800C3110[i].unkF0 = 0;
        D_800C3110[i].unkF4 = 0;
        for (j = 0; j < D_800F37DA; j++) {
            func_800A2B40(&D_800C3110[i].unkF8 + j * 2);
            func_800A2B40(&D_800C3110[i].unkF8 + j * 2 + 1);
        }
    }
    D_800F32A0 = (camera *) D_800C3110;
    D_800F2BCC = &D_800C3110->unkF8;
}

void func_8001D40C() {
    D_800F3FA8 = D_800F37F0;
}

void func_8001D420(s16 index, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->pos = *arg1;
    temp_v0->unkC = *arg2;
    temp_v0->unk18 = *arg3;
}

void func_8001D494(s16 index, f32 arg1, f32 arg2, f32 arg3) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unk_40 = arg1;
    temp_v0->unk_44 = arg2;
    temp_v0->unk_48 = arg3;
    temp_v0->unk4C = 1;
}

void func_8001D4D4(s16 index, Vec4f* arg1) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unkD8.x = arg1->x;
    temp_v0->unkD8.y = arg1->y;
    temp_v0->unkD8.z = arg1->z;
    temp_v0->unkD8.w = arg1->w;
}

void func_8001D520(s16 index, Vec3f* arg1, Vec3f* arg2) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unk24 = *arg1;
    temp_v0->unk30 = *arg2;
}

void func_8001D57C(s16 index) {
    unk_Struct00* temp_s0;
    Mtx* temp_s1;

    temp_s0 = &D_800C3110[index];
    temp_s1 = &temp_s0->unkF8 + (D_800F3FA8 << 1);
    guPerspective(temp_s1, &temp_s0->unk4C, temp_s0->unk_40, (4.0f / 3.0f), temp_s0->unk_44, temp_s0->unk_48, 1.0f);
    guLookAt(temp_s1 + 0x1, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
}

void func_8001D658(s16 index, Gfx** gfx) {
    unk_Struct00* temp_v1;
    unk_Struct00* temp_a0;
    Mtx* temp_s1;

    temp_v1 = &D_800C3110[index];
    temp_s1 = &temp_v1->unkF8 + (D_800F3FA8 * 2);
    temp_a0 = (void*) temp_v1 + (D_800F3FA8 * 16);
    temp_a0->unk58 = temp_v1->unk24.x;
    temp_a0->unk5A = temp_v1->unk24.y;
    temp_a0->unk5C = temp_v1->unk24.z;
    temp_a0->unk60 = temp_v1->unk30.x;
    temp_a0->unk62 = temp_v1->unk30.y;
    temp_a0->unk64 = temp_v1->unk30.z;

#ifdef TARGET_PC
    if (pb_interp_fold_viewport() && index >= 0 && index < 6) {
        /* Frame interpolation: the boards scroll by moving the viewport, which RT64 cannot
           interpolate. Draw through a viewport centred on the camera's scissor rectangle and
           shift the projection by the difference instead (clip x += ofs * w), which RT64
           interpolates. The camera's own Vp and Mtx are left as retail wrote them: 65770.c
           reads them. The board's "where is the star" pan scrolls several viewport widths: an
           offset limit of one width put part of the pan on the retail path (30 fps, and a
           projection jump each time it switched), so only absurd offsets keep it now. */
        static Vp pbVp[6][2];
        static Mtx pbProj[6][2];
        f32 ofsX = (temp_a0->unk60 - (temp_v1->unkD8.x + temp_v1->unkD8.z) * 2.0f) / (f32) temp_a0->unk58;
        f32 ofsY = -(temp_a0->unk62 - (temp_v1->unkD8.y + temp_v1->unkD8.w) * 2.0f) / (f32) temp_a0->unk5A;
        if (temp_a0->unk58 != 0 && temp_a0->unk5A != 0 && fabsf(ofsX) <= 64.0f && fabsf(ofsY) <= 64.0f) {
            Vp* vp = &pbVp[index][D_800F3FA8 & 1];
            Mtx* proj = &pbProj[index][D_800F3FA8 & 1];
            f32 mf[4][4];
            s32 r;

            vp->vp.vscale[0] = temp_a0->unk58;
            vp->vp.vscale[1] = temp_a0->unk5A;
            vp->vp.vscale[2] = temp_a0->unk5C;
            vp->vp.vscale[3] = 0;
            vp->vp.vtrans[0] = (s16) ((temp_v1->unkD8.x + temp_v1->unkD8.z) * 2.0f);
            vp->vp.vtrans[1] = (s16) ((temp_v1->unkD8.y + temp_v1->unkD8.w) * 2.0f);
            vp->vp.vtrans[2] = temp_a0->unk64;
            vp->vp.vtrans[3] = 0;
            /* the rounding of the centre goes into the offset too */
            ofsX = (temp_a0->unk60 - vp->vp.vtrans[0]) / (f32) temp_a0->unk58;
            ofsY = -(temp_a0->unk62 - vp->vp.vtrans[1]) / (f32) temp_a0->unk5A;
            guMtxL2F(mf, temp_s1);
            for (r = 0; r < 4; r++) {
                mf[r][0] += ofsX * mf[r][3];
                mf[r][1] += ofsY * mf[r][3];
            }
            guMtxF2L(mf, proj);
            gSPViewport((*gfx)++, vp);
            gSPPerspNormalize((*gfx)++, temp_v1->unk4C);
            gSPMatrix((*gfx)++, osVirtualToPhysical(proj), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gSPMatrix((*gfx)++, osVirtualToPhysical(temp_s1 + 1), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            return;
        }
    }
#endif
    gSPViewport((*gfx)++, &temp_v1->unk58 + (D_800F3FA8 * 8));
    gSPPerspNormalize((*gfx)++, temp_v1->unk4C);
    gSPMatrix((*gfx)++, osVirtualToPhysical(temp_s1), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
#ifdef TARGET_PC
    /* Retail adds 0x80000040: KSEG0 + 0x80000000 wraps to the physical address on the N64, and
       0x40 is the next Mtx. A host pointer does not wrap. */
    gSPMatrix((*gfx)++, osVirtualToPhysical(temp_s1 + 1), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
#else
    gSPMatrix((*gfx)++, (void*) temp_s1 + 0x80000040, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
#endif
}


void func_8001D7DC(s16 index, Gfx** gfx) {
    unk_Struct00* temp_a2;

    temp_a2 = &D_800C3110[index];
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, temp_a2->unkD8.x, temp_a2->unkD8.y, temp_a2->unkD8.z, temp_a2->unkD8.w);
}

void func_8001D8A0(s16 index, PB_PTR32 arg1, PB_PTR32 arg2) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unkE8 = arg1;
    temp_v0->unkEC = arg2;
}

void func_8001D8D4(s16 index, PB_PTR32 arg1) {
    D_800C3110[index].unkF0 = arg1;
}

void func_8001D904(s16 index, PB_PTR32 arg1) {
    D_800C3110[index].unkF4 = arg1;
}

void Convert3DTo2D(s16 index, Vec3f* arg1, Vec2f* arg2) {
    Matrix4f sp28;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f30;
    unk_Struct00* temp_s0;

    temp_s0 = &D_800C3110[index];
    HuGuLookAtF(sp28, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
    temp_f30 = arg1->x;
    temp_f28 = arg1->y;
    temp_f2 = arg1->z;
    temp_f30 -= temp_s0->pos.x;
    temp_f28 -= temp_s0->pos.y;
    temp_f2 -= temp_s0->pos.z;
    temp_f24 = ((temp_f30 * sp28[0][0]) + (temp_f28 * sp28[1][0])) + (temp_f2 * sp28[2][0]);
    temp_f22 = ((temp_f30 * sp28[0][1]) + (temp_f28 * sp28[1][1])) + (temp_f2 * sp28[2][1]);
    temp_f20 = ((temp_f30 * sp28[0][2]) + (temp_f28 * sp28[1][2])) + (temp_f2 * sp28[2][2]);
    temp_f30 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * temp_f20 * (4.0f / 3.0f);
    temp_f28 = (func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f)) * temp_f20;
    arg2->x = (temp_f24 * (160.0f / (-temp_f30))) + 160.0f;
    arg2->y = ((temp_f22 * (120.0f / temp_f28)) + 120.0f);
}

void func_8001DB2C(s16 index, Vec3f* arg1, Vec2f* arg2) {
    Matrix4f sp28;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f30;
    f32 temp_f2;
    f32 temp_f2_2;
    unk_Struct00* temp_s0;

    temp_s0 = &D_800C3110[index];
    HuGuLookAtF(sp28, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
    temp_f30 = arg1->x;
    temp_f28 = arg1->y;
    temp_f2 = arg1->z;
    temp_f30 -= temp_s0->pos.x;
    temp_f28 -= temp_s0->pos.y;
    temp_f2 -= temp_s0->pos.z;
    temp_f24 = (temp_f30 * sp28[0][0]) + (temp_f28 * sp28[1][0]) + (temp_f2 * sp28[2][0]);
    temp_f22 = (temp_f30 * sp28[0][1]) + (temp_f28 * sp28[1][1]) + (temp_f2 * sp28[2][1]);
    temp_f20 = (temp_f30 * sp28[0][2]) + (temp_f28 * sp28[1][2]) + (temp_f2 * sp28[2][2]);
    temp_f30 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * temp_f20 * (temp_s0->unk24.x / temp_s0->unk24.y);
    temp_f28 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * temp_f20;
    temp_f2_2 = temp_s0->unk30.x / 4.0f;
    arg2->x = temp_f24 * (temp_f2_2 / -temp_f30) + temp_f2_2;
    temp_f0 = temp_s0->unk30.y / 4.0f;
    arg2->y = temp_f22 * (temp_f0 / temp_f28) + temp_f0;
}

void func_8001DD24(s16 index, f32 arg1, Vec3f* arg2, Vec3f* arg3) {
    Matrix4f sp28;
    f32 temp_f20;
    f32 temp_f4;
    f32 unk_var1;
    f32 unk_var2;
    unk_Struct00* temp_s0;

    temp_s0 = &D_800C3110[index];
    HuGuLookAtF(sp28, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
    temp_f20 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * arg1;
    temp_f4 = temp_f20 * (4.0f / 3.0f);
    unk_var1 = arg2->x / 320.0f;
    unk_var2 = (240.0f - arg2->y) / 240.0f;
    arg3->x = 2.0f * temp_f4 * unk_var1 - temp_f4;
    arg3->y = 2.0f * temp_f20 * unk_var2 - temp_f20;
}
