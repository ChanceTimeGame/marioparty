#include "leocmd.h"

// libleo: leoTest_unit_rdy and the lba/byte conversion command.

// leoTest_unit_rdy
void func_80084C90(void) {
    LEO_CUR(LEOCmdTestUnitReady)->test = func_80081210();
    LEO_CUR(LEOCmdHeader)->sense_code = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}

#ifdef NON_MATCHING
// leoByte_to_lba / leoLba_to_byte as a command (control & 1: bytes to lbas)
void func_80084CD0(void) {
    LEOCmdLBAConv* cmd = D_800E87D8;
    u32 lba = cmd->lba;
    u32 count = 0;
    u32 bytes = 0;
    u32 n;
    u32 byte_p_blk;
    u16 vzone = 1;
    u16 zone;
    s32 flag = 1;

    if (lba >= 0x10C4) {
        cmd->header.sense_code = 0x20;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    lba += 0x18;
    if (cmd->header.control & 1) {
        bytes = cmd->in;
        while (bytes != 0) {
            if (flag || (D_800CBC18[D_800E87E8][vzone] == lba)) {
                vzone = func_800817E4(lba);
                zone = D_800CBD18[D_800E87E8][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = D_800CBC04[zone];
            }
            if (bytes < byte_p_blk) {
                bytes = 0;
            } else {
                bytes -= byte_p_blk;
            }
            count++;
            lba++;
            if ((bytes != 0) && (lba >= 0x10DC)) {
                LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = 0;
        }
        LEO_CUR(LEOCmdLBAConv)->out = count;
    } else {
        n = cmd->in;
        while (n != 0) {
            if (flag || (D_800CBC18[D_800E87E8][vzone] == lba)) {
                vzone = func_800817E4(lba);
                zone = D_800CBD18[D_800E87E8][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = D_800CBC04[zone];
            }
            n--;
            bytes += byte_p_blk;
            lba++;
            if ((n != 0) && (lba >= 0x10DC)) {
                LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = 0;
        }
        LEO_CUR(LEOCmdLBAConv)->out = bytes;
    }
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/85890", func_80084CD0);
#endif

