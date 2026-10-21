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


bool g8_isPalindrome_35(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_35(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_35(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_35(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_35(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_35(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_35(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_35(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_36(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_36(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_36(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_36(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_36(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_36(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_36(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_36(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_37(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_37(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_37(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_37(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_37(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_37(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_37(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_37(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_38(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_38(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_38(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_38(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_38(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_38(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_38(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_38(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_39(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_39(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_39(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_39(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_39(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_39(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_39(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_39(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }
