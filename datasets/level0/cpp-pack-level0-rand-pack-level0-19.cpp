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
        int n , k;
        cin >> n >> k;

        string a , b;
        cin >> a >> b;

        ll li = (1LL << k) + 1;

        ll x = 0;
        ll y = 0;

        ll o = 0;
        ll l = 0;

        for(auto k : a){
            if(k == '1')o++;
            else l++;
        }

        x = l * o;
        l = 0;
        o = 0;

        for(auto k : b){
            if(k == '1')o++;
            else l++;
        }

        y = l * o; 
        l = 0;
        o = 0;

        for(int i = 0 ; i < n ; ++i){
            if(a[i] == b[i])o++;
            else l++;
        }

        ll nv = o * l;
        ll rem = li % 3;
        ll ans = 0;

        ans = (li / 3) * (x + y + nv);
        if(rem == 1)ans += x;
        else if(rem == 2)ans += (x + y);

        cout<<ans<<'\n';

    }
                        
    return 0;
}
