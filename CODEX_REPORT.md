# ovl_1C_GrabBag decompilation report

Branch head before this report: `f653cee` (`pb/cx1c`).

Matched on this branch (raw 0): `func_800FB064_GrabBag`, `func_800F7680_GrabBag`, `func_800F7260_GrabBag`, `func_800F7470_GrabBag`, `func_800F738C_GrabBag`, `func_800F72E8_GrabBag`.

Left as asm, pending smallest-first work: `func_800F975C_GrabBag`, `func_800F8984_GrabBag`, `func_800F97E8_GrabBag`, `func_800FAFA0_GrabBag`, `func_800FAED8_GrabBag`, `func_800F9DF0_GrabBag`, `func_800F8484_GrabBag`, `func_800FA304_GrabBag`, `func_800FA658_GrabBag`, `func_800F7538_GrabBag`, `func_800F98A4_GrabBag`, `func_800FA184_GrabBag`, `func_800FA780_GrabBag`, `func_800F9A1C_GrabBag`, `func_800F8A18_GrabBag`, `func_800F6C98_GrabBag`, `func_800F9BC4_GrabBag`, `func_800F67C4_GrabBag`, `func_800F69D4_GrabBag`, `func_800FA424_GrabBag`, `func_800F9ED0_GrabBag`, `func_800FAC0C_GrabBag`, `func_800FA8F4_GrabBag`, `func_800F6E90_GrabBag`, `func_800F859C_GrabBag`, `func_800F8BDC_GrabBag`, `func_800F7EDC_GrabBag`, `func_800F903C_GrabBag`, `func_800F776C_GrabBag`.

Data/rodata moved: none yet. Left: `D_800FB1F8_GrabBag`, `D_800FB208_GrabBag`, and the overlay's initialized data pending typed migration.

Pointer globals/fields introduced on this branch: `GrabBagGroundWork*` stored in `omObjData.unk_50`; no integer pointer holders. Prototype changes in `include/`: none. Makefile edits: none. Host concerns: none identified yet.

Latest verification snapshot (will be refreshed after final commit):
`make -j8`: `make: Nothing to be done for 'all'.`
`n64chkf.py . ALL`: `0 objects differ — OK`
`n64chkf.py . src/overlays/ovl_1C_GrabBag/1837D0.c`:
`function                                       exp   got   raw masked`
`8/8 functions identical — OK`
`n64chkf.py . src/overlays/ovl_1C_GrabBag/184450.c`:
`function                                       exp   got   raw masked`
`5/5 functions identical — OK`
`n64chkf.py . src/overlays/ovl_1C_GrabBag/184870.c`:
`function                                       exp   got   raw masked`
`26/26 functions identical — OK`
`n64nmcmp.sh` output pending final verification.
