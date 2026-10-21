// Omar

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mn = 2e9;
    int mx = 0;

    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;

        mn = min(mn , x);
        mx = max(mx , x);
    }

    cout<<mx-mn<<'\n';

    return 0;
}