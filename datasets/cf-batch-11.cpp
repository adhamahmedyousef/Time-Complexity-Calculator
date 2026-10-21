// 11
// #include "libc++.h"
#include<bits/stdc++.h>
using namespace std;

using int64 = long long;
#define int long long

typedef vector<int> vi;
typedef pair<int,int> pii;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 2e5 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve(){
    int n , m; cin >> n >> m;
    vector<vector<pair<int , int>>> adj(n + 1);

    for(int i = 0 ; i < m ; i++){
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }

    vector<int> cycle(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> cycle[i];

    vector<vector<int>> dist(n + 1 , vector<int>(n + 1 , INF));

    priority_queue<
        tuple<int , int , int>,
        vector<tuple<int , int , int>>,
        greater<>
    > pq;

    dist[1][1] = 0;
    pq.push({0 , 1 , 1}); 

    while(!pq.empty()){

        auto [cost , node , cyc] = pq.top();
        pq.pop();

        if(cost > dist[node][cyc]) continue;

        for(auto [n_node , n_cost] : adj[node]){

            int co = cost + cycle[cyc] * n_cost;

            int new_cyc = cyc;
            if(cycle[n_node] < cycle[cyc])
                new_cyc = n_node;

            if(co < dist[n_node][new_cyc]){
                dist[n_node][new_cyc] = co;
                pq.push({co , n_node , new_cyc});
            }
        }
    }

    int ans = INF;
    for(int i = 1 ; i <= n ; i++)
        ans = min(ans , dist[n][i]);

    cout << ans << "\n";
}

int32_t main(){
    fast();
    int t = 1;
    cin >> t;
    while(t--) solve();
}
