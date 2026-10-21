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


int g8_bsearchStd_15(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_15(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_15(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_15(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_15(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_15(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_15(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_15(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_16(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_16(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_16(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_16(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_16(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_16(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_16(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_16(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_17(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_17(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_17(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_17(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_17(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_17(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_17(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_17(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_18(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_18(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_18(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_18(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_18(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_18(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_18(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_18(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_19(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_19(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_19(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_19(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_19(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_19(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_19(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_19(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }
