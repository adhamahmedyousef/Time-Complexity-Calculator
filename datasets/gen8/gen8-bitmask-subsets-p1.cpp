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


void g8_maskIter_0(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_0(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_0(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_0(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_0(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_0(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_0(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_0(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_1(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_1(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_1(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_1(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_1(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_1(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_1(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_1(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_2(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_2(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_2(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_2(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_2(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_2(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_2(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_2(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_3(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_3(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_3(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_3(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_3(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_3(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_3(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_3(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_4(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_4(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_4(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_4(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_4(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_4(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_4(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_4(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }
