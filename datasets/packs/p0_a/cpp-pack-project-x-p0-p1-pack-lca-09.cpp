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
int pack_project_x_p0_p1_pack_lca_09(const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    int n=(int)adj.size(); vector<int> dep(n), par(n,-1), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v]; return (int)ans;
}
