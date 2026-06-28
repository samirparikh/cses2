// Repetitions

#include <stdio.h>
#include <string.h>

enum { ARRAY_SIZE = 1000001 };

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

    if (len == 1) {
        printf("1");
        return 0;
    }

    long max_length = 1;
    long currentElement = 0;
    while (currentElement < len - 1) {
        long currentLength = 1;
        long nextElement = currentElement + 1;
        while (nextElement < len) {
            if (x[currentElement] == x[nextElement]) {
                currentLength++;
                nextElement++;
                // are we now at the end of the string?
                if (nextElement == len) {
                     if (currentLength > max_length)
                         max_length = currentLength;
                     currentElement = len - 1;
                }
            }
            else {
                if (currentLength > max_length)
                    max_length = currentLength;
                currentElement = nextElement;;
                break;
            }
            currentElement++;
        }
    }
    printf("%ld", max_length);

    return 0;
}
