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

    int start, end;

    for (int i = 0; i < num_movies; i++) {
        if (scanf("%d %d", &start, &end) != 2) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }

        movies[i].start = start;
        movies[i].end   = end;
    }

    qsort(movies, num_movies, sizeof(movies[0]), compare_time);

    for (int i = 0; i < num_movies; i++) {
        printf("movie %d starts at %d and ends at %d\n",
               i, movies[i].start, movies[i].end);
    }

    printf("%d\n", count);

    return 0;
}
