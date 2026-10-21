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
long long heavy_light_decomposition_04(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-05
long long heavy_light_decomposition_05(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-06
long long heavy_light_decomposition_06(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-07
long long heavy_light_decomposition_07(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-08
long long heavy_light_decomposition_08(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-09
long long heavy_light_decomposition_09(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-10
long long heavy_light_decomposition_10(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-11
long long heavy_light_decomposition_11(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-12
long long heavy_light_decomposition_12(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-13
long long heavy_light_decomposition_13(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-14
long long heavy_light_decomposition_14(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-15
long long heavy_light_decomposition_15(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-16
long long heavy_light_decomposition_16(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-17
long long heavy_light_decomposition_17(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-18
long long heavy_light_decomposition_18(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-19
long long heavy_light_decomposition_19(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-20
long long heavy_light_decomposition_20(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-21
long long heavy_light_decomposition_21(int n, const vector<vector<int>>& adj, const vector<pair<int,int>>& qs) {
    vector<int> par(n,-1), dep(n), ord={0};
    for (int i=0;i<(int)ord.size();++i) for (int v:adj[ord[i]]) if (v!=par[ord[i]]) { par[v]=ord[i]; dep[v]=dep[ord[i]]+1; ord.push_back(v); }
    long long ans=0; for (auto [u,v]:qs) ans += dep[u] + dep[v] + n; return ans;
}

// heavy-light-decomposition-22
long long heavy_light_decomposition_22(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// heavy-light-decomposition-23
long long heavy_light_decomposition_23(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// heavy-light-decomposition-24
long long heavy_light_decomposition_24(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// heavy-light-decomposition-25
long long heavy_light_decomposition_25(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// heavy-light-decomposition-26
long long heavy_light_decomposition_26(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// heavy-light-decomposition-27
long long heavy_light_decomposition_27(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// heavy-light-decomposition-28
long long heavy_light_decomposition_28(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// heavy-light-decomposition-29
long long pack_project_x_p0_p1_pack_heavy_light_decomposition_29(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
