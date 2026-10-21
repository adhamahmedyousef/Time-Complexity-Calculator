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


int geometricSeriesInner_0(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_0(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_0(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_0(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_0(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_0(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_0(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_0(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_1(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_1(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_1(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_1(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_1(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_1(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_1(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_1(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_2(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_2(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_2(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_2(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_2(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_2(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_2(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_2(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_3(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_3(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_3(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_3(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_3(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_3(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_3(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_3(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_4(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_4(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_4(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_4(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_4(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_4(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_4(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_4(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_5(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_5(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_5(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_5(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_5(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_5(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_5(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_5(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_6(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_6(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }
