#include "common.h"

void func_800A1BD0(Matrix4f mf, LookAt* l, Vec3f* p, Vec3f* tmp);

/* guLookAtReflect */
void func_800A1E90(Mtx* m, LookAt* l, Vec3f* p) {
    Matrix4f mf;
    Vec3f tmp[3];

    func_800A1BD0(mf, l, p, tmp);
    func_800A0A20(mf, m);
}
