import { execFileSync } from "node:child_process";
import { createHash } from "node:crypto";
import { existsSync, mkdirSync, mkdtempSync, readdirSync, readFileSync, rmSync, statSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import type { ClangNode } from "./model.js";

export function clangAstFor(source: string, clangPath = process.env.PROJECT_X_CLANG ?? "clang++"): ClangNode {
  // The extension starts a short-lived CLI process per invocation. Persisting
  // a bounded local AST cache therefore avoids reparsing an unchanged document
  // when the user selects several functions from it. The cache contains only
  // local source-derived AST JSON and is never uploaded or shared.
  const cacheDirectory = join(tmpdir(), "project-x-ast-cache");
  const cacheKey = createHash("sha256").update("clang-json-ast-v3\0").update(clangPath).update("\0").update(source).digest("hex");
  const cacheFile = join(cacheDirectory, `${cacheKey}.json`);
  if (existsSync(cacheFile)) {
    try {
      return JSON.parse(readFileSync(cacheFile, "utf8")) as ClangNode;
    } catch {
      rmSync(cacheFile, { force: true });
    }
  }
  const directory = mkdtempSync(join(tmpdir(), "project-x-"));
  const input = join(directory, "selection.cpp");
  try {
    writeFileSync(input, source, "utf8");
    // The JSON AST includes declarations from our small C++17 prelude as well
    // as every same-file helper. Node's 1 MiB default truncates ordinary
    // competitive-programming translation units and incorrectly surfaces as a
    // failed Clang launch. Keep a bounded but practical local-only ceiling.
    let output: string;
    try {
      output = execFileSync(clangPath, ["-std=c++17", "-fsyntax-only", "-Xclang", "-ast-dump=json", input], {
        encoding: "utf8",
        stdio: ["ignore", "pipe", "pipe"],
        maxBuffer: 64 * 1024 * 1024,
        windowsHide: true
      });
    } catch (error) {
      // Clang still emits a JSON AST for declarations that were successfully
      // parsed before an unrelated diagnostic. Keeping that AST lets a valid
      // selected function be analyzed even when another function in the same
      // competitive-programming scratch file is incomplete. We only recover
      // when the stdout payload itself is valid JSON; malformed selected code
      // remains a normal compiler failure and therefore stays Unknown.
      const partial = error as { stdout?: unknown };
      if (typeof partial.stdout !== "string") throw error;
      try {
        JSON.parse(partial.stdout);
        output = partial.stdout;
      } catch {
        throw error;
      }
    }
    const ast = JSON.parse(output) as ClangNode;
    // Avoid turning temporary storage into an unbounded dataset cache. Large
    // template-heavy documents still analyse normally, they are simply not
    // persisted. Keep the eight most recent safe-sized ASTs.
    if (Buffer.byteLength(output, "utf8") <= 48 * 1024 * 1024) {
      try {
        mkdirSync(cacheDirectory, { recursive: true });
        writeFileSync(cacheFile, output, "utf8");
        const stale = readdirSync(cacheDirectory)
          .filter((entry) => entry.endsWith(".json"))
          .map((entry) => ({ path: join(cacheDirectory, entry), modified: statSync(join(cacheDirectory, entry)).mtimeMs }))
          .sort((a, b) => b.modified - a.modified)
          .slice(8);
        for (const entry of stale) rmSync(entry.path, { force: true });
      } catch {
        // Caching is an optimization only. A read-only or full temp directory
        // must never prevent an offline analysis from completing.
      }
    }
    return ast;
  } finally {
    rmSync(directory, { recursive: true, force: true });
  }
}

export function findFirstFunction(node: ClangNode): ClangNode | undefined {
  if (node.kind === "FunctionDecl" && node.inner?.some((child) => child.kind === "CompoundStmt")) return node;
  for (const child of node.inner ?? []) {
    const found = findFirstFunction(child);
    if (found) return found;
  }
  return undefined;
}

export function findFunctionNamed(node: ClangNode, name: string): ClangNode | undefined {
  if (node.kind === "FunctionDecl" && node.name === name && node.inner?.some((child) => child.kind === "CompoundStmt")) return node;
  for (const child of node.inner ?? []) {
    const found = findFunctionNamed(child, name);
    if (found) return found;
  }
  return undefined;
}

export function findFunctionDeclarations(node: ClangNode): ClangNode[] {
  const result: ClangNode[] = [];
  const visit = (current: ClangNode): void => {
    if (current.kind === "FunctionDecl" && current.name && current.inner?.some((child) => child.kind === "CompoundStmt")) result.push(current);
    for (const child of current.inner ?? []) visit(child);
  };
  visit(node);
  return result;
}

/**
 * Finds method definitions belonging to explicitly named local records. The
 * caller supplies names extracted from the user's source, which keeps the
 * synthetic STL prelude out of the same-file summary graph.
 */
export function findMethodDeclarations(node: ClangNode, localRecordNames: ReadonlySet<string>): ClangNode[] {
  const result: ClangNode[] = [];
  const visit = (current: ClangNode, insideLocalRecord = false): void => {
    const localRecord = insideLocalRecord || (current.kind === "CXXRecordDecl" && Boolean(current.name && localRecordNames.has(current.name)));
    if (localRecord && current.kind === "CXXMethodDecl" && current.name && current.inner?.some((child) => child.kind === "CompoundStmt")) result.push(current);
    for (const child of current.inner ?? []) visit(child, localRecord);
  };
  visit(node);
  return result;
}
