#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

bool cf_r12_hash_750(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_751(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_752(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_753(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_754(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_755(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_756(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_757(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_758(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_759(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_760(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_761(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_762(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_763(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_764(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_765(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_766(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_767(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_768(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_769(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_770(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_771(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_772(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_773(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_774(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_775(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_776(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_777(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_778(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_779(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_780(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_781(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_782(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_783(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_784(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_785(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_786(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_787(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_788(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_789(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_790(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_791(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_792(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_793(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_794(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_795(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_796(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_797(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_798(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_799(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}