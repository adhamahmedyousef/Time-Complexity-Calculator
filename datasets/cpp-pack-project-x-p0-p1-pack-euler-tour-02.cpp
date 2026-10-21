#include <bits/stdc++.h>
using namespace std;


// euler-tour-01
void dfs_01(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_01(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_01(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_01(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-02
void dfs_02(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_02(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long pack_project_x_p0_p1_pack_euler_tour_02(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_02(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}
