// Project X - Complexity Analyzer Dataset
// Family: two-pointers-sliding-window
// All functions are self-contained, valid, standalone C++17.
// No external/scraped code. Freshly authored for static-analysis testing.

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------
// Case: two-sum-sorted-two-pointer
// Normal case: classic converging two-pointer scan on a sorted array.
// -----------------------------------------------------------------------
bool twoSumSortedTwoPointer(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int sum = a[lo] + a[hi];
        if (sum == target) return true;
        else if (sum < target) lo++;
        else hi--;
    }
    return false;
}

// -----------------------------------------------------------------------
// Case: max-subarray-sum-fixed-window
// Normal case: fixed-size sliding window of length k.
// -----------------------------------------------------------------------
long long maxSubarraySumFixedWindow(const vector<int>& a, int k) {
    long long windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += a[i];
    long long best = windowSum;
    for (size_t i = k; i < a.size(); i++) {
        windowSum += a[i] - a[i - k];
        best = max(best, windowSum);
    }
    return best;
}

// -----------------------------------------------------------------------
// Case: longest-substring-no-repeat-chars
// Normal case: variable-size sliding window, right advances every step,
// left only advances forward, never backtracks.
// -----------------------------------------------------------------------
int longestSubstringNoRepeatChars(const string& s) {
    array<int, 256> lastSeen;
    lastSeen.fill(-1);
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        unsigned char c = s[right];
        if (lastSeen[c] >= left) {
            left = lastSeen[c] + 1;
        }
        lastSeen[c] = right;
        best = max(best, right - left + 1);
    }
    return best;
}

// -----------------------------------------------------------------------
// Case: merge-two-sorted-arrays-two-pointer
// Normal case: two independent monotonic pointers into two input arrays.
// -----------------------------------------------------------------------
vector<int> mergeTwoSortedArraysTwoPointer(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    result.reserve(a.size() + b.size());
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}

// -----------------------------------------------------------------------
// Case: remove-duplicates-sorted-array-two-pointer
// Normal case: slow/fast pointer in-place compaction.
// -----------------------------------------------------------------------
int removeDuplicatesSortedArrayTwoPointer(vector<int>& a) {
    if (a.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < (int)a.size(); fast++) {
        if (a[fast] != a[slow]) {
            slow++;
            a[slow] = a[fast];
        }
    }
    return slow + 1;
}

// -----------------------------------------------------------------------
// Case: three-sum-two-pointer-inner-loop
// Normal case: outer loop plus an inner converging two-pointer scan,
// applied after sorting.
// -----------------------------------------------------------------------
vector<array<int, 3>> threeSumTwoPointerInnerLoop(vector<int> a) {
    sort(a.begin(), a.end());
    vector<array<int, 3>> triples;
    int n = (int)a.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            long long sum = (long long)a[i] + a[lo] + a[hi];
            if (sum == 0) {
                triples.push_back({a[i], a[lo], a[hi]});
                lo++;
                hi--;
            } else if (sum < 0) {
                lo++;
            } else {
                hi--;
            }
        }
    }
    return triples;
}

// -----------------------------------------------------------------------
// Case: container-with-most-water-two-pointer
// Normal case: single pass, two pointers each move at most n times total.
// -----------------------------------------------------------------------
long long containerWithMostWaterTwoPointer(const vector<int>& height) {
    int lo = 0, hi = (int)height.size() - 1;
    long long best = 0;
    while (lo < hi) {
        long long h = min(height[lo], height[hi]);
        long long area = h * (long long)(hi - lo);
        best = max(best, area);
        if (height[lo] < height[hi]) lo++;
        else hi--;
    }
    return best;
}

// -----------------------------------------------------------------------
// Case: min-length-subarray-sum-at-least-target
// Normal case: classic shrinking sliding window; right advances n times
// total and left advances at most n times total across the whole run.
// -----------------------------------------------------------------------
int minLengthSubarraySumAtLeastTarget(const vector<int>& a, long long target) {
    int left = 0, best = INT_MAX;
    long long windowSum = 0;
    for (int right = 0; right < (int)a.size(); right++) {
        windowSum += a[right];
        while (windowSum >= target) {
            best = min(best, right - left + 1);
            windowSum -= a[left];
            left++;
        }
    }
    return best == INT_MAX ? 0 : best;
}

// -----------------------------------------------------------------------
// Case: dutch-flag-partition-three-pointer
// Normal case: three cooperating pointers (low, mid, high), each element
// examined a bounded number of times.
// -----------------------------------------------------------------------
void dutchFlagPartitionThreePointer(vector<int>& a) {
    int low = 0, mid = 0, high = (int)a.size() - 1;
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

// -----------------------------------------------------------------------
// Case: two-pointer-nested-while-with-reset
// Adversarial case: on every outer step the inner pointer is reset back
// close to the outer pointer instead of continuing forward, producing
// quadratic behavior in the worst case.
// -----------------------------------------------------------------------
int twoPointerNestedWhileWithReset(const vector<int>& a) {
    int n = (int)a.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1; // resets every outer iteration instead of persisting
        while (j < n && a[j] > a[i]) {
            count++;
            j++;
        }
    }
    return count;
}

// -----------------------------------------------------------------------
// Case: two-pointer-conditional-skip-multiple
// Unknown case: the right pointer's advance amount is read from the array
// data itself and may be zero, so forward progress is not guaranteed from
// the code alone; the number of iterations is data-dependent and could be
// unbounded for adversarial input (e.g., a run of zeros).
// -----------------------------------------------------------------------
int twoPointerConditionalSkipMultiple(const vector<int>& a) {
    int right = 0, steps = 0;
    int n = (int)a.size();
    while (right < n) {
        int jump = a[right]; // may be 0 or negative depending on data
        right += jump;
        steps++;
    }
    return steps;
}

// -----------------------------------------------------------------------
// Case: is-palindrome-two-pointer
// Normal case: converging two-pointer scan from both ends of a string.
// -----------------------------------------------------------------------
bool isPalindromeTwoPointer(const string& s) {
    int lo = 0, hi = (int)s.size() - 1;
    while (lo < hi) {
        if (s[lo] != s[hi]) return false;
        lo++;
        hi--;
    }
    return true;
}

// -----------------------------------------------------------------------
// Case: longest-substring-at-most-k-distinct
// Normal case: variable sliding window backed by an unordered_map keyed
// by character frequency; right advances n times, left advances at most
// n times total across the whole scan.
// -----------------------------------------------------------------------
int longestSubstringAtMostKDistinct(const string& s, int k) {
    unordered_map<char, int> freq;
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        freq[s[right]]++;
        while ((int)freq.size() > k) {
            char c = s[left];
            freq[c]--;
            if (freq[c] == 0) freq.erase(c);
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

// -----------------------------------------------------------------------
// Case: merge-overlapping-intervals-two-pointer
// Normal case: single forward pass over pre-sorted intervals, both the
// scanning index and the write index move forward monotonically.
// -----------------------------------------------------------------------
vector<pair<int, int>> mergeOverlappingIntervalsTwoPointer(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> merged;
    for (const auto& iv : intervals) {
        if (!merged.empty() && iv.first <= merged.back().second) {
            merged.back().second = max(merged.back().second, iv.second);
        } else {
            merged.push_back(iv);
        }
    }
    return merged;
}

// -----------------------------------------------------------------------
// Case: two-pointer-right-bound-extended-by-callback
// Unknown case: an external callback of unspecified complexity may grow
// the underlying vector on every step, so the effective loop bound and
// per-step cost cannot be determined from this function's text alone.
// -----------------------------------------------------------------------
int twoPointerRightBoundExtendedByCallback(vector<int>& a, const function<void(vector<int>&)>& onStep) {
    int right = 0, steps = 0;
    while (right < (int)a.size()) {
        onStep(a); // unknown side effects: may push_back, may do nothing
        right++;
        steps++;
    }
    return steps;
}

// -----------------------------------------------------------------------
// Case: two-pointer-with-external-predicate
// Unknown case: the per-step comparison is delegated to a caller-supplied
// predicate function pointer whose internal complexity is not visible
// here, so total cost cannot be pinned to a specific bound.
// -----------------------------------------------------------------------
int twoPointerWithExternalPredicate(const vector<int>& a, bool (*shouldAdvance)(int, int)) {
    int lo = 0, hi = (int)a.size() - 1, matches = 0;
    while (lo < hi) {
        if (shouldAdvance(a[lo], a[hi])) {
            matches++;
            lo++;
        } else {
            hi--;
        }
    }
    return matches;
}

// -----------------------------------------------------------------------
// Case: sliding-window-maximum-monotonic-deque
// Normal case: monotonic deque based sliding window maximum; each index
// is pushed and popped from the deque at most once across the whole run.
// -----------------------------------------------------------------------
vector<int> slidingWindowMaximumMonotonicDeque(const vector<int>& a, int k) {
    deque<int> dq; // stores indices, values decreasing front-to-back
    vector<int> result;
    for (int i = 0; i < (int)a.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            result.push_back(a[dq.front()]);
        }
    }
    return result;
}

// -----------------------------------------------------------------------
// Case: shortest-subarray-sum-at-least-k-with-negatives
// Normal case: prefix sums plus a monotonic deque of candidate start
// indices; every index is pushed and popped from the deque at most once.
// -----------------------------------------------------------------------
int shortestSubarraySumAtLeastKWithNegatives(const vector<int>& a, long long k) {
    int n = (int)a.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];
    deque<int> dq;
    int best = INT_MAX;
    for (int i = 0; i <= n; i++) {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            best = min(best, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    return best == INT_MAX ? -1 : best;
}

// -----------------------------------------------------------------------
// Case: two-pointer-early-return-on-match
// Edge case: the scan can terminate before examining all elements, so
// this documents best-case behavior, but the worst case (no match found)
// still requires visiting every element once.
// -----------------------------------------------------------------------
bool twoPointerEarlyReturnOnMatch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        if (a[lo] + a[hi] == target) {
            return true; // may return early, but worst case reaches lo==hi
        }
        if (a[lo] + a[hi] < target) lo++;
        else hi--;
    }
    return false;
}

// -----------------------------------------------------------------------
// Case: two-pointer-oscillating-bounded-reversals
// Adversarial case: the right pointer is allowed to step backward when a
// data-dependent condition is met, and there is no invariant in the code
// bounding how many times this can happen, so the total number of steps
// cannot be shown to be linear from the text alone.
// -----------------------------------------------------------------------
int twoPointerOscillatingBoundedReversals(const vector<int>& a) {
    int n = (int)a.size();
    int right = 0, steps = 0;
    while (right < n) {
        if (a[right] % 2 == 0) {
            right++;
        } else {
            right = max(0, right - a[right]); // may jump backward or stay put, purely data-dependent
        }
        steps++;
    }
    return steps;
}
