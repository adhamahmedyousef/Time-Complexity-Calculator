// Generated family: gen3-adv3-01
// Labels from first principles.
using namespace std;

int collatzSteps_0(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_0(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_0(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_0(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_0(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_0(int n); int mutualRecursion_0(int n) { if (n <= 0) return 0; return 1 + mutualHelper_0(n - 1); } int mutualHelper_0(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_0(n - 2); }
int collatzSteps_1(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_1(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_1(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_1(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_1(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_1(int n); int mutualRecursion_1(int n) { if (n <= 0) return 0; return 1 + mutualHelper_1(n - 1); } int mutualHelper_1(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_1(n - 2); }
int collatzSteps_2(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_2(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_2(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_2(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_2(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_2(int n); int mutualRecursion_2(int n) { if (n <= 0) return 0; return 1 + mutualHelper_2(n - 1); } int mutualHelper_2(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_2(n - 2); }
int collatzSteps_3(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_3(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_3(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_3(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_3(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_3(int n); int mutualRecursion_3(int n) { if (n <= 0) return 0; return 1 + mutualHelper_3(n - 1); } int mutualHelper_3(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_3(n - 2); }
int collatzSteps_4(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_4(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_4(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_4(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_4(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_4(int n); int mutualRecursion_4(int n) { if (n <= 0) return 0; return 1 + mutualHelper_4(n - 1); } int mutualHelper_4(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_4(n - 2); }
int collatzSteps_5(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_5(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_5(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_5(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_5(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_5(int n); int mutualRecursion_5(int n) { if (n <= 0) return 0; return 1 + mutualHelper_5(n - 1); } int mutualHelper_5(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_5(n - 2); }
int collatzSteps_6(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_6(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_6(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_6(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_6(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_6(int n); int mutualRecursion_6(int n) { if (n <= 0) return 0; return 1 + mutualHelper_6(n - 1); } int mutualHelper_6(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_6(n - 2); }
int collatzSteps_7(long long x) { int steps = 0; while (x != 1) { if (x % 2 == 0) x /= 2; else x = 3 * x + 1; ++steps; } return steps; }
int dataDependentWalk_7(vector<int>& a) { int i = 0, steps = 0; while (i >= 0 && i < (int)a.size()) { i = a[i]; ++steps; } return steps; }
int pointerChase_7(vector<int>& nextOf) { int cur = 0, steps = 0; while (cur != -1 && steps <= (int)nextOf.size()) { cur = nextOf[cur]; ++steps; } return steps; }
long long randomishWhile_7(long long seed) { long long x = seed; while (x > 0) { x = x % 7 == 0 ? x / 7 : x - 3; } return x; }
int externalScan_7(vector<int>& a, int (*probe)(int)) { int c = 0; for (int x : a) { if (probe(x)) ++c; } return c; }
int mutualHelper_7(int n); int mutualRecursion_7(int n) { if (n <= 0) return 0; return 1 + mutualHelper_7(n - 1); } int mutualHelper_7(int n) { if (n <= 0) return 0; return 1 + mutualRecursion_7(n - 2); }
