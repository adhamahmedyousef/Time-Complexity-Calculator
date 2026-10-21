// Generated family: gen6-dsu-03
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int dsuFindRoot_66(vector<int>& parent, int x) { int root = x; while (root != parent[root]) root = parent[root]; int curr = x; while (curr != root) { int nxt = parent[curr]; parent[curr] = root; curr = nxt; } return root; }
