#include <bits/stdc++.h>
using namespace std;

int pack_l2_sweepLineEvents(vector<pair<int,int>> intervals) {
    vector<pair<int,int>> ev;
    for (auto [l, r] : intervals) {
        ev.push_back({l, +1});
        ev.push_back({r, -1});
    }
    sort(ev.begin(), ev.end());
    int cur = 0, best = 0;
    for (auto [x, t] : ev) {
        cur += t;
        best = max(best, cur);
    }
    return best;
}
