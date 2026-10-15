#include "common.h"

/* guLookAtHiliteF's arguments as one block: eye/at/up, two light directions, texture size */
typedef struct HuLookAtHiliteArg {
    /* 0x00 */ Vec3f v[3];
    /* 0x24 */ Vec3f l1;
    /* 0x30 */ Vec3f l2;
    /* 0x3C */ s32 tw;
    /* 0x40 */ s32 th;
} HuLookAtHiliteArg;
void func_800A1BD0(Matrix4f mf, LookAt* l, Vec3f* p, Vec3f* tmp);
f32 Vec3SqDistance(Vec3f*);
void func_800A0F70(Vec3f* out, Vec3f* a, f32 s, Vec3f* b);
f32 func_800A1480(Vec3f*, Vec3f*);

/* guLookAtHiliteF (Hudson) */
void func_800A1EF0(Matrix4f mf, LookAt* l, Hilite* h, HuLookAtHiliteArg* p) {
    Vec3f tmp[3];
    Vec3f hv;
    f32 len;

    func_800A1BD0(mf, l, p->v, tmp);
    len = func_800A1200(&p->l1);
    func_800A0F70(&hv, &tmp[2], 1.0f / len, &p->l1);
    len = Vec3SqDistance(&hv);
    if (len > 0.01f) {
        func_800A0F00(&hv, 1.0f / func_800B1750(len), &hv);
        h->h.x1 = 2.0f * ((func_800A1480(&hv, &tmp[0]) + 2.0f) * p->tw);
        h->h.y1 = 2.0f * ((func_800A1480(&hv, &tmp[1]) + 2.0f) * p->th);
    } else {
        h->h.x1 = 2.0f * p->tw;
        h->h.y1 = 2.0f * p->th;
    }
    len = func_800A1200(&p->l2);
    func_800A0F70(&hv, &tmp[2], 1.0f / len, &p->l2);
    len = Vec3SqDistance(&hv);
    if (len > 0.01f) {
        func_800A0F00(&hv, 1.0f / func_800B1750(len), &hv);
        h->h.x2 = 2.0f * ((func_800A1480(&hv, &tmp[0]) + 2.0f) * p->tw);
        h->h.y2 = 2.0f * ((func_800A1480(&hv, &tmp[1]) + 2.0f) * p->th);
    } else {
        h->h.x2 = 2.0f * p->tw;
        h->h.y2 = 2.0f * p->th;
    }
}
