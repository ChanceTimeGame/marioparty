# ovl_2B_CastAways decompilation report (in progress)

Progress recorded through branch commit `4bacaa8` (`pb/cx2b`).

Matched in C (raw 0): `func_800FB858_CastAways`, `func_800F75BC_CastAways`, `func_800F9E2C_CastAways`, `func_800FB374_CastAways`, `func_800FB5B4_CastAways`, `func_800FB884_CastAways`, `func_800F7308_CastAways`, `func_800FB404_CastAways`, `func_800FAFF0_CastAways`, `func_800FB778_CastAways`.

Still `INCLUDE_ASM`: `func_800FABE4_CastAways` (49): attempted, best masked 2 register/allocation residue; `func_800FB668_CastAways` (68), `func_800F73AC_CastAways` (132), `func_800FAD2C_CastAways` (133), `func_800FA198_CastAways` (158), `func_800FB0C8_CastAways` (171), `func_800F9EAC_CastAways` (187), `func_800F76B8_CastAways` (224), `func_800F6A24_CastAways` (380), `func_800F7A38_CastAways` (471), `func_800F8B1C_CastAways` (504), `func_800FA410_CastAways` (511), `func_800F8194_CastAways` (582): pending; `func_800F92FC_CastAways` (734): not attempted, over the requested ~600-instruction cutoff.

Initialized data remains in assembly pending typed migration: `D_800FB930_CastAways` through the end of `1F0DA0.data.s`, and `D_800FBA30_CastAways` through `D_800FBA80_CastAways` in `1F5700.data.s`.

Pointer-bearing globals/fields currently relevant: `D_800FBB48_ovl2B` is `omObjData*[]`; `CastAwaysSpriteData.buffersA/buffersB` are `void*[]`; `CastAwaysPlayerWork.spriteData`, `animDataA`, `animDataB`, and `lureObj`, and `CastAwaysLureWork.playerObj/animData` use pointer types. No pointer is stored in `s32`/`u32` by matched C.

Host/layout note: `func_800FB884_CastAways` uses typed `D_800EE73C` only on N64 to reproduce retail base-register codegen; its `TARGET_PC` path addresses the complete typed camera object `D_800EE738`.

Prototype changes in `include/`: none. Overlay header corrected `func_800F7308_CastAways` to take `omObjData*` and typed the two light parameters. Makefile edits: none.

Final verification evidence will replace this in-progress baseline before handoff. Current baseline: `make: Nothing to be done for 'all'.`; `0 objects differ — OK`; `1F0DA0.c: 29/29 functions identical — OK`; `1F5700.c: 13/13 functions identical — OK`.

## Claude second pass (supersedes the "Still INCLUDE_ASM" and data lines above)

All 15 remaining functions are C: `func_800FB0C8` matches; the other 14 are NON_MATCHING
(logic-checked against the asm with `n64nmcmp.sh`). `.data` of both units is C. bss is referenced
only through splat's `_CastAways` labels (the `_ovl2B` aliases indexed across labels, which the
host gives separate objects). Work structs for the spawner, fish, hook and player objects are in
`CastAways.h`.
