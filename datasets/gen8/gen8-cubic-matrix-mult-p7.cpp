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


vector<vector<int>> g8_matMul_30(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_30(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_30(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_30(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_30(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_30(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_30(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_30(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_31(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_31(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_31(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_31(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_31(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_31(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_31(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_31(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_32(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_32(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_32(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_32(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_32(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_32(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_32(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_32(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_33(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_33(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_33(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_33(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_33(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_33(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_33(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_33(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_34(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_34(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_34(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_34(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_34(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_34(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_34(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_34(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }
