#include "common.h"

typedef struct HuLookAtHiliteArg HuLookAtHiliteArg;
void func_800A1EF0(Matrix4f mf, LookAt* l, Hilite* h, HuLookAtHiliteArg* p);

/* guLookAtHilite */
void func_800A2280(Mtx* m, LookAt* l, Hilite* h, HuLookAtHiliteArg* p) {
    Matrix4f mf;

    func_800A1EF0(mf, l, h, p);
    func_800A0A20(mf, m);
}
