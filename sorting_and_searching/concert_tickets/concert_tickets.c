// Sorting and Searching: Concert Tickets

#include <stdio.h>
#include <stdlib.h>

int compare_long_longs(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;

    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

int main(void) {

    int num_tickets, num_customers;
    //long long tickets, customers;

    if (scanf("%d %d", &num_tickets, &num_customers) != 2) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    long long tickets[num_tickets], customers[num_customers];

    for (int i = 0; i < num_tickets; i++) {
        if (scanf("%lld", &tickets[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }

    for (int i = 0; i < num_customers; i++) {
        if (scanf("%lld", &customers[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }

    // reverse sort tickets
    qsort(tickets, num_tickets, sizeof(tickets[0]), compare_long_longs);

    for (int i = 0; i < num_tickets; i++) printf("%lld ", tickets[i]);
    printf("\n");

    return 0;
}
