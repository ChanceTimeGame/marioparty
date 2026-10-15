#include "common.h"

typedef struct HuViewVolume HuViewVolume;
void func_800A2510(Matrix4f mf, HuViewVolume* v);

/* guFrustum */
void func_800A2720(Mtx* m, HuViewVolume* v) {
    Matrix4f mf;

    func_800A2510(mf, v);
    func_800A0A20(mf, m);
}
