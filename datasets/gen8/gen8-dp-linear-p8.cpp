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


int g8_dpFib_35(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_35(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_35(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_35(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_35(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_35(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_35(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_35(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_36(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_36(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_36(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_36(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_36(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_36(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_36(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_36(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_37(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_37(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_37(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_37(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_37(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_37(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_37(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_37(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_38(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_38(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_38(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_38(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_38(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_38(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_38(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_38(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }

int g8_dpFib_39(int n) { if (n <= 1) return n; vector<int> dp(n + 1); dp[0] = 0; dp[1] = 1; for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2]; return dp[n]; }

int g8_dpClimb_39(int n, const vector<int>& cost) { vector<int> dp(n + 1, 0); for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); return dp[n]; }

int g8_dpRolling_39(int n) { int a = 0, b = 1; for (int i = 2; i <= n; ++i) { int c = a + b; a = b; b = c; } return b; }

vector<int> g8_dpPrefix_39(const vector<int>& a) { vector<int> pref(a.size() + 1, 0); for (int i = 0; i < static_cast<int>(a.size()); ++i) pref[i + 1] = pref[i] + a[i]; return pref; }

vector<int> g8_dpSuffix_39(const vector<int>& a) { int n = a.size(); vector<int> suf(n + 1, 0); for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i]; return suf; }

int g8_dpHouseRobber_39(const vector<int>& nums) { if (nums.empty()) return 0; int prev1 = 0, prev2 = 0; for (int x : nums) { int tmp = max(prev1, prev2 + x); prev2 = prev1; prev1 = tmp; } return prev1; }

int g8_dpMaxSub_39(const vector<int>& a) { int cur = 0, ans = 0; for (int x : a) { cur = max(x, cur + x); ans = max(ans, cur); } return ans; }

vector<int> g8_dpCoin_39(int n) { vector<int> dp(n + 1, 0); for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + 1; return dp; }
