// Project X - Complexity Analyzer Dataset
// Family: range-for-container-size
// All functions are self-contained, valid, standalone C++17.
// No external/scraped code. Freshly authored for static-analysis testing.

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------
// Case: sum-vector-range-for
// Normal case: plain range-for over a vector<int>.
// -----------------------------------------------------------------------
long long sumVectorRangeFor(const vector<int>& v) {
    long long total = 0;
    for (int x : v) {
        total += x;
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-string-indexed-loop
// Normal case: index-based loop bounded by string::size(), non-braced body.
// -----------------------------------------------------------------------
long long sumStringIndexedLoop(const string& s) {
    long long total = 0;
    for (size_t i = 0; i < s.size(); i++)
        total += static_cast<unsigned char>(s[i]);
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-deque-range-for
// Normal case: range-for over a deque<int>.
// -----------------------------------------------------------------------
long long sumDequeRangeFor(const deque<int>& d) {
    long long total = 0;
    for (const int& x : d) {
        total += x;
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-fixed-array-constant-bound
// Edge case: loop bound is a compile-time constant (100), independent of
// any runtime input symbol, so the loop performs a fixed amount of work.
// -----------------------------------------------------------------------
long long sumFixedArrayConstantBound(int arr[100]) {
    long long total = 0;
    for (int i = 0; i < 100; i++) {
        total += arr[i];
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-c-array-param-pointer
// Normal case: decayed pointer parameter, loop bound is runtime parameter n.
// -----------------------------------------------------------------------
long long sumCArrayParamPointer(int* arr, int n) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-nested-vector-total-elements
// Normal case: nested containers, complexity depends on total element
// count across all inner vectors, not just outer size.
// -----------------------------------------------------------------------
long long sumNestedVectorTotalElements(const vector<vector<int>>& grid) {
    long long total = 0;
    for (const auto& row : grid) {
        for (int x : row) {
            total += x;
        }
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-const-vector-ref-range-for
// Edge case: const-qualified vector, range-for using const auto&.
// -----------------------------------------------------------------------
long long sumConstVectorRefRangeFor(const vector<long long>& v) {
    long long total = 0;
    for (const auto& x : v) {
        total += x;
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: count-true-vector-bool
// Edge case: vector<bool> is a bit-packed specialization; iteration is
// still linear in element count despite the packed storage.
// -----------------------------------------------------------------------
long long countTrueVectorBool(const vector<bool>& flags) {
    long long count = 0;
    for (bool b : flags) {
        if (b) count++;
    }
    return count;
}

// -----------------------------------------------------------------------
// Case: sum-begin-end-iterators
// Normal case: manual iterator loop using begin()/end() instead of range-for.
// -----------------------------------------------------------------------
long long sumBeginEndIterators(const vector<int>& v) {
    long long total = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        total += *it;
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-matrix-nested-loops-square
// Normal case: square n x n matrix, nested loops over rows and columns.
// -----------------------------------------------------------------------
long long sumMatrixNestedLoopsSquare(const vector<vector<int>>& mat, int n) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            total += mat[i][j];
        }
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-size-recomputed-each-iteration
// Normal case: v.size() is re-evaluated in the loop condition on every
// iteration; since size() is O(1) on vector, total cost stays O(n).
// -----------------------------------------------------------------------
long long sumSizeRecomputedEachIteration(vector<int>& v) {
    long long total = 0;
    for (size_t i = 0; i < v.size(); i++) {
        total += v[i];
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: grow-vector-while-loop-data-dependent
// Adversarial / Unknown case: the loop appends new elements whose count
// depends on the *values* already stored in the vector, so the number of
// iterations cannot be bounded purely from the initial size.
// -----------------------------------------------------------------------
long long growVectorWhileLoopDataDependent(vector<int>& v) {
    long long steps = 0;
    size_t i = 0;
    while (i < v.size()) {
        if (v[i] > 0) {
            v.push_back(v[i] - 1); // growth amount is data-dependent
        }
        i++;
        steps++;
    }
    return steps;
}

// -----------------------------------------------------------------------
// Case: erase-front-repeatedly-quadratic
// Adversarial case: repeatedly erasing the front element of a vector shifts
// all remaining elements, making each erase O(k) and the whole loop O(n^2).
// -----------------------------------------------------------------------
long long eraseFrontRepeatedlyQuadratic(vector<int> v) {
    long long total = 0;
    while (!v.empty()) {
        total += v.front();
        v.erase(v.begin());
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-map-range-for
// Normal case: range-for over an ordered map<int,int>; iterating a
// red-black tree container visits every node exactly once.
// -----------------------------------------------------------------------
long long sumMapRangeFor(const map<int, int>& m) {
    long long total = 0;
    for (const auto& kv : m) {
        total += kv.second;
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-unordered-map-range-for
// Unknown case: unordered_map iteration cost is O(size + bucket_count).
// bucket_count is not guaranteed to stay proportional to size after a
// history of insertions/erasures without knowing rehashing behavior, so
// worst-case time cannot be pinned to a single asymptotic bound here.
// -----------------------------------------------------------------------
long long sumUnorderedMapRangeFor(const unordered_map<int, int>& um) {
    long long total = 0;
    for (const auto& kv : um) {
        total += kv.second;
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-array-of-vectors-fixed-outer-dim
// Normal case: outer dimension is a compile-time constant (4), inner
// vectors vary in size; total cost depends on total inner element count.
// -----------------------------------------------------------------------
long long sumArrayOfVectorsFixedOuterDim(const array<vector<int>, 4>& buckets) {
    long long total = 0;
    for (const auto& bucket : buckets) {
        for (int x : bucket) {
            total += x;
        }
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: sum-vector-via-aliased-pointer-size
// Adversarial / Unknown case: an auxiliary raw pointer of unknown
// provenance is written to on every iteration. Because the caller controls
// whether aliasHint points into v's own storage (or any other memory the
// loop bound might indirectly depend on), the number of effective
// iterations and their cost cannot be determined from this function alone.
// -----------------------------------------------------------------------
long long sumVectorViaAliasedPointerSize(vector<int>& v, int* aliasHint) {
    long long total = 0;
    for (size_t i = 0; i < v.size(); i++) {
        total += v[i];
        if (aliasHint) {
            *aliasHint = static_cast<int>(total);
        }
    }
    return total;
}

// -----------------------------------------------------------------------
// Case: reverse-range-for-const-array-size
// Edge case: std::array with a compile-time template size N, iterated in
// reverse via rbegin()/rend(). N is treated as an input symbol here since
// the analyzer sees it as a template parameter, not a literal constant.
// -----------------------------------------------------------------------
template <size_t N>
long long reverseRangeForConstArraySize(const array<int, N>& a) {
    long long total = 0;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        total += *it;
    }
    return total;
}

// Explicit instantiation so the template above is compiled and reviewable.
template long long reverseRangeForConstArraySize<8>(const array<int, 8>&);
