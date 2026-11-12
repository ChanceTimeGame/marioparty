#include "leocmd.h"

// libleo: leoSeek.

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
    do {
        if ((sense = func_80081070()) == 0) {
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

