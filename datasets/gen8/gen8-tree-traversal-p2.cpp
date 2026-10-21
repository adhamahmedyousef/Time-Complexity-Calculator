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


int g8_treePreorder_5(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_5(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_5(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_5(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_5(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_5(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_5(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_5(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_6(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_6(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_6(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_6(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_6(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_6(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_6(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_6(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_7(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_7(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_7(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_7(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_7(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_7(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_7(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_7(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_8(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_8(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_8(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_8(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_8(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_8(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_8(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_8(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_9(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_9(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_9(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_9(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_9(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_9(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_9(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_9(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }
