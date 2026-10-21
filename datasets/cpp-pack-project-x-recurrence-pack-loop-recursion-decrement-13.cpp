#include <bits/stdc++.h>
using namespace std;

// loop-recursion-n-times-01
long long loopCallsRecursive_1_1(int n) { if (n <= 1) return 1; long long ans = 0; for (int i = 0; i < n; ++i) ans += loopCallsRecursive_1_1(n - 1); return ans; }

// loop-recursion-n-times-02
static long long h(int n) { if (n <= 1) return 1; long long ans = 0; for (int i = 0; i < n; ++i) ans += h(n - 1); return ans; } long long loopCallsRecursive_1_2(int n) { return h(n); }

// loop-recursion-n-times-03
struct S { long long run(int n) { if (n <= 1) return 1; long long ans = 0; for (int i = 0; i < n; ++i) ans += run(n - 1); return ans; } }; long long loopCallsRecursive_1_3(int n) { return S{}.run(n); }

// loop-recursion-n-times-04
long long loopCallsRecursive_1_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; long long ans = 0; for (int i = 0; i < x; ++i) ans += self(self, x - 1); return ans; }; return go(go, n); }

// loop-recursion-plus-halving-05
long long loopThenHalfRec_2_1(int n) { if (n <= 1) return 1; for (int i = 0; i < n; ++i) { } return loopThenHalfRec_2_1(n / 2); }

// loop-recursion-plus-halving-06
static long long h(int n) { if (n <= 1) return 1; for (int i = 0; i < n; ++i) { } return h(n / 2); } long long loopThenHalfRec_2_2(int n) { return h(n); }

// loop-recursion-plus-halving-07
struct S { long long run(int n) { if (n <= 1) return 1; for (int i = 0; i < n; ++i) { } return run(n / 2); } }; long long loopThenHalfRec_2_3(int n) { return S{}.run(n); }

// loop-recursion-plus-halving-08
long long loopThenHalfRec_2_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; for (int i = 0; i < x; ++i) { } return self(self, x / 2); }; return go(go, n); }

// loop-recursion-linear-rec-09
long long loopCallsLinearRec_3_1(int n) { if (n <= 1) return 1; long long ans = 0; for (int i = 0; i < n; ++i) ans += loopCallsLinearRec_3_1(n - 1); return ans; }

// loop-recursion-linear-rec-10
static long long h(int n) { if (n <= 1) return 1; long long ans = 0; for (int i = 0; i < n; ++i) ans += h(n - 1); return ans; } long long loopCallsLinearRec_3_2(int n) { return h(n); }

// loop-recursion-linear-rec-11
struct S { long long run(int n) { if (n <= 1) return 1; long long ans = 0; for (int i = 0; i < n; ++i) ans += run(n - 1); return ans; } }; long long loopCallsLinearRec_3_3(int n) { return S{}.run(n); }

// loop-recursion-linear-rec-12
long long loopCallsLinearRec_3_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; long long ans = 0; for (int i = 0; i < x; ++i) ans += self(self, x - 1); return ans; }; return go(go, n); }

// loop-recursion-decrement-13
long long pack_project_x_recurrence_pack_loopCallsDecrementRec_4_1(int n) { if (n <= 1) return 1; long long sum = 0; for (int i = 0; i < n; ++i) sum += pack_project_x_recurrence_pack_loopCallsDecrementRec_4_1(n - 2) + pack_project_x_recurrence_pack_loopCallsDecrementRec_4_1(n - 2); return sum; }
