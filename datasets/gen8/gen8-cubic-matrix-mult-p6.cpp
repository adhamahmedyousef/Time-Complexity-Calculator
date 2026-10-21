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


vector<vector<int>> g8_matMul_25(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_25(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_25(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_25(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_25(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_25(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_25(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_25(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_26(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_26(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_26(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_26(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_26(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_26(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_26(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_26(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_27(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_27(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_27(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_27(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_27(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_27(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_27(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_27(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_28(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_28(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_28(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_28(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_28(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_28(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_28(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_28(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_29(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_29(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_29(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_29(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_29(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_29(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_29(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_29(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }
