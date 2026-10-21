// Generated family: gen2-greedy-01
// Labels from first principles.
using namespace std;

int actSelect_0(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return a.second < b.second; }); int count = 0; int lastEnd = -1; for (auto& p : iv) { if (p.first >= lastEnd) { ++count; lastEnd = p.second; } } return count; }
int actSelect_1(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return a.second < b.second; }); int count = 0; int lastEnd = -1; for (auto& p : iv) { if (p.first >= lastEnd) { ++count; lastEnd = p.second; } } return count; }
int actSelect_2(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return a.second < b.second; }); int count = 0; int lastEnd = -1; for (auto& p : iv) { if (p.first >= lastEnd) { ++count; lastEnd = p.second; } } return count; }
int actSelect_3(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return a.second < b.second; }); int count = 0; int lastEnd = -1; for (auto& p : iv) { if (p.first >= lastEnd) { ++count; lastEnd = p.second; } } return count; }
int actSelect_4(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return a.second < b.second; }); int count = 0; int lastEnd = -1; for (auto& p : iv) { if (p.first >= lastEnd) { ++count; lastEnd = p.second; } } return count; }
int actSelect_5(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return a.second < b.second; }); int count = 0; int lastEnd = -1; for (auto& p : iv) { if (p.first >= lastEnd) { ++count; lastEnd = p.second; } } return count; }
