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

    // sort movies based on end time
    qsort(movies, num_movies, sizeof(movies[0]), compare_time);

    int count = 1;

    // watched is the index of the last movie we watched
    int watched = 0;

    // let's start examing the rest of the movies, starting with movie[1]
    for (int i = 1; i < num_movies; i++) {
        if (movies[i].start >= movies[watched].end) {
            watched = i;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
