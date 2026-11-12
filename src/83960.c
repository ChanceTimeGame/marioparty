#include "common.h"
#include "sdk_leo.h"

// libleo C2 (Reed-Solomon) error correction (leoc2ecc.c, MP2 9A210.c), built with IDO 5.3. Its
// rodata (CC9D0-CCDF0) is the GF(256) tables and func_80082D60's jump table; the 64DD lookup tables
// before it (CC998-CC9D0) are another file's and stay asm data.

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
extern u8 D_800E87E5;
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

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBDD0);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBFD0);

// leoC2_Correction: by the number of C1 error sectors
u16 func_80082D60(void) {
    switch (D_800EA140.errNum) {
        case 0:
            break;
        case 1:
            func_80082DEC();
            break;
        case 2:
            func_80082EC0();
            break;
        case 3:
            func_80083140();
            break;
        case 4:
            func_80083528();
            break;
        default:
            return -1;
    }
    return 0;
}

// one erroneous sector: XOR the C2 parity back in
void func_80082DEC(void) {
    u8* p;
    u8* c2;
    u32 n;

    if (D_800EA140.errSector[0] < 0x55) {
        n = D_800EA140.secBytes;
        p = D_800EA140.dram + (D_800EA140.errSector[0] + 1) * n;
        c2 = D_800EA140.c2end;
        do {
            *--p ^= *(c2 -= 4);
        } while (--n != 0);
    }
}

#ifdef NON_MATCHING
// two erroneous sectors: solve for both from the two C2 syndromes
void func_80082EC0(void) {
    u32 e1 = D_800EA140.errSector[0];
    u32 e2 = D_800EA140.errSector[1];
    u8* a2 = &D_800CBDD0[0x58 - e2]; // alpha^(88 - e2)
    u8 k;
    u32 n;
    u8* p1;
    u8* p2;
    u8* c2;
    u8 s0;
    u8 s1;
    u8 v;

    k = D_800CBFD0[func_80083E08(1, D_800CBDD0[0x58 - e2] ^ D_800CBDD0[0x58 - e1])];
    n = D_800EA140.secBytes;
    if (D_800EA140.errSector[1] < 0x55) {
        p2 = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
    } else {
        if (D_800EA140.errSector[0] >= 0x55) {
            return;
        }
        p2 = D_800E99F8;
    }
    p1 = D_800EA140.dram + (D_800EA140.errSector[0] + 1) * n;
    c2 = D_800EA140.c2end;
    for (; n != 0; n--) {
        c2 -= 4;
        p1--;
        s0 = c2[0];
        if (s0 != 0) {
            s1 = c2[1] ^ a2[D_800CBFD0[s0]];
        } else {
            s1 = c2[1];
        }
        p2--;
        if (s1 != 0) {
            v = D_800CBDD0[D_800CBFD0[s1] + k];
            *p1 ^= v;
            *p2 ^= v ^ s0;
        } else {
            *p2 ^= s0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80082EC0);
#endif

#ifdef NON_MATCHING
// three erroneous sectors: invert the 3x3 Vandermonde system once, then correct each byte column
void func_80083140(void) {
    u8 a = D_800CBDD0[0x58 - D_800EA140.errSector[0]];
    u8 b = D_800CBDD0[0x58 - D_800EA140.errSector[1]];
    u8 c = D_800CBDD0[0x58 - D_800EA140.errSector[2]];
    u8 a2, b2, c2sq;
    u8 m10, m11, m12; // row coefficients (logs) for sector 1
    u8 m20, m21, m22; // sector 2
    u8 m30, m31, m32; // sector 3
    u8 det;
    u8 d1, d2, d3;
    u32 n;
    u8* p1;
    u8* p2;
    u8* p3;
    u8* c2;
    u8 x, lx;
    u8 v1, v2, v3;

    c2sq = func_80083DC4(c, c);
    b2 = func_80083DC4(b, b);
    a2 = func_80083DC4(a, a);
    d1 = func_80083DC4(c, b2) ^ func_80083DC4(b, c2sq);
    d2 = func_80083DC4(a, c2sq) ^ func_80083DC4(c, a2);
    d3 = func_80083DC4(a, b2) ^ func_80083DC4(b, a2);
    det = func_80083E08(1, d1 ^ d2 ^ d3);

    m10 = D_800CBFD0[d1];
    m11 = D_800CBFD0[c2sq ^ b2];
    m12 = D_800CBFD0[b ^ c];
    m20 = D_800CBFD0[d2];
    m21 = D_800CBFD0[c2sq ^ a2];
    m22 = D_800CBFD0[c ^ a];
    m30 = D_800CBFD0[d3];
    m31 = D_800CBFD0[b2 ^ a2];
    m32 = D_800CBFD0[a ^ b];
    det = D_800CBFD0[det];

    n = D_800EA140.secBytes;
    if (D_800EA140.errSector[2] < 0x55) {
        p3 = D_800EA140.dram + (D_800EA140.errSector[2] + 1) * n;
        p2 = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
    } else {
        p3 = D_800E99F8;
        if (D_800EA140.errSector[1] < 0x55) {
            p2 = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
        } else {
            p2 = D_800E99F8;
            if (D_800EA140.errSector[0] >= 0x55) {
                return;
            }
        }
    }
    p1 = D_800EA140.dram + (D_800EA140.errSector[0] + 1) * n;
    c2 = D_800EA140.c2end;
    do {
        c2 -= 4;
        p1--;
        p2--;
        if ((x = c2[0]) != 0) {
            lx = D_800CBFD0[x];
            v1 = D_800CBDD0[lx + m10];
            v2 = D_800CBDD0[lx + m20];
            v3 = D_800CBDD0[lx + m30];
        } else {
            v1 = v2 = v3 = 0;
        }
        n--;
        if ((x = c2[1]) != 0) {
            lx = D_800CBFD0[x];
            v1 ^= D_800CBDD0[lx + m11];
            v2 ^= D_800CBDD0[lx + m21];
            v3 ^= D_800CBDD0[lx + m31];
        }
        if ((x = c2[2]) != 0) {
            lx = D_800CBFD0[x];
            v1 ^= D_800CBDD0[lx + m12];
            v2 ^= D_800CBDD0[lx + m22];
            v3 ^= D_800CBDD0[lx + m32];
        }
        p3--;
        if (v1 != 0) {
            *p1 ^= D_800CBDD0[D_800CBFD0[v1] + det];
        }
        if (v2 != 0) {
            *p2 ^= D_800CBDD0[D_800CBFD0[v2] + det];
        }
        if (v3 != 0) {
            *p3 ^= D_800CBDD0[D_800CBFD0[v3] + det];
        }
    } while (n != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083140);
#endif

#define GF_MUL func_80083DC4
#define GF_DIV func_80083E08

#ifdef NON_MATCHING
// four erroneous sectors: Lagrange weights per sector, then every syndrome's contribution per byte
void func_80083528(void) {
    u8 A1 = D_800CBDD0[0x58 - D_800EA140.errSector[0]];
    u8 A2 = D_800CBDD0[0x58 - D_800EA140.errSector[1]];
    u8 A3 = D_800CBDD0[0x58 - D_800EA140.errSector[2]];
    u8 A4 = D_800CBDD0[0x58 - D_800EA140.errSector[3]];
    u8 one = D_800CBDD0[0];
    u8 iA, iB, iC, iD;
    u8 BC, CD, DB, DA, AC, AB;
    u8 q1[4]; // second-syndrome coefficient values (iB^iC^iD, ...)
    u8 r1[4]; // third-syndrome coefficient values
    u8 t1[4]; // fourth-syndrome coefficient values
    u8 W[4];  // Lagrange weights
    u8 L0[4], L1[4], L2[4], L3[4]; // logs of the weighted coefficients, per syndrome
    u32 i;
    u32 n;
    u8* p[4];
    u8* c2;
    u8 x, lx;
    u8 v[4];

    iA = GF_DIV(one, A1);
    iB = GF_DIV(one, A2);
    iC = GF_DIV(one, A3);
    iD = GF_DIV(one, A4);
    BC = GF_MUL(iB, iC);
    CD = GF_MUL(iC, iD);
    DB = GF_MUL(iD, iB);
    DA = GF_MUL(iD, iA);
    AC = GF_MUL(iA, iC);
    AB = GF_MUL(iA, iB);
    r1[0] = BC ^ CD ^ DB;
    r1[1] = CD ^ DA ^ AC;
    r1[2] = DA ^ AB ^ DB;
    r1[3] = AB ^ BC ^ AC;
    q1[0] = iB ^ iC ^ iD;
    q1[1] = iC ^ iD ^ iA;
    q1[2] = iD ^ iA ^ iB;
    q1[3] = iA ^ iB ^ iC;
    t1[0] = GF_MUL(GF_MUL(iB, iC), iD);
    t1[1] = GF_MUL(GF_MUL(iC, iD), iA);
    t1[2] = GF_MUL(GF_MUL(iD, iA), iB);
    t1[3] = GF_MUL(GF_MUL(iA, iB), iC);

    W[0] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A1, A2) ^ 1, GF_DIV(A1, A3) ^ 1), GF_DIV(A1, A4) ^ 1));
    W[1] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A2, A1) ^ 1, GF_DIV(A2, A3) ^ 1), GF_DIV(A2, A4) ^ 1));
    W[2] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A3, A1) ^ 1, GF_DIV(A3, A2) ^ 1), GF_DIV(A3, A4) ^ 1));
    W[3] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A4, A1) ^ 1, GF_DIV(A4, A2) ^ 1), GF_DIV(A4, A3) ^ 1));

    for (i = 0; i < 4; i++) {
        L1[i] = D_800CBFD0[GF_MUL(q1[i], W[i])];
        L2[i] = D_800CBFD0[GF_MUL(r1[i], W[i])];
        L3[i] = D_800CBFD0[GF_MUL(t1[i], W[i])];
        L0[i] = D_800CBFD0[W[i]];
    }

    n = D_800EA140.secBytes;
    if (D_800EA140.errSector[3] < 0x55) {
        p[3] = D_800EA140.dram + (D_800EA140.errSector[3] + 1) * n;
        goto sector3;
    }
    p[3] = D_800E99F8;
    if (D_800EA140.errSector[2] < 0x55) {
    sector3:
        p[2] = D_800EA140.dram + (D_800EA140.errSector[2] + 1) * n;
        goto sector2;
    }
    p[2] = D_800E99F8;
    if (D_800EA140.errSector[1] < 0x55) {
    sector2:
        p[1] = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
    } else {
        p[1] = D_800E99F8;
        if (D_800EA140.errSector[0] >= 0x55) {
            return;
        }
    }
    p[0] = D_800EA140.dram + (D_800EA140.errSector[0] + 1) * n;

    c2 = D_800EA140.c2end;
    do {
        c2 -= 4;
        p[0]--;
        p[1]--;
        if ((x = c2[0]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] = D_800CBDD0[lx + L0[i]];
            }
        } else {
            v[0] = v[1] = v[2] = v[3] = 0;
        }
        p[2]--;
        n--;
        if ((x = c2[1]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= (q1[i] != 0) ? D_800CBDD0[lx + L1[i]] : 0;
            }
        }
        if ((x = c2[2]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= (r1[i] != 0) ? D_800CBDD0[lx + L2[i]] : 0;
            }
        }
        if ((x = c2[3]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= D_800CBDD0[lx + L3[i]];
            }
        }
        p[3]--;
        for (i = 0; i < 4; i++) {
            if (v[i] != 0) {
                *p[i] ^= v[i];
            }
        }
    } while (n != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083528);
#endif

// GF(256) multiply
u8 func_80083DC4(s32 a, s32 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800CBDD0[D_800CBFD0[a] + D_800CBFD0[b]];
}

// GF(256) divide
u8 func_80083E08(s32 a, s32 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800CBECF[D_800CBFD0[a] - D_800CBFD0[b]];
}
