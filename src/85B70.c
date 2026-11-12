#include "common.h"
#include "sdk_leo.h"

// libleo leowrite.c: leoWrite. IDO 5.3; a unit of its own because leowrite.c sees the transfer flags
// (D_800E87E6) as a plain u16, the read unit as volatile.

typedef struct LEOCmdReadTimer {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 reserve12;
    /* 0x0D */ u8 yearhi;
    /* 0x0E */ u8 yearlo;
    /* 0x0F */ u8 month;
    /* 0x10 */ u8 day;
    /* 0x11 */ u8 hour;
    /* 0x12 */ u8 minute;
    /* 0x13 */ u8 second;
} LEOCmdReadTimer;

#define LEO_CUR(type) ((type*)D_800E87D8)
#define LEO_STATUS_GOOD 0
#define LEO_STATUS_CHECK_CONDITION 2

extern void* D_800E87D8;        // LEOcur_command
extern u16 D_800E87E6;
extern OSPiHandle* D_800EA150;  // LEOPiInfo
extern u16 D_800CBD98[];        // first user lba per disk type
extern u8 D_800CC2B0[];         // RTC field maxima
extern u8 D_800CC2B8[];         // days per month
extern OSThread D_800E7D98;     // read/write thread
extern OSMesgQueue D_800E8778;

u8 func_80080EA8(u32 asic_cmd, u32 asic_data);
u8 func_80085394(u8* rtc); // read the RTC (6 bytes)
u8 func_80085504(u8* rtc); // set the RTC (6 bytes)

// leoWrite
void func_80084F70(void) {
    u32 msg;
    u32 lba = LEO_CUR(LEOCmdRead)->lba;
    u32 xfer = LEO_CUR(LEOCmdRead)->xfer_blks;
    u32 write_bytes = 0;
    u8 retry_count = 0;

    if ((lba | xfer) & 0xFFFF0000) {
        goto out_of_range;
    }
    lba += 0x18;
    if ((lba >= 0x10DC) || (lba + xfer > 0x10DC)) {
    out_of_range:
        LEO_CUR(LEOCmdHeader)->sense_code = 0x20; // LBA out of range
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if (lba < D_800CBD98[D_800E87E8]) {
        LEO_CUR(LEOCmdHeader)->sense_code = 0x21; // write protect (system area)
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if (xfer == 0) {
        LEO_CUR(LEOCmdHeader)->sense_code = 0;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        return;
    }
    D_800E87E6 = 0x8000;
    D_800E87F0.lba = lba;
    osStartThread(&D_800E7D98);
    osRecvMesg(&D_800E8778, (OSMesg*)&msg, OS_MESG_BLOCK);
    if (msg != 0x90000) {
        LEO_CUR(LEOCmdHeader)->sense_code = msg;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEO_CUR(LEOCmdHeader)->sense_code = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}

