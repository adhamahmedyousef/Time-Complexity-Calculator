# Project-X analyzer performance comparison (BEFORE vs AFTER)

- BEFORE run: round7-before3 (best-of-3 merge: round7-before1, round7-before2, round7-before3) - 2026-10-18T21:35:30.609Z → 2026-10-18T21:39:04.629Z - dist `C:\Users\j\OneDrive\Desktop\Project-X\benchmarks\baseline-snapshot\analyzer\dist\index.js`
- AFTER run: round7-after3 (best-of-3 merge: round7-after1, round7-after2, round7-after3) - 2026-10-18T21:36:17.436Z → 2026-10-18T21:39:46.283Z - dist `C:\Users\j\OneDrive\Desktop\Project-X\analyzer\dist\index.js`
- Workload file: `C:\Users\j\OneDrive\Desktop\Project-X\benchmarks\workloads\workloads.json` (seed 20261017) - identical for both runs
- Node v24.12.0, platform win32, clang `C:\Program Files\LLVM\bin\clang++.exe`
- Cold sample = fresh Clang parse (AST cache cleared); warm sample = cached-AST re-analysis.

| Scenario | Cases | Cold median before | Cold median after | Cold change | Warm median before | Warm median after | Warm change | Peak RSS before | Peak RSS after | Correctness before | Correctness after |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| typical-selection | 12 | 138.6 ms | 141.6 ms | -2.2% | 9.14 ms | 9.33 ms | -2.1% | 104500 KB | 87880 KB | 12/12 | 12/12 |
| boundary-one-liners | 8 | 142.1 ms | 140.6 ms | +1.1% | 8.44 ms | 8.46 ms | -0.3% | 80600 KB | 80136 KB | 7/7 | 7/7 |
| previously-failing | 15 | 140.9 ms | 141.6 ms | -0.5% | 9.55 ms | 9.48 ms | +0.7% | 99596 KB | 99660 KB | 14/14 | 14/14 |
| adversarial-shapes | 6 | 146.3 ms | 150.7 ms | -3.0% | 14.20 ms | 16.38 ms | -15.4% | 129688 KB | 137276 KB | 0/0 | 0/0 |
| invalid-inputs | 8 | 139.0 ms | 137.2 ms | +1.3% | 7.93 ms | 8.38 ms | -5.6% | 75560 KB | 74080 KB | 0/0 | 0/0 |
| large-document | 2 | 365.3 ms | 400.3 ms | -9.6% | 161.81 ms | 208.32 ms | -28.7% | 146612 KB | 160572 KB | 0/0 | 0/0 |
| stress-throughput | 60 | 140.7 ms | 140.0 ms | +0.5% | 8.93 ms | 8.79 ms | +1.6% | 108308 KB | 110672 KB | 60/60 | 60/60 |
| **overall** | 111 | 141.2 ms | 140.6 ms | +0.4% | 9.02 ms | 8.94 ms | +0.9% | n/a | n/a | 93/93 | 93/93 |

Positive percentages in the change columns mean the AFTER build is faster (lower latency); for RSS they mean lower memory.

