#include "common.h"

#include "engine/esprite.h"

/* Menu choice: target point, camera index, message. */
typedef struct HouseMenuEntry {
    /* 0x00 */ s8 pos;
    /* 0x01 */ s8 cam;
    /* 0x04 */ s32 msg;
} HouseMenuEntry;

s32 func_80059CB8(void);
s32 func_80059CE8(void* str, s16 win);
void func_800532E0(void);
void func_800532F4(void);
void func_8007FAC0(void);
void func_8004F8DC(void);
s16 func_80059C28(void);
s16 func_80060128(s32);
void func_800601D4(s32);
void func_800726AC(s16, s16);
s32 func_80072718(void);
void func_80070ED4(void);
void func_8005B244(void);
void func_8006EB40(s16);
void func_8006E288(s16, u8);
void func_8007F54C(void* code, u16* outbuf, u32 outbufWidth, u16* workbuf);

void func_800F6AD0_MinigameHouse(void);
void func_800F6BAC_MinigameHouse(void);
void func_800F7024_MinigameHouse(void);
void func_800F70E8_MinigameHouse(void);
void func_800F7BA0_MinigameHouse(void);
void func_800F7F50_MinigameHouse(void);
void func_800F8860_MinigameHouse(void);
void func_800FB2DC_MinigameHouse(void);
void func_800FB96C_MinigameHouse(omObjData*);
void func_800FD2D0_MinigameHouse(void);

extern s8 D_800C5721;
extern u8 D_800C5722;
extern u32 D_800F383C;
extern s16 D_800F384C;
extern u16 D_800F5144;
extern u8 D_800ECC22;
extern Vec3f* D_800ED610;
extern Vec3f* D_800ED72C;
#ifdef TARGET_PC
extern s16 D_800F3B70[];
#define D_800F3B74 (D_800F3B70[2]) /* splat label inside 72D90.c's s16 array */
#else
extern s16 D_800F3B74;
#endif

/* .data */
extern Vec3f D_800FFEC0_MinigameHouse[];
extern Vec3f D_800FFF38_MinigameHouse[];
extern Vec3f D_800FFFB0_MinigameHouse[];
extern HouseMenuEntry D_800FFFEC_MinigameHouse[5];
extern s32 D_80100014_MinigameHouse;
extern s32 D_80100018_MinigameHouse;
extern s32 D_8010001C_MinigameHouse[];

/* .bss */
extern s16 D_8010055C_MinigameHouse; /* the message window */
extern Process* D_80100560_MinigameHouse;
extern omObjData* D_80100568_MinigameHouse[6];
extern s16 D_80100580_MinigameHouse;
extern u16 D_80100582_MinigameHouse[2];
extern s16 D_80100586_MinigameHouse;
extern u16 D_80100588_MinigameHouse[4];
extern u16* D_80100590_MinigameHouse;
extern s32 D_80100594_MinigameHouse;
extern unkCommonStruct0 D_80100598_MinigameHouse;
#ifdef TARGET_PC
#define D_801005AC_MinigameHouse (D_80100598_MinigameHouse.unk_14)
#else
extern s16 D_801005AC_MinigameHouse[];
#endif
extern s16 D_80100600_MinigameHouse;
extern s16 D_80100602_MinigameHouse;
extern u16 D_80100604_MinigameHouse;
extern s32 D_80100608_MinigameHouse;
extern omObjData* D_8010060C_MinigameHouse;
extern u16* D_80100610_MinigameHouse;




void func_800F65E0_MinigameHouse(void) {
    s32 i;
    s32 var_a0;

    InitCameras(1);
    omInitObjMan(0x20, 8);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80059EBC), 0xA0);
    D_800F384C = 0;
    func_8006CEA0();
    func_8004F8DC();
    D_80100608_MinigameHouse = func_8004F954(0x2B, 0x20);
    func_8004FA90(D_80100608_MinigameHouse, 1.0f, 1.0f, 1.0f);
    func_8007FAC0();
    D_80100590_MinigameHouse = func_80023684(0x1040, 0x7918);
    func_800532E0();
    func_800F7BA0_MinigameHouse();
    func_800F7F50_MinigameHouse();
    D_80100580_MinigameHouse = InitSprite(0x9004B);
    for (i = 0; i < 2; i++) {
        D_80100582_MinigameHouse[i] = func_80019060(D_80100580_MinigameHouse, 0, 1);
        func_80018C90(D_80100582_MinigameHouse[i]);
        func_80018D84(D_80100582_MinigameHouse[i], 0xFFF0);
    }
    func_800674BC(D_800ED60C[(s16)D_80100582_MinigameHouse[1]].unk_04, 0, 1);
    D_80100586_MinigameHouse = InitSprite(0x90024);
    for (i = 0; i < 4; i++) {
        D_80100588_MinigameHouse[i] = func_80019060(D_80100586_MinigameHouse, 0, 1);
        func_80018C90(D_80100588_MinigameHouse[i]);
        func_80018D84(D_80100588_MinigameHouse[i], 0xFFF0);
    }
    func_8007B168("\x82\x4F\x82\x60", 0);
    D_80100602_MinigameHouse = InitSprite(0xA0013);
    D_80100604_MinigameHouse = func_80019060(D_80100602_MinigameHouse, 0, 1);
    SetBasicSpriteSize(D_80100604_MinigameHouse, 0.5f, 0.5f);
    SetBasicSpritePos(D_80100604_MinigameHouse, 0x20, 0x18);
    D_80100600_MinigameHouse = GMesFontCreate(&D_80100598_MinigameHouse, "00000", 0, -1, -1);
    omAddObj(1, 0, 0, -1, &func_800F6AD0_MinigameHouse);
    func_80066DC4(D_801005AC_MinigameHouse[D_80100600_MinigameHouse], 0, 0x4C, 0x18);
    for (i = 0; i < 6; i++) {
        D_80100568_MinigameHouse[i] = omAddObj(1, 1, 1, -1, &func_800FB96C_MinigameHouse);
    }
    D_80100560_MinigameHouse = omAddPrcObj(func_800F6BAC_MinigameHouse, 0xA, 0, 0);
    SetFadeInTypeAndTime(0xFF, 8);
    D_80100594_MinigameHouse = func_8005AF60();
    if (D_80100594_MinigameHouse == 0) {
        D_80100594_MinigameHouse = 1;
    }
    if (D_800C5721 == 0) {
        D_8010055C_MinigameHouse = func_80059C28();
    }
    var_a0 = 7;
    if (D_800C5721 == 1 && !(D_800C5722 & 0x80)) {
        var_a0 = 0x13;
    }
    func_80060128(var_a0);
}
void func_800F6970_MinigameHouse(s32 arg0) {
    D_800ED610 = &D_800FFEC0_MinigameHouse[arg0];
    D_800ED72C = &D_800FFF38_MinigameHouse[arg0];
}
void func_800F69A8_MinigameHouse(void) {
    ShowBasicSprite(D_80100582_MinigameHouse[0]);
    ShowBasicSprite(D_80100582_MinigameHouse[1]);
}
void func_800F69DC_MinigameHouse(void) {
    func_80018C90(D_80100582_MinigameHouse[0]);
    func_80018C90(D_80100582_MinigameHouse[1]);
}
void func_800F6A10_MinigameHouse(s16 arg0, s32 arg1, s16 arg2) {
    SetBasicSpritePos(D_80100582_MinigameHouse[0], arg1 - ((D_800F383C & 0xC) >> 2) - 8, arg2);
    SetBasicSpritePos(D_80100582_MinigameHouse[1], arg1 + ((D_800F383C & 0xC) >> 2) + 8 + arg0 * 11, arg2);
}
void func_800F6AD0_MinigameHouse(void) {
    s32 i;
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0x2710;
    var_s0 = GwCommon.coinNum;

    for (i = 1; i < 6; i++) {
        func_80067208(D_801005AC_MinigameHouse[D_80100600_MinigameHouse], i, D_800F3B74, var_s0 / var_s1);
        var_s0 = var_s0 % var_s1;
        var_s1 /= 0xA;
    }
}
void func_800F6BAC_MinigameHouse(void) {
    Vec2f pos;
    s32 prevMsg;
    s32 cur;
    s32 prevCam;
    s32 spr;
    u32 btn;

    prevMsg = -1;
    cur = 0;
    prevCam = 0;
    if (D_800C5721 != 0) {
        prevCam = -1;
        func_800FD2D0_MinigameHouse();
        D_800F384C = 0;
        cur = 4;
        HuPrcVSleep();
    }
    spr = func_80019060((s16)InitSprite(0x85), 1, 1);
    ShowBasicSprite((u16)spr);
    func_80018D84((u16)spr, 0xFFF0);
    while (1) {
        btn = func_80059CB8();
        D_800ECC22 = 1;
        if (btn & 0x8000) {
            D_800F384C = 0;
            D_800ECC22 = 0;
            PlaySound(0xF6);
            func_80018C90((u16)spr);
            switch (cur) {
            case 0:
                func_800FB2DC_MinigameHouse();
                break;
            case 1:
                func_800F70E8_MinigameHouse();
                break;
            case 4:
                func_800FD2D0_MinigameHouse();
                break;
            case 3:
                func_800F8860_MinigameHouse();
                break;
            case 2:
                if (func_80059CE8((void*)0x3D, D_8010055C_MinigameHouse) != 0) {
                    func_80025EB4(D_8010060C_MinigameHouse->model[0], 1, 0);
                    HuPrcSleep(15);
                    D_800F5144 = 1;
                    while (1) {
                        HuPrcVSleep();
                    }
                }
                break;
            }
            if (D_800F5144 != 1) {
                prevMsg = -1;
                prevCam = -1;
                ShowBasicSprite((u16)spr);
            }
        }
        if ((btn >> 14) & 1 & (cur != 2)) {
            PlaySound(0xF8);
            cur = 2;
        }
        if (func_8006FCC0(D_8010055C_MinigameHouse) == 0) {
            if (btn & 0x900) {
                cur++;
                if (cur == 3) {
                    cur += (_CheckFlag(0x1F) == 0);
                }
                if (cur >= 5) {
                    cur = 0;
                }
            }
            if (btn & 0x600) {
                cur--;
                if (cur == 3) {
                    cur -= (_CheckFlag(0x1F) == 0);
                }
                if (cur < 0) {
                    cur = 4;
                }
            }
        }
        if (prevMsg != D_800FFFEC_MinigameHouse[cur].msg) {
            if (prevMsg != -1) {
                PlaySound(0xF5);
            }
            func_8006EB40(D_8010055C_MinigameHouse);
            func_8006E288(D_8010055C_MinigameHouse, 7);
            LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)(PB_PTR32)D_800FFFEC_MinigameHouse[cur].msg, -1, -1);
        }
        prevMsg = D_800FFFEC_MinigameHouse[cur].msg;
        if (prevCam != D_800FFFEC_MinigameHouse[cur].cam) {
            func_800F6970_MinigameHouse(D_800FFFEC_MinigameHouse[cur].cam);
            D_800F384C = btn;
        }
        prevCam = D_800FFFEC_MinigameHouse[cur].cam;
        Convert3DTo2D(0, &D_800FFFB0_MinigameHouse[D_800FFFEC_MinigameHouse[cur].pos], &pos);
        SetBasicSpritePos((u16)spr, pos.x - 24.0f, pos.y);
        if (!(D_80100018_MinigameHouse & 0x3F)) {
            func_8004F9F4(D_80100608_MinigameHouse, -35.5f, 90.0f, -60.0f, 4);
        }
        D_80100018_MinigameHouse++;
        HuPrcVSleep();
    }
}
void func_800F6F94_MinigameHouse(omObjData* arg0) {
    if (D_800F5144 != 0 || D_80100014_MinigameHouse != 0) {
        func_800601D4(0x1E);
        if (D_80100014_MinigameHouse == 2) {
            func_80072724(0, 0, 0);
        } else {
            func_80072724(0xFF, 0xFF, 0xFF);
        }
        func_800726AC(0, 4);
        arg0->func_ptr = &func_800F7024_MinigameHouse;
    }
}
void func_800F7024_MinigameHouse(void) {
    if (func_80072718() == 0) {
        func_800532F4();
        func_80070ED4();
        ClearBoardFeatureFlag(0x30);
        func_8005B244();
        switch (D_80100014_MinigameHouse) {
        case 1:
            SetBoardFeatureFlag(0x30);
            omOvlCallEx(0x6F, 0, 0x94);
            break;
        case 2:
            ClearBoardFeatureFlag(0x29);
            GwSystem.curBoardIndex = 9;
            omOvlCallEx(0x6A, 3, 0x91);
            break;
        default:
            ClearBoardFeatureFlag(0x29);
            omOvlReturnEx(1);
            break;
        }
    }
}
void func_800F70E8_MinigameHouse(void) {
    Vec3f center;
    Vec3f rot;
    s32 i;

    func_800F6970_MinigameHouse(7);
    if (func_80059CE8((void*)0x83, D_8010055C_MinigameHouse) != 0) {
        func_800F6970_MinigameHouse(8);
        HuPrcSleep(0x1E);
        func_80070D90(D_8010055C_MinigameHouse);
        rot.x = CRot.x;
        rot.y = CRot.y;
        rot.z = CRot.z;
        center.x = Center.x;
        center.y = Center.y;
        center.z = Center.z;
        PlaySound(0);
        for (i = 0; i < 40; i++) {
            center.y -= 10.0f;
            rot.y += 5.0f;
            D_800ED610 = &center;
            D_800ED72C = &rot;
            HuPrcVSleep();
        }
        D_80100014_MinigameHouse = 2;
        while (1) {
            HuPrcVSleep();
        }
    }
}
void func_800F7218_MinigameHouse(s16 arg0) {
    void* data;

    data = DataRead(D_8010001C_MinigameHouse[arg0]);
    func_8007F54C(data, D_80100610_MinigameHouse, 0xA0, D_80100590_MinigameHouse);
    DataClose(data);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7274_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7B00_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7BA0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7C6C_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7DE0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7F50_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8324_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8364_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8514_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8540_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8860_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002BC_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F9D64_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F9FF4_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FA2E4_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FA3B0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FA470_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FA600_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FA7C0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FA8D0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FA92C_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FAD28_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FAE94_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FAF5C_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB108_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB238_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB2DC_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB7E0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB96C_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FBAC0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FBB28_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FBFA4_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC090_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC110_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC204_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002C4_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002CC_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002D4_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC410_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FCB78_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FCC38_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FCCD8_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FCE7C_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FCEFC_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FD078_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002DC_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002E0_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002F0_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002FC_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_8010032C_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FD2D0_MinigameHouse);
