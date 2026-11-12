#include "leocmd.h"

// libleo: leoReadCapacity.

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

