#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

bool cf_r12_hash_700(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_701(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_702(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_703(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_704(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_705(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_706(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_707(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_708(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_709(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_710(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_711(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_712(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_713(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_714(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_715(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_716(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_717(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_718(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_719(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_720(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_721(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_722(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_723(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_724(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_725(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_726(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_727(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_728(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_729(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_730(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_731(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_732(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_733(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_734(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_735(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_736(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_737(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_738(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_739(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_740(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_741(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_742(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_743(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_744(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_745(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_746(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_747(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_748(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_749(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}