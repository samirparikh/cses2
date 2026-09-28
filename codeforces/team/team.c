// Codeforces: Team

#include <stdio.h>

int main(void) {

    int n, a, b, c;
    int total = 0;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d %d %d", &a, &b, &c) != 3) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }
        if (a + b + c > 1) total++;
    }

    printf("%d\n", total);

    return 0;
}
