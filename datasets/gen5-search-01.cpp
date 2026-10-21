// Generated family: gen5-search-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int lowerBoundBinarySearch_0(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_0(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_0(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_0(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_1(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_1(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_1(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_1(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_2(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_2(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_2(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_2(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_3(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_3(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_3(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_3(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_4(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_4(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_4(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_4(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_5(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_5(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_5(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_5(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_6(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_6(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_6(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_6(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_7(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_7(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_7(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_7(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_8(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_8(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_8(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_8(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_9(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_9(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_9(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_9(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_10(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_10(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_10(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_10(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_11(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_11(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_11(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_11(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_12(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_12(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_12(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_12(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_13(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_13(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_13(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_13(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_14(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_14(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_14(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_14(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_15(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_15(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_15(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_15(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_16(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_16(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_16(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_16(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_17(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_17(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_17(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_17(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_18(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_18(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_18(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_18(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_19(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_19(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_19(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_19(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_20(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_20(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_20(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_20(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_21(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_21(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_21(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_21(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_22(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_22(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_22(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_22(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_23(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_23(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_23(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_23(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_24(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_24(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_24(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_24(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
