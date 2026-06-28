// Repetitions
// https://cses.fi/problemset/
//
// Read from stdin, write the answer to stdout.

#include <stdio.h>
#include <string.h>

enum { ARRAY_SIZE = 1000000 };

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

    // printf("value of len is %ld\n", len);

    long max_length = 0;
    for (long currentElement = 0; currentElement < len - 1; currentElement++) {
        long currentLength = 1;
        long nextElement = currentElement + 1;
        while (nextElement < len) {
            // printf("-------------------\n");
            // printf("comparing %ld:%c with %ld:%c\n",
            //         currentElement, x[currentElement], nextElement, x[nextElement]);
            if (x[currentElement] == x[nextElement]) {
                // printf("found a match! ");
                currentLength++;
                nextElement++;
                // printf("current length is %ld\n", currentLength);
                // are we now at the end of the string?
                // printf("%ld and %ld\n", nextElement, len);
                if (nextElement == len) {
                     // printf("we should be done at this point\n");
                     if (currentLength > max_length)
                         max_length = currentLength;
                     currentElement = len - 1;
                }
            }
            else {
                if (currentLength > max_length)
                    max_length = currentLength;
                break;
            }
        }
    }
    // printf("the max repeating length is %ld", max_length);
    printf("%ld", max_length);

    return 0;
}
