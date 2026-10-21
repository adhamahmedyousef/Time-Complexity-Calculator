#include <bits/stdc++.h>
using namespace std;

void nonProgressingWhileLoop(int n) {
    int i = n;
    while (i > 0) {
        if (i % 2 == 0) {
            i /= 2;
        } else {
            i = i * 3 + 1;
        }
    }
}

void pointerAliasingSideEffects(int* a, int* b, int n) {
    for (int i = 0; i < n; ++i) {
        *a += *b;
    }
}

template <typename T>
void templateUnconstrainedOperation(T& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        it->process();
    }
}

void externalApiCallLoop(int n) {
    for (int i = 0; i < n; ++i) {
        system("echo test > /dev/null");
    }
}
