#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


vector<vector<int>> matrixMultiplication_6(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_6(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_6(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_6(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_6(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_6(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_7(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_7(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_7(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_7(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_7(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_7(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_7(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_7(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_8(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_8(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_8(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_8(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_8(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_8(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_8(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_8(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_9(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_9(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_9(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_9(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_9(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_9(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_9(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_9(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_10(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_10(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_10(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_10(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_10(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_10(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_10(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_10(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_11(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_11(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_11(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_11(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_11(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_11(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_11(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_11(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_12(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_12(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_12(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_12(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }
