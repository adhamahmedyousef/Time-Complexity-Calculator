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


void g8_maskIter_5(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_5(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_5(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_5(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_5(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_5(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_5(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_5(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_6(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_6(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_6(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_6(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_6(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_6(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_6(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_6(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_7(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_7(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_7(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_7(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_7(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_7(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_7(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_7(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_8(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_8(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_8(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_8(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_8(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_8(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_8(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_8(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_9(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_9(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_9(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_9(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_9(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_9(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_9(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_9(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }
