// 9
// #include "libc++.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

typedef vector<ll> vi;
typedef pair<ll,ll> pii;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll arr[N];
ll arr1[N];
ll dp[N][3];
ll n;

ll f(int p , int prv){
    if(p == n){
        return 0;
    }

    if(dp[p][prv] != -1){
        return dp[p][prv];
    }

    
    ll ans = f(p + 1 , prv);
    if(prv != 0){
        ans = max(ans , arr[p] + f(p + 1 , 0));
        
    }
    if(prv != 1){
        ans = max(ans , arr1[p] + f(p + 1 , 1));

    }

    return dp[p][prv] = ans;

}


void solve(){
    cin >> n;
    
    for(int i = 0 ; i < n  ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> arr1[i];
    }

    memset(dp , -1 , sizeof dp);
    cout << f(0 , 2);
    
}

int main(){
    //freopen("input.txt", "r", stdin);
    fast();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
