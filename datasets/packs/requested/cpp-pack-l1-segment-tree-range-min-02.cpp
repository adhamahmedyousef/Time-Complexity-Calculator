#include <bits/stdc++.h>
using namespace std;

struct Seg {
            int n;
            vector<int> t;
            Seg(const vector<int>& a): n((int)a.size()), t(4 * max(1, (int)a.size()), INT_MAX) {
                build(1, 0, n - 1, a);
            }
            void build(int p, int l, int r, const vector<int>& a) {
                if (l == r) { t[p] = a[l]; return; }
                int m = (l + r) / 2;
                build(p << 1, l, m, a);
                build(p << 1 | 1, m + 1, r, a);
                t[p] = min(t[p << 1], t[p << 1 | 1]);
            }
            int query(int p, int l, int r, int ql, int qr) const {
                if (qr < l || r < ql) return INT_MAX;
                if (ql <= l && r <= qr) return t[p];
                int m = (l + r) / 2;
                return min(query(p << 1, l, m, ql, qr), query(p << 1 | 1, m + 1, r, ql, qr));
            }
        };
        int pack_l1_segmentTreeRangeMin(const vector<int>& a, const vector<pair<int,int>>& queries) {
            Seg s(a);
            int ans = 0;
            for (auto [l, r] : queries) ans += s.query(1, 0, (int)a.size() - 1, l, r);
            return ans;
        }
