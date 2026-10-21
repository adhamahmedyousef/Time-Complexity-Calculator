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

const int mx = 35000;
unordered_map<int , int> tr;
vector<int> sieve(mx + 1 , true);
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

void comp(int x){
    for(auto p : primes){
        if(1LL * p * p > x)break;

        while(!(x % p)){
            if(p != 2 && p != 3)tr[p]++;
            x/=p;
        }
    }
    if(x > 1 && x != 2 && x != 3)tr[x] = 1;
}

bool ok(int y , int s){
     
    unordered_map<int , int> mp;

    for(auto p : primes){
        if(1LL * p * p > y)break;

        while(!(y%p)){
            if(p != 2 && p != 3)mp[p]++;
            y/=p;
        }
    }
    if(y > 1 && y != 2 && y != 3)mp[y] = 1;

    if(mp.size() != s)return false;

    for(auto &[k , v] : mp){
        if(v != tr[k])return false;
    }

    return true;
}

int pack_level0_rand_pack_main() {
    fast_io;

    // freopen("input.txt", "r", stdin);

    Build();

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i)cin >> a[i];

    comp(a[0]);
    int x = tr.size();
    // for(auto &[k , v] : tr)cout<<k<<" "<<v<<'\n';

    for(int i = 1 ; i < n ; ++i){
        if(!ok(a[i] , x)){
            cout<<"No"<<'\n';
            return 0;
        }
    }

    cout<<"Yes"<<'\n';

    return 0;
}
