// Codeforces: 39j

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 256

bool read_line(char *buffer, size_t length) {
    if (fgets(buffer, length, stdin) == NULL) {
        fprintf(stderr, "invalid input\n");
        return false;
    }
    buffer[strcspn(buffer, "\n")] = '\0';  // remove newline
    return true;
}

int main(void) {

    static char s1[MAX_LENGTH + 1], s2[MAX_LENGTH + 1];
    static char pre[MAX_LENGTH], suf[MAX_LENGTH];

    // array which stores valid positions
    static unsigned long positions[MAX_LENGTH] = {0};
    // index of positions[] into which we place our answers
    unsigned long total = 0;

    // zero-indexed position of character we remove to test
    unsigned long position = 0;

    if (read_line(s1, sizeof(s1)) == false) return 1;
    if (read_line(s2, sizeof(s2)) == false) return 1;

    size_t s1_len = strlen(s1);

    // printf("s1 = %s\n", s1);
    // printf("s2 = %s\n", s2);

    /*
    * Assume that s1, the longer string, is:
    * 
    *   | 0 | 1 | 2 | 3 | 4 |
    *   ├-------------------┤
    *   | a | b | c | d | e |
    */

    // compare removal of first character (position = 0) of s1
    // destination, starting position of source, number of characters
    strncpy(suf, s1 + position + 1, s1_len - position - 1);
    // printf("initial suffix is %s\n", suf);
    if (strcmp(suf, s2) == 0) {
        // printf("%s and %s are the same\n", suf, s2);
        positions[total] = position + 1;
        total++;
    }

    // compare removal of second through penultimate characters of s1
    // positions 1 through (length - 2)
    for (position = 1; position <= s1_len - 2; position++) {
        // memcpy only copies exactly the number of bytes specified
        // it does not append null terminator
        memcpy(pre, s1, position);
        pre[position] = '\0';
        size_t len = s1_len - position - 1;
        memcpy(suf, s1 + position + 1, len);
        suf[len] = '\0';
        // printf("prefix = %s, suffix = %s\n", pre, suf);
        size_t remaining_space = sizeof(pre) - strlen(suf) - 1;
        strncat(pre, suf, remaining_space);
        // printf("comparing %s with %s\n", pre, s2);
        if (strcmp(pre, s2) == 0) {
            // printf("%s and %s are the same\n", pre, s2);
            positions[total] = position + 1;
            total++;
        }
    }

    // compare removal of last character (position = length - 1)
    memcpy(pre, s1, position);
    pre[position] = '\0';
    // printf("last prefix to compare is %s\n", pre);
    if (strcmp(pre, s2) == 0) {
        // printf("%s and %s are the same\n", pre, s2);
        positions[total] = position + 1;
        total++;
    }

    // print out results
    if (total) {
        printf("%lu\n", total);
        for (unsigned long i = 0; i < total; i++) {
            printf("%lu ", positions[i]);
        }
        printf("\n");
    } else {
        printf("0\n");
    }


    return 0;
}
