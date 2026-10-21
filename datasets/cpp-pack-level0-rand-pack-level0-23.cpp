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

        vector<int> a(n) , b(n);

        for(int i = 0 ; i < n ; ++i)cin >> a[i];
        for(int i = 0 ; i < n ; ++i)cin >> b[i];

        for(int i = 0 ; i < n  ;++i){
            int v1 = a[i] , v2 = b[i];
            a[i] = min(v1 , v2);
            b[i] = max(v1 , v2);
        }

        ll ans = *max_element(all(a));

        for(auto k : b)ans+=k;

        cout<<ans<<'\n';

    }

    return 0;
}
