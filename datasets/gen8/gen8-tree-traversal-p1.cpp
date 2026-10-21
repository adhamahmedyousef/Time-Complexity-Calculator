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


int g8_treePreorder_0(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_0(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_0(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_0(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_0(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_0(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_0(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_0(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_1(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_1(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_1(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_1(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_1(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_1(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_1(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_1(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_2(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_2(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_2(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_2(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_2(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_2(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_2(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_2(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_3(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_3(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_3(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_3(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_3(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_3(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_3(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_3(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }

int g8_treePreorder_4(int n) { int s = 0; for (int i = 0; i < n; ++i) s += i; return s; }

int g8_vectorRange_4(const vector<int>& a) { int sum = 0; for (int x : a) sum += x; return sum; }

int g8_treeSubtreeSum_4(const vector<int>& weights) { int tot = 0; for (int i = 0; i < static_cast<int>(weights.size()); ++i) tot += weights[i]; return tot; }

int g8_treeMaxDegree_4(const vector<int>& deg) { int mx = 0; for (int i = 0; i < static_cast<int>(deg.size()); ++i) if (deg[i] > mx) mx = deg[i]; return mx; }

vector<int> g8_treeInitParent_4(int n) { vector<int> parent(n); for (int i = 0; i < n; ++i) parent[i] = i; return parent; }

int g8_treeLeafCount_4(const vector<int>& deg) { int leaves = 0; for (int d : deg) if (d == 1) leaves++; return leaves; }

vector<int> g8_treeDepthArray_4(int n) { vector<int> d(n, 0); for (int i = 1; i < n; ++i) d[i] = d[i - 1] + 1; return d; }

int g8_treeEdgeCount_4(int n) { int edges = 0; for (int i = 1; i < n; ++i) edges++; return edges; }
