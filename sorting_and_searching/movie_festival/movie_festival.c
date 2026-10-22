// sorting_and_searching: movie festival

#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
    int start;
    int end;
} movie;

int compare_time(const void *a, const void *b) {
    const movie *movie_a = a;
    const movie *movie_b = b;

    if (movie_a->end < movie_b->end) return -1;
    if (movie_a->end > movie_b->end) return 1;
    return 0;
}

int main(void) {

    int num_movies;
    int count = 0;

    if (scanf("%d", &num_movies) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    movie movies[num_movies];

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
