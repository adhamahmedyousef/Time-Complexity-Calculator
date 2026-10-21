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


int slidingWindowAtMostK_27(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_27(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_28(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_28(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_28(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_28(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_28(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_28(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_28(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_28(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_28(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_29(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_29(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_29(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_29(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_29(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_29(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_29(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_29(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_29(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_30(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_30(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_30(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_30(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_30(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_30(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_30(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_30(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_30(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_31(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_31(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_31(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_31(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_31(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_31(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_31(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_31(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_31(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_32(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_32(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_32(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_32(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_32(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_32(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_32(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_32(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_32(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_33(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_33(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_33(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }
