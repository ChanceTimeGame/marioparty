#include "common.h"
#include "105EA0.h"

void func_800FCF10_UnusedMinigame0(s16 arg0) {
    D_80103700_UnusedMinigame0 = 0;
    func_800FD5E0_UnusedMinigame0();
    func_800FCFB4_UnusedMinigame0(arg0);
    func_800FF488_UnusedMinigame0();
    func_800FE360_UnusedMinigame0();
    func_801025B8_UnusedMinigame0(D_80108B50_UnusedMinigame0);
    func_800258EC(UM0_MODEL(0), 4, 4);
    func_800258EC(UM0_MODEL(1), 4, 4);
    func_800258EC(UM0_MODEL(2), 4, 4);
    func_800258EC(UM0_MODEL_DROP, 4, 4);
}
// register allocation: retail recomputes &D_8010A040[i] where GCC reuses it
#ifdef NON_MATCHING
void func_800FCFB4_UnusedMinigame0(s32 arg0) {
    UM0Tile* t;
    UM0Tile* p;
    UM0Tile** slot;
    s32 k;
    s32 col;
    s32 row;
    s32 i;
    s32 j;
    void* buf;

    col = 0;
    row = 0;
    D_80103708_UnusedMinigame0 = D_80103640_UnusedMinigame0[arg0][rand8() & 7];
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            D_80108B88_UnusedMinigame0[i][j] = NULL;
        }
    }
    D_80108B88_UnusedMinigame0[0][5] = &D_8010A040_UnusedMinigame0[47];
    for (i = 0; i < 48; i++) {
        t = &D_8010A040_UnusedMinigame0[i];
        if (i < 40) {
            p = D_8010A040_UnusedMinigame0 + i;
            do {
                col = func_80102568_UnusedMinigame0(8);
                row = func_80102568_UnusedMinigame0(6);
                slot = &D_80108B88_UnusedMinigame0[col][row];
            } while (*slot != NULL);
            *slot = p;
        } else if (i == 47) {
            col = 0;
            row = 5;
        } else {
            p = &D_8010A040_UnusedMinigame0[i];
            for (j = 0; j < 6; j++) {
                for (k = 0; k < 8; k++) {
                    if (D_80108B88_UnusedMinigame0[k][j] == NULL) {
                        col = k;
                        row = j;
                        D_80108B88_UnusedMinigame0[k][j] = p;
                        j = 8;
                        k = 8;
                    }
                }
            }
        }
        t->col = col;
        t->row = row;
        t->x = col * 40.0 + -140.0;
        t->z = row * 40.0 + -100.0;
        t->color = func_80102568_UnusedMinigame0(arg0);
        t->fade = 0;
        t->links = 0;
        t->rot = 0;
        t->shape = 0;
        t->flags = 1;
        t->visited = 0;
        t->state = 0;
        t->dy = t->dx = 0.0f;
        t->moveTimer = 0;
        t->match = NULL;
    }
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            t = &D_8010A040_UnusedMinigame0[i + j * 8];
            func_800FDA50_UnusedMinigame0(t, 0);
            if (t->shape == 0) {
                t->fade = 0x70;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        buf = HuMemDirectMalloc(0x1E00);
        D_801098A8_UnusedMinigame0[i] = buf;
        D_80109CC0_UnusedMinigame0[i] = func_80024198(0x19, buf, 4);
    }
    func_800FEBF0_UnusedMinigame0(0);
    func_80025830(UM0_MODEL(0), 2.5f, 2.5f, 2.5f);
    func_80025830(UM0_MODEL(1), 2.5f, 2.5f, 2.5f);
    func_80025830(UM0_MODEL(2), 2.5f, 2.5f, 2.5f);
    buf = DataRead(0x180007);
    D_80109CD0_UnusedMinigame0 = func_800678A4(buf);
    HuMemDirectFree(buf);
    D_80109CD4_UnusedMinigame0 = func_80064EF4(0x20, 0);
    for (i = 0; i < 32; i++) {
        func_80067208(UM0_SPRGRP, i, UM0_SPRITE, 0);
        func_800674BC(UM0_SPRGRP, i, 0x9000);
        func_800672B0(UM0_SPRGRP, i, 2);
        func_80067284(UM0_SPRGRP, i, 1.0f);
        D_8010AD60_UnusedMinigame0[i].active = 0;
        (D_8010AD60_UnusedMinigame0 + i)->timer = 0;
        D_8010AD60_UnusedMinigame0[i].unk_08 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FCFB4_UnusedMinigame0);
#endif
// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800FD430_UnusedMinigame0(void) {
    s32 i;
    s32 k;
    s32 f;
    s32 j;

    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_801098A8_UnusedMinigame0[i]);
    }
    for (i = 0; i < 6; i++) {
        for (j = 1; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                for (f = 0; f < 3; f++) {
                    HuMemDirectFree(D_80109CD8_UnusedMinigame0[i][j][k][f]);
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_80108C50_UnusedMinigame0[i]);
        for (k = 0; k < 4; k++) {
            HuMemDirectFree(D_8010B070_UnusedMinigame0[k][i]);
            HuMemDirectFree(D_8010B0D0_UnusedMinigame0[k][i]);
            HuMemDirectFree(D_8010B0D0_UnusedMinigame0[k + 4][i]);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FD430_UnusedMinigame0);
#endif
void func_800FD5E0_UnusedMinigame0(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 f;
    s32 n;

    D_8010AD00_UnusedMinigame0[0] = D_80102F20_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[1] = D_801030C8_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[2] = D_80103220_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[3] = D_80103350_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[4] = D_80103428_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[5] = D_80103498_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[0][0][0][0] = D_80102D20_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[1][0][0][0] = D_80102F30_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[2][0][0][0] = D_801030D8_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[3][0][0][0] = D_80103230_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[4][0][0][0] = D_80103360_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[5][0][0][0] = D_80103438_UnusedMinigame0;
    for (i = 0; i < 6; i++) {
        for (j = 1; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                for (f = 0; f < 3; f++) {
                    D_80109CD8_UnusedMinigame0[i][j][k][f] = HuMemDirectMalloc(D_80103688_UnusedMinigame0[i] * sizeof(Vtx));
                    for (n = 0; n < D_80103688_UnusedMinigame0[i]; n++) {
                        D_80109CD8_UnusedMinigame0[i][j][k][f][n] = D_80109CD8_UnusedMinigame0[i][0][0][0][n];
                    }
                }
            }
        }
    }
}
s32 func_800FD800_UnusedMinigame0(s32 col, s32 row) {
    UM0Tile* t;
    UM0Tile* n;
    UM0Tile* u;
    UM0Tile* w;
    u32 c;
    u32 r;
    s32 i;
    s32 j;
    s32 k;

    t = D_80108B88_UnusedMinigame0[col][row];
    if (t == NULL) {
        return 0;
    }
    t->match = NULL;
    t->visited = 1;
    for (i = 0; i < 4; i++) {
        c = D_8010370C_UnusedMinigame0[i][0] + t->col;
        if (c < 8) {
            r = D_8010370C_UnusedMinigame0[i][1] + t->row;
            if (r < 6) {
                n = D_80108B88_UnusedMinigame0[c][r];
                if (n != NULL && t->color == n->color) {
                    n->match = t;
                    func_800FDA50_UnusedMinigame0(n, 1);
                    t->state = 1;
                }
            }
        }
    }
    if (t->state != 0) {
        for (i = t->row - 1; i >= 0; i--) {
            u = D_80108B88_UnusedMinigame0[t->col][i];
            if (u != NULL) {
                u->dy += 1.0f;
            }
        }
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                w = D_80108B88_UnusedMinigame0[i][j];
                if (w != NULL && w->state == 0) {
                    break;
                }
            }
            if (j == 6) {
                for (k = i; k < 8; k++) {
                    for (j = 0; j < 6; j++) {
                        w = D_80108B88_UnusedMinigame0[k][j];
                        if (w != NULL) {
                            w->dx += 1.0f;
                        }
                    }
                }
            }
        }
    }
    return 1;
}
void func_800FDA50_UnusedMinigame0(UM0Tile* t, s32 match) {
    UM0Tile* n;
    UM0Tile* u;
    u32 c;
    u32 r;
    s32 i;

    if (t->visited == 0) {
        t->visited = 1;
        t->links = 0;
        for (i = 0; i < 4; i++) {
            c = D_8010371C_UnusedMinigame0[i][0] + t->col;
            if (c < 8) {
                r = D_8010371C_UnusedMinigame0[i][1] + t->row;
                if (r < 6) {
                    n = D_80108B88_UnusedMinigame0[c][r];
                    if (n != NULL && n->state == 0 && t->color == n->color) {
                        if (n->visited == 0) {
                            n->match = t;
                            func_800FDA50_UnusedMinigame0(n, match);
                        }
                        t->links |= (D_8010372C_UnusedMinigame0 + i)->bit;
                    }
                }
            }
        }
        if (match != 0) {
            t->state = 1;
            for (i = t->row - 1; i >= 0; i--) {
                u = D_80108B88_UnusedMinigame0[t->col][i];
                if (u != NULL) {
                    u->dy += 1.0f;
                }
            }
        } else {
            t->shape = D_80103608_UnusedMinigame0[t->links].shape;
            t->rot = D_80103608_UnusedMinigame0[t->links].rot;
        }
    }
}
// argument narrowing order (retail narrows col/row twice)
#ifdef NON_MATCHING
s32 func_800FDC1C_UnusedMinigame0(s32 col, s32 row) {
    UM0Tile** p;

    if ((s16)func_800FD800_UnusedMinigame0((s16)col, (s16)row) != 0) {
        func_801025B8_UnusedMinigame0(D_80108B50_UnusedMinigame0);
        func_80102634_UnusedMinigame0(D_80108B50_UnusedMinigame0, (s16)col, (s16)row);
        p = &D_80108B88_UnusedMinigame0[(s16)col][(s16)row];
        if ((*p)->state == 0) {
            D_80103734_UnusedMinigame0 = 0x10;
            (*p)->flags |= 1;
            return 0;
        }
        D_80103734_UnusedMinigame0 = 0x18;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FDC1C_UnusedMinigame0);
#endif
s32 func_800FDCF8_UnusedMinigame0(s16 arg0) {
    UM0Tile* t;
    s32 i;
    s32 j;
    s32 r;

    switch (D_80103700_UnusedMinigame0) {
    case 0:
        D_80103704_UnusedMinigame0 = (D_80103704_UnusedMinigame0 + 1) % 3;
        if (D_80103738_UnusedMinigame0 != 0) {
            func_800258EC(UM0_MODEL_DROP, 4, 0);
            D_8010373C_UnusedMinigame0 = func_80060540(0x1EB, 0);
            D_80103738_UnusedMinigame0 = 0;
        }
        if ((s16)func_80100850_UnusedMinigame0() != 0) {
            D_80103700_UnusedMinigame0 = 1;
            func_800258EC(UM0_MODEL_DROP, 4, 4);
            func_800258EC(UM0_MODEL(D_80103704_UnusedMinigame0), 4, 0);
            func_800FEBF0_UnusedMinigame0(arg0);
            func_8006071C(UM0_SOUND);
            func_80060540(0x1F0, 2);
            D_80103734_UnusedMinigame0 = 0x10;
        }
        break;
    case 1:
        if (D_80103734_UnusedMinigame0 > 0 || arg0 != D_80103740_UnusedMinigame0) {
            D_80103704_UnusedMinigame0 = (D_80103704_UnusedMinigame0 + 1) % 3;
            if (D_80103734_UnusedMinigame0 > 0x10) {
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 8; j++) {
                        t = &D_8010A040_UnusedMinigame0[j + i * 8];
                        if (t->state == 2) {
                            continue;
                        }
                        if (t->state == 1) {
                            func_800FE1FC_UnusedMinigame0(t);
                        } else if (t->dy > 0.0f || t->dx > 0.0f) {
                            if (D_80103734_UnusedMinigame0 == 0x18) {
                                if (t == D_80108B88_UnusedMinigame0[t->col][t->row]) {
                                    D_80108B88_UnusedMinigame0[t->col][t->row] = NULL;
                                }
                                t->col = t->col - t->dx;
                                t->row = t->row + t->dy;
                                D_80108B88_UnusedMinigame0[t->col][t->row] = t;
                                if (t->dx != 0.0f) {
                                    t->flags |= 2;
                                }
                                if (t->dy != 0.0f) {
                                    t->flags |= 1;
                                }
                            }
                            func_800FE168_UnusedMinigame0(t);
                        }
                    }
                }
            }
            func_800FE3CC_UnusedMinigame0(D_80103734_UnusedMinigame0);
            if (D_80103734_UnusedMinigame0 == 1) {
                func_800FE360_UnusedMinigame0();
            }
            func_800FEBF0_UnusedMinigame0(arg0);
            D_80103734_UnusedMinigame0--;
            func_800258EC(UM0_MODEL((D_80103704_UnusedMinigame0 + 2) % 3), 4, 4);
            func_800258EC(UM0_MODEL((D_80103704_UnusedMinigame0 + 1) % 3), 4, 4);
            func_800258EC(UM0_MODEL(D_80103704_UnusedMinigame0), 4, 0);
            D_80103740_UnusedMinigame0 = arg0;
        }
        func_800FF284_UnusedMinigame0();
        break;
    }
    return D_80103700_UnusedMinigame0;
}
void func_800FE168_UnusedMinigame0(UM0Tile* t) {
    t->x = t->x - t->dx * 5.0;
    t->z = t->z + t->dy * 5.0;
    if (++t->moveTimer >= 8) {
        t->moveTimer = 0;
        t->dx = t->dy = 0.0f;
        func_80060540(0x1EF, 2);
    }
}
void func_800FE1FC_UnusedMinigame0(UM0Tile* t) {
    s32 i;

    if (t == D_80108B88_UnusedMinigame0[t->col][t->row]) {
        D_80108B88_UnusedMinigame0[t->col][t->row] = NULL;
    }
    t->state = 2;
    func_80060540(0x1EE, 2);
    for (i = 0; i < 32; i++) {
        if (D_8010AD60_UnusedMinigame0[i].active == 0) {
            break;
        }
    }
    if (i != 32) {
        D_8010AD60_UnusedMinigame0[i].active = 1;
        D_8010AD60_UnusedMinigame0[i].color = t->color;
        D_8010AD60_UnusedMinigame0[i].timer = 0;
        func_80067480(UM0_SPRGRP, i, 0x8000);
        func_80066DF4(UM0_SPRGRP, i, 0, t->x * 2.5, 100.0f, t->z * 2.5);
        func_800672DC(UM0_SPRGRP, i, 0, 0);
    }
}
void func_800FE360_UnusedMinigame0(void) {
    UM0Tile** slot;
    UM0Tile* t;
    s32 i;
    s32 j;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            t = D_80108B88_UnusedMinigame0[i][j];
            if (t != NULL) {
                if (t->state != 0) {
                    D_80108B88_UnusedMinigame0[i][j] = NULL;
                }
                t->visited = 0;
            }
        }
    }
}
void func_800FE3CC_UnusedMinigame0(s32 arg0) {
    UM0Tile* t;
    s32 i;
    s32 n;

    if ((arg0 == 0x18) | (arg0 == 0x10)) {
        D_80104340_UnusedMinigame0 = 90;
        D_80104344_UnusedMinigame0 = 8.0f;
        func_80060540(0x1F0, 3);
    }
    for (i = 0; i < 6; i++) {
        for (n = 0; n < D_80103688_UnusedMinigame0[i]; n++) {
            if (D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[1] >= 0) {
                D_80109CD8_UnusedMinigame0[i][1][0][D_80103704_UnusedMinigame0][n].v.ob[0] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0];
                D_80109CD8_UnusedMinigame0[i][1][0][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][1][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][1][D_80103704_UnusedMinigame0][n].v.ob[2] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2];
                D_80109CD8_UnusedMinigame0[i][1][2][D_80103704_UnusedMinigame0][n].v.ob[0] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0];
                D_80109CD8_UnusedMinigame0[i][1][2][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][3][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][3][D_80103704_UnusedMinigame0][n].v.ob[2] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2];
                D_80109CD8_UnusedMinigame0[i][2][0][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][0][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][1][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][1][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][2][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][2][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][3][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][3][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
            }
        }
    }
    if (arg0 < 0x11 && D_80104344_UnusedMinigame0 >= 0.0f) {
        D_80104340_UnusedMinigame0 = (D_80104340_UnusedMinigame0 + 90) % 360;
        D_80104344_UnusedMinigame0 -= 0.5;
    }
    for (i = 0; i < 8; i++) {
        for (n = 0; n < 6; n++) {
            t = &D_8010A040_UnusedMinigame0[i + n * 8];
            if (t->state != 2) {
                if (arg0 == 0x10) {
                    func_800FDA50_UnusedMinigame0(t, 0);
                } else if (arg0 == 1) {
                    t->flags = 0;
                }
                if (t->shape != 0 && t->fade > 0) {
                    t->fade -= 8;
                } else if (t->shape == 0 && t->fade < 0x70) {
                    t->fade += 8;
                }
            }
        }
    }
}
void func_800FEBF0_UnusedMinigame0(s16 arg0) {
    Gfx* gfx;
    Mtx* mtx;
    UM0Tile* t;
    Mtx m;
    s32 i;

    gfx = D_801098A8_UnusedMinigame0[D_80103704_UnusedMinigame0];
    mtx = D_80104350_UnusedMinigame0[D_80103704_UnusedMinigame0];
    gDPPipeSync(gfx++);
    if (arg0 == 0) {
        gDPSetRenderMode(gfx++, 0x404240, 0);
    } else {
        gDPSetRenderMode(gfx++, 0x404A50, 0);
    }
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    for (i = 0; i < 48; i++) {
        t = &D_8010A040_UnusedMinigame0[i];
        if (t->state == 0) {
            switch (t->color) {
            case 0:
                gDPSetPrimColor(gfx++, 0, 0, 0xFF - t->fade, 0, 0, t->fade * 0.5 + 112.0);
                break;
            case 1:
                gDPSetPrimColor(gfx++, 0, 0, 0, 56.0 - t->fade * 0.5, 0xFF - t->fade, t->fade * 0.5 + 112.0);
                break;
            case 2:
                gDPSetPrimColor(gfx++, 0, 0, 0, 0xFF - t->fade, 0, t->fade * 0.5 + 112.0);
                break;
            case 3:
                gDPSetPrimColor(gfx++, 0, 0, 0xFF - t->fade, 0xFF - t->fade, 0, t->fade * 0.5 + 112.0);
                break;
            case 4:
                gDPSetPrimColor(gfx++, 0, 0, 0xFF - t->fade, 128.0 - t->fade * 0.5, 0, t->fade * 0.5 + 112.0);
                break;
            }
            switch (t->flags) {
            case 0:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][0][0][0]));
                break;
            case 1:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][1][t->rot][D_80103704_UnusedMinigame0]));
                break;
            case 2:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][1][(t->rot + 1) & 3][D_80103704_UnusedMinigame0]));
                break;
            case 3:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][2][t->rot][D_80103704_UnusedMinigame0]));
                break;
            }
            guMtxIdent(mtx);
            guRotate(&m, t->rot * 90, 0.0f, 1.0f, 0.0f);
            guMtxCatL(mtx, &m, mtx);
            guTranslate(&m, t->x, 20.0f, t->z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_8010AD00_UnusedMinigame0[t->shape]);
            gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
        }
    }
    gSPEndDisplayList(gfx++);
}
void func_800FF284_UnusedMinigame0(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        if (D_8010AD60_UnusedMinigame0[i].active == 1) {
            D_8010AD60_UnusedMinigame0[i].timer++;
            if (D_8010AD60_UnusedMinigame0[i].timer == 1) {
                switch (D_8010AD60_UnusedMinigame0[i].color) {
                case 0:
                    func_80067558(UM0_SPRGRP, (s16)i, 0xFF, 0x40, 0x40, 0xE4);
                    break;
                case 1:
                    func_80067558(UM0_SPRGRP, (s16)i, 0x40, 0x40, 0xFF, 0xE4);
                    break;
                case 2:
                    func_80067558(UM0_SPRGRP, (s16)i, 0x40, 0xFF, 0x40, 0xE4);
                    break;
                case 3:
                    func_80067558(UM0_SPRGRP, (s16)i, 0xFF, 0xFF, 0x40, 0xE4);
                    break;
                case 4:
                    func_80067558(UM0_SPRGRP, (s16)i, 0xFF, 0xA0, 0x40, 0xE4);
                    break;
                }
            } else if (D_8010AD60_UnusedMinigame0[i].timer > 0x10) {
                func_800674BC(UM0_SPRGRP, i, 0x8000);
                func_800672DC(UM0_SPRGRP, i, 0, 0);
                D_8010AD60_UnusedMinigame0[i].active = 0;
                D_8010AD60_UnusedMinigame0[i].timer = 0;
            }
        }
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FF488_UnusedMinigame0);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FFA64_UnusedMinigame0);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_80100850_UnusedMinigame0);

u32 func_80102568_UnusedMinigame0(u32 n) {
    D_80103708_UnusedMinigame0 = D_80103708_UnusedMinigame0 * 0x41C64E6D + 0x3039;
    return ((D_80103708_UnusedMinigame0 >> 16) + ((D_80103708_UnusedMinigame0 << 16) >> 31)) % n;
}
void func_801025B8_UnusedMinigame0(u8 (*out)[6]) {
    UM0Tile* t;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 6; j++) {
            t = D_80108B88_UnusedMinigame0[i][j];
            if (t == NULL) {
                out[i][j] = 0;
            } else {
                out[i][j] = (u8)t->color + 1;
            }
        }
    }
}
// register allocation (masked 0)
#ifdef NON_MATCHING
s32 func_80102634_UnusedMinigame0(u8 (*grid)[6], s32 col, s32 row) {
    UM0Cell* c;
    UM0Cell* n;
    u32 nc;
    u32 nr;
    s32 i;
    s32 j;
    s32 k;
    s32 count;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            c = &D_8010B150_UnusedMinigame0[i][j];
            if ((c->color = grid[i][j] & 0x7F) != 0) {
                c->done = 0;
                c->seen = 0;
            } else {
                c->done = 1;
                c->seen = 1;
            }
            c->shiftRows = 0;
            c->shiftCols = 0;
            grid[i][j] = 0;
        }
    }
    c = &D_8010B150_UnusedMinigame0[col][row];
    c->seen = 1;
    for (i = 0; i < 4; i++) {
        nc = col + D_80103758_UnusedMinigame0[i][0];
        if (nc < 8) {
            nr = row + D_80103758_UnusedMinigame0[i][1];
            if (nr < 6) {
                n = &D_8010B150_UnusedMinigame0[nc][nr];
                /* done and seen both clear (one word test) */
                if (*(s32*)&n->done == 0) {
                    n->seen = 1;
                    if (c->color == n->color) {
                        func_8010298C_UnusedMinigame0(col + D_80103758_UnusedMinigame0[i][0],
                                                      row + D_80103758_UnusedMinigame0[i][1]);
                        c->done = 1;
                    }
                }
            }
        }
    }
    if (c->done != 0) {
        for (i = row - 1; i >= 0; i--) {
            n = &D_8010B150_UnusedMinigame0[col][i];
            n->shiftRows++;
        }
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                if (D_8010B150_UnusedMinigame0[i][j].done == 0) {
                    break;
                }
            }
            if (j == 6) {
                for (k = i; k < 8; k++) {
                    for (j = 0; j < 6; j++) {
                        n = &D_8010B150_UnusedMinigame0[k][j];
                        n->shiftCols++;
                    }
                }
            }
        }
    }
    count = 0;
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            c = &D_8010B150_UnusedMinigame0[i][j];
            if (c->done == 0) {
                grid[i - c->shiftCols][j + c->shiftRows] = (u8)c->color;
                count++;
            }
        }
    }
    return count;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_80102634_UnusedMinigame0);
#endif
// register allocation (masked 0)
#ifdef NON_MATCHING
void func_8010298C_UnusedMinigame0(s32 col, s32 row) {
    UM0Cell* c0;
    UM0Cell* n;
    u32 nc;
    u32 nr;
    s32 i;
    s32 j;

    c0 = &D_8010B150_UnusedMinigame0[col][row];
    c0->done = 1;
    for (j = row - 1; j >= 0; j--) {
        n = &D_8010B150_UnusedMinigame0[col][j];
        n->shiftRows++;
    }
    for (i = 0; i < 4; i++) {
        nc = col + D_80103768_UnusedMinigame0[i][0];
        if (nc < 8) {
            nr = row + D_80103768_UnusedMinigame0[i][1];
            if (nr < 6) {
                n = &D_8010B150_UnusedMinigame0[nc][nr];
                if (*(s32*)&n->done == 0) {
                    n->seen = 1;
                    if (c0->color == n->color) {
                        func_8010298C_UnusedMinigame0(col + D_80103768_UnusedMinigame0[i][0],
                                                      row + D_80103768_UnusedMinigame0[i][1]);
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_8010298C_UnusedMinigame0);
#endif
