// Generated family: gen5-twoptr-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool twoSumSortedTarget_0(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_0(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_0(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_0(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_0(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_1(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_1(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_1(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_1(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_1(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_2(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_2(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_2(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_2(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_2(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_3(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_3(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_3(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_3(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_3(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_4(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_4(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_4(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_4(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_4(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_5(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_5(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_5(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_5(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_5(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_6(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_6(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_6(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_6(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_6(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_7(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_7(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_7(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_7(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_7(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_8(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_8(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_8(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_8(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_8(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_9(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_9(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_9(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_9(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_9(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_10(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_10(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_10(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_10(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_10(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_11(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_11(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_11(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_11(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_11(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_12(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_12(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_12(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_12(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_12(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_13(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_13(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_13(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_13(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_13(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_14(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_14(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_14(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_14(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_14(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_15(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_15(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_15(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_15(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_15(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_16(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_16(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_16(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_16(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_16(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_17(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_17(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_17(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_17(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_17(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_18(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_18(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_18(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_18(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_18(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_19(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_19(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_19(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_19(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_19(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
