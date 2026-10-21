#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int constantWork(int x) { return x * 3 + 7; }

long long linearFor(const vector<int>& a) {
    long long sum = 0;
    for (int x : a) sum += x;
    return sum;
}

int logMultiply(int n) {
    int steps = 0;
    for (int i = 1; i < n; i *= 2) ++steps;
    return steps;
}

long long nestedIndependent(int n) {
    long long work = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ++work;
    return work;
}

long long triangularLoop(int n) {
    long long work = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            ++work;
    return work;
}

long long nLogNLoop(int n) {
    long long work = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < n; j *= 2)
            ++work;
    return work;
}

long long cubicLoop(int n) {
    long long work = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                ++work;
    return work;
}

bool twoPointers(const vector<int>& a, int target) {
    int left = 0, right = static_cast<int>(a.size()) - 1;
    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == target) return true;
        if (sum < target) ++left;
        else --right;
    }
    return false;
}

int binarySearch(const vector<int>& a, int target) {
    int left = 0, right = static_cast<int>(a.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int slidingWindow(const vector<int>& a, int limit) {
    int left = 0, sum = 0, best = 0;
    for (int right = 0; right < static_cast<int>(a.size()); ++right) {
        sum += a[right];
        while (sum > limit) sum -= a[left++];
        best = max(best, right - left + 1);
    }
    return best;
}

set<int> setInserts(const vector<int>& a) {
    set<int> values;
    for (int x : a) values.insert(x);
    return values;
}

int priorityQueuePushes(const vector<int>& a) {
    priority_queue<int> pq;
    for (int x : a) pq.push(x);
    return pq.top();
}

vector<int> bfs(const vector<vector<int>>& graph, int source) {
    int n = static_cast<int>(graph.size());
    vector<int> distance(n, -1);
    queue<int> q;
    distance[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int next : graph[node]) if (distance[next] == -1) {
            distance[next] = distance[node] + 1;
            q.push(next);
        }
    }
    return distance;
}

void dfsVisit(int node, const vector<vector<int>>& graph, vector<int>& seen) {
    seen[node] = 1;
    for (int next : graph[node]) if (!seen[next]) dfsVisit(next, graph, seen);
}

vector<int> dfs(const vector<vector<int>>& graph, int source) {
    vector<int> seen(graph.size());
    dfsVisit(source, graph, seen);
    return seen;
}

vector<long long> dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
    int n = static_cast<int>(graph.size());
    vector<long long> dist(n, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[source] = 0; pq.push({0, source});
    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if (cost != dist[node]) continue;
        for (auto [next, weight] : graph[node]) if (cost + weight < dist[next]) {
            dist[next] = cost + weight;
            pq.push({dist[next], next});
        }
    }
    return dist;
}

struct DSU {
    vector<int> parent, size;
    explicit DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b); if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a; size[a] += size[b]; return true;
    }
};

int unionAll(int n, const vector<pair<int, int>>& edges) {
    DSU dsu(n);
    for (auto [a, b] : edges) dsu.unite(a, b);
    return dsu.find(0);
}

void mergeSort(vector<int>& a) {
    if (a.size() <= 1) return;
    int mid = static_cast<int>(a.size()) / 2;
    vector<int> left(a.begin(), a.begin() + mid), right(a.begin() + mid, a.end());
    mergeSort(left); mergeSort(right);
    merge(left.begin(), left.end(), right.begin(), right.end(), a.begin());
}

long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sortAndReturn(vector<int> a) {
    sort(a.begin(), a.end());
    return a.front();
}

bool externalPredicate(int);
void externalSolve(int);

void unknownCall(int x) {
    while (externalPredicate(x)) externalSolve(x);
}
