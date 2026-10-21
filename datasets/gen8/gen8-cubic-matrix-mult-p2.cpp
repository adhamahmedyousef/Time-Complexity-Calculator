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


vector<vector<int>> g8_matMul_5(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_5(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_5(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_5(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_5(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_5(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_5(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_5(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_6(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_6(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_6(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_6(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_6(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_6(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_6(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_6(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_7(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_7(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_7(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_7(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_7(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_7(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_7(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_7(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_8(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_8(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_8(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_8(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_8(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_8(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_8(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_8(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_9(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_9(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_9(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_9(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_9(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_9(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_9(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_9(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }
