// Generated family: gen5-range-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<long long> diffArrayRangeUpdates_25(int n, int q) { vector<long long> diff(n + 2, 0); for (int i = 0; i < q; ++i) { diff[1] += 5; diff[n + 1] -= 5; } for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1]; return diff; }
vector<int> prefixMinScan_25(const vector<int>& a) { int n = a.size(); vector<int> pm(n); if (n == 0) return pm; pm[0] = a[0]; for (int i = 1; i < n; ++i) pm[i] = min(pm[i - 1], a[i]); return pm; }
vector<int> suffixMaxScan_25(const vector<int>& a) { int n = a.size(); vector<int> sm(n); if (n == 0) return sm; sm[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) sm[i] = max(sm[i + 1], a[i]); return sm; }
vector<vector<int>> prefixSum2DBuild_25(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = g[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }
vector<long long> diffArrayRangeUpdates_26(int n, int q) { vector<long long> diff(n + 2, 0); for (int i = 0; i < q; ++i) { diff[1] += 5; diff[n + 1] -= 5; } for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1]; return diff; }
vector<int> prefixMinScan_26(const vector<int>& a) { int n = a.size(); vector<int> pm(n); if (n == 0) return pm; pm[0] = a[0]; for (int i = 1; i < n; ++i) pm[i] = min(pm[i - 1], a[i]); return pm; }
vector<int> suffixMaxScan_26(const vector<int>& a) { int n = a.size(); vector<int> sm(n); if (n == 0) return sm; sm[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) sm[i] = max(sm[i + 1], a[i]); return sm; }
vector<vector<int>> prefixSum2DBuild_26(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = g[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }
vector<long long> diffArrayRangeUpdates_27(int n, int q) { vector<long long> diff(n + 2, 0); for (int i = 0; i < q; ++i) { diff[1] += 5; diff[n + 1] -= 5; } for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1]; return diff; }
vector<int> prefixMinScan_27(const vector<int>& a) { int n = a.size(); vector<int> pm(n); if (n == 0) return pm; pm[0] = a[0]; for (int i = 1; i < n; ++i) pm[i] = min(pm[i - 1], a[i]); return pm; }
vector<int> suffixMaxScan_27(const vector<int>& a) { int n = a.size(); vector<int> sm(n); if (n == 0) return sm; sm[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) sm[i] = max(sm[i + 1], a[i]); return sm; }
vector<vector<int>> prefixSum2DBuild_27(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = g[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }
vector<long long> diffArrayRangeUpdates_28(int n, int q) { vector<long long> diff(n + 2, 0); for (int i = 0; i < q; ++i) { diff[1] += 5; diff[n + 1] -= 5; } for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1]; return diff; }
vector<int> prefixMinScan_28(const vector<int>& a) { int n = a.size(); vector<int> pm(n); if (n == 0) return pm; pm[0] = a[0]; for (int i = 1; i < n; ++i) pm[i] = min(pm[i - 1], a[i]); return pm; }
vector<int> suffixMaxScan_28(const vector<int>& a) { int n = a.size(); vector<int> sm(n); if (n == 0) return sm; sm[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) sm[i] = max(sm[i + 1], a[i]); return sm; }
vector<vector<int>> prefixSum2DBuild_28(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = g[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }
vector<long long> diffArrayRangeUpdates_29(int n, int q) { vector<long long> diff(n + 2, 0); for (int i = 0; i < q; ++i) { diff[1] += 5; diff[n + 1] -= 5; } for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1]; return diff; }
vector<int> prefixMinScan_29(const vector<int>& a) { int n = a.size(); vector<int> pm(n); if (n == 0) return pm; pm[0] = a[0]; for (int i = 1; i < n; ++i) pm[i] = min(pm[i - 1], a[i]); return pm; }
vector<int> suffixMaxScan_29(const vector<int>& a) { int n = a.size(); vector<int> sm(n); if (n == 0) return sm; sm[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) sm[i] = max(sm[i + 1], a[i]); return sm; }
vector<vector<int>> prefixSum2DBuild_29(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = g[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }
