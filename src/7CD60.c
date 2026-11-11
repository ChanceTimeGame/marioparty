#include "common.h"

typedef struct {
    u8 file_version[16];
    u16 width;                    /* Width of image, in pixels */
    u16 height;                    /* Height of image, in pixels */
    u16 nest_start_x;            /* Nest origin, X */
    u16 nest_start_y;            /* Nest origin, Y */
    u32 unk_value;
    u8 y_shiftnum;                /* Nest step in vertical direction (number of shifts) */
    u8 quantize_step;            /* DC quantized step */
    u8 h_sampling_rate;            /* Horizontal sampling rate for color difference component */
    u8 v_sampling_rate;            /* Vertical sampling rate for color difference component */
    u32 basisnum_offset[2];        /* Base number section offset */
    u32 basnum_run_offset[2];    /* Base number run section offset */
    u32 dc_offset[3];            /* DC section offset */
    u32 dc_run_offset[3];        /* DC run section offset */
    u32 scale_offset[3];        /* Base scale section offset */
    u32 fix_offset[3];            /* Fixed length code section offset */
} HVQ2Header;

typedef struct {
    u32 bit;
    u32 value;
    u32 *pos;
} BitStream;

typedef struct {
    s16 root;
    s16 array[2][512];
} Tree;

// One work-buffer entry per 4x4 block: DC value and basis count
typedef struct HVQPair {
    u8 dc;
    u8 bn;
} HVQPair;

// Per-plane block cursor
typedef struct unkStruct_D_800E6EC8 {
    /* 0x00 */ HVQPair* unk0; // row above
    /* 0x04 */ HVQPair* unk4; // current row
    /* 0x08 */ HVQPair* unk8; // row below
    /* 0x0C */ HVQPair next;
    /* 0x0E */ HVQPair cur;
    /* 0x10 */ u8 left;
} unkStruct_D_800E6EC8; // sizeof 0x18


/* Globals*/
extern s32 D_800E6F30[];
extern u8 D_800E7730[];

extern s32 D_800E7A3C;
extern s32 D_800E7A40;
extern u8* D_800E7A54;
extern s32 D_800E7A58;
extern s32 D_800E7A5C;

extern u8 D_800E4360; // unk type
extern BitStream D_800E4DC8[2]; // basis number
extern BitStream D_800E4DE0[2]; // basis number run
extern BitStream D_800E4DF8[3]; // DC
extern BitStream D_800E4E20[3]; // scale
extern BitStream D_800E4E48[3]; // DC run
extern u8* D_800E4E6C[];
extern Tree D_800E4E80;
extern Tree D_800E5690;
extern Tree D_800E5EA0;
extern Tree D_800E66B0;
extern s16 D_800E6EB2;
extern s16 D_800E6EB4;
extern s16 D_800E6EB6;
extern HVQPair* D_800E6EB8;
extern HVQPair* D_800E6EBC;
extern HVQPair* D_800E6EC0;
extern u32 D_800E7A30;
extern s32 D_800E7A34;
extern s32 D_800E7A38;
extern s32 D_800E7A3C;
extern s32 D_800E7A40;
extern s32 D_800E7A44;
extern s32 D_800E7A48;
extern s32 D_800E7A4C;
extern s32 D_800E7A50;
extern u8* D_800E7A54;
extern s32 D_800E7A58;
extern s32 D_800E7A5C;
extern u8 D_800E7A60;

extern unkStruct_D_800E6EC8 D_800E6EC8;
extern unkStruct_D_800E6EC8 D_800E6EE0;
extern unkStruct_D_800E6EC8 D_800E6EF8;
extern unkStruct_D_800E6EC8 D_800E6F10;
/* Globals */

void func_8007C434(void);
s32 func_8007C818(u8* dcrun, BitStream* buf, BitStream* runbuf);
void func_8007CA90(void);
void func_8007CFCC(s16* block, s32* scale, s32 plane);
void func_8007D470(s16* block, s32 nbasis, s32 dc, s32 plane);
void func_8007DA48(s16* block, unkStruct_D_800E6EC8* info, s32 plane);


static inline u8 getBit(BitStream *buf)
{
    u32 ret;
    if (buf->bit == 0)
    {
        buf->value = *buf->pos++;
        buf->bit = 1 << 31;
    }
    ret = (buf->value & buf->bit) != 0;
    buf->bit >>= 1;
    return ret;
}

static inline s16 getByte(BitStream *buf)
{
    return (getBit(buf) << 7) | (getBit(buf) << 6) | (getBit(buf) << 5) | (getBit(buf) << 4) | (getBit(buf) << 3) | (getBit(buf) << 2) | (getBit(buf) << 1) | getBit(buf);
}

u32 func_8007C160(BitStream* arg0, Tree* arg1)
{
    if (getBit(arg0)) {
        s32 pos = D_800E6EB2++;
        // read the 0 side of the tree
        arg1->array[0][pos] = func_8007C160(arg0, arg1);
        // read the 1 side of the tree
        arg1->array[1][pos] = func_8007C160(arg0, arg1);

        return pos;
    }

    return getByte(arg0);
}

static inline s16 decodeHuff(BitStream* buf, Tree* tree) {
    u16 pos = tree->root;

    while ((s16)pos >= 0x100) {
        if (getBit(buf)) {
            pos = tree->array[1][(s16)pos];
        } else {
            pos = tree->array[0][(s16)pos];
        }
    }
    return pos;
}

// register choice v0/v1 for the masked run length, so reorg fills two delay slots differently (masked 9;
// tried u8 temp, n -= run + 1, reusing code as the temp)
#ifdef NON_MATCHING
void func_8007C434(void) {
    s32 n;
    HVQPair* p;
    HVQPair* pu;
    HVQPair* pv;
    s16 code;
    s32 run;
    u32 c2;

    n = D_800E7A44;
    p = D_800E6EB8;
    while (n > 0) {
        code = decodeHuff(&D_800E4DC8[0], &D_800E5690);
        if (!(code & 0xFF)) {
            run = decodeHuff(&D_800E4DE0[0], &D_800E66B0) & 0xFF;
            n = n - 1 - run;
            for (; run != -1; run--) {
                p->bn = 0;
                p++;
            }
        } else {
            p->bn = code;
            p++;
            n--;
        }
    }
    n = D_800E7A50;
    pu = D_800E6EBC;
    pv = D_800E6EC0;
    while (n > 0) {
        c2 = decodeHuff(&D_800E4DC8[1], &D_800E5690) & 0xFF;
        if (c2 == 0) {
            run = decodeHuff(&D_800E4DE0[1], &D_800E66B0) & 0xFF;
            n = n - 1 - run;
            for (; run != -1; run--) {
                pv->bn = 0;
                pv++;
                pu->bn = 0;
                pu++;
            }
        } else {
            pu->bn = c2 & 0xF;
            pu++;
            pv->bn = c2 >> 4;
            pv++;
            n--;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/7CD60", func_8007C434);
#endif

static inline s16 decodeSym(BitStream* buf, Tree* tree) {
    return tree->array[0][decodeHuff(buf, tree)];
}

s32 func_8007C818(u8* dcrun, BitStream* buf, BitStream* runbuf) {
    s16 delta;
    s16 val;

    if (*dcrun == 0) {
        delta = decodeSym(buf, &D_800E4E80);
        if (delta == 0) {
            *dcrun = decodeHuff(runbuf, &D_800E66B0);
            return 0;
        }
        if (delta == D_800E6EB6 || delta == D_800E6EB4) {
            do {
                val = decodeSym(buf, &D_800E4E80);
                delta += val;
            } while (val <= D_800E6EB6 || val >= D_800E6EB4);
        }
        return delta;
    }
    *dcrun -= 1;
    return 0;
}

// register allocation and spill-slot choice under -O3 (pointer locals spilled in retail; masked 147: the opcode
// mix is identical except retail has three more spill lw/sw pairs)
#ifdef NON_MATCHING
void func_8007CA90(void) {
    u8 dcrun[3];
    s32 rows;
    HVQPair* py;
    HVQPair* pu;
    HVQPair* pv;
    HVQPair* pyp;
    HVQPair* pup;
    HVQPair* pvp;
    s32 i;
    u8 y;
    u8 u;
    u8 v;
    u8 t;

    py = D_800E6EB8;
    i = D_800E7A48;
    pu = D_800E6EBC;
    pv = D_800E6EC0;
    pup = pu;
    pvp = pv;
    v = 0;
    u = 0;
    y = 0;
    dcrun[2] = 0;
    dcrun[1] = 0;
    dcrun[0] = 0;
    pyp = py;
    for (; i > 0; i--) {
        t = y + func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
        py->dc = t;
        py += 1;
        y = t + func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
        py->dc = y;
        py += 1;
        u += func_8007C818(&dcrun[1], &D_800E4DF8[1], &D_800E4E48[1]);
        pu->dc = u;
        pu += 1;
        v += func_8007C818(&dcrun[2], &D_800E4DF8[2], &D_800E4E48[2]);
        pv->dc = v;
        pv += 1;
    }
    y = pyp->dc;
    for (i = D_800E7A48; i > 0; i--) {
        y += func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
        py->dc = y;
        pyp += 1;
        py += 1;
        y = ((pyp->dc + y) >> 1) + func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
        pyp += 1;
        py->dc = y;
        py += 1;
        y = (pyp->dc + y) >> 1;
    }
    for (rows = D_800E7A4C - 1; rows > 0; rows--) {
        u = pup->dc;
        v = pvp->dc;
        y = pyp->dc;
        for (i = D_800E7A48; i > 0; i--) {
            y += func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
            py->dc = y;
            pyp += 1;
            py += 1;
            pup += 1;
            pvp += 1;
            y = ((pyp->dc + y) >> 1) + func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
            pyp += 1;
            py->dc = y;
            y = (pyp->dc + y) >> 1;
            u += func_8007C818(&dcrun[1], &D_800E4DF8[1], &D_800E4E48[1]);
            pu->dc = u;
            u = (pup->dc + u) >> 1;
            v += func_8007C818(&dcrun[2], &D_800E4DF8[2], &D_800E4E48[2]);
            pu += 1;
            py += 1;
            pv->dc = v;
            pv += 1;
            v = (pvp->dc + v) >> 1;
        }
        y = pyp->dc;
        for (i = D_800E7A48; i > 0; i--) {
            y += func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
            py->dc = y;
            pyp += 1;
            py += 1;
            y = ((pyp->dc + y) >> 1) + func_8007C818(&dcrun[0], &D_800E4DF8[0], &D_800E4E48[0]);
            pyp += 1;
            py->dc = y;
            py += 1;
            y = (pyp->dc + y) >> 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/7CD60", func_8007CA90);
#endif

/* NEST */
void func_8007CE28(u8* arg0) {
    s32 i, j;
    s32 hNestBlocks, hMirror, hEmpty;
    s32 vNestBlocks, vMirror, vEmpty;
    u8  *nest, *nest2;

    nest = D_800E7A54;
    if (D_800E7A3C < D_800E7A58) {
        hNestBlocks = D_800E7A3C;
        hMirror = D_800E7A58 - hNestBlocks;
        if (hNestBlocks < hMirror) {
            hMirror = hNestBlocks;
        }
        hEmpty = D_800E7A58 - (hNestBlocks + hMirror);
    } else {
        hNestBlocks = D_800E7A58;
        hMirror = 0;
        hEmpty = 0;
    }

    vNestBlocks = D_800E7A40;
    vMirror = D_800E7A5C - D_800E7A40;
    if (D_800E7A40 < D_800E7A5C) {
        if (D_800E7A40 < vMirror) {
            vMirror = D_800E7A40;
        }
        vEmpty = D_800E7A5C - (D_800E7A40 + vMirror);
    } else {
        vNestBlocks = D_800E7A5C;
        vMirror = 0;
        vEmpty = 0;
    }

    for (i = vNestBlocks; i > 0; i--) {
        u8* var_a1 = arg0;
        for (j = hNestBlocks; j > 0; j--) {
            *nest++ = *var_a1;
            var_a1++; var_a1++;
        }
        for (j = hMirror; j > 0; j--) {
            var_a1--; var_a1--;
            *nest++ = *var_a1;
        }
        for (j = hEmpty; j > 0; j--) {
            *nest++ = 0;
        }
        arg0 += D_800E7A3C * 2;
    }

    nest2 = nest - D_800E7A58;
    for (i = vMirror; i > 0; i--) {
        u8* var_a0_2 = nest2;
        for (j = D_800E7A58; j > 0; j--) {    
            *nest++ = *var_a0_2++;
        }
        nest2 -= D_800E7A58;
    }

    for (i = vEmpty; i > 0; i--) {
        for (j = D_800E7A58; j > 0; j--) {
            *nest++ = 0;
        }
    }
    
}

// register allocation, and the abs/max tests take bgez/bnezl instead of bltzl/beqz (masked 84; tried the MP3
// hvq.c s16 abs/max shape, block++ after the max test, a ternary abs: all worse)
#ifdef NON_MATCHING
void func_8007CFCC(s16* block, s32* scale, s32 plane) {
    u16 code;
    s32 step;
    s32 pitch;
    u8* p;
    u8* q;
    s32 mean;
    s32 sum;
    s32 max;
    s32 v;

    code = *(u16*)D_800E4E6C[plane];
    D_800E4E6C[plane] += 2;
    step = (code & 1) + 1;
    pitch = ((code >> 1) & 1) + 1;
    if (D_800E7A60 == 8) {
        p = D_800E7A54 + (((code >> 2) & 0x3F) + ((code >> 8) & 0x1F) * D_800E7A58);
    } else {
        p = D_800E7A54 + (((code >> 2) & 0x1F) + ((code >> 7) & 0x3F) * D_800E7A58);
    }
    pitch *= D_800E7A58;
    q = p;
    sum = block[0] = *q; q += step;
    sum += block[1] = *q; q += step;
    sum += block[2] = *q; q += step;
    sum += block[3] = *q;
    p += pitch;
    q = p;
    sum += block[4] = *q; q += step;
    sum += block[5] = *q; q += step;
    sum += block[6] = *q; q += step;
    sum += block[7] = *q;
    p += pitch;
    q = p;
    sum += block[8] = *q; q += step;
    sum += block[9] = *q; q += step;
    sum += block[10] = *q; q += step;
    sum += block[11] = *q;
    p += pitch;
    q = p;
    sum += block[12] = *q; q += step;
    sum += block[13] = *q; q += step;
    sum += block[14] = *q; q += step;
    sum += block[15] = *q;
    mean = (sum + 8) >> 4;

#define SUB_MEAN()               \
    v = *block -= mean;          \
    block++;                     \
    if (v < 0) {                 \
        v = -v;                  \
    }                            \
    if (max < v) {               \
        max = v;                 \
    }

    max = *block -= mean;
    block++;
    if (max < 0) {
        max = -max;
    }
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
#undef SUB_MEAN
    *scale = D_800E6F30[max] * (*scale + (code >> 13));
}
#else
INCLUDE_ASM("asm/nonmatchings/7CD60", func_8007CFCC);
#endif

void func_8007D470(s16* block, s32 nbasis, s32 dc, s32 plane) {
    s16 basis[16];
    s32 scale;
    s32 i;
    s16* p;

    if (nbasis == 8) {
#define RAW() *block++ = *D_800E4E6C[plane]++
        RAW(); RAW(); RAW(); RAW();
        RAW(); RAW(); RAW(); RAW();
        RAW(); RAW(); RAW(); RAW();
        RAW(); RAW(); RAW(); RAW();
#undef RAW
        return;
    }
    dc &= 0xFF;
    p = block;
#define FILL() *p++ = dc
    FILL(); FILL(); FILL(); FILL();
    FILL(); FILL(); FILL(); FILL();
    FILL(); FILL(); FILL(); FILL();
    FILL(); FILL(); FILL(); FILL();
#undef FILL
    for (i = 0; i < nbasis; i++) {
        scale = decodeSym(&D_800E4E20[plane], &D_800E5EA0);
        func_8007CFCC(basis, &scale, plane);
        p = block;
#define ADD(n) *p++ += (scale * basis[n] + 0x200) >> 10
        ADD(0); ADD(1); ADD(2); ADD(3);
        ADD(4); ADD(5); ADD(6); ADD(7);
        ADD(8); ADD(9); ADD(10); ADD(11);
        ADD(12); ADD(13); ADD(14); ADD(15);
#undef ADD
    }
}

// MP3 hvq.c func_80066A44_main shape (s16 results stored last). Retail sign-extends the four corner sums
// (ur/dr/ul/dl) and GCC drops them here: masked 18, 126 of 134 (s16 sums: 42; s16 c2/downv or s32 u8s: worse).
// Logic-equivalent: the sums fit in s16 and only the low 16 bits of each shift are stored.
#ifdef NON_MATCHING
void func_8007DA48(s16* block, unkStruct_D_800E6EC8* info, s32 plane) {
    s32 bn = info->cur.bn;
    u8 dc = info->cur.dc;

    if (bn == 0) {
        s16* p = block;
        u8 right, up, down, left;
        s32 base, c2;
        s32 downv, rightv;
        s32 ud, lr, s0, s1;
        s32 urx, drx, ulx, dlx;
        s32 ur, dr, ul, dl;
        s16 p0, p1, p2, p3;
        s16 p4, p5, p6, p7;
        s16 p8, p9, p10, p11;
        s16 p12, p13, p14;

        right = dc;
        if (info->next.bn == 0) {
            right = info->next.dc;
        }
        up = info->unk0->bn == 0 ? info->unk0->dc : dc;
        down = info->unk8->bn == 0 ? info->unk8->dc : dc;
        left = info->left;
        downv = down;
        rightv = right;
        c2 = dc << 1;
        base = (dc << 3) | 4;
        dr = downv + rightv - c2;
        ud = up - down;
        lr = left - right;
        s0 = ud + lr;
        s1 = ud - lr;
        urx = up - right;
        drx = down - right;
        ulx = up - left;
        dlx = down - left;
        ur = up + right - c2;
        ul = up + left - c2;
        dl = left + down - c2;

        p0 = (base + s0 + ul) >> 3;
        p1 = (base + s0 + ulx) >> 3;
        p2 = (base + s1 + urx) >> 3;
        p3 = (base + s1 + ur) >> 3;
        p4 = (base + s0 - ulx) >> 3;
        p5 = (base - dr) >> 3;
        p6 = (base - dl) >> 3;
        p7 = (base + s1 - urx) >> 3;
        p8 = (base - s1 - dlx) >> 3;
        p9 = (base - ur) >> 3;
        p10 = (base - ul) >> 3;
        p11 = (base - s0 - drx) >> 3;
        p12 = (base - s1 + dl) >> 3;
        p13 = (base - s1 + dlx) >> 3;
        p14 = (base - s0 + drx) >> 3;
        p[0] = p0;
        p[1] = p1;
        p[2] = p2;
        p[3] = p3;
        p[4] = p4;
        p[5] = p5;
        p[6] = p6;
        p[7] = p7;
        p[8] = p8;
        p[9] = p9;
        p[10] = p10;
        p[11] = p11;
        p[12] = p12;
        p[13] = p13;
        p[14] = p14;
        p[15] = (base - s0 + dr) >> 3;
        info->left = dc;
    } else {
        func_8007D470(block, bn, dc, plane);
        info->left = info->next.dc;
    }
    info->unk0++;
    info->unk8++;
}
#else
INCLUDE_ASM("asm/nonmatchings/7CD60", func_8007DA48);
#endif

/* color conversion */
extern u8  D_800E7730[];

#define tempMacro(y, pixY1, outbuf) \
    do { \
        y = *pixY1++ << 6; \
        outbuf += D_800E7A30; \
    } while (0)

#define UV_BASE ((s32)(16384*(513.0/512.0))) // 0x4020
#define CONVERT(U,V,UPTR,VPTR,R,G,B)\
  V = *(VPTR) - 128;\
  R = 90 * v + UV_BASE;\
  U = *(UPTR) - 128;\
  G = -22 * U + -46 * V + UV_BASE;\
  B = 113 * U + UV_BASE;


static inline u16 getRGB(s16 y, s16 ruv, s16 guv, s16 buv) {
    return  (D_800E7730[(y + ruv) >> 6] << 8) | 
            (D_800E7730[(y + guv) >> 6] << 3) |  
            (D_800E7730[(y + buv) >> 6] >> 2);
}

void func_8007DC58(u16* outbuf, u16* pixY, u16* pixU, u16* pixV) {
    s32 i;
    u16* pixY0, *pixY1, *pixY2;
    s16 y, u, v;
    s16 ruv1, guv1, buv1,
        ruv2, guv2, buv2,
        ruv3, guv3, buv3,
        ruv4, guv4, buv4;
        u16* curoutbuf = outbuf;

    pixY1 = pixY;
    pixY2 = pixY = pixY + 16;

    i = 4;
    while (i > 0) {
        curoutbuf = outbuf;
        CONVERT(u, v, pixU++, pixV++, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        
        CONVERT(u, v, pixU++, pixV++, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);

        CONVERT(u, v, pixU++, pixV++, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        
        CONVERT(u, v, pixU++, pixV++, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);

        outbuf += D_800E7A30;
        curoutbuf = outbuf;

        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        i-=2;
        outbuf += D_800E7A30;
    }

    pixY = pixY + 16;
    pixY1 = pixY;
    pixY2 = pixY + 16;

    i = 4;
    while (i > 0) {
        curoutbuf = outbuf;
        CONVERT(u, v, pixU++, pixV++, ruv1, guv1, buv1);

        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);

        CONVERT(u, v, pixU++, pixV++, ruv2, guv2, buv2);

        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);

        CONVERT(u, v, pixU++, pixV++, ruv3, guv3, buv3);

        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);

        CONVERT(u, v, pixU++, pixV++, ruv4, guv4, buv4);

        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        
        outbuf += D_800E7A30;
        curoutbuf = outbuf;

        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        
        i-=2;
        outbuf += D_800E7A30;
    }
}

// Shift the plane's cursor one block right: the current block takes the
// read-ahead one, which is refilled from the work buffer.
#define ADVANCE(info)                     \
    (info).cur = (info).next;             \
    (info).next = *++(info).unk4

#define ADVANCE_LAST(info)                \
    (info).cur = (info).next;             \
    (info).unk4++

void func_8007EE54(u16* outbuf) {
    s16 y[64];
    s16 u[16];
    s16 v[16];
    s32 i;

    D_800E6EC8.next = *D_800E6EC8.unk4;
    D_800E6EC8.left = D_800E6EC8.next.dc;
    D_800E6EE0.next = *D_800E6EE0.unk4;
    D_800E6EE0.left = D_800E6EE0.next.dc;
    D_800E6EF8.next = *D_800E6EF8.unk4;
    D_800E6EF8.left = D_800E6EF8.next.dc;
    D_800E6F10.next = *D_800E6F10.unk4;
    D_800E6F10.left = D_800E6F10.next.dc;
    for (i = D_800E7A48 - 1; i > 0; i--) {
        ADVANCE(D_800E6EC8);
        func_8007DA48(&y[0], &D_800E6EC8, 0);
        ADVANCE(D_800E6EC8);
        func_8007DA48(&y[16], &D_800E6EC8, 0);
        ADVANCE(D_800E6EE0);
        func_8007DA48(&y[32], &D_800E6EE0, 0);
        ADVANCE(D_800E6EE0);
        func_8007DA48(&y[48], &D_800E6EE0, 0);
        ADVANCE(D_800E6EF8);
        func_8007DA48(u, &D_800E6EF8, 1);
        ADVANCE(D_800E6F10);
        func_8007DA48(v, &D_800E6F10, 2);
        func_8007DC58(outbuf, (u16*)y, (u16*)u, (u16*)v);
        outbuf += 8;
    }
    ADVANCE(D_800E6EC8);
    func_8007DA48(&y[0], &D_800E6EC8, 0);
    ADVANCE_LAST(D_800E6EC8);
    func_8007DA48(&y[16], &D_800E6EC8, 0);
    ADVANCE(D_800E6EE0);
    func_8007DA48(&y[32], &D_800E6EE0, 0);
    ADVANCE_LAST(D_800E6EE0);
    func_8007DA48(&y[48], &D_800E6EE0, 0);
    ADVANCE_LAST(D_800E6EF8);
    func_8007DA48(u, &D_800E6EF8, 1);
    ADVANCE_LAST(D_800E6F10);
    func_8007DA48(v, &D_800E6F10, 2);
    func_8007DC58(outbuf, (u16*)y, (u16*)u, (u16*)v);
}

/* What is this? */
void func_8007F2FC(u16* arg0) {
    s32 var_s2;
    u16* var_s3;

    D_800E6EC8.unk0 = D_800E6EC8.unk4 = D_800E6EB8;
    D_800E6EC8.unk8 = D_800E6EB8 + D_800E7A3C;

    D_800E6EF8.unk0 = D_800E6EF8.unk4 = D_800E6EBC;
    D_800E6EF8.unk8 = D_800E6EBC + D_800E7A48;
    
    D_800E6F10.unk0 = D_800E6F10.unk4 = D_800E6EC0;
    D_800E6F10.unk8 = D_800E6EC0 + D_800E7A48;

    D_800E6EE0.unk0 = D_800E6EB8;
    D_800E6EE0.unk4 = D_800E6EB8 + D_800E7A3C;
    D_800E6EE0.unk8 = D_800E6EB8 + D_800E7A3C + D_800E7A3C;

    func_8007EE54(arg0); // blocks width?
    arg0 += D_800E7A34;

    D_800E6EF8.unk0 = D_800E6EBC;
    D_800E6F10.unk0 = D_800E6EC0;

    D_800E6EC8.unk4 += D_800E7A3C;
    D_800E6EC8.unk8 += D_800E7A3C;
    
    D_800E6EE0.unk0 += D_800E7A3C;
    D_800E6EE0.unk4 += D_800E7A3C;
    D_800E6EE0.unk8 += D_800E7A3C;

    for (var_s2 = D_800E7A4C - 2;var_s2 > 0; var_s2--) {
        func_8007EE54(arg0);
        arg0 += D_800E7A34;
        
        D_800E6EC8.unk0 += D_800E7A3C;
        D_800E6EC8.unk4 += D_800E7A3C;
        D_800E6EC8.unk8 += D_800E7A3C;
        
        D_800E6EE0.unk0 += D_800E7A3C;
        D_800E6EE0.unk4 += D_800E7A3C;
        D_800E6EE0.unk8 += D_800E7A3C;
    }
    
    D_800E6EE0.unk8 = D_800E6EE0.unk4;
    D_800E6EF8.unk8 = D_800E6EF8.unk4;
    D_800E6F10.unk8 = D_800E6F10.unk4;
    func_8007EE54(arg0);
}

/* DECODE */
extern u32 func_8007C160(BitStream*, Tree*);

static inline void ReadHufStream(BitStream *buf, Tree *tree, u32 *src) {
    if(*src) {
        buf->pos = &src[1];
        buf->bit = 0;
        if(tree) {
            D_800E6EB2 = 256;
            tree->root = func_8007C160(buf, tree);
        }
    } else {
        buf->pos = NULL;
        buf->bit = 0;
    }
}
static inline void ReadStream(BitStream *buf, u32 *src) {
    if(!(*src)) {
        buf->pos = NULL;
    } else {
        buf->pos = &src[1];
        buf->bit = 0;
        return;
    }
    buf->bit = 0;
}
static inline void GenQuantizeData(int step) {
    int i, alt_i;
    D_800E6EB4 = 0x7F << step;
    D_800E6EB6 = -0x80 << step;
    for(alt_i = i = 0; i < 256; i++, alt_i++) {
        D_800E5EA0.array[0][i] = (s8)alt_i << 3;
        D_800E4E80.array[0][i] = (s8)alt_i << step;
    }
}

//decodes HVQ2 image to RGB
void func_8007F54C(void* code, u16* outbuf, u32 outbufWidth, u16* workbuf) {
    u16 blocks_h, blocks_w;
    u16 *dc_ptr, *scale_ptr;
    HVQ2Header *header = code;
    blocks_w = header->width >> 2;
    blocks_h = header->height >> 2;
    D_800E7A30 = outbufWidth;
    D_800E7A34 = outbufWidth * 8;
    D_800E7A38 = outbufWidth * 4;
    D_800E7A3C = blocks_w;
    D_800E7A40 = blocks_h;
    D_800E7A48 = D_800E7A3C >> 1;
    D_800E7A4C = D_800E7A40 >> 1;
    D_800E7A44 = D_800E7A3C * D_800E7A40;
    D_800E7A50 = D_800E7A48 * D_800E7A4C;
    D_800E7A60 = header->y_shiftnum;
    if (D_800E7A60 == 8) {
        D_800E7A58 = 0x46;
        D_800E7A5C = 0x26;
    } else {
        D_800E7A58 = 0x26;
        D_800E7A5C = 0x46;
    }
    D_800E4E6C[0] = code+header->fix_offset[0]+4;
    D_800E4E6C[1] = code+header->fix_offset[1]+4;
    D_800E4E6C[2] = code+header->fix_offset[2]+4;
    ReadHufStream(&D_800E4DC8[0], &D_800E5690, code+header->basisnum_offset[0]);
    ReadStream(&D_800E4DC8[1], code+header->basisnum_offset[1]);
    ReadHufStream(&D_800E4DE0[0], &D_800E66B0, code+header->basnum_run_offset[0]);
    ReadStream(&D_800E4DE0[1], code+header->basnum_run_offset[1]);
    ReadStream(&D_800E4E48[0], code+header->dc_run_offset[0]);
    ReadStream(&D_800E4E48[1], code+header->dc_run_offset[1]);
    ReadStream(&D_800E4E48[2], code+header->dc_run_offset[2]);
    ReadHufStream(&D_800E4E20[0], &D_800E5EA0, code+header->scale_offset[0]);
    ReadStream(&D_800E4E20[1], code+header->scale_offset[1]);
    ReadStream(&D_800E4E20[2], code+header->scale_offset[2]);
    ReadHufStream(&D_800E4DF8[0], &D_800E4E80, code+header->dc_offset[0]);
    ReadStream(&D_800E4DF8[1], code+header->dc_offset[1]);
    ReadStream(&D_800E4DF8[2], code+header->dc_offset[2]);
    GenQuantizeData(header->quantize_step);
    D_800E7A54 = &D_800E4360;
    D_800E6EB8 = (HVQPair*)workbuf;
    D_800E6EBC = D_800E6EB8+D_800E7A44;
    D_800E6EC0 = D_800E6EBC+D_800E7A50;
    func_8007C434();
    func_8007CA90();
    func_8007CE28((u8*) &D_800E6EB8[header->nest_start_x + (header->nest_start_y * D_800E7A3C)]);
    func_8007F2FC(outbuf);
}


/* hvqInit1 */
static inline s32 calc_E7730val(s32 index){
    if(index >= 0) {
        if(index >= 0x100) {
            return 0xF8;
        } else {
            return index & ~0x7;
        }
    } else {
        return 0;
    }
}

void func_8007FAC0() {
    s32 i;
    s32 var_v1;
    u8 var_v0;

    for (i = 0, var_v1 = -0x100; i < 0x300; i++, var_v1++) {
        D_800E7730[i] = calc_E7730val(var_v1);
    }

    D_800E6F30[0] = 0;
    for (i = 1; i < 0x200; i++) {
        D_800E6F30[i] = 0x1000 / i;
    }
}