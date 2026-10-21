// Generated family: gen3-dp3-02
// Labels from first principles.
using namespace std;

int lcsStrings_7(const string& a, const string& b) { int m = a.size(), n = b.size(); vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) { if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]; } return dp[m][n]; }
int editDistance_7(const string& a, const string& b) { int m = a.size(), n = b.size(); vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); for (int i = 0; i <= m; ++i) dp[i][0] = i; for (int j = 0; j <= n; ++j) dp[0][j] = j; for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) { int best = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]; int diag = dp[i - 1][j - 1]; if (a[i - 1] != b[j - 1]) ++diag; if (diag < best) best = diag; dp[i][j] = best; } return dp[m][n]; }
int minPathSum_7(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> dp(n, vector<int>(m, 0)); dp[0][0] = g[0][0]; for (int i = 1; i < n; ++i) dp[i][0] = dp[i - 1][0] + g[i][0]; for (int j = 1; j < m; ++j) dp[0][j] = dp[0][j - 1] + g[0][j]; for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j) dp[i][j] = (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]) + g[i][j]; return dp[n - 1][m - 1]; }
long long uniquePaths_7(int n, int m) { vector<vector<long long>> dp(n, vector<long long>(m, 1)); for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; return dp[n - 1][m - 1]; }
