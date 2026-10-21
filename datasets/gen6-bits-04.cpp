// Generated family: gen6-bits-04
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

unsigned int reverseBits32_27(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_27(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_27(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_27(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_27(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_27(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_27(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_27(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_28(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_28(int x) { return x & (x - 1); }
int isolateLowestSetBit_28(int x) { return x & (-x); }
unsigned int reverseBits32_28(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_28(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_28(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_28(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_28(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_28(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_28(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_28(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_29(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_29(int x) { return x & (x - 1); }
int isolateLowestSetBit_29(int x) { return x & (-x); }
unsigned int reverseBits32_29(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_29(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_29(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_29(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_29(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_29(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_29(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_29(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_30(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_30(int x) { return x & (x - 1); }
int isolateLowestSetBit_30(int x) { return x & (-x); }
unsigned int reverseBits32_30(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_30(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_30(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_30(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_30(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_30(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_30(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_30(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_31(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_31(int x) { return x & (x - 1); }
int isolateLowestSetBit_31(int x) { return x & (-x); }
unsigned int reverseBits32_31(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_31(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_31(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_31(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_31(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_31(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_31(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_31(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_32(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_32(int x) { return x & (x - 1); }
int isolateLowestSetBit_32(int x) { return x & (-x); }
unsigned int reverseBits32_32(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_32(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_32(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_32(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_32(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_32(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_32(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_32(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_33(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_33(int x) { return x & (x - 1); }
int isolateLowestSetBit_33(int x) { return x & (-x); }
unsigned int reverseBits32_33(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_33(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_33(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_33(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_33(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_33(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_33(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_33(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_34(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_34(int x) { return x & (x - 1); }
int isolateLowestSetBit_34(int x) { return x & (-x); }
unsigned int reverseBits32_34(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_34(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_34(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_34(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_34(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_34(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_34(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_34(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_35(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_35(int x) { return x & (x - 1); }
int isolateLowestSetBit_35(int x) { return x & (-x); }
unsigned int reverseBits32_35(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_35(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_35(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_35(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_35(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_35(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_35(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_35(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_36(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_36(int x) { return x & (x - 1); }
int isolateLowestSetBit_36(int x) { return x & (-x); }
unsigned int reverseBits32_36(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
