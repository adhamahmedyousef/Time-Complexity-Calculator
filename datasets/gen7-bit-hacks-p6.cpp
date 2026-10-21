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


int bitIsolateLowest_31(int x) { return x & (-x); }

int bitCountTrailingZeroes_31(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_31(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_31(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_31(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_31(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_32(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_32(int x) { return x & (x - 1); }

int bitIsolateLowest_32(int x) { return x & (-x); }

int bitCountTrailingZeroes_32(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_32(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_32(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_32(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_32(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_33(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_33(int x) { return x & (x - 1); }

int bitIsolateLowest_33(int x) { return x & (-x); }

int bitCountTrailingZeroes_33(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_33(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_33(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_33(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_33(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_34(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_34(int x) { return x & (x - 1); }

int bitIsolateLowest_34(int x) { return x & (-x); }

int bitCountTrailingZeroes_34(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_34(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_34(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_34(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_34(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_35(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_35(int x) { return x & (x - 1); }

int bitIsolateLowest_35(int x) { return x & (-x); }

int bitCountTrailingZeroes_35(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_35(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_35(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_35(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_35(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_36(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_36(int x) { return x & (x - 1); }

int bitIsolateLowest_36(int x) { return x & (-x); }

int bitCountTrailingZeroes_36(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_36(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_36(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_36(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_36(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_37(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_37(int x) { return x & (x - 1); }

int bitIsolateLowest_37(int x) { return x & (-x); }

int bitCountTrailingZeroes_37(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
