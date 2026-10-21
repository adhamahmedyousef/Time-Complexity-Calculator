// Omar

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool ok(int x){
    if(x < 2)return false;

    for(ll i = 2 ; i * i <= x ; ++i){
        if(!(x % i))return false;
    }

    return true;
}

int pack_level0_rand_pack_main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(ok(n)){
            cout<<1<<" "<<n-1<<'\n';
        }
        else if(n & 1){
            ll mx = 0;
            for(ll i = 1 ; i * i <= n ; ++i){
                if(!(n % i && i != n)){
                    mx = max(mx , i);
                    if(i != n / i && n / i != n)mx = max(mx , n / i);
                }
            }
            cout<<mx<<" "<<n - mx<<" "<<'\n';
        }
        else cout<<n/2<<" "<<n/2<<'\n';
    }

    return 0;
}
