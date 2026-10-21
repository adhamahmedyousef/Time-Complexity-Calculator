#include <bits/stdc++.h>
using namespace std;

static vector<long long> buildPrefix(const vector<int>& a) {
            vector<long long> pref(a.size() + 1, 0);
            for (size_t i = 0; i < a.size(); ++i) pref[i + 1] = pref[i] + a[i];
            return pref;
        }
        long long pack_l1_offlinePrefixWithHelper(const vector<int>& a, const vector<pair<int,int>>& queries) {
            auto pref = buildPrefix(a);
            long long ans = 0;
            for (auto [l, r] : queries) ans += pref[r + 1] - pref[l];
            return ans;
        }
