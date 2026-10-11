#include "common.h"

void func_800F6DB8_BalloonBurst(omObjData *, s32, s32);
void func_800F7298_BalloonBurst(omObjData *);

extern Gfx **D_800FB0F8_BalloonBurst[];
extern s16 D_800F3778;
extern s16 D_800FB10C_BalloonBurst;
extern u16 D_800FB10E_BalloonBurst;
extern u16 D_800FC386_BalloonBurst;
extern f32 D_800FC380_BalloonBurst;
extern s16 D_800FC384_BalloonBurst;
extern s16 D_800FC388_BalloonBurst;
extern s16 D_800FC38A_BalloonBurst;
extern s16 D_800FC38C_BalloonBurst;
extern s16 D_800FC38E_BalloonBurst;
extern s16 D_800FC3A0_BalloonBurst;
extern volatile f32 D_800FC3A8_BalloonBurst;
extern volatile f32 D_800FC3AC_BalloonBurst;
extern s32 D_800FC3B0_BalloonBurst;
extern s32 D_800FC3B4_BalloonBurst;

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFA0_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFAC_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFB8_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFC4_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFD0_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFDC_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFE8_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FAFF4_BalloonBurst);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", D_800FB000_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F65E0_BalloonBurst);

void func_800F6BAC_BalloonBurst(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 centerX, f32 centerY, f32 centerZ) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = centerX;
    Center.y = centerY;
    Center.z = centerZ;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F6C44_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F6D14_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F6DB8_BalloonBurst);

void func_800F70E0_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 0, 0);
}

void func_800F7100_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 1, 1);
}

void func_800F7120_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 2, 2);
}

void func_800F7140_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 3, 3);
}

void func_800F7160_BalloonBurst(void) {
    s32 i;

    for (i = 0; i < D_800F3778; i++) {
        if (D_800F5144 == 1) {
            D_800F5144 = 0;
            func_800601D4(0x28);
            omOvlReturnEx(1);
        }
    }
}

void func_800F71D8_BalloonBurst(omObjData *arg0) {
    f32 zero;

    D_800FB10C_BalloonBurst = 0;
    D_800FB10E_BalloonBurst = 0;
    D_800FC384_BalloonBurst = 0;
    D_800FC380_BalloonBurst = 2200.0725f;
    D_800FC386_BalloonBurst = 0x1E;
    D_800FC388_BalloonBurst = 0x1E;
    zero = 0.0f;
    D_800FC3AC_BalloonBurst = zero;
    D_800FC3A8_BalloonBurst = zero;
    D_800FC38A_BalloonBurst = 0;
    D_800FC38C_BalloonBurst = 0;
    D_800FC38E_BalloonBurst = -1;
    D_800FC3B4_BalloonBurst = 0;
    D_800FC3B0_BalloonBurst = 0;
    D_800FC3A0_BalloonBurst = InitSprite(0x25000A);
    arg0->func_ptr = func_800F7298_BalloonBurst;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F7298_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F77D0_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F7D9C_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F7E38_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F7F94_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F8670_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F8D6C_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F9368_BalloonBurst);

void func_800F94E0_BalloonBurst(s16 arg0, s16 arg1) {
    D_800F2B7C[arg0].unk_6C->unk_00 = D_800FB0F8_BalloonBurst[arg1];
}

void func_800F9520_BalloonBurst(omObjData *arg0) {
    switch (D_800FB10E_BalloonBurst) {
        case 0:
            if (func_80072718() == 0) {
                D_800FB10E_BalloonBurst = 1;
                func_80060128(0x26);
            }
            break;
        case 1:
            D_800FB10E_BalloonBurst = 2;
            GMesCreate(0);
            break;
        case 2:
            if (GMesStatAllGet() == 0) {
                D_800FB10C_BalloonBurst = 1;
                omDelObj(arg0);
                GMesCreate(8, D_800FC386_BalloonBurst, 0xA0, 0x20);
            }
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F95F8_BalloonBurst);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800FA8A4_BalloonBurst);

void func_800FA9C4_BalloonBurst(f32 arg0, Vec3f *arg1) {
    f32 angle = arg0 * 2.0f;

    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    arg1->x = func_800AEAC0(arg0) * 160.0f;
    arg1->z = func_800AEFD0(arg0) * 160.0f;
    arg1->y = func_800AEAC0(angle) * 50.0f;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800FAA6C_BalloonBurst);
