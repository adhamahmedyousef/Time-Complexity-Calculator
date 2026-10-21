#include <bits/stdc++.h>
using namespace std;


// monotonic-stack-01
long long monotonic_stack_01(const vector<int>& a) { vector<int> st; long long ans=0; for (int x:a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); ans += st.size(); } return ans; }

// monotonic-stack-02
long long monotonic_stack_02(const vector<int>& a) { vector<int> st; long long ans=0; for (int x:a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); ans += st.size(); } return ans; }

// monotonic-stack-03
long long monotonic_stack_03(const vector<int>& a) { vector<int> st; long long ans=0; for (int x:a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); ans += st.size(); } return ans; }

// monotonic-stack-04
long long pack_project_x_p0_p1_pack_monotonic_stack_04(const vector<int>& a) { vector<int> st; long long ans=0; for (int x:a) { while (!st.empty() && st.back() > x) st.pop_back(); st.push_back(x); ans += st.size(); } return ans; }
