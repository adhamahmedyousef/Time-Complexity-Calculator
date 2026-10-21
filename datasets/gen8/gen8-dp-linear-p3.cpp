#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int g8_dpFib_10(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_10(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_10(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_10(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_10(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_10(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_10(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_10(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_11(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_11(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_11(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_11(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_11(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_11(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_11(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_11(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_12(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_12(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_12(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_12(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_12(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_12(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_12(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_12(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_13(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_13(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_13(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_13(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_13(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_13(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_13(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_13(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_14(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_14(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_14(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_14(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_14(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_14(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_14(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_14(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }
