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


int g8_dpFib_30(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_30(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_30(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_30(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_30(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_30(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_30(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_30(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_31(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_31(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_31(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_31(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_31(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_31(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_31(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_31(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_32(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_32(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_32(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_32(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_32(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_32(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_32(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_32(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_33(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_33(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_33(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_33(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_33(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_33(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_33(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_33(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_34(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_34(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_34(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_34(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_34(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_34(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_34(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_34(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }
