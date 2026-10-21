// Generated family: gen6-strings-04
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int countSubstringsLenK_50(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_50(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_50(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_50(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_50(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_50(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_51(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_51(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_51(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_51(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_51(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_51(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_52(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_52(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_52(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_52(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_52(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_52(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_53(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_53(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_53(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_53(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_53(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_53(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_54(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_54(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_54(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_54(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_54(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_54(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_55(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_55(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_55(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_55(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_55(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_55(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_56(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_56(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_56(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_56(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_56(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_56(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_57(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_57(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_57(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_57(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_57(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_57(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_58(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_58(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_58(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_58(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_58(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_58(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_59(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_59(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_59(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_59(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_59(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_59(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_60(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_60(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_60(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_60(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_60(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_60(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_61(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_61(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_61(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_61(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_61(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_61(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_62(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_62(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_62(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_62(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_62(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_62(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_63(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_63(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_63(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_63(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_63(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_63(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_64(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_64(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_64(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_64(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_64(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_64(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_65(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_65(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_65(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_65(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_65(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_65(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_66(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_66(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_66(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_66(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
