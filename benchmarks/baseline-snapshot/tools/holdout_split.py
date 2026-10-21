#!/usr/bin/env python3
"""
Generates datasets/holdout-manifests.txt — the locked family-split holdout.

Rule (deterministic, documented):
  1. Whole families below are locked. They were chosen to span distinct
     analysis topics (amortized DSU, lazy trees, graph algorithms, tree
     queries, sweep line, two pointers, coordinate compression) and include
     the largest single-topic family (cpp-dsu-amortized).
  2. From the mixed cpp-pack-level0-400-pack-level0 batch, every 6th manifest
     (sorted by name) joins the holdout so no per-case cherry-picking occurs.

The holdout is measured once at project start (baseline) and once at the end.
It must never drive engine changes. Delete this file to dissolve the split.
"""
import os
from collections import defaultdict

DATASETS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "datasets")
OUT = os.path.join(DATASETS, "holdout-manifests.txt")

LOCKED_FAMILIES = [
    "cpp-dsu-amortized",
    "cpp-pack-project-x-p0-p1-pack-lazy-segment-tree",
    "cpp-advanced-graphs",
    "cpp-pack-project-x-p0-p1-pack-lca",
    "cpp-pack-project-x-p0-p1-pack-sweep-line-events",
    "cpp-two-pointers-sliding-window",
    "cpp-pack-project-x-p0-p1-pack-coordinate-compression",
]

MIXED_PREFIX = "cpp-pack-level0-400-pack-level0"
MIXED_STRIDE = 6

manifests = sorted(n for n in os.listdir(DATASETS) if n.endswith(".manifest.json"))
holdout = set()
for name in manifests:
    base = name.replace(".manifest.json", "")
    if base in LOCKED_FAMILIES:
        holdout.add(name)

mixed = [name for name in manifests if name.startswith(MIXED_PREFIX)]
holdout.update(mixed[::MIXED_STRIDE])

with open(OUT, "w", encoding="utf-8", newline="\n") as handle:
    handle.write("# Locked family-split holdout (see tools/holdout_split.py)\n")
    for name in sorted(holdout):
        handle.write(name + "\n")
print(f"{len(holdout)} holdout manifests written to {OUT}")
