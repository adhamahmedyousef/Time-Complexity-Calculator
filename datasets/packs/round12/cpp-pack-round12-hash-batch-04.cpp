#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

bool cf_r12_hash_150(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_151(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_152(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_153(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_154(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_155(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_156(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_157(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_158(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_159(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_160(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_161(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_162(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_163(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_164(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_165(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_166(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_167(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_168(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_169(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_170(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_171(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_172(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_173(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_174(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_175(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_176(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_177(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_178(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_179(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_180(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_181(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_182(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_183(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_184(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_185(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_186(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_187(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_188(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_189(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_190(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_191(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_192(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_193(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_194(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_195(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_196(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_197(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_198(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_199(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}