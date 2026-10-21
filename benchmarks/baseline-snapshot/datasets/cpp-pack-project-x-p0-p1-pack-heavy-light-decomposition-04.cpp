#include <bits/stdc++.h>
using namespace std;


// heavy-light-decomposition-01
long long heavy_light_decomposition_01(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-02
long long heavy_light_decomposition_02(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-03
long long heavy_light_decomposition_03(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-04
long long pack_project_x_p0_p1_pack_heavy_light_decomposition_04(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}
