#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int main(void) {
    int n;

    if (scanf("%d", &n) !=1) {
        fprintf(stderr, "invalid input\n");
        return EXIT_FAILURE;
    }

    // Start with an empty list
    Node *head = NULL;
    Node *tail = NULL;

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

    tail->next = head;
    Node *current = head;
    Node *next_node;

    while (current != NULL) {

        // current represents the current node
        // let's find the next node
        next_node = current->next;
        // print the value in the next node
        printf("%d ", next_node->value);
        // check to see if only one node remains (it points to itself)
        if (next_node == current) break;
        // point the current node to whatever the next node points to
        current->next = next_node->next;
        // free the next_node now
        free(next_node);
        // advance the current node pointer
        current = current->next;

    }

    return EXIT_SUCCESS;
}
