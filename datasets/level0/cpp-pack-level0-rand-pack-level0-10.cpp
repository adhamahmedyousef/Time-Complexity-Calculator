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

const int mx = 1e7;
int spf[mx + 1];

void Build(){
    for(int i= 1 ; i <= mx ; ++i)spf[i] = i;

    for(ll i = 2 ; i * i <= mx ; ++i){
        if(spf[i] == i){
            for(ll j = i * i ; j <= mx ; j += i){
                if(spf[j] == j)spf[j] = i;
            }
        }
    }
}

// int Second_P(int x){
//     vector<int> p;

//     while(x > 1){
//         int pi = spf[x];
//         while(!(x % pi))x/=pi;

//         p.push_back(pi);                        2 3 5
//     }

//     for(auto ki : p){
//         if(spf[ki + 2] == ki + 2)return ki;
//     }

//     return -1;
// }

pair<int , int> Pair_(int x){
    int t = x;
    int d1 = 1;
    int d2 = 1;
    int p = spf[x];

    while(!(t % p)){
        d1 *= p;
        t /= p;
    }

    d2 = x / d1;

    if(d2 == 1)return {-1,-1};

    if(gcd(d2 + d1 , x) == 1)return {d1 , d2};

    return {-1 , -1};

}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    Build();

    int n;
    cin >> n;
                                                                                                                    
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i)cin >> a[i];

    vector<pair<int , int>> ans;

    for(auto k : a){                                
        if(!(k%2) && !(k%3) && k%5)ans.push_back({2 , 3});
        else if(spf[k] == k)ans.push_back({-1,  -1});
        else{
            ll r = sqrtl(k);
            if(1LL * r * r == k && spf[r] == r)ans.push_back({-1 , -1});
            else ans.push_back(Pair_(k));
        }
    }

    for(auto &[f , s] : ans){
       cout<<f<<" ";
    }

    cout<<'\n';
    for(auto &[f , s] : ans){
        cout<<s<<" ";
    }


    return 0;
}
