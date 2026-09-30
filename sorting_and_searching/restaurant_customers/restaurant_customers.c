// sorting_and_searching: restaurant customers

#include <stdio.h>

#define MAX_TIMES 1000000000

int main(void) {

    int times[MAX_TIMES] = {0};

    int num_customers;

    if (scanf("%d", &num_customers) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    unsigned long long enter, exit;

    for (int i = 0; i < num_customers; i++) {
        if (scanf("%llu %llu", &enter, &exit) != 2) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }

    return 0;
}
