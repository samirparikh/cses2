// codeforces: watermelon

#include <stdio.h>

int main(void) {

    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    if (n > 2 && n % 2 == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
