#include "common.h"
#include "engine/process.h"

void func_8001DFC0(void);
void func_80025658(s32, s32);
void func_8002B6C8(void);
void pfClsScr(void);
void omMain(void);
void func_80018B2C(void);
void func_8001E5A0(s32);
void func_800247FC(void*, s32);
void func_80052CCC(s32, s32);
void func_800594E4(s32, s32);
extern s8 D_800ED558[];
extern s16 D_800F3778;
extern s32 D_800ED538;
s32 _CheckFlag(s32);
void func_8000B00C(s32, s32, void*, s32);
void* func_8000B2BC(void);
void func_8000B364(s32);
void func_8000BE98(Addr*, Addr*, s32, s32, s32);
void func_80010C30(Addr*, s32, s32, s32);
void func_8001A3DC(void);
void func_8001A428(void);
void func_8001A454(void);
void func_80023B40(void* (*)(s32), void (*)(void*), u16, u16, s32, s32);
void func_8003B710(void);
s32 func_8005B0C4(void);
void func_8005B6D0(Addr*);
void pfInit(void);
void func_80072190(void);
extern Addr D_1778BC0;
extern Addr D_1832AE0;
extern Addr D_1BB8460;
extern Addr D_1CECC60;
extern Addr D_1CED490;
extern s16 D_800C599E;
extern s16 D_800C59A0;
extern f32 CZoomM[4];
extern u16 D_800ED726;
extern Process* D_800F2BD0;
extern Process* D_800F3700;
extern u8 D_800F3705;
extern u16 D_800F3F30;
extern Vec3f CenterM[4];
extern u16 D_800F64EC;
extern Vec3f CRotM[6];
extern Addr D_FCB860;

void func_8001A0F0(void) {
    file_1ACF0_struct* temp_s1;
    s32 temp_s0;
    s32 i;
    
    HuPrcVSleep();
    CRot.x = 325.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 2250.0f;
    Center.x = Center.y = Center.z = 0.0f;
    
    for (i = 0; i < 4; i++) {
        CRotM[i].x = 325.0f;
        CRotM[i].y = CRotM[i].z = 0.0f;
        CZoomM[i] = 2250.0f;
        CenterM[i].x = CenterM[i].y = CenterM[i].z = 0.0f;
    }
    
    D_800F3705 = 3;
    D_800F3F30 = 0x1000;
    D_800ED726 = 0x2004;
    D_800F64EC = 0x180;
    func_80072190();
    func_80023B40(HuMemDirectMalloc, HuMemDirectFree, D_800F3F30, D_800ED726, D_800F64EC, D_800F3705);
    InitCameras(1);
    pfInit();
    func_8005B6D0(&D_FCB860);
    func_8003B710();
    D_800F2BD0 = HuPrcCreate(func_8001A3DC, 0xF000, 0x3000, 0);
    HuPrcCreate(func_8001A428, 0x4000, 0x3000, 0);
    D_800F3700 = HuPrcCreate(func_8001A454, 0x1000, 0x3000, 0);
    func_8001A498();
    temp_s0 = func_8005B0C4();
    temp_s1 = func_8000B2BC();
    
    if (temp_s0 == 1) {
        omOvlCallEx(0x68, 0, 0x81);
    } else {
        omOvlCallEx(0x67, 0, 0x81);
    }
    
    func_80010C30(&D_1BB8460, 0, 0, 0);
    func_8000BE98(&D_1778BC0, &D_1832AE0, 0, 0, 0);
    D_800C59A0 = 1;
    D_800C599E = 1;
    temp_s1->unk_24 = &D_1CECC60;
    temp_s1->unk_28 = &D_1CED490;
    temp_s1->unk_40 = 0x14;
    func_8000B00C(0x6E, 0, (void*)0x802E0000, 0x80000);
    
    if (_CheckFlag(0x10) != 0) {
        func_8000B364(0);
    } else {
        func_8000B364(1);
    }

    HuPrcKill(HuPrcCurrentGet());
    
    while (1) {
        HuPrcVSleep();
    }
    
}

void func_8001A3DC(void) {
    while (1) {
        HuPrcVSleep();
        func_8002B6C8();
        func_8001DFC0();
        func_80025658(0x02000000, 0x3D0800);
        pfClsScr();        
    }
}

void func_8001A428(void) {
    while (1) {
        HuPrcVSleep();
        omMain();       
    }
}

void func_8001A454(void) {
    while (1) {
        HuPrcVSleep();
        func_80018B2C();
        func_8001E5A0(2);
        func_800247FC(&D_800ED538, 2);        
    }
}

void func_8001A498(void) {
    s32 i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        if (i < D_800F3778) {
            D_800ED558[i] = 0;
            GwPlayer[i].flags = GwPlayer[i].flags & ~1;
        } else {
            D_800ED558[i] = 1;
            GwPlayer[i].flags = GwPlayer[i].flags | 1;
        }
        
        GwPlayer[i].port = i;
        GwPlayer[i].coins = 10;
        GwPlayer[i].coins_mg = 0;
        GwPlayer[i].group = i;
        func_80052CCC(i, 1);
        GwPlayer[i].stars = 0;
    }
    
    func_800594E4(0, 0x4650);
    func_800594E4(1, 0xE10);
    func_800594E4(2, 0xE10);
    func_800594E4(3, 0x4650);
    func_800594E4(5, 0xE10);
    func_800594E4(6, 0xE10);
    func_800594E4(7, 0xE10);
}
