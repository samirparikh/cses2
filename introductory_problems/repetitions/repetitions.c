// Repetitions
// https://cses.fi/problemset/
//
// Read from stdin, write the answer to stdout.

#include <stdio.h>
#include <string.h>

enum { ARRAY_SIZE = 100 };

// Reads a line into x, strips the trailing newline.
// Returns the length of the string, or -1 on EOF/error.
int read_input(char *x, int size) {
    if (fgets(x, size, stdin) == NULL) {
        return -1;
    }

    size_t len = strlen(x);

    if (len > 0 && x[len - 1] == '\n') {
        x[len - 1] = '\0';
        len--;
    }

    return (int)len;
}

int main(void) {
    char x[ARRAY_SIZE];

    signed long len = read_input(x, ARRAY_SIZE);
    if (len < 0) {
        return 0;
    }

    // printf("x[0] = %c\n", x[0]);
    // printf("x[1] = %c\n", x[1]);
    // printf("x[2] = %c\n", x[2]);

    printf("value of len is %ld\n", len);

    long max_length = 0;
    for (long currentElement = 0; currentElement < len - 1; currentElement++) {
        //printf("x[%ld] = %c\n", currentElement, x[currentElement]);
        long currentLength = 0;
        long nextElement = currentElement + 1;
        while (nextElement < len) {
            printf("comparing %c with %c\n", x[currentElement], x[nextElement]);
            if (x[currentElement] == x[nextElement]) {
                printf("found a match!\n");
                currentLength++;
                nextElement++;
            }
            else {
                if (currentLength > max_length)
                    max_length = currentLength;
                break;
            }
        }
    }
    printf("the max repeating length is %ld", max_length);

    return 0;
}
