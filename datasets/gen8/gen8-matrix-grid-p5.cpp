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


void g8_matrixFill_20(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_20(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_20(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_20(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_20(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_20(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_20(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_20(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_21(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_21(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_21(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_21(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_21(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_21(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_21(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_21(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_22(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_22(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_22(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_22(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_22(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_22(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_22(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_22(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_23(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_23(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_23(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_23(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_23(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_23(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_23(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_23(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_24(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_24(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_24(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_24(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_24(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_24(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_24(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_24(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }
