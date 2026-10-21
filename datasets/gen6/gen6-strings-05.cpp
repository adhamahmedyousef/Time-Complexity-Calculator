// Generated family: gen6-strings-05
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

string copyAsciiOnly_66(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_66(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
