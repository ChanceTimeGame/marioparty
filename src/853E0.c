#include "leocmd.h"

// libleo: leoReadDiskId, leoRead and leoRead_common, leoRezero.

extern volatile u16 D_800E87E6; // transfer mode flags

#ifdef NON_MATCHING
// leoReadDiskId: read the disk ID from the first system-area lba that reads
void func_800847E0(void) {
    LEOCmdReadDiskId* saved = D_800E87D8;
    LEOCmdRead tmp;
    u8* lba = D_800CC2A0;
    u32* dst;
    u32* src;

    D_800E87D8 = &tmp;
    do {
        tmp = D_800C6450;
        D_800E87E6 = 0x2000;
        tmp.lba = *lba;
        func_8008499C(0);
        lba++;
        if (tmp.header.sense_code != 0x17) {
            break;
        }
    } while (lba < D_800CC2A2);
    D_800E87D8 = saved;
    dst = saved->buffer_pointer;
    for (src = D_800E9910; src != D_800E9910 + 8; src += 4, dst += 4) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
    }
    LEO_CUR(LEOCmdHeader)->sense_code = tmp.header.sense_code;
    LEO_CUR(LEOCmdHeader)->status = tmp.header.status;
    if (LEO_CUR(LEOCmdHeader)->status == LEO_STATUS_GOOD) {
        func_800812DC();
    } else {
        func_800812F8();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/853E0", func_800847E0);
#endif

// leoRead
void func_80084970(void) {
    D_800E87E6 = 0;
    func_8008499C(0x18);
}

#ifdef NON_MATCHING
// leoRead_common: the read thread does the transfer; 0x80000 asks for C2 correction
void func_8008499C(u32 start) {
    u32 lba = LEO_CUR(LEOCmdRead)->lba;
    u32 xfer = LEO_CUR(LEOCmdRead)->xfer_blks;
    u32 msg;

    if ((lba | xfer) & 0xFFFF0000) {
        goto out_of_range;
    }
    lba += start;
    if (lba + xfer > 0x10DC) {
    out_of_range:
        LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if (xfer == 0) {
        if (lba < 0x10DC) {
            LEO_CUR(LEOCmdHeader)->sense_code = 0;
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        } else {
            goto out_of_range;
        }
        return;
    }
    D_800E87F0.lba = lba;
    D_800E87E6 &= 0x3FFF;
    osSendMesg(&D_800E7A98, NULL, OS_MESG_NOBLOCK);
    osStartThread(&D_800E7D98);
    while (TRUE) {
        osRecvMesg(&D_800E8778, (OSMesg*)&msg, OS_MESG_BLOCK);
        switch (msg) {
            case 0x80000:
                func_80082D60();
                D_800E87E6 &= ~0x4000;
                osSendMesg(&D_800E7A98, NULL, OS_MESG_NOBLOCK);
                break;
            case 0x90000:
                LEO_CUR(LEOCmdHeader)->sense_code = 0;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
                return;
            default:
                LEO_CUR(LEOCmdHeader)->sense_code = msg;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/853E0", func_8008499C);
#endif

// leoRezero
void func_80084B30(void) {
    u8 retry = 8;
    u8 sense;

    do {
        if ((sense = func_80080FE4()) == 0) {
            D_800E87F0.cylinder = 0;
            D_800E87F0.head = 0;
            D_800E87F0.zone = 0;
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80081100(sense) != 0) {
            break;
        }
    } while (retry--);
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}

INCLUDE_RODATA("asm/nonmatchings/853E0", D_800CC2A0);
