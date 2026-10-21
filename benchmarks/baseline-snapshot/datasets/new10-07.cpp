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

int main() {
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n , k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0 ; i < n ; ++i)cin >> a[i];

        ll ans = 0;

        for(auto ki : a){        
            if(ki < k)ans += min(k - ki , ki);
            else if(ki % k)ans += min(ki % k , k - (ki % k));
        }

        cout<<ans<<'\n';

    }

    return 0;
}