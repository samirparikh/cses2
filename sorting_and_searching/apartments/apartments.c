#include <stdio.h>
#include <stdlib.h>

#include "compare_ints.h"

int main(void) {
    int       num_applicants, num_apartments;
    long long max_difference;

    if (scanf("%d %d %lld", &num_applicants, &num_apartments, &max_difference) != 3) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    // printf("%d %d %lld", num_applicants, num_apartments, max_difference);

    long long desired_size[num_applicants], apartment_size[num_apartments];

    for (int i = 0; i < num_applicants; i++) {
        if (scanf("%lld", &desired_size[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
        printf("%lld ", desired_size[i]);
    }

    printf("\n");

    for (int i = 0; i < num_apartments; i++) {
        if (scanf("%lld", &apartment_size[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
        printf("%lld ", apartment_size[i]);
    }
    
    printf("\n");

    qsort(desired_size, num_applicants, sizeof(desired_size[0]), compare_long_longs);
    qsort(apartment_size, num_apartments, sizeof(apartment_size[0]), compare_long_longs);
    return 0;
}
