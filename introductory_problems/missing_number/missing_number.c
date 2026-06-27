#include <stdio.h>

// Missing Number
// https://cses.fi/problemset/1083
//
// You are given all numbers between 1,2,...,n except one. Your task is to find
// the missing number.
// Input
// The first input line contains an integer n.
// The second line contains n-1 numbers. Each number is distinct and between 1
// and n (inclusive).
// Output
// Print the missing number.
// Read from stdin, write the answer to stdout.

int main(void) {
    unsigned long n, x = 0;
    scanf("%lu", &n);
    unsigned long long sum = n * (n + 1) / 2;
    for (unsigned long i = 0; i < n - 1; i++) {
        scanf("%lu", &x);
        sum -= x;
    }
    printf("%llu", sum);
    return 0;
}
