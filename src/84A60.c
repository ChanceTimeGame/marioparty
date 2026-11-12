#include "leocmd.h"

// libleo leocmdex.c: the command thread (leomain), leoRead_system_area; then leoInquiry and leoMode_sel.

extern volatile u16 D_800E87E6; // transfer mode flags

INCLUDE_RODATA("asm/nonmatchings/84A60", D_800CC1F0);

#ifdef NON_MATCHING
// leomain: the 64DD command thread
void func_80083E60(void* arg) {
    u32 stat;
    u32 sense;
    u8 command;

    ((u8*)&D_800E87FC)[0] = *(vu8*)0xA0000010;
    ((u8*)&D_800E87FC)[1] = *(vu8*)0xA0000090;
    ((u8*)&D_800E87FC)[2] = *(vu8*)0xA0000110;
    ((u8*)&D_800E87FC)[3] = *(vu8*)0xA0000190;
    D_800E87E0 = 0;
    D_800E87DC = 0;
    D_800E87E4 = 0;
    D_800E87E5 = 0;
    func_80081310();
    D_800EA150 = osLeoDiskInit();
    D_800EA158.hdr.pri = OS_MESG_PRI_HIGH;
    D_800EA158.hdr.retQueue = &D_800E8790;
    osEPiReadIo(D_800EA150, 0x05000508, &stat); // LEO_STATUS
    if (!(stat & 0x400000) && (stat & 0x6800000)) {
        func_80081250();
    }

    while (TRUE) {
        osRecvMesg(&D_800E8748, (OSMesg*)&D_800E87D8, OS_MESG_BLOCK);
        D_800EA170 = LEO_CUR(LEOCmdHeader)->command;
        if (LEO_CUR(LEOCmdHeader)->command == 0) { // clear queue
            func_80081250();
            osRecvMesg(&D_800E8760, NULL, OS_MESG_NOBLOCK);
            continue;
        }

        sense = func_80080ADC(0x10001);
        stat = func_80081280();
        if (stat == 0) {
            if (sense == 0) {
                goto dispatch;
            }
        } else if ((sense != 3) && (sense != 0x25) && (sense != 0x29) && (sense != 0x2B)) {
            if (sense == 0x31) {
                if (func_8008128C() == 0x2B) {
                    sense = 0x2B;
                }
            } else {
                sense = func_8008128C();
            }
        }

        command = LEO_CUR(LEOCmdHeader)->command;
        if (sense == 0x2B) { // medium may have changed
            if ((command == 2) || (command == 0xD) || (command == 0xE)) {
                goto dispatch;
            }
            if (command == 0xF) {
                func_800812C0();
                goto dispatch;
            }
        } else if (sense == 0x2F) {
            switch (command) {
                case 2:
                case 8:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
            }
        } else if (sense == 0x31) {
            switch (command) {
                case 2:
                case 11:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
                default:
                    sense = 0x2A;
                    break;
            }
        }
        if (command == 3) { // test unit ready
            ((LEOCmdTestUnitReady*)D_800E87D8)->test = func_80081210();
        }
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        goto done;

    dispatch:
        if (D_800E87E4 == 0) {
            switch (LEO_CUR(LEOCmdHeader)->command) {
                case 2:
                case 3:
                case 8:
                case 11:
                case 13:
                case 14:
                case 15:
                    break;
                default:
                    // commands that need the system area: read it first
                    if (D_800E87FC == 0) {
                        osEPiReadIo(D_800EA150, 0x05000540, &stat); // ASIC_ID_REG
                        if ((stat & 0x70000) != 0x40000) {
                            while (TRUE) {
                            }
                        }
                    }
                    if (func_800842DC() != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    sense = func_80080E70(0xB0001, D_800E7B00[5] << 16);
                    LEO_CUR(LEOCmdHeader)->sense_code = sense;
                    if (sense != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    if ((D_800E7B00[5] & 0xF0) != 0x10) {
                        goto bad_disk;
                    }
                    D_800E87E8 = D_800E7B00[5] & 0xF;
                    if (D_800E87E8 >= 7) {
                    bad_disk:
                        LEO_CUR(LEOCmdHeader)->sense_code = 0xB;
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    D_800E87E4 = 0xFF;
                    break;
            }
        }
        D_800C63F0[LEO_CUR(LEOCmdHeader)->command]();

    done:
        if (LEO_CUR(LEOCmdHeader)->control & 0x80) {
            osSendMesg(LEO_CUR(LEOCmdHeader)->post, (OSMesg)(u32)LEO_CUR(LEOCmdHeader)->sense_code,
                       OS_MESG_BLOCK);
        }
        if (D_800E87E5 != 0) {
            func_800814D0();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/84A60", func_80083E60);
#endif

#ifdef NON_MATCHING
// leoRead_system_area: read the disk's system area into D_800E7B00, retrying
u8 func_800842DC(void) {
    LEOCmdRead* saved = D_800E87D8;
    LEOCmdRead tmp;
    u32 retry = 0;
    s32 phase = 0;
    u8 sense;

    D_800E87D8 = &tmp;
    while (TRUE) {
        tmp = D_800C6430;
        D_800E87E8 = 0;
        D_800E7B00[8] = 0;
        D_800E87E6 = 0x3000;
        if (phase == 0) {
            func_8008499C(0);
            if (tmp.header.sense_code == 0) {
                retry = 0;
                while (D_800E87FC != 0) {
                }
                phase--;
                continue;
            }
            if (tmp.header.sense_code == 0x17) {
                retry = 0;
                while (D_800E87FC == 0) {
                }
                phase--;
                continue;
            }
        } else {
            tmp.lba = D_800CC1F0[retry & 3];
            if (D_800E87FC == 0) {
                tmp.lba += 2;
            }
            func_8008499C(0);
            if (tmp.header.status == LEO_STATUS_GOOD) {
                while (D_800E87FC != *(u32*)D_800E7B00) {
                }
                break;
            }
        }
        while (TRUE) {
            if (func_80081100(tmp.header.sense_code) != 0) {
                goto end;
            }
            if (retry >= 0x40) {
                goto end;
            }
            retry++;
            if ((retry & 7) != 0) {
                break;
            }
            sense = func_80080E70(0x30001, 0);
            tmp.header.sense_code = sense;
            if (sense == 0) {
                break;
            }
        }
    }
end:
    D_800E87D8 = saved;
    saved->header.sense_code = tmp.header.sense_code;
    return tmp.header.sense_code;
}
#else
INCLUDE_ASM("asm/nonmatchings/84A60", func_800842DC);
#endif

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
