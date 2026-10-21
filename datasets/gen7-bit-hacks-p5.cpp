#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


bool bitIsPowerOfTwo_25(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_25(int x) { return x & (x - 1); }

int bitIsolateLowest_25(int x) { return x & (-x); }

int bitCountTrailingZeroes_25(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_25(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_25(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_25(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_25(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_26(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_26(int x) { return x & (x - 1); }

int bitIsolateLowest_26(int x) { return x & (-x); }

int bitCountTrailingZeroes_26(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_26(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_26(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_26(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_26(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_27(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_27(int x) { return x & (x - 1); }

int bitIsolateLowest_27(int x) { return x & (-x); }

int bitCountTrailingZeroes_27(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_27(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_27(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_27(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_27(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_28(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_28(int x) { return x & (x - 1); }

int bitIsolateLowest_28(int x) { return x & (-x); }

int bitCountTrailingZeroes_28(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_28(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_28(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_28(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_28(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_29(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_29(int x) { return x & (x - 1); }

int bitIsolateLowest_29(int x) { return x & (-x); }

int bitCountTrailingZeroes_29(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_29(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_29(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_29(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_29(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_30(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_30(int x) { return x & (x - 1); }

int bitIsolateLowest_30(int x) { return x & (-x); }

int bitCountTrailingZeroes_30(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_30(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_30(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_30(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_30(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_31(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_31(int x) { return x & (x - 1); }
