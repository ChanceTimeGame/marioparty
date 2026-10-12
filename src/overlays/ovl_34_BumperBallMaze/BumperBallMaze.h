#ifndef BUMPERBALLMAZE_H
#define BUMPERBALLMAZE_H

/* Host views of splat labels that retail indexes across (games/mp1/host/tools/gen_ovl.py reads
   these to keep the label inside the object before it). */
#ifdef TARGET_PC
/* The far-edge wave phases: 0x3C into D_800FAE20's rows (240010.c). */
#define D_800FAE5C_BumperBallMaze ((f32*) D_800FAE20_BumperBallMaze + 15)
#endif

#endif
