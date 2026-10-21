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


int slidingWindowLimit_0(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_0(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_0(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_0(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_0(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_0(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_0(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_0(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_0(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_1(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_1(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_1(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_1(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_1(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_1(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_1(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_1(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_1(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_2(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_2(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_2(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_2(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_2(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_2(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_2(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_2(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_2(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_3(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_3(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_3(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_3(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_3(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_3(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_3(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_3(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_3(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_4(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_4(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_4(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_4(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_4(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_4(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_4(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_4(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_4(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_5(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_5(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_5(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_5(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_5(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }
