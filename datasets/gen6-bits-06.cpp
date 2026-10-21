// Generated family: gen6-bits-06
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int countTrailingZeroes_45(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_45(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_45(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_45(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_45(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_45(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_46(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_46(int x) { return x & (x - 1); }
int isolateLowestSetBit_46(int x) { return x & (-x); }
unsigned int reverseBits32_46(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_46(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_46(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_46(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_46(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_46(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_46(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_46(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_47(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_47(int x) { return x & (x - 1); }
int isolateLowestSetBit_47(int x) { return x & (-x); }
unsigned int reverseBits32_47(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_47(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_47(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_47(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_47(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_47(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_47(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_47(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_48(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_48(int x) { return x & (x - 1); }
int isolateLowestSetBit_48(int x) { return x & (-x); }
unsigned int reverseBits32_48(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_48(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_48(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_48(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_48(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_48(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_48(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_48(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_49(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_49(int x) { return x & (x - 1); }
int isolateLowestSetBit_49(int x) { return x & (-x); }
unsigned int reverseBits32_49(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_49(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_49(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_49(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_49(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_49(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_49(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_49(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_50(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_50(int x) { return x & (x - 1); }
int isolateLowestSetBit_50(int x) { return x & (-x); }
unsigned int reverseBits32_50(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_50(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_50(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_50(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_50(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_50(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_50(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_50(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_51(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_51(int x) { return x & (x - 1); }
int isolateLowestSetBit_51(int x) { return x & (-x); }
unsigned int reverseBits32_51(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_51(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_51(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_51(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_51(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_51(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_51(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_51(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_52(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_52(int x) { return x & (x - 1); }
int isolateLowestSetBit_52(int x) { return x & (-x); }
unsigned int reverseBits32_52(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_52(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_52(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_52(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_52(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_52(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_52(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_52(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_53(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_53(int x) { return x & (x - 1); }
int isolateLowestSetBit_53(int x) { return x & (-x); }
unsigned int reverseBits32_53(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_53(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_53(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_53(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_53(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_53(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_53(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_53(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_54(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_54(int x) { return x & (x - 1); }
int isolateLowestSetBit_54(int x) { return x & (-x); }
unsigned int reverseBits32_54(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_54(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_54(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
