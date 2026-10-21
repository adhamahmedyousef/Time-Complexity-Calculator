// Generated family: gen3-bits3-01
// Labels from first principles.
using namespace std;

int popcount_0(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_0(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_0(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_0(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_0(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_0(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_0(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_0(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_0(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_0(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
int popcount_1(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_1(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_1(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_1(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_1(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_1(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_1(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_1(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_1(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_1(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
int popcount_2(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_2(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_2(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_2(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_2(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_2(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_2(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_2(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_2(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_2(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
int popcount_3(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_3(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_3(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_3(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_3(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_3(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_3(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_3(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_3(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_3(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
int popcount_4(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_4(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_4(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_4(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_4(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_4(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_4(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_4(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_4(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_4(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
int popcount_5(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_5(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_5(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_5(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_5(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_5(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_5(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_5(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_5(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_5(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
int popcount_6(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_6(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_6(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_6(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_6(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_6(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_6(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_6(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_6(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_6(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
int popcount_7(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool isPowerOfTwoLoop_7(int x) { if (x <= 0) return false; while (x) { if (x == 1) return true; if (x % 2 != 0) return false; x >>= 1; } return false; }
unsigned int reverseBitsLoop_7(unsigned int x) { unsigned int r = 0; while (x) { r = (r << 1) | (x & 1); x >>= 1; } return r; }
int countBitsRange_7(int n) { int total = 0; for (int i = 1; i <= n; ++i) { int x = i; while (x) { total += x & 1; x >>= 1; } } return total; }
bool subsetSumBrute_7(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCodeBuild_7(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
long long subsetEnumCount_7(int n) { long long c = 0; for (int mask = 0; mask < (1 << n); ++mask) ++c; return c; }
vector<int> countingBitsDP_7(int n) { vector<int> r(n + 1, 0); for (int i = 1; i <= n; ++i) r[i] = r[i >> 1] + (i & 1); return r; }
int xorRange_7(int n) { int x = 0; for (int i = 1; i <= n; ++i) x ^= i; return x; }
int bitAndRange_7(const vector<int>& a) { int x = a[0]; for (int i = 1; i < (int)a.size(); ++i) x &= a[i]; return x; }
