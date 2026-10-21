#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


bool g8_isPalindrome_20(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_20(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_20(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_20(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_20(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_20(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_20(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_20(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_21(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_21(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_21(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_21(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_21(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_21(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_21(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_21(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_22(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_22(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_22(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_22(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_22(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_22(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_22(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_22(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_23(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_23(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_23(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_23(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_23(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_23(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_23(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_23(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_24(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_24(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_24(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_24(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_24(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_24(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_24(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_24(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }
