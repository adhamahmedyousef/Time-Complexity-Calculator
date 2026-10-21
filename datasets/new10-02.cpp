// Omar

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout<<"YES"<<'\n';
        cout<<(n + 1) / 2 <<" "<<(n - 1) / 2<<'\n';
    }

    return 0;
}