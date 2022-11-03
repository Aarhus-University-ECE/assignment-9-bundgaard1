#include "sum.h"

int sum(int a[], int n) {
    // Recursive step:
    if (n > 0) {
        return a[n - 1] + sum(a, n - 1);
    }

    // Base case:
    else {
        return 0;
    }
    return 0;
}