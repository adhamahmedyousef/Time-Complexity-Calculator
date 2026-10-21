// Omar

#include <bits/stdc++.h>
using namespace std;
#define chocolatemilk ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define ld long double
const int N = 24 * 60 + 5 ;
ll arr [N];
int main() {
    chocolatemilk
    ll t ; 
    cin >> t ; 
    while (t --){
        ll q , m ; 
        cin >> q >> m;
        for (int i = 0 ; i < N ; i ++)
         arr[i] = 0; 
        ll a = 24 * 60 , teta = 0;
        for (int i = 0 ; i < q ; i ++){
            string s ;
            ll x ; 
            cin >>s >> x;
            ll h =  (s [0] - '0') * 10 + (s [1] - '0');
            ll m = ( s[3] - '0') * 10 + (s[4] - '0');
            ll time = h * 60 + m ;
            if ((time + x - 1) <= a){
                arr [time] ++ ; 
                arr [time + x ] --;

        }
    }
    ll maxi = 0 , chatoosa = 0 ; 
    for (int i = 0 ; i < N ;  i ++){
        chatoosa += arr [i] ; 
        maxi = max (maxi , chatoosa);
    }
    if (maxi <= m) 
    cout << "YES" << endl;
    else 
    cout << "NO" << endl;
    }
}