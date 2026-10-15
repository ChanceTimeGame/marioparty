#include "common.h"
#include "sdk_leo.h"

// libleo command execution (the leocmdex.c family): the per-command handlers the command thread
// runs on the current command (D_800E87D8), the drive's RTC, and the C2 (Reed-Solomon) error
// correction. IDO-compiled: NON_MATCHING (see sdk_leo.h).

typedef struct LEOCmdTestUnitReady {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 test;
} LEOCmdTestUnitReady;

typedef struct LEOCmdReadCapacity {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 startLBA;
    /* 0x10 */ u32 endLBA;
    /* 0x14 */ u32 nbytes;
} LEOCmdReadCapacity;

typedef struct LEOCmdModeSelect {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 page;
    /* 0x0D */ u8 reserve1;
    /* 0x0E */ u8 standby_time;
    /* 0x0F */ u8 sleep_time;
    /* 0x10 */ u32 led_on_time;
} LEOCmdModeSelect;

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
extern u8 D_800CBDD0[];         // GF(256) exponent table (doubled)
extern u8 D_800CBECF[];         // = D_800CBDD0 + 0xFF
extern u8 D_800CBFD0[];         // GF(256) logarithm table
extern u16 D_800CBD98[];        // first user lba per disk type
extern u32 D_800CBDA8[];        // capacity in bytes per disk type

u8 func_80080E70(u32 asic_cmd, u32 asic_data);
u8 func_80080EA8(u32 asic_cmd, u32 asic_data);
u8 func_80080FE4(void);
u8 func_80081070(void);
s32 func_80081100(u32 sense);
u8 func_80081210(void);

void func_8008499C(u32 start); // leoRead_common
u8 func_80085394(u8* rtc);     // read the RTC (6 bytes)

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBD98);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBDA8);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBDD0);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBFD0);

INCLUDE_ASM("asm/nonmatchings/83960", func_80082D60);

INCLUDE_ASM("asm/nonmatchings/83960", func_80082DEC);

INCLUDE_ASM("asm/nonmatchings/83960", func_80082EC0);

INCLUDE_ASM("asm/nonmatchings/83960", func_80083140);

INCLUDE_ASM("asm/nonmatchings/83960", func_80083528);

#ifdef NON_MATCHING
// GF(256) multiply
u8 func_80083DC4(u8 a, u8 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800CBDD0[D_800CBFD0[b] + D_800CBFD0[a]];
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083DC4);
#endif

#ifdef NON_MATCHING
// GF(256) divide
u8 func_80083E08(u8 a, u8 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800CBECF[D_800CBFD0[a] - D_800CBFD0[b]];
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083E08);
#endif

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC1F0);

INCLUDE_ASM("asm/nonmatchings/83960", func_80083E60);

INCLUDE_ASM("asm/nonmatchings/83960", func_800842DC);

#ifdef NON_MATCHING
// leoInquiry
void func_800844F0(void) {
    u32 asic_id;
    u32 asic_data;

    osEPiReadIo(D_800EA150, 0x05000540, &asic_id); // ASIC_ID_REG
    if (func_80080E70(0x1B0000, 0) == 0) {
        osEPiReadIo(D_800EA150, 0x05000500, &asic_data); // ASIC_DATA
        if (asic_data & 0x10000) {
            asic_id |= 0x100000;
        }
    }
    LEO_CUR(LEOCmdInquiry)->dev_type = 0;
    LEO_CUR(LEOCmdInquiry)->version = asic_id >> 16;
    LEO_CUR(LEOCmdInquiry)->dev_num = 1;
    LEO_CUR(LEOCmdInquiry)->leo_bios_ver = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800844F0);
#endif

#ifdef NON_MATCHING
// leoMode_sel
void func_800845A0(void) {
    u8 sense;

    if (((sense = func_80080EA8(0x60000, LEO_CUR(LEOCmdModeSelect)->standby_time << 16)) != 0) ||
        ((sense = func_80080EA8(0x70000, LEO_CUR(LEOCmdModeSelect)->sleep_time << 16)) != 0) ||
        ((sense = func_80080EA8(0x150000, LEO_CUR(LEOCmdModeSelect)->led_on_time)) != 0)) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800845A0);
#endif

INCLUDE_ASM("asm/nonmatchings/83960", func_80084650);

#ifdef NON_MATCHING
// leoReadCapacity
void func_80084740(void) {
    LEOCmdReadCapacity* cmd = D_800E87D8;

    if (cmd->header.control & 1) {
        cmd->startLBA = D_800CBD98[D_800E87E8] - 0x18;
        LEO_CUR(LEOCmdReadCapacity)->endLBA = 0x10C3;
        LEO_CUR(LEOCmdReadCapacity)->nbytes = D_800CBDA8[D_800E87E8];
    } else {
        cmd->startLBA = 0;
        LEO_CUR(LEOCmdReadCapacity)->endLBA = 0x10C3;
        LEO_CUR(LEOCmdReadCapacity)->nbytes = 0x3D78F40;
    }
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084740);
#endif

INCLUDE_ASM("asm/nonmatchings/83960", func_800847E0);

#ifdef NON_MATCHING
// leoRead
void func_80084970(void) {
    D_800E87E6 = 0;
    func_8008499C(0x18);
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084970);
#endif

INCLUDE_ASM("asm/nonmatchings/83960", func_8008499C);

#ifdef NON_MATCHING
// leoRezero
void func_80084B30(void) {
    u8 retry = 8;
    u8 sense;

    while (TRUE) {
        sense = func_80080FE4();
        if (sense == 0) {
            D_800E87F0.cylinder = 0;
            D_800E87F0.head = 0;
            D_800E87F0.zone = 0;
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80081100(sense) != 0) {
            break;
        }
        if (retry-- == 0) {
            break;
        }
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084B30);
#endif

#ifdef NON_MATCHING
// leoSeek
void func_80084BD0(void) {
    u8 retry = 20;
    u8 sense;

    if (LEO_CUR(LEOCmdRead)->lba >= 0x10C4) {
        LEO_CUR(LEOCmdHeader)->sense_code = 0x20; // LBA out of range
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    func_800815F0(LEO_CUR(LEOCmdRead)->lba + 0x18);
    while (TRUE) {
        sense = func_80081070();
        if (sense == 0) {
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80081100(sense) != 0) {
            break;
        }
        if (retry-- == 0) {
            break;
        }
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084BD0);
#endif

#ifdef NON_MATCHING
// leoTest_unit_rdy
void func_80084C90(void) {
    LEO_CUR(LEOCmdTestUnitReady)->test = func_80081210();
    LEO_CUR(LEOCmdHeader)->sense_code = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084C90);
#endif

INCLUDE_ASM("asm/nonmatchings/83960", func_80084CD0);

INCLUDE_ASM("asm/nonmatchings/83960", func_80084F70);

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
    LEO_CUR(LEOCmdReadTimer)->yearhi = (LEO_CUR(LEOCmdReadTimer)->yearlo < 0x96) ? 0x20 : 0x19;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800850A0);
#endif

INCLUDE_ASM("asm/nonmatchings/83960", func_8008515C);

INCLUDE_ASM("asm/nonmatchings/83960", func_80085394);

#ifdef NON_MATCHING
// set the RTC from 6 bytes (year, month, day, hour, minute, second)
u8 func_80085504(u8* rtc) {
    u32 yearMonth = (rtc[0] << 24) + (rtc[1] << 16);
    u32 dayHour = (rtc[2] << 24) + (rtc[3] << 16);
    u32 minSec = (rtc[4] << 24) + (rtc[5] << 16);
    u8 sense;

    if ((sense = func_80080EA8(0xF0000, yearMonth)) != 0) {
        return sense;
    }
    if ((sense = func_80080EA8(0x100000, dayHour)) != 0) {
        return sense;
    }
    if ((sense = func_80080EA8(0x110000, minSec)) != 0) {
        return sense;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80085504);
#endif

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC2A0);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC2B0);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC2B8);
