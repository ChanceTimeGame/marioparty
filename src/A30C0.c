#include "common.h"

typedef struct HuViewVolume HuViewVolume;
void func_800A22E0(Matrix4f mf, HuViewVolume* v);

/* guOrtho */
void func_800A24C0(Mtx* m, HuViewVolume* v) {
    Matrix4f mf;

    func_800A22E0(mf, v);
    func_800A0A20(mf, m);
}
