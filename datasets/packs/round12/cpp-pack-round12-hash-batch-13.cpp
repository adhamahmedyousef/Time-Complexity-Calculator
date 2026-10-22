#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

bool cf_r12_hash_600(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_601(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_602(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_603(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_604(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_605(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_606(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_607(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_608(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_609(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_610(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_611(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_612(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_613(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_614(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_615(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_616(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_617(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_618(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_619(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_620(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_621(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_622(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_623(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_624(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_625(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_626(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_627(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_628(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_629(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_630(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_631(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_632(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_633(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_634(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_635(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_636(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_637(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_638(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_639(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_640(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_641(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_642(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_643(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_644(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_645(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_646(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_647(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_648(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_649(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}