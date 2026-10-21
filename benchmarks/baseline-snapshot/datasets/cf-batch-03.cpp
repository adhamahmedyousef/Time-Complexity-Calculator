// 3
// #include "libc++.h"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

typedef vector<ll> vi;
typedef pair<ll,ll> pii;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int arr[N];
int n;

ll dp[N][2];
bool vis[N][2];

ll f(int i , int trn){
    if(i == n)
        return (trn ? 0 : -INF);
    

    if(vis[i][trn])
        return dp[i][trn];
    vis[i][trn] = 1;

    ll ch1 = -INF , ch2 = -INF;
    ch1 = max(ch1 , f(i + 1 , trn));
    ch2 = max(ch2 , f(i + 1 , trn ^ (arr[i] & 1)) + arr[i]);

    return dp[i][trn] = max(ch1 , ch2);
}


void solve(){
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    memset(vis , 0 , sizeof vis);

    cout << f(0  ,0);
        
}

int main(){
    //freopen("input.txt", "r", stdin);
    fast();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
