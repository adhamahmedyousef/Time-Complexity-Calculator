// Generated family: gen6-strings-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int countSubstringsLenK_0(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_0(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_0(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_0(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_0(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_0(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_1(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_1(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_1(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_1(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_1(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_1(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_2(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_2(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_2(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_2(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_2(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_2(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_3(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_3(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_3(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_3(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_3(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_3(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_4(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_4(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_4(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_4(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_4(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_4(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_5(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_5(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_5(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_5(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_5(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_5(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_6(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_6(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_6(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_6(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_6(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_6(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_7(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_7(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_7(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_7(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_7(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_7(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_8(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_8(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_8(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_8(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_8(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_8(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_9(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_9(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_9(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_9(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_9(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_9(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_10(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_10(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_10(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_10(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_10(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_10(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_11(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_11(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_11(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_11(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_11(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_11(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_12(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_12(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_12(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_12(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_12(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_12(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_13(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_13(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_13(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_13(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_13(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_13(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_14(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_14(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_14(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_14(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_14(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_14(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_15(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_15(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_15(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_15(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_15(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_15(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_16(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_16(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_16(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_16(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
