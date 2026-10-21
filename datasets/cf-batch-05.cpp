// 5
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

int pal[5001][5001];
int dp[5001][5001];
int n;
int p_count(int l , int r){
    if(l > r || r >= n)
        return 0;
    
    if(r == n)
        return 0;
    if(~dp[l][r])
        return dp[l][r];

    int ch1 = p_count(l , r - 1);
    int ch2 = p_count(l + 1 , r);
    int ch3 = p_count(l + 1 , r - 1);

    return dp[l][r] = ch1 + ch2 - ch3 + pal[l][r];
}


void solve(){
    string s; cin >> s;
     n = s.size();
    memset(dp , -1 , sizeof dp);
    for(int mid = 0 ; mid < n ; mid++){
        for(int j = mid , k = mid ; j >= 0 && k < n ; j-- , k++){
            if(s[j] == s[k]) pal[j][k] = 1;
            else break;
        }
    }

    for(int mid = 0 ; mid < n ; mid++){
        for(int j = mid , k = mid + 1 ; j >= 0 && k < n ; j-- , k++){
            if(s[j] == s[k]) pal[j][k] = 1;
            else break;
        }
    }

    

    int q; cin >> q;
    while(q--){
        int l , r; cin >> l >> r;
        l --; r--;
        cout << p_count(l , r) << '\n';
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    fast();
    int t = 1;
    
    while(t--) solve();
}
