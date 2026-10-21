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


bool g8_isPalindrome_15(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_15(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_15(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_15(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_15(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_15(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_15(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_15(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_16(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_16(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_16(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_16(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_16(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_16(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_16(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_16(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_17(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_17(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_17(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_17(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_17(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_17(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_17(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_17(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_18(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_18(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_18(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_18(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_18(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_18(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_18(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_18(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_19(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_19(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_19(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_19(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_19(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_19(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_19(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_19(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }
