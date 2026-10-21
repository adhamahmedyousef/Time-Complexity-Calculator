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


int g8_harmonicSum_10(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_10(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_10(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_10(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_10(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_10(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_10(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_10(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_11(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_11(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_11(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_11(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_11(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_11(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_11(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_11(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_12(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_12(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_12(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_12(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_12(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_12(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_12(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_12(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_13(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_13(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_13(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_13(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_13(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_13(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_13(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_13(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_14(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_14(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_14(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_14(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_14(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_14(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_14(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_14(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }
