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
long long euler_tour_02(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_02(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-03
void dfs_03(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_03(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_03(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_03(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-04
void dfs_04(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_04(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_04(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_04(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-05
void dfs_05(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_05(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_05(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_05(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-06
void dfs_06(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_06(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_06(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_06(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-07
void dfs_07(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_07(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_07(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_07(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-08
void dfs_08(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_08(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_08(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_08(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-09
void dfs_09(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_09(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_09(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_09(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-10
void dfs_10(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_10(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_10(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_10(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-11
void dfs_11(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_11(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_11(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_11(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-12
void dfs_12(int u, int p, const vector<vector<int>>& adj, vector<int>& tin, vector<int>& tout, vector<int>& ord) {
    tin[u]=(int)ord.size(); ord.push_back(u); for (int v:adj[u]) if (v!=p) dfs_12(v,u,adj,tin,tout,ord); tout[u]=(int)ord.size()-1;
}
long long euler_tour_12(int n, const vector<vector<int>>& adj, const vector<int>& nodes) {
    vector<int> tin(n), tout(n), ord; if (n) dfs_12(0,-1,adj,tin,tout,ord); long long ans=0; for (int u:nodes) ans += tout[u]-tin[u]+1; return ans;
}

// euler-tour-13
long long euler_tour_13(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// euler-tour-14
long long euler_tour_14(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// euler-tour-15
long long euler_tour_15(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// euler-tour-16
long long euler_tour_16(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }

// euler-tour-17
long long pack_project_x_p0_p1_pack_euler_tour_17(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
