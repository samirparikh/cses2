#include <stdio.h>
#include<stdbool.h>

enum { MAX_NUMBERS = 1000000000 };

int main(void) {

    int n;
    int distinct = 0;
    bool x[MAX_NUMBERS] = {false};


    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        long long input;
        if (scanf("%lld", &input) !=1) {
            fprintf(stderr, "Invalide input\n");
            return 1;
        }
        else {
            if (x[input] == false) {
                x[input] = true;
                distinct++;
            }
        }
    }

    printf("distinct = %d\n", distinct);
}
