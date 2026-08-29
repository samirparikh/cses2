#include <stdio.h>
#include <stdlib.h>

long max(long a, long b) {
    if (a > b) return a;
    return b;
}

int main(void) {

    typedef struct element {
        unsigned long long value;
        long y;
        long x;
    } element;

    element current, largest;

    long n;

    if (scanf("%ld", &n) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (long i = 0; i < n; i++) {
        if (scanf("%ld %ld", &current.y, &current.x) != 2) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }

        long m = max(current.y, current.x);
        largest.value = m * m;

        if (m % 2) {        // odd
            largest.y = 1;
            largest.x = m;
        } else {            // even
            largest.y = m;
            largest.x = 1;
        }

        long delta_y = labs(largest.y - current.y);
        long delta_x = labs(largest.x - current.x);
        long distance = delta_y + delta_x;

        printf("%llu\n", largest.value - distance);
    }
}
