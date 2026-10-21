#include <bits/stdc++.h>
using namespace std;

// branching-triple-01
long long tripleBranchRec_1_1(int n) { if (n <= 1) return 1; return tripleBranchRec_1_1(n - 1) + tripleBranchRec_1_1(n - 2) + tripleBranchRec_1_1(n - 3); }

// branching-triple-02
static long long helper(int n) { if (n <= 1) return 1; return helper(n - 1) + helper(n - 2) + helper(n - 3); } long long tripleBranchRec_1_2(int n) { return helper(n); }

// branching-triple-03
struct S { long long run(int n) { if (n <= 1) return 1; return run(n - 1) + run(n - 2) + run(n - 3); } }; long long tripleBranchRec_1_3(int n) { return S{}.run(n); }

// branching-triple-04
long long tripleBranchRec_1_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x - 1) + self(self, x - 2) + self(self, x - 3); }; return go(go, n); }

// branching-two-05
long long doubleBranchRec_2_1(int n) { if (n <= 1) return 1; return doubleBranchRec_2_1(n - 1) + doubleBranchRec_2_1(n - 1); }

// branching-two-06
static long long h(int n) { if (n <= 1) return 1; return h(n - 1) + h(n - 1); } long long doubleBranchRec_2_2(int n) { return h(n); }

// branching-two-07
struct S { long long run(int n) { if (n <= 1) return 1; return run(n - 1) + run(n - 1); } }; long long doubleBranchRec_2_3(int n) { return S{}.run(n); }

// branching-two-08
long long doubleBranchRec_2_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x - 1) + self(self, x - 1); }; return go(go, n); }

// branching-mixed-step-09
long long mixedStepRec_3_1(int n) { if (n <= 1) return 1; return mixedStepRec_3_1(n - 1) + mixedStepRec_3_1(n - 4); }

// branching-mixed-step-10
static long long h(int n) { if (n <= 1) return 1; return h(n - 1) + h(n - 4); } long long mixedStepRec_3_2(int n) { return h(n); }

// branching-mixed-step-11
struct S { long long run(int n) { if (n <= 1) return 1; return run(n - 1) + run(n - 4); } }; long long mixedStepRec_3_3(int n) { return S{}.run(n); }

// branching-mixed-step-12
long long mixedStepRec_3_4(int n) { auto go = [&](auto&& self, int x)->long long { if (x <= 1) return 1; return self(self, x - 1) + self(self, x - 4); }; return go(go, n); }

// branching-balanced-step-13
long long pack_project_x_recurrence_pack_balancedTwoStepRec_4_1(int n) { if (n <= 1) return 1; return pack_project_x_recurrence_pack_balancedTwoStepRec_4_1(n - 2) + pack_project_x_recurrence_pack_balancedTwoStepRec_4_1(n - 2); }
