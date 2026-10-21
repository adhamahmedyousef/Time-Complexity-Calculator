// Generated family: gen6-range-05
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<long long> sumOfSquaresPrefix_66(const vector<int>& a) { int n = a.size(); vector<long long> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + (long long)a[i] * a[i]; return p; }
vector<vector<int>> prefixSum2DBuild_66(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = g[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }
