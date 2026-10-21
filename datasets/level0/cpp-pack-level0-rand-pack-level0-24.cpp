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

int cnt = 0;

void C_lucky(ll x){
    while(x){
        if(x % 10 == 7 || x % 10 == 4)cnt++;
        x/=10;
    }
}

bool check(int c){
    if(!c)return false;
    
    while(c){
        if(c % 10 != 4 && c % 10 != 7)return false;
        c/= 10;
    }

    return true;
}


int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    C_lucky(n);

    if(check(cnt))cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';

    return 0;
}
