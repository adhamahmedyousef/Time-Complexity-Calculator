#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
using namespace std;


int slidingWindowNonNegative_33(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_33(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_33(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_33(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_33(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_33(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_34(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_34(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_34(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_34(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_34(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_34(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_34(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_34(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_34(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_35(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_35(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_35(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_35(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_35(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_35(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_35(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_35(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_35(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_36(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_36(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_36(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_36(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_36(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_36(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_36(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_36(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_36(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_37(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_37(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_37(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_37(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_37(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_37(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_37(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_37(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_37(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_38(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_38(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_38(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_38(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_38(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_38(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_38(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_38(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }
