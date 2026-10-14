// sorting_and_searching: restaurant customers

#include <stdio.h>

#define MAX_CUSTOMERS 200000

typedef struct event {
    unsigned long time;
    int change;
} event;

int array_max(int *a, size_t length) {
    int max = a[0];
    for (size_t i = 1; i < length; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main(void) {

    event events[MAX_CUSTOMERS] = {0};

    int num_customers;

    if (scanf("%d", &num_customers) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    unsigned long long enter, exit, x;

    for (int i = 0; i < num_customers; i++) {
        if (scanf("%llu %llu", &enter, &exit) != 2) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }

        // printf("-------------\n");

        for (x = enter; x <= exit; x++) {
            // printf("updating times[%llu] from %d to ", x, times[x]);
            times[x]++;
            // printf("%d\n", times[x]);
        }

    }

    int max = array_max(times, MAX_TIMES);
    printf("%d\n", max);

    return 0;
}
