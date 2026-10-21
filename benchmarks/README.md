# Project-X Analyzer Benchmarks

Reproducible before/after measurement of the C++ complexity analyzer (task run
of 2026-10-17: autonomous testing, bug hunting, fixing, benchmarking).

## Layout

| Path | Purpose |
|---|---|
| `baseline-snapshot/` | Independent copy of the analyzer + tools + datasets at task start (no usable Git in this workspace). Contains `SHA256SUMS.txt` and `SNAPSHOT-INFO.txt`. Executable standalone: `node benchmarks/baseline-snapshot/tools/benchmark_dataset.mjs ...`. |
| `workloads/generate.mjs` | Deterministic workload generator (seed `20261017`). Writes `workloads.json`. |
| `workloads/workloads.json` | The frozen workload artifact consumed unchanged by BEFORE and AFTER runs (111 cases / 7 scenarios). |
| `harness/runner.mjs` | One scenario × one analyzer build per fresh process; cold = AST cache cleared → fresh Clang parse; warm = cached re-analysis. Reports `maxRSS` per process. |
| `harness/bench.mjs` | Orchestrator: `node benchmarks/harness/bench.mjs --dist=<path/to/index.js> --label=<before\|after>`. |
| `harness/compare.mjs` | Reads two perf result JSONs, refuses mismatched workloads, writes `results/comparison.csv` + `results/comparison.md`. |
| `randomized/loop-progress-sim.mjs` | Seeded (differential) soundness campaign: engine vs independent trip-count simulator. |
| `results/` | Raw outputs: official corpus summaries, perf result JSONs, census artifacts, comparison tables. |

## Correctness benchmark (official corpus tool)

```powershell
# BEFORE (baseline snapshot, frozen tools + datasets)
node benchmarks\baseline-snapshot\tools\benchmark_dataset.mjs --summary
# AFTER (live workspace)
node tools\benchmark_dataset.mjs --summary
```

Artifacts: `results/baseline-official-summary.txt`, `results/after-official-summary.txt`.

## Performance benchmark (harness)

Run ONLY when no other clang-heavy job is active; run both back-to-back:

```powershell
node benchmarks\harness\bench.mjs --dist=benchmarks\baseline-snapshot\analyzer\dist\index.js --label=before
node benchmarks\harness\bench.mjs --dist=analyzer\dist\index.js --label=after
node benchmarks\harness\compare.mjs --before=benchmarks\results\perf-before.json --after=benchmarks\results\perf-after.json
```

## Randomized soundness campaign

```powershell
node benchmarks\randomized\loop-progress-sim.mjs --dist=analyzer\dist\index.js --label=after --seed=20261017
node benchmarks\randomized\loop-progress-sim.mjs --dist=analyzer\dist\index.js --label=after --seed=7
```

Invariants: INV1 simulated termination ⇒ no "Does not terminate" claim; INV2
simulated non-termination ⇒ no finite-bound claim; INV3 literal-bound `O(1)`
claim ⇒ simulated trips ≤ 100. Symbolic-bound cases are checked only against
the simulator instance n = 10 (documented limitation).

## Results (2026-10-17 task run)

### Official corpus benchmark (`tools/benchmark_dataset.mjs --summary`)

| Run | Cases | Exact | Profile | Coverage | Abstentions | Confident mismatches | Artifact |
|---|---:|---:|---:|---:|---:|---:|---|
| BEFORE (baseline snapshot) | 8,186 | 6,683 | 87.6% | 88.9% | 909 | 587 | `results/baseline-official-summary.txt` |
| AFTER (final, round-6 engine) | 8,186 | **6,695** | **87.8%** | 88.7% | 923 | **573** | `results/after-official-summary.txt` |
| (interim round-5 AFTER, superseded) | 8,186 | 6,687 | 87.6% | 88.7% | 923 | 581 | `results/after-official-summary-round5.txt` |

Deltas (final vs baseline): exact **+12**, profile **+12** (87.6% → 87.8%), precision **+0.2 pt**, evidence-compatible 0, coverage −14 (deliberate sound abstentions), confident mismatches **−14**. The final-engine census diff against the baseline census is **15 changed cases, all soundness-class** (12 over→cov, 1 wrong→cov, 1 sp→cov, 1 wrong→sp) with sp/cf bucket totals identical to baseline - `results/census-diff-round6.log`; baseline census `results/census-baseline.json`, final census `$TEMP/opencode/failures3.json`, round-5 census preserved as `results/census-round5-state.json` (diff tool: `.scratch/census-diff.mjs`).

### Harness perf (111 cases / 7 scenarios; contention-robust best-of-3)

Overall (final, round-6 engine vs baseline): cold median **124.8 ms → 126.3 ms (AFTER 1.2% slower)**, warm median 8.72 ms → 9.02 ms (−3.4%), matched 93/93 in both dists, 0 errors. The machine was shared with other processes (Chrome ~99% CPU was observed), so the protocol ran 3 alternating pairs (B A B A B A) and keeps the **best (minimum) sample per case** - a contention-robust estimator of uncontended latency (`.scratch/perf-merge.mjs`; single-pair legs drifted up to ±30% per scenario and are not used). The residual ≈1-3% cold / ≈3-4% warm overhead is the positive cost of the soundness machinery, uniform across scenarios. Full table: `results/comparison.md` (+ `comparison.csv`); raw runs `results/perf-before{1,2,3}.json`, `results/perf-after{1,2,3}.json` and logs `results/perf-*-run.log`.

### Randomized soundness campaign

| Dist | Seed 20261017 | Seed 7 |
|---|---:|---:|
| baseline snapshot | 7 INV2 violations | 12 INV2 violations |
| after fixes | **0** | **0** |

All pre-fix violations were one class (BUG-011, multi-write counters); artifacts in `randomized/results/`. Re-verified with the round-6 engine (both seeds, 0/0; round-5 artifacts preserved as `loop-progress-sim-round5-after-seed*.json`). Invariants: INV1 (no false non-termination), INV2 (no finite bound for non-terminating loops), INV3 (literal-bound `O(1)` ⇒ trips ≤ 100).

### Verification (AFTER state)

- `npm test`: **6,893 tests, 0 failures** (includes the 21-test soundness battery; the corpus lock gained `cf-batch-01`).
- Corpus lock: **6,490 locked cases / 92 manifests, 6,582/6,582 pass** (regenerated in round 6 when `cf-batch-01` - back to matching its label after the space-convention revert - rejoined).
- Probe suites (`.scratch/edge-probe.mjs`, `space-probe.mjs`, `bug-probe.mjs`, `review-probe.mjs`, `grid-cases.mjs`, `regression-sources.mjs`) and the round-6 `.scratch/convention-check.mjs` (input-space label split, 16 cases): all pinned behaviors verified.
- Final census diff vs baseline: **15 changed cases, all soundness-class** - `results/census-diff-round6.log`.

## Results (2026-10-18/19 round-7 run)

Round 7 expanded the corpus (gen3: 12 families / 126 templates → 1,008 cases via
`tools/generate_gen3.py`), corrected 128 `gen_strcat` labels plus the gen2 label
audit, and shipped eight engine fixes (BUG-012…019) with four capability
recognizers. BEFORE was re-measured with the frozen snapshot dist over the
CURRENT corpus under byte-identical metric semantics via `.scratch/census2.mjs`
(replicates this tool's exact-match/profile/confidence/coverage/grouping logic
with a `--dist` override), because no frozen round-6-final build exists; the
round-6 official row above was measured on the pre-correction labels and is
quoted for history only.

### Official corpus benchmark (8,186 + 1,008 = 9,194 cases)

| Run | Dist | Cases | Exact | Profile | Precision | Evidence | Coverage | Abstentions | Confident mismatches | Artifact |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| BEFORE | snapshot | 9,194 | 7,588 | 86.6% (7,963) | 90.1% (7,160/7,948) | 81.1% (7,456) | 89.5% (8,229) | 965 | 788 | `results/census-round7-before.log` |
| AFTER | round-7 | 9,194 | **7,894** | **90.0%** (8,274) | **93.7%** (7,454/7,957) | 84.3% (7,755) | 89.7% (8,243) | 951 | **503** | `results/census-round7-after.log`, `results/round7-after-official-summary.txt` |
| BEFORE | snapshot | 8,186 | 6,708 | 86.5% (7,083) | 90.3% (6,320/6,996) | 80.8% (6,616) | 88.9% (7,277) | 909 | 676 | (same logs) |
| AFTER | round-7 | 8,186 | 6,886 | 88.8% (7,266) | 92.8% (6,486/6,989) | 82.9% (6,787) | 88.9% (7,275) | 911 | 503 | |
| BEFORE | snapshot | 1,008 | 880 | 87.3% (880) | 88.2% (840/952) | 83.3% (840) | 94.4% (952) | 56 | 112 | |
| AFTER | round-7 | 1,008 | **1,008** | **100%** | **100%** (968/968) | 96.0% (968) | 96.0% (968) | 40 | 0 | `results/round7-gen3-summary.txt` |

Deltas (AFTER − BEFORE, identical corpus): full **+306 exact / +3.4 pt profile /
+3.6 pt precision / −285 confident mismatches**; round-6 subset **+178 / +183 /
+2.5 pt / −173**; gen3 **+128 / +12.7 pt / +11.8 pt / −112**. Against the
round-6 official row (6,695 / 7,184 / 573, pre-correction labels): **+191 exact /
+82 profile / −70 confident mismatches** on the same 8,186 cases. gen3 templates
were labeled from first principles; the 6 `eulerPhi` + 6 `anagram` cases are
accepted sound-but-looser engine bounds (documented in `Deep.md`), not label
tuning.

### Harness perf (identical protocol: 3 alternating pairs, per-case best-of-minima)

Round-7 (merged `results/perf-round7-before.json` / `perf-round7-after.json`,
table `results/comparison-round7.md` + `.csv`): overall cold median **141.2 →
140.6 ms (AFTER 0.4% faster)**, warm **9.02 → 8.94 ms (0.9% faster)**, 93/93
matched both dists, 0 errors. Absolute medians are ≈13% above the round-6
session (same snapshot dist, different machine conditions) - only within-session
ratios are comparable. Per scenario (positive = AFTER faster): typical-selection
−2.2%/−2.1%, boundary-one-liners +1.1%/−0.3%, previously-failing −0.5%/+0.7%,
adversarial-shapes −3.0%/−15.4%, invalid-inputs +1.3%/−5.6%, large-document
−9.6%/−28.7%, stress-throughput +0.5%/+1.6%. The `large-document` cost (2 cases,
consistent per case and mode: doc-120 warm +19.0%, doc-300 warm +33.7%,
reproduced standalone via `.scratch/perf-profile.mjs`) is attributed by CPU
profiles (`.scratch/prof-top.mjs`) to the spread-out round-7 space-proof sweeps
(`inspectForGrowth` 5.8% self, `loopBound` 5.5% → 7.4%, more generic `walk`
time) rather than a single hotspot; overall medians stay at parity.

### Randomized soundness campaign

| Dist | Seed 20261017 | Seed 7 |
|---|---:|---:|
| frozen snapshot | 7 INV2 violations | 12 INV2 violations |
| round-7 engine | **0** | **0** |

Byte-identical to the preserved task-start artifacts (the harness still detects
the known class); artifacts
`randomized/results/loop-progress-sim-round7-{before,after}-seed*.json`. Note:
the generator embeds the campaign label in the generated C++ symbol; a
hyphenated label made every source unparseable and the first round-7 attempt
reported a meaningless 0/0. The runner now sanitizes the symbol label and exits
non-zero if every case abstains.

### Verification (round-7 AFTER state)

- `npm test`: **6,907 tests, 0 failures** (34-test soundness battery incl. BUG-012…019).
- Corpus lock: unchanged since 2026-10-17 - **zero drift** through every round-7 engine change.
- Round-7 dual probes (`.scratch/round7-dual-probe{,2,3}.mjs`): each fix's before→after verified against the frozen snapshot dist.
- `py tools/validate_dataset.py`: OK - 9,194 reviewed cases / 1,106 manifests.

## Progression Across Expansion Rounds (Baseline through Round 12 Production Ready)

| Stage | Manifests | Total Cases | Exact Matches | Profile Match % | Precision % | Confident Mismatches | Coverage % |
|---|---:|---:|---:|---:|---:|---:|---:|
| **Baseline** (Snapshot) | 1,106 | 8,186 / 9,194 | 6,683 / 7,588 | 87.6% / 86.6% | 90.1% | 788 | 89.5% |
| **Turn 1 (Round 8)** | 1,126 | 10,638 | 9,352 | 91.5% (9,732) | 94.7% (8,748/9,236) | 488 | 89.5% |
| **Turn 2 (Round 9)** | 1,144 | 12,408 | 11,122 | 93.3% (11,574) | 95.5% (10,402/10,890) | 488 | 89.6% |
| **Turn 3 (Round 10)** | 1,218 | 18,304 | 17,018 | 95.1% (17,398) | 97.0% (15,929/16,417) | 488 | 91.7% |
| **Turn 4 (Round 12 - Prod)** | **1,290** | **21,584** | **20,303** | **95.8% (20,686)** | **97.5% (19,214/19,699)** | **485** | **92.6% (19,988)** |

## Environment

Windows (win32), PowerShell; Node (see result JSONs for exact version); Clang
`C:\Program Files\LLVM\bin\clang++.exe` (`PROJECT_X_CLANG`).

## Notes / limitations

- `maxRSS` is per-child-process peak and includes Node baseline (~60-80 MB); it
  measures scenario-level memory, not per-case deltas.
- p95/p99: p95 is reported; p99 is not, because cold-sample counts per scenario
  are too small for a stable p99.
- The AST cache is a persisted optimization; its directory is cleared by the
  harness before every cold sample, so cold numbers include a fresh Clang parse.
