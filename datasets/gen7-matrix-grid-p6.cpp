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


vector<vector<int>> matrixMultiplication_31(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_31(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_31(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_31(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_31(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_31(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_32(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_32(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_32(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_32(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_32(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_32(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_32(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_32(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_33(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_33(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_33(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_33(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_33(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_33(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_33(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_33(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_34(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_34(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_34(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_34(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_34(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_34(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_34(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_34(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_35(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_35(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_35(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_35(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_35(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_35(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_35(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_35(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_36(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_36(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_36(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_36(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_36(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_36(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_36(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_36(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_37(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_37(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_37(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_37(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }
