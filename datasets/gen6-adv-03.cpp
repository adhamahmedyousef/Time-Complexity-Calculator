// Generated family: gen6-adv-03
// Labels derived from first principles.
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int unsupportedCallbackLoop_66(const vector<int>& a, int (*predicate)(int)) { int c = 0; for (int x : a) if (predicate(x) > 0) ++c; return c; }
