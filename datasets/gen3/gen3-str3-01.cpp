// Generated family: gen3-str3-01
// Labels from first principles.
using namespace std;

int countVowels_0(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_0(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_0(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_0(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_0(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_0(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_0(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_0(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_0(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_0(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
int countVowels_1(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_1(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_1(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_1(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_1(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_1(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_1(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_1(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_1(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_1(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
int countVowels_2(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_2(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_2(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_2(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_2(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_2(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_2(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_2(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_2(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_2(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
int countVowels_3(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_3(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_3(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_3(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_3(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_3(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_3(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_3(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_3(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_3(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
int countVowels_4(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_4(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_4(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_4(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_4(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_4(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_4(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_4(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_4(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_4(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
int countVowels_5(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_5(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_5(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_5(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_5(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_5(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_5(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_5(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_5(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_5(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
int countVowels_6(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_6(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_6(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_6(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_6(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_6(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_6(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_6(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_6(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_6(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
int countVowels_7(const string& s) { int c = 0; for (char ch : s) { if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++c; } return c; }
bool isPalindromeStr_7(const string& s) { int lo = 0, hi = (int)s.size() - 1; while (lo < hi) { if (s[lo] != s[hi]) return false; ++lo; --hi; } return true; }
string reverseStringNew_7(const string& s) { int n = (int)s.size(); string r; for (int i = 0; i < n; ++i) r.push_back(s[n - 1 - i]); return r; }
string removeSpaces_7(const string& s) { string r; for (char ch : s) { if (ch != ' ') r += ch; } return r; }
int charFrequency26_7(const string& s) { int cnt[26] = {0}; for (char ch : s) if (ch >= 'a' && ch <= 'z') ++cnt[ch - 'a']; int best = 0; for (int i = 0; i < 26; ++i) if (cnt[i] > best) best = cnt[i]; return best; }
int longestUniqueWindow_7(const string& s) { int last[128]; for (int i = 0; i < 128; ++i) last[i] = -1; int best = 0, lo = 0; for (int hi = 0; hi < (int)s.size(); ++hi) { if (last[(int)s[hi]] >= lo) lo = last[(int)s[hi]] + 1; last[(int)s[hi]] = hi; if (hi - lo + 1 > best) best = hi - lo + 1; } return best; }
int firstUniqueCharMap_7(const string& s) { map<char, int> freq; for (char ch : s) ++freq[ch]; for (int i = 0; i < (int)s.size(); ++i) if (freq[s[i]] == 1) return i; return -1; }
void toUpperInPlace_7(string& s) { for (int i = 0; i < (int)s.size(); ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; }
string stringCompress_7(const string& s) { string r; for (int i = 0; i < (int)s.size(); ++i) { if (i == 0 || s[i] != s[i - 1]) r.push_back(s[i]); } return r; }
int countSubstringsStart_7(const string& s, char c) { int n = s.size(), total = 0; for (int i = 0; i < n; ++i) if (s[i] == c) total += n - i; return total; }
