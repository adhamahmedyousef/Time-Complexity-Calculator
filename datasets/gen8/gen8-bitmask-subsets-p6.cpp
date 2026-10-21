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


void g8_maskIter_25(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_25(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_25(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_25(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_25(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_25(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_25(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_25(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_26(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_26(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_26(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_26(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_26(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_26(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_26(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_26(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_27(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_27(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_27(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_27(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_27(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_27(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_27(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_27(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_28(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_28(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_28(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_28(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_28(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_28(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_28(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_28(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_29(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_29(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_29(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_29(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_29(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_29(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_29(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_29(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }
