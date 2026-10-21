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


int tribonacciIterativeDP_31(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_31(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_31(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_31(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_31(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_31(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_32(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_32(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_32(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_32(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_32(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_32(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_32(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_32(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_33(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_33(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_33(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_33(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_33(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_33(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_33(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_33(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_34(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_34(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_34(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_34(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_34(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_34(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_34(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_34(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_35(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_35(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_35(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_35(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_35(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_35(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_35(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_35(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_36(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_36(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_36(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_36(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }

vector<int> runningDifferenceDP_36(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> diff(n, 0); for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1]; return diff; }

long long linearAccumulateDP_36(const vector<int>& a) { long long s = 0; for (size_t i = 0; i < a.size(); ++i) s += a[i]; return s; }

int linearMinTracking_36(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] < m) m = a[i]; return m; }

int linearMaxTracking_36(const vector<int>& a) { if (a.empty()) return 0; int m = a[0]; for (size_t i = 1; i < a.size(); ++i) if (a[i] > m) m = a[i]; return m; }

long long fibonacciIterativeTable_37(int n) { if (n <= 1) return n; vector<long long> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

long long climbingStairsRollingDP_37(int n) { if (n <= 2) return n; long long a = 1, b = 2; for (int i = 3; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }

int tribonacciIterativeDP_37(int n) { if (n == 0) return 0; if (n <= 2) return 1; int a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { int d = a + b + c; a = b; b = c; c = d; } return c; }

vector<int> prefixSumArrayQueries_37(const vector<int>& a) { int n = static_cast<int>(a.size()); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i]; return p; }
