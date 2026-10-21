// Project X - Complexity Analyzer Dataset
// Family: binary-search
// All functions are self-contained, valid, standalone C++17.
// No external/scraped code. Freshly authored for static-analysis testing.

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------
// Case: binary-search-classic-iterative
// Normal case: textbook iterative binary search on a sorted array.
// -----------------------------------------------------------------------
int binarySearchClassicIterative(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// -----------------------------------------------------------------------
// Case: binary-search-lower-bound-manual
// Normal case: manually implemented lower_bound (first index with
// a[index] >= target).
// -----------------------------------------------------------------------
int binarySearchLowerBoundManual(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// -----------------------------------------------------------------------
// Case: binary-search-upper-bound-manual
// Normal case: manually implemented upper_bound (first index with
// a[index] > target), non-braced if bodies.
// -----------------------------------------------------------------------
int binarySearchUpperBoundManual(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// -----------------------------------------------------------------------
// Case: first-occurrence-binary-search
// Normal case: search continues past a match to find the leftmost one.
// -----------------------------------------------------------------------
int firstOccurrenceBinarySearch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1, result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) {
            result = mid;
            hi = mid - 1;
        } else if (a[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return result;
}

// -----------------------------------------------------------------------
// Case: last-occurrence-binary-search
// Normal case: search continues past a match to find the rightmost one.
// -----------------------------------------------------------------------
int lastOccurrenceBinarySearch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1, result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) {
            result = mid;
            lo = mid + 1;
        } else if (a[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return result;
}

// -----------------------------------------------------------------------
// Case: binary-search-recursive
// Normal case: recursive divide-and-conquer binary search; each call
// halves the search range, and the recursion depth grows the call stack.
// -----------------------------------------------------------------------
int binarySearchRecursive(const vector<int>& a, int lo, int hi, int target) {
    if (lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target) return binarySearchRecursive(a, mid + 1, hi, target);
    return binarySearchRecursive(a, lo, mid - 1, target);
}

// -----------------------------------------------------------------------
// Case: can-ship-within-days (helper for binary-search-on-answer)
// Feasibility predicate used by the answer-space binary search below.
// -----------------------------------------------------------------------
bool canShipWithinDays(const vector<int>& weights, int capacity, int maxDays) {
    int daysNeeded = 1;
    long long currentLoad = 0;
    for (int w : weights) {
        if (currentLoad + w > capacity) {
            daysNeeded++;
            currentLoad = 0;
        }
        currentLoad += w;
    }
    return daysNeeded <= maxDays;
}

// -----------------------------------------------------------------------
// Case: binary-search-on-answer-min-ship-capacity
// Normal case: answer-space binary search where each feasibility check
// costs O(n), multiplying the O(log(range)) number of checks.
// -----------------------------------------------------------------------
int binarySearchOnAnswerMinShipCapacity(const vector<int>& weights, int maxDays) {
    int lo = *max_element(weights.begin(), weights.end());
    int hi = accumulate(weights.begin(), weights.end(), 0);
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canShipWithinDays(weights, mid, maxDays)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// -----------------------------------------------------------------------
// Case: binary-search-custom-predicate-bool-array
// Normal case: search over an implicit monotonic boolean predicate rather
// than array values directly.
// -----------------------------------------------------------------------
int binarySearchCustomPredicateBoolArray(int n, const function<bool(int)>& isTrue) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (isTrue(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// -----------------------------------------------------------------------
// Case: binary-search-non-progressing-update
// Adversarial / Unknown case: when the predicate is false, hi is set to
// mid instead of mid - 1, so lo and hi can become stuck at adjacent
// values (lo == mid) without ever converging, risking an infinite loop.
// -----------------------------------------------------------------------
int binarySearchNonProgressingUpdate(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) lo = mid; // bug: does not exclude mid, no progress guaranteed
        else hi = mid - 1;
    }
    return (lo >= 0 && lo < (int)a.size() && a[lo] == target) ? lo : -1;
}

// -----------------------------------------------------------------------
// Case: binary-search-off-by-one-infinite-loop
// Adversarial / Unknown case: hi is updated to mid instead of mid - 1 in
// the "too high" branch while mid rounds toward lo, so for a two-element
// range where a[mid] is always greater than target the range never
// shrinks, and the loop can fail to terminate.
// -----------------------------------------------------------------------
int binarySearchOffByOneInfiniteLoop(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] >= target) hi = mid; // if mid == lo, hi never moves below lo+1 boundary safely handled below
        else lo = mid; // bug: does not exclude mid, can stall when mid == lo
    }
    return (lo >= 0 && lo < (int)a.size() && a[lo] == target) ? lo : -1;
}

// -----------------------------------------------------------------------
// Case: binary-search-fixed-iteration-real
// Edge case: floating-point binary search that always runs a fixed
// literal number of iterations, independent of any input symbol.
// -----------------------------------------------------------------------
double binarySearchFixedIterationReal(double lo, double hi, const function<bool(double)>& predicate) {
    for (int iter = 0; iter < 100; iter++) {
        double mid = (lo + hi) / 2.0;
        if (predicate(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

// -----------------------------------------------------------------------
// Case: exponential-search-then-binary
// Normal case: exponential probing to find a range, followed by a bounded
// binary search inside that range.
// -----------------------------------------------------------------------
int exponentialSearchThenBinary(const vector<int>& a, int target) {
    int n = (int)a.size();
    if (n == 0) return -1;
    if (a[0] == target) return 0;
    int bound = 1;
    while (bound < n && a[bound] < target) {
        bound *= 2;
    }
    int lo = bound / 2;
    int hi = min(bound, n - 1);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// -----------------------------------------------------------------------
// Case: binary-search-rotated-sorted-array
// Normal case: modified binary search over a rotated sorted array, still
// halving the search range on every iteration.
// -----------------------------------------------------------------------
int binarySearchRotatedSortedArray(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[lo] <= a[mid]) {
            if (a[lo] <= target && target < a[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if (a[mid] < target && target <= a[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

// -----------------------------------------------------------------------
// Case: binary-search-with-external-comparator
// Unknown case: the comparison at each step is delegated to a caller
// supplied comparator function pointer of unknown internal cost, so the
// total time cannot be reduced to a fixed bound even though the number
// of comparisons itself is O(log n).
// -----------------------------------------------------------------------
int binarySearchWithExternalComparator(const vector<int>& a, int target, int (*compare)(int, int)) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cmp = compare(a[mid], target);
        if (cmp == 0) return mid;
        else if (cmp < 0) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// -----------------------------------------------------------------------
// Case: binary-search-recursive-tail-position
// Normal case: recursive binary search written in tail-call position.
// Space is reported without assuming tail-call optimization, since the
// C++ standard does not guarantee it.
// -----------------------------------------------------------------------
int binarySearchRecursiveTailPosition(const vector<int>& a, int lo, int hi, int target) {
    if (lo > hi) {
        return -1;
    }
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) {
        return mid;
    }
    return (a[mid] < target)
        ? binarySearchRecursiveTailPosition(a, mid + 1, hi, target)
        : binarySearchRecursiveTailPosition(a, lo, mid - 1, target);
}

// -----------------------------------------------------------------------
// Case: binary-search-guess-number-external-api
// Unknown case: each probe delegates to an externally supplied guess
// function of unspecified complexity (e.g., could be a network call or a
// heavy computation), so even though the number of probes is O(log n),
// the total time cannot be bounded without knowing that function's cost.
// -----------------------------------------------------------------------
int binarySearchGuessNumberExternalApi(int n, const function<int(int)>& guess) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int result = guess(mid); // -1: guess too high, 1: too low, 0: correct
        if (result == 0) return mid;
        else if (result == 1) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// -----------------------------------------------------------------------
// Case: count-occurrences-via-std-bounds
// Normal case: relies on std::lower_bound / std::upper_bound, which are
// guaranteed O(log n) for the random-access iterators of a vector.
// -----------------------------------------------------------------------
int countOccurrencesViaStdBounds(const vector<int>& a, int target) {
    auto lo = lower_bound(a.begin(), a.end(), target);
    auto hi = upper_bound(a.begin(), a.end(), target);
    return (int)distance(lo, hi);
}

// -----------------------------------------------------------------------
// Case: jump-search-linear-block
// Normal case: block-jump search followed by a bounded linear scan
// within the found block; not a pure binary search but shares the
// answer-space search family's monotonic-step structure.
// -----------------------------------------------------------------------
int jumpSearchLinearBlock(const vector<int>& a, int target) {
    int n = (int)a.size();
    if (n == 0) return -1;
    int step = max(1, (int)sqrt((double)n));
    int prev = 0, curr = 0;
    while (curr < n && a[curr] < target) {
        prev = curr;
        curr += step;
    }
    int limit = min(curr, n - 1);
    for (int i = prev; i <= limit; i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

// -----------------------------------------------------------------------
// Case: binary-search-on-answer-min-max-partition
// Normal case: another answer-space binary search variant, splitting an
// array into m contiguous parts minimizing the largest part sum; each
// feasibility check costs O(n).
// -----------------------------------------------------------------------
bool canPartitionWithMaxSum(const vector<int>& a, long long maxSum, int m) {
    int parts = 1;
    long long currentSum = 0;
    for (int x : a) {
        if (currentSum + x > maxSum) {
            parts++;
            currentSum = 0;
        }
        currentSum += x;
    }
    return parts <= m;
}

long long binarySearchOnAnswerMinMaxPartition(const vector<int>& a, int m) {
    long long lo = *max_element(a.begin(), a.end());
    long long hi = accumulate(a.begin(), a.end(), 0LL);
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canPartitionWithMaxSum(a, mid, m)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// -----------------------------------------------------------------------
// Case: binary-search-empty-and-single-element-edge
// Edge case: explicitly exercises n == 0 and n == 1 inputs; still bounded
// by the same O(log n) loop structure as the classic search, which
// degenerates to O(1) work for these tiny sizes but is reported generally.
// -----------------------------------------------------------------------
int binarySearchEmptyAndSingleElementEdge(const vector<int>& a, int target) {
    if (a.empty()) return -1;
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
