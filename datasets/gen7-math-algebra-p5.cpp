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


int geometricSeriesInner_25(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_25(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_25(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_25(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_25(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_25(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_25(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_25(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_26(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_26(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_26(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_26(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_26(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_26(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_26(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_26(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_27(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_27(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_27(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_27(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_27(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_27(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_27(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_27(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_28(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_28(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_28(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_28(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_28(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_28(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_28(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_28(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_29(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_29(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_29(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_29(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_29(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_29(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_29(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_29(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_30(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_30(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_30(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_30(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_30(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_30(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_30(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_30(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_31(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_31(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }
