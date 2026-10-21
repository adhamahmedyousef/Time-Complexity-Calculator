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


vector<int> g8_dsuInit_35(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_35(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_35(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_35(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_35(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_35(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_35(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_35(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_36(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_36(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_36(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_36(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_36(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_36(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_36(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_36(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_37(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_37(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_37(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_37(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_37(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_37(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_37(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_37(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_38(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_38(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_38(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_38(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_38(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_38(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_38(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_38(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_39(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_39(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_39(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_39(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_39(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_39(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_39(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_39(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }
