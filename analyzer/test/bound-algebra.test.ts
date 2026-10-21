import assert from "node:assert/strict";
import { test } from "node:test";
import { formatBound, maxBounds, multiplyBounds, parseBound, dominates, constantBound } from "../src/bound.js";
import { multiplyExpressions, dominantExpression } from "../src/complexity-expression.js";

test("parses and round-trips canonical polynomial products", () => {
  assert.equal(formatBound(parseBound("O(n)")!), "O(n)");
  assert.equal(formatBound(parseBound("O(n m)")!), "O(n m)");
  assert.equal(formatBound(parseBound("O(n^3 log^2 n)")!), "O(n^3 log^2 n)");
  assert.equal(formatBound(parseBound("O(1)")!), "O(1)");
});

test("multiplies exponents across factors", () => {
  const product = multiplyBounds(parseBound("O(n log n)")!, parseBound("O(n)")!);
  assert.equal(product ? formatBound(product) : undefined, "O(n^2 log n)");
});

test("exponential bounds compose instead of abstaining", () => {
  const product = multiplyBounds(parseBound("O(2^n)")!, parseBound("O(n)")!);
  assert.equal(product ? formatBound(product) : undefined, "O(n 2^n)");
  const squared = multiplyBounds(parseBound("O(2^n)")!, parseBound("O(2^n)")!);
  assert.equal(squared ? formatBound(squared) : undefined, "O(4^n)");
});

test("factorial, sqrt, log log, and inverse-Ackermann factors parse mid-term", () => {
  assert.equal(formatBound(parseBound("O(n n!)")!), "O(n n!)");
  assert.equal(formatBound(parseBound("O(sqrt n)")!), "O(sqrt n)");
  assert.equal(formatBound(parseBound("O(n log log n)")!), "O(n log log n)");
  assert.equal(formatBound(parseBound("O(m α(n))")!), "O(m α(n))");
  assert.equal(formatBound(parseBound("O((n + m) α(n))")!), "O((n + m) α(n))");
});

test("domination ordering follows asymptotics", () => {
  const n = parseBound("O(n)")!;
  const n2 = parseBound("O(n^2)")!;
  const log = parseBound("O(log n)")!;
  const exp = parseBound("O(2^n)")!;
  const fact = parseBound("O(n!)")!;
  const ackermann = parseBound("O(α(n))")!;
  const logLog = parseBound("O(log log n)")!;
  assert.ok(dominates(n2[0], n[0]));
  assert.ok(!dominates(n[0], n2[0]));
  assert.ok(dominates(n[0], log[0]));
  assert.ok(dominates(exp[0], n2[0]));
  assert.ok(!dominates(n2[0], exp[0]));
  assert.ok(dominates(fact[0], exp[0]));
  assert.ok(!dominates(exp[0], fact[0]));
  assert.ok(dominates(logLog[0], ackermann[0]));
  assert.ok(!dominates(ackermann[0], logLog[0]));
});

test("independent dimensions stay incomparable and survive as sums", () => {
  assert.equal(dominantExpression("O(n)", "O(m)"), undefined);
  const sum = maxBounds(parseBound("O(n)")!, parseBound("O(m)")!);
  assert.equal(formatBound(sum), "O(n + m)");
});

test("max drops dominated summands", () => {
  const merged = maxBounds(parseBound("O(n log n)")!, parseBound("O(n)")!);
  assert.equal(formatBound(merged), "O(n log n)");
  const mixed = maxBounds(parseBound("O(n + q log n)")!, parseBound("O(q)")!);
  assert.equal(formatBondSafe(mixed), "O(n + q log n)");
});

function formatBondSafe(bound: ReturnType<typeof maxBounds>): string {
  return formatBound(bound);
}

test("sqrt parses from both spellings and dominates constants", () => {
  const unicode = parseBound("O(√n)");
  assert.ok(unicode);
  assert.equal(formatBound(unicode!), "O(sqrt n)");
  assert.ok(dominates(unicode![0], constantBound()[0]));
});

test("facade multiply and dominance match the algebra", () => {
  assert.equal(multiplyExpressions("O(n log n)", "O(n)"), "O(n^2 log n)");
  assert.equal(multiplyExpressions("O(2^k)", "O(n)"), "O(n 2^k)");
  assert.equal(dominantExpression("O(n)", "O(n^2)"), "O(n^2)");
  assert.equal(dominantExpression("O(n + m)", "O(n)"), "O(n + m)");
  assert.equal(dominantExpression("O(1)", "O(log n)"), "O(log n)");
});

test("half exponents add into integer powers", () => {
  const product = multiplyBounds(parseBound("O(sqrt n)")!, parseBound("O(sqrt n)")!);
  assert.equal(product ? formatBound(product) : undefined, "O(n)");
});
