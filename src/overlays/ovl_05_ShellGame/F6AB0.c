#include "common.h"
#include "ShellGame.h"

/* .data (0x800FEC10..0x800FEC40) */
u32 D_800FEC10_ShellGame = 0x19971204;
s16 D_800FEC14_ShellGame = 1;
s16 D_800FEC16_ShellGame = 0;
s16 D_800FEC18_ShellGame = 0;
f32 D_800FEC1C_ShellGame = 0.0f;
s16 D_800FEC20_ShellGame = 0;
s16 D_800FEC22_ShellGame = 0;
s16 D_800FEC24_ShellGame = 0;
s16 D_800FEC26_ShellGame = 0;
s16 D_800FEC28_ShellGame = 0;
s16 D_800FEC2A_ShellGame = 1;
s16 D_800FEC2C_ShellGame = 0;
s16 D_800FEC2E_ShellGame = 0;
s16 D_800FEC30_ShellGame = 0;
s16 D_800FEC32_ShellGame = 0;
s32 D_800FEC34_ShellGame = 0;
f32 D_800FEC38_ShellGame = 0.0f;
f32 D_800FEC3C_ShellGame = 0.0f;

void func_800F65E0_ShellGame(void) {
    unk_Struct00* cam;
    s32 temp_s0;

    func_80029090(50);
    omInitObjMan(50, 0);
    func_80060088();
    func_8001DE70(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800234B8(0, 0xA0, 0x78, 0x78);
    func_800234B8(1, 0xFF, 0xA8, 0xA8);
    func_80023504(1, -96.0f, 100.0f, 26.0f);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 4000.0f);
    func_800F7034_ShellGame();
    func_800F720C_ShellGame(rand8());
    func_800F7550_ShellGame();
    func_800F828C_ShellGame();
    func_800F87CC_ShellGame();
    cam = D_800C3110;
    D_800FF168_ShellGame = func_800AEAC0(cam->unk_40 / 2.0) / func_800AEFD0(cam->unk_40 / 2.0);
    guMtxL2F(D_800FF128_ShellGame, &cam->unk_138);
    func_80028510(0x3A5, 0x402, 0xFF, 0xC8, 0xC8);
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800EE984 = 0;
    D_800FF0F8_ShellGame = omAddObj(0x20, 0, 0, -1, &func_800F689C_ShellGame);
    D_800FF9EC_ShellGame = 0;
    D_800FFA3C_ShellGame = 0;
    D_800FF10C_ShellGame = 0x14A;
    D_800FEC14_ShellGame = 1;
    D_800FF780_ShellGame = 0;
    D_800FF782_ShellGame = 0;
    D_800FEC16_ShellGame = 0;
    D_800FEC18_ShellGame = 0;
    D_800FEC1C_ShellGame = 0;
    D_800FF784_ShellGame = 0;
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
    func_8007B168((u8*)"\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1);
    func_8007B168((u8*)"\x82\x73\x82\x68\x82\x6C\x82\x64\x82\x74\x82\x6F", 1);
}

void func_800F689C_ShellGame(omObjData* arg0) {
    arg0->func_ptr = &func_800F68E8_ShellGame;
    func_800F9618_ShellGame();
    func_800F9738_ShellGame();
    func_800F915C_ShellGame();
    if (_CheckFlag(0x2B) != 0) {
        D_800FF784_ShellGame = 1;
    }
}

void func_800F68E8_ShellGame(omObjData* arg0) {
    func_800F76C4_ShellGame();
    func_800F85B4_ShellGame();
    func_800F8CF8_ShellGame();
    func_800F7BDC_ShellGame();
    func_800F6A98_ShellGame(arg0);

    if (D_800FEC16_ShellGame == 1) {
        if (D_800ED430 == D_800FEC16_ShellGame) {
            if ((func_800F8154_ShellGame()) == 0) {
                if (D_800F3FB0[0]->trans.y == 0.0f) {
                    D_800FF10C_ShellGame = 0;
                    D_800FFA3C_ShellGame = 0;
                    D_800FEC16_ShellGame = 0;
                    D_800FEC14_ShellGame = 0;
                    if (D_800FF784_ShellGame == 0) {
                        D_800FF0F8_ShellGame->func_ptr = &func_800F6AC0_ShellGame;
                    } else {
                        func_800601D4(0x28);
                        D_800FF0F8_ShellGame->func_ptr = &func_800F6EE4_ShellGame;
                    }
                    D_800FF9D0_ShellGame.unk6 = 5;
                    D_800ED430 = 0;
                    D_800FF780_ShellGame = 1;
                    D_800ED430 = 0;
                }
            }
        }
    }
}

void func_800F6A14_ShellGame(omObjData* arg0) {
    u16 i;

    func_800F87AC_ShellGame();
    func_800F913C_ShellGame();
    func_80060198();

    for (i = 0; i < D_800F37DA; i++) {
        HuMemDirectFree(D_800FF718_ShellGame[i]);
    }

    omOvlReturnEx(1);
}

void func_800F6A98_ShellGame(omObjData* arg0) {
    if (D_800F5144 == 1) {
        arg0->func_ptr = &func_800F6A14_ShellGame;
    }
}

// NON_MATCHING: register allocation of two timer compares (masked 0)
#ifdef NON_MATCHING
void func_800F6AC0_ShellGame(omObjData* arg0) {
    s16 winSe[6] = { 0x451, 0x452, 0x453, 0x454, 0x455, 0x456 };
    s16 loseSe[6] = { 0x44A, 0x44B, 0x44C, 0x44D, 0x44E, 0x44F };
    f32 t;
    s32 mes;
    s32 ok;

    func_800F76C4_ShellGame();
    func_800F85B4_ShellGame();
    func_800F8CF8_ShellGame();
    func_800F7BDC_ShellGame();
    func_800F6A98_ShellGame(arg0);
    if (D_800FEC24_ShellGame != 0) {
        if (D_800FF9D0_ShellGame.unk6 == 5) {
            t = D_800FEC26_ShellGame / 45.0;
        } else {
            t = D_800FEC26_ShellGame / 30.0;
        }
        if (t > 1.0) {
            t = 1.0f;
            D_800FEC24_ShellGame = 0;
        }
        func_800F7098_ShellGame(t);
        D_800FEC26_ShellGame++;
    }
    switch (D_800FEC20_ShellGame) {
    case 0:
        if (++D_800FEC22_ShellGame >= 0) {
            mes = 0x10;
            if (D_800FF780_ShellGame == 0 && (mes = 0xE, D_800FF9D0_ShellGame.unk6 != 5)) {
                GMesCreate(2);
            } else {
                GMesCreate(mes);
                GwPlayer[D_800FF9F0_ShellGame].coins_mg -= 5;
            }
            D_800FEC22_ShellGame = 0;
            D_800FEC20_ShellGame = 1;
        }
        break;
    case 1:
        if (++D_800FEC22_ShellGame >= 0 && GMesStatAllGet() == 2) {
            func_80060128(D_800FF9D0_ShellGame.unk6 != 5 ? 0x33 : 0x34);
            D_800FEC22_ShellGame = 0;
            D_800FEC20_ShellGame = 2;
            D_800FEC24_ShellGame = 1;
        }
        break;
    case 2:
        if (++D_800FEC22_ShellGame >= 0) {
            if (D_800FF9D0_ShellGame.unk6 != 5) {
                D_800FFA3C_ShellGame = 0x309;
            } else {
                D_800FFA3C_ShellGame = 0x14D;
            }
            D_800FF9EC_ShellGame = 4;
            D_800FEC22_ShellGame = 0;
            D_800FEC20_ShellGame = 3;
        }
        break;
    case 3:
        D_800FEC22_ShellGame++;
        if (D_800FF9D0_ShellGame.unk6 != 5) {
            ok = 35 < D_800FEC22_ShellGame;
        } else {
            ok = D_800FEC22_ShellGame >= 18;
        }
        if (ok) {
            if (D_800FF9D0_ShellGame.unk6 != 5) {
                PlaySound(winSe[D_800FFA0C_ShellGame]);
            } else {
                PlaySound(loseSe[D_800FFA0C_ShellGame]);
            }
            D_800FEC22_ShellGame = 0;
            D_800FEC20_ShellGame = 4;
        }
        break;
    case 4:
        D_800FEC22_ShellGame++;
        if (D_800FF9D0_ShellGame.unk6 != 5) {
            ok = 56 < D_800FEC22_ShellGame;
        } else {
            ok = D_800FEC22_ShellGame >= 72;
        }
        if (ok && GMesWait() != 1) {
            func_800726AC(0, 20);
            func_800601D4(0x28);
            arg0->func_ptr = &func_800F6FFC_ShellGame;
            D_800FEC22_ShellGame = 0;
            D_800FEC20_ShellGame = 5;
        }
        break;
    }
}
#else
const s16 D_800FEC98_ShellGame[6] __attribute__((section(".rodata"))) = { 0x451, 0x452, 0x453, 0x454, 0x455, 0x456 };
const s16 D_800FECA4_ShellGame[6] __attribute__((section(".rodata"))) = { 0x44A, 0x44B, 0x44C, 0x44D, 0x44E, 0x44F };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F6AC0_ShellGame);
#endif

void func_800F6EE4_ShellGame(omObjData* arg0) {
    func_800F76C4_ShellGame();
    func_800F85B4_ShellGame();
    func_800F8CF8_ShellGame();
    func_800F7BDC_ShellGame();
    func_800F6A98_ShellGame(arg0);
    switch (D_800FEC28_ShellGame) {
    case 0:
        GMesCreate(2);
        if (D_800FF780_ShellGame != 0 || D_800FF9D0_ShellGame.unk6 == 5) {
            GwPlayer[D_800FF9F0_ShellGame].coins_mg -= 5;
        }
        D_800FEC28_ShellGame++;
        break;
    case 1:
        if (GMesStatAllGet() == 2) {
            D_800FEC28_ShellGame++;
        }
        break;
    default:
        if (GMesWait() == 0) {
            func_800726AC(0, 20);
            func_80060398(0x28);
            arg0->func_ptr = &func_800F6FFC_ShellGame;
        }
        break;
    }
}
void func_800F6FFC_ShellGame(omObjData* arg0) {
    if (func_80072718() == 0) {
        arg0->func_ptr = &func_800F6A14_ShellGame;
    }
}

void func_800F7034_ShellGame(void) {
    CRot.x = -34.26f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = -5.5f;
    Center.y = -81.0f;
    Center.z = 0.0f;
    CZoom = 1328.0f;
}

void func_800F7098_ShellGame(f32 arg0) {
    omObjData* temp_a0;

    if (arg0 == 0.0) {
        temp_a0 = D_800F3FB0[0];
        D_800FF0A0_ShellGame.x = Center.x;
        D_800FF0A0_ShellGame.y = Center.y;
        D_800FF0A0_ShellGame.z = Center.z;
        D_800FF0AC_ShellGame.x = temp_a0->trans.x;
        D_800FF0AC_ShellGame.y = temp_a0->trans.y;
        D_800FF0AC_ShellGame.z = temp_a0->trans.z;
        return;
    }
    Center.x = D_800FF0A0_ShellGame.x + (arg0 * (D_800FF0AC_ShellGame.x - D_800FF0A0_ShellGame.x));
    Center.y = D_800FF0A0_ShellGame.y + (arg0 * (D_800FF0AC_ShellGame.y - D_800FF0A0_ShellGame.y));
    Center.z = D_800FF0A0_ShellGame.z + (arg0 * (D_800FF0AC_ShellGame.z - D_800FF0A0_ShellGame.z));
    CZoom = 1328.0 - (arg0 * 664.0);
}

u16 func_800F719C_ShellGame(u16 arg0) {
    D_800FEC10_ShellGame = D_800FEC10_ShellGame * 0x19971204;
    D_800FEC10_ShellGame = (D_800FEC10_ShellGame + 0x19760831) >> 0x10;
    if (arg0 == 0) {
        return D_800FEC10_ShellGame;
    } else {
        return (D_800FEC10_ShellGame % arg0);
    }
}

void func_800F720C_ShellGame(u8 arg0) {
    D_800FEC10_ShellGame = arg0 + (arg0 * D_800FEC10_ShellGame);
}

f32 func_800F7230_ShellGame(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_f4;
    
    if ((arg0 >= 360.0)) {
        arg0 = arg0 - 360.0;
    } else {
        if (arg0 < 0.0) {
            arg0 = arg0 + 360.0;
        }        
    }
    if ((arg1 >= 360.0)) {
        arg1 = arg1 - 360.0;
    } else {
        if (arg1 < 0.0) {
            arg1 = arg1 + 360.0;
        }        
    }
    
    temp_f4 = func_8009B618((arg0 - arg1) + 360.0, 360.0);
    
    if (temp_f4 < 180.0) {
        if (temp_f4 <= arg2) {
            return temp_f4;
        }
        return arg2;
    }
    if ((360.0 - temp_f4) <= arg2) {
        return -(360.0 - temp_f4);
    }
    return -arg2;
}

f32 func_800F7398_ShellGame(f32 arg0, f32 arg1) {
    f32 var_f4;
    f64 temp_f0;
    f64 temp_f2;
    f64 temp_f2_2;
    f64 var_f0;

    var_f4 = func_800B0CD8(arg0, arg1);
    temp_f0 = var_f4;
    temp_f2 = 360.0;
    if ((temp_f2 < temp_f0)) {
        var_f4 = temp_f0 - temp_f2;
    } else {
        temp_f2_2 = var_f4;
        if (temp_f2_2 < 0.0) {
            var_f4 = temp_f2_2 + 360.0;
        }        
    }
    return var_f4;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F7410_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F7470_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F750C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F7550_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F76C4_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F7840_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F79FC_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F7AE8_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F7BDC_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F7DA8_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F8154_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F8238_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F828C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F83BC_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F85B4_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F87AC_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F87CC_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F88E8_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F8CF8_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F913C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F915C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F91DC_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F94A0_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F9570_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F9618_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F9738_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F9A8C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800F9E24_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FA038_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FA0EC_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FA664_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FA954_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FAA44_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FAC34_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FB030_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FB120_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FB4A4_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FBB44_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FBBC8_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FBDB8_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FBEF0_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC17C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC3F4_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC55C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC6E0_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC714_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC748_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC77C_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC7B0_ShellGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/F6AB0", func_800FC800_ShellGame);
