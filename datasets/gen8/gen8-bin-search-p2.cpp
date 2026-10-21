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


int g8_bsearchStd_5(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_5(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_5(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_5(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_5(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_5(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_5(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_5(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_6(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_6(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_6(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_6(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_6(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_6(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_6(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_6(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_7(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_7(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_7(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_7(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_7(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_7(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_7(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_7(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_8(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_8(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_8(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_8(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_8(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_8(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_8(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_8(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_9(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_9(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_9(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_9(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_9(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_9(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_9(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_9(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }
