// Generated family: gen5-strings-01
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long polynomialHash_0(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_0(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_0(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_0(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_1(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_1(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_1(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_1(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_2(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_2(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_2(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_2(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_3(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_3(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_3(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_3(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_4(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_4(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_4(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_4(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_5(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_5(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_5(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_5(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_6(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_6(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_6(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_6(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_7(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_7(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_7(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_7(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_8(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_8(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_8(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_8(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_9(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_9(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_9(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_9(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_10(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_10(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_10(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_10(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_11(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_11(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_11(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_11(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_12(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_12(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_12(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_12(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_13(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_13(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_13(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_13(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_14(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_14(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_14(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_14(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_15(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_15(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_15(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_15(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_16(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_16(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_16(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_16(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_17(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_17(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_17(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_17(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_18(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_18(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_18(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_18(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_19(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_19(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_19(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_19(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_20(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_20(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_20(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_20(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_21(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_21(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_21(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_21(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_22(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_22(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_22(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_22(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_23(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_23(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_23(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_23(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
long long polynomialHash_24(const string& s) { long long hash = 0, p = 31, mod = 1e9 + 7, p_pow = 1; for (char c : s) { hash = (hash + (c - 'a' + 1) * p_pow) % mod; p_pow = (p_pow * p) % mod; } return hash; }
int countMatching_24(const string& a, const string& b) { int c = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++c; return c; }
int countUppercase_24(const string& s) { int c = 0; for (char ch : s) if (ch >= 'A' && ch <= 'Z') ++c; return c; }
int consecutiveDuplicates_24(const string& s) { int c = 0; for (size_t i = 1; i < s.size(); ++i) if (s[i] == s[i - 1]) ++c; return c; }
