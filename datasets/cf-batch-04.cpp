// 4
#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int n, m, k;
ll arr[5005], pref[5005];
ll dp[5005][5005];

ll gain(int l){
    return pref[l + m] - pref[l];
}

ll f(int i, int rem){

    if(rem == 0)
        return 0;

    if(i > n - m)
        return -1e18;

    if(~dp[i][rem])
        return dp[i][rem];

    ll leave = f(i + 1, rem);

    ll take = gain(i) + f(i + m, rem - 1);

    return dp[i][rem] = max(leave, take);
}

void solve(){

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + arr[i];

    memset(dp, -1, sizeof dp);

    cout << f(0, k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
