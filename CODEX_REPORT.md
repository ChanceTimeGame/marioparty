# ovl_24_FlowerShower decomp report (in progress)
Branch head: `9e61005` (`pb/cx24`); report baseline recorded 2026-10-12.
Matched this branch: `func_800F6A64_FlowerShower`, `func_800F6FF4_FlowerShower`, `func_800F712C_FlowerShower`, `func_800F726C_FlowerShower`, `func_800F7BD0_FlowerShower`, `func_800F7CE0_FlowerShower`, `func_800F7DF0_FlowerShower`, `func_800F7F00_FlowerShower`, `func_800F8010_FlowerShower`, `func_800F8058_FlowerShower`, `func_800F80A8_FlowerShower`, `func_800F80F4_FlowerShower`, `func_800F8148_FlowerShower`, `func_800F8198_FlowerShower`, `func_800F81E8_FlowerShower`, `func_800F8234_FlowerShower`, `func_800F8620_FlowerShower`, `func_800F8648_FlowerShower`, `func_800F8918_FlowerShower`, `func_800FA4EC_FlowerShower`, `func_800FA58C_FlowerShower`, `func_800FACA0_FlowerShower`.
Still asm, pending attempt: `func_800F65E0_FlowerShower` (~289 instructions), `func_800F6A90_FlowerShower` (~345), `func_800F7348_FlowerShower` (~181), `func_800F761C_FlowerShower` (~259), `func_800F7A28_FlowerShower` (~106), `func_800F8280_FlowerShower` (~232), `func_800F870C_FlowerShower` (~131), `func_800F898C_FlowerShower` (~456), `func_800F90AC_FlowerShower` (~94), `func_800F9224_FlowerShower` (~244), `func_800F95F4_FlowerShower` (~310), `func_800F9ACC_FlowerShower` (~427), `func_800FA178_FlowerShower` (~78), `func_800FA2B0_FlowerShower` (~143), `func_800FA5B8_FlowerShower` (~221), `func_800FA92C_FlowerShower` (~221). Reason: not yet attempted on this run.
Data/rodata moved: none yet. Left: `.data` labels `D_800FAD30` through `D_800FADCC`; rodata `D_800FADD0`, and function-owned constants `D_800FAE40`/`D_800FAE48`.
Pointer holders: `FlowerShowerBodyWork.unk_68` is `s32*`; no integer pointer holders identified. `omObjData.unk_50` uses the repository pointer field.
Prototype changes in `include/`: none. Makefile edits: none.
Host watch items: opaque `FlowerShowerBodyWork` prefix and layout-sensitive engine object fields remain to review; every called function will be prototyped.

Verification baseline (will be replaced after the final commit):
`make: Nothing to be done for 'all'.`
`0 objects differ — OK`
```text
function                                       exp   got   raw masked
38/38 functions identical — OK
```
`n64nmcmp.sh`: baseline raw invocation printed `1`; final report will include a fresh full raw run.
