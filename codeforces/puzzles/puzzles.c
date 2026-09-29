// codeforces: puzzles

#include <stdio.h>
#include <stdlib.h>

static inline int compare_ints(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}


int main(void) {

    int num_students, num_puzzles;

    if (scanf("%d %d", &num_students, &num_puzzles) != 2) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    int puzzles[num_puzzles];

    for (int i = 0; i < num_puzzles; i++) {
        if (scanf("%d", &puzzles[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }

    qsort(puzzles, num_puzzles, sizeof(puzzles[0]), compare_ints);

    int least_difference = 1000;

    for (int i = 0; i <= num_puzzles - num_students; i++) {
        if (puzzles[i + num_students - 1] - puzzles[i] < least_difference)
            least_difference = puzzles[i + num_students - 1] - puzzles[i];
    }

    printf("%d\n", least_difference);

    return 0;
}
