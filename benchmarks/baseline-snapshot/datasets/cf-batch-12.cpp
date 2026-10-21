// 12
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

const int N = 1005;
const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<pair<int , int>> adj[N];
int dist[N][N];

void dijkstra(int src , int n){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
    pq.push({0 , src});
    dist[src][src] = 0;

    while(!pq.empty()){
        auto [cost , u] = pq.top();
        pq.pop();

        if(cost > dist[src][u]) continue;

        for(auto [v , w] : adj[u]){
            if(cost + w < dist[src][v]){
                dist[src][v] = cost + w;
                pq.push({dist[src][v] , v});
            }
        }
    }
}

void solve(){
    
    int n , m , k; cin >> n >> m >> k;

    vector<tuple<int,int,int>> edges;

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            dist[i][j] = INF;

    for(int i = 0 ; i < m ; i++){
        int u , v , w; cin >> u >> v >> w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
        edges.push_back({u , v , w});
    }

    vector<pair<int,int>> qrs(k);

    for(int i = 0 ; i < k ; i++)
        cin >> qrs[i].first >> qrs[i].second;

    for(int i = 1 ; i <= n ; i++)
        dijkstra(i , n);

    int ans = INF;

    for(auto [u , v , w] : edges){

        int cur = 0;

        for(auto [a , b] : qrs){
            int best = dist[a][b];
            best = min(best , dist[a][u] + dist[v][b]);
            best = min(best , dist[a][v] + dist[u][b]);
            cur += best;
        }

        ans = min(ans , cur);
    }

    cout << ans;
}

int32_t main(){
    fast();
    int t = 1;
    while(t--) solve();
}
