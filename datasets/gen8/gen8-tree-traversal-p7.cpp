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


int g8_treePreorder_30(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_30(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_30(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_30(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_30(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_30(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_30(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_30(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_31(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_31(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_31(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_31(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_31(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_31(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_31(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_31(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_32(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_32(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_32(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_32(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_32(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_32(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_32(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_32(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_33(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_33(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_33(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_33(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_33(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_33(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_33(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_33(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_34(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_34(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_34(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_34(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_34(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_34(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_34(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_34(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }
