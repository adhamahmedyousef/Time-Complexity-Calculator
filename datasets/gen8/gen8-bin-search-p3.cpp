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


int g8_bsearchStd_10(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_10(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_10(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_10(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_10(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_10(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_10(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_10(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_11(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_11(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_11(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_11(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_11(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_11(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_11(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_11(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_12(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_12(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_12(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_12(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_12(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_12(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_12(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_12(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_13(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_13(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_13(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_13(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_13(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_13(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_13(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_13(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_14(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_14(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_14(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_14(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_14(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_14(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_14(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_14(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }
