#include "common.h"

#include "engine/esprite.h"

/* The head of 42E40.c's SpriteAnimWork (func_800429CC's result); no pointers before 0x10. */
typedef struct HouseSpriteAnim {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
} HouseSpriteAnim;

/* A minigame category for the completion counts: minigame ids (1-based) and their count. */
typedef struct HouseMgCat {
    /* 0x00 */ u8* list;
    /* 0x04 */ u8 count;
} HouseMgCat;

void* func_800429CC(s16, s16);
void func_80025C20(s16, s16, s16, s16, s16);
void func_8002888C(s16, s16);
void func_8005A258(s16);
extern HouseSpriteAnim* D_80100638_MinigameHouse[3];
extern HouseMgCat D_801001C4_MinigameHouse[4];


extern s8 D_800C5720;


/* A minigame group shown in the house: its title message, the minigame list (1-based ids) and the
   range of that list to show. */
typedef struct HouseMgGroup {
    /* 0x00 */ s32 msg;
    /* 0x04 */ u8* list;
    /* 0x08 */ u8 start;
    /* 0x09 */ u8 end;
} HouseMgGroup; /* 0x0C on the N64 */

void func_8009B960(void*, void*);
void func_8006DA5C(s16, void*, s8);
void func_80071788(s32, s16);
extern HouseMgGroup D_80100170_MinigameHouse[7];
extern char D_80100430_MinigameHouse[10][30];
extern s16 D_80100634_MinigameHouse;


s16 func_80059400(s16);
s16 func_8005949C(s16);
char* func_800F9D64_MinigameHouse(s32);
s16 func_8006D93C(u8*);
extern char D_80100410_MinigameHouse[0x20];
extern u16 D_80100100_MinigameHouse[];
extern u16 D_80100632_MinigameHouse;


void func_800F6F94_MinigameHouse(omObjData* arg0);
s32 func_8005A22C(s32);
void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
TextWindow* func_8006DD60(s16);
extern unk_Struct00* D_800C3110;
extern f32 D_801000FC_MinigameHouse;
extern omObjData* D_80100614_MinigameHouse;
extern omObjData* D_80100618_MinigameHouse;
extern omObjData* D_8010061C_MinigameHouse;
extern omObjData* D_80100620_MinigameHouse;
extern u8 D_80100624_MinigameHouse[10];
extern s16 D_8010062E_MinigameHouse;
extern s16 D_80100630_MinigameHouse;


void func_8003A060(Gfx** arg0, PB_PTR32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);


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
void func_800F7C6C_MinigameHouse(omObjData*);
void func_800F7DE0_MinigameHouse(omObjData*);
s16 func_800F8364_MinigameHouse(s32, s16);
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
// loop-invariant hoisting as in ovl_6F's twin func_800F94E8: retail hoists 32.0f/255 only to the inner loop and keeps 2^31 inline (masked 62)
#ifdef NON_MATCHING
void func_800F7274_MinigameHouse(s16 model, s16 idx) {
    Gfx* gfx;
    void* data;
    unk2C0C0StructC0* mdl;
    unk2C0C0Struct30* mesh;
    Vtx* vtx;
    Vtx* vtxStart;
    s16 i;
    s16 j;
    s16 k;
    s16 h;
    s32 w;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 maxY;
    f32 rangeX;
    f32 rangeY;
    f32 baseX;
    f32 baseY;
    f32 x;
    f32 y;
    f32 sLo;
    f32 sHi;
    f32 tLo;
    f32 tHi;

    data = DataRead(D_8010001C_MinigameHouse[idx]);
    w = 160;
    h = 128;
    D_80100610_MinigameHouse = func_80023684(0xA000, 0x7918);
    func_8007F54C(data, D_80100610_MinigameHouse, 160, D_80100590_MinigameHouse);
    DataClose(data);
    mdl = D_800F2B7C[model].unk_6C;
    mesh = mdl->unk_80;
    vtx = func_80023684(0x500, 0x7918);
    mdl->unk_00[0] = gfx = func_80023684(0x200 * sizeof(Gfx), 0x7918); /* 0x1000 on N64; host Gfx is 16 bytes */
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPClearGeometryMode(gfx++, G_LIGHTING);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    maxY = maxX = -100000.0f;
    minY = minX = 100000.0f;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = mdl->unk_78[k].unk_00;
            if (x < minX) {
                minX = x;
            }
            x = mdl->unk_78[k].unk_00;
            if (maxX < x) {
                maxX = x;
            }
            y = mdl->unk_78[k].unk_02;
            if (y < minY) {
                minY = y;
            }
            y = mdl->unk_78[k].unk_02;
            if (maxY < y) {
                maxY = y;
            }
        }
    }
    rangeX = maxX - minX;
    rangeY = maxY - minY;
    baseX = minX;
    baseY = minY;
    vtxStart = vtx;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        maxY = maxX = -100000.0f;
        minY = minX = 100000.0f;
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = (vtx->v.ob[0] = mdl->unk_78[k].unk_00);
            y = (vtx->v.ob[1] = mdl->unk_78[k].unk_02);
            vtx->v.ob[2] = mdl->unk_78[k].unk_04;
            if (x < minX) {
                minX = x;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (y < minY) {
                minY = y;
            }
            if (maxY < y) {
                maxY = y;
            }
            vtx->v.cn[0] = vtx->v.cn[1] = vtx->v.cn[2] = -1;
            x = w * ((x - baseX) / rangeX);
            y = h * ((-y - baseY) / rangeY);
            vtx->v.tc[0] = x * 32.0f;
            vtx->v.tc[1] = y * 32.0f;
            vtx->v.cn[3] = 0xFF;
            vtx++;
        }
        sLo = ((minX - baseX) / rangeX) * w;
        sHi = ((maxX - baseX) / rangeX) * w;
        tLo = h - ((minY - baseY) / rangeY) * h;
        tHi = h - ((maxY - baseY) / rangeY) * h;
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        func_8003A060(&gfx, (PB_PTR32) D_80100610_MinigameHouse, G_IM_FMT_RGBA, G_IM_SIZ_16b, w, h, (u32) sLo, (u32) tHi,
                      (u32) sHi, (u32) tLo, 0, 2, 2, 0, 0, 0, 0);
        gSPVertex(gfx++, vtxStart, mesh->unk_34[i].unk_00, 0);
        if (mesh->unk_34[i].unk_00 == 3) {
            gSP1Triangle(gfx++, 0, 1, 2, 0);
        } else {
            gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
        }
        vtxStart = vtx;
    }
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7274_MinigameHouse);
#endif
void func_800F7B00_MinigameHouse(omObjData* arg0) {
    arg0->model[0] = func_800174C0(0x90045, 0x2D9);
    func_80025EB4(arg0->model[0], 1, 1);
    arg0->model[1] = func_800174C0(0x90043, 0x202B9);
    func_80025798(arg0->model[1], -17.0f, 0.0f, 0.0f);
    func_80025EB4(arg0->model[1], 1, 1);
    arg0->func_ptr = &func_800F6F94_MinigameHouse;
}
void func_800F7BA0_MinigameHouse(void) {
    CRot.x = 0.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 110.0f;
    Center.z = 700.0f;
    D_800C3110->unk_44 = 10.0f;
    if (D_800C5721 != 0) {
        func_800F6970_MinigameHouse(4);
    } else {
        func_800F6970_MinigameHouse(0);
    }
    func_8002890C(0xFF, 0xFF, 0xFF);
    D_8010060C_MinigameHouse = omAddObj(0x2710, 2, 0, -1, &func_800F7B00_MinigameHouse);
}
// model[1] load scheduled after the 180.0f constant (masked 2)
#ifdef NON_MATCHING
void func_800F7C6C_MinigameHouse(omObjData* arg0) {
    TextWindow* win;

    func_80027E48(arg0->model[0], D_801000FC_MinigameHouse, 0, 0x40, 0x40, "36t_002", 0);
    D_801000FC_MinigameHouse += 0.5f;
    if (D_801000FC_MinigameHouse > 64.0f) {
        D_801000FC_MinigameHouse -= 64.0f;
    }
    func_800257E4(arg0->model[1], 180.0f - func_800B0CD8(arg0->trans.y + 20.0f - Center.y, arg0->trans.z - Center.z), 0.0f, 0.0f);
    win = arg0->unk_50;
    if (win != NULL) {
        if ((s8)arg0->work[0] != win->unk_11) {
            if (D_80100624_MinigameHouse[win->unk_11] != 0) {
                func_800258EC(arg0->model[1], 4, 0);
                func_800F7218_MinigameHouse(D_80100624_MinigameHouse[win->unk_11] - 1);
            } else {
                func_800258EC(arg0->model[1], 4, 4);
            }
        }
        arg0->work[0] = win->unk_11;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7C6C_MinigameHouse);
#endif
// float register allocation f0/f2 (masked 0)
#ifdef NON_MATCHING
void func_800F7DE0_MinigameHouse(omObjData* arg0) {
    s32 v;
    u8 t;
    f32 scale;

    arg0->work[0]++;
    if (arg0->work[0] >= 0x5B) {
        arg0->work[0] = 0;
        arg0->work[1] = 12;
        arg0->work[2] = rand8() & 1;
    }
    if (arg0->work[1] != 0) {
        arg0->work[1]--;
        if (arg0->work[2] != 0) {
            v = arg0->work[1];
            if (v < 6U) {
                scale = v * 0.02f;
            } else {
                scale = (12 - v) * 0.02f;
            }
        } else {
            t = arg0->work[1] % 6;
            if (t < 3) {
                scale = t;
            } else {
                scale = 6 - t;
            }
            scale *= 0.04f;
        }
        arg0->scale.y = scale + 1.0f;
    } else {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7DE0_MinigameHouse);
#endif
void func_800F7F50_MinigameHouse(void) {
    omObjData* obj;
    s32 idx;

    obj = omAddObj(1, 1, 3, -1, NULL);
    D_80100614_MinigameHouse = obj;
    obj->model[0] = LoadFormFile(0x90048, 0x202B9);
    obj->motion[0] = func_80025E48(obj->model[0]);
    obj->motion[1] = func_8005A22C(0x90049);
    obj->motion[2] = func_8005A22C(0x9004A);
    func_80025EB4(obj->model[0], 2, 2);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = -180.0f;

    obj = omAddObj(1, 1, 0, -1, NULL);
    D_80100618_MinigameHouse = obj;
    obj->model[0] = func_800174C0(0x90044, 0x20299);
    func_800258EC(obj->model[0], 4, 4);
    obj->trans.x = 35.5f;
    obj->trans.y = 75.5f;
    obj->trans.z = -77.5f;

    obj = omAddObj(1, 2, 0, -1, &func_800F7C6C_MinigameHouse);
    D_8010061C_MinigameHouse = obj;
    obj->model[0] = func_800174C0(0x90046, 0x2B9);
    func_80026040(obj->model[0]);
    obj->trans.x = -35.5f;
    obj->trans.y = 68.0f;
    obj->trans.z = -85.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.5f;
    omSetStatBit(obj, 0xA0);
    obj->unk_50 = NULL;
    obj->work[0] = 0xFF;
    obj->model[1] = LoadFormFile(0x90010, 0x2C9);
    func_80025830(obj->model[1], 0.06f, 0.06f, 0.06f);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 20.0f, obj->trans.z);
    idx = GwSystem.unk_1E;
    if (idx > 0) {
        func_800F7274_MinigameHouse(obj->model[1], idx);
    } else {
        idx = 0;
        func_800F7274_MinigameHouse(obj->model[1], idx);
    }
    if (D_800C5721 == 0) {
        func_800258EC(obj->model[1], 4, 4);
    }

    obj = omAddObj(1, 1, 0, -1, &func_800F7DE0_MinigameHouse);
    obj->model[0] = LoadFormFile(0x90050, 0x202B9);
    obj->work[0] = obj->work[1] = 0;
    if (_CheckFlag(0x1F) != 0) {
        obj = omAddObj(1, 1, 2, -1, NULL);
    D_80100620_MinigameHouse = obj;
        obj->model[0] = func_800174C0(0x9004E, 0x2A9);
        func_80025EB4(obj->model[0], 1, 1);
        obj->motion[0] = func_80025E48(obj->model[0]);
        obj->motion[1] = func_8005A22C(0x9004F);
        obj->trans.x = -170.0f;
        obj->trans.y = 73.0f;
        obj->trans.z = 200.0f;
        obj->scale.x = obj->scale.y = obj->scale.z = 0.3f;
        obj->rot.x = 0.0f;
        obj->rot.y = 90.0f;
        obj->rot.z = 0.0f;
    }
}
void func_800F8324_MinigameHouse(void) {
    void* data;

    data = DataRead(0x87);
    D_8010062E_MinigameHouse = func_800678A4(data);
    DataClose(data);
}
// register allocation s0/s1 (masked 2)
#ifdef NON_MATCHING
s16 func_800F8364_MinigameHouse(s32 arg0, s16 arg1) {
    s16 i;
    s16 x;
    s16 win;

    D_80100630_MinigameHouse = win = func_80064EF4(7, 5);
    func_80067208(win, 0, D_8010062E_MinigameHouse, 0);
    func_80067480(win, 0, 0xFFFF);
    func_800674BC(win, 0, 0x8000);
    func_80066DC4(win, 0, arg0 - 0x10, arg1);
    func_80067384(win, 0, 1);
    x = 4;
    for (i = 1; i < 7; i++) {
        func_80067384(win, i, 1);
        func_80067208(win, i, D_8010062E_MinigameHouse, 0);
        func_80066DC4(win, i, x, 0);
        func_80067480(win, i, 0xFFFF);
        func_800674BC(win, i, 0x8000);
        if (i == 3) {
            x += 8;
        } else {
            x += 12;
        }
        func_80067598(win, i, 0);
    }
    func_80067480(win, 2, 0x8000);
    return win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8364_MinigameHouse);
#endif
void func_800F8514_MinigameHouse(void) {
    func_80064D38(D_80100630_MinigameHouse);
    func_80067704(D_8010062E_MinigameHouse);
}
void func_800F8540_MinigameHouse(s16 arg0) {
    s16 sec;
    s16 hund;

    func_80067480(D_80100630_MinigameHouse, 0, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 0, arg0 / 1800, 0);
    func_800672B0(D_80100630_MinigameHouse, 0, 1);
    arg0 %= 1800;
    func_80067480(D_80100630_MinigameHouse, 1, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 1, 10, 0);
    func_800672B0(D_80100630_MinigameHouse, 1, 1);
    func_80067480(D_80100630_MinigameHouse, 2, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 2, arg0 / 300, 0);
    func_800672B0(D_80100630_MinigameHouse, 2, 1);
    arg0 %= 300;
    sec = arg0 / 30;
    func_80067480(D_80100630_MinigameHouse, 3, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 3, sec, 0);
    func_800672B0(D_80100630_MinigameHouse, 3, 1);
    hund = (arg0 * 100) / 30 - sec * 100;
    func_80067480(D_80100630_MinigameHouse, 4, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 4, 11, 0);
    func_800672B0(D_80100630_MinigameHouse, 4, 1);
    func_80067480(D_80100630_MinigameHouse, 5, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 5, hund / 10, 0);
    func_800672B0(D_80100630_MinigameHouse, 5, 1);
    hund %= 10;
    func_80067480(D_80100630_MinigameHouse, 6, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 6, hund, 0);
    func_800672B0(D_80100630_MinigameHouse, 6, 1);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8860_MinigameHouse);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", D_801002BC_MinigameHouse);

// register allocation; retail hoists the buffer base out of three fill loops (masked 37)
#ifdef NON_MATCHING
char* func_800F9D64_MinigameHouse(s32 arg0) {
    u8* str;
    char* p;
    s32 len;
    s32 width;
    s32 n;
    s32 digits;
    s32 i;
    u16 score;

    str = func_8005B7E8(arg0 + 0x325);
    p = (char*)str;
#ifdef TARGET_PC
    len = func_8006D93C(str);
#else
    len = (s16)((s32 (*)(u8*))func_8006D93C)(str); /* retail: called as returning int */
#endif
    if (func_80059400(arg0) != 0 || func_8005949C(arg0) != 0) {
        n = 0;
        while (*p != 0) {
            if (*p != '\n') {
                *(n + D_80100410_MinigameHouse) = *p;
                n++;
            }
            p++;
        }
#ifdef TARGET_PC
        width = func_8006D99C(str, 0);
#else
        width = (s16)((s32 (*)(u8*, s16))func_8006D99C)(str, 0); /* retail: called as returning int */
#endif
    } else {
        for (n = 0; n < len; n++) {
            D_80100410_MinigameHouse[n] = 0xC3;
        }
        width = len * 6;
    }
    len = (0x83 - width) / 12;
    func_8005B838(str);
    if (D_80100632_MinigameHouse == 0 && func_8005949C(arg0) == 0) {
        score = D_80100100_MinigameHouse[arg0];
        if (len < 0) {
            len = 0;
        }
        for (i = 0; i < len; i++) {
            *(n + D_80100410_MinigameHouse) = 0xE;
            n++;
        }
        if (func_80059400(arg0) != 0) {
            sprintf((char*)&D_80100410_MinigameHouse[n], "%4d", score);
            return D_80100410_MinigameHouse;
        }
        digits = 1;
        if (score >= 10) {
            digits = (score >= 100) ? 3 : 2;
        }
        for (i = 0; i < 4 - digits; i++) {
            *(n + D_80100410_MinigameHouse) = ' ';
            n++;
        }
        for (i = 0; i < digits; i++) {
            *(n + D_80100410_MinigameHouse) = 0xC3;
            n++;
        }
    }
    D_80100410_MinigameHouse[n] = 0;
    return D_80100410_MinigameHouse;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F9D64_MinigameHouse);
#endif
s32 func_800F9FF4_MinigameHouse(s16 win, s32 grp, char* out) {
    char buf[0x58];
    s32 n;
    s32 cnt;
    s32 i;
    s32 j;
    char* name;
    void* title;

    n = 0;
    cnt = 0;
    for (i = D_80100170_MinigameHouse[grp].start; i < D_80100170_MinigameHouse[grp].end; i++) {
        D_80100624_MinigameHouse[n] = D_80100170_MinigameHouse[grp].list[i];
        func_8009B960(name = D_80100430_MinigameHouse[n], func_800F9D64_MinigameHouse(D_80100624_MinigameHouse[n] - 1));
        if (*name != (char)0xC3) {
            cnt++;
        } else {
            D_80100624_MinigameHouse[n] = 0;
        }
        func_8006DA5C(win, D_80100430_MinigameHouse[n], n);
        n++;
    }
    for (i = n; i < 10; i++) {
        D_80100624_MinigameHouse[i] = 0;
    }
    j = 0;
    for (i = 0; i < n; i++) {
        buf[j++] = 10;
        if (D_80100624_MinigameHouse[i] != 0) {
            if (func_8005949C(D_80100624_MinigameHouse[i] - 1) != 0) {
                buf[j++] = 5;
                buf[j++] = 0x3B;
                buf[j++] = 14;
                buf[j++] = 8;
            } else {
                buf[j++] = 14;
                buf[j++] = 8;
            }
        } else {
            buf[j++] = 14;
            buf[j++] = 7;
        }
        buf[j++] = 12;
        buf[j++] = i + 0x11;
        buf[j++] = 13;
    }
    buf[j++] = 8;
    buf[j] = 0;
    title = func_8005B7E8(D_80100170_MinigameHouse[grp].msg);
    sprintf(out, "\x08%s\n%s", title, buf);
    func_8005B838(title);
    return cnt;
}
void func_800FA2E4_MinigameHouse(void) {
    TextWindow* w;
    s16 spr;

    D_80100634_MinigameHouse = func_8006D010(0x82, 0x20, 0xD9, 0xB0, 0, 0);
    func_8007155C(D_80100634_MinigameHouse, (s16)(1 << GwPlayer[0].port));
    func_8006E0A4(D_80100634_MinigameHouse, -1);
    w = func_8006DD60(D_80100634_MinigameHouse);
    w->unk_04 = 0;
    w->unk_03 = 0;
    w->unk_09 = 0;
    spr = w->unk_44;
    func_800674BC(spr, 0, 0x8000);
    func_800674F4(spr, 8, 0, 0, 0);
    func_800674F4(spr, 7, 0, 0, 0);
}
void func_800FA3B0_MinigameHouse(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_80100624_MinigameHouse[i] == 0 ||
            (D_80100632_MinigameHouse == 0 &&
             (func_8005949C(D_80100624_MinigameHouse[i] - 1) != 0 ||
              (s32)GwCommon.coinNum < D_80100100_MinigameHouse[D_80100624_MinigameHouse[i] - 1]))) {
            func_80071788(D_80100634_MinigameHouse, i);
        }
    }
}
void func_800FA470_MinigameHouse(omObjData* obj) {
    TextWindow* w;
    s32 i;

    w = func_8006DD60(D_80100634_MinigameHouse);
    func_80066DC4(w->unk_44, 0, w->unk_14, w->unk_16);
    for (i = 0; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = 270.0f - (i * 90.0f) / 256.0f;
        func_8006752C(w->unk_44, 5, i);
        func_8006752C(w->unk_44, 8, i / 2);
        func_8006752C(w->unk_44, 7, i / 4);
        if (obj != NULL) {
            func_800211BC(obj->model[0], (i * 90) / 256);
        }
        HuPrcVSleep();
    }
    D_80100618_MinigameHouse->rot.z = 180.0f;
    func_8006752C(w->unk_44, 5, 0xFF);
    func_8006752C(w->unk_44, 8, 0x7F);
    func_8006752C(w->unk_44, 7, 0x3F);
    if (obj != NULL) {
        func_800211BC(obj->model[0], 90);
    }
}
void func_800FA600_MinigameHouse(omObjData* obj) {
    TextWindow* w;
    s32 i;
    s32 v;

    w = func_8006DD60(D_80100634_MinigameHouse);
    for (i = 0; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = (i * 90.0f) / 256.0f + 180.0f;
        v = 0xFF - i;
        func_8006752C(w->unk_44, 5, v);
        func_8006752C(w->unk_44, 8, v / 2);
        func_8006752C(w->unk_44, 7, v / 4);
        if (obj != NULL) {
            func_800211BC(obj->model[0], ((0xFF - i) * 90) / 256);
        }
        HuPrcVSleep();
    }
    D_80100618_MinigameHouse->rot.z = 270.0f;
    func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
    func_8006752C(w->unk_44, 5, 0);
    func_8006752C(w->unk_44, 8, 0);
    func_8006752C(w->unk_44, 7, 0);
    if (obj != NULL) {
        func_800211BC(obj->model[0], 0);
    }
    func_8006EB40(D_80100634_MinigameHouse);
    HuPrcVSleep();
}
void func_800FA7C0_MinigameHouse(char* msg) {
    s32 i;

    LoadStringIntoWindow(D_80100634_MinigameHouse, msg, -1, -1);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
    PlaySound(0x27);
    for (i = 0; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = 360.0f - (i * 90.0f) / 256.0f;
        HuPrcVSleep();
    }
    while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    func_800FA470_MinigameHouse(NULL);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
}
s32 func_800FA8D0_MinigameHouse(void) {
    if (D_80100632_MinigameHouse == 0) {
        return 0;
    }
    switch (D_800C5720) {
    case 1:
        return 3;
    case 0:
        return 0;
    case 2:
        return 4;
    default:
        return 5;
    }
}
u8 func_800FA92C_MinigameHouse(s32* sel) {
    char buf[0x68];
    s16 win;
    s32 min;
    s32 max;
    s32 prev;
    s32 res;
    s32 i;
    u32 btn;

    min = func_800FA8D0_MinigameHouse();
    max = 5;
    if (D_80100632_MinigameHouse != 0) {
        if (D_800C5720 != 0) {
            max = 6;
            if (D_800C5720 != 3) {
                max = min;
            }
        } else {
            max = 2;
        }
    }
    goto loop;
found:
    func_800F7218_MinigameHouse(D_80100624_MinigameHouse[res] - 1);
    return D_80100624_MinigameHouse[res];
loop:
    {
    }
    prev = *sel;
    while (1) {
        func_800F69A8_MinigameHouse();
        func_800258EC(D_8010061C_MinigameHouse->model[1], 4, 4);
        btn = func_80059CB8();
        if (btn & 0x8000) {
            func_800F69DC_MinigameHouse();
            PlaySound(0xF6);
            if (D_80100632_MinigameHouse != 0) {
                win = func_8006D010(0x18, 0x94, 0x81, 0x30, 0, 0);
                func_8006E070(win, 0);
                LoadStringIntoWindow(win, (void*)0x68, -1, -1);
                while (func_8006FCC0(win) != 0) {
                    HuPrcVSleep();
                }
            }
            func_800FA3B0_MinigameHouse();
            D_8010061C_MinigameHouse->unk_50 = func_8006DD60(D_80100634_MinigameHouse);
            D_8010061C_MinigameHouse->work[0] = 0xFF;
            res = func_8006FCF0(D_80100634_MinigameHouse, 0, 0);
            if (D_80100632_MinigameHouse != 0) {
                func_80070D90(win);
            }
            D_8010061C_MinigameHouse->unk_50 = NULL;
            if (res != -1) {
                goto found;
            }
        }
        if (btn & 0x4000) {
            break;
        }
        if (btn & 0x100) {
            (*sel)++;
            if (max < *sel) {
                *sel = max;
            }
        }
        if (btn & 0x200) {
            (*sel)--;
            if (*sel < min) {
                *sel = min;
            }
        }
        if (D_80100632_MinigameHouse == 0) {
            func_800F6A10_MinigameHouse(0, 0x82, 0x1C);
        } else {
            func_800F6A10_MinigameHouse(0, 0x98, 0x1C);
        }
        if (*sel == min) {
            func_80018C90(D_80100582_MinigameHouse[0]);
        }
        if (*sel == max) {
            func_80018C90(D_80100582_MinigameHouse[1]);
        }
        if (prev != *sel) {
            func_800F69DC_MinigameHouse();
            func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, *sel, buf);
            if (btn & 0x100) {
                func_800FA600_MinigameHouse(NULL);
                func_800FA7C0_MinigameHouse(buf);
            } else {
                func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
                PlaySound(0x27);
                func_800FA600_MinigameHouse(NULL);
                LoadStringIntoWindow(D_80100634_MinigameHouse, buf, -1, -1);
                for (i = 0x20; i < 0x100; i += 0x20) {
                    D_80100618_MinigameHouse->rot.z = (i * 90.0f) / 256.0f + 270.0f;
                    HuPrcVSleep();
                }
                func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
                while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
                    HuPrcVSleep();
                }
                func_800FA470_MinigameHouse(NULL);
            }
        }
        prev = *sel;
        HuPrcVSleep();
    }
    func_800F69DC_MinigameHouse();
    PlaySound(0xF8);
    return 0;
}
s32 func_800FAD28_MinigameHouse(s16* out, s16 y) {
    s32 i;
    s32 n;
    s32 max;

    for (i = 0, max = 0; i < 4; i++) {
        if (max < GwPlayer[i].coins) {
            max = GwPlayer[i].coins;
        }
    }
    for (i = 0, n = 0; i < 4; i++) {
        if (max == GwPlayer[i].coins) {
            out[n] = GwPlayer[i].character;
            n++;
        }
    }
    if (n >= 4) {
        n = 0;
    }
    for (i = 0; i < n; i++) {
        D_80100638_MinigameHouse[i] = func_800429CC(out[i], 0);
        D_80100638_MinigameHouse[i]->x = (i * 2 - n) * 40 + 200;
        D_80100638_MinigameHouse[i]->y = y;
        D_80100638_MinigameHouse[i]->flags |= 2;
        D_80100638_MinigameHouse[i]->attr = 0x6000;
    }
    return n;
}
// retail keeps the final 1/0 as a branch; GCC here folds it to sltu (masked 3)
#ifdef NON_MATCHING
s32 func_800FAE94_MinigameHouse(s32 cat) {
    s32 ret;
    s32 r;
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; i < D_801001C4_MinigameHouse[cat].count; i++) {
        n += func_8005949C(D_801001C4_MinigameHouse[cat].list[i] - 1) != 0;
    }
    r = n < 5;
    if (((cat == 0) | (cat == 3)) == 0) {
        r = n < 3;
    }
    if (r != 0) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FAE94_MinigameHouse);
#endif
s32 func_800FAF5C_MinigameHouse(s16 win) {
    char buf[2][3];
    s32 total;
    s32 left;
    s32 c;
    s32 i;
    s32 n;

    total = 0;
    left = 0;
    for (c = 0; c < 4; c++) {
        n = 0;
        for (i = 0; i < D_801001C4_MinigameHouse[c].count; i++) {
            if (func_80059400(D_801001C4_MinigameHouse[c].list[i] - 1) != 0 ||
                func_8005949C(D_801001C4_MinigameHouse[c].list[i] - 1) != 0) {
                n++;
            }
        }
        left += D_801001C4_MinigameHouse[c].count - n;
        total += n;
    }
    sprintf(buf[0], "%02d", total);
    func_8006DA5C(win, buf[0], 0);
    sprintf(buf[1], "%02d", left);
    func_8006DA5C(win, buf[1], 1);
    LoadStringIntoWindow(win, (void*)0x57, -1, -1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    return total;
}
s32 func_800FB108_MinigameHouse(s16 win) {
    char buf[3];
    s32 total;
    s32 c;
    s32 i;
    s32 n;

    total = 0;
    for (c = 0; c < 4; c++) {
        n = 0;
        for (i = 0; i < D_801001C4_MinigameHouse[c].count; i++) {
            n += func_8005949C(D_801001C4_MinigameHouse[c].list[i] - 1) != 0;
        }
        total += n;
    }
    sprintf(buf, "%02d", total);
    func_8006DA5C(win, buf, 0);
    LoadStringIntoWindow(win, (void*)0x58, -1, -1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    return total;
}
void func_800FB238_MinigameHouse(void) {
    func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[2], 0, 10, 1);
    HuPrcSleep(5);
    func_8002888C(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[2]);
    HuPrcSleep(12);
    PlaySound(0x25);
    func_80025EB4(D_8010060C_MinigameHouse->model[1], 5, 0);
    func_8005A258(D_80100614_MinigameHouse->model[0]);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB2DC_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB7E0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB96C_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FBAC0_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FBB28_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FBFA4_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC090_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC110_MinigameHouse);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC204_MinigameHouse);





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
