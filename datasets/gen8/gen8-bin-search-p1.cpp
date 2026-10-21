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


int g8_bsearchStd_0(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_0(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_0(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_0(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_0(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_0(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_0(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_0(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_1(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_1(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_1(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_1(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_1(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_1(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_1(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_1(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_2(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_2(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_2(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_2(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_2(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_2(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_2(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_2(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_3(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_3(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_3(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_3(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_3(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_3(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_3(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_3(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }

int g8_bsearchStd_4(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()) - 1; while (l <= r) { int mid = l + (r - l) / 2; if (a[mid] == x) return mid; if (a[mid] < x) l = mid + 1; else r = mid - 1; } return -1; }

int g8_bsearchLower_4(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] < x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchUpper_4(const vector<int>& a, int x) { int l = 0, r = static_cast<int>(a.size()); while (l < r) { int mid = l + (r - l) / 2; if (a[mid] <= x) l = mid + 1; else r = mid; } return l; }

int g8_bsearchMonotone_4(int n) { int low = 1, high = n, ans = 1; while (low <= high) { int mid = low + (high - low) / 2; if (mid * 2 <= n) { ans = mid; low = mid + 1; } else { high = mid - 1; } } return ans; }

int g8_bsearchBitwise_4(int n) { int lo = 0, hi = n; while (lo < hi) { int mid = lo + (hi - lo) / 2; if (mid >= 10) hi = mid; else lo = mid + 1; } return lo; }

int g8_bsearchCast_4(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low <= high) { int m = low + (high - low) / 2; if (a[m] == target) return m; if (a[m] < target) low = m + 1; else high = m - 1; } return -1; }

int g8_bsearchFloat_4(int n) { int low = 0, high = n; while (low < high) { int mid = low + (high - low) / 2; if (mid >= 5) high = mid; else low = mid + 1; } return high; }

int g8_bsearchSqrt_4(int n) { int l = 1, r = n, ans = 1; while (l <= r) { int mid = l + (r - l) / 2; if (mid <= n / mid) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }
