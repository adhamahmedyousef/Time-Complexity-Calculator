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


int binSearchFunctionalCast_37(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_37(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_37(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_37(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_38(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_38(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_38(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_38(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_38(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_38(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_38(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_38(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }

int binSearchLowerBound_39(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] >= target) high = mid; else low = mid + 1; } return low; }

int binSearchUpperBound_39(const vector<int>& a, int target) { int low = 0, high = static_cast<int>(a.size()); while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > target) high = mid; else low = mid + 1; } return low; }

int binSearchClassic_39(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = left + (right - left) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchParenMid_39(const vector<int>& a, int target) { int left = 0, right = static_cast<int>(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchFunctionalCast_39(const vector<int>& a, int target) { int left = 0, right = int(a.size()) - 1; while (left <= right) { int mid = (left + right) / 2; if (a[mid] == target) return mid; if (a[mid] < target) left = mid + 1; else right = mid - 1; } return -1; }

int binSearchRotatedMin_39(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] > a[high]) low = mid + 1; else high = mid; } return a[low]; }

int binSearchPeakElement_39(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1; while (low < high) { int mid = low + (high - low) / 2; if (a[mid] < a[mid + 1]) low = mid + 1; else high = mid; } return low; }

int binSearchFirstPositive_39(const vector<int>& a) { int low = 0, high = static_cast<int>(a.size()) - 1, ans = -1; while (low <= high) { int mid = (low + high) / 2; if (a[mid] > 0) { ans = mid; high = mid - 1; } else low = mid + 1; } return ans; }
