// Generated family: gen6-fenwick-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int fenwickPrefixSum_33(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_33(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_34(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_34(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_34(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_35(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_35(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_35(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_36(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_36(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_36(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_37(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_37(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_37(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_38(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_38(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_38(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_39(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_39(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_39(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_40(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_40(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_40(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_41(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_41(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_41(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_42(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_42(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_42(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_43(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_43(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_43(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_44(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_44(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_44(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_45(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_45(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_45(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_46(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_46(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_46(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_47(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_47(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_47(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_48(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_48(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_48(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_49(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_49(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_49(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_50(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_50(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_50(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_51(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_51(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_51(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_52(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_52(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_52(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_53(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_53(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_53(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_54(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_54(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_54(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_55(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_55(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_55(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_56(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_56(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_56(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_57(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_57(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_57(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_58(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_58(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_58(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_59(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_59(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_59(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_60(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_60(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_60(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_61(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_61(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_61(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_62(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_62(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_62(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_63(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_63(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_63(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_64(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_64(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_64(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_65(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_65(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
void fenwickScale_65(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
void fenwickPointUpdate_66(vector<int>& bit, int idx, int val) { int n = bit.size(); for (; idx < n; idx += idx & -idx) bit[idx] += val; }
int fenwickPrefixSum_66(const vector<int>& bit, int idx) { int s = 0; for (; idx > 0; idx -= idx & -idx) s += bit[idx]; return s; }
