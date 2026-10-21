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


long long cubicTripleLoop_12(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_12(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_12(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_12(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_13(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_13(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_13(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_13(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_13(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_13(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_13(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_13(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_14(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_14(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_14(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_14(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_14(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_14(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_14(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_14(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_15(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_15(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_15(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_15(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_15(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_15(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_15(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_15(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_16(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_16(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_16(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_16(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_16(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_16(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_16(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_16(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_17(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_17(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_17(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_17(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_17(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_17(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_17(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_17(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_18(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_18(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_18(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_18(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_18(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_18(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }
