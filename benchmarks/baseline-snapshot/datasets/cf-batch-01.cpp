// 1
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
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0 ; i < n - 1 ; i++) cin >> arr[i];

    sort(arr.begin() , arr.end());
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] != i){
            cout << i;
            break;
        }
    }

}

int main(){
    //freopen("input.txt", "r", stdin);
    fast();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
