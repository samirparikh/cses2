// sorting_and_searching: restaurant customers

#include <stdio.h>
#include <stdlib.h>

typedef struct event {
    unsigned long time;
    int change;
} event;

int compare_time(const void *a, const void *b) {
    const event *event_a = a;
    const event *event_b = b;

    if (event_a->time < event_b->time) return -1;
    if (event_a->time > event_b->time) return 1;
    return 0;
}

int main(void) {

    unsigned long num_customers;
    unsigned long current_count = 0;
    unsigned long max_cust_count = 0;

    if (scanf("%lu", &num_customers) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    unsigned long num_events = num_customers * 2;

    event events[num_events];

    unsigned long long enter, exit;

    for (unsigned long i = 0; i < num_events; i++) {
        if (scanf("%llu %llu", &enter, &exit) != 2) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }

        events[i].time   = enter;
        events[i].change = 1;
        i++;
        events[i].time   = exit;
        events[i].change = -1;
    }

    qsort(events, num_events, sizeof(events[0]), compare_time);

    for (unsigned long i = 0; i < num_events; i++) {
        current_count += events[i].change;
        if (current_count > max_cust_count)
            max_cust_count = current_count;
    }

    printf("%lu\n", max_cust_count);

    return 0;
}
