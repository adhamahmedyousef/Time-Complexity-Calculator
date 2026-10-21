#include <bits/stdc++.h>
using namespace std;

// User-provided simulation, normalized only into a callable test unit.
string simulation(long long n, long long a, long long b) {
  long long wins = 0, losses = 0, draws = 0;
  bool possible = true;
  for (long long i = 0; i < n; ++i) {
    if (a != b) {
      if (a > b) { a -= 3; ++wins; }
      else { b -= 3; ++losses; }
    } else if (a < n - i) { possible = false; break; }
    else if (a > n - i) { ++losses; b -= 3; }
    else { draws += n - i; a -= n - i; b -= n - i; break; }
  }
  string answer;
  if (!possible || a || b || wins + losses + draws > n) return answer;
  answer.append(static_cast<size_t>(draws), 'D');
  answer.append(static_cast<size_t>(losses), 'W');
  answer.append(static_cast<size_t>(wins), 'L');
  return answer;
}

struct Dsu {
  vector<int> parent;
  explicit Dsu(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }
  int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
  bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; parent[b] = a; return true; }
};

vector<int> offline_dsu(int n, vector<tuple<int, int, int>> edges, vector<pair<long long, int>> queries) {
  sort(queries.begin(), queries.end(), greater<>());
  sort(edges.begin(), edges.end(), greater<>());
  Dsu dsu(n + 1); vector<int> result(queries.size()); int components = n, edge = 0;
  for (const auto &[threshold, index] : queries) {
    while (edge < static_cast<int>(edges.size()) && get<0>(edges[edge]) > threshold) {
      if (dsu.unite(get<1>(edges[edge]), get<2>(edges[edge]))) --components;
      ++edge;
    }
    result[index] = components;
  }
  return result;
}

long long grouped_priority(int n, int k, int copies, const vector<pair<int, int>> &items) {
  unordered_map<int, pair<int, int>> remaining;
  unordered_map<int, vector<int>> values;
  for (const auto &[value, color] : items) { values[color].push_back(value); remaining[color] = {copies, 0}; }
  for (auto &[color, group] : values) sort(group.begin(), group.end(), greater<>());
  priority_queue<pair<int, int>> pq;
  for (const auto &[color, state] : remaining) pq.push({values[color][0], color});
  long long answer = 0;
  while (!pq.empty() && k--) {
    const auto [value, color] = pq.top(); pq.pop(); answer += value;
    auto &[left, index] = remaining[color]; --left; ++index;
    if (left > 0 && index < static_cast<int>(values[color].size())) pq.push({values[color][index], color});
  }
  return answer;
}

vector<long long> bit_prefix_queries(const vector<int> &values, const vector<pair<int, int>> &queries) {
  constexpr int bits = 31; const int n = static_cast<int>(values.size());
  vector<vector<int>> prefix(bits, vector<int>(n + 1));
  for (int bit = 0; bit < bits; ++bit) for (int i = 1; i <= n; ++i)
    prefix[bit][i] = prefix[bit][i - 1] + ((values[i - 1] >> bit) & 1);
  vector<long long> result;
  for (const auto &[left, right] : queries) {
    long long sum = 0, length = right - left + 1;
    for (int bit = 0; bit < bits; ++bit) { const long long ones = prefix[bit][right] - prefix[bit][left - 1]; sum += ones * (length - ones) * (1LL << bit); }
    result.push_back(sum);
  }
  return result;
}

long long constant_case(long long a, long long b) { return (a == 3 ? 0 : a) + (b == 3 ? 0 : b); }
