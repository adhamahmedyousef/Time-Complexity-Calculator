// Generated family: gen6-matrix-04
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool matrixSymmetricCheck_42(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_43(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_43(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_43(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_43(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_43(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_43(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_43(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_44(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_44(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_44(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_44(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_44(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_44(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_44(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_45(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_45(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_45(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_45(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_45(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_45(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_45(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_46(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_46(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_46(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_46(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_46(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_46(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_46(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_47(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_47(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_47(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_47(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_47(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_47(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_47(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_48(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_48(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_48(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_48(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_48(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_48(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_48(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_49(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_49(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_49(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_49(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_49(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_49(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_49(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_50(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_50(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_50(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_50(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_50(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_50(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_50(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_51(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_51(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_51(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_51(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_51(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_51(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_51(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_52(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_52(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_52(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_52(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_52(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_52(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_52(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_53(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_53(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_53(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_53(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_53(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_53(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_53(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_54(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_54(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_54(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_54(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_54(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_54(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_54(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_55(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_55(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_55(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_55(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_55(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_55(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_55(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_56(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_56(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<int> matrixVectorMul_56(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
void matrixTransposeSquare_56(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<vector<int>> matrixSquareMultiply_56(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
long long matrixTraceDiagonal_56(const vector<vector<int>>& a) { int n = a.size(); long long tr = 0; for (int i = 0; i < n; ++i) tr += a[i][i]; return tr; }
bool matrixSymmetricCheck_56(const vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i][j] != a[j][i]) return false; return true; }
vector<vector<int>> matrixIdentityInit_57(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
