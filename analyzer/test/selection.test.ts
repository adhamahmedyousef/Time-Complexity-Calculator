import assert from "node:assert/strict";
import test from "node:test";
import { prepareCppSelection } from "../src/index.js";

test("a statement selection is wrapped with symbolic CP input variables", () => {
  const prepared = prepareCppSelection("for (int i = 0; i < n; ++i) cout << i;");
  assert.equal(prepared.functionName, "__project_x_selection");
  assert.match(prepared.input, /class __project_x_stream/);
  assert.match(prepared.input, /long long n, m, k, q, h, W, sum, V, E, t;/);
});

test("a for block is not mistaken for a complete function", () => {
  const prepared = prepareCppSelection("for (int i = 0; i < n; ++i) { cout << i; }");
  assert.equal(prepared.functionName, "__project_x_selection");
});

test("a complete function selection gets the standard C++ prelude and keeps its name", () => {
  const source = "void solve(int n) { for (int i = 0; i < n; ++i) {} }";
  const prepared = prepareCppSelection(source);
  assert.equal(prepared.functionName, "solve");
  assert.match(prepared.input, /class vector/);
  assert.match(prepared.input, /void solve/);
});

test("a lambda inside a selected function is never mistaken for that function", () => {
  const prepared = prepareCppSelection(`
    void solve(int n) {
      auto less = [](int a, int b) { return a < b; };
      if (less(1, n)) return;
    }`);
  assert.equal(prepared.functionName, "solve");
});
