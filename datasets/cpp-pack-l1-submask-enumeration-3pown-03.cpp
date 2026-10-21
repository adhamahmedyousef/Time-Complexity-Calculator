#include <bits/stdc++.h>
using namespace std;

long long pack_l1_submaskEnumeration(int n) {
            long long cnt = 0;
            for (int mask = 0; mask < (1 << n); ++mask) {
                for (int sub = mask; sub; sub = (sub - 1) & mask) ++cnt;
            }
            return cnt;
        }
