#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

bool cf_r12_hash_850(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_851(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_852(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_853(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_854(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_855(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_856(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_857(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_858(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_859(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_860(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_861(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_862(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_863(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_864(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_865(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_866(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_867(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_868(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_869(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_870(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_871(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_872(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_873(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_874(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_875(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_876(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_877(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_878(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_879(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_880(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_881(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_882(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_883(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_884(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_885(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_886(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_887(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_888(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_889(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_890(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_891(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return true;
    seen.insert(x);
  }
  return false;
}
long long cf_r12_hash_892(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_893(const vector<int>& a) {
  set<int> seen;
  for (int x : a) seen.insert(x);
  return (long long)seen.size();
}
long long cf_r12_hash_894(const vector<int>& a) {
  unordered_map<int, int> freq;
  for (int x : a) freq[x]++;
  return (long long)freq.size();
}
bool cf_r12_hash_895(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_896(const vector<int>& a) {
  set<int> seen;
  for (int x : a) {
    if (seen.contains(x)) return true;
    seen.insert(x);
  }
  return false;
}
int cf_r12_hash_897(const vector<int>& a) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(x)) return x;
    seen.insert(x);
  }
  return -1;
}
bool cf_r12_hash_898(const vector<int>& a, int target) {
  unordered_set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}
bool cf_r12_hash_899(const vector<int>& a, int target) {
  set<int> seen;
  for (int x : a) {
    if (seen.count(target - x)) return true;
    seen.insert(x);
  }
  return false;
}