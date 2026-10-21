#include <bits/stdc++.h>
using namespace std;

long long pack_l1_slidingWindowPrefixHybrid(const vector<int>& a) {
            long long cur = 0, best = 0;
            int l = 0;
            for (int r = 0; r < (int)a.size(); ++r) {
                cur += a[r];
                while (l <= r && cur > 700) cur -= a[l++];
                best = max(best, cur);
            }
            return best;
        }
