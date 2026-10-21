#!/usr/bin/env python3
"""Counts cases per dataset manifest, grouped by family prefix."""
import json
import os
import re
from collections import defaultdict

DATASETS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "datasets")

def family_of(name: str) -> str:
    base = name.replace(".manifest.json", "")
    # Collapse trailing -NN batch numbers into a family prefix
    return re.sub(r"-\d{1,3}$", "", base)

families = defaultdict(lambda: {"manifests": 0, "cases": 0, "conf": defaultdict(int)})
for name in sorted(os.listdir(DATASETS)):
    if not name.endswith(".manifest.json"):
        continue
    with open(os.path.join(DATASETS, name), encoding="utf-8") as handle:
        manifest = json.load(handle)
    fam = family_of(name)
    families[fam]["manifests"] += 1
    families[fam]["cases"] += len(manifest.get("cases", []))
    for case in manifest.get("cases", []):
        families[fam]["conf"][case.get("confidence", "?")] += 1

total = 0
for fam, stats in sorted(families.items(), key=lambda kv: -kv[1]["cases"]):
    conf = stats["conf"]
    total += stats["cases"]
    print(f"{stats['cases']:5d} cases {stats['manifests']:4d} files  exact={conf.get('exact',0):4d} est={conf.get('estimated',0):3d} unk={conf.get('unknown',0):3d}  {fam}")
print(f"{total:5d} TOTAL")
