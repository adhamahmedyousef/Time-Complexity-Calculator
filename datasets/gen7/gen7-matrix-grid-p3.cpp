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


vector<vector<int>> matrixPrefix2D_12(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_12(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_12(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_12(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_13(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_13(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_13(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_13(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_13(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_13(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_13(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_13(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_14(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_14(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_14(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_14(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_14(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_14(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_14(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_14(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_15(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_15(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_15(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_15(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_15(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_15(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_15(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_15(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_16(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_16(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_16(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_16(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_16(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_16(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_16(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_16(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_17(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_17(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_17(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_17(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_17(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_17(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_17(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_17(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_18(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_18(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_18(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_18(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_18(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_18(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }
