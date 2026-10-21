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


int g8_dpFib_20(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_20(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_20(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_20(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_20(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_20(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_20(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_20(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_21(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_21(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_21(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_21(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_21(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_21(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_21(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_21(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_22(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_22(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_22(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_22(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_22(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_22(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_22(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_22(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_23(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_23(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_23(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_23(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_23(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_23(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_23(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_23(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_24(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_24(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_24(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_24(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_24(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_24(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_24(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_24(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }
