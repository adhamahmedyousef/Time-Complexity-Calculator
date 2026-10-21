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
    if (!a || !b) return 0;
    if (a > INFLL / b) return INFLL;
    return a * b;
}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    if(s[0] != '9'){
        if(9 - (s[0] - '0') < s[0] - '0')cout<<9-(s[0] - '0');
        else cout<<s[0];
    }
    else cout<<s[0];

    for(int i = 1 ; i < (int)s.size() ; ++i){
        if(9 - (s[i] - '0') < s[i] - '0')cout<<9 - (s[i] - '0');
        else cout<<s[i];
        
    }


    return 0;
}
