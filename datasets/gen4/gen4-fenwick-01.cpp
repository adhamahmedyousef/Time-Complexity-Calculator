// Generated family: gen4-fenwick-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void fenwickPointUpdate_0(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_0(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_0(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_1(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_1(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_1(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_2(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_2(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_2(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_3(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_3(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_3(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_4(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_4(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_4(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_5(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_5(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_5(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_6(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_6(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_6(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_7(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_7(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_7(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_8(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_8(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_8(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_9(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_9(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_9(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_10(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_10(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_10(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_11(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_11(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_11(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_12(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_12(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_12(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_13(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_13(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_13(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_14(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_14(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_14(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_15(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_15(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_15(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_16(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_16(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_16(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_17(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_17(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_17(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_18(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_18(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_18(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_19(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_19(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_19(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
