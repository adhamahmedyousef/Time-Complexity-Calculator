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


int g8_dpFib_5(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_5(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_5(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_5(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_5(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_5(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_5(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_5(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_6(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_6(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_6(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_6(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_6(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_6(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_6(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_6(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_7(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_7(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_7(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_7(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_7(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_7(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_7(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_7(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_8(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_8(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_8(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_8(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_8(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_8(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_8(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_8(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_9(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_9(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_9(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_9(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_9(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_9(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_9(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_9(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }
