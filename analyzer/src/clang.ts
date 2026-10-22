import { execFileSync } from "node:child_process";
import { createHash } from "node:crypto";
import { existsSync, mkdirSync, mkdtempSync, readdirSync, readFileSync, rmSync, statSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { synthesizeAstFromCpp } from "./fallback-parser.js";
import type { ClangNode } from "./model.js";

/**
 * Robustly auto-discovers Clang++ across system PATH and standard compiler installation paths.
 */
export function resolveSystemClang(configuredPath?: string): string | undefined {
  if (configuredPath?.trim() && existsSync(configuredPath.trim())) return configuredPath.trim();
  if (process.env.PROJECT_X_CLANG && existsSync(process.env.PROJECT_X_CLANG)) return process.env.PROJECT_X_CLANG;

  // 1. Search PATH directories
  const envPath = process.env.PATH || "";
  const pathDirs = envPath.split(process.platform === "win32" ? ";" : ":");
  const binNames = process.platform === "win32"
    ? ["clang++.exe", "clang.exe"]
    : ["clang++", "clang"];

  for (const dir of pathDirs) {
    if (!dir) continue;
    for (const bin of binNames) {
      const full = join(dir, bin);
      if (existsSync(full)) return full;
    }
  }

  // 2. Search common compiler installation directories
  const candidates: string[] = [];
  if (process.platform === "win32") {
    candidates.push(
      "C:\\Program Files\\LLVM\\bin\\clang++.exe",
      "C:\\Program Files (x86)\\LLVM\\bin\\clang++.exe",
      "C:\\LLVM\\bin\\clang++.exe",
      "C:\\msys64\\ucrt64\\bin\\clang++.exe",
      "C:\\msys64\\clang64\\bin\\clang++.exe",
      "C:\\msys64\\mingw64\\bin\\clang++.exe",
      "C:\\msys64\\mingw32\\bin\\clang++.exe",
      "C:\\msys64\\usr\\bin\\clang++.exe",
      "C:\\winlibs\\bin\\clang++.exe",
      "C:\\Strawberry\\c\\bin\\clang++.exe",
      "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      "C:\\Program Files\\Microsoft Visual Studio\\2022\\Professional\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      "C:\\Program Files\\Microsoft Visual Studio\\2022\\Enterprise\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      "C:\\Program Files\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Professional\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Enterprise\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\BuildTools\\VC\\Tools\\Llvm\\bin\\clang++.exe",
      join(process.env.USERPROFILE || "", "scoop", "shims", "clang++.exe"),
      join(process.env.USERPROFILE || "", "scoop", "apps", "llvm", "current", "bin", "clang++.exe"),
      "C:\\ProgramData\\chocolatey\\bin\\clang++.exe",
      join(process.env.LOCALAPPDATA || "", "Programs", "LLVM", "bin", "clang++.exe")
    );
  } else if (process.platform === "darwin") {
    candidates.push(
      "/opt/homebrew/bin/clang++",
      "/usr/local/bin/clang++",
      "/usr/bin/clang++",
      "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++",
      join(process.env.HOME || "", ".brew", "bin", "clang++")
    );
  } else {
    candidates.push(
      "/usr/bin/clang++",
      "/usr/local/bin/clang++",
      "/usr/lib/llvm-18/bin/clang++",
      "/usr/lib/llvm-17/bin/clang++",
      "/usr/lib/llvm-16/bin/clang++",
      "/usr/lib/llvm-15/bin/clang++",
      join(process.env.HOME || "", ".local", "bin", "clang++")
    );
  }

  for (const candidate of candidates) {
    if (existsSync(candidate)) return candidate;
  }

  return undefined;
}

export function clangAstFor(source: string, clangPath?: string): ClangNode {
  const compiler = clangPath || resolveSystemClang();
  if (!compiler) {
    return synthesizeAstFromCpp(source);
  }

  // The extension starts a short-lived CLI process per invocation. Persisting
  // a bounded local AST cache therefore avoids reparsing an unchanged document
  // when the user selects several functions from it. The cache contains only
  // local source-derived AST JSON and is never uploaded or shared.
  const cacheDirectory = join(tmpdir(), "project-x-ast-cache");
  const cacheKey = createHash("sha256").update("clang-json-ast-v3\0").update(compiler).update("\0").update(source).digest("hex");
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
    let output: string;
    try {
      output = execFileSync(compiler, ["-std=c++17", "-fsyntax-only", "-Xclang", "-ast-dump=json", input], {
        encoding: "utf8",
        stdio: ["ignore", "pipe", "pipe"],
        maxBuffer: 128 * 1024 * 1024,
        windowsHide: true
      });
    } catch (error) {
      const partial = error as { stdout?: unknown };
      if (typeof partial.stdout === "string") {
        try {
          JSON.parse(partial.stdout);
          output = partial.stdout;
        } catch {
          return synthesizeAstFromCpp(source);
        }
      } else {
        return synthesizeAstFromCpp(source);
      }
    }
    const ast = JSON.parse(output) as ClangNode;
    if (Buffer.byteLength(output, "utf8") <= 48 * 1024 * 1024) {
      try {
        mkdirSync(cacheDirectory, { recursive: true });
        writeFileSync(cacheFile, output, "utf8");
        const stale = readdirSync(cacheDirectory)
          .filter((entry) => entry.endsWith(".json"))
          .map((entry) => ({ path: join(cacheDirectory, entry), modified: statSync(join(cacheDirectory, entry)).mtimeMs }))
          .sort((a, b) => b.modified - a.modified)
          .slice(2048);
        for (const entry of stale) rmSync(entry.path, { force: true });
      } catch {
        // Caching is an optimization only.
      }
    }
    return ast;
  } catch {
    return synthesizeAstFromCpp(source);
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
