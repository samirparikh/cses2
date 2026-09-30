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
    
    for (size_t i = 0; s1[i]; i++) {
        if (tolower(s1[i]) < tolower(s2[i])) {
            printf("-1\n");
            return 0;
        }
        if (tolower(s1[i]) > tolower(s2[i])) {
            printf("1\n");
            return 0;
        }
    }

    printf("0\n");

    return 0;
}
