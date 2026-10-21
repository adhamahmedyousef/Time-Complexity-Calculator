#include <bits/stdc++.h>
using namespace std;

// mutual-recursion-01
long long B(int); long long mutualRecursionA_1_1(int n) { if (n <= 1) return 1; return B(n - 1); } long long B(int n) { if (n <= 1) return 1; return mutualRecursionA_1_1(n - 1); }

// mutual-recursion-02
long long B(int); static long long H(int n) { if (n <= 1) return 1; return B(n - 1); } long long mutualRecursionA_1_2(int n) { return H(n); } long long B(int n) { if (n <= 1) return 1; return mutualRecursionA_1_2(n - 1); }

// mutual-recursion-03
struct S { long long run(int n) { if (n <= 1) return 1; return run(n - 1); } }; long long mutualRecursionA_1_3(int n) { return S{}.run(n); }

// mutual-recursion-04
long long mutualRecursionA_1_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x - 1); }; return go(go, n); }

// function-pointer-alias-05
long long functionPointerAliasRec_2_1(int n); static long long (*pf)(int) = functionPointerAliasRec_2_1; long long functionPointerAliasRec_2_1(int n) { if (n <= 1) return 1; return pf(n - 1) + pf(n - 1); }

// function-pointer-alias-06
long long functionPointerAliasRec_2_2(int n); static long long (*pf)(int) = functionPointerAliasRec_2_2; static long long h(int n) { if (n <= 1) return 1; return pf(n - 1) + pf(n - 1); } long long functionPointerAliasRec_2_2(int n) { return h(n); }

// function-pointer-alias-07
struct S { long long run(int n) { if (n <= 1) return 1; return run(n - 1) + run(n - 1); } }; long long functionPointerAliasRec_2_3(int n) { return S{}.run(n); }

// function-pointer-alias-08
long long functionPointerAliasRec_2_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x - 1) + self(self, x - 1); }; return go(go, n); }

// wrapper-forwarding-09
static long long core(int n) { if (n <= 1) return 1; return core(n - 1); } long long wrapperForwardRec_3_1(int n) { return core(n); }

// wrapper-forwarding-10
static long long core(int n) { if (n <= 1) return 1; return core(n - 1); } long long wrapperForwardRec_3_2(int n) { int seed = n ^ 7; return core(seed); }

// wrapper-forwarding-11
struct S { long long run(int n) { if (n <= 1) return 1; return run(n - 1); } }; long long wrapperForwardRec_3_3(int n) { return S{}.run(n); }

// wrapper-forwarding-12
long long wrapperForwardRec_3_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x - 1); }; return go(go, n); }

// alias-to-free-helper-13
long long helper_alias(int n) { if (n <= 0) return 1; return helper_alias(n - 1); } long long pack_project_x_recurrence_pack_aliasToFreeHelperRec_4_1(int n) { auto alias = helper_alias; return alias(n); }
