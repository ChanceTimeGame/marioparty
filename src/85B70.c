#include "common.h"
#include "sdk_leo.h"

// libleo: leoWrite, the RTC commands (leoReadTimer, leoSetTimer) and their RTC helpers. IDO 5.3; a unit of
// its own because leowrite.c sees the transfer flags (D_800E87E6) as a plain u16, the read unit as volatile.

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

#ifdef NON_MATCHING
// leoWrite
void func_80084F70(void) {
    u32 msg;
    u32 lba = LEO_CUR(LEOCmdRead)->lba;
    u32 xfer = LEO_CUR(LEOCmdRead)->xfer_blks;

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
#else
INCLUDE_ASM("asm/nonmatchings/85B70", func_80084F70);
#endif

#ifdef NON_MATCHING
// leoReadTimer
void func_800850A0(void) {
    u8 rtc[6];
    u8 sense = func_80085394(rtc);

    LEO_CUR(LEOCmdReadTimer)->yearlo = rtc[0];
    LEO_CUR(LEOCmdReadTimer)->month = rtc[1];
    LEO_CUR(LEOCmdReadTimer)->day = rtc[2];
    LEO_CUR(LEOCmdReadTimer)->hour = rtc[3];
    LEO_CUR(LEOCmdReadTimer)->minute = rtc[4];
    LEO_CUR(LEOCmdReadTimer)->second = rtc[5];
    if (sense != 0) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if (LEO_CUR(LEOCmdReadTimer)->yearlo >= 0x96U) {
        LEO_CUR(LEOCmdReadTimer)->yearhi = 0x19;
    } else {
        LEO_CUR(LEOCmdReadTimer)->yearhi = 0x20;
    }
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/85B70", func_800850A0);
#endif

#ifdef NON_MATCHING
// leoSetTimer: validate the BCD date (year, month, day, hour, minute, second), write it, read it back
void func_8008515C(void) {
    LEOCmdReadTimer* cmd = D_800E87D8;
    u8* p = &cmd->yearlo;
    u8 rtc[6];
    u32 prev = 0;  // the field before this one
    u32 prev2 = 0; // the one before that
    u32 v;
    u32 i;
    u8 sense;

    for (i = 0; i < 6; i++) {
        v = p[i];
        if ((v & 0xF) >= 10) {
            goto invalid;
        }
        v -= (v >> 4) * 6;
        if (i == 2) {
            // day: 29 February only in a leap year
            if ((D_800CC2B8[prev] < v) && ((v != 29) || ((prev2 & 3) != 0))) {
                goto invalid;
            }
        }
        if (((i == 1) || (i == 2)) && (v == 0)) {
            goto invalid;
        }
        if (D_800CC2B0[i] < v) {
            goto invalid;
        }
        prev2 = prev;
        prev = v;
    }
    rtc[0] = cmd->yearlo;
    rtc[1] = cmd->month;
    rtc[2] = cmd->day;
    rtc[3] = cmd->hour;
    rtc[4] = cmd->minute;
    rtc[5] = cmd->second;
    if ((sense = func_80085504(rtc)) != 0) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if ((sense = func_80085394(rtc)) != 0) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    cmd = D_800E87D8;
    if ((cmd->yearlo != rtc[0]) || (cmd->month != rtc[1]) || (cmd->day != rtc[2]) ||
        (cmd->hour != rtc[3]) || (cmd->minute != rtc[4]) || (cmd->second != rtc[5])) {
        cmd->header.sense_code = 0x24;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    cmd->header.status = LEO_STATUS_GOOD;
    return;

invalid:
    cmd->header.sense_code = 0x24; // invalid field
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/85B70", func_8008515C);
#endif

// read the RTC: year, month, day, hour, minute, second
u8 func_80085394(u8* rtc) {
    u32 data;
    u8 sense;

    if ((sense = func_80080EA8(0x140000, 0)) != 0) {
        return sense;
    }
    osEPiReadIo(D_800EA150, 0x05000500, &data);
    rtc[4] = (data & 0xFF000000) >> 24;
    rtc[5] = (data & 0xFF0000) >> 16;
    if ((sense = func_80080EA8(0x130000, 0)) != 0) {
        rtc[4] &= 0xFF7F;
        return sense;
    }
    osEPiReadIo(D_800EA150, 0x05000500, &data);
    rtc[2] = (data & 0xFF000000) >> 24;
    rtc[3] = (data & 0xFF0000) >> 16;
    if ((sense = func_80080EA8(0x120000, 0)) != 0) {
        rtc[4] &= 0xFF7F;
        return sense;
    }
    osEPiReadIo(D_800EA150, 0x05000500, &data);
    rtc[0] = (data & 0xFF000000) >> 24;
    rtc[1] = (data & 0xFF0000) >> 16;
    if (rtc[4] & 0x80) {
        rtc[4] &= 0xFF7F;
        return 5;
    }
    return 0;
}

// set the RTC from 6 bytes (year, month, day, hour, minute, second)
u8 func_80085504(u8* rtc) {
    u32 yearMonth = (rtc[1] << 16) + (rtc[0] << 24);
    u32 dayHour = (rtc[3] << 16) + (rtc[2] << 24);
    u32 minSec = (rtc[5] << 16) + (rtc[4] << 24);
    u8 sense;

    if ((sense = func_80080EA8(0xF0000, yearMonth)) != 0 ||
        (sense = func_80080EA8(0x100000, dayHour)) != 0 ||
        (sense = func_80080EA8(0x110000, minSec)) != 0) {
        return sense;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/85B70", D_800CC2B0);

INCLUDE_RODATA("asm/nonmatchings/85B70", D_800CC2B8);
