#include <bits/stdc++.h>
using namespace std;

int pack_l2_earlyReturnCorrelated(const vector<int>& a) {
    int i = 0, j = (int)a.size() - 1, ans = 0;
    while (i < j) {
        if (a[i] + a[j] > 0) return ans;
        if ((a[i] & 1) == 0) ++i;
        else --j;
        ++ans;
    }
    return ans;
}
