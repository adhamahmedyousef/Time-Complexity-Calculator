// 8
// #include "libc++.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

typedef vector<ll> vi;
typedef pair<ll,ll> pii;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

unordered_map<int , int> mp;
ll mx = -INF; 

ll dp[N];

ll f(int idx){
    if(idx > mx)
        return 0;

    if(~dp[idx])
        return dp[idx];
    
    ll ch1 = 0;
    ll ch2 = f(idx + 1);

    if(mp.count(idx)){
        ch1 = f(idx + 2) + 1LL * idx * mp[idx];
    }

    return dp[idx] = max(ch1 , ch2);

}

void solve(){
    int n; cin >> n;

    
    for(int i = 0 ; i < n ; i++){
        ll c; cin >> c;
        mx = max(mx , 1LL * c);
        mp[c]++;
    }
    memset(dp , -1 , sizeof dp);
    cout << f(0);
}

int main(){
    //freopen("input.txt", "r", stdin);
    fast();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
