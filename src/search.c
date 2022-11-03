#include "search.h"

#include <stdbool.h>

bool search(int a[], int n, int x) {
    if (n > 0) {
        if (a[n - 1] == x) {
            return true;
        } else {
            return search(a, n - 1, x);
        }
    } else {
        return false;
    }

    return 0;
}