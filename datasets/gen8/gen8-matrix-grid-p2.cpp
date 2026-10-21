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


void g8_matrixFill_5(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_5(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_5(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_5(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_5(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_5(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_5(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_5(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_6(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_6(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_6(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_6(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_6(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_6(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_6(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_6(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_7(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_7(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_7(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_7(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_7(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_7(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_7(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_7(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_8(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_8(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_8(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_8(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_8(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_8(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_8(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_8(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_9(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_9(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_9(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_9(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_9(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_9(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_9(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_9(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }
