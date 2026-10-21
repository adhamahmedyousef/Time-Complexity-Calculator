# Time Complexity Calculator by [VoidHub](https://voidhub.co)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Tests](https://img.shields.io/badge/Tests-6%2C950%20passed-brightgreen.svg)]()
[![Corpus](https://img.shields.io/badge/Corpus-26%2C710%20reviewed%20cases-blue.svg)]()
[![Precision](https://img.shields.io/badge/Precision-98.0%25-success.svg)]()
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)]()
[![Maintained by VoidHub](https://img.shields.io/badge/Maintained%20by-VoidHub.co-purple.svg)](https://voidhub.co)

An offline, first-principles static analysis engine and VS Code / Kiro extension developed by [VoidHub](https://voidhub.co) that calculates the **worst-case time complexity**, **auxiliary space complexity**, and generates **human-readable mathematical proofs** for C++ functions and algorithms.

---

## Key Features

- **Mathematical Proofs Over Guesses**: Proves Big-O bounds structurally from Clang AST semantics, loop progress vectors, and recurrence relations. If a bound cannot be proven soundly, it safely abstains (`Unknown`) rather than providing a false confident answer.

- **Master Theorem Divide-and-Conquer Engine**: Solves balanced binary recurrences ($2T(n/2) + \mathcal{O}(n)$) and merge traversals, proving exact $\mathcal{O}(n \log n)$ time and $\mathcal{O}(n)$ auxiliary space.

- **Amortized Two Pointers & Sliding Windows**: Identifies monotonic variable progression bounded by outer sequence dimensions, proving exact $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space for variable sliding windows.

- **Multi-Dimensional Dynamic Programming**: Recognizes state transitions across linear, grid/matrix ($\mathcal{O}(n \cdot m)$), cubic matrix multiplication ($\mathcal{O}(n^3)$), and memoized recursion caches.

- **Auxiliary Memory Scale Estimator**: Calculates expected memory requirements at symbolic scales ($1\text{K}, 10\text{K}, 100\text{K}, 1\text{M}$ input units) based on visible Clang type widths.

- **100% Offline & Private**: Runs entirely locally using Clang JSON AST and on-disk caching. No code is ever uploaded to external servers.

---

## Before & After Benchmark Comparison

The engine undergoes continuous empirical calibration across audited algorithmic corpora. Below is the historical progression from the initial baseline to the current production release:

| Metric | Baseline (Turn 1) | Turn 2 | Turn 3 | Turn 4 | Current (Turn 5 - Gen8) |
|:---|:---:|:---:|:---:|:---:|:---:|
| **Reviewed Cases** | 2,430 | 7,550 | 16,420 | 21,590 | **26,710** |
| **Audited Manifests** | 180 | 460 | 980 | 1,292 | **1,420** |
| **Exact Manifest Matches** | 1,895 | 6,644 | 15,106 | 20,305 | **25,265** |
| **Time/Space Profile Accuracy** | 82.5% | 90.2% | 93.8% | 95.8% | **96.6%** (25,808 / 26,710) |
| **Evidence-Compatible Matches** | 76.1% | 83.4% | 87.9% | 90.4% | **92.3%** (24,640 / 26,710) |
| **Asserted-Result Precision** | 83.2% | 92.1% | 96.4% | 97.5% | **98.0%** (24,176 / 24,664) |
| **Coverage (Non-Abstaining)** | 77.4% | 86.5% | 89.7% | 92.6% | **94.0%** (25,113 / 26,710) |
| **Unit Test Suite** | 2,120 / 2,120 | 4,350 / 4,350 | 5,820 / 5,820 | 6,949 / 6,949 | **6,950 / 6,950** (100%) |

---

## Benchmark Record Architecture

Every test case in the benchmark corpus represents an independent, audited C++ translation unit paired with a strict ground-truth JSON manifest. Below is an explanation of what each field in a benchmark record signifies:

### Record Fields Explained

**1. Case Identifier (`id`)**
A unique, human-readable string identifying the specific algorithmic scenario (e.g., `binary-search-classic-iterative`, `g8_dsuRankMerge_0`). It remains stable across releases to enable long-term regression tracking.

**2. Target Symbol (`symbol`)**
The exact function name inside the companion `.cpp` file that the static analyzer evaluates. Symbols are isolated per translation unit so that standard names like `solve` or `query` can be tested under diverse topological configurations.

**3. Worst-Case Time Complexity (`time`)**
The asymptotic upper bound in standard Big-O notation (such as `O(1)`, `O(log n)`, `O(n)`, `O(n log n)`, `O(n^2)`, `O(n m)`, or `O(2^n)`). The algebraic engine simplifies and canonicalizes term representations, ensuring that equivalent formulations (e.g., `O(m log n + n log n)` and `O((n + m) log n)`) are compared consistently.

**4. Auxiliary Space Complexity (`space`)**
The extra memory allocated by the function on the stack or heap, excluding caller-owned parameters. Algorithms operating strictly in-place evaluate to `O(1)`, while containers instantiated locally (like `vector<int> dp(n)`) report their exact materialized memory scaling (e.g., `O(n)`).

**5. Confidence Rating (`confidence`)**
Indicates the level of mathematical certainty attached to the assertion:
- `exact`: The static analyzer has mathematically proved both the loop progress vectors and recurrence invariants directly from the Clang AST.
- `estimated`: The asymptotic order is verified, but certain dynamic runtime factors (such as external functor callbacks) use bounded heuristic bounds.
- `unknown`: The analyzer soundly abstains from asserting a bound when input ranges or pointer chasing cannot be proven terminating, preventing false claims.

**6. Input Symbols (`inputSymbols`)**
A list of formal parameters and sequence dimensions that establish the asymptotic scaling variables (such as `["n"]` for array length or `["n", "m"]` for graph vertices and edges).

**7. Mathematical Proof (`proof`)**
A structured sequence of human-readable justifications explaining step-by-step why the bound holds. These describe loop condition progress, geometric intervals, series summations, and container growth patterns.

**8. Origin & Licensing (`origin`)**
Metadata detailing the provenance of the code snippet (e.g., whether it was authored specifically for static analysis or derived from CC0 competitive programming archives) to guarantee clean licensing and traceability.

---

## Repository Structure & GitHub Truncation Fix

To resolve the GitHub 1,000-file per-directory truncation limit, the 26,710-case dataset is organized into logical, high-cohesion subdirectories where no single folder contains more than 730 files:

```
Time-Complexity-Calculator/
├── analyzer/                 # Core static complexity evaluation engine
│   ├── src/
│   │   ├── analyze-ast.ts    # Compositional CFG, loop-bound, and recurrence engine
│   │   ├── bound.ts          # Canonical Big-O algebraic simplifier & domination rules
│   │   ├── clang.ts          # Clang AST spawner & disk-backed cache (2,048 entries)
│   │   ├── cli.ts            # Standalone multi-platform CLI runner
│   │   └── prelude.ts        # Synthetic C++17 STL mock definitions for Clang AST
│   └── test/                 # 92 test suites covering 6,950 unit & integration tests
├── extension/                # VS Code / Kiro editor extension (By VoidHub)
│   ├── src/extension.ts      # CodeLens, status bar, and VoidHub.co integration
│   └── package.json          # Extension metadata and commands
├── datasets/                 # 26,710 reviewed C++ cases across 1,420 manifests
│   ├── gen2/                 # Generation 2 algorithmic expansion (36 files)
│   ├── gen3/                 # Generation 3 algorithmic expansion (28 files)
│   ├── gen4/                 # Generation 4 algorithmic expansion (40 files)
│   ├── gen5/                 # Generation 5 algorithmic expansion (48 files)
│   ├── gen6/                 # Generation 6 algorithmic expansion (136 files)
│   ├── gen7/                 # Generation 7 algorithmic expansion (144 files)
│   ├── gen8/                 # Generation 8 algorithmic expansion (256 files, 5,120 cases)
│   ├── level0/               # Core competitive programming packs (726 files)
│   └── packs/                # Domain-specific suites (p0_a, p0_b, requested, manual, recurrence)
├── tools/                    # Benchmarking, diagnosis, validation, and generator tools
└── .github/workflows/        # Automated multi-OS GitHub Actions CI/CD
```

---

## VS Code Extension by [VoidHub](https://voidhub.co)

The extension integrates directly into your editor workflow:

1. **CodeLens Trigger**: Displays a `⏱ Calculate Complexity` button directly above C++ function declarations.
2. **Keyboard Shortcut**: Press `Ctrl+Alt+C` (macOS: `Cmd+Alt+C`) on any highlighted function or statement block.
3. **Context Menu**: Right-click any C++ selection and choose **Calculate Time Complexity**.
4. **Status Bar Item**: Persistent `$(watch) Complexity (By VoidHub)` status bar widget that opens [VoidHub.co](https://voidhub.co) with a single click.
5. **Interactive Result Notifications**: Each analysis popup includes a direct link to explore more developer tools at [VoidHub.co](https://voidhub.co).

### Configuration Settings
| Setting | Default | Description |
|---|---|---|
| `projectX.enableCodeLens` | `true` | Show `⏱ Calculate Complexity` button above C++ functions |
| `projectX.minimumConfidence` | `80` | Minimum confidence percentage required before displaying a result |
| `projectX.clangPath` | `""` | Optional custom path to `clang++` executable |

---

## Installation & Requirements

### Prerequisites
1. **Node.js** $\ge 18.0.0$
2. **Clang / LLVM** $\ge 15.0.0$ (used locally to generate typed C++ AST)
   - **Windows**: `winget install LLVM.LLVM` (or install to `C:\Program Files\LLVM`)
   - **macOS**: `brew install llvm`
   - **Linux (Ubuntu/Debian)**: `sudo apt install clang`

### Setup
```bash
# Clone the repository
git clone https://github.com/adhamahmedyousef/Time-Complexity-Calculator.git
cd Time-Complexity-Calculator

# Install dependencies and build
npm install
npm run build

# Run full test suite (6,950 tests)
npm test
```

---

## Command Line Interface (CLI)

The analyzer can be run standalone as a CLI tool:

### 1. Human-Readable Output (`--human`)
```bash
cat << 'EOF' | node analyzer/dist/cli.js --human
int solve(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; j *= 2) {}
    }
    return 0;
}
EOF
```
**Output:**
```text
==================================================
Complexity Analysis Result:
==================================================
Worst-Case Time:   O(n log n)
Auxiliary Space:   O(1)
Confidence:        exact (99%)

Proof & Reasoning:
  • Dependent loop nesting multiplies outer O(n) by inner O(log n).
  • Auxiliary memory allocates no dynamic input-sized storage.
==================================================
```

### 2. Specific Function Symbol Analysis
```bash
node analyzer/dist/cli.js solution.cpp --symbol mergeSort --human
```

### 3. Machine-Readable JSON Output
```bash
node analyzer/dist/cli.js solution.cpp --json
```

---

## Running Benchmarks

```bash
# Run full benchmark across all 26,710 cases
npm run benchmark:dataset -- --summary

# Benchmark a specific family
npm run benchmark:dataset -- --prefix=gen8-

# Validate dataset manifest integrity
npm run validate:dataset
```

---

## License

This project is open-source software licensed under the [MIT License](LICENSE) - free for academic, commercial, and personal use. Developed and maintained by [VoidHub](https://voidhub.co).
