import assert from "node:assert/strict";
import test from "node:test";
import { existsSync, readFileSync } from "node:fs";
import { resolve } from "node:path";
import { analyseCppFunctionInDocument, analyseCppSelection } from "../src/index.js";
import { analyseFunctionAst } from "../src/analyze-ast.js";
import type { ClangNode } from "../src/model.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);
const ref = (name: string): ClangNode => ({ kind: "DeclRefExpr", referencedDecl: { name } });
const loop = (update: string, body: ClangNode[] = []): ClangNode => ({ kind: "ForStmt", inner: [
  { kind: "BinaryOperator", opcode: "<", inner: [ref("i"), ref("n")] },
  { kind: update === "++" ? "UnaryOperator" : "CompoundAssignOperator", opcode: update, inner: [ref("i")] },
  { kind: "CompoundStmt", inner: body }
] });
const fn = (body: ClangNode[]): ClangNode => ({ kind: "FunctionDecl", name: "f", inner: [{ kind: "ParmVarDecl", name: "n" }, { kind: "CompoundStmt", inner: body }] });

test("real Clang AST handles the geometric/dependent/independent triple nest", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void test14(int n) {
      for (int i = 1; i < n; i *= 2)
        for (int j = 0; j < i; ++j)
          for (int k = 0; k < n; ++k) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n^2)");
});

test("real Clang AST accepts vector in a complete selected function", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void vectorWork(int n) {
      vector<int> arr(n);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {}
  }`);
  assert.equal(result.worstCaseTime, "O(n^2)");
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("C++17 range algorithms compose with vector auxiliary storage", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void scan(int n) {
      vector<int> values(n);
      int total = accumulate(values.begin(), values.end(), 0);
      (void)total;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("ordered container member lookup composes as O(n log n)", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void mapLookup(int n) {
      map<int, int> frequency;
      for (int i = 0; i < n; ++i) {
        auto it = frequency.find(i);
        (void)it;
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
});

test("real Clang AST accepts a selected local constant declaration", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  assert.equal(analyseCppSelection("int m = 100;").worstCaseTime, "O(1)");
});

test("range-for derives linear work from a vector parameter", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long sumVectorRangeFor(const vector<int>& values) {
      long long total = 0;
      for (int value : values) total += value;
      return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("container size() is a symbolic linear loop limit, not constant work", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long sumSizeRecomputedEachIteration(const vector<int>& values) {
      long long total = 0;
      for (size_t i = 0; i < values.size(); ++i) total += values[i];
      return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("range-for with ordered-container insertion composes traversal and log lookup", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void uniqueValues(const vector<int>& values) {
      set<int> seen;
      for (int value : values) seen.insert(value);
    }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)", result.proof.join(" "));
});

test("structural binary search is proved from midpoint and shrinking updates", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int lowerBoundManual(const vector<int>& values, int target) {
      int lo = 0, hi = (int)values.size();
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (values[mid] < target) lo = mid + 1;
        else hi = mid;
      }
      return lo;
    }`);
  assert.equal(result.worstCaseTime, "O(log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("binary-search corpus parses as a complete translation unit with local std declarations", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const corpus = readFileSync(resolve(import.meta.dirname, "../../datasets/cpp-binary-search.cpp"), "utf8");
  const result = analyseCppFunctionInDocument(corpus, "binarySearchClassicIterative");
  assert.equal(result.worstCaseTime, "O(log n)", result.proof.join(" "));
});

test("range-for corpus parses despite unrelated templates in the same file", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const corpus = readFileSync(resolve(import.meta.dirname, "../../datasets/cpp-range-for-container-size.cpp"), "utf8");
  const result = analyseCppFunctionInDocument(corpus, "sumVectorRangeFor");
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("non-progressing binary-search-like update is not falsely proved", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int stuckSearch(const vector<int>& values, int target) {
      int lo = 0, hi = (int)values.size() - 1;
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (values[mid] < target) lo = mid;
        else hi = mid - 1;
      }
      return lo;
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("structural two pointers proves each if/else path converges", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    bool hasPair(const vector<int>& values, int target) {
      int left = 0, right = (int)values.size() - 1;
      while (left < right) {
        int sum = values[left] + values[right];
        if (sum == target) return true;
        else if (sum < target) ++left;
        else --right;
      }
      return false;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("two pointers with a non-progressing branch stays Unknown", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void mayStall(const vector<int>& values) {
      int left = 0, right = (int)values.size() - 1;
      while (left < right) {
        if (values[left] < values[right]) ++left;
      }
    }`);
  assert.equal(result.worstCaseTime, "Unknown", result.proof.join(" "));
});

test("real AST composes polynomial work with two independent logarithmic loops", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void polynomialLogSquared(int n) {
      for (int a = 0; a < n; ++a)
        for (int b = 0; b < n; ++b)
          for (int c = 1; c < n; c *= 2)
            for (int d = 1; d < n; d *= 2) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n^2 log^2 n)", result.proof.join(" "));
});

test("geometric outer index with dependent linear work uses a geometric-series bound", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void geometricDependent(int n) {
      for (int i = 1; i < n; i *= 2)
        for (int j = 0; j < i; ++j)
          for (int k = 0; k < n; ++k) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
});

test("divide and conquer recurrence with two half-size calls and linear work is n log n", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int divideAndConquerSum(int n) {
      if (n <= 1) return n;
      int left = divideAndConquerSum(n / 2);
      int right = divideAndConquerSum(n / 2);
      for (int i = 0; i < n; ++i) {}
      return left + right;
    }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(log n)");
});

test("divide and conquer recurrence with two half-size calls and constant work is linear", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    int binaryTreeCalls(int n) {
      if (n <= 1) return 1;
      return binaryTreeCalls(n / 2) + binaryTreeCalls(n / 2);
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(log n)");
});

test("branching unit-decrement recursion is classified as exponential", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    long long fibNaive(int n) {
      if (n <= 1) return n;
      return fibNaive(n - 1) + fibNaive(n - 2);
    }`);
  assert.equal(result.worstCaseTime, "O(1.618^n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("permutation-style recursive loop is classified as factorial", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void generatePermutations(vector<int>& values, int start) {
      if (start == (int)values.size()) return;
      for (int i = start; i < (int)values.size(); ++i) {
        swap(values[start], values[i]);
        generatePermutations(values, start + 1);
        swap(values[start], values[i]);
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n!)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("nested loops over distinct container inputs are n times m", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void printCombinations(vector<int>& a, vector<int>& b) {
      for (int i = 0; i < (int)a.size(); ++i)
        for (int j = 0; j < (int)b.size(); ++j) {}
    }`);
  assert.equal(result.worstCaseTime, "O(n m)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("three-phase traversal of two distinct inputs is n plus m", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    vector<int> mergeTwoSortedArrays(vector<int>& a, vector<int>& b) {
      vector<int> result;
      int i = 0, j = 0;
      while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
      }
      while (i < (int)a.size()) result.push_back(a[i++]);
      while (j < (int)b.size()) result.push_back(b[j++]);
      return result;
    }`);
  assert.equal(result.worstCaseTime, "O(n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n + m)");
  assert.equal(result.confidence, "estimated");
});

test("indexed balanced split-and-merge recursion is n log n", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void mergeParts(vector<int>& values, int left, int middle, int right) {}
    void splitAndMerge(vector<int>& values, int left, int right) {
      if (left >= right) return;
      int middle = (left + right) / 2;
      splitAndMerge(values, left, middle);
      splitAndMerge(values, middle + 1, right);
      mergeParts(values, left, middle, right);
    }`);
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("named corpus analysis accepts a complete multi-function translation unit", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const corpus = readFileSync(resolve(import.meta.dirname, "../../datasets/cpp-core.cpp"), "utf8");
  const result = analyseCppFunctionInDocument(corpus, "logMultiply");
  assert.equal(result.worstCaseTime, "O(log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("two-pointer corpus now proves container-size traversal structurally", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const corpus = readFileSync(resolve(import.meta.dirname, "../../datasets/cpp-core.cpp"), "utf8");
  const result = analyseCppFunctionInDocument(corpus, "twoPointers");
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.confidence, "exact");
});

test("real Clang AST composes max_element inside two linear loops", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    void maxInsideLoops(int n) {
      vector<int> arr(n);
      for (int j = 0; j < n; ++j)
        for (int i = 0; i < n; ++i) {
          int y = *max_element(arr.begin(), arr.end());
          (void)y;
        }
    }`);
  assert.equal(result.worstCaseTime, "O(n^3)", result.proof.join(" "));
});

test("real Clang AST composes a same-file local function call", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = "#include <bits/stdc++.h>\nusing namespace std;\nconst int N = 100000; int arr[N];\n"
    + "int mx(int n) { int x = arr[0]; for (int i = 1; i < n; ++i) x = max(x, arr[i]); return x; }\n"
    + "void t(int n) { for (int j = 0; j < n; ++j) for (int i = 0; i < n; ++i) { int y = mx(n); (void)y; } }";
  const result = analyseCppSelection(source);
  assert.equal(result.worstCaseTime, "O(n^3)", result.proof.join(" "));
});

test("selected caller is analyzed against local helpers from the complete document", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const document = "int mx(int n) { int answer = 0; for (int i = 0; i < n; ++i) ++answer; return answer; }\n"
    + "void t(int n) { for (int i = 0; i < n; ++i) { int x = mx(n); (void)x; } }";
  const result = analyseCppSelection("void t(int n) { for (int i = 0; i < n; ++i) { int x = mx(n); (void)x; } }", document);
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
});

test("same-file helper resolution uses DFS rather than declaration order", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = "int mx(int);\n"
    + "void t(int n) { for (int i = 0; i < n; ++i) { int x = mx(n); (void)x; } }\n"
    + "int mx(int n) { for (int j = 0; j < n; ++j) {} return 1; }";
  const result = analyseCppSelection("void t(int n) { for (int i = 0; i < n; ++i) { int x = mx(n); (void)x; } }", source);
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
});

test("a selected self-contained block can call helpers from the full document", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const selection = "for (int i = 0; i < n; ++i) { int x = mx(n); (void)x; }";
  const document = "int mx(int n) { for (int j = 0; j < n; ++j) {} return 1; }\n"
    + "void t(int n) { " + selection + " }";
  const result = analyseCppSelection(selection, document);
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
});

test("real Clang AST derives an n times n loop bound", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection("void nSquared(int n) { for (int i = 0; i < n * n; ++i) {} }");
  assert.equal(result.worstCaseTime, "O(n^2)", result.proof.join(" "));
});

test("real Clang AST composes three loops, a logarithmic loop, and a DFS-resolved helper", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = "int mx(int n) { for (int i = 0; i < n; ++i) {} return 1; }\n"
    + "void t(int n) { for (int j = 0; j < n; ++j) for (int i = 0; i < n; ++i) for (int k = 1; k < n; k *= 2) { int x = mx(n); (void)x; } }";
  const result = analyseCppSelection(source);
  assert.equal(result.worstCaseTime, "O(n^3 log n)", result.proof.join(" "));
});

test("canonical Eratosthenes sieve is recognized structurally", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    const int N = 100000;
    int main() {
      vector<bool> prime(N, true);
      prime[0] = prime[1] = false;
      for (int i = 2; i * i <= N; ++i) {
        if (prime[i]) {
          for (int j = i * i; j <= N; j += i) {
            prime[j] = false;
          }
        }
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n log log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("Sieve composes a DFS-resolved linear helper called for every marking", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    const int N = 100000;
    int mx(int n) { for (int i = 0; i < n; ++i) {} return 1; }
    void t(int n) {
      vector<bool> arr(N, true);
      arr[0] = arr[1] = false;
      for (int i = 2; i * i <= N; ++i) {
        if (arr[i]) {
          for (int j = i * i; j <= N; j += i) {
            arr[j] = false;
            int x = mx(n);
            (void)x;
          }
        }
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n^2 log log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("Sieve multiplies nested loop work and a DFS-resolved helper for every marking", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    const int N = 100000;
    int mx(int n) { for (int i = 0; i < n; ++i) {} return 1; }
    void t(int n) {
      vector<bool> arr(N, true);
      arr[0] = arr[1] = false;
      for (int i = 2; i * i <= N; ++i) {
        if (arr[i]) {
          for (int j = i * i; j <= N; j += i) {
            arr[j] = false;
            for (int l = 0; l < n; ++l) {
              int x = mx(n);
              (void)x;
            }
          }
        }
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n^3 log log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("smallest-prime-factor sieve is recognized with a raw preallocated table", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    const int N = 100000;
    int arr[N + 1];
    void Build(int n) {
      for (int i = 1; i <= n; ++i) arr[i] = i;
      for (int i = 2; i * i <= n; ++i) {
        if (arr[i] == i) {
          for (int j = i * i; j <= n; j += i) {
            if (arr[j] == j) arr[j] = i;
          }
        }
      }
    }`);
  assert.equal(result.worstCaseTime, "O(n log log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("unknown external calls name the unresolved callee", () => {
  const result = analyseFunctionAst(fn([loop("++", [{ kind: "CallExpr", inner: [ref("notAvailableHere")] }])]));
  assert.match(result.proof[0], /notAvailableHere/);
});
