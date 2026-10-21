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


void g8_maskIter_20(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_20(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_20(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_20(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_20(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_20(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_20(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_20(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_21(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_21(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_21(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_21(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_21(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_21(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_21(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_21(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_22(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_22(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_22(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_22(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_22(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_22(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_22(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_22(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_23(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_23(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_23(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_23(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_23(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_23(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_23(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_23(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_24(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_24(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_24(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_24(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_24(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_24(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_24(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_24(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }
