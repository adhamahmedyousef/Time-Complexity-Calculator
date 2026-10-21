// 7
// #include "libc++.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

typedef vector<ll> vi;
typedef pair<ll,ll> pii;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 105;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int OFFSET = 100000;

ll dp[N][200005];

int n, k;
int a[N], b[N], val[N];

ll f(int idx, int sum){
    if(idx == n){
        if(sum == 0) return 0;
        return -INF;
    }

    ll &ret = dp[idx][sum + OFFSET];
    if(~ret) return ret;

    ll ch1 = f(idx + 1, sum);

    ll ch2 = f(idx + 1, sum + val[idx]);
    if(ch2 != -INF)
        ch2 += a[idx];

    return ret = max(ch1, ch2);
}

void solve(){
    cin >> n >> k;

    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];

    for(int i = 0 ; i < n ; i++)
        val[i] = a[i] - k * b[i];

    memset(dp , -1 , sizeof dp);

    ll ans = f(0 , 0);

    if(ans <= 0) cout << -1;
    else cout << ans;
}

int main(){
    fast();
    int t = 1;
    while(t--) solve();
}
