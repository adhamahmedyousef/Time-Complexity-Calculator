#include <bits/stdc++.h>
using namespace std;

// kmp-search-01
vector<int> pi1(const string& p) {
    vector<int> f(p.size(), 0);
    for (int i = 1; i < (int)p.size(); ++i) {
        int j = f[i - 1];
        while (j && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) ++j;
        f[i] = j;
    }
    return f;
}
int kmpSearch_1(const string& text, const string& pat) {
    auto f = pi1(pat);
    int j = 0, hits = 0;
    for (char c : text) {
        while (j && c != pat[j]) j = f[j - 1];
        if (c == pat[j]) ++j;
        if (j == (int)pat.size()) { ++hits; j = f[j - 1]; }
    }
    return hits;
}

// z-algorithm-01
vector<int> zf1(const string& s) {
    int n = (int)s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
int pack_cp_requested_dataset_pack_zAlgorithmSearch_1(const string& text, const string& pat) {
    string s = pat + '$' + text;
    auto z = zf1(s);
    int cnt = 0;
    for (int x : z) if (x == (int)pat.size()) ++cnt;
    return cnt;
}
