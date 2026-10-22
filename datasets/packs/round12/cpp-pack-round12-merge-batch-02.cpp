#include <vector>
using namespace std;

void cf_r12_mergesort_50(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_50(a, l, mid);
  cf_r12_mergesort_50(a, mid + 1, r);
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
void cf_r12_mergesort_51(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_51(a, l, mid);
  cf_r12_mergesort_51(a, mid + 1, r);
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
void cf_r12_mergesort_52(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_52(a, l, mid);
  cf_r12_mergesort_52(a, mid + 1, r);
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
void cf_r12_mergesort_53(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_53(a, l, mid);
  cf_r12_mergesort_53(a, mid + 1, r);
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
void cf_r12_mergesort_54(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_54(a, l, mid);
  cf_r12_mergesort_54(a, mid + 1, r);
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
void cf_r12_mergesort_55(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_55(a, l, mid);
  cf_r12_mergesort_55(a, mid + 1, r);
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
void cf_r12_mergesort_56(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_56(a, l, mid);
  cf_r12_mergesort_56(a, mid + 1, r);
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
void cf_r12_mergesort_57(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_57(a, l, mid);
  cf_r12_mergesort_57(a, mid + 1, r);
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
void cf_r12_mergesort_58(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_58(a, l, mid);
  cf_r12_mergesort_58(a, mid + 1, r);
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
void cf_r12_mergesort_59(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_59(a, l, mid);
  cf_r12_mergesort_59(a, mid + 1, r);
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
void cf_r12_mergesort_60(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_60(a, l, mid);
  cf_r12_mergesort_60(a, mid + 1, r);
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
void cf_r12_mergesort_61(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_61(a, l, mid);
  cf_r12_mergesort_61(a, mid + 1, r);
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
void cf_r12_mergesort_62(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_62(a, l, mid);
  cf_r12_mergesort_62(a, mid + 1, r);
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
void cf_r12_mergesort_63(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_63(a, l, mid);
  cf_r12_mergesort_63(a, mid + 1, r);
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
void cf_r12_mergesort_64(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_64(a, l, mid);
  cf_r12_mergesort_64(a, mid + 1, r);
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
void cf_r12_mergesort_65(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_65(a, l, mid);
  cf_r12_mergesort_65(a, mid + 1, r);
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
void cf_r12_mergesort_66(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_66(a, l, mid);
  cf_r12_mergesort_66(a, mid + 1, r);
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
void cf_r12_mergesort_67(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_67(a, l, mid);
  cf_r12_mergesort_67(a, mid + 1, r);
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
void cf_r12_mergesort_68(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_68(a, l, mid);
  cf_r12_mergesort_68(a, mid + 1, r);
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
void cf_r12_mergesort_69(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_69(a, l, mid);
  cf_r12_mergesort_69(a, mid + 1, r);
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
void cf_r12_mergesort_70(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_70(a, l, mid);
  cf_r12_mergesort_70(a, mid + 1, r);
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
void cf_r12_mergesort_71(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_71(a, l, mid);
  cf_r12_mergesort_71(a, mid + 1, r);
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
void cf_r12_mergesort_72(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_72(a, l, mid);
  cf_r12_mergesort_72(a, mid + 1, r);
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
void cf_r12_mergesort_73(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_73(a, l, mid);
  cf_r12_mergesort_73(a, mid + 1, r);
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
void cf_r12_mergesort_74(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_74(a, l, mid);
  cf_r12_mergesort_74(a, mid + 1, r);
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
void cf_r12_mergesort_75(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_75(a, l, mid);
  cf_r12_mergesort_75(a, mid + 1, r);
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
void cf_r12_mergesort_76(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_76(a, l, mid);
  cf_r12_mergesort_76(a, mid + 1, r);
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
void cf_r12_mergesort_77(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_77(a, l, mid);
  cf_r12_mergesort_77(a, mid + 1, r);
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
void cf_r12_mergesort_78(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_78(a, l, mid);
  cf_r12_mergesort_78(a, mid + 1, r);
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
void cf_r12_mergesort_79(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_79(a, l, mid);
  cf_r12_mergesort_79(a, mid + 1, r);
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
void cf_r12_mergesort_80(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_80(a, l, mid);
  cf_r12_mergesort_80(a, mid + 1, r);
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
void cf_r12_mergesort_81(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_81(a, l, mid);
  cf_r12_mergesort_81(a, mid + 1, r);
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
void cf_r12_mergesort_82(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_82(a, l, mid);
  cf_r12_mergesort_82(a, mid + 1, r);
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
void cf_r12_mergesort_83(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_83(a, l, mid);
  cf_r12_mergesort_83(a, mid + 1, r);
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
void cf_r12_mergesort_84(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_84(a, l, mid);
  cf_r12_mergesort_84(a, mid + 1, r);
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
void cf_r12_mergesort_85(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_85(a, l, mid);
  cf_r12_mergesort_85(a, mid + 1, r);
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
void cf_r12_mergesort_86(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_86(a, l, mid);
  cf_r12_mergesort_86(a, mid + 1, r);
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
void cf_r12_mergesort_87(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_87(a, l, mid);
  cf_r12_mergesort_87(a, mid + 1, r);
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
void cf_r12_mergesort_88(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_88(a, l, mid);
  cf_r12_mergesort_88(a, mid + 1, r);
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
void cf_r12_mergesort_89(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_89(a, l, mid);
  cf_r12_mergesort_89(a, mid + 1, r);
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
void cf_r12_mergesort_90(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_90(a, l, mid);
  cf_r12_mergesort_90(a, mid + 1, r);
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
void cf_r12_mergesort_91(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_91(a, l, mid);
  cf_r12_mergesort_91(a, mid + 1, r);
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
void cf_r12_mergesort_92(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_92(a, l, mid);
  cf_r12_mergesort_92(a, mid + 1, r);
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
void cf_r12_mergesort_93(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_93(a, l, mid);
  cf_r12_mergesort_93(a, mid + 1, r);
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
void cf_r12_mergesort_94(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_94(a, l, mid);
  cf_r12_mergesort_94(a, mid + 1, r);
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
void cf_r12_mergesort_95(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_95(a, l, mid);
  cf_r12_mergesort_95(a, mid + 1, r);
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
void cf_r12_mergesort_96(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_96(a, l, mid);
  cf_r12_mergesort_96(a, mid + 1, r);
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
void cf_r12_mergesort_97(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_97(a, l, mid);
  cf_r12_mergesort_97(a, mid + 1, r);
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
void cf_r12_mergesort_98(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  cf_r12_mergesort_98(a, l, mid);
  cf_r12_mergesort_98(a, mid + 1, r);
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
void cf_r12_mergesort_99(vector<int>& a, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  cf_r12_mergesort_99(a, l, mid);
  cf_r12_mergesort_99(a, mid + 1, r);
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