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
u16 D_800FEC2A_ShellGame = 1;
u16 D_800FEC2C_ShellGame = 0;
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

f32 func_800F7410_ShellGame(f32 t, f32 a, f32 b, f32 c) {
    f32 u = 1.0 - t;

    return u * u * a + 2.0 * (u * t * b) + t * t * c;
}
void func_800F7470_ShellGame(f32 t, f32* a, f32* b, f32* c, f32* out) {
    s32 i;

    for (i = 0; i < 3; i++) {
        *out++ = func_800F7410_ShellGame(t, *a++, *b++, *c++);
    }
}
u16 func_800F750C_ShellGame(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = func_800678A4(data);
    DataClose(data);
    return ret;
}
void func_800F7550_ShellGame(void) {
    SGSprite* p;
    u16 i;

    D_800FF170_ShellGame[1] = func_800F750C_ShellGame(0x170007);
    D_800FF170_ShellGame[2] = func_800F750C_ShellGame(0x21);
    D_800FF170_ShellGame[3] = func_800F750C_ShellGame(0x22);
    D_800FF170_ShellGame[4] = func_800F750C_ShellGame(0x23);
    D_800FF170_ShellGame[5] = func_800F750C_ShellGame(0x270006);
    D_800FF170_ShellGame[6] = func_800F750C_ShellGame(0x170008);
    D_800FF170_ShellGame[7] = func_800F750C_ShellGame(0x34);
    D_800FF170_ShellGame[8] = func_800F750C_ShellGame(0x75);
    p = D_800FF190_ShellGame;
    for (i = 0; i < 32; i++, p++) {
        p->unk2 = func_80064EF4(1, 0);
        func_80067480(p->unk2, 0, -1);
        func_800674BC(p->unk2, 0, 0x8000);
        func_800672B0(p->unk2, 0, 0);
        func_80067384(p->unk2, 0, i + 0xFF00);
        p->unk0 = 0;
        p->unk4 = 0;
        p->unk6 = 0;
        p->unk8 = 0;
        p->unkC = 1.0f;
        p->unk10 = p->unk14 = p->unk18 = 0.0f;
        p->unk1C = p->unk1E = p->unk20 = p->unk22 = 0;
        p->unk24 = p->unk26 = p->unk28 = p->unk2A = 0;
    }
}
void func_800F76C4_ShellGame(void) {
    SGSprite* p;
    f32 s;
    u16 i;

    p = D_800FF190_ShellGame;
    for (i = 0; i < 32; i++) {
        if (p->unk0 != 0) {
            if ((p->unk4 & 8) && --p->unk8 == 0xFFFF) {
                p->unk0 = 0;
                p->unk4 = 0;
                func_800674BC(p->unk2, 0, 0x8000);
                func_800672B0(p->unk2, 0, 0);
                p->unk1C = p->unk1E = p->unk20 = p->unk22 = 0;
                p->unk24 = p->unk26 = p->unk28 = p->unk2A = 0;
                continue; /* retail: the next slot is not advanced to */
            } else if (p->unk4 & 2) {
                s = (f32)(p->unk18 / 2000.0 + 1.0) * p->unkC;
                func_80067354(p->unk2, 0, s, s);
                func_80066DF4(p->unk2, 0, 0, p->unk10, p->unk14, p->unk18);
            } else {
                func_80066DC4(p->unk2, 0, p->unk10, p->unk14);
            }
        }
        p++;
    }
}

s16 func_800F7840_ShellGame(s16 image, f32 x, f32 y, f32 z, u16 flags) {
    SGSprite* p;
    u16 i;

    p = D_800FF190_ShellGame;
    for (i = 0; i < 32; i++, p++) {
        if (p->unk2 >= 0 && (p->unk0 == 0) & ((u16)image < 12)) {
            func_80067480(p->unk2, 0, 0xFFFF);
            func_800674BC(p->unk2, 0, 0x1000);
            func_80067354(p->unk2, 0, 1.0f, 1.0f);
            func_80067208(p->unk2, 0, D_800FF170_ShellGame[(u16)image], 0);
            func_800671DC(p->unk2, 0, 0);
            func_80067284(p->unk2, 0, 0.3f);
            if (flags & 4) {
                func_800672B0(p->unk2, 0, 2);
            } else {
                func_800672B0(p->unk2, 0, 0);
            }
            p->unk0 = 1;
            p->unk4 = flags;
            p->unk6 = image;
            p->unkC = 1.0f;
            p->unk8 = 0;
            p->unk10 = x;
            p->unk14 = y;
            p->unk18 = z;
            p->unk1C = p->unk1E = p->unk20 = p->unk22 = 0;
            p->unk24 = p->unk26 = p->unk28 = p->unk2A = 0;
            return i;
        }
    }
    return -1;
}
void func_800F79FC_ShellGame(omObjData* obj, u16 chance) {
    s16 i;

    if (func_800F719C_ShellGame(chance) == 0) {
        i = func_800F7840_ShellGame(6, obj->trans.x, obj->trans.y, obj->trans.z, 0xE);
        if (i >= 0) {
            func_800674F4(D_800FF190_ShellGame[i].unk2, 0, 0xFF, 0xFF, 0xFF);
            func_80067284(D_800FF190_ShellGame[i].unk2, 0, 1.0f);
            func_80066DF4(D_800FF190_ShellGame[i].unk2, 0, 0, obj->trans.x, obj->trans.y, obj->trans.z);
            D_800FF190_ShellGame[i].unk8 = 8;
        }
    }
}
void func_800F7AE8_ShellGame(f32 x, f32 y, f32 z) {
    s16 i;

    i = func_800F7840_ShellGame(6, x, y, z, 0xE);
    if (i >= 0) {
        func_800674F4(D_800FF190_ShellGame[i].unk2, 0, 0xFF, 0xFF, 0xFF);
        func_80067284(D_800FF190_ShellGame[i].unk2, 0, 1.0f);
        func_80066DF4(D_800FF190_ShellGame[i].unk2, 0, 0, x, y, z);
        D_800FF190_ShellGame[i].unk8 = 8;
    }
}
void func_800F7BDC_ShellGame(void) {
    SGSprite* p;
    f32 a;
    u16 i;

    p = D_800FF190_ShellGame;
    for (i = 0; i < 32; i++, p++) {
        if (p->unk0 != 0 && p->unk1C == 1) {
            a = (f32)p->unk8 / 5.0 * 255.0;
            if (a > 255.0) {
                a = 255.0f;
            }
            p->unk10 += func_800AEAC0(p->unk1E) * 40.0;
            p->unk14 += 20.0;
            p->unk18 += func_800AEFD0(p->unk1E) * 40.0;
            func_80066DF4(p->unk2, 0, 0, p->unk10, p->unk14, p->unk18);
            func_8006752C(p->unk2, 0, a);
        }
    }
}
void func_800F7DA8_ShellGame(omObjData* obj, s32 show) {
    f32* ang;
    u16 i;
    s16 on;

    if (D_800FEC2A_ShellGame == 1) {
        for (i = 0; i < 3; i++) {
            D_800FF0B8_ShellGame[i] = func_800F7840_ShellGame(1, 0, 0, 0, 6);
            func_800674BC(D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk2, 0, 0x8000);
            D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unkC = 0.6f;
            D_800FF0C0_ShellGame[i] = i * 120.0;
        }
        D_800FEC2A_ShellGame = 0;
        return;
    }
    on = show & -(D_800FEC14_ShellGame != 0);
    for (i = 0; i < 3; i++) {
        if (on == 0) {
            func_800674BC(D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk2, 0, 0x8000);
        } else {
            ang = &D_800FF0C0_ShellGame[i];
            *ang += 20.0;
            if (*ang > 360.0) {
                *ang -= 360.0;
            }
            if (D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk0 != 1) {
                D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk0 = 1;
            }
            D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk10 =
                func_800AEFD0(D_800FF0C0_ShellGame[i]) * 3.0 * 20.0 + obj->trans.x;
            D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk14 = obj->trans.y + 160.0;
            D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk18 =
                func_800AEAC0(D_800FF0C0_ShellGame[i]) * 3.0 * 20.0 + obj->trans.z;
            func_80067480(D_800FF190_ShellGame[D_800FF0B8_ShellGame[i]].unk2, 0, 0x8000);
        }
    }
}
s16 func_800F8154_ShellGame(void) {
    u16 sec;
    u16 tens;

    sec = D_800FF10C_ShellGame / 30;
    tens = sec / 10;
    if (D_800FF10C_ShellGame == 0x14A) {
        GMesCreate(8, 10, 160, 32);
    } else {
        func_80079078(sec);
    }
    if (sec != 0) {
        D_800FF10C_ShellGame--;
        return 1;
    }
    if (D_800FF782_ShellGame == 0) {
        D_800FF782_ShellGame = 1;
        func_800790C0();
    }
    D_800FEC14_ShellGame = 0;
    return 0;
}
s16 func_800F8238_ShellGame(s32 a, s32 b, s32 c) {
    s16 id;

    id = ReadImgPackand(a, b, c);
    func_80025930(D_800ECDE0[id].unk_00, 0x70000000, 0x70000000);
    return id;
}
void func_800F828C_ShellGame(void) {
    SGCoin* p;
    s16 i;

    p = D_800FF710_ShellGame = HuMemDirectMalloc(10 * sizeof(SGCoin));
    for (i = 0; i < 10; i++, p++) {
        p->unk4 = func_800F8238_ShellGame(0x21, 0x289, 8);
        if (p->unk4 != -1) {
            p->unk6 = D_800ECDE0[p->unk4].unk_00;
            p->unk0 = 0;
            p->unk8 = 0;
            p->unkC = p->unk10 = p->unk14 = 0.0f;
            p->unk18 = p->unk1C = p->unk20 = 3.0f;
            p->unk24 = p->unk26 = p->unk28 = p->unk2A = p->unk2C = 0;
            p->unk30 = p->unk34 = p->unk38 = p->unk3C = p->unk40 = 0.0f;
            func_800258EC(p->unk6, 4, 4);
            func_8001E2A8(p->unk4, 0);
        } else {
            p->unk0 = -1;
        }
    }
}
void func_800F83BC_ShellGame(f32 x, f32 y, f32 z) {
    SGCoin* p;
    f32 dir;
    f32 a;
    s16 i;

    dir = func_800F7398_ShellGame(D_800F3FB0[0]->trans.x - x, D_800F3FB0[0]->trans.z - z);
    p = D_800FF710_ShellGame;
    for (i = 0; i < 10; i++, p++) {
        a = func_800F719C_ShellGame(360);
        if (func_800F7230_ShellGame(dir, a, 20.0f) < 20.0) {
            a += 180.0;
        }
        if (a >= 360.0) {
            a -= 360.0;
        }
        p->unk0 = 1;
        p->unk24 = func_800F719C_ShellGame(15);
        p->unk30 = a;
        p->unk34 = func_800F719C_ShellGame(10) + 10.0;
        p->unk38 = func_800F719C_ShellGame(40) + 40.0;
        p->unkC = x;
        p->unk10 = y;
        p->unk14 = z;
        p->unk18 = p->unk1C = p->unk20 = 2.0f;
        func_80025798(p->unk6, p->unkC, p->unk10, p->unk14);
        func_80025830(p->unk6, p->unk18, p->unk1C, p->unk20);
        func_800258EC(p->unk6, 4, 0);
    }
}
void func_800F85B4_ShellGame(void) {
    SGCoin* p;
    f32 d;
    s16 i;

    p = D_800FF710_ShellGame;
    i = 0;
    do {
        if (p->unk0 != -1) {
            if (p->unk0 == 0) {
            } else if (p->unk24 <= 0) {
                p->unkC = func_800AEAC0(p->unk30) * p->unk34 + p->unkC;
                p->unk14 = func_800AEFD0(p->unk30) * p->unk34 + p->unk14;
                p->unk10 = p->unk10 + p->unk38;
                d = sqrtf(p->unkC * p->unkC + p->unk14 * p->unk14);
                if (d < 432.0) {
                    if (p->unk10 < 0.0) {
                        PlaySound(0x108);
                        p->unk10 = 0.0f;
                        p->unk38 = func_800F719C_ShellGame(40) + 20.0;
                    } else {
                        p->unk38 = p->unk38 - 6.0;
                    }
                } else {
                    if (p->unk10 < -2000.0) {
                        p->unk0 = 0;
                        func_800258EC(p->unk6, 4, 4);
                    }
                    p->unk38 = p->unk38 - 20.0;
                }
                func_80025798(p->unk6, p->unkC, p->unk10, p->unk14);
            } else {
                p->unk24--;
            }
        }
        p++;
    } while (++i < 10);
}

void func_800F87AC_ShellGame(void) {
    HuMemDirectFree(D_800FF710_ShellGame);
}
void func_800F87CC_ShellGame(void) {
    SGSprite* p;
    s16 i;

    p = D_800FF714_ShellGame = HuMemDirectMalloc(10 * sizeof(SGSprite));
    for (i = 0; i < 10; i++, p++) {
        p->unk2 = func_80064EF4(1, 0);
        func_80067480(p->unk2, 0, -1);
        func_800674BC(p->unk2, 0, 0x8000);
        func_80067208(p->unk2, 0, D_800FF170_ShellGame[2], 0);
        func_800671DC(p->unk2, 0, 0);
        func_800672B0(p->unk2, 0, 2);
        p->unk0 = p->unk4 = p->unk6 = p->unk8 = 0;
        p->unkC = 1.0f;
        p->unk10 = p->unk14 = p->unk18 = 0.0f;
        p->unk1C = p->unk1E = p->unk20 = p->unk22 = 0;
        p->unk24 = p->unk26 = p->unk28 = p->unk2A = 0;
    }
}
void func_800F88E8_ShellGame(Vec* from, Vec* to, s16 frames, s16 type) {
    unk65770Obj* o;
    f32 p0[2];
    f32 p1[2];
    f32 d[2];
    f32 len;
    f32 ang;
    SGSprite* p;
    s32 dx;
    s32 dy;
    s16 i;

    ang = 0.0f;
    p = D_800FF714_ShellGame;
    func_80066DF4(p->unk2, 0, 0, from->x, from->y, from->z);
    o = func_800675F4(p->unk2, 0);
    p0[0] = o->unk40;
    p0[1] = o->unk42;
    switch (type) {
    case 1:
        len = p0[1] - 16.0f;
        break;
    case 2:
        func_80066DF4(p->unk2, 0, 0, to->x, to->y + 100.0, to->z);
        o = func_800675F4(p->unk2, 0);
        p1[0] = o->unk40;
        p1[1] = o->unk42;
        dx = p1[0] - p0[0];
        if (dx < 0) {
            dx = -dx;
        }
        d[0] = dx;
        dy = p1[1] - p0[1];
        if (dy < 0) {
            dy = -dy;
        }
        d[1] = dy;
        len = sqrtf(d[0] * d[0] + d[1] * d[1]);
        ang = func_800F7398_ShellGame(p0[0] - p1[0], p0[1] - p1[1]);
        if (ang < 360.0) {
            ang += 360.0;
        }
        break;
    default:
        len = 0.0f;
        break;
    }
    for (i = 0; i < 10; i++, p++) {
        p->unk0 = type;
        p->unk8 = frames;
        switch (type) {
        case 1:
            p->unk1C = p0[0];
            p->unk1E = p0[1];
            p->unk20 = len;
            p->unk22 = frames;
            p->unk24 = i * 2;
            p->unk10 = p->unk1C;
            p->unk14 = p->unk1E - p->unk20;
            break;
        case 2:
            p->unk1C = p1[0];
            p->unk1E = p1[1];
            p->unk20 = len;
            p->unk22 = frames;
            p->unk24 = i * 2;
            p->unk26 = ang;
            p->unk10 = p0[0];
            p->unk14 = p0[1];
            break;
        }
        if (frames >= 41) {
            p->unk2A = 0;
        } else {
            p->unk2A = 1;
        }
        func_80066DC4(p->unk2, 0, p->unk10, p->unk14);
        func_80067208(p->unk2, 0, D_800FF170_ShellGame[2], 0);
        func_80067480(p->unk2, 0, 0x8000);
        func_800671DC(p->unk2, 0, 0);
    }
}
void func_800F8CF8_ShellGame(void) {
    SGSprite* p;
    f32 t;
    f32 a;
    s16 i;

    p = D_800FF714_ShellGame;
    for (i = 0; i < 10; i++, p++) {
        switch (p->unk0) {
        case 0:
            break;
        case 1:
            t = (f32)p->unk8 / (f32)p->unk22;
            p->unk10 = p->unk1C;
            p->unk14 = p->unk1E - p->unk20 * t;
            if (t > 0.33) {
                p->unkC = 1.0f;
            } else {
                p->unkC = t * 3.0;
            }
            func_80066DC4(p->unk2, 0, p->unk10, p->unk14);
            func_80067354(p->unk2, 0, p->unkC, p->unkC);
            if (p->unk24 > 0) {
                p->unk24--;
            } else {
                p->unk8 = p->unk8 - 1.0;
                if (p->unk8 <= 0.0) {
                    p->unk0 = 0;
                    func_800674BC(p->unk2, 0, 0x8000);
                }
            }
            break;
        case 2:
            t = (f32)p->unk8 / (f32)p->unk22;
            a = p->unk26 - t * 360.0;
            if (a < 0.0) {
                a += 360.0;
            }
            p->unk10 = p->unk1C + func_800AEAC0(a) * p->unk20 * t;
            p->unk14 = p->unk1E + func_800AEFD0(a) * p->unk20 * t;
            p->unkC = t;
            func_80066DC4(p->unk2, 0, p->unk10, p->unk14);
            func_80067354(p->unk2, 0, p->unkC, p->unkC);
            if (p->unk24 > 0) {
                p->unk24--;
            } else {
                p->unk8 = p->unk8 - 1.0;
                if (p->unk8 <= 0.0) {
                    p->unk0 = 0;
                    if (p->unk2A != 0) {
                        PlaySound(0xFC);
                    } else if (i == 0) {
                        PlaySound(0x1EA);
                    }
                    func_800674BC(p->unk2, 0, 0x8000);
                }
            }
            break;
        }
    }
}
void func_800F913C_ShellGame(void) {
    HuMemDirectFree(D_800FF714_ShellGame);
}
void func_800F915C_ShellGame(void) {
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440] = omAddObj(10, 1, 1, -1, &func_800FE6BC_ShellGame);
    D_800FF108_ShellGame = omAddObj(10, 2, 1, -1, &func_800F91DC_ShellGame);
}
void func_800F91DC_ShellGame(omObjData* obj) {
    SGStageWork* w;
    u16 i;

    obj->func_ptr = &func_800F94A0_ShellGame;
    obj->model[0] = LoadFormFile(0x170000, 0x99);
    obj->model[1] = LoadFormFile(0x170006, 0xB9);
    obj->unk_50 = w = func_80023684(sizeof(SGStageWork), 0x7918);
    func_8009B770(w, 0, sizeof(SGStageWork));
    w->unk4 = 1;
    w->unk5 = 0;
    D_800FF182_ShellGame = func_800F750C_ShellGame(0x17000A);
    for (i = 0; i < D_800F37DA; i++) {
        /* 0x1900 bytes on the N64: 0x320 commands (a host Gfx is 16 bytes) */
        D_800FF718_ShellGame[i] = HuMemDirectMalloc(0x320 * sizeof(Gfx));
    }
    for (i = 0; i < 11; i++) {
        D_800FF728_ShellGame[i][0] = i * 4;
        D_800FF728_ShellGame[i][1] = i * 10 - 80;
    }
    for (i = 0; i < D_800F37DA; i++) {
        func_800FC800_ShellGame(D_800FF718_ShellGame[i], D_800FF182_ShellGame, 20, 160, 10, 11, 2.0f, 2.0f);
    }
    D_800FF724_ShellGame = func_80024198(0x99, D_800FF718_ShellGame[0], 0);
    D_800FF184_ShellGame = func_800F750C_ShellGame(0x170009);
    D_800FF188_ShellGame = func_80064EF4(1, 0);
    func_80067208(D_800FF188_ShellGame, 0, D_800FF184_ShellGame, 0);
    func_800674BC(D_800FF188_ShellGame, 0, 0x02004000);
    func_80066DC4(D_800FF188_ShellGame, 0, 0xA0, 0x78);
    func_800674F4(D_800FF188_ShellGame, 0, 0xED, 0xE6, 0xC1);
    func_80067354(D_800FF188_ShellGame, 0, 160.0f, 120.0f);
    func_80067384(D_800FF188_ShellGame, 0, 0x20);
    SetFadeInTypeAndTime(0, 16);
    D_800ED440++;
}
void func_800F94A0_ShellGame(omObjData* obj) {
    Gfx* gfx;

    D_800FEC2C_ShellGame++;
    if (D_800FEC2C_ShellGame >= D_800F37DA) {
        D_800FEC2C_ShellGame = 0;
    }
    gfx = D_800FF718_ShellGame[D_800FEC2C_ShellGame];
    func_800FC800_ShellGame(gfx, D_800FF182_ShellGame, 20, 160, 10, 11, 2.0f, 2.0f);
    D_800F2B7C[D_800FF724_ShellGame].unk_6C->unk_00 = (Gfx**)gfx;
}
void func_800F9570_ShellGame(omObjData* obj) {
    SGShellWork* w;

    D_800EDE70[(u16)D_800EE984++] = obj;
    obj->unk_50 = w = func_80023684(sizeof(SGShellWork), 0x7918);
    w->unk44 = 0.1f;
    w->unk48 = 80.0f;
    w->unk34 = 40.0f;
    w->unk5C = 0;
    w->unk3C = 0;
    w->unk52 = 7;
    w->unk60 = 0;
    w->unk50 = 0;
    w->unk54 = 1;
}
void func_800F9618_ShellGame(void) {
    omObjData* obj;
    s16 i;

    obj = omAddObj(11, 9, 60, -1, &func_800FCF90_ShellGame);
    D_800F3FB0[D_800F2BC0] = obj;
    obj->work[0] = 0;
    D_800F2BC0++;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    /* retail: no breaks, so the player is always 0 here (func_800FCF90 sets it again) */
    switch (i) {
    case 0:
        D_800FF9F0_ShellGame = 0;
    case 1:
        D_800FF9F0_ShellGame = 1;
    case 2:
        D_800FF9F0_ShellGame = 2;
    case 3:
        D_800FF9F0_ShellGame = 3;
    default:
        D_800FF9F0_ShellGame = 0;
    }
}
void func_800F9738_ShellGame(void) {
    s16 cnt[3] = { 3, 3, 3 };
    SGGame* g;
    u16* cap;
    s16 skill;
    u16 i;

    switch (GwPlayer[D_800FF9F0_ShellGame].cpu_difficulty) {
    case 0:
        skill = 1;
        break;
    case 1:
        skill = 2;
        break;
    case 2:
        skill = 3;
        break;
    case 3:
        skill = 4;
        break;
    default:
        skill = 2;
        break;
    }
    D_800FF9D0_ShellGame.unk0 = skill;
    D_800FF9D0_ShellGame.unk2 = 4;
    cap = &D_800FF9D0_ShellGame.unk2;
    if (*cap < 3) {
        *cap = 3;
    }
    g = &D_800FF9D0_ShellGame;
    g->unk4 = func_800F719C_ShellGame(g->unk2);
    g->unk6 = -1;
    g->unk8 = 0;
    g->unkC = 0;
    g->unk10 = 70;
    g->unk12 = 20;
    g->unk14 = 7;
    g->unk16 = 7;
    g->unk18 = 5;
    cap = &D_800FF9D0_ShellGame.unk18;
    if (*cap < 6) {
        *cap = 6;
    }
    for (i = 0; i < D_800FF9D0_ShellGame.unk2; i++) {
        D_800FF9F8_ShellGame[i] = D_800F3FB0[i + 1] = omAddObj(2, 5, 0, -1, &func_800F9A8C_ShellGame);
        D_800FF9F8_ShellGame[i]->work[0] = i;
        if (i == D_800FF9D0_ShellGame.unk4) {
            D_800FF7A0_ShellGame[i].unk6C = 2;
        } else {
            D_800FF7A0_ShellGame[i].unk6C = 5;
        }
    }
    for (i = 0; i < D_800FF9D0_ShellGame.unk18; i++) {
        switch (func_800F719C_ShellGame(3)) {
        case 0:
            if (cnt[0]-- > 0) {
                D_800FF110_ShellGame[i] = 0;
                break;
            }
        case 1:
            if (cnt[1]-- > 0) {
                D_800FF110_ShellGame[i] = 1;
                break;
            }
        case 2:
            if (cnt[2]-- > 0) {
                D_800FF110_ShellGame[i] = 0;
                break;
            }
        default:
            D_800FF110_ShellGame[i] = func_800F719C_ShellGame(2);
            break;
        }
    }
    D_800FF0FC_ShellGame = omAddObj(1, 0, 0, -1, &func_800FA038_ShellGame);
    D_800FF100_ShellGame = 0;
    D_800FF104_ShellGame = 0;
}
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
