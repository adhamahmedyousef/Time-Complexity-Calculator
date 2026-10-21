import assert from "node:assert/strict";
import { existsSync } from "node:fs";
import test from "node:test";
import { analyseCppSelection } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";

// ============================================================================
// Round 10 Engine Capabilities & Algorithmic Unit Tests
// Tests every major algorithmic recognizer, CFG propagation, and proof invariant.
// ============================================================================

test("Matrix DP: 2D table with sequential query loop composes O(n m + q)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int gridQueries(int n, int m, int q) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        dp[i][j] = i + j;
    int ans = 0;
    while (q--) {
      ans += dp[0][0];
    }
    return ans;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n m + q)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n m)");
  assert.equal(res.confidence, "exact");
});

test("Matrix DP: 3-level cubic matrix multiplication proves O(n^3)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  vector<vector<int>> matMul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          c[i][j] += a[i][k] * b[k][j];
    return c;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n^3)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n^2)");
  assert.equal(res.confidence, "exact");
});

test("Number Theory: Euler totient with factor reduction proves O(sqrt n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  int eulerPhi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        while (n % i == 0) n /= i;
        result -= result / i;
      }
    }
    if (n > 1) result -= result / n;
    return result;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(sqrt n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Number Theory: trial division prime test is exact O(sqrt n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(sqrt n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Number Theory: Sieve of Eratosthenes is O(n log log n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int sieve(int n) {
    if (n < 2) return 0;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; ++p)
      if (isPrime[p])
        for (int i = p * p; i <= n; i += p)
          isPrime[i] = false;
    int c = 0;
    for (int i = 2; i <= n; ++i) if (isPrime[i]) ++c;
    return c;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n log log n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n)");
  assert.equal(res.confidence, "exact");
});

test("Two Pointers: Container with most water proves O(n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int maxArea(const vector<int>& h) {
    int lo = 0, hi = (int)h.size() - 1, best = 0;
    while (lo < hi) {
      int w = hi - lo;
      if (h[lo] < h[hi]) {
        int cur = h[lo] * w;
        if (cur > best) best = cur;
        ++lo;
      } else {
        int cur = h[hi] * w;
        if (cur > best) best = cur;
        --hi;
      }
    }
    return best;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Two Pointers: Trapping rain water proves O(n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int trap(const vector<int>& h) {
    int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0;
    while (lo <= hi) {
      if (h[lo] <= h[hi]) {
        if (h[lo] >= lmax) lmax = h[lo];
        else total += lmax - h[lo];
        ++lo;
      } else {
        if (h[hi] >= rmax) rmax = h[hi];
        else total += rmax - h[hi];
        --hi;
      }
    }
    return total;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Two Pointers: In-place sorted array duplicate removal is O(n)", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int removeDuplicates(vector<int>& a) {
    if (a.empty()) return 0;
    int slow = 0;
    for (size_t fast = 1; fast < a.size(); ++fast) {
      if (a[fast] != a[slow]) a[++slow] = a[fast];
    }
    return slow + 1;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Monotonic Stack: Next Greater Element is O(n) estimated", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  vector<int> nge(const vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && a[st.back()] < a[i]) {
        res[st.back()] = a[i];
        st.pop_back();
      }
      st.push_back(i);
    }
    return res;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n)");
  assert.equal(res.confidence, "estimated");
});

test("Monotonic Stack: Daily Temperatures span is O(n) estimated", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  vector<int> dailyTemps(const vector<int>& t) {
    int n = t.size();
    vector<int> ans(n, 0);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && t[i] > t[st.back()]) {
        int idx = st.back();
        st.pop_back();
        ans[idx] = i - idx;
      }
      st.push_back(i);
    }
    return ans;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n)");
  assert.equal(res.confidence, "estimated");
});

test("Graphs: BFS reachable component count proves O(V + E) estimated", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <queue>
  using namespace std;
  int bfsReachable(const vector<vector<int>>& adj, int s) {
    int V = adj.size(), count = 0;
    vector<bool> seen(V, false);
    queue<int> q;
    seen[s] = true;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      ++count;
      for (int nxt : adj[u]) {
        if (!seen[nxt]) {
          seen[nxt] = true;
          q.push(nxt);
        }
      }
    }
    return count;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(V + E)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(V)");
  assert.equal(res.confidence, "estimated");
});

test("Graphs: Kahn topological sort proves O(V + E) estimated", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <queue>
  using namespace std;
  vector<int> topoSort(const vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> inDeg(V, 0);
    for (int u = 0; u < V; ++u)
      for (int v : adj[u])
        ++inDeg[v];
    queue<int> q;
    for (int i = 0; i < V; ++i)
      if (inDeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      order.push_back(u);
      for (int v : adj[u]) {
        if (--inDeg[v] == 0) q.push(v);
      }
    }
    return order;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(V + E)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(V)");
  assert.equal(res.confidence, "estimated");
});

test("Graphs: Floyd-Warshall all-pairs shortest paths proves O(n^3) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <algorithm>
  using namespace std;
  void floydWarshall(vector<vector<int>>& d) {
    int n = d.size();
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n^3)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Binary Search: standard lower bound proves O(log n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int lowerBound(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (a[mid] >= target) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(log n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Binary Search: integer square root binary search is O(log n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  long long intSqrt(long long n) {
    if (n < 2) return n;
    long long lo = 1, hi = n, ans = 1;
    while (lo <= hi) {
      long long mid = lo + (hi - lo) / 2;
      if (mid <= n / mid) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return ans;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(log n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("DP: 0/1 Knapsack with capacity W proves O(n W) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <algorithm>
  using namespace std;
  int knapsack(const vector<int>& wt, const vector<int>& val, int W) {
    vector<int> dp(W + 1, 0);
    for (size_t i = 0; i < wt.size(); ++i) {
      for (int w = W; w >= wt[i]; --w) {
        dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
      }
    }
    return dp[W];
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n W)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(W)");
  assert.equal(res.confidence, "exact");
});

test("DP: Kadane's maximum subarray sum proves O(n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <algorithm>
  using namespace std;
  int kadane(const vector<int>& a) {
    int best = a[0], cur = a[0];
    for (size_t i = 1; i < a.size(); ++i) {
      cur = max(a[i], cur + a[i]);
      best = max(best, cur);
    }
    return best;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("DP: Longest Increasing Subsequence quadratic proves O(n^2) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <algorithm>
  using namespace std;
  int lis(const vector<int>& a) {
    int n = a.size(), mx = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[i] > mx) mx = dp[i];
    }
    return mx;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n^2)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n)");
  assert.equal(res.confidence, "exact");
});

test("Range: Difference array with queries proves O(n + q) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  vector<long long> diffQueries(int n, int q) {
    vector<long long> diff(n + 2, 0);
    for (int i = 0; i < q; ++i) {
      diff[1] += 5;
      diff[n + 1] -= 5;
    }
    for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1];
    return diff;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n + q)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n)");
  assert.equal(res.confidence, "exact");
});

test("Adversarial: Collatz sequence soundly abstains as Unknown", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  int collatz(long long x) {
    int count = 0;
    while (x > 1) {
      if (x % 2 == 0) x /= 2;
      else x = 3 * x + 1;
      ++count;
    }
    return count;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "Unknown", res.proof.join(" "));
  assert.equal(res.confidence, "unknown");
});

test("Adversarial: Opaque modulo step while loop soundly abstains as Unknown", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  long long opaqueModuloStep(long long x) {
    while (x > 0) {
      if (x % 7 == 0) x /= 7;
      else x -= 4;
    }
    return x;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "Unknown", res.proof.join(" "));
  assert.equal(res.confidence, "unknown");
});

test("Math: Modular fast exponentiation is O(log n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
      if (exp & 1) res = (res * base) % mod;
      base = (base * base) % mod;
      exp >>= 1;
    }
    return res;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(log n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Matrix: Matrix-Vector multiplication is O(n m) exact with O(n) space", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  vector<int> matVec(const vector<vector<int>>& a, const vector<int>& x) {
    int n = a.size(), m = a[0].size();
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        res[i] += a[i][j] * x[j];
    return res;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n m)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n)");
  assert.equal(res.confidence, "exact");
});

test("Range: Prefix XOR with post-queries is O(n + q) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <algorithm>
  using namespace std;
  int xorQueries(const vector<int>& a, int q) {
    int n = a.size();
    vector<int> px(n + 1, 0);
    for (int i = 0; i < n; ++i) px[i + 1] = px[i] ^ a[i];
    int total = 0;
    for (int i = 0; i < q; ++i) {
      int l = i % n, r = (i + 1) % n;
      if (l > r) swap(l, r);
      total ^= px[r + 1] ^ px[l];
    }
    return total;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n + q)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(n)");
  assert.equal(res.confidence, "exact");
});

test("Fenwick: BIT point update is O(log n) estimated", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  void bitUpdate(vector<int>& bit, int idx, int val) {
    int n = bit.size();
    for (; idx < n; idx += idx & -idx) bit[idx] += val;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(log n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "estimated");
});

test("Fenwick: BIT prefix sum query is O(log n) estimated", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int bitQuery(const vector<int>& bit, int idx) {
    int s = 0;
    for (; idx > 0; idx -= idx & -idx) s += bit[idx];
    return s;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(log n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "estimated");
});

test("Sort: Counting sort frequency array is O(n) time, O(k) space", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  vector<int> countSort(const vector<int>& a, int k) {
    vector<int> cnt(k + 1, 0);
    for (int x : a) ++cnt[x];
    return cnt;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(k)");
  assert.equal(res.confidence, "exact");
});

test("Sort: Selection sort minimum swap is O(n^2) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  #include <algorithm>
  using namespace std;
  void selSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
      int mn = i;
      for (int j = i + 1; j < n; ++j) if (a[j] < a[mn]) mn = j;
      swap(a[i], a[mn]);
    }
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n^2)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Sort: Insertion sort is O(n^2) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  void insSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
      int key = a[i];
      int j = i - 1;
      while (j >= 0 && a[j] > key) {
        a[j + 1] = a[j];
        --j;
      }
      a[j + 1] = key;
    }
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n^2)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Bits: Single number XOR reduction is O(n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <vector>
  using namespace std;
  int singleXor(const vector<int>& a) {
    int x = 0;
    for (int v : a) x ^= v;
    return x;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Bits: Reverse bits of 32-bit integer is O(1) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  unsigned int revBits(unsigned int x) {
    unsigned int r = 0;
    for (int i = 0; i < 32; ++i) {
      r = (r << 1) | (x & 1);
      x >>= 1;
    }
    return r;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(1)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Bits: Subset mask iteration is O(2^n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  long long subsetMasks(int n) {
    long long s = 0;
    for (int mask = 0; mask < (1 << n); ++mask) s += mask;
    return s;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(2^n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});

test("Strings: Polynomial rolling hash is O(n) exact", { skip: !existsSync(clangPath) }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const code = `
  #include <string>
  using namespace std;
  long long polyHash(const string& s) {
    long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1;
    for (char c : s) {
      hash = (hash + (c - 'a' + 1) * p_pow) % mod;
      p_pow = (p_pow * p) % mod;
    }
    return hash;
  }
  `;
  const res = analyseCppSelection(code);
  assert.equal(res.worstCaseTime, "O(n)", res.proof.join(" "));
  assert.equal(res.auxiliarySpace, "O(1)");
  assert.equal(res.confidence, "exact");
});
