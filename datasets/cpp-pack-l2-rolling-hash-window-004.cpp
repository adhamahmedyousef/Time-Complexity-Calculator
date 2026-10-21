#include <bits/stdc++.h>
using namespace std;

long long pack_l2_rollingHashWindow(const string& s) {
    const long long B = 911382323LL, M = 972663749LL;
    long long h = 0, p = 1;
    for (char c : s) {
        h = (h * B + c) % M;
        p = (p * B) % M;
    }
    return h ^ p;
}
