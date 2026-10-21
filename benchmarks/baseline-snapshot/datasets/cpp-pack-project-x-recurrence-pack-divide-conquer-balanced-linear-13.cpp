#include <bits/stdc++.h>
using namespace std;

// divide-conquer-halves-plus-linear-01
long long halfPlusLinearRec_1_1(int n) { if (n <= 1) return 1; return halfPlusLinearRec_1_1(n / 2) + halfPlusLinearRec_1_1(n / 2) + n; }

// divide-conquer-halves-plus-linear-02
static long long h(int n) { if (n <= 1) return 1; return h(n / 2) + h(n / 2) + n; } long long halfPlusLinearRec_1_2(int n) { return h(n); }

// divide-conquer-halves-plus-linear-03
struct S { long long run(int n) { if (n <= 1) return 1; return run(n / 2) + run(n / 2) + n; } }; long long halfPlusLinearRec_1_3(int n) { return S{}.run(n); }

// divide-conquer-halves-plus-linear-04
long long halfPlusLinearRec_1_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x / 2) + self(self, x / 2) + x; }; return go(go, n); }

// divide-conquer-single-plus-linear-05
long long singlePlusLinearRec_2_1(int n) { if (n <= 1) return 1; return singlePlusLinearRec_2_1(n / 2) + n; }

// divide-conquer-single-plus-linear-06
static long long h(int n) { if (n <= 1) return 1; return h(n / 2) + n; } long long singlePlusLinearRec_2_2(int n) { return h(n); }

// divide-conquer-single-plus-linear-07
struct S { long long run(int n) { if (n <= 1) return 1; return run(n / 2) + n; } }; long long singlePlusLinearRec_2_3(int n) { return S{}.run(n); }

// divide-conquer-single-plus-linear-08
long long singlePlusLinearRec_2_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x / 2) + x; }; return go(go, n); }

// divide-conquer-mixed-split-09
long long mixedSplitRec_3_1(int n) { if (n <= 1) return 1; return mixedSplitRec_3_1(n / 2) + mixedSplitRec_3_1(n / 3) + n; }

// divide-conquer-mixed-split-10
static long long h(int n) { if (n <= 1) return 1; return h(n / 2) + h(n / 3) + n; } long long mixedSplitRec_3_2(int n) { return h(n); }

// divide-conquer-mixed-split-11
struct S { long long run(int n) { if (n <= 1) return 1; return run(n / 2) + run(n / 3) + n; } }; long long mixedSplitRec_3_3(int n) { return S{}.run(n); }

// divide-conquer-mixed-split-12
long long mixedSplitRec_3_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x / 2) + self(self, x / 3) + x; }; return go(go, n); }

// divide-conquer-balanced-linear-13
long long pack_project_x_recurrence_pack_balancedLinearRec_4_1(int n) { if (n <= 1) return 1; return pack_project_x_recurrence_pack_balancedLinearRec_4_1(n / 2) + pack_project_x_recurrence_pack_balancedLinearRec_4_1(n / 2) + 1; }
