#include <bits/stdc++.h>
using namespace std;

void depthFirstSearchHelper(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) depthFirstSearchHelper(v, adj, visited);
    }
}

void depthFirstSearch(int n, const vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) depthFirstSearchHelper(i, adj, visited);
    }
}

void breadthFirstSearch(int n, int startNode, const vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

vector<long long> dijkstraShortestPath(int n, int source, const vector<vector<pair<int, long long>>>& adj) {
    vector<long long> dist(n, numeric_limits<long long>::max());
    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (const auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

vector<int> zeroOneBfs(int n, int source, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, numeric_limits<int>::max());
    deque<int> dq;
    dist[source] = 0;
    dq.push_back(source);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (const auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}

void unknownGraphCallback(int n, const vector<vector<int>>& adj, std::function<void(int)> callback) {
    vector<bool> visited(n, false);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        callback(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
