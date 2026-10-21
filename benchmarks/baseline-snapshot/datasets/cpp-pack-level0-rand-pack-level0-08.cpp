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

unordered_map<int , int> mp;
const int mx = 45000;
vector<bool> sieve(mx , true);
vector<int> primes;

void Build(){
    sieve[0] = sieve[1] = false;

    for(int i = 2 ; i * i <= mx ; ++i){
        if(sieve[i]){
            for(int j = i * i ; j <= mx ; j += i){
                sieve[j] = false;
            }
        }
    }

    for(int i = 2 ; i <= mx ; ++i){
        if(sieve[i])primes.push_back(i);
    }
}

vector<int> fact(int x){

    vector<int> facts;

    for(auto p : primes){
        if(1LL * p * p > x)break;
        while(!(x % p))x /= p;

        facts.push_back(p);
    }    
    if(x > 1)facts.push_back(x);

    return facts;
}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    Build();

    int t;
    cin >> t;

    vector<pair<int , int>> pi;

    while(t--){
        int a , b;
        cin >> a >> b;

        pi.push_back({a , b});
    }

    auto [x , y] = pi[0];

    unordered_set<int> st;

    auto v1 = fact(x);
    auto v2 = fact(y);

    for(auto k : v1)st.insert(k);
    for(auto k : v2)st.insert(k);

    int ans = 0;

    for(auto k : st){
        bool ok = true;
        for(auto &[f , s] : pi){
            if(f % k && s % k){
                ok = false;
                break;
            }
        }
        if(ok)ans = k;
    }

    cout<<((!ans)?-1:ans)<<'\n';


    return 0;
}
