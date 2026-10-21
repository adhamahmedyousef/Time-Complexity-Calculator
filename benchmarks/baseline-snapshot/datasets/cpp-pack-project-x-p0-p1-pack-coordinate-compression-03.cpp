#include <bits/stdc++.h>
using namespace std;


// coordinate-compression-01
long long coordinate_compression_01(vector<int> a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); return (long long)a.size(); }

// coordinate-compression-02
long long coordinate_compression_02(vector<int> a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); return (long long)a.size(); }

// coordinate-compression-03
long long pack_project_x_p0_p1_pack_coordinate_compression_03(vector<int> a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); return (long long)a.size(); }
