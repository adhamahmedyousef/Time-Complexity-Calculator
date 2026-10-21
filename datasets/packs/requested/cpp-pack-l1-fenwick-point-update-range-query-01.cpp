#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
            int n;
            vector<long long> bit;
            Fenwick(int n): n(n), bit(n + 1) {}
            void add(int i, long long v) { for (; i <= n; i += i & -i) bit[i] += v; }
            long long sum(int i) const { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
        };
        long long pack_l1_fenwickPointUpdateRangeQuery(int n, const vector<pair<int,int>>& qs) {
            Fenwick f(n);
            for (int i = 1; i <= n; ++i) f.add(i, i);
            long long score = 0;
            for (auto [l, r] : qs) score += f.sum(r) - f.sum(l - 1);
            return score;
        }
