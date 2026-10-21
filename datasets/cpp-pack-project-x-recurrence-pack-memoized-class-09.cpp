#include <bits/stdc++.h>
using namespace std;

// memoized-fib-01
long long memoFibRec_1_1(int n) { static unordered_map<int,long long> dp; if (n <= 1) return 1; if (auto it = dp.find(n); it != dp.end()) return it->second; return dp[n] = memoFibRec_1_1(n - 1) + memoFibRec_1_1(n - 2); }

// memoized-fib-02
static unordered_map<int,long long> dp; long long memoFibRec_1_2(int n) { if (n <= 1) return 1; if (auto it = dp.find(n); it != dp.end()) return it->second; return dp[n] = memoFibRec_1_2(n - 1) + memoFibRec_1_2(n - 2); }

// memoized-fib-03
struct S { unordered_map<int,long long> dp; long long run(int n) { if (n <= 1) return 1; if (auto it = dp.find(n); it != dp.end()) return it->second; return dp[n] = run(n - 1) + run(n - 2); } }; long long memoFibRec_1_3(int n) { return S{}.run(n); }

// memoized-fib-04
long long memoFibRec_1_4(int n) { auto go = [&](auto&& self, int x)->long long { static unordered_map<int,long long> dp; if (x <= 1) return 1; if (auto it = dp.find(x); it != dp.end()) return it->second; return dp[x] = self(self, x - 1) + self(self, x - 2); }; return go(go, n); }

// memoized-grid-05
long long memoGridRec_2_1(int n, int m) { static map<pair<int,int>, long long> dp; if (n <= 0 || m <= 0) return 1; auto key = make_pair(n, m); if (auto it = dp.find(key); it != dp.end()) return it->second; return dp[key] = memoGridRec_2_1(n - 1, m) + memoGridRec_2_1(n, m - 1); }

// memoized-grid-06
static map<pair<int,int>, long long> dp; long long memoGridRec_2_2(int n, int m) { if (n <= 0 || m <= 0) return 1; auto key = make_pair(n, m); if (auto it = dp.find(key); it != dp.end()) return it->second; return dp[key] = memoGridRec_2_2(n - 1, m) + memoGridRec_2_2(n, m - 1); }

// memoized-grid-07
struct S { map<pair<int,int>, long long> dp; long long run(int n, int m) { if (n <= 0 || m <= 0) return 1; auto key = make_pair(n, m); if (auto it = dp.find(key); it != dp.end()) return it->second; return dp[key] = run(n - 1, m) + run(n, m - 1); } }; long long memoGridRec_2_3(int n, int m) { return S{}.run(n, m); }

// memoized-grid-08
long long memoGridRec_2_4(int n, int m) { auto go = [&](auto&& self, int a, int b)->long long { static map<pair<int,int>, long long> dp; if (a <= 0 || b <= 0) return 1; auto key = make_pair(a, b); if (auto it = dp.find(key); it != dp.end()) return it->second; return dp[key] = self(self, a - 1, b) + self(self, a, b - 1); }; return go(go, n, m); }

// memoized-class-09
struct Solver { vector<long long> memo; explicit Solver(int n) : memo(n + 1, -1) {} long long solve(int n) { if (n <= 1) return 1; long long& res = memo[n]; if (res != -1) return res; return res = solve(n - 1) + solve(n - 2); } }; long long pack_project_x_recurrence_pack_memoClassRec_3_1(int n) { Solver s(n); return s.solve(n); }
