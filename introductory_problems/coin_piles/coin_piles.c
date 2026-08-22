// introductory_problems: Coin Piles

#include <stdio.h>

int main(void) {

    long n, left, right;
    if (scanf("%ld", &n) !=1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (long i = 0; i < n; i++) {
        if (scanf("%ld %ld", &left, &right) != 2) {
            fprintf(stderr, "invalid input reading line %ld\n", i + 2);
            return 1;
        } else {
            long anum = (2 * left - right);
            long bnum = (2 * right - left);
            if (anum >= 0 && bnum >= 0 && anum % 3 ==0 && bnum % 3 == 0)
                printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
