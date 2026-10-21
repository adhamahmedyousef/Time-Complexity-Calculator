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

bool isp(ll x){
    vector<int> s;
    vector<int> k;
    while(x){
        s.push_back(x % 10);
        k.push_back(x % 10);
        x /= 10;
    }
    reverse(all(s));

    if(s == k)return true;
    return false;
}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        if(!(n % 12)){cout<<0<<" "<<n<<'\n';continue;}
        if(isp(n)){cout<<n<<" "<<0<<'\n';continue;}

        ll f = n / 12;
        ll nv = f * 12;
        ll x = 0;

        while(nv >= 12){
            if(isp(n - nv)){x = n - nv;break;}
            nv -= 12;
        }

        if(x)cout<<n - nv<<" "<<nv<<'\n';
        else cout<<-1<<'\n';
    }

    return 0;
}
