#include "leocmd.h"

// libleo: leoStart_stop.

// leoStart_stop
void func_80084650(void) {
    u32 cmd;
    u32 data;
    u8 sense;
    u8 retry = 8;

    do {
        data = 0;
        if (LEO_CUR(LEOCmdHeader)->control & 1) {
            cmd = 0x50001;
        } else if (LEO_CUR(LEOCmdHeader)->control & 2) {
            cmd = 0xD0000;
        } else {
            if (LEO_CUR(LEOCmdHeader)->control & 4) {
                data = 0x10000;
            }
            cmd = 0x40000;
        }
        if ((sense = func_80080EA8(cmd, data)) == 0) {
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

