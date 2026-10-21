# Project-X analyzer performance comparison (BEFORE vs AFTER)

- BEFORE run: before3 - 2026-10-17T15:32:41.915Z → 2026-10-17T15:33:24.398Z - dist `C:\Users\j\OneDrive\Desktop\Project-X\benchmarks\baseline-snapshot\analyzer\dist\index.js`
- AFTER run: after3 - 2026-10-17T15:33:24.523Z → 2026-10-17T15:34:15.345Z - dist `C:\Users\j\OneDrive\Desktop\Project-X\analyzer\dist\index.js`
- Workload file: `C:\Users\j\OneDrive\Desktop\Project-X\benchmarks\workloads\workloads.json` (seed 20261017) - identical for both runs
- Node v24.12.0, platform win32, clang `C:\Program Files\LLVM\bin\clang++.exe`
- Cold sample = fresh Clang parse (AST cache cleared); warm sample = cached-AST re-analysis.

| Scenario | Cases | Cold median before | Cold median after | Cold change | Warm median before | Warm median after | Warm change | Peak RSS before | Peak RSS after | Correctness before | Correctness after |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| typical-selection | 12 | 124.1 ms | 123.7 ms | +0.3% | 8.97 ms | 9.43 ms | -5.2% | 99652 KB | 98976 KB | 12/12 | 12/12 |
| boundary-one-liners | 8 | 128.7 ms | 124.8 ms | +3.0% | 9.21 ms | 8.27 ms | +10.1% | 79860 KB | 79864 KB | 7/7 | 7/7 |
| previously-failing | 15 | 124.8 ms | 126.3 ms | -1.2% | 8.75 ms | 9.52 ms | -8.9% | 102536 KB | 100508 KB | 14/14 | 14/14 |
| adversarial-shapes | 6 | 131.1 ms | 130.4 ms | +0.5% | 13.52 ms | 14.18 ms | -4.9% | 131088 KB | 109416 KB | 0/0 | 0/0 |
| invalid-inputs | 8 | 124.1 ms | 124.4 ms | -0.2% | 8.39 ms | 8.39 ms | -0.0% | 75680 KB | 72756 KB | 0/0 | 0/0 |
| large-document | 2 | 315.7 ms | 327.2 ms | -3.6% | 137.79 ms | 144.46 ms | -4.8% | 146344 KB | 188072 KB | 0/0 | 0/0 |
| stress-throughput | 60 | 124.6 ms | 127.1 ms | -2.0% | 8.55 ms | 8.88 ms | -3.9% | 107456 KB | 109276 KB | 60/60 | 60/60 |
| **overall** | 111 | 124.8 ms | 126.3 ms | -1.2% | 8.72 ms | 9.02 ms | -3.4% | n/a | n/a | 93/93 | 93/93 |

Positive percentages in the change columns mean the AFTER build is faster (lower latency); for RSS they mean lower memory.

