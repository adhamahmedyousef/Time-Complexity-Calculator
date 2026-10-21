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


// عارف ان في حل سهل والله ياعم البورم بس بتدرب على تحليل ارقام كبيرة بسرعة

const int mx = 35000;
vector<bool> sieve(mx + 1 , true);
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
    vector<int> pi;

    for(auto p : primes){
        if(1LL * p * p > x)break;

        if(!(x % p)){
            pi.push_back(p);
            while(!(x % p))x/=p;
        }
    }
    if(x > 1)pi.push_back(x);

    return pi;
}

int New_p(int x , int y){
    auto v1 = fact(x);
    auto v2 = fact(y);

    unordered_set<int> st;

    for(auto k : v1)st.insert(k);
    for(auto k : v2)st.insert(k);

    for(auto k : primes){
        if(!st.count(k))return k;
    }

    return -1; // والله ما هتشتغل بس الكومبايلر مضايقني
}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    Build();

    int n;
    cin >> n;

    vector<int> a(n) , ans;
    for(int i = 0 ; i < n ; ++i)cin >> a[i];

    for(int i = 0 ; i < n - 1; ++i){                                          
        if(gcd(a[i] , a[i+1]) > 1){
            int v = New_p(a[i] , a[i+1]);
            ans.push_back(a[i]);
            ans.push_back(v);
        }
        else{
            ans.push_back(a[i]);
        } 
    }

    ans.push_back(a[n-1]);
    int diff = ans.size() - a.size();

    cout<<diff<<'\n';
    for(auto k : ans)cout<<k<<" ";

    return 0;
}
