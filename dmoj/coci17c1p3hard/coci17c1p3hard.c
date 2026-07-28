// dmoj: coci17c1p3hard

#include <stdio.h>
#include <string.h>

#define MAX_USERS 100000
#define MAX_PASSWORD 10

int main(void) {

    static char users[MAX_USERS][MAX_PASSWORD + 1];
    int num_ops, op, op_type, total, j;
    char password[MAX_PASSWORD + 1];
    int num_users = 0;

    if (scanf("%d", &num_ops) != 1) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }

    for (op = 0; op < num_ops; op++) {
        if (scanf("%d%s", &op_type, password) != 2) {
            fprintf(stderr, "invalid input\n");
            return 1;
        }

        // add new user password to users[]
        if (op_type == 1) {
            strcpy(users[num_users], password);
            num_users++;
        }

        // query user input against all passwords in user[]
        else {
            total = 0;
            for (j = 0; j < num_users; j++)
                if (strstr(users[j], password))
                    total++;
            printf("%d\n", total);
        }
    }

    return 0;
}
