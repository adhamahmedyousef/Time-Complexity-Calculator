#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int g8_harmonicSum_20(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_20(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_20(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_20(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_20(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_20(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_20(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_20(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_21(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_21(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_21(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_21(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_21(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_21(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_21(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_21(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_22(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_22(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_22(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_22(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_22(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_22(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_22(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_22(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_23(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_23(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_23(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_23(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_23(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_23(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_23(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_23(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_24(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_24(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_24(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_24(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_24(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_24(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_24(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_24(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }
