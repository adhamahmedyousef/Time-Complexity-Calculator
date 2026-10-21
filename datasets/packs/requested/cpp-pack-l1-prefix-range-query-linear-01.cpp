#include <bits/stdc++.h>
using namespace std;

long long pack_l1_prefixRangeQuery(vector<int> vals, const vector<pair<int,int>>& qs) {
            vector<long long> ps(vals.size() + 1, 0);
            for (size_t i = 0; i < vals.size(); ++i) ps[i + 1] = ps[i] + vals[i];
            long long ans = 0;
            for (auto [l, r] : qs) ans += ps[r + 1] - ps[l];
            return ans;
        }
