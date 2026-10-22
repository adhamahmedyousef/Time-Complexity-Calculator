// ============================================================================
// Time Complexity Calculator by VoidHub (https://voidhub.co)
// Interactive Demo C++ File
//
// How to test in VS Code / Cursor / Kiro:
// 1. Look above each function declaration to see the CodeLens button:
//    "⏱ Calculate Complexity: <functionName>"
// 2. Click the CodeLens button to compute Time, Auxiliary Space, and Proof!
// 3. Alternatively, select any function block and press: Ctrl+Alt+C (macOS: Cmd+Alt+C)
// 4. Hover over function names to view the cached complexity card!
// ============================================================================

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// 1. Logarithmic Binary Search: O(log n) time, O(1) space
int binarySearchDemo(const vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// 2. Linear Two-Pointer Palindrome Verification: O(n) time, O(1) space
bool isPalindromeDemo(const string& s) {
    int lo = 0, hi = static_cast<int>(s.size()) - 1;
    while (lo < hi) {
        if (s[lo] != s[hi]) return false;
        lo++;
        hi--;
    }
    return true;
}

// 3. Divide and Conquer Merge Sort: O(n log n) time, O(n) space
void mergeSortDemo(vector<int>& a) {
    if (a.size() <= 1) return;
    int mid = static_cast<int>(a.size()) / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());
    mergeSortDemo(left);
    mergeSortDemo(right);
    merge(left.begin(), left.end(), right.begin(), right.end(), a.begin());
}

// 4. Cubic Matrix Multiplication: O(n^3) time, O(n^2) space
vector<vector<int>> matrixMultiplyDemo(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) {
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

// 5. Square Root Trial Division Primality: O(sqrt n) time, O(1) space
bool isPrimeDemo(int n) {
    if (n <= 1) return false;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}

// 6. Branching Fibonacci Recursion: O(1.618^n) time, O(n) space
int fibonacciDemo(int n) {
    if (n <= 1) return n;
    return fibonacciDemo(n - 1) + fibonacciDemo(n - 2);
}

// 7. Amortized Variable Sliding Window: O(n) time, O(1) space
int maxSubarraySumAtMostLimitDemo(const vector<int>& a, int limit) {
    int left = 0, current = 0, best = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        current += a[right];
        while (current > limit && left <= right) {
            current -= a[left++];
        }
        best = max(best, right - left + 1);
    }
    return best;
}

// 8. Harmonic Series Sieve Pass: O(n log n) time, O(n) space
vector<int> harmonicDivisorCountDemo(int n) {
    vector<int> count(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            count[j]++;
        }
    }
    return count;
}
