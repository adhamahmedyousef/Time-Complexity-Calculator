#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node { array<int, 26> nxt; bool end = false; Node() { nxt.fill(-1); } };
    vector<Node> t;
    Trie() { t.emplace_back(); }
    void add(const string& s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) { t[u].nxt[x] = (int)t.size(); t.emplace_back(); }
            u = t[u].nxt[x];
        }
        t[u].end = true;
    }
};
int pack_l2_trieInsertLookup(const vector<string>& words) {
    Trie tr;
    for (auto& w : words) tr.add(w);
    return (int)tr.t.size();
}
