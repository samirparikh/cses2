// dmoj: Special Day

#include <stdio.h>

int main(void) {

    int month, day;
    if (scanf("%d %d", &month, &day) != 2) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    if (month == 1 || (month == 2 && day < 18)) {
        printf("Before");
    }

    else if ((month == 2 && day > 18) || month > 2) {
        printf("After");
    }

    else {
        printf("Special");
    }
    
    return 0;
}
