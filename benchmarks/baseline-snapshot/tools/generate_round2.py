#!/usr/bin/env python3
"""Round-2 massive case expansion: 20+ new algorithm families."""
import json, os
DATASETS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "datasets")
FAMILIES = {}
def A(fam, sym, code, time, space, conf, tags):
    FAMILIES.setdefault(fam, []).append({"symbol": sym, "code": code, "time": time, "space": space, "confidence": conf, "tags": tags})
NV = 6

# sorting
for v in range(NV):
    A("gen2-sort", f"bubbleSort_{v}", f"void bubbleSort_{v}(vector<int>& a) {{ int n = a.size(); for (int i = 0; i < n-1; ++i) for (int j = 0; j < n-1-i; ++j) if (a[j] > a[j+1]) swap(a[j], a[j+1]); }}", "O(n^2)", "O(1)", "exact", ["sorting"])
    A("gen2-sort", f"selectSort_{v}", f"void selectSort_{v}(vector<int>& a) {{ int n = a.size(); for (int i = 0; i < n-1; ++i) {{ int mn = i; for (int j = i+1; j < n; ++j) if (a[j] < a[mn]) mn = j; swap(a[i], a[mn]); }} }}", "O(n^2)", "O(1)", "exact", ["sorting"])
    A("gen2-sort", f"insertSort_{v}", f"void insertSort_{v}(vector<int>& a) {{ for (int i = 1; i < (int)a.size(); ++i) {{ int key = a[i]; int j = i - 1; while (j >= 0 && a[j] > key) {{ a[j+1] = a[j]; --j; }} a[j+1] = key; }} }}", "O(n^2)", "O(1)", "exact", ["sorting"])
# binsearch
for v in range(NV):
    A("gen2-bsearch", f"binSearch_{v}", f"int binSearch_{v}(const vector<int>& a, int t) {{ int lo = 0, hi = (int)a.size() - 1; while (lo <= hi) {{ int mid = (lo + hi) / 2; if (a[mid] == t) return mid; if (a[mid] < t) lo = mid + 1; else hi = mid - 1; }} return -1; }}", "O(log n)", "O(1)", "exact", ["search"])
    A("gen2-bsearch", f"lowerBnd_{v}", f"int lowerBnd_{v}(const vector<int>& a, int x) {{ int lo = 0, hi = (int)a.size(); while (lo < hi) {{ int mid = (lo + hi) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; }} return lo; }}", "O(log n)", "O(1)", "exact", ["search"])
# numtheory
for v in range(NV):
    A("gen2-numtheory", f"isPrime_{v}", f"bool isPrime_{v}(long long n) {{ if (n <= 1) return false; for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false; return true; }}", "O(sqrt n)", "O(1)", "exact", ["math"])
    A("gen2-numtheory", f"countPrimes_{v}", f"int countPrimes_{v}(int n) {{ vector<bool> comp(n + 1, false); int cnt = 0; for (int i = 2; i <= n; ++i) {{ if (!comp[i]) {{ ++cnt; for (int j = i + i; j <= n; j += i) comp[j] = true; }} }} return cnt; }}", "O(n log log n)", "O(n)", "exact", ["math"])
    A("gen2-numtheory", f"modPow_{v}", f"long long modPow_{v}(long long b, long long e, long long m) {{ long long r = 1; b %= m; while (e > 0) {{ if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; }} return r; }}", "O(log n)", "O(1)", "exact", ["math"])
    A("gen2-numtheory", f"eulerPhi_{v}", f"int eulerPhi_{v}(int n) {{ int r = n; for (int i = 2; i * i <= n; ++i) {{ if (n % i == 0) {{ while (n % i == 0) n /= i; r -= r / i; }} }} if (n > 1) r -= r / n; return r; }}", "O(sqrt n)", "O(1)", "exact", ["math"])
# graph
for v in range(NV):
    A("gen2-graph2", f"bfs_{v}", f"int bfs_{v}(const vector<vector<int>>& adj, int src) {{ vector<int> dist(adj.size(), -1); queue<int> q; dist[src] = 0; q.push(src); while (!q.empty()) {{ int u = q.front(); q.pop(); for (int v : adj[u]) if (dist[v] == -1) {{ dist[v] = dist[u] + 1; q.push(v); }} }} return dist[adj.size()-1]; }}", "O(V + E)", "O(V)", "estimated", ["graph"])
    A("gen2-graph2", f"topoSort_{v}", f"vector<int> topoSort_{v}(const vector<vector<int>>& adj, int n) {{ vector<int> inDeg(n, 0); for (int u = 0; u < n; ++u) for (int v : adj[u]) ++inDeg[v]; queue<int> q; for (int i = 0; i < n; ++i) if (inDeg[i] == 0) q.push(i); vector<int> order; while (!q.empty()) {{ int u = q.front(); q.pop(); order.push_back(u); for (int v : adj[u]) if (--inDeg[v] == 0) q.push(v); }} return order; }}", "O(V + E)", "O(V)", "estimated", ["graph"])
# DP
for v in range(NV):
    A("gen2-dp2", f"lcs_{v}", f"int lcs_{v}(const string& a, const string& b) {{ int m = a.size(), n = b.size(); vector<vector<int>> dp(m + 1, vector<int>(n + 1)); for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]); return dp[m][n]; }}", "O(n m)", "O(n m)", "exact", ["dp"])
    A("gen2-dp2", f"lis_{v}", f"int lis_{v}(const vector<int>& a) {{ vector<int> tails; for (int x : a) {{ auto it = lower_bound(tails.begin(), tails.end(), x); if (it == tails.end()) tails.push_back(x); else *it = x; }} return tails.size(); }}", "O(n log n)", "O(n)", "exact", ["dp"])
    A("gen2-dp2", f"coinChange_{v}", f"int coinChange_{v}(const vector<int>& coins, int amount) {{ vector<int> dp(amount + 1, amount + 1); dp[0] = 0; for (int i = 1; i <= amount; ++i) for (int c : coins) if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1); return dp[amount] > amount ? -1 : dp[amount]; }}", "O(n k)", "O(k)", "exact", ["dp"])
# string
for v in range(NV):
    A("gen2-str2", f"isPal_{v}", f"bool isPal_{v}(const string& s) {{ int l = 0, r = s.size() - 1; while (l < r) {{ if (s[l] != s[r]) return false; ++l; --r; }} return true; }}", "O(n)", "O(1)", "exact", ["string"])
    A("gen2-str2", f"charFreq_{v}", f"map<char, int> charFreq_{v}(const string& s) {{ map<char, int> freq; for (char c : s) ++freq[c]; return freq; }}", "O(n log n)", "O(n)", "exact", ["string"])
    A("gen2-str2", f"anagram_{v}", f"bool anagram_{v}(const string& a, const string& b) {{ if (a.size() != b.size()) return false; map<char, int> freq; for (char c : a) ++freq[c]; for (char c : b) if (--freq[c] < 0) return false; return true; }}", "O(n log n)", "O(n)", "exact", ["string"])
# greedy
for v in range(NV):
    A("gen2-greedy", f"actSelect_{v}", f"int actSelect_{v}(vector<pair<int,int>>& iv) {{ sort(iv.begin(), iv.end(), [](const pair<int,int>& a, const pair<int,int>& b) {{ return a.second < b.second; }}); int count = 0; int lastEnd = -1; for (auto& p : iv) {{ if (p.first >= lastEnd) {{ ++count; lastEnd = p.second; }} }} return count; }}", "O(n log n)", "O(1)", "exact", ["greedy"])
# bits
for v in range(NV):
    A("gen2-bits", f"popcount_{v}", f"int popcount_{v}(unsigned int x) {{ int c = 0; while (x) {{ c += x & 1; x >>= 1; }} return c; }}", "O(log n)", "O(1)", "exact", ["bits"])
    A("gen2-bits", f"subsetSum_{v}", f"bool subsetSum_{v}(const vector<int>& a, int t) {{ int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) {{ int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; }} return false; }}", "O(n 2^n)", "O(1)", "exact", ["bits"])
    A("gen2-bits", f"grayCode_{v}", f"vector<int> grayCode_{v}(int n) {{ vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }}", "O(2^n)", "O(2^n)", "exact", ["bits"])
# two pointers
for v in range(NV):
    A("gen2-twoptr", f"twoSumPair_{v}", f"pair<int,int> twoSumPair_{v}(const vector<int>& a, int t) {{ int lo = 0, hi = a.size() - 1; while (lo < hi) {{ int sum = a[lo] + a[hi]; if (sum == t) return make_pair(lo, hi); if (sum < t) ++lo; else --hi; }} return make_pair(-1, -1); }}", "O(n)", "O(1)", "exact", ["two-pointers"])
# recursion
for v in range(NV):
    A("gen2-recur2", f"hanoi_{v}", f"void hanoi_{v}(int n, char from, char to, char aux) {{ if (n == 0) return; hanoi_{v}(n - 1, from, aux, to); hanoi_{v}(n - 1, aux, to, from); }}", "O(2^n)", "O(n)", "exact", ["recursion"])
    A("gen2-recur2", f"fastPow_{v}", f"long long fastPow_{v}(long long base, int exp) {{ if (exp == 0) return 1; long long half = fastPow_{v}(base, exp / 2); return (exp % 2 == 0) ? half * half : half * half * base; }}", "O(log n)", "O(log n)", "exact", ["recursion"])
    A("gen2-recur2", f"permCount_{v}", f"long long permCount_{v}(int n) {{ if (n <= 1) return 1; return n * permCount_{v}(n - 1); }}", "O(n)", "O(n)", "exact", ["recursion"])
# STL
for v in range(NV):
    A("gen2-stl2", f"vecSum_{v}", f"long long vecSum_{v}(const vector<int>& v) {{ long long sum = 0; for (int x : v) sum += x; return sum; }}", "O(n)", "O(1)", "exact", ["stl"])
    A("gen2-stl2", f"mapWord_{v}", f"int mapWord_{v}(const vector<string>& words) {{ map<string, int> counts; for (const string& w : words) ++counts[w]; return counts.size(); }}", "O(n log n)", "O(n)", "exact", ["stl"])
# amortized
for v in range(NV):
    A("gen2-amortized", f"dequeWin_{v}", f"vector<int> dequeWin_{v}(const vector<int>& a, int k) {{ deque<int> dq; vector<int> res; for (int i = 0; i < (int)a.size(); ++i) {{ while (!dq.empty() && dq.front() <= i - k) dq.pop_front(); while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back(); dq.push_back(i); if (i >= k - 1) res.push_back(a[dq.front()]); }} return res; }}", "O(n)", "O(k)", "exact", ["amortized"])
# intervals
for v in range(NV):
    A("gen2-intervals", f"mergeIv_{v}", f"vector<pair<int,int>> mergeIv_{v}(vector<pair<int,int>>& iv) {{ sort(iv.begin(), iv.end()); vector<pair<int,int>> merged; for (auto& p : iv) {{ if (!merged.empty() && merged.back().second >= p.first) merged.back().second = max(merged.back().second, p.second); else merged.push_back(p); }} return merged; }}", "O(n log n)", "O(n)", "exact", ["intervals"])
# constants
for v in range(4):
    A("gen2-const", f"constLoop_{v}", f"int constLoop_{v}() {{ const int SIZE = 1000; int sum = 0; for (int i = 0; i < SIZE; ++i) sum += i; return sum; }}", "O(1)", "O(1)", "exact", ["constant"])
    A("gen2-const", f"fixedArr_{v}", f"long long fixedArr_{v}() {{ long long total = 0; for (int i = 0; i < 100; ++i) total += i; return total; }}", "O(1)", "O(1)", "exact", ["constant"])
# composition
for v in range(NV):
    A("gen2-compose2", f"run_{v}", f"int h1_{v}(int x) {{ return x * 2; }} int h2_{v}(int x) {{ return h1_{v}(x) + 1; }} int run_{v}(int n) {{ int s = 0; for (int i = 0; i < n; ++i) s += h2_{v}(i); return s; }}", "O(n)", "O(1)", "exact", ["composition"])
    A("gen2-compose2", f"f_{v}", f"int a_{v}(int x) {{ return x + 1; }} int b_{v}(int x) {{ return a_{v}(x) * 2; }} int c_{v}(int x) {{ return b_{v}(x) - 1; }} int f_{v}(int n) {{ int t = 0; for (int i = 0; i < n; ++i) t += c_{v}(i); return t; }}", "O(n)", "O(1)", "exact", ["composition"])
# sequential
for v in range(NV):
    A("gen2-seq2", f"threePhase_{v}", f"long long threePhase_{v}(int n, int m) {{ long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ++s; for (int i = 0; i < m; ++i) ++s; for (int i = 0; i < n; ++i) ++s; return s; }}", "O(n^2 + m)", "O(1)", "exact", ["sequential"])
    A("gen2-seq2", f"mixedLoops_{v}", f"long long mixedLoops_{v}(int n) {{ long long s = 0; for (int i = 0; i < n; ++i) ++s; for (int i = 0; i < n; i *= 2) ++s; for (int i = 1; i * i <= n; ++i) ++s; return s; }}", "O(n)", "O(1)", "exact", ["sequential"])
# conditional
for v in range(NV):
    A("gen2-cond2", f"branchLoop_{v}", f"long long branchLoop_{v}(int n, bool flag) {{ long long s = 0; for (int i = 0; i < n; ++i) {{ if (flag) s += i; else s += 2 * i; }} return s; }}", "O(n)", "O(1)", "exact", ["conditional"])
# STL ops
for v in range(NV):
    A("gen2-stlops", f"vecPush_{v}", f"void vecPush_{v}(vector<int>& v, int n) {{ for (int i = 0; i < n; ++i) v.push_back(i); }}", "O(n)", "O(n)", "exact", ["stl"])
    A("gen2-stlops", f"setInsert_{v}", f"int setInsert_{v}(int n) {{ set<int> s; for (int i = 0; i < n; ++i) s.insert(i); return s.size(); }}", "O(n log n)", "O(n)", "exact", ["stl"])

# Generate
total = 0
for family, cases in FAMILIES.items():
    expanded = cases  # templates already embed the variant number
    chunk_size = 100
    for ci in range(0, len(expanded), chunk_size):
        chunk = expanded[ci:ci + chunk_size]
        part = f"{family}-{ci // chunk_size + 1:02d}"
        cpp = [f"// Generated family: {part}", "// Labels from first principles.", "using namespace std;", ""]
        mc = []
        for case in chunk:
            cpp.append(case["code"])
            mc.append({"id": f"{part}-{case['symbol']}", "symbol": case["symbol"], "time": case["time"], "space": case["space"], "confidence": case["confidence"], "tags": case["tags"]})
        with open(os.path.join(DATASETS, part + ".cpp"), "w", encoding="utf-8", newline="\n") as f:
            f.write("\n".join(cpp) + "\n")
        with open(os.path.join(DATASETS, part + ".manifest.json"), "w", encoding="utf-8", newline="\n") as f:
            json.dump({"version": 1, "language": "cpp", "cases": mc}, f, indent=1)
        total += len(chunk)
print(f"Round-2 TOTAL: {total}")
