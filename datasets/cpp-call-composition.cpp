#include <algorithm>
#include <vector>
using namespace std;

int localMaximum(const vector<int>& values, int n) {
    int best = values[0];
    for (int i = 1; i < n; ++i) best = max(best, values[i]);
    return best;
}

int localCallInsideLoops(const vector<int>& values, int n) {
    int total = 0;
    for (int row = 0; row < n; ++row)
        for (int column = 0; column < n; ++column)
            total += localMaximum(values, n);
    return total;
}

int maxElementInsideLoops(const vector<int>& values, int n) {
    int total = 0;
    for (int row = 0; row < n; ++row)
        for (int column = 0; column < n; ++column)
            total += *max_element(values.begin(), values.end());
    return total;
}

int externalCallMustBeUnknown(int n) {
    extern int externalScore(int);
    int total = 0;
    for (int i = 0; i < n; ++i) total += externalScore(i);
    return total;
}
