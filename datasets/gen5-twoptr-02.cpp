// Generated family: gen5-twoptr-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool twoSumSortedTarget_20(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_20(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_20(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_20(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_20(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_21(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_21(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_21(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_21(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_21(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_22(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_22(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_22(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_22(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_22(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_23(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_23(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_23(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_23(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_23(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_24(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_24(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_24(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_24(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_24(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_25(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_25(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_25(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_25(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_25(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_26(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_26(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_26(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_26(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_26(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_27(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_27(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_27(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_27(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_27(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_28(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_28(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_28(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_28(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_28(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool twoSumSortedTarget_29(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int trapRainWaterTwoPtr_29(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, total = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else total += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else total += rmax - h[hi]; --hi; } } return total; }
void moveZeroesInPlace_29(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
int removeDuplicatesFast_29(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
bool isPalindromeScan_29(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
