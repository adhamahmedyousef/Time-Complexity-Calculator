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


long long fibonacciIterativeTable_25(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_25(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_25(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_25(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_25(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_25(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_25(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_25(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_26(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_26(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_26(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_26(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_26(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_26(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_26(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_26(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_27(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_27(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_27(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_27(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_27(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_27(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_27(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_27(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_28(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_28(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_28(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_28(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_28(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_28(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_28(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_28(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_29(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_29(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_29(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_29(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_29(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_29(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_29(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_29(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_30(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_30(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_30(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_30(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_30(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_30(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_30(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_30(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_31(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_31(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }
