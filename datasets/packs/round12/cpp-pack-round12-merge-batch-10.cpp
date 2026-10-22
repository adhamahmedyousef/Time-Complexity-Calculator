#include <vector>
using namespace std;

void cf_r12_mergesort_450(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_450(a, l, mid);
  cf_r12_mergesort_450(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_451(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_451(a, l, mid);
  cf_r12_mergesort_451(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_452(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_452(a, l, mid);
  cf_r12_mergesort_452(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_453(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_453(a, l, mid);
  cf_r12_mergesort_453(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_454(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_454(a, l, mid);
  cf_r12_mergesort_454(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_455(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_455(a, l, mid);
  cf_r12_mergesort_455(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_456(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_456(a, l, mid);
  cf_r12_mergesort_456(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_457(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_457(a, l, mid);
  cf_r12_mergesort_457(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_458(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_458(a, l, mid);
  cf_r12_mergesort_458(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_459(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_459(a, l, mid);
  cf_r12_mergesort_459(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_460(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_460(a, l, mid);
  cf_r12_mergesort_460(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_461(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_461(a, l, mid);
  cf_r12_mergesort_461(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_462(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_462(a, l, mid);
  cf_r12_mergesort_462(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_463(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_463(a, l, mid);
  cf_r12_mergesort_463(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_464(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_464(a, l, mid);
  cf_r12_mergesort_464(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_465(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_465(a, l, mid);
  cf_r12_mergesort_465(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_466(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_466(a, l, mid);
  cf_r12_mergesort_466(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_467(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_467(a, l, mid);
  cf_r12_mergesort_467(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_468(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_468(a, l, mid);
  cf_r12_mergesort_468(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_469(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_469(a, l, mid);
  cf_r12_mergesort_469(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_470(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_470(a, l, mid);
  cf_r12_mergesort_470(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_471(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_471(a, l, mid);
  cf_r12_mergesort_471(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_472(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_472(a, l, mid);
  cf_r12_mergesort_472(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_473(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_473(a, l, mid);
  cf_r12_mergesort_473(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_474(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_474(a, l, mid);
  cf_r12_mergesort_474(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_475(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_475(a, l, mid);
  cf_r12_mergesort_475(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_476(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_476(a, l, mid);
  cf_r12_mergesort_476(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_477(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_477(a, l, mid);
  cf_r12_mergesort_477(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_478(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_478(a, l, mid);
  cf_r12_mergesort_478(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_479(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_479(a, l, mid);
  cf_r12_mergesort_479(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_480(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_480(a, l, mid);
  cf_r12_mergesort_480(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_481(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_481(a, l, mid);
  cf_r12_mergesort_481(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_482(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_482(a, l, mid);
  cf_r12_mergesort_482(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_483(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_483(a, l, mid);
  cf_r12_mergesort_483(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_484(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_484(a, l, mid);
  cf_r12_mergesort_484(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_485(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_485(a, l, mid);
  cf_r12_mergesort_485(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_486(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_486(a, l, mid);
  cf_r12_mergesort_486(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_487(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_487(a, l, mid);
  cf_r12_mergesort_487(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_488(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_488(a, l, mid);
  cf_r12_mergesort_488(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_489(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_489(a, l, mid);
  cf_r12_mergesort_489(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_490(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_490(a, l, mid);
  cf_r12_mergesort_490(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_491(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_491(a, l, mid);
  cf_r12_mergesort_491(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_492(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_492(a, l, mid);
  cf_r12_mergesort_492(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_493(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_493(a, l, mid);
  cf_r12_mergesort_493(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_494(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_494(a, l, mid);
  cf_r12_mergesort_494(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}
void cf_r12_mergesort_495(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_495(a, l, mid);
  cf_r12_mergesort_495(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_496(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_496(a, l, mid);
  cf_r12_mergesort_496(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_497(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_497(a, l, mid);
  cf_r12_mergesort_497(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] >= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_498(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_498(a, l, mid);
  cf_r12_mergesort_498(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); k++) a[l + k] = temp[k];
}
void cf_r12_mergesort_499(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_499(a, l, mid);
  cf_r12_mergesort_499(a, mid + 1, r);
  vector<int> temp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) temp.push_back(a[i++]);
    else temp.push_back(a[j++]);
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= r) temp.push_back(a[j++]);
  for (int k = 0; k < (int)temp.size(); ++k) a[l + k] = temp[k];
}