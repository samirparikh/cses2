// dmoj: ccc11s2

#include <stdio.h>

#define MAX_LINES 10000

int main(void) {

    int lines;
    int correct = 0;
    char responses[MAX_LINES];
    char answer;

    if (scanf("%d", &lines) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (int i = 0; i < lines; i++) {
        if (scanf(" %c", &responses[i]) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
    }

    for (int i = 0; i < lines; i++) {
        if (scanf(" %c", &answer) != 1) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
        if (responses[i] == answer) correct++;
    }

    printf("%d\n", correct);

    return 0;
}
