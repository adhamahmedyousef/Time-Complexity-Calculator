// Generated family: gen6-strings-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

string copyAsciiOnly_16(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_16(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_17(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_17(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_17(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_17(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_17(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_17(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_18(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_18(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_18(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_18(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_18(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_18(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_19(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_19(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_19(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_19(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_19(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_19(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_20(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_20(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_20(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_20(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_20(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_20(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_21(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_21(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_21(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_21(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_21(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_21(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_22(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_22(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_22(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_22(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_22(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_22(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_23(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_23(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_23(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_23(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_23(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_23(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_24(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_24(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_24(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_24(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_24(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_24(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_25(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_25(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_25(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_25(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_25(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_25(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_26(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_26(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_26(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_26(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_26(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_26(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_27(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_27(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_27(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_27(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_27(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_27(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_28(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_28(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_28(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_28(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_28(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_28(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_29(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_29(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_29(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_29(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_29(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_29(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_30(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_30(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_30(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_30(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_30(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_30(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_31(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_31(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_31(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_31(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_31(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_31(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_32(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_32(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_32(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_32(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_32(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_32(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_33(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_33(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
