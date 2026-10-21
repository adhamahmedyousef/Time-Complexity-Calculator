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


vector<int> g8_dsuInit_30(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_30(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_30(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_30(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_30(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_30(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_30(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_30(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_31(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_31(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_31(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_31(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_31(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_31(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_31(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_31(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_32(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_32(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_32(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_32(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_32(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_32(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_32(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_32(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_33(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_33(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_33(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_33(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_33(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_33(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_33(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_33(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_34(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_34(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_34(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_34(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_34(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_34(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_34(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_34(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }
