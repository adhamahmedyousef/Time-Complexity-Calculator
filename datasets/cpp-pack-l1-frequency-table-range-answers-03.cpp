#include <bits/stdc++.h>
using namespace std;

long long pack_l1_frequencyTableRangeAnswers(const vector<int>& values, const vector<pair<int,int>>& queries) {
            unordered_map<int,int> freq;
            for (int x : values) ++freq[x];
            long long score = 0;
            for (auto [l, r] : queries) score += (freq.count(l) ? freq[l] : 0) + (freq.count(r) ? freq[r] : 0);
            return score;
        }
