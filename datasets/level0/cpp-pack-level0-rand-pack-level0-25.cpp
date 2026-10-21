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
        int n , q;
        cin >> n >> q;

        vector<int> a(n) , b(n);

        for(int i = 0 ; i < n ; ++i)cin >> a[i];
        for(int i = 0 ; i < n ; ++i)cin >> b[i];

        vector<int> cc(n);

        for(int i = 0 ; i < n ; ++i){
            cc[i] = max(a[i] , b[i]);
        }

        vector<int> mx(n);
        mx[n-1] = cc[n-1];

        for(int i = n - 2 ; i >= 0 ; --i){
            mx[i] = max(mx[i + 1] , cc[i]);
        }

        vector<int> suff(n);

        suff[n - 1] = mx[n - 1];

        for(int i = n - 2 ; i >= 0 ; --i){
            suff[i] = suff[i + 1] + mx[i];
        }
       

        while(q--){
            int l , r;
            cin >> l >> r;
            --l;--r;

            if(r == n - 1)cout<<suff[l]<<" ";
            else cout<<suff[l] - suff[r + 1]<<" ";

        }
        cout<<'\n';

    }

    return 0;
}
