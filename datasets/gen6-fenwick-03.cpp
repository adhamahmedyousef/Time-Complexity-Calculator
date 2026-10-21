// Generated family: gen6-fenwick-03
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void fenwickScale_66(vector<int>& bit, int factor) { int n = bit.size(); for (int i = 1; i < n; ++i) bit[i] *= factor; }
