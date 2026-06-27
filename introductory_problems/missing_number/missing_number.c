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
    printf("Hello world!\n");
    int n, x, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
    }
    printf("sum is %d\n", sum);
    return 0;
}
