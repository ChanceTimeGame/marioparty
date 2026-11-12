#ifndef LEOCMD_H
#define LEOCMD_H

#include "common.h"
#include "sdk_leo.h"

// libleo command handlers (src/84A60.c to 85890.c, one unit per retail file where IDO's 16-byte
// .text padding shows a file boundary): their command structs and the driver state they share.

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
extern OSPiHandle* D_800EA150;  // LEOPiInfo
extern u8 D_800CBDD0[];         // GF(256) exponent table (doubled)
extern u8 D_800CBECF[];         // = D_800CBDD0 + 0xFF
extern u8 D_800CBFD0[];         // GF(256) logarithm table
extern u16 D_800CBD98[];        // first user lba per disk type
extern u32 D_800CBDA8[];        // capacity in bytes per disk type

// C1 error report of the last read (80BE0.c)
typedef struct LEORwInfo {
    /* 0x00 */ u8* dram;
    /* 0x04 */ u8* c2end;
    /* 0x08 */ u8 errSector[4];
    /* 0x0C */ u8 errNum;
    /* 0x0D */ u8 secBytes;
    /* 0x0E */ u16 blkBytes;
} LEORwInfo;

extern LEORwInfo D_800EA140;
extern u8 D_800E99F8[];          // scratch sector (end) for an out-of-range erasure
extern LEOCmdRead D_800C6450;    // read command template for the system area
extern u8 D_800CC2A0[];          // system-area lbas tried in turn (2)
extern u8 D_800CC2A2[];
extern u32 D_800E9910[8];        // disk ID read from the system area
extern OSMesgQueue D_800E7A98;
extern u8 D_800CC2B0[];          // RTC field maxima
extern u8 D_800CC2B8[];          // days per month

typedef struct LEOCmdReadDiskId {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32* buffer_pointer;
} LEOCmdReadDiskId;

typedef struct LEOCmdLBAConv {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 lba;
    /* 0x10 */ u32 in;  // bytes (control & 1) or lbas
    /* 0x14 */ u32 out; // lbas (control & 1) or bytes
} LEOCmdLBAConv;

extern u32 D_800E87DC;
extern u32 D_800E87E0;
extern u8 D_800E87E4;            // non-zero once the system area has been read
extern volatile u8 D_800E87E5;
extern s32 D_800EA170;           // current command code
extern OSIoMesg D_800EA158;
extern OSMesgQueue D_800E8748;   // command queue
extern OSMesgQueue D_800E8760;
extern OSMesgQueue D_800E8790;
extern LEOCmdRead D_800C6430;    // system-area read command template
extern u8 D_800CC1F0[];          // system-area lbas
extern void (*D_800C63F0[])(void); // command handlers, by command code

u8 func_80080ADC(u32 asic_cmd);
u8 func_80081280(void);
u8 func_8008128C(void);
void func_800812C0(void);
void func_80081250(void);
void func_80081310(void);
void func_800814D0(void);
u8 func_800842DC(void);
void func_800812DC(void);
void func_800812F8(void);
u16 func_80082D60(void);
u8 func_80085504(u8* rtc);
extern OSThread D_800E7D98;      // read/write thread
extern OSMesgQueue D_800E8778;

u8 func_80080E70(u32 asic_cmd, u32 asic_data);
u8 func_80080EA8(u32 asic_cmd, u32 asic_data);
u8 func_80080FE4(void);
u8 func_80081070(void);
s32 func_80081100(u32 sense);
u8 func_80081210(void);

void func_8008499C(u32 start); // leoRead_common
u8 func_80083DC4(s32 a, s32 b); // GF(256) multiply
u8 func_80083E08(s32 a, s32 b); // GF(256) divide
void func_80082DEC(void);
void func_80082EC0(void);
void func_80083140(void);
void func_80083528(void);
u8 func_80085394(u8* rtc);     // read the RTC (6 bytes)


#endif
