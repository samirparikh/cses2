#include <stdio.h>
#include <stdlib.h>

int compare_long_longs(const void *a, const void *b)
{
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

int main(void) {
    int       num_children;
    long long max_weight;

    if (scanf("%d %lld", &num_children, &max_weight) != 2) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    long long child_weight[num_children];

    for (int i = 0; i < num_children; i++) {
        if (scanf("%lld", &child_weight[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }

    qsort(child_weight, num_children, sizeof(child_weight[1]), compare_long_longs);

    for (int i = 0; i < num_children; i++) printf("%lld ", child_weight[i]); printf("\n");

    return 0;
}
