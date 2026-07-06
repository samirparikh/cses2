#include <stdio.h>
#include <stdlib.h>

#include "compare_ints.h"

int main(void) {
    int       num_applicants, num_apartments;
    long long max_difference;

    // read in number of applicants, apartments and maximum allowed difference
    if (scanf("%d %d %lld", &num_applicants, &num_apartments, &max_difference) != 3) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    // printf("%d %d %lld", num_applicants, num_apartments, max_difference);

    long long desired_size[num_applicants], apartment_size[num_apartments];

    // read in applicants' desired apartment sizes
    for (int i = 0; i < num_applicants; i++) {
        if (scanf("%lld", &desired_size[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
        // printf("%lld ", desired_size[i]);
    }

    // printf("\n");

    // read in actual available apartment sizes
    for (int i = 0; i < num_apartments; i++) {
        if (scanf("%lld", &apartment_size[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
        // printf("%lld ", apartment_size[i]);
    }
    
    // printf("\n");

    // sort the arrays
    qsort(desired_size, num_applicants, sizeof(desired_size[0]), compare_long_longs);
    qsort(apartment_size, num_apartments, sizeof(apartment_size[0]), compare_long_longs);

    for (int i = 0; i < num_applicants; i++) {
        printf("%lld ", desired_size[i]);
    }
    printf("\n");
    
    for (int i = 0; i < num_apartments; i++) {
        printf("%lld ", apartment_size[i]);
    }
    printf("\n");

    // apartment matching loop
    int applicant_pointer = 0;
    int apartment_pointer = 0;
    int matches = 0;

    while (applicant_pointer < num_applicants && apartment_pointer < num_apartments) {
        long long current_applicant = desired_size[applicant_pointer];
        long long current_apartment = apartment_size[apartment_pointer];
        printf("comparing desired size of %lld with actual size of %lld",
            current_applicant, current_apartment);

        // actual size is within tolerance
        if (llabs(current_applicant - current_apartment) <= max_difference) {
            printf("found apartment within tolerance\n");
            // increment matches
            // move pointers

        }
        

        // actual size is below tolerance
        else if (current_apartment < current_applicant - max_difference) {
            printf("current apartment size is below tolerance\n");

        }
       


        // actual size is above tolerance
        else {
            printf("current apartment size to above tolerance\n");
        }
    }


    return 0;
}
