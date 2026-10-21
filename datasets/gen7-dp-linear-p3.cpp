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


vector<int> runningDifferenceDP_12(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_12(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_12(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_12(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_13(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_13(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_13(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_13(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_13(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_13(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_13(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_13(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_14(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_14(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_14(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_14(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_14(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_14(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_14(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_14(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_15(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_15(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_15(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_15(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_15(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_15(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_15(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_15(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_16(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_16(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_16(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_16(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_16(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_16(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_16(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_16(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_17(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_17(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_17(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_17(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_17(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_17(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_17(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_17(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_18(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_18(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_18(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_18(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_18(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_18(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }
