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

void facts(int x , unordered_map<int ,int>& f){
    for(int i = 2 ; i * i <= x ; ++i){
        while(!(x % i)){
            f[i]++;
            x /= i;
        }
    }

    if(x > 1)f[x] = 1;
}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    int a , b;
    cin >> a >> b;

    unordered_map<int ,int> v1 , v2;

    facts(a , v1);
    facts(b , v2);

    bool ok = true;
    int ans = 0;

    for(auto &[k , v] : v2){
        if(!v1.count(k) && (k == 2 || k == 3 || k == 5)){
            ans += v;
            v2[k] = 0;
        }
        else if(!v1.count(k))ok = false;
        else if(v1.count(k) && (k == 2 || k == 3 || k == 5)){
            ans += max(v1[k] , v) - min(v1[k] , v);
            v2[k] -= max(v1[k] , v) - min(v1[k] , v);

        }
    }

    for(auto &[k , v] : v1){
        if(!v2.count(k) && (k == 2 || k == 3 || k == 5)){
            ans += v;
        }
        else if(!v2.count(k))ok = false;
        else if(v2.count(k) && (k == 2 || k == 3 || k == 5)){
            ans += max(v1[k] , v) - min(v1[k] , v);
        }
    }

    if(ok)
        cout<<ans<<'\n';
    else cout<<-1<<'\n';


    return 0;
}
