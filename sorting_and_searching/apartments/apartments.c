#include <stdio.h>
#include <stdlib.h>

int compare_long_longs(const void *a, const void *b)
{
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int       num_applicants, num_apartments;
    long long max_difference;

    // read in number of applicants, apartments and maximum allowed difference
    if (scanf("%d %d %lld", &num_applicants, &num_apartments, &max_difference) != 3) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    long long desired_size[num_applicants], apartment_size[num_apartments];

    // read in applicants' desired apartment sizes
    for (int i = 0; i < num_applicants; i++) {
        if (scanf("%lld", &desired_size[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }

    // read in actual available apartment sizes
    for (int i = 0; i < num_apartments; i++) {
        if (scanf("%lld", &apartment_size[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }
    
    // sort the arrays
    qsort(desired_size, num_applicants, sizeof(desired_size[0]), compare_long_longs);
    qsort(apartment_size, num_apartments, sizeof(apartment_size[0]), compare_long_longs);

    // apartment matching loop
    int applicant_pointer = 0;
    int apartment_pointer = 0;
    int matches = 0;

    while (applicant_pointer < num_applicants && apartment_pointer < num_apartments) {
        long long desired = desired_size[applicant_pointer];
        long long actual  = apartment_size[apartment_pointer];

        // actual size is within tolerance
        if (llabs(desired - actual) <= max_difference) {
            // increment matches
            matches++;
            // move pointers
            applicant_pointer++;
            apartment_pointer++;
        }
        
        // actual size is below tolerance
        else if (actual < desired - max_difference) {
            // if next apartment size is less than or equal to desired size + tolerance,
            // increment only the apartment pointer, and go back to beginning of loop to assess it
            // (this may be an area to optimize)
            if (apartment_size[apartment_pointer+1] <= desired + max_difference) {
                apartment_pointer++;
            }

            // otherwise, no apartments available for this applicant
            // increment both pointers only
            else {
                applicant_pointer++;
                apartment_pointer++;
            }

        }
       
        // actual size is above tolerance
        else {
            // there is no suitable apartment for this candidate
            // increment candidate pointer only
            applicant_pointer++;
        }
    }

    printf("%d\n", matches);

    return 0;
}
