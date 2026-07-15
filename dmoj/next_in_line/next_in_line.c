// dmoj: Next in line

#include <stdio.h>

int main(void) {

    unsigned short youngest, middle;
    if (scanf("%hu %hu", &youngest, &middle) != 2) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    printf("%hu\n", 2 * middle - youngest);
    return 0;
}
