#include <algorithm>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

void sortValues(vector<int>& values) {
    sort(values.begin(), values.end());
}

int findLowerBound(const vector<int>& values, int target) {
    return static_cast<int>(lower_bound(values.begin(), values.end(), target) - values.begin());
}

long long standardGcd(long long a, long long b) {
    return gcd(a, b);
}

vector<int> appendValues(const vector<int>& values) {
    vector<int> copy;
    for (int value : values) copy.push_back(value);
    return copy;
}

set<int> orderedInsertions(const vector<int>& values) {
    set<int> result;
    for (int value : values) result.insert(value);
    return result;
}

int priorityQueueWork(const vector<int>& values) {
    priority_queue<int> heap;
    for (int value : values) heap.push(value);
    return heap.empty() ? 0 : heap.top();
}

long long unorderedFrequency(const vector<int>& values) {
    unordered_map<int, int> frequency;
    for (int value : values) ++frequency[value];
    return static_cast<long long>(frequency.size());
}
