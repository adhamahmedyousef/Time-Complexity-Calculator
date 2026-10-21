#include <bits/stdc++.h>
using namespace std;

vector<int> pi(const string& p) {
    vector<int> f(p.size(), 0);
    for (int i = 1; i < (int)p.size(); ++i) {
        int j = f[i - 1];
        while (j && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) ++j;
        f[i] = j;
    }
    return f;
}
int pack_l2_kmpSearch(const string& s, const string& pat) {
    auto f = pi(pat);
    int j = 0, hits = 0;
    for (char c : s) {
        while (j && c != pat[j]) j = f[j - 1];
        if (c == pat[j]) ++j;
        if (j == (int)pat.size()) { ++hits; j = f[j - 1]; }
    }
    return hits;
}
