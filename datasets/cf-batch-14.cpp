// 14
#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
#define int int64
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
#define vc  vector<char>
#define vb  vector<bool>

#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
typedef unordered_set<int> ss;

#define fast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define endl '\n'
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    int n , m; cin >> n >> m;
    vi arr1(n) , arr2(m);

    for(int i = 0 ; i < n ; i++) cin >> arr1[i];
    for(int i = 0 ; i < m ; i++) cin >> arr2[i];

    vi res;
    int l = 0 , r = 0;
    while(l < n && r < m){
        if(arr1[l] < arr2[r]){
            res.push_back(arr1[l]);
            l++;
        }else{
            res.push_back(arr2[r]);
            r++;
        }
    }
    for(int i = l ; i < n ; i++)res.push_back(arr1[i]);
    for(int i = r ; i < m ; i++)res.push_back(arr2[i]);
    for(int i = 0 ; i < res.size() ; i++) cout << res[i] << " ";

}

int32_t main() {
    fast();
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
