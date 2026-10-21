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


vector<int> g8_dsuInit_10(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_10(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_10(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_10(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_10(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_10(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_10(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_10(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_11(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_11(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_11(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_11(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_11(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_11(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_11(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_11(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_12(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_12(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_12(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_12(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_12(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_12(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_12(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_12(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_13(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_13(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_13(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_13(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_13(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_13(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_13(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_13(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_14(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_14(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_14(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_14(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_14(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_14(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_14(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_14(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }
