#include "libc++.h"
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

ll fb(ll a , ll b){
    ll res = 1;
    while(b){
        if(b & 1)res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

void solve(){
    ll x; cin >> x;

    int z = 0;
    ll k = x;
    ll ans = 0;

    while(k > 0){
        if(!(k & 1)){
            ans += fb(2 , z);
        }
        z++;
        k = k >> 1;
    }

    cout << ans << '\n';

}

int main(){
    fast();
    int t = 1;
    cin >> t;
    while(t--) solve();
}