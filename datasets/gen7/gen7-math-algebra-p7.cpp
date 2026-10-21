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


long long cubicTripleLoop_37(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_37(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_37(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_37(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_38(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_38(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_38(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_38(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_38(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_38(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_38(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_38(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }

int geometricSeriesInner_39(int n) { int s = 0; for (int step = n; step > 0; step /= 2) { for (int i = 0; i < step; ++i) ++s; } return s; }

long long harmonicSeriesDouble_39(int n) { long long s = 0; for (int i = 1; i <= n; ++i) { for (int j = i; j <= n; j += i) s += j; } return s; }

long long triangularNestedQuadratic_39(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) s += (i ^ j); return s; }

long long strictSquareDoubleLoop_39(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s += (i + j); return s; }

long long cubicTripleLoop_39(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) s += i * j * k; return s; }

int halvingNestedLogLog_39(int n) { int c = 0; for (int i = 1; i < n; i *= 2) for (int j = 1; j < n; j *= 2) ++c; return c; }

long long linearOutsideLogarithmic_39(int n) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 1; j < n; j *= 2) s += (i + j); return s; }

long long twoIndependentDimensionsNM_39(int n, int m) { long long s = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s += (i + j); return s; }
