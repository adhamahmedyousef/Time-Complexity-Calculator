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
    string s , s1;
    cin >> s >> s1;

    int n = s.size() , m = s1.size();

    int l = n - 1 , r = m - 1;
    int d = 0;
    while(l >= 0 && r >= 0){
        if(s[l] != s1[r])
            break;
        l--;
        r--;
        d++;
    }

    cout << (n - d) + (m - d); 
}

int main(){
    fast();
    int t = 1;
    while(t--) solve();
}