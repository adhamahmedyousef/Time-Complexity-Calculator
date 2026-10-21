#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int g8_bsearchStd_20(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_20(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_20(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_20(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_20(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_20(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_20(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_20(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_21(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_21(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_21(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_21(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_21(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_21(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_21(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_21(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_22(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_22(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_22(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_22(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_22(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_22(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_22(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_22(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_23(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_23(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_23(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_23(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_23(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_23(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_23(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_23(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_24(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_24(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_24(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_24(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_24(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_24(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_24(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_24(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }
