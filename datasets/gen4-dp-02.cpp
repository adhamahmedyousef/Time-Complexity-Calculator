// Generated family: gen4-dp-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long tribonacciLinear_16(int n) { if (n == 0) return 0; if (n <= 2) return 1; long long a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { long long d = a + b + c; a = b; b = c; c = d; } return c; }
long long fibonacciSpaceOptimized_16(int n) { if (n <= 1) return n; long long a = 0, b = 1; for (int i = 2; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }
int rodCuttingDP_17(const vector<int>& price, int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) { int mx = 0; for (int j = 1; j <= i; ++j) { int cand = price[j - 1] + dp[i - j]; if (cand > mx) mx = cand; } dp[i] = mx; } return dp[n]; }
long long paintFenceDP_17(int n, int k) { if (n == 0) return 0; if (n == 1) return k; long long same = k, diff = (long long)k * (k - 1); for (int i = 3; i <= n; ++i) { long long prevDiff = diff; diff = (same + diff) * (k - 1); same = prevDiff; } return same + diff; }
int maxSubarraySumCircular_17(const vector<int>& a) { int total = 0, maxSoFar = a[0], curMax = 0, minSoFar = a[0], curMin = 0; for (int x : a) { curMax = max(curMax + x, x); maxSoFar = max(maxSoFar, curMax); curMin = min(curMin + x, x); minSoFar = min(minSoFar, curMin); total += x; } return maxSoFar > 0 ? max(maxSoFar, total - minSoFar) : maxSoFar; }
int targetSumSubsetWays_17(const vector<int>& a, int W) { vector<int> dp(W + 1, 0); dp[0] = 1; for (int x : a) for (int c = W; c >= x; --c) dp[c] += dp[c - x]; return dp[W]; }
long long tribonacciLinear_17(int n) { if (n == 0) return 0; if (n <= 2) return 1; long long a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { long long d = a + b + c; a = b; b = c; c = d; } return c; }
long long fibonacciSpaceOptimized_17(int n) { if (n <= 1) return n; long long a = 0, b = 1; for (int i = 2; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }
int rodCuttingDP_18(const vector<int>& price, int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) { int mx = 0; for (int j = 1; j <= i; ++j) { int cand = price[j - 1] + dp[i - j]; if (cand > mx) mx = cand; } dp[i] = mx; } return dp[n]; }
long long paintFenceDP_18(int n, int k) { if (n == 0) return 0; if (n == 1) return k; long long same = k, diff = (long long)k * (k - 1); for (int i = 3; i <= n; ++i) { long long prevDiff = diff; diff = (same + diff) * (k - 1); same = prevDiff; } return same + diff; }
int maxSubarraySumCircular_18(const vector<int>& a) { int total = 0, maxSoFar = a[0], curMax = 0, minSoFar = a[0], curMin = 0; for (int x : a) { curMax = max(curMax + x, x); maxSoFar = max(maxSoFar, curMax); curMin = min(curMin + x, x); minSoFar = min(minSoFar, curMin); total += x; } return maxSoFar > 0 ? max(maxSoFar, total - minSoFar) : maxSoFar; }
int targetSumSubsetWays_18(const vector<int>& a, int W) { vector<int> dp(W + 1, 0); dp[0] = 1; for (int x : a) for (int c = W; c >= x; --c) dp[c] += dp[c - x]; return dp[W]; }
long long tribonacciLinear_18(int n) { if (n == 0) return 0; if (n <= 2) return 1; long long a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { long long d = a + b + c; a = b; b = c; c = d; } return c; }
long long fibonacciSpaceOptimized_18(int n) { if (n <= 1) return n; long long a = 0, b = 1; for (int i = 2; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }
int rodCuttingDP_19(const vector<int>& price, int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) { int mx = 0; for (int j = 1; j <= i; ++j) { int cand = price[j - 1] + dp[i - j]; if (cand > mx) mx = cand; } dp[i] = mx; } return dp[n]; }
long long paintFenceDP_19(int n, int k) { if (n == 0) return 0; if (n == 1) return k; long long same = k, diff = (long long)k * (k - 1); for (int i = 3; i <= n; ++i) { long long prevDiff = diff; diff = (same + diff) * (k - 1); same = prevDiff; } return same + diff; }
int maxSubarraySumCircular_19(const vector<int>& a) { int total = 0, maxSoFar = a[0], curMax = 0, minSoFar = a[0], curMin = 0; for (int x : a) { curMax = max(curMax + x, x); maxSoFar = max(maxSoFar, curMax); curMin = min(curMin + x, x); minSoFar = min(minSoFar, curMin); total += x; } return maxSoFar > 0 ? max(maxSoFar, total - minSoFar) : maxSoFar; }
int targetSumSubsetWays_19(const vector<int>& a, int W) { vector<int> dp(W + 1, 0); dp[0] = 1; for (int x : a) for (int c = W; c >= x; --c) dp[c] += dp[c - x]; return dp[W]; }
long long tribonacciLinear_19(int n) { if (n == 0) return 0; if (n <= 2) return 1; long long a = 0, b = 1, c = 1; for (int i = 3; i <= n; ++i) { long long d = a + b + c; a = b; b = c; c = d; } return c; }
long long fibonacciSpaceOptimized_19(int n) { if (n <= 1) return n; long long a = 0, b = 1; for (int i = 2; i <= n; ++i) { long long c = a + b; a = b; b = c; } return b; }
