import type { Complexity } from "./model.js";

/**
 * Conservative C++17 free-algorithm knowledge base.
 * Entries describe element-operation cost; unknown iterator/category-dependent cases stay absent.
 */
const constant = [
  "max", "min", "swap", "abs", "fabs", "ceil", "floor", "clamp", "exchange",
  // sqrt/pow compile to constant-time hardware/math instructions; the
  // repeated-sqrt reduction pattern relies on them being costable.
  "sqrt", "pow", "fmod", "trunc", "round",
  // Compiler integer bit primitives inspect a fixed-width scalar. They are
  // constant time and commonly appear in sparse-table queries.
  "__builtin_clz", "__builtin_clzl", "__builtin_clzll", "__builtin_ctz", "__builtin_ctzl", "__builtin_ctzll", "__builtin_popcount", "__builtin_popcountll",
  // Value-category casts do not traverse a container or allocate.  They show
  // up as normal CallExpr nodes in Clang's AST, so omitting them made a
  // wrapper such as `return helper(n, std::move(v));` look unsupported.
  "move", "forward",
  "printf", "scanf", "puts", "getchar", "putchar"
];

const logarithmic = [
  "lower_bound", "upper_bound", "equal_range", "binary_search", "gcd", "__gcd", "lcm"
];

const linear = [
  "max_element", "min_element", "find", "find_if", "find_if_not", "count", "count_if",
  "accumulate", "all_of", "any_of", "none_of", "for_each", "copy", "copy_if", "copy_n",
  "fill", "fill_n", "transform", "reverse", "rotate", "nth_element", "replace", "replace_if",
  "remove", "remove_if", "unique", "partition", "is_sorted", "is_partitioned",
  "adjacent_find", "mismatch", "equal", "lexicographical_compare", "iota",
  // Merging two sorted ranges touches every element once; it is the work of
  // one merge-sort combine step and of k-way merge passes.
  "merge", "set_union", "set_intersection", "set_difference", "set_symmetric_difference",
  // next_permutation/prev_permutation reverse the suffix above the pivot:
  // one linear pass per invocation. partition_point binary-searches.
  "next_permutation", "prev_permutation", "partition_point", "rotate_copy",
  // iterator_category determines whether distance() is constant-time, and the
  // iterator kind of an arbitrary pair of arguments is not provable here, so
  // the linear upper bound is the sound entry.
  "distance"
];

const nLogN = [
  "sort", "stable_sort", "partial_sort", "inplace_merge", "make_heap", "sort_heap", "stable_partition"
];

const costs = new Map<string, Complexity>();
for (const name of constant) costs.set(name, "O(1)");
for (const name of logarithmic) costs.set(name, "O(log n)");
for (const name of linear) costs.set(name, "O(n)");
for (const name of nLogN) costs.set(name, "O(n log n)");

export function standardFreeFunctionCost(name: string): Complexity | undefined {
  return costs.get(name);
}

export function standardFreeFunctionNames(): readonly string[] {
  return [...costs.keys()];
}
