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


void g8_matrixFill_35(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_35(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_35(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_35(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_35(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_35(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_35(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_35(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_36(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_36(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_36(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_36(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_36(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_36(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_36(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_36(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_37(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_37(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_37(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_37(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_37(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_37(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_37(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_37(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_38(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_38(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_38(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_38(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_38(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_38(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_38(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_38(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

void g8_matrixFill_39(int n, int m) { for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { (void)i; (void)j; } }

vector<vector<int>> g8_matrixAlloc_39(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i + j; return g; }

void g8_matrixPrefix2D_39(int n, int m) { vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) pref[i][j] = pref[i-1][j] + pref[i][j-1]; }

int g8_matrixTriangular_39(int n) { int count = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) count++; return count; }

void g8_matrixSquare_39(int n) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { } }

vector<vector<int>> g8_matrixSquareAlloc_39(int n) { vector<vector<int>> mat(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mat[i][j] = 1; return mat; }

int g8_matrixBorder_39(int n, int m) { int s = 0; for (int i = 0; i < n; ++i) s += i; for (int j = 0; j < m; ++j) s += j; return s; }

int g8_matrixDiagonal_39(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }
