// Generated family: gen4-dsu-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> dsuInitParent_0(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_0(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_0(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_1(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_1(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_1(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_2(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_2(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_2(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_3(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_3(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_3(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_4(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_4(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_4(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_5(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_5(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_5(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_6(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_6(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_6(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_7(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_7(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_7(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_8(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_8(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_8(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_9(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_9(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_9(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_10(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_10(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_10(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_11(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_11(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_11(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_12(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_12(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_12(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_13(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_13(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_13(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_14(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_14(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_14(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_15(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_15(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_15(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_16(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_16(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_16(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_17(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_17(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_17(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_18(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_18(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_18(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
vector<int> dsuInitParent_19(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }
int dsuFindRoot_19(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
int dsuCountSets_19(const vector<int>& parent) { int n = parent.size(), sets = 0; for (int i = 0; i < n; ++i) if (parent[i] == i) ++sets; return sets; }
