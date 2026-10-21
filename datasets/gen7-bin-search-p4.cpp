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


int binSearchPeakElement_18(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_18(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_19(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_19(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_19(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_19(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_19(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_19(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_19(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_19(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_20(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_20(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_20(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_20(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_20(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_20(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_20(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_20(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_21(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_21(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_21(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_21(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_21(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_21(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_21(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_21(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_22(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_22(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_22(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_22(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_22(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_22(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_22(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_22(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_23(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_23(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_23(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_23(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_23(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_23(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_23(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_23(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_24(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_24(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_24(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_24(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_24(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_24(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_24(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_24(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }
