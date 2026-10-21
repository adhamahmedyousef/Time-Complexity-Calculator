// Generated family: gen4-matrix-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> matrixSquareMultiply_0(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_0(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_0(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_0(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_0(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_1(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_1(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_1(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_1(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_1(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_2(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_2(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_2(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_2(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_2(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_3(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_3(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_3(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_3(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_3(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_4(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_4(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_4(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_4(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_4(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_5(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_5(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_5(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_5(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_5(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_6(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_6(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_6(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_6(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_6(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_7(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_7(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_7(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_7(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_7(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_8(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_8(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_8(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_8(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_8(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_9(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_9(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_9(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_9(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_9(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_10(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_10(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_10(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_10(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_10(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_11(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_11(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_11(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_11(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_11(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_12(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_12(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_12(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_12(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_12(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_13(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_13(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_13(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_13(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_13(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_14(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_14(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_14(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_14(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_14(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_15(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_15(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_15(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_15(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_15(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_16(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_16(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_16(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_16(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_16(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_17(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_17(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_17(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_17(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_17(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_18(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_18(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_18(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_18(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_18(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
vector<vector<int>> matrixSquareMultiply_19(const vector<vector<int>>& a, const vector<vector<int>>& b) { int n = a.size(); vector<vector<int>> c(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j]; return c; }
void matrixTransposeSquare_19(vector<vector<int>>& a) { int n = a.size(); for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) swap(a[i][j], a[j][i]); }
vector<int> matrixVectorMul_19(const vector<vector<int>>& a, const vector<int>& x) { int n = a.size(), m = a[0].size(); vector<int> res(n, 0); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i] += a[i][j] * x[j]; return res; }
vector<vector<int>> matrixIdentityInit_19(int n) { vector<vector<int>> id(n, vector<int>(n, 0)); for (int i = 0; i < n; ++i) id[i][i] = 1; return id; }
void matrixZeroOut_19(vector<vector<int>>& a) { int n = a.size(), m = a[0].size(); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0; }
