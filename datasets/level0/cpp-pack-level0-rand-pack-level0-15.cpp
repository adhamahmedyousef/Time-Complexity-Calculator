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

    vector<int> a(n);

    for(int i = 0 ; i < n ; ++i)cin >> a[i];

    
    vector<int> chr = {0 , 0};
    
    for(auto k : a){
        if(k == 25)chr[0] += 1;
        if(k == 50)chr[1] += 1;
        k -= 25;

        if(!k)continue;

        if(k == 25){
            if(chr[0])chr[0]--;
            else{
                cout<<"NO"<<'\n';
                return 0;
            }
        }
        else if(k == 50){
            if(chr[1])chr[1]--;
            else if(chr[0] >= 2)chr[0]-=2;
            else{
                cout<<"NO"<<'\n';
                return 0;
            }
        }
        else if(k == 75){
            if(chr[0] && chr[1]){chr[0]--;chr[1]--;}
            else if(chr[0] >= 3)chr[0]-=3;
            else{
                cout<<"NO"<<'\n';
                return 0;
            }
        }
       
    }
    cout<<"YES"<<'\n';

    return 0;
}
