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


void g8_maskIter_35(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_35(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_35(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_35(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_35(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_35(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_35(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_35(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_36(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_36(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_36(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_36(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_36(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_36(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_36(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_36(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_37(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_37(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_37(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_37(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_37(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_37(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_37(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_37(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_38(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_38(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_38(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_38(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_38(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_38(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_38(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_38(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }

void g8_maskIter_39(int n) { int limit = 1 << n; for (int mask = 0; mask < limit; ++mask) { (void)mask; } }

int g8_maskCount_39(int n) { int cnt = 0; for (int mask = 0; mask < (1 << n); ++mask) cnt++; return cnt; }

void g8_maskScanBits_39(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int i = 0; i < n; ++i) if (mask & (1 << i)) { } }

int g8_bitIterate_39(int mask, int n) { int cnt = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) cnt++; return cnt; }

void g8_allSubmasks_39(int n) { for (int mask = 0; mask < (1 << n); ++mask) for (int sub = mask; sub > 0; sub = (sub - 1) & mask) { } }

vector<int> g8_maskVectorAlloc_39(int n) { vector<int> dp(1 << n, 0); for (int i = 0; i < (1 << n); ++i) dp[i] = i; return dp; }

int g8_clearLowBit_39(int x) { int count = 0; while (x > 0) { count++; x /= 2; } return count; }

int g8_singleMaskSweep_39(int n) { int total = 0; for (int i = 0; i < (1 << n); ++i) total += i; return total; }
