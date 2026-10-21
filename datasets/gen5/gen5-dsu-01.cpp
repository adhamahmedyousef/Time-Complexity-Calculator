// Generated family: gen5-dsu-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> dsuParentVector_0(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_0(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_0(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_1(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_1(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_1(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_2(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_2(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_2(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_3(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_3(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_3(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_4(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_4(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_4(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_5(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_5(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_5(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_6(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_6(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_6(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_7(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_7(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_7(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_8(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_8(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_8(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_9(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_9(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_9(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_10(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_10(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_10(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_11(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_11(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_11(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_12(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_12(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_12(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_13(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_13(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_13(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_14(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_14(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_14(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_15(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_15(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_15(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_16(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_16(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_16(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_17(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_17(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_17(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_18(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_18(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_18(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_19(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_19(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_19(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_20(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_20(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_20(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_21(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_21(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_21(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_22(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_22(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_22(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_23(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_23(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_23(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_24(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_24(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_24(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_25(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_25(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_25(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_26(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_26(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_26(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_27(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_27(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_27(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_28(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_28(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_28(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
vector<int> dsuParentVector_29(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }
int dsuComponentCount_29(const vector<int>& p) { int c = 0; for (int i = 0; i < (int)p.size(); ++i) if (p[i] == i) ++c; return c; }
int dsuPathCompression_29(vector<int>& p, int x) { int r = x; while (r != p[r]) r = p[r]; int curr = x; while (curr != r) { int nxt = p[curr]; p[curr] = r; curr = nxt; } return r; }
