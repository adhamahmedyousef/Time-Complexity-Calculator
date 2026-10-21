// Generated family: gen2-bits-01
// Labels from first principles.
using namespace std;

int popcount_0(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool subsetSum_0(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCode_0(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
int popcount_1(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool subsetSum_1(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCode_1(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
int popcount_2(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool subsetSum_2(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCode_2(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
int popcount_3(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool subsetSum_3(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCode_3(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
int popcount_4(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool subsetSum_4(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCode_4(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
int popcount_5(unsigned int x) { int c = 0; while (x) { c += x & 1; x >>= 1; } return c; }
bool subsetSum_5(const vector<int>& a, int t) { int n = a.size(); for (int mask = 0; mask < (1 << n); ++mask) { int sum = 0; for (int i = 0; i < n; ++i) if (mask & (1 << i)) sum += a[i]; if (sum == t) return true; } return false; }
vector<int> grayCode_5(int n) { vector<int> result; for (int i = 0; i < (1 << n); ++i) result.push_back(i ^ (i >> 1)); return result; }
