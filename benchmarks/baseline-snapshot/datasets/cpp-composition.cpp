void halvingOuterFixedInner(int n) {
    int i = n;
    while (i > 1) {
        for (int j = 0; j < n; ++j) {
            volatile int sink = j;
            (void)sink;
        }
        i /= 2;
    }
}

void independentLogarithmicLoops(int n) {
    for (int i = 1; i < n; i *= 2)
        for (int j = 1; j < n; j *= 2) {
            volatile int sink = i + j;
            (void)sink;
        }
}

void halvingOuterDependentInner(int n) {
    for (int i = n; i > 0; i /= 2)
        for (int j = 0; j < i; ++j) {
            volatile int sink = j;
            (void)sink;
        }
}

void doublingOuterDependentInner(int n) {
    for (int i = 1; i < n; i *= 2)
        for (int j = 0; j < i; ++j) {
            volatile int sink = j;
            (void)sink;
        }
}

void halveRecursively(int n) {
    if (n <= 1) return;
    halveRecursively(n / 2);
}
