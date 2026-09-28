// codeforces: Way Too Long Words

#include <stdio.h>

#define MAXCHAR 100 + 1

int main(void) {

    int n;
    char line[MAXCHAR];

    // if (scanf("%d", &n) != 1) {
    //     fprintf(stderr, "invalid input\n");
    //     return 1;
    // }

    // char buffer[BUFFERMAX];

    if (fgets(line, MAXCHAR, stdin) == NULL) {
        return 1;
    }

    if (sscanf(line, "%d", &n) != 1) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fgets(line, MAXCHAR, stdin) == NULL) {
            return 1;
        }
        printf("line is %s\n", line);
    }

    return 0;
}
