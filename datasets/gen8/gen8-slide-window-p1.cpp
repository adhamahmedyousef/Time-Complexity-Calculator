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


int g8_slideSum_0(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_0(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_0(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_0(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_0(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_0(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_0(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_0(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_1(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_1(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_1(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_1(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_1(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_1(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_1(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_1(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_2(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_2(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_2(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_2(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_2(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_2(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_2(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_2(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_3(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_3(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_3(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_3(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_3(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_3(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_3(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_3(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_4(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_4(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_4(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_4(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_4(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_4(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_4(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_4(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }
