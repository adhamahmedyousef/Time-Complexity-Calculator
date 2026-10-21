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


vector<int> g8_dsuInit_25(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_25(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_25(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_25(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_25(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_25(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_25(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_25(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_26(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_26(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_26(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_26(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_26(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_26(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_26(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_26(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_27(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_27(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_27(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_27(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_27(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_27(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_27(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_27(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_28(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_28(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_28(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_28(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_28(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_28(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_28(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_28(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_29(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_29(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_29(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_29(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_29(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_29(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_29(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_29(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }
