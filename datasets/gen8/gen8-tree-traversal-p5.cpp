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


int g8_treePreorder_20(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_20(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_20(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_20(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_20(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_20(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_20(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_20(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_21(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_21(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_21(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_21(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_21(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_21(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_21(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_21(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_22(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_22(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_22(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_22(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_22(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_22(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_22(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_22(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_23(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_23(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_23(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_23(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_23(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_23(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_23(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_23(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_24(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_24(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_24(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_24(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_24(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_24(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_24(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_24(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }
