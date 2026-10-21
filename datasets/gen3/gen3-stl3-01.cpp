// Generated family: gen3-stl3-01
// Labels from first principles.
using namespace std;

long long rangeForSum_0(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_0(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_0(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_0(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_0(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_0(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_0(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_0(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_0(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_0(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_0(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_0(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
long long rangeForSum_1(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_1(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_1(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_1(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_1(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_1(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_1(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_1(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_1(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_1(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_1(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_1(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
long long rangeForSum_2(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_2(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_2(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_2(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_2(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_2(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_2(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_2(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_2(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_2(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_2(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_2(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
long long rangeForSum_3(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_3(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_3(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_3(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_3(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_3(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_3(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_3(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_3(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_3(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_3(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_3(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
long long rangeForSum_4(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_4(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_4(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_4(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_4(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_4(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_4(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_4(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_4(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_4(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_4(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_4(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
long long rangeForSum_5(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_5(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_5(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_5(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_5(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_5(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_5(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_5(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_5(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_5(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_5(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_5(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
long long rangeForSum_6(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_6(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_6(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_6(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_6(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_6(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_6(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_6(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_6(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_6(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_6(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_6(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
long long rangeForSum_7(const vector<int>& a) { long long s = 0; for (int x : a) s += x; return s; }
int rangeForMax_7(const vector<int>& a) { int best = a[0]; for (int x : a) { if (x > best) best = x; } return best; }
int mapCountFreq_7(const vector<int>& a) { map<int, int> freq; for (int x : a) ++freq[x]; int best = 0; for (const auto& e : freq) if (e.second > best) best = e.second; return best; }
int setInsertLoop_7(int n) { set<int> s; for (int i = 0; i < n; ++i) s.insert(i * 7 % n); return s.size(); }
int sortUniqueCount_7(vector<int>& a) { sort(a.begin(), a.end()); int unique = 0; for (int i = 0; i < (int)a.size(); ++i) if (i == 0 || a[i] != a[i - 1]) ++unique; return unique; }
bool balancedParens_7(const string& s) { stack<char> st; for (char c : s) { if (c == '(') st.push(c); else if (c == ')') { if (st.empty()) return false; st.pop(); } } return st.empty(); }
int queueSimulation_7(int n) { queue<int> q; for (int i = 0; i < n; ++i) q.push(i); int processed = 0; while (!q.empty()) { q.pop(); ++processed; } return processed; }
long long pqPushAll_7(const vector<int>& a) { priority_queue<int> pq; for (int x : a) pq.push(x); long long s = 0; while (!pq.empty()) { s += pq.top(); pq.pop(); } return s; }
void vecPushParam_7(vector<int>& v, int n) { for (int i = 0; i < n; ++i) v.push_back(i * i); }
int dequeBackFront_7(int n) { deque<int> d; for (int i = 0; i < n; ++i) d.push_back(i); int total = 0; while (!d.empty()) { total += d.front(); d.pop_front(); } return total; }
vector<vector<int>> gridFill_7(int n, int m) { vector<vector<int>> g(n, vector<int>(m, 0)); for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) g[i][j] = i * j; return g; }
string stringBuilder_7(const string& s) { string r; for (char c : s) if (c != ' ') r += c; return r; }
