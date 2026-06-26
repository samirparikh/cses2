#include <stdio.h>

// Weird Algorithm
// https://cses.fi/problemset/task/1068
//
// Start with a number n. On each step:
//   - if n is even, divide it by 2,
//   - if n is odd,  multiply it by 3 and add 1.
// Repeat until n becomes 1, printing every value visited (n included).
//
// Note: n is up to 10^6, but the intermediate values can grow well past the
// range of a 32-bit int, so we use `long long` to stay safe.

int main(void) {
    long long n;
    scanf("%lld", &n);

    printf("%lld", n);
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        printf(" %lld", n);
    }
    printf("\n");

    return 0;
}
