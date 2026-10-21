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


void g8_matrixFill_15(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_15(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_15(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_15(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_15(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_15(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_15(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_15(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_16(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_16(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_16(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_16(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_16(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_16(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_16(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_16(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_17(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_17(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_17(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_17(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_17(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_17(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_17(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_17(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_18(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_18(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_18(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_18(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_18(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_18(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_18(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_18(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_19(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_19(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_19(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_19(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_19(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_19(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_19(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_19(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }
