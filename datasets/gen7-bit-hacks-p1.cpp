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


bool bitIsPowerOfTwo_0(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_0(int x) { return x & (x - 1); }

int bitIsolateLowest_0(int x) { return x & (-x); }

int bitCountTrailingZeroes_0(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_0(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_0(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_0(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_0(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_1(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_1(int x) { return x & (x - 1); }

int bitIsolateLowest_1(int x) { return x & (-x); }

int bitCountTrailingZeroes_1(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_1(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_1(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_1(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_1(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_2(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_2(int x) { return x & (x - 1); }

int bitIsolateLowest_2(int x) { return x & (-x); }

int bitCountTrailingZeroes_2(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_2(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_2(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_2(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_2(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_3(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_3(int x) { return x & (x - 1); }

int bitIsolateLowest_3(int x) { return x & (-x); }

int bitCountTrailingZeroes_3(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_3(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_3(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_3(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_3(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_4(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_4(int x) { return x & (x - 1); }

int bitIsolateLowest_4(int x) { return x & (-x); }

int bitCountTrailingZeroes_4(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_4(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_4(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_4(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_4(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_5(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_5(int x) { return x & (x - 1); }

int bitIsolateLowest_5(int x) { return x & (-x); }

int bitCountTrailingZeroes_5(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }

int bitSingleNumberXor_5(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }

long long bitSubsetMaskScan_5(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }

vector<int> bitGrayCodeVec_5(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }

int bitCountOddBits_5(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }

bool bitIsPowerOfTwo_6(int x) { return x > 0 && (x & (x - 1)) == 0; }

int bitClearLowest_6(int x) { return x & (x - 1); }
