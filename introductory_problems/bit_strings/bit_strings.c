// Introductory Problems: Bit Strings

#include <stdio.h>

#define MODULUS 1000000007

int main(void) {

    unsigned long long n;
    unsigned long long result = 1;
    if (scanf("%llu", &n) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (unsigned long i = 1; i <= n; i++) {
        result = (result * 2) % MODULUS;
    }

    printf("%llu\n", result);

    return 0;
}
