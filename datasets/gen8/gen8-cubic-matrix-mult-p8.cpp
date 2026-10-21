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


vector<vector<int>> g8_matMul_35(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_35(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_35(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_35(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_35(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_35(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_35(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_35(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_36(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_36(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_36(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_36(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_36(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_36(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_36(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_36(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_37(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_37(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_37(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_37(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_37(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_37(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_37(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_37(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_38(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_38(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_38(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_38(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_38(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_38(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_38(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_38(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_39(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_39(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_39(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_39(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_39(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_39(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_39(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_39(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }
