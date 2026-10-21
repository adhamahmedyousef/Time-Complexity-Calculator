// Generated family: gen6-fenwick-01
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
void fenwickPointUpdate_20(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_20(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_20(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_21(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_21(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_21(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_22(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_22(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_22(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_23(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_23(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_23(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_24(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_24(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_24(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_25(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_25(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_25(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_26(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_26(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_26(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_27(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_27(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_27(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_28(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_28(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_28(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_29(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_29(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_29(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_30(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_30(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_30(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_31(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_31(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_31(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_32(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_32(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_32(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_33(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
