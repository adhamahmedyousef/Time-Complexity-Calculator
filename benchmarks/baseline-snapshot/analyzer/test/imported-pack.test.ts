import assert from "node:assert/strict";
import { existsSync, readFileSync } from "node:fs";
import { fileURLToPath } from "node:url";
import test from "node:test";
import { analyseCppFunctionInDocument } from "../src/index.js";

const clangPath = process.env.PROJECT_X_CLANG ?? "C:\\Program Files\\LLVM\\bin\\clang++.exe";
const available = existsSync(clangPath);

// Regression for archive stems containing hyphens.  The importer must turn
// every generated symbol into a valid C++ identifier before it reaches Clang;
// this exercises the imported file rather than a hand-written approximation.
test("imports a hyphenated archive stem as valid analyzable C++", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = readFileSync(fileURLToPath(new URL("../../datasets/cpp-pack-cp-requested-dataset-pack-fenwick-point-update-prefix-01.cpp", import.meta.url)), "utf8");
  const result = analyseCppFunctionInDocument(source, "pack_cp_requested_dataset_pack_fenwickQueries_1");
  assert.equal(result.worstCaseTime, "O(n log n)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
  assert.notEqual(result.proof[0], "Clang rejected the corpus function, so no safe complexity result can be produced.");
});

test("offline STL prelude accepts sparse-table assign before complexity analysis", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = readFileSync(fileURLToPath(new URL("../../datasets/cpp-pack-cp-requested-dataset-pack-sparse-table-rmq-01.cpp", import.meta.url)), "utf8");
  const result = analyseCppFunctionInDocument(source, "pack_cp_requested_dataset_pack_sparseTableRMQ_1");
  assert.notEqual(result.proof[0], "Clang rejected the corpus function, so no safe complexity result can be produced.");
  assert.equal(result.worstCaseTime, "O(n log n + q)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n log n)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});

test("structural sparse-table preprocessing composes with a direct static query pass", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = readFileSync(fileURLToPath(new URL("../../datasets/cpp-pack-project-x-p0-p1-pack-sparse-table-01.cpp", import.meta.url)), "utf8");
  const result = analyseCppFunctionInDocument(source, "pack_project_x_p0_p1_pack_sparse_table_01");
  assert.equal(result.worstCaseTime, "O(n log n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n log n)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});

test("sparse-table proof also accepts a compiler-provided bit-width level count", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = readFileSync(fileURLToPath(new URL("../../datasets/cpp-pack-l1-sparse-table-rmq-03.cpp", import.meta.url)), "utf8");
  const result = analyseCppFunctionInDocument(source, "pack_l1_sparseTableRMQ");
  assert.equal(result.worstCaseTime, "O(n log n + m)", result.proof.join(" "));
  assert.equal(result.auxiliarySpace, "O(n log n)", result.proof.join(" "));
  assert.equal(result.confidence, "estimated");
});

test("does not mistake an unrelated cubic constructor for sparse-table preprocessing", { skip: !available }, () => {
  process.env.PROJECT_X_CLANG = clangPath;
  const source = `
    #include <bits/stdc++.h>
    using namespace std;
    struct NotASparseTable {
      vector<vector<int>> table;
      NotASparseTable(int n) {
        int levels = 1;
        while ((1 << levels) <= n) ++levels;
        table.assign(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k) table[i][j] += k;
      }
    };
    void use(int n) { NotASparseTable value(n); }
  `;
  const result = analyseCppFunctionInDocument(source, "use");
  assert.equal(result.worstCaseTime, "O(1)", result.proof.join(" "));
  assert.equal(result.confidence, "exact", result.proof.join(" "));
});
