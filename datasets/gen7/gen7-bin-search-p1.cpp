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


int binSearchLowerBound_0(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_0(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_0(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_0(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_0(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_0(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_0(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_0(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_1(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_1(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_1(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_1(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_1(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_1(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_1(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_1(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_2(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_2(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_2(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_2(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_2(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_2(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_2(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_2(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_3(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_3(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_3(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_3(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_3(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_3(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_3(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_3(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_4(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_4(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_4(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_4(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_4(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_4(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_4(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_4(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_5(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_5(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_5(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_5(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_5(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_5(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_5(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_5(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_6(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_6(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }
