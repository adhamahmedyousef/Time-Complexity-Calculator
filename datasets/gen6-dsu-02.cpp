// Generated family: gen6-dsu-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int dsuCountSets_33(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_33(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_34(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_34(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_34(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_35(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_35(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_35(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_36(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_36(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_36(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_37(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_37(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_37(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_38(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_38(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_38(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_39(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_39(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_39(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_40(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_40(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_40(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_41(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_41(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_41(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_42(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_42(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_42(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_43(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_43(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_43(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_44(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_44(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_44(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_45(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_45(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_45(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_46(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_46(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_46(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_47(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_47(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_47(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_48(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_48(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_48(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_49(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_49(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_49(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_50(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_50(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_50(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_51(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_51(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_51(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_52(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_52(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_52(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_53(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_53(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_53(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_54(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_54(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_54(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_55(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_55(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_55(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_56(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_56(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_56(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_57(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_57(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_57(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_58(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_58(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_58(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_59(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_59(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_59(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_60(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_60(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_60(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_61(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_61(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_61(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_62(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_62(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_62(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_63(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_63(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_63(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_64(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_64(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_64(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_65(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_65(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
int dsuFindRoot_65(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
vector<int> dsuInitParent_66(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuCountSets_66(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
