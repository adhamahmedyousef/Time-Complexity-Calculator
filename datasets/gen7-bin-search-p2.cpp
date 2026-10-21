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


int binSearchClassic_6(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_6(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_6(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_6(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_6(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_6(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_7(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_7(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_7(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_7(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_7(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_7(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_7(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_7(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_8(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_8(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_8(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_8(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_8(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_8(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_8(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_8(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_9(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_9(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_9(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_9(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_9(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_9(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_9(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_9(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_10(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_10(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_10(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_10(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_10(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_10(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_10(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_10(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_11(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_11(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_11(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_11(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_11(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_11(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_11(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_11(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_12(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_12(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_12(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_12(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }
