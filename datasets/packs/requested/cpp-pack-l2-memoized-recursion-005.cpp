#include <bits/stdc++.h>
using namespace std;

long long pack_l2_memoizedRecursion(int n) {
    vector<long long> memo(n + 1, -1);
    function<long long(int)> f = [&](int x) -> long long {
        if (x <= 1) return 1;
        auto& r = memo[x];
        if (r != -1) return r;
        return r = f(x - 1) + f(x - 2);
    };
    return f(n);
}
