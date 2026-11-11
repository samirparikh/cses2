#include <stdio.h>
// #include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

/*
void traverse_list(Node *cur) {
    while (cur != NULL) {
        printf("%d\n", cur->value); // print value of current node
        Node *next = cur->next;     // get the next node
        cur = next;                 // set current node to next node
    }
}

bool get_number(int *number) {
    printf("Enter a number (Ctrl-D to end): ");
    int result = scanf("%d", number);

    if (result == EOF) return false;

    if (result != 1) {
        fprintf(stderr, "invalid input\n");
        exit(EXIT_FAILURE);
    }
    return true;
}
*/

int main(void) {
    // int number;
    int n;

    if (scanf("%d", &n) !=1) {
        fprintf(stderr, "invalid input\n");
        return EXIT_FAILURE;
    }

    // Start with an empty list
    Node *head = NULL;
    Node *tail = NULL;

    // while (get_number(&number)) {
    for (int number = 1; number <= n; number++) {
        Node *new_node = malloc(sizeof(*new_node));
        if (new_node == NULL) {
            fprintf(stderr, "memory allocation error\n");

            // Clean up already allocated memory to prevent leaks
            while (head != NULL) {
                Node *temp = head;
                head = head->next;
                free(temp);
            }

            return EXIT_FAILURE;
        }

        new_node->value = number;
        new_node->next = NULL;

        // Insertion logic
        if (head == NULL) {         // if no nodes exist, ...
            head = new_node;        // ...first node becomes head
        } else {
            tail->next = new_node;  // ...otherwise link previous tail to new node
        }
        tail = new_node;            // update tail to new node
    }


    printf("\ntraversing list...\n");
    // traverse_list(head);

    // printf("and again\n");
    Node *cur = head;
    while (cur != NULL) {
        printf("%d\n", cur->value); // print value of current node
        Node *next = cur->next;     // get the next node
        free(cur);                  // free the current node
        cur = next;                 // set current node to next node
    }

    return EXIT_SUCCESS;
}
