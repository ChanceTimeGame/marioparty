#include "common.h"

void func_800A18F0(Matrix4f mf, Vec3f* p, Vec3f* tmp);

/* guLookAt */
void func_800A1DF0(Mtx* m, Vec3f* p) {
    Matrix4f mf;
    Vec3f tmp[3];

    func_800A18F0(mf, p, tmp);
    func_800A0A20(mf, m);
}
