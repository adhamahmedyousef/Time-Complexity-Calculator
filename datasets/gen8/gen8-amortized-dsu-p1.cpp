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


vector<int> g8_dsuInit_0(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_0(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_0(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_0(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_0(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_0(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_0(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_0(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_1(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_1(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_1(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_1(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_1(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_1(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_1(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_1(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_2(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_2(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_2(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_2(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_2(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_2(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_2(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_2(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_3(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_3(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_3(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_3(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_3(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_3(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_3(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_3(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }

vector<int> g8_dsuInit_4(int n) { vector<int> p(n); for (int i = 0; i < n; ++i) p[i] = i; return p; }

void g8_dsuRankInit_4(int n) { vector<int> r(n, 0); for (int i = 0; i < n; ++i) r[i] = 1; }

int g8_dsuFindLoop_4(vector<int>& p, int x) { for (int iter = 0; iter < static_cast<int>(p.size()); ++iter) { if (x == p[x]) return x; x = p[x]; } return x; }

int g8_dsuCountRoots_4(const vector<int>& p) { int roots = 0; for (int i = 0; i < static_cast<int>(p.size()); ++i) if (p[i] == i) roots++; return roots; }

vector<int> g8_dsuCompSizes_4(const vector<int>& p) { int n = p.size(); vector<int> sz(n, 0); for (int i = 0; i < n; ++i) sz[p[i]]++; return sz; }

void g8_dsuEdgeIteration_4(int m) { for (int i = 0; i < m; ++i) { (void)i; } }

void g8_dsuSequentialPass_4(int n, int m) { for (int i = 0; i < n; ++i) { } for (int j = 0; j < m; ++j) { } }

void g8_dsuRankMerge_4(vector<int>& p, vector<int>& r, int a, int b) { if (r[a] < r[b]) p[a] = b; else { p[b] = a; if (r[a] == r[b]) r[a]++; } }
