// codeforces: petya and strings

#include <stdio.h>
#include <string.h>
#include <ctype.h>  // for tolower()

#define MAXCHAR 1000 + 2

int main(void) {

    char s1[MAXCHAR], s2[MAXCHAR];

    if (fgets(s1, MAXCHAR, stdin) == NULL) return 1;
    if (fgets(s2, MAXCHAR, stdin) == NULL) return 1;
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';
    
    // size_t length = strlen(s1);

    // while (*s1 && *s2) {
    //     printf("%c - %c\n", *s1, *s2);
    //     s1++;
    //     s2++;
    // }
    
    for (size_t i = 0; s1[i]; i++) {
        printf("%c - %c\n", s1[i], s2[i]);
    }

    return 0;
}
