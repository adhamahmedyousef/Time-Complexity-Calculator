# Native LibTooling analyzer

This target is the production upgrade path for Project X. It is intentionally
separate from the existing TypeScript analyzer until it compiles and passes the
same corpus checks.

It uses LibTooling directly, which means Clang performs preprocessing, macro
expansion, template parsing, type resolution, and AST construction locally.
The executable emits a verified structural JSON summary: main-file function
names, resolved direct-callee names, per-function and global loop kinds,
self-recursion counts, and Clang CFG basic-block counts. The resolved callee
edge is an AST fact, not a textual search, so it remains valid across normal
whitespace, comments, namespace qualification, and macro-expanded call sites.
Subsequent milestones move symbolic bounds, CFG/data-flow, and algorithm
recognizers into this native process.

Example output:

```json
{"parsed":true,"functions":1,"forLoops":1,"whileLoops":0,"doLoops":0,"rangeForLoops":0,"calls":2,"functionFacts":[{"name":"mergeLike","cfgBlocks":8,"directCalls":2,"selfRecursiveCalls":2,"forLoops":1,"whileLoops":0,"doLoops":0,"rangeForLoops":0,"directCallees":["mergeLike"]}]}
```

The Project X bootstrap pins LLVM/Clang to one version and builds the required
development libraries. Configure this target using matching package paths:

```powershell
cmake -S native-analyzer -B C:\local-build\project-x-native -G Ninja `
  -DClang_DIR=C:\path\to\llvm-install\lib\cmake\clang `
  -DLLVM_DIR=C:\path\to\llvm-install\lib\cmake\llvm `
  -DCMAKE_BUILD_TYPE=Release `
  -DCMAKE_TRY_COMPILE_CONFIGURATION=Release
cmake --build C:\local-build\project-x-native
```

Keep the native build directory outside OneDrive: MSVC temporary PDB files can
be locked by file-sync clients. The verified local Release executable is about
28 MiB before VSIX packaging.

The extension will only switch to this executable after the native test harness
passes; the current local AST process remains the safe fallback.
