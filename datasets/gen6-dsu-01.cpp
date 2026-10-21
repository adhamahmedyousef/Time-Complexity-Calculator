// Generated family: gen6-dsu-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> dsuInitParent_0(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_0(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_0(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_1(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_1(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_1(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_2(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_2(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_2(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_3(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_3(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_3(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_4(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_4(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_4(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_5(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_5(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_5(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_6(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_6(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_6(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_7(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_7(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_7(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_8(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_8(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_8(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_9(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_9(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_9(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_10(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_10(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_10(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_11(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_11(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_11(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_12(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_12(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_12(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_13(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_13(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_13(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_14(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_14(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_14(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_15(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_15(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_15(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_16(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_16(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_16(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_17(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_17(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_17(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_18(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_18(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_18(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_19(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_19(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_19(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_20(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_20(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_20(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_21(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_21(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_21(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_22(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_22(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_22(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_23(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_23(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_23(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_24(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_24(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_24(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_25(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_25(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_25(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_26(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_26(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_26(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_27(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_27(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_27(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_28(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_28(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_28(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_29(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_29(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_29(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_30(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_30(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_30(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_31(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_31(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_31(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_32(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_32(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_32(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_33(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
