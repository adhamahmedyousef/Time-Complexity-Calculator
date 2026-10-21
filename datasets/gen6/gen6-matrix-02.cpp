// Generated family: gen6-matrix-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> matrixVectorMul_14(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_14(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_14(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_14(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_14(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_15(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_15(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_15(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_15(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_15(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_15(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_15(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_16(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_16(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_16(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_16(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_16(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_16(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_16(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_17(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_17(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_17(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_17(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_17(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_17(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_17(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_18(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_18(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_18(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_18(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_18(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_18(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_18(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_19(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_19(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_19(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_19(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_19(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_19(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_19(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_20(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_20(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_20(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_20(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_20(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_20(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_20(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_21(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_21(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_21(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_21(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_21(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_21(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_21(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_22(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_22(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_22(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_22(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_22(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_22(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_22(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_23(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_23(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_23(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_23(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_23(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_23(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_23(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_24(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_24(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_24(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_24(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_24(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_24(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_24(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_25(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_25(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_25(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_25(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_25(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_25(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_25(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_26(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_26(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_26(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_26(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_26(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_26(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_26(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_27(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_27(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_27(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_27(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_27(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_27(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_27(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_28(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_28(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_28(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_28(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
