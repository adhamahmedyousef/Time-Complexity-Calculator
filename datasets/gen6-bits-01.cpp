// Generated family: gen6-bits-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool isPowerOfTwo_0(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_0(int x) { return x & (x - 1); }
int isolateLowestSetBit_0(int x) { return x & (-x); }
unsigned int reverseBits32_0(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_0(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_0(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_0(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_0(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_0(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_0(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_0(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_1(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_1(int x) { return x & (x - 1); }
int isolateLowestSetBit_1(int x) { return x & (-x); }
unsigned int reverseBits32_1(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_1(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_1(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_1(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_1(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_1(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_1(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_1(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_2(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_2(int x) { return x & (x - 1); }
int isolateLowestSetBit_2(int x) { return x & (-x); }
unsigned int reverseBits32_2(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_2(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_2(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_2(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_2(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_2(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_2(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_2(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_3(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_3(int x) { return x & (x - 1); }
int isolateLowestSetBit_3(int x) { return x & (-x); }
unsigned int reverseBits32_3(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_3(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_3(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_3(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_3(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_3(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_3(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_3(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_4(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_4(int x) { return x & (x - 1); }
int isolateLowestSetBit_4(int x) { return x & (-x); }
unsigned int reverseBits32_4(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_4(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_4(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_4(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_4(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_4(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_4(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_4(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_5(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_5(int x) { return x & (x - 1); }
int isolateLowestSetBit_5(int x) { return x & (-x); }
unsigned int reverseBits32_5(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_5(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_5(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_5(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_5(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_5(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_5(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_5(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_6(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_6(int x) { return x & (x - 1); }
int isolateLowestSetBit_6(int x) { return x & (-x); }
unsigned int reverseBits32_6(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_6(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_6(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_6(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_6(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_6(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_6(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_6(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_7(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_7(int x) { return x & (x - 1); }
int isolateLowestSetBit_7(int x) { return x & (-x); }
unsigned int reverseBits32_7(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_7(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_7(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_7(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_7(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_7(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_7(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_7(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_8(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_8(int x) { return x & (x - 1); }
int isolateLowestSetBit_8(int x) { return x & (-x); }
unsigned int reverseBits32_8(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_8(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_8(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_8(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_8(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_8(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_8(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_8(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_9(int x) { return x > 0 && (x & (x - 1)) == 0; }
