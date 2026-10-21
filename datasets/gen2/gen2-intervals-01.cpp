// Generated family: gen2-intervals-01
// Labels from first principles.
using namespace std;

vector<pair<int,int>> mergeIv_0(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end()); vector<pair<int,int>> merged; for (auto& p : iv) { if (!merged.empty() && merged.back().second >= p.first) merged.back().second = max(merged.back().second, p.second); else merged.push_back(p); } return merged; }
vector<pair<int,int>> mergeIv_1(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end()); vector<pair<int,int>> merged; for (auto& p : iv) { if (!merged.empty() && merged.back().second >= p.first) merged.back().second = max(merged.back().second, p.second); else merged.push_back(p); } return merged; }
vector<pair<int,int>> mergeIv_2(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end()); vector<pair<int,int>> merged; for (auto& p : iv) { if (!merged.empty() && merged.back().second >= p.first) merged.back().second = max(merged.back().second, p.second); else merged.push_back(p); } return merged; }
vector<pair<int,int>> mergeIv_3(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end()); vector<pair<int,int>> merged; for (auto& p : iv) { if (!merged.empty() && merged.back().second >= p.first) merged.back().second = max(merged.back().second, p.second); else merged.push_back(p); } return merged; }
vector<pair<int,int>> mergeIv_4(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end()); vector<pair<int,int>> merged; for (auto& p : iv) { if (!merged.empty() && merged.back().second >= p.first) merged.back().second = max(merged.back().second, p.second); else merged.push_back(p); } return merged; }
vector<pair<int,int>> mergeIv_5(vector<pair<int,int>>& iv) { sort(iv.begin(), iv.end()); vector<pair<int,int>> merged; for (auto& p : iv) { if (!merged.empty() && merged.back().second >= p.first) merged.back().second = max(merged.back().second, p.second); else merged.push_back(p); } return merged; }
