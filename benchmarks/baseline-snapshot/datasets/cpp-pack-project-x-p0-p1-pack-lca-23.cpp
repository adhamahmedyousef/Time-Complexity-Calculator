#include <bits/stdc++.h>
using namespace std;


// lca-01
int lca_01(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-02
int lca_02(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-03
int lca_03(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-04
int lca_04(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-05
int lca_05(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-06
int lca_06(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-07
int lca_07(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-08
int lca_08(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-09
int lca_09(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-10
int lca_10(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-11
int lca_11(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-12
int lca_12(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-13
int lca_13(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-14
int lca_14(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-15
int lca_15(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-16
int lca_16(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-17
int lca_17(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-18
int lca_18(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}

// lca-19
long long lca_19(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// lca-20
long long lca_20(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// lca-21
long long lca_21(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// lca-22
long long lca_22(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// lca-23
long long pack_project_x_p0_p1_pack_lca_23(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
