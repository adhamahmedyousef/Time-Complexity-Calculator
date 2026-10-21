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


int bitSingleNumberXor_12(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_12(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_12(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_12(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_13(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_13(int x) { return x & (x - 1); }

int bitIsolateLowest_13(int x) { return x & (-x); }

int bitCountTrailingZeroes_13(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_13(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_13(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_13(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_13(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_14(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_14(int x) { return x & (x - 1); }

int bitIsolateLowest_14(int x) { return x & (-x); }

int bitCountTrailingZeroes_14(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_14(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_14(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_14(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_14(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_15(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_15(int x) { return x & (x - 1); }

int bitIsolateLowest_15(int x) { return x & (-x); }

int bitCountTrailingZeroes_15(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_15(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_15(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_15(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_15(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_16(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_16(int x) { return x & (x - 1); }

int bitIsolateLowest_16(int x) { return x & (-x); }

int bitCountTrailingZeroes_16(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_16(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_16(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_16(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_16(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_17(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_17(int x) { return x & (x - 1); }

int bitIsolateLowest_17(int x) { return x & (-x); }

int bitCountTrailingZeroes_17(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_17(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_17(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_17(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_17(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_18(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_18(int x) { return x & (x - 1); }

int bitIsolateLowest_18(int x) { return x & (-x); }

int bitCountTrailingZeroes_18(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_18(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_18(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
