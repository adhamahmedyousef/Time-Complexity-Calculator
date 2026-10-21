// Generated family: gen6-matrix-03
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> matrixSquareMultiply_28(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_28(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_28(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_29(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_29(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_29(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_29(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_29(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_29(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_29(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_30(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_30(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_30(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_30(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_30(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_30(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_30(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_31(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_31(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_31(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_31(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_31(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_31(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_31(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_32(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_32(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_32(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_32(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_32(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_32(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_32(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_33(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_33(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_33(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_33(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_33(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_33(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_33(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_34(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_34(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_34(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_34(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_34(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_34(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_34(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_35(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_35(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_35(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_35(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_35(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_35(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_35(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_36(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_36(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_36(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_36(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_36(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_36(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_36(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_37(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_37(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_37(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_37(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_37(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_37(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_37(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_38(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_38(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_38(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_38(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_38(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_38(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_38(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_39(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_39(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_39(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_39(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_39(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_39(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_39(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_40(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_40(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_40(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_40(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_40(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_40(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_40(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_41(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_41(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_41(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_41(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_41(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_41(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_41(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_42(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_42(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_42(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_42(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_42(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_42(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
