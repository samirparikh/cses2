/*
 * Comparison functions for use with qsort() (and bsearch()).
 *
 * qsort() always passes pointers of type `const void *`, so each
 * comparator must cast them back to the actual element type before
 * dereferencing.
 *
 * Return value contract:
 *   < 0 if *a should come before *b
 *     0 if they are equal
 *   > 0 if *a should come after *b
 *
 * The functions are `static inline` so that this header can be
 * included from any translation unit without producing duplicate
 * symbols at link time. Each .c file that includes this header
 * gets its own private copy.
 */

#ifndef COMPARE_INTS_H
#define COMPARE_INTS_H

static inline int compare_ints(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static inline int compare_long_longs(const void *a, const void *b)
{
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

#endif
