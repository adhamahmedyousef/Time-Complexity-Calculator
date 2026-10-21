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


int g8_harmonicSum_35(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_35(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_35(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_35(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_35(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_35(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_35(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_35(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_36(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_36(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_36(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_36(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_36(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_36(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_36(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_36(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_37(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_37(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_37(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_37(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_37(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_37(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_37(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_37(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_38(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_38(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_38(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_38(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_38(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_38(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_38(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_38(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }

int g8_harmonicSum_39(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

int g8_harmonicCount_39(int n) { int cnt = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) cnt++; return cnt; }

vector<int> g8_harmonicDivisors_39(int n) { vector<int> divs(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) divs[j]++; return divs; }

void g8_harmonicAlloc_39(int n) { vector<int> table(n + 1, 0); for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) table[j] += i; }

void g8_harmonicOdd_39(int n) { for (int i = 1; i <= n; i += 2) for (int j = i; j <= n; j += i) { } }

int g8_harmonicHalf_39(int n) { int s = 0; for (int i = 1; i <= n / 2; ++i) for (int j = i; j <= n; j += i) s += j; return s; }

int g8_harmonicPairs_39(int n) { int p = 0; for (int i = 2; i <= n; ++i) for (int j = i; j <= n; j += i) p += 1; return p; }

int g8_harmonicFilter_39(int n) { int res = 0; for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) if (j % 2 == 0) res++; return res; }
