# Reviewed dataset case format

Each corpus is a matched pair:

~~~
datasets/cpp-<family>.cpp
datasets/cpp-<family>.manifest.json
~~~

Every function in the C++ file has exactly one manifest entry. Use original code you wrote, or code with an explicit compatible license and source record; do not paste judge submissions.

For the 10,000-case program, submit batches by algorithm family (50-200 cases per pair). Keep reviewed base cases separate from generated syntax variants. A variant improves robustness, but does not count as a new algorithm family.

## Manifest template

~~~json
{
  "version": 2,
  "language": "cpp",
  "family": "number-theory-sieves",
  "reviewedBy": "reviewer-handle-or-team",
  "cases": [
    {
      "id": "short-stable-kebab-id",
      "symbol": "exactCppFunctionName",
      "time": "O(n log n)",
      "space": "O(n)",
      "confidence": "exact",
      "tags": ["family", "pattern"],
      "inputSymbols": ["n"],
      "proof": "One short reviewer explanation of the worst-case bound.",
      "origin": {"kind": "authored", "license": "CC0-1.0-or-authored"},
      "variantOf": null
    }
  ]
}
~~~

Allowed confidence values are exact, estimated, and unknown. Time and space labels must be worst-case unless the label and tags explicitly say otherwise. Put one algorithm family per corpus, include normal and adversarial examples, and include Unknown examples for forms the analyzer should reject safely.

`origin.kind` is one of `authored`, `licensed`, or `derived`. `licensed` requires an explicit SPDX-compatible license and a source URL in the short batch note. `derived` must name its reviewed base case using `variantOf`.

Use `inputSymbols` to identify the mathematical sizes in the proof (`n`, `m`, `V`, `E`, `Q`, etc.). Use `Unknown` only when a reviewer agrees the code cannot safely be given an exact label under Project X's policy.

Run `npm run benchmark:dataset` after adding a batch. It reports precision among asserted answers separately from coverage: an `Unknown` result is an honest abstention, not a passing exact answer. Use `npm run benchmark:dataset -- --strict` in CI to fail only on confident mismatches, and evaluate public accuracy claims on the separate hidden holdout.

## What to send

Send the paired .cpp and .manifest.json files, plus a short note for each non-obvious case explaining its complexity and assumptions. Good initial families are STL calls, number theory, graph traversal, shortest paths, trees, DP, recursion, and deliberately ambiguous code. Variants of one algorithm are useful, but label them as variants and do not count them as distinct families.

Suggested first batches:

- `number-theory-sieves`, `number-theory-gcd-factorization`, `number-theory-modular`;
- `two-pointers-sliding-window`, `binary-search-parametric`;
- `graph-traversal`, `shortest-path`, `dsu-mst`;
- `dp-1d`, `dp-2d`, `dp-bitmask`, `tree-dp`;
- `recurrence-divide-conquer`, `stl-containers-algorithms`, and `unknown-adversarial`.
