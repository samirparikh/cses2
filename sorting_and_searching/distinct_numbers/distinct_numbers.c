#include <stdio.h>
#include <stdlib.h>

#include "compare_ints.h"

int main(void)
{
    int n;
    int distinct = 1;

    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    long long x[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &x[i]) != 1) {
            fprintf(stderr, "Invalide input\n");
            return 1;
        }
    }

    /*
     * qsort() arguments:
     *
     *   numbers             Pointer to the first element.
     *   n                   Number of elements.
     *   sizeof(x[0])        Size (in bytes) of each element.
     *   compare_long_longs  Function used to compare elements.
     */
    qsort(x, n, sizeof(x[0]), compare_long_longs);

    for (int i = 1; i < n; i++) {
        if (x[i] != x[i-1])
            distinct++;
    }

    printf("%d", distinct);

    return 0;
}
