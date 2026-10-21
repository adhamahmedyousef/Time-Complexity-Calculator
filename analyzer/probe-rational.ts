import { parseBound, formatBound, multiplyBounds, maxBounds } from "./src/bound.js";
const r = parseBound("O(n / i)");
console.log("parse n/i:", r ? formatBound(r) : "FAIL");
const prod = multiplyBounds(parseBound("O(n)"), parseBound("O(n / i)"));
console.log("n * (n/i):", prod ? formatBound(prod) : "FAIL");
console.log("roundtrip:", formatBound(maxBounds(parseBound("O(n / i)"))));
