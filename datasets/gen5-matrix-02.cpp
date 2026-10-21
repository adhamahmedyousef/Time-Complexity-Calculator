// Generated family: gen5-matrix-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> matrixSquareMul_20(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_20(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_20(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_20(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_20(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_21(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_21(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_21(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_21(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_21(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_22(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_22(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_22(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_22(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_22(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_23(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_23(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_23(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_23(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_23(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_24(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_24(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_24(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_24(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_24(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_25(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_25(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_25(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_25(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_25(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_26(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_26(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_26(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_26(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_26(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_27(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_27(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_27(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_27(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_27(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_28(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_28(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_28(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_28(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_28(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMul_29(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTranspose_29(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_29(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentity_29(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZero_29(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
