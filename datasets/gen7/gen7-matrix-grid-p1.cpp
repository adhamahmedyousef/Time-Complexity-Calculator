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


bool matrixZeroCheck_0(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_0(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_0(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_0(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_0(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_0(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_0(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_0(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_1(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_1(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_1(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_1(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_1(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_1(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_1(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_1(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_2(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_2(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_2(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_2(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_2(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_2(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_2(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_2(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_3(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_3(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_3(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_3(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_3(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_3(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_3(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_3(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_4(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_4(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_4(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_4(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_4(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_4(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_4(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_4(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_5(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_5(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }

vector<vector<int>> matrixMultiplication_5(const vector<vector<int>>& A, const vector<vector<int>>& B) { int n = static_cast<int>(A.size()); vector<vector<int>> C(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int k = 0; k < n; ++k) for (int j = 0; j < n; ++j) C[i][j] += A[i][k] * B[k][j]; return C; }

void matrixTransposeInplace_5(vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(mat[i][j], mat[j][i]); }

vector<vector<int>> matrixPrefix2D_5(const vector<vector<int>>& grid) { int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size()); vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]; return pref; }

bool matrixSymmetricCheck_5(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (mat[i][j] != mat[j][i]) return false; return true; }

int matrixQueryLoopSequential_5(const vector<vector<int>>& mat, int q) { int n = static_cast<int>(mat.size()), total = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) total += mat[i][j]; int dummy = 0; while (q--) dummy += total; return dummy; }

vector<int> matrixRowMinimums_5(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); vector<int> mins(n); for (int i = 0; i < n; ++i) { int m = mat[i][0]; for (int val : mat[i]) m = min(m, val); mins[i] = m; } return mins; }

bool matrixZeroCheck_6(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (mat[i][j] != 0) return false; return true; }

int matrixDiagonalSum_6(const vector<vector<int>>& mat) { int n = static_cast<int>(mat.size()), s = 0; for (int i = 0; i < n; ++i) { s += mat[i][i]; if (i != n - 1 - i) s += mat[i][n - 1 - i]; } return s; }
