// 10
// #include "libc++.h"
#include<bits/stdc++.h>
using namespace std;

using int64 = long long;
#define int long long

typedef vector<int> vi;
typedef pair<int,int> pii;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 2e5 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;


bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void solve() {
    int n; 
    cin >> n;

    vector<int> prs;

    for (int x = 2; prs.size() < n + 1; x++) {
        if (isPrime(x)) {
            prs.push_back(x);
        }
    }
    for (int i = 0; i < n; i++) cout << prs[i] * prs[i + 1] << " ";
    cout << '\n';
}


int32_t main(){
    //freopen("input.txt", "r", stdin);
    fast();
    int t = 1;
    cin >> t;
    while(t--) solve();
}
