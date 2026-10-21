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


void g8_matrixFill_10(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_10(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_10(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_10(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_10(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_10(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_10(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_10(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_11(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_11(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_11(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_11(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_11(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_11(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_11(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_11(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_12(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_12(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_12(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_12(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_12(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_12(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_12(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_12(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_13(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_13(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_13(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_13(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_13(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_13(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_13(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_13(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_14(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_14(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_14(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_14(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_14(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_14(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_14(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_14(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }
