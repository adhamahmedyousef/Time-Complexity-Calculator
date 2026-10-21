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


int g8_slideSum_35(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_35(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_35(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_35(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_35(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_35(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_35(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_35(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_36(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_36(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_36(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_36(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_36(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_36(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_36(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_36(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_37(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_37(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_37(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_37(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_37(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_37(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_37(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_37(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_38(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_38(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_38(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_38(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_38(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_38(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_38(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_38(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }

int g8_slideSum_39(const vector<int>& a, int limit) { int left = 0, sum = 0, ans = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { sum += a[right]; while (sum > limit) { sum -= a[left++]; } ans = max(ans, right - left + 1); } return ans; }

int g8_slideDiff_39(const vector<int>& a, int k) { int left = 0, cur = 0; for (int right = 0; right < static_cast<int>(a.size()); ++right) { cur += a[right]; while (cur >= k && left <= right) { cur -= a[left]; left++; } } return left; }

int g8_slideCount_39(vector<int>& v, int threshold) { int l = 0, cnt = 0; for (int r = 0; r < static_cast<int>(v.size()); ++r) { cnt += v[r]; while (cnt > threshold) { cnt -= v[l++]; } } return cnt; }

void g8_slideFixed_39(const vector<int>& a, int k) { if (k <= 0 || a.empty()) return; int cur = 0; for (int i = 0; i < k && i < static_cast<int>(a.size()); ++i) cur += a[i]; for (int i = k; i < static_cast<int>(a.size()); ++i) { cur += a[i] - a[i - k]; } }

int g8_slideTwoPtr_39(vector<int>& a, int val) { int l = 0, r = static_cast<int>(a.size()) - 1, ans = 0; while (l < r) { if (a[l] + a[r] == val) { ans++; l++; r--; } else if (a[l] + a[r] < val) { l++; } else { r--; } } return ans; }

int g8_slidePrefix_39(const vector<int>& a, int limit) { int l = 0, total = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { total += a[r]; while (total > limit && l <= r) { total -= a[l]; ++l; } } return l; }

int g8_slideNonneg_39(const vector<int>& a, int maxVal) { int left = 0, cur = 0; for (int i = 0; i < static_cast<int>(a.size()); ++i) { cur += a[i]; while (cur > maxVal && left <= i) { cur -= a[left++]; } } return left; }

int g8_slideSubstr_39(const vector<int>& a, int target) { int l = 0, s = 0; for (int r = 0; r < static_cast<int>(a.size()); ++r) { s += a[r]; while (s > target) { s -= a[l++]; } } return s; }
