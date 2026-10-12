#include "common.h"

void func_800F6DB8_BalloonBurst(omObjData *, s32, s32);
void func_800F7298_BalloonBurst(omObjData *);
void func_800F6D14_BalloonBurst(omObjData *);
void func_80027E48(s16, f32, f32, u16, u16, char *, u8);

extern Gfx **D_800FB0F8_BalloonBurst[];
extern s16 D_800F3778;
extern s16 D_800FB10C_BalloonBurst;
extern u16 D_800FB10E_BalloonBurst;
extern u8 D_800FAF79_BalloonBurst[];
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
extern u16 D_800FC3A2_BalloonBurst[];
extern u8 D_800F64F8;
extern u16 D_800FB54E_BalloonBurst[];
extern u16 D_800FB550_BalloonBurst[];
extern unk34D80Struct80 *D_800ED554;

void func_800396B0(s16, u8);

typedef struct BalloonBurstObstacle {
    char unk_00[0x3E];
    s16 model;
    char unk_40[2];
    s16 secondary_model;
    s32 unk_44;
    char unk_48[8];
    f32 unk_50;
    char unk_54[0x1E];
    s16 unk_72;
    char unk_74[0x34];
} BalloonBurstObstacle;

typedef struct BalloonBurstPlayer {
    BalloonBurstObstacle obstacles[7];
} BalloonBurstPlayer;

typedef struct BalloonBurstObjectWork {
    char unk_00[3];
    s8 player_index;
    char unk_04[8];
    f32 unk_0C;
    f32 unk_10;
    char unk_14[2];
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    u16 unk_22;
} BalloonBurstObjectWork;

extern BalloonBurstPlayer D_800FB120_BalloonBurst[];

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

void func_800F6C44_BalloonBurst(omObjData *arg0) {
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    arg0->model[0] = LoadFormFile(0x250000, 0x299);
    func_80039C48("sora1_DEF", D_800FC3A2_BalloonBurst);
    func_80026040(arg0->model[0]);
    arg0->func_ptr = func_800F6D14_BalloonBurst;
}

void func_800F6D14_BalloonBurst(omObjData *arg0) {
    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0) {
        D_800FC3A8_BalloonBurst -= 0.1f;
    }
    func_80027E48(arg0->model[0], D_800FC3A8_BalloonBurst, D_800FC3AC_BalloonBurst,
                 D_800FC3A2_BalloonBurst[0], D_800FC3A2_BalloonBurst[1], "24m_000A-grid2", 1);
}

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

void func_800F7D9C_BalloonBurst(u16 arg0) {
    BalloonBurstPlayer *player = &D_800FB120_BalloonBurst[arg0];
    s32 i;

    for (i = 0; i < 7; i++) {
        func_800258EC(((BalloonBurstObstacle *)(i * sizeof(BalloonBurstObstacle) + (u8 *)player))->model, 4, 4);
    }
    func_800258EC(player->obstacles[6].secondary_model, 4, 4);
}

void func_800F7E38_BalloonBurst(omObjData *arg0, s8 player_index) {
    BalloonBurstObjectWork *work = arg0->unk_50;
    unk_ovl_2D_struct *model;
    BalloonBurstPlayer *player;
    f32 frame;

    work->player_index = player_index;
    model = &D_800F2B7C[arg0->model[0]];
    model->unk_0A |= 3;
    frame = D_800ED554[model->unk_08].unk_02 - 1.0f;
    work->unk_10 = frame;
    work->unk_0C = frame;
    func_80025798(arg0->model[1], arg0->trans.x, 0.0f, arg0->trans.z);
    func_80025830(arg0->model[1], 0.5f, 0.5f, 0.5f);
    player = &D_800FB120_BalloonBurst[(u8)player_index];
    player->obstacles[0].unk_50 = 5.0f;
    work->unk_0C = 0.0f;
    player->obstacles[0].unk_44 = 0;
    func_800396B0(player->obstacles[0].unk_72,
                  D_800FAF79_BalloonBurst[(s32)(player->obstacles[0].unk_50 / 1.6666666f) * 2]);
}

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

void func_800FA8A4_BalloonBurst(s32 arg0) {
    s32 offset = (arg0 & 0xFFFF) * 0x498;
    u16 model = *(u16 *)((u8 *)D_800FB54E_BalloonBurst + offset);
    u16 copy = *(u16 *)((u8 *)D_800FB550_BalloonBurst + offset);
    unk_ovl_2D_struct *src = &D_800F2B7C[model];

    func_800258EC((s16)model, 4, 4);
    func_80025798((s16)copy, src->unk_24, src->unk_28, src->unk_2C);
    func_800257E4((s16)copy, src->unk_30, src->unk_34, src->unk_38);
    func_80025830((s16)copy, src->unk_3C, src->unk_40, src->unk_44);
    D_800F2B7C[copy].unk_48 = src->unk_48;
    func_800258EC((s16)copy, 4, 0);
    func_80025830((s16)copy, 1.5f, 1.5f, 1.5f);
}

void func_800FA9C4_BalloonBurst(f32 arg0, Vec3f *arg1) {
    f32 angle = arg0 * 2.0f;

    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    arg1->x = func_800AEAC0(arg0) * 160.0f;
    arg1->z = func_800AEFD0(arg0) * 160.0f;
    arg1->y = func_800AEAC0(angle) * 50.0f;
}

void func_800FAA6C_BalloonBurst(omObjData *arg0, u16 *arg1, s16 *arg2) {
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u16 var_v0;
    BalloonBurstObjectWork *temp_s0;

    temp_s0 = arg0->unk_50;
    *arg1 = 0;
    *arg2 = 0;
    if (temp_s0->unk_1E == 0) {
        temp_s0->unk_1E = temp_s0->unk_16 + ((s32)(rand8() & 0xFF) % (s32)temp_s0->unk_18);
    }
    temp_v1 = temp_s0->unk_1C;
    if (temp_v1 & 4) {
        if (temp_s0->unk_22 == 0) {
            temp_s0->unk_1C = temp_v1 & 0xFFFB;
            return;
        }
        temp_s0->unk_22--;
        return;
    }
    if ((temp_s0->unk_20 < temp_s0->unk_1E) && !(temp_s0->unk_1C & 1)) {
        *arg1 |= 0x2000;
        temp_s0->unk_1C |= 2;
        var_v0 = temp_s0->unk_20 + 1;
        goto block_20;
    }
    if (temp_s0->unk_20 == temp_s0->unk_1E) {
        temp_v1_2 = temp_s0->unk_1C;
        if (temp_v1_2 & 2) {
            temp_s0->unk_1C = (temp_v1_2 & 0xFFFD) | 1;
            goto block_15;
        }
    }
    if (temp_s0->unk_20 == 0) {
        temp_v1_3 = temp_s0->unk_1C;
        if (temp_v1_3 & 1) {
            temp_s0->unk_1C = temp_v1_3 & 0xFFFE;
            temp_s0->unk_1E = temp_s0->unk_16 + ((s32)(rand8() & 0xFF) % (s32)temp_s0->unk_18);
block_15:
            if (temp_s0->unk_1A >= 2U) {
                temp_s0->unk_22 = (s32)(rand8() & 0xFF) % (s32)temp_s0->unk_1A;
                temp_s0->unk_1C |= 4;
            }
        } else if (temp_s0->unk_20 != 0) {
            goto block_18;
        }
    } else {
block_18:
        if (temp_s0->unk_1C & 1) {
            *arg1 |= 0x8000;
            var_v0 = temp_s0->unk_20 - 1;
block_20:
            temp_s0->unk_20 = var_v0;
        }
    }
}
