// Omar

#include <bits/stdc++.h>
using namespace std;
#define chocolatemilk ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define ld long double
const int N = 24 * 60 + 5 ;
ll arr [N];
int main() {
    chocolatemilk
   ll t ; 
   cin >> t ; 
   while (t --){
    ll n ; 
    cin >> n ; 
    if (n <= 2 ){
        cout << 0 << endl;
            continue ;
    }
    cout << n -1 << endl;
         n --;
    for (int i = 0 ; i < n - 1; i ++){
        if (i % 2) 
            cout << "B" ;
        else 
            cout << "F" ;
    }   
     cout << "B" << endl;
   }
}