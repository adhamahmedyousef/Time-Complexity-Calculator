import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const clangAvailable = existsSync(clangPath);

const segmentTreeSource = `
  struct SegTree {
      int n;
      vector<int> t;
      SegTree(const vector<int>& a) : n((int)a.size()), t(4 * max(1, (int)a.size()), INT_MAX) { build(1, 0, n - 1, a); }
      void build(int p, int l, int r, const vector<int>& a) {
          if (l == r) { t[p] = a[l]; return; }
          int m = (l + r) / 2;
          build(p << 1, l, m, a);
          build(p << 1 | 1, m + 1, r, a);
          t[p] = min(t[p << 1], t[p << 1 | 1]);
      }
      int query(int p, int l, int r, int ql, int qr) const {
          if (qr < l || r < ql) return INT_MAX;
          if (ql <= l && r <= qr) return t[p];
          int m = (l + r) / 2;
          return min(query(p << 1, l, m, ql, qr), query(p << 1 | 1, m + 1, r, ql, qr));
      }
  };
  long long rangeMinSum(const vector<int>& a, const vector<pair<int,int>>& queries) {
      SegTree st(a);
      long long total = 0;
      for (auto [l, r] : queries) total += st.query(1, 0, (int)a.size() - 1, l, r);
      return total;
  }`;

test("recursive interval build composes as preprocessing over container queries", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(segmentTreeSource);
  assert.equal(result.worstCaseTime, "O((n + q) log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "estimated");
});

test("a span the build cannot tie to the container stays at the plain scan bound", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  // leafCount is a constant member: the build depth cannot be charged to a.size().
  const result = analyseCppSelection(`
    struct Fixed {
        int root;
        int leafCount;
        vector<int> t;
        Fixed(const vector<int>& a) : root(1), leafCount(8), t((int)a.size()) { build(root, 0, leafCount - 1, a); }
        void build(int p, int l, int r, const vector<int>& a) {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            build(p << 1, l, m, a);
            build(p << 1 | 1, m + 1, r, a);
            t[p] = min(t[p << 1], t[p << 1 | 1]);
        }
    };
    long long useFixed(const vector<int>& a) {
        Fixed f(a);
        long long total = 0;
        for (int x : a) total += x;
        return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  // Only the storage-bearing record remains.
  assert.equal(result.auxiliarySpace, "O(n)");
});

test("a literal-span build over a fixed table is not container-scaled preprocessing", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct Fixed {
        int n;
        vector<int> t;
        Fixed(const vector<int>& a) : n(100), t(10) { build(1, 0, 99, a); }
        void build(int p, int l, int r, const vector<int>& a) {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            build(p << 1, l, m, a);
            build(p << 1 | 1, m + 1, r, a);
            t[p] = min(t[p << 1], t[p << 1 | 1]);
        }
    };
    long long useFixed(const vector<int>& a) {
        Fixed f(a);
        long long total = 0;
        for (int x : a) total += x;
        return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(1)");
});

test("loop-driven balance passes are not recognized as loop-free interval recursion", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct LoopBuild {
        int n;
        vector<int> t;
        LoopBuild(const vector<int>& a) : n((int)a.size()), t(4 * (int)a.size()) { build(1, 0, n - 1, a); }
        void build(int p, int l, int r, const vector<int>& a) {
            while (l < r) { int m = (l + r) / 2; build(p << 1, l, m, a); l = m + 1; }
        }
    };
    long long useLoopBuild(const vector<int>& a) {
        LoopBuild lb(a);
        long long total = 0;
        for (int x : a) total += x;
        return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
  assert.notEqual(result.confidence, "unknown");
});

test("a constructor invoking two record methods is not a single interval build", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct S {
        int n;
        vector<int> t;
        S(const vector<int>& a) : n((int)a.size()), t(4 * (int)a.size()) { build(1, 0, n - 1, a); clear(); }
        void build(int p, int l, int r) {
            if (l == r) { t[p] = 0; return; }
            int m = (l + r) / 2;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
        }
        void clear() { t.clear(); }
    };
    long long useS(const vector<int>& a) {
        S s(a);
        long long total = 0;
        for (int x : a) total += x;
        return total;
    }`);
  assert.equal(result.worstCaseTime, "O(n)", result.proof.join(" "));
});

test("midpoint derived as l + (r - l) / 2 is the same interval recursion", { skip: !clangAvailable }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const result = analyseCppSelection(`
    struct SegTree {
        int n;
        vector<int> t;
        SegTree(const vector<int>& a) : n((int)a.size()), t(4 * (int)a.size()) { build(1, 0, n - 1, a); }
        void build(int p, int l, int r, const vector<int>& a) {
            if (l == r) { t[p] = a[l]; return; }
            int m = l + (r - l) / 2;
            build(p << 1, l, m, a);
            build(p << 1 | 1, m + 1, r, a);
            t[p] = min(t[p << 1], t[p << 1 | 1]);
        }
    };
    long long buildCostOnly(const vector<int>& a) {
        SegTree st(a);
        long long total = 0;
        for (int x : a) total += x;
        return total;
    }`);
  // Construction adds the proven O(n log n) preprocessing to the linear scan.
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n)");
});
