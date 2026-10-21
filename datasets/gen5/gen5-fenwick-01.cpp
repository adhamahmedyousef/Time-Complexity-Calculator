// Generated family: gen5-fenwick-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void fenwickAddPoint_0(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_0(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_0(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_1(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_1(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_1(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_2(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_2(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_2(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_3(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_3(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_3(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_4(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_4(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_4(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_5(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_5(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_5(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_6(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_6(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_6(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_7(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_7(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_7(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_8(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_8(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_8(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_9(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_9(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_9(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_10(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_10(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_10(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_11(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_11(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_11(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_12(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_12(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_12(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_13(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_13(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_13(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_14(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_14(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_14(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_15(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_15(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_15(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_16(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_16(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_16(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_17(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_17(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_17(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_18(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_18(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_18(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_19(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_19(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_19(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_20(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_20(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_20(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_21(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_21(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_21(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_22(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_22(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_22(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_23(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_23(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_23(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_24(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_24(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_24(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_25(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_25(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_25(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_26(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_26(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_26(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_27(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_27(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_27(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_28(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_28(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_28(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
void fenwickAddPoint_29(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickQuerySum_29(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickMultiplyAll_29(vector<int>& bit, int mul) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= mul; }
