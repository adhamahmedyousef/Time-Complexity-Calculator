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


int g8_slideSum_30(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_30(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_30(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_30(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_30(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_30(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_30(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_30(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_31(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_31(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_31(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_31(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_31(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_31(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_31(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_31(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_32(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_32(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_32(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_32(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_32(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_32(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_32(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_32(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_33(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_33(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_33(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_33(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_33(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_33(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_33(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_33(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_34(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_34(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_34(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_34(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_34(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_34(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_34(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_34(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }
