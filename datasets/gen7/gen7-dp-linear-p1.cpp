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


long long fibonacciIterativeTable_0(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_0(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_0(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_0(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_0(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_0(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_0(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_0(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_1(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_1(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_1(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_1(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_1(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_1(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_1(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_1(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_2(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_2(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_2(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_2(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_2(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_2(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_2(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_2(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_3(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_3(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_3(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_3(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_3(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_3(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_3(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_3(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_4(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_4(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_4(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_4(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_4(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_4(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_4(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_4(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_5(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_5(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_5(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_5(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_5(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_5(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_5(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_5(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_6(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_6(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }
