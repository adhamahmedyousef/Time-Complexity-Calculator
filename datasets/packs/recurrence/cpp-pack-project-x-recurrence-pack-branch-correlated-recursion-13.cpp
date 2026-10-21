#include <bits/stdc++.h>
using namespace std;

// data-dependent-recursion-01
long long dataDependentRec_1_1(vector<int>& a, int i) { if (i < 0 || i >= (int)a.size()) return 1; if (a[i] < 0) return dataDependentRec_1_1(a, i + a[i]); return dataDependentRec_1_1(a, i - a[i]); }

// data-dependent-recursion-02
long long dataDependentRec_1_2(vector<int>& a, int i) { if (i < 0 || i >= (int)a.size()) return 1; if (a[i] < 0) return dataDependentRec_1_2(a, i + a[i]); return dataDependentRec_1_2(a, i - a[i]); }

// data-dependent-recursion-03
struct S { long long run(vector<int>& a, int i) { if (i < 0 || i >= (int)a.size()) return 1; if (a[i] < 0) return run(a, i + a[i]); return run(a, i - a[i]); } }; long long dataDependentRec_1_3(vector<int>& a, int i) { return S{}.run(a, i); }

// data-dependent-recursion-04
long long dataDependentRec_1_4(vector<int>& a, int i) { auto go = [&](auto&& self, vector<int>& arr, int x)->long long { if (x < 0 || x >= (int)arr.size()) return 1; if (arr[x] < 0) return self(self, arr, x + arr[x]); return self(self, arr, x - arr[x]); }; return go(go, a, i); }

// macro-recursion-05
#define STEP(x) ((x) & 1 ? (x) - 1 : (x) / 2) long long macroRecursion_2_1(int n) { if (n <= 1) return 1; return macroRecursion_2_1(STEP(n)) + macroRecursion_2_1(STEP(n)); }

// macro-recursion-06
#define STEP(x) ((x) & 1 ? (x) - 1 : (x) / 2) long long macroRecursion_2_2(int n) { if (n <= 1) return 1; return macroRecursion_2_2(STEP(n)) + macroRecursion_2_2(STEP(n)); }

// macro-recursion-07
struct S { static int step(int x) { return (x & 1) ? x - 1 : x / 2; } long long run(int n) { if (n <= 1) return 1; return run(step(n)) + run(step(n)); } }; long long macroRecursion_2_3(int n) { return S{}.run(n); }

// macro-recursion-08
long long macroRecursion_2_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; int y = (x & 1) ? x - 1 : x / 2; return self(self, y) + self(self, y); }; return go(go, n); }

// external-helper-recursion-09
int external(int); long long externalHelperRecursion_3_1(int n) { if (n <= 1) return 1; return external(n - 1) + externalHelperRecursion_3_1(n / 2); }

// external-helper-recursion-10
int external(int); long long externalHelperRecursion_3_2(int n) { if (n <= 1) return 1; return external(n - 1) + externalHelperRecursion_3_2(n / 2); }

// external-helper-recursion-11
struct S { static int external(int x) { return x / 2; } long long run(int n) { if (n <= 1) return 1; return external(n - 1) + run(n / 2); } }; long long externalHelperRecursion_3_3(int n) { return S{}.run(n); }

// external-helper-recursion-12
long long externalHelperRecursion_3_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return (x / 2) + self(self, x / 2); }; return go(go, n); }

// branch-correlated-recursion-13
long long pack_project_x_recurrence_pack_branchCorrelatedRecursion_4_1(int n) { if (n <= 1) return 1; if (n % 2) return pack_project_x_recurrence_pack_branchCorrelatedRecursion_4_1(n - 1) + pack_project_x_recurrence_pack_branchCorrelatedRecursion_4_1(n / 2); return pack_project_x_recurrence_pack_branchCorrelatedRecursion_4_1(n - 3) + pack_project_x_recurrence_pack_branchCorrelatedRecursion_4_1(n / 3); }
