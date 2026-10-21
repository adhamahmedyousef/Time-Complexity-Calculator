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


int bitIsolateLowest_6(int x) { return x & (-x); }

int bitCountTrailingZeroes_6(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_6(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_6(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_6(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_6(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_7(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_7(int x) { return x & (x - 1); }

int bitIsolateLowest_7(int x) { return x & (-x); }

int bitCountTrailingZeroes_7(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_7(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_7(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_7(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_7(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_8(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_8(int x) { return x & (x - 1); }

int bitIsolateLowest_8(int x) { return x & (-x); }

int bitCountTrailingZeroes_8(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_8(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_8(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_8(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_8(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_9(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_9(int x) { return x & (x - 1); }

int bitIsolateLowest_9(int x) { return x & (-x); }

int bitCountTrailingZeroes_9(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_9(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_9(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_9(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_9(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_10(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_10(int x) { return x & (x - 1); }

int bitIsolateLowest_10(int x) { return x & (-x); }

int bitCountTrailingZeroes_10(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_10(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_10(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_10(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_10(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_11(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_11(int x) { return x & (x - 1); }

int bitIsolateLowest_11(int x) { return x & (-x); }

int bitCountTrailingZeroes_11(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_11(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_11(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_11(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_11(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_12(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_12(int x) { return x & (x - 1); }

int bitIsolateLowest_12(int x) { return x & (-x); }

int bitCountTrailingZeroes_12(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
