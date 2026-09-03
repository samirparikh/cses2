// DMOJ: ecna05b

#include <stdio.h>
#include <string.h>

typedef struct node {
    int num_children;
    struct node **children;
    char *name;
    int score;
} node;

node *find_node(node *nodes[], int num_node, char *name)
{
    int i;
    for (i = 0; i < num_node; i++)
        if (strcmp(nodes[i]->name, name) == 0)
            return nodes[i];
    return NULL;
}

int main(void) {

    return 0;
}
