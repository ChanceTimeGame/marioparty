#include "common.h"

typedef struct HuViewVolume {
    /* 0x00 */ f32 l;
    /* 0x04 */ f32 r;
    /* 0x08 */ f32 b;
    /* 0x0C */ f32 t;
    /* 0x10 */ f32 n;
    /* 0x14 */ f32 f;
    /* 0x18 */ f32 scale;
} HuViewVolume;

/* guFrustumF (Hudson) */
void func_800A2510(Matrix4f mf, HuViewVolume* v) {
    f32 sx;
    f32 sy;
    f32 sz;
    f32 n2;

    sx = v->scale / (v->r - v->l);
    sy = v->scale / (v->t - v->b);
    sz = v->scale / (v->f - v->n);
    n2 = v->n + v->n;
    mf[0][0] = n2 * sx;
    mf[1][1] = n2 * sy;
    mf[2][0] = (v->r + v->l) * sx;
    mf[2][1] = (v->t + v->b) * sy;
    mf[2][2] = -(v->f + v->n) * sz;
    mf[2][3] = -v->scale;
    mf[3][2] = -v->f * n2 * sz;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[3][0] = mf[3][1] = mf[3][3] = 0.0f;
}
