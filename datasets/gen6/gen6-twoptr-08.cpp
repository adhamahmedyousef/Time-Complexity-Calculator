// Generated family: gen6-twoptr-08
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool isPalindromeScan_63(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool isSortedAscending_63(const vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) if (a[i] < a[i - 1]) return false; return true; }
vector<int> sortedSquaresMerge_63(const vector<int>& a) { int n = a.size(); vector<int> res(n); int lo = 0, hi = n - 1, p = n - 1; while (lo <= hi) { int s1 = a[lo] * a[lo], s2 = a[hi] * a[hi]; if (s1 > s2) { res[p--] = s1; ++lo; } else { res[p--] = s2; --hi; } } return res; }
vector<double> slidingWindowAverage_63(const vector<int>& a, int k) { int n = a.size(); vector<double> res; if (n < k || k <= 0) return res; double s = 0; for (int i = 0; i < k; ++i) s += a[i]; res.push_back(s / k); for (int i = k; i < n; ++i) { s += a[i] - a[i - k]; res.push_back(s / k); } return res; }
bool twoSumSortedTarget_64(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int twoSumLessThanK_64(const vector<int>& a, int k) { int lo = 0, hi = (int)a.size() - 1, best = -1; while (lo < hi) { int s = a[lo] + a[hi]; if (s < k) { if (s > best) best = s; ++lo; } else --hi; } return best; }
int containerMostWater_64(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, best = 0; while (lo < hi) { int w = hi - lo; if (h[lo] < h[hi]) { int cur = h[lo] * w; if (cur > best) best = cur; ++lo; } else { int cur = h[hi] * w; if (cur > best) best = cur; --hi; } } return best; }
int trappingRainWater_64(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, ans = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else ans += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else ans += rmax - h[hi]; --hi; } } return ans; }
int removeDuplicatesFast_64(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
int removeTargetVal_64(vector<int>& a, int val) { int k = 0; for (int i = 0; i < (int)a.size(); ++i) if (a[i] != val) a[k++] = a[i]; return k; }
void moveZeroesInPlace_64(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
bool isPalindromeScan_64(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool isSortedAscending_64(const vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) if (a[i] < a[i - 1]) return false; return true; }
vector<int> sortedSquaresMerge_64(const vector<int>& a) { int n = a.size(); vector<int> res(n); int lo = 0, hi = n - 1, p = n - 1; while (lo <= hi) { int s1 = a[lo] * a[lo], s2 = a[hi] * a[hi]; if (s1 > s2) { res[p--] = s1; ++lo; } else { res[p--] = s2; --hi; } } return res; }
vector<double> slidingWindowAverage_64(const vector<int>& a, int k) { int n = a.size(); vector<double> res; if (n < k || k <= 0) return res; double s = 0; for (int i = 0; i < k; ++i) s += a[i]; res.push_back(s / k); for (int i = k; i < n; ++i) { s += a[i] - a[i - k]; res.push_back(s / k); } return res; }
bool twoSumSortedTarget_65(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int twoSumLessThanK_65(const vector<int>& a, int k) { int lo = 0, hi = (int)a.size() - 1, best = -1; while (lo < hi) { int s = a[lo] + a[hi]; if (s < k) { if (s > best) best = s; ++lo; } else --hi; } return best; }
int containerMostWater_65(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, best = 0; while (lo < hi) { int w = hi - lo; if (h[lo] < h[hi]) { int cur = h[lo] * w; if (cur > best) best = cur; ++lo; } else { int cur = h[hi] * w; if (cur > best) best = cur; --hi; } } return best; }
int trappingRainWater_65(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, ans = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else ans += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else ans += rmax - h[hi]; --hi; } } return ans; }
int removeDuplicatesFast_65(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
int removeTargetVal_65(vector<int>& a, int val) { int k = 0; for (int i = 0; i < (int)a.size(); ++i) if (a[i] != val) a[k++] = a[i]; return k; }
void moveZeroesInPlace_65(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
bool isPalindromeScan_65(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool isSortedAscending_65(const vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) if (a[i] < a[i - 1]) return false; return true; }
vector<int> sortedSquaresMerge_65(const vector<int>& a) { int n = a.size(); vector<int> res(n); int lo = 0, hi = n - 1, p = n - 1; while (lo <= hi) { int s1 = a[lo] * a[lo], s2 = a[hi] * a[hi]; if (s1 > s2) { res[p--] = s1; ++lo; } else { res[p--] = s2; --hi; } } return res; }
vector<double> slidingWindowAverage_65(const vector<int>& a, int k) { int n = a.size(); vector<double> res; if (n < k || k <= 0) return res; double s = 0; for (int i = 0; i < k; ++i) s += a[i]; res.push_back(s / k); for (int i = k; i < n; ++i) { s += a[i] - a[i - k]; res.push_back(s / k); } return res; }
bool twoSumSortedTarget_66(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int s = a[lo] + a[hi]; if (s == target) return true; if (s < target) ++lo; else --hi; } return false; }
int twoSumLessThanK_66(const vector<int>& a, int k) { int lo = 0, hi = (int)a.size() - 1, best = -1; while (lo < hi) { int s = a[lo] + a[hi]; if (s < k) { if (s > best) best = s; ++lo; } else --hi; } return best; }
int containerMostWater_66(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, best = 0; while (lo < hi) { int w = hi - lo; if (h[lo] < h[hi]) { int cur = h[lo] * w; if (cur > best) best = cur; ++lo; } else { int cur = h[hi] * w; if (cur > best) best = cur; --hi; } } return best; }
int trappingRainWater_66(const vector<int>& h) { int lo = 0, hi = (int)h.size() - 1, lmax = 0, rmax = 0, ans = 0; while (lo <= hi) { if (h[lo] <= h[hi]) { if (h[lo] >= lmax) lmax = h[lo]; else ans += lmax - h[lo]; ++lo; } else { if (h[hi] >= rmax) rmax = h[hi]; else ans += rmax - h[hi]; --hi; } } return ans; }
int removeDuplicatesFast_66(vector<int>& a) { if (a.empty()) return 0; int slow = 0; for (size_t fast = 1; fast < a.size(); ++fast) if (a[fast] != a[slow]) a[++slow] = a[fast]; return slow + 1; }
int removeTargetVal_66(vector<int>& a, int val) { int k = 0; for (int i = 0; i < (int)a.size(); ++i) if (a[i] != val) a[k++] = a[i]; return k; }
void moveZeroesInPlace_66(vector<int>& a) { int slow = 0, n = a.size(); for (int fast = 0; fast < n; ++fast) if (a[fast] != 0) swap(a[slow++], a[fast]); }
bool isPalindromeScan_66(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
bool isSortedAscending_66(const vector<int>& a) { for (int i = 1; i < (int)a.size(); ++i) if (a[i] < a[i - 1]) return false; return true; }
vector<int> sortedSquaresMerge_66(const vector<int>& a) { int n = a.size(); vector<int> res(n); int lo = 0, hi = n - 1, p = n - 1; while (lo <= hi) { int s1 = a[lo] * a[lo], s2 = a[hi] * a[hi]; if (s1 > s2) { res[p--] = s1; ++lo; } else { res[p--] = s2; --hi; } } return res; }
vector<double> slidingWindowAverage_66(const vector<int>& a, int k) { int n = a.size(); vector<double> res; if (n < k || k <= 0) return res; double s = 0; for (int i = 0; i < k; ++i) s += a[i]; res.push_back(s / k); for (int i = k; i < n; ++i) { s += a[i] - a[i - k]; res.push_back(s / k); } return res; }
