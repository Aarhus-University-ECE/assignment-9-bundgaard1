#include "search.h"

#include <stdbool.h>

bool search(int a[], int n, int x) {
    if (n > 0) {
        // Base case 1:
        if (a[n - 1] == x) {
            return true;
        }
        // Recursive step:
        else {
            return search(a, n - 1, x);
        }
    }
    // Base case 2:
    else {
        return false;
    }

    return 0;
}