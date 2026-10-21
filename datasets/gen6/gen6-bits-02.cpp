// Generated family: gen6-bits-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int clearLowestSetBit_9(int x) { return x & (x - 1); }
int isolateLowestSetBit_9(int x) { return x & (-x); }
unsigned int reverseBits32_9(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_9(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_9(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_9(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_9(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_9(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_9(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_9(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_10(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_10(int x) { return x & (x - 1); }
int isolateLowestSetBit_10(int x) { return x & (-x); }
unsigned int reverseBits32_10(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_10(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_10(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_10(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_10(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_10(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_10(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_10(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_11(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_11(int x) { return x & (x - 1); }
int isolateLowestSetBit_11(int x) { return x & (-x); }
unsigned int reverseBits32_11(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_11(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_11(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_11(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_11(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_11(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_11(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_11(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_12(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_12(int x) { return x & (x - 1); }
int isolateLowestSetBit_12(int x) { return x & (-x); }
unsigned int reverseBits32_12(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_12(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_12(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_12(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_12(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_12(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_12(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_12(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_13(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_13(int x) { return x & (x - 1); }
int isolateLowestSetBit_13(int x) { return x & (-x); }
unsigned int reverseBits32_13(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_13(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_13(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_13(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_13(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_13(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_13(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_13(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_14(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_14(int x) { return x & (x - 1); }
int isolateLowestSetBit_14(int x) { return x & (-x); }
unsigned int reverseBits32_14(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_14(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_14(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_14(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_14(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_14(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_14(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_14(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_15(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_15(int x) { return x & (x - 1); }
int isolateLowestSetBit_15(int x) { return x & (-x); }
unsigned int reverseBits32_15(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_15(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_15(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_15(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_15(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_15(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_15(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_15(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_16(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_16(int x) { return x & (x - 1); }
int isolateLowestSetBit_16(int x) { return x & (-x); }
unsigned int reverseBits32_16(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_16(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_16(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_16(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_16(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_16(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_16(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_16(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_17(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_17(int x) { return x & (x - 1); }
int isolateLowestSetBit_17(int x) { return x & (-x); }
unsigned int reverseBits32_17(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_17(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_17(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_17(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_17(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_17(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_17(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_17(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_18(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_18(int x) { return x & (x - 1); }
