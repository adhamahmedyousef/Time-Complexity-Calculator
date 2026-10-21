#include <bits/stdc++.h>
using namespace std;

vector<long long> pack_l1_differenceArrayRangeUpdates(int n, const vector<tuple<int,int,int>>& updates) {
            vector<long long> diff(n + 1, 0);
            for (auto [l, r, add] : updates) {
                diff[l] += add;
                if (r + 1 < n) diff[r + 1] -= add;
            }
            vector<long long> a(n, 0);
            long long cur = 0;
            for (int i = 0; i < n; ++i) {
                cur += diff[i];
                a[i] = cur;
            }
            return a;
        }
