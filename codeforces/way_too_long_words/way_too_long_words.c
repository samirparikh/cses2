// codeforces: Way Too Long Words

#include <stdio.h>
#include <string.h>

#define MAXCHAR 100 + 2

int main(void) {

    int n;
    char line[MAXCHAR];
    size_t length;

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
        line[strcspn(line, "\n")] = '\0';
        length = strlen(line);
        if (length > 10) {
            printf("%c%zu%c\n", line[0], length - 2, line[length - 1]);
        }
        else {
            printf("%s\n", line);
        }
    }

    return 0;
}
