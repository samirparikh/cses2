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

    // reverse sort array
    qsort(child_weight, num_children, sizeof(child_weight[1]), compare_long_longs);

    // for (int i = 0; i < num_children; i++) printf("%lld ", child_weight[i]); printf("\n");

    // initialize pointers
    int heavy = 0;
    int light = num_children - 1;

    int gondolas = 0;

    while (heavy <= light) {
        // if child weight equals max weight, put one child in gondola and move to the next
        // heaviest child by incrementing heavy pointer
        // printf("-------------------\n");
        // printf("top of loop: heavy = %d, light = %d\n", heavy, light);
        // printf("comparing heavy (%lld) with light (%lld)\n", child_weight[heavy], child_weight[light]);
        if (child_weight[heavy] == max_weight) {
            // printf("heavy child equals max weight of %lld\n", max_weight);
            gondolas++;
            // printf("putting heavy child into gondola %d\n", gondolas);
            heavy++;
        }

        // else, check to see if heavy child can be paired with light child
        else if (child_weight[heavy] + child_weight[light] <= max_weight) {
            // put both children in gondola and increment pointers
            gondolas++;
            // printf("able to put heavy and light children into gondola %d\n", gondolas);
            heavy++;
            light--;
        }

        // otherwise, put the less than max weight heavy child in gondola by themselves
        else {
            gondolas++;
            // printf("less than max weight heavy child goes into gondola %d\n", gondolas);
            heavy++;
        }
        // printf("bottom of loop: heavy = %d, light = %d\n", heavy, light);
    }

    printf("%d\n", gondolas);

    return 0;
}
