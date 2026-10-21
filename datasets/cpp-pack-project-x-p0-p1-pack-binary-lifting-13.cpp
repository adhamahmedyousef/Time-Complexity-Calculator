#include <bits/stdc++.h>
using namespace std;


// binary-lifting-01
int binary_lifting_01(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-02
int binary_lifting_02(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-03
int binary_lifting_03(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-04
int binary_lifting_04(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-05
int binary_lifting_05(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-06
int binary_lifting_06(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-07
int binary_lifting_07(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-08
int binary_lifting_08(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-09
int binary_lifting_09(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-10
int binary_lifting_10(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-11
int binary_lifting_11(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-12
int binary_lifting_12(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(), LOG=1; while ((1<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(n,-1)); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    for (int k=1;k<LOG;++k) for (int v=0; v<n; ++v) up[k][v] = up[k-1][v] < 0 ? -1 : up[k-1][up[k-1][v]];
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// binary-lifting-13
long long pack_project_x_p0_p1_pack_binary_lifting_13(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
