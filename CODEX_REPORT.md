# ovl_24_FlowerShower decomp report (in progress)
Branch head before this report update: `e1cf492` (`pb/cx24`); updated 2026-10-12.
Matched this run: `func_800FA178_FlowerShower`, `func_800F90AC_FlowerShower`, `func_800F7A28_FlowerShower`, `func_800F870C_FlowerShower`, `func_800FA2B0_FlowerShower`, `func_800F7348_FlowerShower`, `func_800FA5B8_FlowerShower`, `func_800FA92C_FlowerShower`.
Matched on the first run: `func_800F6A64_FlowerShower`, `func_800F6FF4_FlowerShower`, `func_800F712C_FlowerShower`, `func_800F726C_FlowerShower`, `func_800F7BD0_FlowerShower`, `func_800F7CE0_FlowerShower`, `func_800F7DF0_FlowerShower`, `func_800F7F00_FlowerShower`, `func_800F8010_FlowerShower`, `func_800F8058_FlowerShower`, `func_800F80A8_FlowerShower`, `func_800F80F4_FlowerShower`, `func_800F8148_FlowerShower`, `func_800F8198_FlowerShower`, `func_800F81E8_FlowerShower`, `func_800F8234_FlowerShower`, `func_800F8620_FlowerShower`, `func_800F8648_FlowerShower`, `func_800F8918_FlowerShower`, `func_800FA4EC_FlowerShower`, `func_800FA58C_FlowerShower`, `func_800FACA0_FlowerShower`.
Still asm, pending attempt: `func_800F65E0_FlowerShower` (~289 instructions), `func_800F6A90_FlowerShower` (~345), `func_800F761C_FlowerShower` (~259), `func_800F8280_FlowerShower` (~232), `func_800F898C_FlowerShower` (~456), `func_800F9224_FlowerShower` (~244), `func_800F95F4_FlowerShower` (~310), `func_800F9ACC_FlowerShower` (~427). Reason: not yet attempted on this run.
Data/rodata moved: function-owned doubles `D_800FAE40`/`D_800FAE48` are now matching compiler literals. Left: `.data` labels `D_800FAD30` through `D_800FADCC` and rodata `D_800FADD0`.
Pointer holders: `FlowerShowerBodyWork.unk_68` is `s32*`; no integer pointer holders identified. `omObjData.unk_50` uses the repository pointer field.
Prototype changes in `include/`: none. Makefile edits: isolated `1BD640.c` mul-fix CFLAGS and blank-line-strip assembly rule.
Host watch items: the work prefix remains partly opaque; `unk_24`, `unk_50`, `unk_53`, `unk_54`, `unk_56`, and `unk_58` are now typed from their loads. Every newly called function has a local prototype.

Verification baseline (will be replaced after the final commit):
`OK`
`0 objects differ — OK`
```text
function                                       exp   got   raw masked
38/38 functions identical — OK
```
`n64nmcmp.sh`: baseline raw invocation printed `1`; final report will include a fresh full raw run.
