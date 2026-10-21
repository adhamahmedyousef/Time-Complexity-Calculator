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


int g8_harmonicSum_25(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_25(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_25(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_25(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_25(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_25(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_25(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_25(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_26(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_26(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_26(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_26(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_26(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_26(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_26(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_26(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_27(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_27(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_27(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_27(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_27(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_27(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_27(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_27(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_28(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_28(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_28(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_28(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_28(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_28(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_28(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_28(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_29(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_29(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_29(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_29(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_29(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_29(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_29(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_29(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }
