#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int binSearchFunctionalCast_12(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_12(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_12(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_12(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_13(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_13(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_13(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_13(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_13(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_13(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_13(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_13(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_14(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_14(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_14(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_14(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_14(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_14(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_14(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_14(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_15(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_15(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_15(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_15(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_15(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_15(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_15(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_15(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_16(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_16(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_16(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_16(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_16(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_16(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_16(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_16(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_17(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_17(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_17(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_17(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_17(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_17(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_17(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_17(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_18(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_18(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_18(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_18(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_18(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_18(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }
