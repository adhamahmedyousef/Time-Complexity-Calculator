#include <bits/stdc++.h>
using namespace std;

int pack_l2_suffixPrefixFrequency(const string& s) {
    array<int, 256> cnt{};
    for (unsigned char c : s) ++cnt[c];
    int ans = 0;
    for (int i = 0; i < 256; ++i) ans += cnt[i];
    return ans;
}
