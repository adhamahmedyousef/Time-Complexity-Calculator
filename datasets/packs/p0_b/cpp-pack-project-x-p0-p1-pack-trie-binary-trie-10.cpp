#include <bits/stdc++.h>
using namespace std;


// trie-binary-trie-01
struct T_01 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_01(const vector<string>& words) { T_01 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-02
struct T_02 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_02(const vector<string>& words) { T_02 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-03
struct T_03 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_03(const vector<string>& words) { T_03 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-04
struct T_04 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_04(const vector<string>& words) { T_04 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-05
struct T_05 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_05(const vector<string>& words) { T_05 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-06
struct T_06 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_06(const vector<string>& words) { T_06 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-07
struct T_07 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_07(const vector<string>& words) { T_07 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-08
struct T_08 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_08(const vector<string>& words) { T_08 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-09
struct T_09 { struct Node { array<int,2> ch{-1,-1}; }; vector<Node> t{Node()}; void add(const string& s) { int u=0; for (char c:s) { int b=c&1; if (t[u].ch[b]==-1) { t[u].ch[b]=t.size(); t.push_back(Node()); } u=t[u].ch[b]; } } };
long long trie_binary_trie_09(const vector<string>& words) { T_09 tr; for (auto& w:words) tr.add(w); return (long long)tr.t.size(); }

// trie-binary-trie-10
long long pack_project_x_p0_p1_pack_trie_binary_trie_10(int n) { while (n > 0) { if (n & 1) n -= 3; else n += 1; if (n > 1000000) break; } return n; }
