#include <bits/stdc++.h>
using namespace std;

// tarjan-scc-01
struct Tarjan_1 {
    int timer = 0;
    vector<int> disc, low, st, on;
    vector<vector<int>> comp;
    Tarjan_1(int n) : disc(n, -1), low(n, -1), on(n, 0) {}
    void dfs(int u, const vector<vector<int>>& adj) {
        disc[u] = low[u] = timer++;
        st.push_back(u); on[u] = 1;
        for (int v : adj[u]) {
            if (disc[v] == -1) { dfs(v, adj); low[u] = min(low[u], low[v]); }
            else if (on[v]) low[u] = min(low[u], disc[v]);
        }
        if (low[u] == disc[u]) {
            vector<int> c;
            while (!st.empty()) {
                int x = st.back(); st.pop_back(); on[x] = 0; c.push_back(x);
                if (x == u) break;
            }
            comp.push_back(c);
        }
    }
};
int pack_cp_requested_dataset_pack_tarjanScc_1(const vector<vector<int>>& adj) {
    Tarjan_1 t((int)adj.size());
    for (int i = 0; i < (int)adj.size(); ++i) if (t.disc[i] == -1) t.dfs(i, adj);
    return (int)t.comp.size();
}
