#include <bits/stdc++.h>
using namespace std;

long long pack_l2_nonProgressingUnknown(int n) {
    long long x = 1;
    while (x < n) {
        if (rand() & 1) x += 2;
        else x -= 1;
        if (x < 0) x = 1;
    }
    return x;
}
