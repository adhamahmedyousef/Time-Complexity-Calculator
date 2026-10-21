// Generated family: gen6-strings-03
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int countLetterPairs_33(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_33(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_33(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_33(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_34(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_34(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_34(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_34(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_34(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_34(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_35(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_35(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_35(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_35(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_35(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_35(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_36(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_36(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_36(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_36(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_36(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_36(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_37(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_37(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_37(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_37(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_37(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_37(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_38(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_38(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_38(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_38(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_38(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_38(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_39(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_39(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_39(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_39(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_39(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_39(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_40(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_40(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_40(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_40(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_40(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_40(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_41(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_41(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_41(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_41(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_41(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_41(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_42(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_42(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_42(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_42(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_42(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_42(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_43(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_43(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_43(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_43(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_43(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_43(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_44(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_44(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_44(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_44(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_44(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_44(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_45(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_45(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_45(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_45(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_45(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_45(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_46(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_46(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_46(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_46(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_46(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_46(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_47(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_47(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_47(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_47(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_47(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_47(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_48(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_48(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_48(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_48(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_48(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_48(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countSubstringsLenK_49(const string& s, int k) { int n = s.size(); return n >= k ? n - k + 1 : 0; }
int countMatchingChars_49(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countLetterPairs_49(const string& s) { int cnt = 0; for (int i = 0; i + 1 < (int)s.size(); ++i) if (s[i] == s[i + 1]) ++cnt; return cnt; }
int countDigitsInString_49(const string& s) { int d = 0; for (char c : s) if (c >= '0' && c <= '9') ++d; return d; }
string copyAsciiOnly_49(const string& s) { string r; for (char c : s) if (c >= 0 && c <= 127) r.push_back(c); return r; }
long long polynomialHash_49(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
