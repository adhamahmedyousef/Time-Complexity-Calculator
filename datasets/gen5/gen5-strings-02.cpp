// Generated family: gen5-strings-02
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long polynomialHash_25(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_25(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_25(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_25(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_26(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_26(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_26(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_26(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_27(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_27(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_27(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_27(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_28(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_28(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_28(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_28(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_29(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_29(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_29(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_29(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
