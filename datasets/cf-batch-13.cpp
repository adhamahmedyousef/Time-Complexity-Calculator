// 13
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
const int MOD = 998244353;
const int K = 19;

vector<int> adj[N];
vector<int> rev_adj[N];
int dist[N][K + 1];
pair<int, int> dist_large[N][2];

int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve(){

    int n , m; cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u); 
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= K; j++) dist[i][j] = INF;
        dist_large[i][0] = dist_large[i][1] = {INF, INF};
    }

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

    dist[1][0] = 0;
    pq.push({0 , 1 , 0}); 
    while(!pq.empty()){

        auto [d , u , k] = pq.top();
        pq.pop();

        if(d > dist[u][k]) continue;

        auto &g = (k % 2) ? rev_adj : adj;

        for(auto v : g[u]){
            if(d + 1 < dist[v][k]){
                dist[v][k] = d + 1;
                pq.push({dist[v][k] , v , k});
            }
        }

        if(k < K){
            if(d < dist[u][k + 1]){
                dist[u][k + 1] = d;
                pq.push({d , u , k + 1});
            }
        }
    }

    int min_small = INF;
    for(int k = 0 ; k <= K ; k++){
        if(dist[n][k] != INF){
            min_small = min(min_small, (1LL << k) - 1 + dist[n][k]);
        }
    }

    if(min_small != INF){
        cout << min_small % MOD << "\n";
        return;
    }

    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> lpq;

    for(int i = 1; i <= n; i++){
        if(dist[i][K] != INF){
            dist_large[i][K % 2] = {K, dist[i][K]};
            lpq.push({{K, dist[i][K]}, {i, K % 2}});
        }
    }

    while(!lpq.empty()){
        auto curr = lpq.top(); lpq.pop();
        int k = curr.first.first;
        int d = curr.first.second;
        int u = curr.second.first;
        int p = curr.second.second;

        if(make_pair(k, d) > dist_large[u][p]) continue;

        auto &g = p ? rev_adj : adj;
        for(int v : g[u]){
            if(dist_large[v][p] > make_pair(k, d + 1)){
                dist_large[v][p] = {k, d + 1};
                lpq.push({{k, d + 1}, {v, p}});
            }
        }

        if(dist_large[u][1 - p] > make_pair(k + 1, d)){
            dist_large[u][1 - p] = {k + 1, d};
            lpq.push({{k + 1, d}, {u, 1 - p}});
        }
    }

    pair<int, int> res = min(dist_large[n][0], dist_large[n][1]);
    int ans = (power(2, res.first) - 1 + res.second) % MOD;
    cout << ans << "\n";

}

int32_t main(){
    fast();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
