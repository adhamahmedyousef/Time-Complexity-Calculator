// -_- <3

#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vi  = vector<int>;
using pii = pair<int,int>;

#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

constexpr ll INFLL = (ll)4e18;
constexpr int INF  = (int)2e9;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

inline ll add(ll a, ll b) {
    if (a > INFLL - b) return INFLL;
    return a + b;
}

inline ll mul(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a > INFLL / b) return INFLL;
    return a * b;
}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n % 2){
            cout<<"NO"<<'\n';
            continue;
        }

        bool ok = false;

        if(n == 2){cout<<"YES"<<'\n';continue;}

        while(true){
            ll r = sqrtl(n);
            if(1LL*r*r == n){
                ok = true;
                break;
            }
            if(n & 1)break;
            n >>= 1;
        }

        if(ok)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
        
    }

    return 0;
}
