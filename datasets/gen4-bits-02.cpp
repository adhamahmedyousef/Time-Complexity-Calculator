// Generated family: gen4-bits-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int countOddBits_12(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_12(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_12(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_12(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
bool isPowerOfTwo_13(int x) { return x > 0 && (x & (x - 1)) == 0; }
unsigned int reverseBits32_13(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
long long subsetMaskScan_13(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_13(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
int countOddBits_13(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_13(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_13(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_13(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
bool isPowerOfTwo_14(int x) { return x > 0 && (x & (x - 1)) == 0; }
unsigned int reverseBits32_14(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
long long subsetMaskScan_14(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_14(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
int countOddBits_14(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_14(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_14(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_14(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
bool isPowerOfTwo_15(int x) { return x > 0 && (x & (x - 1)) == 0; }
unsigned int reverseBits32_15(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
long long subsetMaskScan_15(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_15(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
int countOddBits_15(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_15(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_15(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_15(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
bool isPowerOfTwo_16(int x) { return x > 0 && (x & (x - 1)) == 0; }
unsigned int reverseBits32_16(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
long long subsetMaskScan_16(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_16(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
int countOddBits_16(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_16(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_16(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_16(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
bool isPowerOfTwo_17(int x) { return x > 0 && (x & (x - 1)) == 0; }
unsigned int reverseBits32_17(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
long long subsetMaskScan_17(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_17(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
int countOddBits_17(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_17(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_17(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_17(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
bool isPowerOfTwo_18(int x) { return x > 0 && (x & (x - 1)) == 0; }
unsigned int reverseBits32_18(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
long long subsetMaskScan_18(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_18(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
int countOddBits_18(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_18(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_18(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_18(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
bool isPowerOfTwo_19(int x) { return x > 0 && (x & (x - 1)) == 0; }
unsigned int reverseBits32_19(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
long long subsetMaskScan_19(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_19(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
int countOddBits_19(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
int highestSetBitPos_19(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_19(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countTrailingZeroes_19(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
