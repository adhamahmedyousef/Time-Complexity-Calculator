import assert from "node:assert/strict";
import test from "node:test";
import { dominantExpression, multiplyExpressions } from "../src/complexity-expression.js";

test("symbolic products compose arbitrary polynomial and logarithmic exponents", () => {
  assert.equal(multiplyExpressions("O(n)", "O(n)"), "O(n^2)");
  assert.equal(multiplyExpressions("O(n^2)", "O(n log n)"), "O(n^3 log n)");
  assert.equal(multiplyExpressions("O(n^3 log n)", "O(log n)"), "O(n^3 log^2 n)");
  assert.equal(multiplyExpressions("O(n log^2 n)", "O(n)"), "O(n^2 log^2 n)");
});

test("symbolic sums choose the dominant term", () => {
  assert.equal(dominantExpression("O(n)", "O(n^2)"), "O(n^2)");
  assert.equal(dominantExpression("O(n log n)", "O(n)"), "O(n log n)");
});
