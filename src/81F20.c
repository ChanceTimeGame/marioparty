#include "common.h"

// 64DD driver (libleo) microsequence loader (leoSet_mseq and its two tables) and the command
// queue flush (MP2 990A0.c), built with IDO 5.3. Its rodata (CC770-CC7F8) follows 80BE0.c's jump
// tables: IDO emits a file's const data before its jump tables, so this is a separate file.
// func_80081320 does not match yet and stays asm.

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

// Current transfer target (splat also labels +2 and +6 separately)
typedef struct LEOTgtParam {
    /* 0x00 */ u16 lba;
    /* 0x02 */ u16 cylinder;
    /* 0x04 */ u16 blk_bytes;
    /* 0x06 */ u8 sec_bytes;
    /* 0x07 */ u8 head;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 rdwr_blocks;
    /* 0x0A */ u8 unkA;
} LEOTgtParam;

// C1 error report handed to the interrupt thread
typedef struct LEORwInfo {
    /* 0x00 */ u8* dram;
    /* 0x04 */ u8* c2end;
    /* 0x08 */ u8 errSector[4];
    /* 0x0C */ u8 errNum;
    /* 0x0D */ u8 secBytes;
    /* 0x0E */ u16 blkBytes;
} LEORwInfo; // sizeof 0x10

u32 func_80080170(void);
s32 func_8008076C(void);
void func_800807D4(void);
u8 func_800808BC(void);
u8 func_800809D0(void);
u8 func_80080ADC(u32 asic_cmd);
u8 func_80080BC4(u32 asic_cmd);
u8 func_80080D78(u32 asic_cmd, u32 asic_data);
u8 func_80080E20(u32 asic_cmd);
u8 func_80080E70(u32 asic_cmd, u32 asic_data);
u8 func_80080F94(void);
u8 func_8008100C(u16 rwmode);
s32 func_800810AC(s32 control);
s32 func_80081100(u32 sense);
void func_80081250(void);
void func_80081320(u16 rwmode);
void func_800815F0(u16 lba);

extern OSMesg D_800E7A90;
extern OSMesgQueue D_800E7A98;
extern u32 D_800E7AB0;
extern u32 D_800E7AB4;
extern u32 D_800E7AC0[16];
extern OSThread D_800E7D98;
extern OSMesgQueue D_800E8748;
extern OSMesgQueue D_800E8760;
extern OSMesgQueue D_800E8778;
extern OSMesgQueue D_800E8790;
extern u8* D_800E87D4;
extern LEOCmdRead* D_800E87D8;
extern u32 D_800E87DC;
extern u32 D_800E87E0;
extern u8 D_800E87E4;
extern volatile u16 D_800E87E6;
extern LEOTgtParam D_800E87F0;
extern u8 D_800E9A00[0x3A0];
extern u8 D_800E9DA0[0x3A0];
extern LEORwInfo D_800EA140;
extern OSPiHandle* D_800EA150;
extern OSIoMesg D_800EA158;
extern s32 D_800EA170;

// read microsequence (loaded by func_80081320)
const u32 D_800CBB70[16] = {
    0x00010000, 0x00020200, 0x80030100, 0x82040000, 0xA8050000, 0xA0060600,
    0x31760000, 0x00020300, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x04060000,
};

// write microsequence
const u32 D_800CBBB0[16] = {
    0x40020000, 0x00020000, 0x40130B00, 0x42140100, 0x68050000, 0x50060600,
    0x401702FF, 0x01870000, 0x40020000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x040F0000,
};

// unreferenced; ends this unit's rodata
const char D_800CBBF0[] = "B014A26";

// IDO-compiled libleo (leoSet_mseq: load the read or write microsequence)
#ifdef NON_MATCHING
void func_80081320(u16 rwmode) {
    u32* src;
    u8 i;
    u32 secm1;
    u32 sec;

    D_800E87E0 &= ~0x40000000;
    osEPiWriteIo(D_800EA150, 0x05000518, D_800E87E0);
    if (rwmode == 1) {
        src = D_800CBBB0;
    } else {
        src = D_800CBB70;
    }
    for (i = 0; i < 16; i++) {
        D_800E7AC0[i] = *src++;
    }
    secm1 = D_800E87F0.sec_bytes - 1;
    D_800E7AC0[4] |= secm1 << 8;
    osWritebackDCache(D_800E7AC0, sizeof(D_800E7AC0));
    D_800EA158.dramAddr = D_800E7AC0;
    D_800EA158.devAddr = 0x05000580;
    D_800EA158.size = sizeof(D_800E7AC0);
    D_800EA150->transferInfo.cmdType = OS_OTHERS;
    osEPiStartDma(D_800EA150, &D_800EA158, OS_WRITE);
    osRecvMesg(&D_800E8790, NULL, OS_MESG_BLOCK);
    osEPiWriteIo(D_800EA150, 0x05000530, ((secm1 + 7) | 0x5900) << 16);
    sec = secm1 << 8;
    if (D_800E87E6 & 0x800) {
        sec += 0x100;
    }
    osEPiWriteIo(D_800EA150, 0x05000528, sec << 8);
    D_800E87E0 |= 0x40000000;
    osEPiWriteIo(D_800EA150, 0x05000518, D_800E87E0);
}
#else
INCLUDE_ASM("asm/nonmatchings/81F20", func_80081320);
#endif

// IDO-compiled libleo (flush the command queue: every pending command is terminated)
void func_800814D0(void) {
    LEOCmdHeader* cmd;

    while (osRecvMesg(&D_800E8748, (OSMesg*)&cmd, OS_MESG_NOBLOCK) == 0) {
        cmd->sense_code = 0x22;
        cmd->status = 2;
        if (cmd->control & 0x80) {
            osSendMesg(cmd->post, (OSMesg)0x22, OS_MESG_BLOCK);
        }
    }
}

// IDO-compiled libleo
void func_80081578(void) {
    u32 sense;

    sense = func_800809D0();
    if (sense == 3 || sense == 0x29 || sense == 0x2B) {
        D_800E87D8->header.sense_code = sense;
        D_800E87D8->header.status = 2;
    } else {
        D_800E87D8->header.sense_code = 0;
        D_800E87D8->header.status = 0;
    }
}

