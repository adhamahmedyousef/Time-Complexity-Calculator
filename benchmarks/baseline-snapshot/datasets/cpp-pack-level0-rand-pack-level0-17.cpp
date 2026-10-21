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

    int n;
    cin >> n;

    unordered_set<int> s;
    for(int i = 1 ; i <= n ; ++i)s.insert(i);

    unordered_set<int> a;

    for(int j = 0 ; j < n - 1; ++j){
        int x;
        cin >> x;

        a.insert(x);
    }

    for(auto k : s){
        if(!a.count(k)){
            cout<<k<<'\n';
            break;
        }
    }
        
    

    return 0;
}
