#include "common.h"

// libleo manager API, built with IDO 5.3.

typedef struct LEOCmdHeader {
    /* 0x00 */ u8 command;
    /* 0x01 */ u8 reserve1;
    /* 0x02 */ u8 control;
    /* 0x03 */ u8 reserve3;
    /* 0x04 */ u8 status;
    /* 0x05 */ u8 sense_code;
    /* 0x06 */ u8 reserve6;
    /* 0x07 */ u8 reserve7;
    /* 0x08 */ OSMesgQueue* post;
} LEOCmdHeader; // sizeof 0xC

typedef struct LEOCmdRead {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 lba;
    /* 0x10 */ u32 xfer_blks;
    /* 0x14 */ u8* buff_ptr;
    /* 0x18 */ u32 rw_bytes;
} LEOCmdRead; // sizeof 0x1C

extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);

void func_80083E60(void*);
void func_8007FFE0(void*);
void func_80081250(void);
void func_800814D0(void);

extern s32 D_800C63C0;
extern s32 D_800C63C4;
extern LEOCmdHeader D_800CBAF0;
extern OSMesgQueue D_800E7A70;
extern OSMesg D_800E7A88;
extern OSThread D_800E7BE8;
extern OSThread D_800E7D98;
extern u8 D_800E8348[];
extern OSMesgQueue D_800E8748;
extern OSMesgQueue D_800E8760;
extern OSMesgQueue D_800E8778;
extern OSMesgQueue D_800E8790;
extern OSMesgQueue D_800E87A8;
extern OSMesg D_800E87C0;
extern OSMesg D_800E87C4;
extern OSMesg D_800E87C8[2];
extern OSMesg D_800E87D0;
extern volatile u8 D_800E87E5;

// libleo (LeoCreateLeoManager)
void func_8007FB70(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri curPri;
    OSPri myPri;

    if (intPri < comPri) {
        myPri = comPri;
    } else {
        myPri = intPri;
    }
    oldPri = -1;
    curPri = osGetThreadPri(NULL);
    if (curPri < myPri) {
        oldPri = curPri;
        osSetThreadPri(NULL, myPri);
    }
    savedMask = __osDisableInt();
    D_800C63C4 = 1;
    osCreateMesgQueue(&D_800E8748, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&D_800E8778, &D_800E87C4, 1);
    osCreateMesgQueue(&D_800E8760, &D_800E87C0, 1);
    osCreateMesgQueue(&D_800E8790, D_800E87C8, 2);
    osCreateMesgQueue(&D_800E87A8, &D_800E87D0, 1);
    osCreateMesgQueue(&D_800E7A70, &D_800E7A88, 1);
    osCreateThread(&D_800E7BE8, 1, func_80083E60, NULL, D_800E8348, comPri);
    osStartThread(&D_800E7BE8);
    osCreateThread(&D_800E7D98, 1, func_8007FFE0, NULL, &D_800E8748, intPri);
    osStartThread(&D_800E7D98);
    osSetEventMesg(OS_EVENT_CART, &D_800E8760, (OSMesg)0x30000);
    osSendMesg(&D_800E87A8, NULL, OS_MESG_NOBLOCK);
    __osRestoreInt(savedMask);
    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

// libleo (leoCommand)
void func_8007FD44(LEOCmdRead* cmd) {
    if (D_800C63C0 != 0) {
        cmd->header.status = 2;
        cmd->header.sense_code = 0x25;
        if (cmd->header.control & 0x80) {
            osSendMesg(cmd->header.post, (OSMesg)0x25, OS_MESG_BLOCK);
        }
        return;
    }
    osRecvMesg(&D_800E87A8, NULL, OS_MESG_BLOCK);
    cmd->header.status = 8;
    cmd->header.sense_code = 0;
    switch (cmd->header.command) {
        case 1:
            D_800E87E5 = 0xFF;
            func_800814D0();
            D_800E87E5 = 0;
            cmd->header.status = 0;
            if (cmd->header.control & 0x80) {
                osSendMesg(cmd->header.post, NULL, OS_MESG_BLOCK);
            }
            break;
        case 5:
        case 6:
            cmd->rw_bytes = 0;
            goto send;
        default:
            if ((u32)(cmd->header.command - 1) >= 14) {
                cmd->header.sense_code = 0x1F;
                cmd->header.status = 2;
                break;
            }
        send:
            if (osSendMesg(&D_800E8748, cmd, OS_MESG_NOBLOCK) != 0) {
                cmd->header.sense_code = 0x23;
                cmd->header.status = 2;
            }
            break;
    }
    osSendMesg(&D_800E87A8, NULL, OS_MESG_BLOCK);
}

// libleo (LeoReset)
void func_8007FEA4(void) {
    D_800C63C0 = 1;
    if (D_800C63C4 != 0) {
        D_800E87E5 = 0xFF;
        func_800814D0();
        D_800E87E5 = 0;
        osRecvMesg(&D_800E8760, NULL, OS_MESG_NOBLOCK);
        osSendMesg(&D_800E8760, (OSMesg)0xA0000, OS_MESG_BLOCK);
        osSendMesg(&D_800E8748, &D_800CBAF0, OS_MESG_BLOCK);
    }
}

// libleo (LeoResetClear)
s32 func_8007FF34(void) {
    func_80081250();
    return 0;
}

// libleo (LeoTestUnitReady)
u8 func_8007FF58(void) {
    LEOCmdHeader cmd;

    cmd.command = 0xF;
    cmd.control = 0x80;
    cmd.status = 0;
    cmd.post = &D_800E7A70;
    if (osSendMesg(&D_800E8748, &cmd, OS_MESG_NOBLOCK) != 0) {
        return 0x23;
    }
    osRecvMesg(&D_800E7A70, NULL, OS_MESG_BLOCK);
    if (cmd.status == 0) {
        return 0;
    }
    return cmd.sense_code;
}
