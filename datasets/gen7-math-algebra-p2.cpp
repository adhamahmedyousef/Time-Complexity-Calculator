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


long long triangularNestedQuadratic_6(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_6(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_6(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_6(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_6(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_6(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_7(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_7(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_7(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_7(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_7(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_7(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_7(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_7(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_8(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_8(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_8(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_8(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_8(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_8(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_8(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_8(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_9(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_9(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_9(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_9(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_9(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_9(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_9(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_9(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_10(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_10(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_10(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_10(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_10(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_10(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_10(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_10(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_11(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_11(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_11(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_11(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_11(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_11(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_11(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_11(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_12(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_12(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_12(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_12(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }
