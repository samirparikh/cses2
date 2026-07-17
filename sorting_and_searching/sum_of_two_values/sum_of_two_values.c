// Sorting and Searching: Sum of Two Values

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 30000

/* Basic data structure will be:

             search for key = 348238
                       │
                       ▼
           hash(348238) % TABLE_SIZE
                       │
                       ▼
                  bucket #8
                       │
                       ▼
      +-------------------------------+
      | 838 → 348238 → 5788 → NULL    |
      +-------------------------------+
                │
                ▼
        Compare actual keys:
        838 == 348238?    No
        348238 == 348238? Yes

*/

/* One node in one linked list:
Node
+------------------+
| key              |
| position         |
| next  -----------+----> another Node
+------------------+
*/
typedef struct Node {
    int     key;                // integer we need
    int     position;           // the order it appeared (1st, 2nd, ...)
    struct  Node *next;         // next node in this bucket
} Node;

// define hash table as an array (buckets) of pointers
// each array element points to head of linked list (or NULL)
Node *table[TABLE_SIZE] = {NULL};

// simple hash function
int hash (int key) {
    return key % TABLE_SIZE;
}

// insert one (key, position) pair into the table
void insert(long long key, int position) {

    int bucket = hash(key);

    // Allocate memory for the new node
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    new_node->key      = key;
    new_node->position = position;

    // insert node at beginning of list
    new_node->next = table[bucket];
    table[bucket]  = new_node;
}

int find_position(long long key) {

    int bucket    = hash(key);

    Node *current = table[bucket];

    while (current != NULL) {
        if (current->key == key) {
            return current->position;
        }

        current = current->next;
    }

    return 0;
}

// free allocated memory
void destroy_table(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = table[i];

        while (current != NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }
}

int main(void) {
    int         array_size;
    long long   target_sum;

    if (scanf("%d %lld", &array_size, &target_sum) != 2) {
        fprintf(stderr, "invalid input");
        return 1;
    }

    long long numbers[array_size];

    for (int i = 0; i < array_size; i++) {
        if (scanf("%lld", &numbers[i]) != 1) {
            fprintf(stderr, "invalid input");
            return 1;
        }

        insert(numbers[i], i + 1);
    }

    int pair_found = 0;
    // assuming we find a pair whose sum is the target:
    // index1 represents the position of the first integer
    // index2 represents the position of the second integer
    int index1 = 0;

    // while loop only needs to check up to the second to last number
    // (array_size - 2) because if it makes up a valid pair, the other number
    // in the pair would have to be the last number in the array (array_size - 1)
    while (index1 < array_size - 1) {
        long long target_number = target_sum - numbers[index1];
        if (target_number > 0) {  // target numbers are greater than zero
            int index2 = find_position(target_number);
            if (index2 && index1 + 1 != index2) {
                printf("%d %d\n", index1 + 1, index2);
                pair_found = 1;
                break;
            }
        }
        index1++;
    }

    if (!pair_found) printf("IMPOSSIBLE\n");

    destroy_table();

    return 0;
}
