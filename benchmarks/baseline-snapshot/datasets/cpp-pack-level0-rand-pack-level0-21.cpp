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

        vector<int> a(n);
        for(int i = 0 ; i < n ; ++i)cin >> a[i];

        sort(all(a) , greater<>());

        bool ok = true;

        for(int i = 2 ; i < n ; ++i){
            if(a[i - 2] % a[i - 1] != a[i]){
                ok = false;
                break;
            }
        }

        if(ok)cout<<a[0]<<" "<<a[1]<<'\n';
        else cout<<-1<<'\n';
    }

    return 0;
}
