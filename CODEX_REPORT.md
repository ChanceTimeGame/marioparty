# ovl_34_BumperBallMaze decompilation report
Branch head at report creation: `43b053f` (`pb/cx34`).
Baseline: `make: Nothing to be done for 'all'.`
Baseline: `0 objects differ — OK`
Matched C already on branch: func_800F6994, func_800F6BB8, func_800F6C28, func_800F6C44, func_800F7ED0, func_800F7F60, func_800F8108, func_800F8184, func_800F8220, func_800F8AB8, func_800F8DFC, func_800F9034, func_800F923C, func_800F9278, func_800F943C, func_800F96B0, func_800F9768, func_800F97B4, func_800F9890, func_800F993C, func_800F9974 (all names suffixed `_BumperBallMaze`).
Still asm, pending attempt: func_800F9610 (40 insns), func_800F7FE0 (74), func_800F94A0 (92), func_800F928C (108), func_800F69F4 (113), func_800F827C (123), func_800F9050 (123), func_800F8E1C (134), func_800F8AFC (192), func_800F7BB8 (199), func_800F65E0 (237), func_800FA620 (314), func_800F6C7C (370), func_800FA010 (388), func_800F9990 (418), func_800F8468 (420).
Not attempted by instruction cutoff: func_800F7240 (614 insns).
Initialised data/rodata: pending inventory and migration.
Pointer-bearing globals/fields: object globals use `omObjData*`; `omObjData.unk_50` is cast to typed work/state pointers; no integer pointer storage introduced.
Prototype changes in `include/`: none so far.
Makefile edits: none so far.
Host review pending: remaining asm and initialised data will be checked for pointer and layout hazards.
Final per-unit `n64chkf.py` and `n64nmcmp.sh` evidence will replace this provisional section after the last commit.
