# Dataset and accuracy policy

The corpus is not training data that the extension memorizes. It is a reviewed benchmark used to test analysis rules on code the engine has not seen during development.

## Sources

1. Start with original, authored C++ snippets in this repository.
2. Add only code with an explicit permissive license or written by a contributor who agrees to the repository license.
3. Do not scrape contest-platform submissions or use judge time as a Big-O label.

## Accuracy target

The project may claim 90% exact accuracy only after a locked, manually reviewed holdout set has at least 500 cases. Cases must be split by algorithm family so syntactic variants of the same algorithm do not appear in both development and holdout data.

`unknown` is a correct result when the selected code cannot be analyzed safely.

The public precision claim is stricter: it requires at least **95% precision on supported cases** against a locked, manually reviewed hidden holdout of 1,000 cases. Syntax variants may increase robustness checks, but are not counted as independent algorithm families.

## Growth plan

- Baseline: 20 authored cases.
- MVP gate: 200 reviewed cases.
- Growth target: 3,000 diverse, reviewed base cases.
- Public accuracy gate: 1,000 locked hidden holdout cases, with family-disjoint development and holdout sets.
- Add adversarial and `unknown` cases continuously; generated syntax variants supplement, never replace, distinct reviewed base cases.
