#include <stdio.h>
#include <stdlib.h>

/*
 * Comparison function used by qsort().
 *
 * Parameters:
 *   a - pointer to the first element being compared
 *   b - pointer to the second element being compared
 *
 * qsort() always passes pointers of type const void *,
 * so we must cast them back to the actual element type
 * (in this case, int).
 *
 * Return value:
 *   < 0 if *a should come before *b
 *     0 if they are equal
 *   > 0 if *a should come after *b
 */
int compare_ints(const void *a, const void *b)
{
    // Convert the generic pointers into int pointers,
    // then dereference them to obtain the integer values.
    int x = *(const int *)a;
    int y = *(const int *)b;

    // Return a negative value if x should come first.
    if (x < y)
        return -1;

    // Return a positive value if y should come first.
    if (x > y)
        return 1;

    // Return zero if the values are equal.
    return 0;
}

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
     *   compare_ints        Function used to compare elements.
     */
    qsort(x, n, sizeof(x[0]), compare_ints);

    for (int i = 1; i < n; i++) {
        if (x[i] != x[i-1])
            distinct++;
    }

    printf("%d", distinct);

    return 0;
}
