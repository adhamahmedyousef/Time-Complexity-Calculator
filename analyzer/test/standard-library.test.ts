import assert from "node:assert/strict";
import test from "node:test";
import { standardFreeFunctionCost } from "../src/standard-library.js";
import { analyseCppFunctionInDocument } from "../src/index.js";

test("standard library knowledge base classifies representative C++17 algorithms", () => {
  assert.equal(standardFreeFunctionCost("max_element"), "O(n)");
  assert.equal(standardFreeFunctionCost("lower_bound"), "O(log n)");
  assert.equal(standardFreeFunctionCost("sort"), "O(n log n)");
  assert.equal(standardFreeFunctionCost("nth_element"), "O(n)");
  assert.equal(standardFreeFunctionCost("stable_partition"), "O(n log n)");
  assert.equal(standardFreeFunctionCost("swap"), "O(1)");
  assert.equal(standardFreeFunctionCost("unknownFunction"), undefined);
});

test("offline C++17 prelude accepts representative advanced STL declarations", () => {
  const result = analyseCppFunctionInDocument(`
    #include <bits/stdc++.h>
    using namespace std;
    long long parsed(vector<int> a) {
      list<int> values;
      multiset<int> ordered;
      tuple<int, int, int> state(1, 2, 3);
      priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
      nth_element(a.begin(), a.begin(), a.end());
      values.push_back(1); ordered.insert(1); pq.push(state);
      return a.size();
    }
  `, "parsed");
  assert.notEqual(result.proof[0], "Clang rejected the corpus function, so no safe complexity result can be produced.");
});
