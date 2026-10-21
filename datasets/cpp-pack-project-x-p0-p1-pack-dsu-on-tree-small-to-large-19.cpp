#include <bits/stdc++.h>
using namespace std;


// dsu-on-tree-small-to-large-01
long long dsu_on_tree_small_to_large_01(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-02
long long dsu_on_tree_small_to_large_02(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-03
long long dsu_on_tree_small_to_large_03(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-04
long long dsu_on_tree_small_to_large_04(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-05
long long dsu_on_tree_small_to_large_05(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-06
long long dsu_on_tree_small_to_large_06(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-07
long long dsu_on_tree_small_to_large_07(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-08
long long dsu_on_tree_small_to_large_08(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-09
long long dsu_on_tree_small_to_large_09(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-10
long long dsu_on_tree_small_to_large_10(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-11
long long dsu_on_tree_small_to_large_11(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-12
long long dsu_on_tree_small_to_large_12(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-13
long long dsu_on_tree_small_to_large_13(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-14
long long dsu_on_tree_small_to_large_14(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-15
long long dsu_on_tree_small_to_large_15(int n, const vector<vector<int>>& adj) {
    vector<int> par(n,-1), ord={0}, sz(n,1);
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; ord.push_back(v); }
    for (int i=n-1;i>0;--i) sz[par[ord[i]]] += sz[ord[i]];
    return accumulate(sz.begin(), sz.end(), 0LL);
}

// dsu-on-tree-small-to-large-16
long long dsu_on_tree_small_to_large_16(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// dsu-on-tree-small-to-large-17
long long dsu_on_tree_small_to_large_17(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// dsu-on-tree-small-to-large-18
long long dsu_on_tree_small_to_large_18(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// dsu-on-tree-small-to-large-19
long long pack_project_x_p0_p1_pack_dsu_on_tree_small_to_large_19(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
