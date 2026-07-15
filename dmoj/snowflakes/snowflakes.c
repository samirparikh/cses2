// dmoj: Snowflakes

#include <stdio.h>
#include <stdlib.h>
#define SNOWFLAKE_SIDES      6
#define SIZE            100000

typedef struct snowflake_node {
    int snowflake[SNOWFLAKE_SIDES];
    struct snowflake_node *next;
} snowflake_node;

int code(int snowflake[]) {
    int sum = 0;
    for (int i = 0; i < SNOWFLAKE_SIDES; i++)
        sum += snowflake[i];
    return sum % SIZE;
}

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

void identify_identical(snowflake_node *snowflakes[]) {
    snowflake_node *node1, *node2;
    
    for (int i = 0; i < SIZE; i++) {
        node1 = snowflakes[i];
        while (node1 != NULL) {
            node2 = node1->next;
            while (node2 != NULL) {
                if (are_identical(node1->snowflake, node2->snowflake)) {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }
    printf("No two snowflakes are alike.\n");
}

int main(void) {

    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow;
    int n, snowflake_code;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        snow = malloc(sizeof(snowflake_node));
        if (snow == NULL) {
            fprintf(stderr, "malloc error\n");
            return 1;
        }
        for (int j = 0; j < SNOWFLAKE_SIDES; j++)
            scanf("%d", &snow->snowflake[j]);
        snowflake_code = code(snow->snowflake);
        snow->next = snowflakes[snowflake_code];
        snowflakes[snowflake_code] = snow;
    }

    identify_identical(snowflakes);

    return 0;
}
