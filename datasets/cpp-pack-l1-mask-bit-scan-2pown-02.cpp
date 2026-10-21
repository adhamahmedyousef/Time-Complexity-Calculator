#include <bits/stdc++.h>
using namespace std;

long long pack_l1_maskBitScan(int n) {
            long long ops = 0;
            for (int mask = 0; mask < (1 << n); ++mask)
                for (int i = 0; i < n; ++i)
                    if (mask & (1 << i)) ++ops;
            return ops;
        }
