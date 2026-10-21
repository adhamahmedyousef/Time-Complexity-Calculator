#include <bits/stdc++.h>
using namespace std;

int sampleUnorderedMapNestedWorstCase(const vector<int>& a) { unordered_map<int,int> mp; int ans = 0; for (int x : a) { mp[x] = x; for (int y : a) if (mp.find(y) != mp.end()) ++ans; } return ans; }
long long sampleStringConcatLoop(const vector<string>& parts) { string value; for (const string& part : parts) value += part; return static_cast<long long>(value.size()); }
void sampleVectorInsertFront(vector<int> a, int x) { for (int i = 0; i < x; ++i) a.insert(a.begin(), i); }
int sampleSortEveryPrefix(vector<int> a) { int score = 0; for (int i = 1; i <= static_cast<int>(a.size()); ++i) { sort(a.begin(), a.begin() + i); score += a[i - 1]; } return score; }
int sampleSetOps(const vector<int>& a) { set<int> s; for (int x : a) s.insert(x); int count = 0; for (int x : a) if (s.find(x) != s.end()) ++count; return count; }
long long sampleHashHeavyInsideLoop(const vector<int>& a) { unordered_map<int,int> mp; long long result = 0; for (int x : a) { ++mp[x]; result += mp.size(); } return result; }
