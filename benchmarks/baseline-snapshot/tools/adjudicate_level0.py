#!/usr/bin/env python3
"""
Groups cpp-pack-level0-400 manifest cases by normalized code shape so each
DISTINCT template is adjudicated once. Read-only; prints shape -> label -> engine.
The engine result comes from the built analyzer (imported fresh).
"""
import glob
import json
import os
import re
import subprocess
import sys

DATASETS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "datasets")

def normalize(source: str) -> str:
    text = source
    # Strip comments and collapse whitespace for shape comparison.
    text = re.sub(r"//[^\n]*", "", text)
    text = re.sub(r"\s+", " ", text).strip()
    return text

groups = {}
for path in sorted(glob.glob(os.path.join(DATASETS, "cpp-pack-level0-400-*.manifest.json"))):
    stem = path[:-len(".manifest.json")]
    with open(path, encoding="utf-8") as handle:
        manifest = json.load(handle)
    with open(stem + ".cpp", encoding="utf-8") as handle:
        source = handle.read()
    shape = normalize(source)
    for case in manifest.get("cases", []):
        groups.setdefault(shape, []).append((os.path.basename(stem), case))

print(f"{len(groups)} distinct shapes, {sum(len(v) for v in groups.values())} cases")
for index, (shape, cases) in enumerate(sorted(groups.items(), key=lambda kv: -len(kv[1]))):
    labels = {}
    for _, case in cases:
        key = (case["time"], case["space"], case["confidence"])
        labels[key] = labels.get(key, 0) + 1
    print(f"--- shape {index}: {len(cases)} cases, labels: {labels}")
    print("    ", shape[:400])
