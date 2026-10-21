import assert from "node:assert/strict";
import test from "node:test";
import { analyseCppFunctionsInDocument } from "../src/index.js";

test("round 11: amortized variable sliding window loop proves exact linear time and O(1) space", () => {
  const source = `
    #include <vector>
    using namespace std;
    int slidingWindow(const vector<int>& a, int limit) {
      int left = 0, sum = 0, best = 0;
      for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        sum += a[right];
        while (sum > limit) sum -= a[left++];
        best = max(best, right - left + 1);
      }
      return best;
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["slidingWindow"]);
  const result = results.get("slidingWindow");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(n)");
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "exact");
});

test("round 11: vector divide-and-conquer merge sort proves exact O(n log n) time and O(n) space", () => {
  const source = `
    #include <vector>
    #include <algorithm>
    using namespace std;
    void mergeSort(vector<int>& a) {
      if (a.size() <= 1) return;
      int mid = static_cast<int>(a.size()) / 2;
      vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end());
      mergeSort(left); mergeSort(right);
      merge(left.begin(), left.end(), right.begin(), right.end(), a.begin());
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["mergeSort"]);
  const result = results.get("mergeSort");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(n log n)");
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "exact");
});

test("round 11: static_cast in binary search bounds computes O(log n) rather than O(log S)", () => {
  const source = `
    #include <vector>
    using namespace std;
    int binarySearch(const vector<int>& a, int target) {
      int left = 0, right = static_cast<int>(a.size()) - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
      }
      return -1;
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["binarySearch"]);
  const result = results.get("binarySearch");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(log n)");
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "exact");
});

test("round 11: single-parameter divide and conquer recurrence with linear combine proves O(n log n)", () => {
  const source = `
    using namespace std;
    void combine(int n) {
      for (int i = 0; i < n; ++i) {}
    }
    void splitAndMerge(int n) {
      if (n <= 1) return;
      int mid = n / 2;
      splitAndMerge(mid);
      splitAndMerge(mid);
      combine(n);
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["splitAndMerge"]);
  const result = results.get("splitAndMerge");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(n log n)");
  assert.equal(result.auxiliarySpace, "O(log n)");
});

test("round 11: sliding window on string container proves exact linear time", () => {
  const source = `
    #include <string>
    using namespace std;
    int longestDistinct(const string& s) {
      int left = 0, best = 0;
      int freq[256] = {0};
      for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        freq[static_cast<unsigned char>(s[right])]++;
        while (freq[static_cast<unsigned char>(s[right])] > 1) {
          freq[static_cast<unsigned char>(s[left++])]--;
        }
        best = max(best, right - left + 1);
      }
      return best;
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["longestDistinct"]);
  const result = results.get("longestDistinct");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(n)");
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "exact");
});

test("round 11: vector merge sort with inplace_merge proves exact O(n log n) and O(n) space", () => {
  const source = `
    #include <vector>
    #include <algorithm>
    using namespace std;
    void mergeSortInplace(vector<int>& a) {
      if (a.empty() || a.size() == 1) return;
      int mid = static_cast<int>(a.size()) / 2;
      vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end());
      mergeSortInplace(left); mergeSortInplace(right);
      inplace_merge(left.begin(), left.end(), right.end());
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["mergeSortInplace"]);
  const result = results.get("mergeSortInplace");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(n log n)");
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "exact");
});

test("round 11: binary search with explicit CStyleCast and functional cast preserves logarithmic bound", () => {
  const source = `
    #include <vector>
    using namespace std;
    int binarySearchCast(const vector<int>& a, int target) {
      int left = 0, right = int(a.size()) - 1;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
      }
      return -1;
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["binarySearchCast"]);
  const result = results.get("binarySearchCast");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(log n)");
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "exact");
});

test("round 11: deque-based divide-and-conquer recurrence proves exact O(n log n)", () => {
  const source = `
    #include <deque>
    #include <algorithm>
    using namespace std;
    void dequeMergeSort(deque<int>& a) {
      if (a.size() <= 1) return;
      int mid = static_cast<int>(a.size()) / 2;
      deque<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end());
      dequeMergeSort(left); dequeMergeSort(right);
      merge(left.begin(), left.end(), right.begin(), right.end(), a.begin());
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["dequeMergeSort"]);
  const result = results.get("dequeMergeSort");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(n log n)");
  assert.equal(result.auxiliarySpace, "O(n)");
  assert.equal(result.confidence, "exact");
});

test("round 11: variable sliding window with pre-increment proves exact O(n)", () => {
  const source = `
    #include <vector>
    using namespace std;
    int slidingWindowPre(const vector<int>& a, int limit) {
      int left = 0, sum = 0, best = 0;
      for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        sum += a[right];
        while (sum > limit) {
          sum -= a[left];
          ++left;
        }
        best = max(best, right - left + 1);
      }
      return best;
    }
  `;
  const results = analyseCppFunctionsInDocument(source, ["slidingWindowPre"]);
  const result = results.get("slidingWindowPre");
  assert.ok(result);
  assert.equal(result.worstCaseTime, "O(n)");
  assert.equal(result.auxiliarySpace, "O(1)");
  assert.equal(result.confidence, "exact");
});
