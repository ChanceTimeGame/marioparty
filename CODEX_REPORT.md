# ovl_13_BalloonBurst decompilation report (in progress)

Branch: `pb/cx13`; head: `32db5dc` (in-progress snapshot).
Status: work in progress; final verification output will replace the placeholders below.
Matched before this run: `func_800F6BAC_BalloonBurst`, `func_800F6D14_BalloonBurst`, `func_800F70E0_BalloonBurst`, `func_800F7100_BalloonBurst`, `func_800F7120_BalloonBurst`, `func_800F7140_BalloonBurst`, `func_800F7160_BalloonBurst`, `func_800F71D8_BalloonBurst`, `func_800F7D9C_BalloonBurst`, `func_800F94E0_BalloonBurst`, `func_800F9520_BalloonBurst`, `func_800FA8A4_BalloonBurst`, `func_800FA9C4_BalloonBurst`.
Matched this run: `func_800F6C44_BalloonBurst`, `func_800F7E38_BalloonBurst`, `func_800FAA6C_BalloonBurst`.
Still asm: `func_800F65E0_BalloonBurst`, `func_800F6DB8_BalloonBurst`, `func_800F7298_BalloonBurst`, `func_800F77D0_BalloonBurst`, `func_800F7F94_BalloonBurst`, `func_800F8670_BalloonBurst`, `func_800F8D6C_BalloonBurst`, `func_800F9368_BalloonBurst` (attempted; best raw 39/masked 17), `func_800F95F8_BalloonBurst`.
Data/rodata: all initialized data and nine rodata labels are still assembly pending verified migration.
Pointer globals/fields: `D_800FB0F8_BalloonBurst` is `Gfx **[]`; `D_800ED554` is `unk34D80Struct80 *`; `omObjData.unk_50` is converted directly to `BalloonBurstObjectWork *`; `omObjData.func_ptr` is used directly.
Prototype changes in `include/`: none.
Makefile edits: none.
Host concerns: existing `func_800FA8A4_BalloonBurst` uses byte-offset accesses into overlay BSS; final audit pending.

Final `make -j8` last line: PENDING
Final `n64chkf.py . ALL` last line: PENDING
Final per-unit `n64chkf.py` output: PENDING
Final per-unit `n64nmcmp.sh` output: PENDING
