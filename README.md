# Time Complexity Calculator

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Tests](https://img.shields.io/badge/Tests-6%2C949%20passed-brightgreen.svg)]()
[![Corpus](https://img.shields.io/badge/Corpus-21%2C584%20reviewed%20cases-blue.svg)]()
[![Precision](https://img.shields.io/badge/Precision-97.5%25-success.svg)]()
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)]()

An offline, first-principles static analysis engine and VS Code / Kiro extension that calculates the **worst-case time complexity**, **auxiliary space complexity**, and generates **human-readable proofs** for C++ functions and algorithms.

---

## Key Features

- **Mathematical Proofs Over Guesses**: Proves Big-O bounds structurally from Clang AST semantics, loop progress vectors, and recurrence relations. If a bound cannot be proven soundly, it safely abstains (`Unknown`) rather than providing a false confident answer.
- **Master Theorem Divide-and-Conquer Engine**: Solves balanced binary recurrences ($2T(n/2) + \mathcal{O}(n)$) and merge traversals, proving exact $\mathcal{O}(n \log n)$ time and $\mathcal{O}(n)$ auxiliary space.
- **Amortized Two Pointers & Sliding Windows**: Identifies monotonic variable progression bounded by outer sequence dimensions, proving exact $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space for variable sliding windows.
- **Multi-Dimensional Dynamic Programming**: Recognizes state transitions across linear, grid/matrix ($\mathcal{O}(n \cdot m)$), cubic matrix multiplication ($\mathcal{O}(n^3)$), and memoized recursion caches.
- **Auxiliary Memory Scale Estimator**: Calculates expected memory requirements at symbolic scales ($1\text{K}, 10\text{K}, 100\text{K}, 1\text{M}$ input units) based on visible Clang type widths.
- **100% Offline & Private**: Runs entirely locally using Clang JSON AST and on-disk caching. No code is ever uploaded to external servers.

---

## Empirical Benchmark (21,584 Reviewed Cases)

The engine is continuously verified against an audited corpus of **21,584 competitive programming and algorithmic cases** across **1,290 manifests**:

| Metric | Score | Note |
|:---|:---:|:---|
| **Reviewed Cases** | **21,584** | 1,290 audited manifests across 14 algorithm families |
| **Exact Manifest Matches** | **20,303** | Exact time, space, and confidence match |
| **Time/Space Profile Accuracy** | **95.8%** | 20,686 / 21,584 cases |
| **Asserted-Result Precision** | **97.5%** | 19,214 correct / 19,699 asserted results |
| **Coverage (Non-Abstaining)** | **92.6%** | 19,988 / 21,584 cases |
| **Unit Test Suite** | **6,949 / 6,949** | 100% passing across 92 test suites |

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

# Run full test suite (6,949 tests)
npm test
```

---

## VS Code Extension

The extension integrates directly into your editor workflow:

1. **CodeLens Button**: Automatically displays a `⏱ Calculate Complexity` button above C++ function declarations.
2. **Keyboard Shortcut**: Press `Ctrl+Alt+C` (macOS: `Cmd+Alt+C`) on any selected function or statement block.
3. **Context Menu**: Right-click any C++ selection and select **Calculate Time Complexity**.

### Configuration Settings
| Setting | Default | Description |
|---|---|---|
| `projectX.enableCodeLens` | `true` | Show `⏱ Calculate Complexity` button above C++ functions |
| `projectX.minimumConfidence` | `80` | Minimum confidence percentage required before displaying a result |
| `projectX.clangPath` | `""` | Optional custom path to `clang++` executable |

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
# Run full benchmark across all 21,584 cases
npm run benchmark:dataset -- --summary

# Benchmark a specific family
npm run benchmark:dataset -- --prefix=gen7-

# Validate dataset manifest integrity
npm run validate:dataset
```

---

## Architecture

```
Time-Complexity-Calculator/
├── analyzer/                 # Core static complexity evaluation engine
│   ├── src/
│   │   ├── analyze-ast.ts    # Compositional CFG, loop-bound, and recurrence engine
│   │   ├── bound.ts          # Canonical Big-O algebraic simplifier & domination rules
│   │   ├── clang.ts          # Clang AST spawner & disk-backed cache (2,048 entries)
│   │   ├── cli.ts            # Standalone multi-platform CLI runner
│   │   └── prelude.ts        # Synthetic C++17 STL mock definitions for Clang AST
│   └── test/                 # 92 test suites covering 6,949 unit & integration tests
├── extension/                # VS Code / Kiro editor extension
│   └── src/extension.ts      # CodeLens, notifications, and bundled CLI invocation
├── datasets/                 # 1,290 audited C++ manifests and test cases (Gen1–Gen7)
├── tools/                    # Benchmarking, diagnosis, and dataset generation scripts
└── .github/workflows/        # Automated multi-OS GitHub Actions CI/CD
```

---

## License

This project is licensed under the [MIT License](LICENSE) — free for academic, commercial, and personal use.
