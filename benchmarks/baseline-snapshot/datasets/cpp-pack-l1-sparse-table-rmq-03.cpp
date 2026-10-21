#include <bits/stdc++.h>
using namespace std;

int pack_l1_sparseTableRMQ(const vector<int>& a, const vector<pair<int,int>>& qs) {
            int n = (int)a.size();
            int K = 32 - __builtin_clz(max(1, n));
            vector<vector<int>> st(K, vector<int>(n));
            st[0] = a;
            for (int k = 1; k < K; ++k)
                for (int i = 0; i + (1 << k) <= n; ++i)
                    st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            int ans = 0;
            for (auto [l, r] : qs) {
                int len = r - l + 1;
                int k = 31 - __builtin_clz(len);
                ans += min(st[k][l], st[k][r - (1 << k) + 1]);
            }
            return ans;
        }
