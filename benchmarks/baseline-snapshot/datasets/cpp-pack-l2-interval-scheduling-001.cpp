#include <bits/stdc++.h>
using namespace std;

int pack_l2_intervalScheduling(vector<pair<int,int>> items) {
    sort(items.begin(), items.end(), [](auto a, auto b){ return a.second < b.second; });
    int cur = INT_MIN, cnt = 0;
    for (auto [l, r] : items) {
        if (l >= cur) { cur = r; ++cnt; }
    }
    return cnt;
}
