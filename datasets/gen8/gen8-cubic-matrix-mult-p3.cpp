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


vector<vector<int>> g8_matMul_10(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_10(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_10(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_10(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_10(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_10(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_10(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_10(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_11(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_11(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_11(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_11(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_11(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_11(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_11(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_11(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_12(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_12(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_12(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_12(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_12(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_12(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_12(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_12(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_13(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_13(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_13(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_13(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_13(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_13(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_13(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_13(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }

vector<vector<int>> g8_matMul_14(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) { vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }

void g8_cubicLoop_14(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) { (void)i; (void)j; (void)k; } }

int g8_cubicTriangular_14(int n) { int cnt = 0; for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) cnt++; return cnt; }

vector<vector<int>> g8_cubicAlloc_14(int n) { vector<vector<int>> res(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) res[i][j] += 1; return res; }

void g8_cubicRect_14(int n, int m, int p) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < p; ++k) { } }

long long g8_cubicSum_14(int n) { long long total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) total += i + j + k; return total; }

void g8_cubicBreak_14(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) if (k > 100) break; }

int g8_cubicZero_14(int n) { int s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s ^= (i * j * k); return s; }
