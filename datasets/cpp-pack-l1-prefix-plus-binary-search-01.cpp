#include <bits/stdc++.h>
using namespace std;

long long pack_l1_prefixBinarySearchHybrid(const vector<int>& a) {
            vector<long long> pref(a.size() + 1, 0);
            for (size_t i = 0; i < a.size(); ++i) pref[i + 1] = pref[i] + a[i];
            long long ans = 0;
            for (size_t q = 0; q < a.size(); ++q) {
                size_t lo = 0, hi = a.size();
                while (lo < hi) {
                    size_t mid = (lo + hi) / 2;
                    if (pref[mid] < pref[q]) lo = mid + 1;
                    else hi = mid;
                }
                ans += lo;
            }
            return ans;
        }
