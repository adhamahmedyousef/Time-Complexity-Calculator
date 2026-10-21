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


bool g8_isPalindrome_25(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_25(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_25(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_25(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_25(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_25(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_25(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_25(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_26(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_26(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_26(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_26(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_26(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_26(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_26(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_26(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_27(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_27(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_27(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_27(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_27(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_27(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_27(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_27(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_28(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_28(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_28(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_28(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_28(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_28(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_28(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_28(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_29(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_29(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_29(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_29(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_29(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_29(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_29(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_29(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }
