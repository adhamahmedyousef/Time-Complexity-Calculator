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

ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, t;
    cin >> n >> t;

    vector<ll> fact(n + 1), inv(n + 1);

    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv[n] = binpow(fact[n], MOD - 2);

    for(int i = n; i >= 1; i--)
        inv[i - 1] = inv[i] * i % MOD;

    auto C = [&](int nn, int rr){
        if(rr < 0 || rr > nn) return 0LL;
        return fact[nn] * inv[rr] % MOD * inv[nn - rr] % MOD;
    };

    cout << (2LL * C(n - 1, t)) % MOD << '\n';
}

int main(){
    fast();
    int t = 1;
    while(t--) solve();
}