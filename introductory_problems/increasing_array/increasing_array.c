#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    long long moves = 0;

    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    long long x[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &x[i]) != 1) {
            fprintf(stderr, "Invalide input\n");
            return 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if (x[i] < x[i-1]) {
            moves += x[i-1] - x[i];
            x[i] = x[i-1];
        }
    }

    printf("%lld", moves);

    return 0;
}
