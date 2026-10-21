// Generated family: gen5-search-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int lowerBoundBinarySearch_25(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_25(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_25(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_25(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_26(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_26(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_26(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_26(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_27(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_27(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_27(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_27(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_28(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_28(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_28(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_28(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
int lowerBoundBinarySearch_29(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] >= target) hi = mid; else lo = mid + 1; } return lo; }
int upperBoundBinarySearch_29(const vector<int>& a, int target) { int lo = 0, hi = (int)a.size(); while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] > target) hi = mid; else lo = mid + 1; } return lo; }
int findPeakElement_29(const vector<int>& a) { int lo = 0, hi = (int)a.size() - 1; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < a[mid + 1]) lo = mid + 1; else hi = mid; } return lo; }
long long intSquareRootBS_29(long long n) { if (n < 2) return n; long long lo = 1, hi = n, ans = 1; while (lo <= hi) { long long mid = lo + (hi - lo) / 2; if (mid <= n / mid) { ans = mid; lo = mid + 1; } else hi = mid - 1; } return ans; }
