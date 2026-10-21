#include <bits/stdc++.h>
using namespace std;

int pack_l1_twoPointersFrequencyHybrid(const string& s) {
            array<int, 256> cnt{};
            int l = 0, ans = 0;
            for (int r = 0; r < (int)s.size(); ++r) {
                ++cnt[(unsigned char)s[r]];
                while (cnt[(unsigned char)s[r]] > 1) --cnt[(unsigned char)s[l++]];
                ans = max(ans, r - l + 1);
            }
            return ans;
        }
