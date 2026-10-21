// Generated family: gen6-bits-08
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int singleNumberXor_63(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_63(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_63(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_63(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_64(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_64(int x) { return x & (x - 1); }
int isolateLowestSetBit_64(int x) { return x & (-x); }
unsigned int reverseBits32_64(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_64(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_64(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_64(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_64(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_64(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_64(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_64(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_65(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_65(int x) { return x & (x - 1); }
int isolateLowestSetBit_65(int x) { return x & (-x); }
unsigned int reverseBits32_65(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_65(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_65(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_65(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_65(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_65(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_65(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_65(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
bool isPowerOfTwo_66(int x) { return x > 0 && (x & (x - 1)) == 0; }
int clearLowestSetBit_66(int x) { return x & (x - 1); }
int isolateLowestSetBit_66(int x) { return x & (-x); }
unsigned int reverseBits32_66(unsigned int x) { unsigned int r = 0; for (int i = 0; i < 32; ++i) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int popcount32Loop_66(unsigned int x) { int c = 0; for (int i = 0; i < 32; ++i) { c += (x & 1); x >>= 1; } return c; }
int countTrailingZeroes_66(unsigned int n) { int c = 0; while ((n & 1) == 0 && n > 0) { ++c; n >>= 1; } return c; }
int highestSetBitPos_66(int n) { int pos = 0; while (n > 1) { n >>= 1; ++pos; } return pos; }
int singleNumberXor_66(const vector<int>& a) { int x = 0; for (int v : a) x ^= v; return x; }
int countOddBits_66(const vector<int>& a) { int cnt = 0; for (int x : a) if (x & 1) ++cnt; return cnt; }
long long subsetMaskScan_66(int n) { long long s = 0; for (int mask = 0; mask < (1 << n); ++mask) s += mask; return s; }
vector<int> grayCodeVec_66(int n) { vector<int> res; for (int i = 0; i < (1 << n); ++i) res.push_back(i ^ (i >> 1)); return res; }
