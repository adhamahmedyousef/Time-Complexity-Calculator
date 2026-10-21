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


int slidingWindowPreInc_11(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_11(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_11(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_11(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_11(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_11(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_11(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_11(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_12(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_12(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_12(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_12(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_12(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_12(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_12(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_12(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_12(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_13(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_13(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_13(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_13(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_13(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_13(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_13(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_13(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_13(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_14(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_14(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_14(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_14(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_14(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_14(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_14(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_14(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_14(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_15(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_15(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_15(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_15(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_15(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_15(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

long long slidingWindowProduct_15(const vector<int>& a, long long k) { if (k <= 1) return 0; long long prod = 1, ans = 0; int left = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { prod *= a[right]; while (prod >= k) prod /= a[left++]; ans += right - left + 1; } return ans; }

int slidingWindowAtMostK_15(const string& s, int k) { int left = 0, best = 0; int odd = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { if (s[right] % 2 != 0) ++odd; while (odd > k) { if (s[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }

int slidingWindowCharFreq_15(const string& s, int maxLen) { int left = 0, best = 0; for (int right = 0; right < static_cast<int>(s.size()); ++right) { while (right - left + 1 > maxLen) ++left; best = max(best, right - left + 1); } return best; }

int slidingWindowLimit_16(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) sum -= a[left++]; best = max(best, right - left + 1); } return best; }

int slidingWindowPreInc_16(const vector<int>& a, int limit) { int left = 0, sum = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left]; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowString_16(const string& s) { int left = 0, best = 0; int freq[256] = {0}; for (int right = 0; right < static_cast<int>(s.size()); ++right) { freq[static_cast<unsigned char>(s[right])]++; while (freq[static_cast<unsigned char>(s[right])] > 1) { freq[static_cast<unsigned char>(s[left++])]--; } best = max(best, right - left + 1); } return best; }

int slidingWindowNonNegative_16(const vector<int>& a, int k) { int left = 0, zeroes = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] == 0) ++zeroes; while (zeroes > k) { if (a[left] == 0) --zeroes; ++left; } best = max(best, right - left + 1); } return best; }

int slidingWindowMinSubarray_16(const vector<int>& a) { int left = 0, sum = 0, n = static_cast<int>(a.size()), best = n + 1; for (int right = 0; right < n; ++right) { sum += a[right]; while (sum > 100) { best = min(best, right - left + 1); sum -= a[left++]; } } return best <= n ? best : 0; }

int slidingWindowTwoPtrK_16(const vector<int>& a, int k) { int left = 0, odd = 0, best = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { if (a[right] % 2 != 0) ++odd; while (odd > k) { if (a[left++] % 2 != 0) --odd; } best = max(best, right - left + 1); } return best; }
