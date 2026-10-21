#include <bits/stdc++.h>
using namespace std;

int pack_l1_dataDependentLoopProgress(vector<int> vals) {
            int i = 0, cnt = 0;
            while (i < (int)a.size()) {
                i += max(1, a[i] % 3);
                ++cnt;
                if (cnt > 500000) break;
            }
            return cnt;
        }
