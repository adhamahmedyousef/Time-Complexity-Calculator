#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int g8_treePreorder_25(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_25(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_25(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_25(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_25(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_25(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_25(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_25(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_26(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_26(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_26(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_26(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_26(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_26(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_26(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_26(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_27(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_27(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_27(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_27(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_27(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_27(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_27(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_27(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_28(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_28(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_28(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_28(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_28(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_28(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_28(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_28(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_29(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_29(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_29(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_29(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_29(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_29(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_29(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_29(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }
