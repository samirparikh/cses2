// dmoj: Snowflakes

#include <stdio.h>
#define SNOWFLAKE_SIDES      6
#define SIZE            100000

// void identify_identical(int values[], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (values[i] == values[j]) {
//                 printf("twin integers (%d) found\n", values[i]);
//                 return;
//             }
//         }
//     }
//     printf("no two integers are the same\n");
//     return;
// }

int identical_right(int snow1[], int snow2[], int start) {
    for (int offset = 0; offset < SNOWFLAKE_SIDES; offset++) {
        if (snow1[offset] != snow2[(start + offset) % SNOWFLAKE_SIDES])
            return 0;
    }
    return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
    int snow2_index;
    for (int offset = 0; offset < SNOWFLAKE_SIDES; offset++) {
        snow2_index = start - offset;
        if (snow2_index < 0)
            snow2_index = snow2_index + SNOWFLAKE_SIDES;
        if (snow1[offset] != snow2[snow2_index])
            return 0;
    }
    return 1;
}

int are_identical(int snow1[], int snow2[]) {
    for (int start = 0; start < SNOWFLAKE_SIDES; start++) {
        if (identical_right(snow1, snow2, start)) return 1;
        if (identical_left(snow1, snow2, start)) return 1;
    }
    return 0;
}


void identify_identical(int snowflakes[][SNOWFLAKE_SIDES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (are_identical(snowflakes[i], snowflakes[j])) {
                printf("Twin snowflakes found.\n");
                return;
            }
            // if (values[i] == values[j]) {
            //     printf("twin integers (%d) found\n", values[i]);
            //     return;
            // }
        }
    }
    printf("No two snowflakes are alike.\n");
    return;
}
int main(void) {

    //int numbers[SNOWFLAKE_SIDES];
    // int snow1[SNOWFLAKE_SIDES], snow2[SNOWFLAKE_SIDES];
    // for (int i = 0; i < SNOWFLAKE_SIDES; i++) {
    //     if (scanf("%d", &snow1[i]) != 1) {
    //         fprintf(stderr, "invalid input\n");
    //         return 1;
    //     }
    // }

    // for (int i = 0; i < SNOWFLAKE_SIDES; i++) {
    //     if (scanf("%d", &snow2[i]) != 1) {
    //         fprintf(stderr, "invalid input\n");
    //         return 1;
    //     }
    // }

    //identify_identical(numbers, SNOWFLAKE_SIDES);
    // printf("snowflakes are ");
    // if (are_identical(snow1, snow2)) printf("the same\n");
    // else printf("different\n");

    static int snowflakes[SIZE][6];
    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < SNOWFLAKE_SIDES; j++)
            if (scanf("%d", &snowflakes[i][j]) != 1) {
                fprintf(stderr, "invalid input\n");
                return 1;
            }
    identify_identical(snowflakes, n);

    return 0;
}
