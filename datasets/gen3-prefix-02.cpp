// Generated family: gen3-prefix-02
// Labels from first principles.
using namespace std;

vector<long long> suffixSum_7(const vector<int>& a) { int n = a.size(); vector<long long> s(n + 1, 0); for (int i = n - 1; i >= 0; --i) s[i] = s[i + 1] + a[i]; return s; }
vector<long long> diffArray_7(const vector<int>& a) { int n = a.size(); vector<long long> d(n, 0); if (n > 0) d[0] = a[0]; for (int i = 1; i < n; ++i) d[i] = a[i] - a[i - 1]; return d; }
vector<long long> rangeAddRestore_7(int n, int q) { vector<long long> d(n + 1, 0); for (int i = 0; i < q; ++i) { int l = i % n, r = (i * 2 + 1) % n; if (l > r) { int tmp = l; l = r; r = tmp; } d[l] += 1; if (r + 1 <= n) d[r + 1] -= 1; } long long cur = 0; for (int i = 0; i < n; ++i) { cur += d[i]; d[i] = cur; } return d; }
int runningMax_7(const vector<int>& a) { int best = a[0]; for (int x : a) if (x > best) best = x; return best; }
int runningMin_7(const vector<int>& a) { int best = a[0]; for (int i = 0; i < (int)a.size(); ++i) if (a[i] < best) best = a[i]; return best; }
vector<int> prefixMax_7(const vector<int>& a) { int n = a.size(); vector<int> p(n, 0); if (n > 0) p[0] = a[0]; for (int i = 1; i < n; ++i) { p[i] = p[i - 1]; if (a[i] > p[i]) p[i] = a[i]; } return p; }
vector<vector<int>> gridRowPrefix_7(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<int>> p(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { p[i][j] = g[i][j]; if (j > 0) p[i][j] += p[i][j - 1]; } return p; }
vector<vector<long long>> gridPrefix2d_7(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<vector<long long>> p(n + 1, vector<long long>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) p[i][j] = g[i - 1][j - 1] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1]; return p; }
vector<int> gridRowSums_7(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<int> sums(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) sums[i] += g[i][j]; return sums; }
vector<int> gridColSums_7(const vector<vector<int>>& g) { int n = g.size(), m = g[0].size(); vector<int> sums(m, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) sums[j] += g[i][j]; return sums; }
long long diagonalSum_7(const vector<vector<int>>& g) { int n = g.size(); long long s = 0; for (int i = 0; i < n; ++i) s += g[i][i]; return s; }
int prefixCountQueries_7(const vector<int>& a, int q) { int n = a.size(); vector<int> p(n + 1, 0); for (int i = 0; i < n; ++i) p[i + 1] = p[i] + (a[i] % 2 == 0 ? 1 : 0); int total = 0; for (int i = 0; i < q; ++i) { int l = i % n, r = (i + n / 2) % n; if (l > r) { int tmp = l; l = r; r = tmp; } total += p[r + 1] - p[l]; } return total; }
