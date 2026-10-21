// Generated family: gen2-str2-01
// Labels from first principles.
using namespace std;

bool isPal_0(const string& s) { int l = 0, r = s.size() - 1; while (l < r) { if (s[l] != s[r]) return false; ++l; --r; } return true; }
map<char, int> charFreq_0(const string& s) { map<char, int> freq; for (char c : s) ++freq[c]; return freq; }
bool anagram_0(const string& a, const string& b) { if (a.size() != b.size()) return false; map<char, int> freq; for (char c : a) ++freq[c]; for (char c : b) if (--freq[c] < 0) return false; return true; }
bool isPal_1(const string& s) { int l = 0, r = s.size() - 1; while (l < r) { if (s[l] != s[r]) return false; ++l; --r; } return true; }
map<char, int> charFreq_1(const string& s) { map<char, int> freq; for (char c : s) ++freq[c]; return freq; }
bool anagram_1(const string& a, const string& b) { if (a.size() != b.size()) return false; map<char, int> freq; for (char c : a) ++freq[c]; for (char c : b) if (--freq[c] < 0) return false; return true; }
bool isPal_2(const string& s) { int l = 0, r = s.size() - 1; while (l < r) { if (s[l] != s[r]) return false; ++l; --r; } return true; }
map<char, int> charFreq_2(const string& s) { map<char, int> freq; for (char c : s) ++freq[c]; return freq; }
bool anagram_2(const string& a, const string& b) { if (a.size() != b.size()) return false; map<char, int> freq; for (char c : a) ++freq[c]; for (char c : b) if (--freq[c] < 0) return false; return true; }
bool isPal_3(const string& s) { int l = 0, r = s.size() - 1; while (l < r) { if (s[l] != s[r]) return false; ++l; --r; } return true; }
map<char, int> charFreq_3(const string& s) { map<char, int> freq; for (char c : s) ++freq[c]; return freq; }
bool anagram_3(const string& a, const string& b) { if (a.size() != b.size()) return false; map<char, int> freq; for (char c : a) ++freq[c]; for (char c : b) if (--freq[c] < 0) return false; return true; }
bool isPal_4(const string& s) { int l = 0, r = s.size() - 1; while (l < r) { if (s[l] != s[r]) return false; ++l; --r; } return true; }
map<char, int> charFreq_4(const string& s) { map<char, int> freq; for (char c : s) ++freq[c]; return freq; }
bool anagram_4(const string& a, const string& b) { if (a.size() != b.size()) return false; map<char, int> freq; for (char c : a) ++freq[c]; for (char c : b) if (--freq[c] < 0) return false; return true; }
bool isPal_5(const string& s) { int l = 0, r = s.size() - 1; while (l < r) { if (s[l] != s[r]) return false; ++l; --r; } return true; }
map<char, int> charFreq_5(const string& s) { map<char, int> freq; for (char c : s) ++freq[c]; return freq; }
bool anagram_5(const string& a, const string& b) { if (a.size() != b.size()) return false; map<char, int> freq; for (char c : a) ++freq[c]; for (char c : b) if (--freq[c] < 0) return false; return true; }
