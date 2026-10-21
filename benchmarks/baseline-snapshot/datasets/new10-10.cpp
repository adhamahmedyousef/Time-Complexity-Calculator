// #include "libc++.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

typedef vector<ll> vi;
typedef pair<ll,ll> pii;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve(){
    int k , n; cin >> k >> n;
    if(n > k)
        cout << 0;
    else
        cout << (k / n) * n;

}

int main(){
    fast();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}