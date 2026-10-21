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


bool g8_isPalindrome_0(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_0(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_0(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_0(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_0(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_0(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_0(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_0(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_1(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_1(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_1(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_1(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_1(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_1(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_1(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_1(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_2(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_2(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_2(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_2(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_2(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_2(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_2(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_2(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_3(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_3(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_3(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_3(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_3(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_3(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_3(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_3(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }

bool g8_isPalindrome_4(const string& s) { int lo = 0, hi = static_cast<int>(s.size()) - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; lo++; hi--; } return true; }

vector<int> g8_charFreq_4(const string& s) { vector<int> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

int g8_countVowels_4(const string& s) { int cnt = 0; for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++; return cnt; }

string g8_reverseString_4(string s) { int l = 0, r = static_cast<int>(s.size()) - 1; while (l < r) { swap(s[l++], s[r--]); } return s; }

int g8_prefixMatch_4(const string& s, const string& t) { int n = min(s.size(), t.size()), matched = 0; for (int i = 0; i < n; ++i) { if (s[i] == t[i]) matched++; else break; } return matched; }

void g8_toUpper_4(string& s) { for (int i = 0; i < static_cast<int>(s.size()); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; }

int g8_strDiff_4(const string& a, const string& b) { int diff = 0, n = min(a.size(), b.size()); for (int i = 0; i < n; ++i) if (a[i] != b[i]) diff++; return diff; }

int g8_runLengthCount_4(const string& s) { if (s.empty()) return 0; int runs = 1; for (size_t i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) runs++; return runs; }
