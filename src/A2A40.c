#include "common.h"

void func_800A1BD0(Matrix4f mf, LookAt* l, Vec3f* p, Vec3f* tmp);

void func_800A1E40(Matrix4f mf, LookAt* l, Vec3f* p) {
    Vec3f tmp[3];

    func_800A1BD0(mf, l, p, tmp);
}
