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


int g8_harmonicSum_15(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_15(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_15(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_15(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_15(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_15(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_15(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_15(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_16(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_16(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_16(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_16(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_16(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_16(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_16(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_16(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_17(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_17(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_17(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_17(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_17(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_17(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_17(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_17(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_18(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_18(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_18(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_18(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_18(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_18(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_18(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_18(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_19(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_19(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_19(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_19(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_19(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_19(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_19(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_19(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }
