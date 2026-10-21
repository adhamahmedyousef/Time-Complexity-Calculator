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
int zAlgorithmSearch_1(const string& text, const string& pat) {
    string s = pat + '$' + text;
    auto z = zf1(s);
    int cnt = 0;
    for (int x : z) if (x == (int)pat.size()) ++cnt;
    return cnt;
}

// trie-insert-search-delete-01
struct Trie_1 {
    struct Node { array<int, 26> nxt; int end = 0; Node() { nxt.fill(-1); } };
    vector<Node> t;
    Trie_1() { t.emplace_back(); }
    void add(const string& s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) { t[u].nxt[x] = (int)t.size(); t.emplace_back(); }
            u = t[u].nxt[x];
        }
        ++t[u].end;
    }
    bool contains(const string& s) const {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) return false;
            u = t[u].nxt[x];
        }
        return t[u].end > 0;
    }
    void erase(const string& s) {
        int u = 0;
        for (char c : s) u = t[u].nxt[c - 'a'];
        if (u >= 0) --t[u].end;
    }
};
int trieOperations_1(const vector<string>& words) {
    Trie_1 tr;
    for (auto& w : words) tr.add(w);
    return (int)tr.t.size();
}

// rolling-hash-window-01
long long pack_cp_requested_dataset_pack_rollingHashWindow_1(const string& s) {
    const long long B = 911382323LL, M = 972663749LL;
    long long h = 0, p = 1;
    for (char c : s) {
        h = (h * B + c) % M;
        p = (p * B) % M;
    }
    return h ^ p;
}
