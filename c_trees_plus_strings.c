#include <stdio.h>

#define MAX_CHILDREN 5

typedef struct node {
    char *data;
    struct node *children[MAX_CHILDREN];
    int numChildren;
} Node;

/*
      0
     / \  \
    1   2  4
       /
      3

*/

void Tree_Print(Node *root)
{
    Node *stack[10];
    int stackVal = 0;
    stack[stackVal++] = root;
    int count = 7;

    while(stackVal && --count)
    {
        Node *n = stack[--stackVal];
        printf("Processing node %s\n", n->data);
        for (int child = 0; child < n->numChildren; ++child)
        {
            printf("Adding child %s\n", n->children[child]->data);
            stack[stackVal++] = n->children[child];
        }
    }
}

int main()
{
    Node three = {"3", {NULL}, 0};
    Node four = {"4", {NULL}, 0};
    Node two = {"2", {&three}, 1};
    Node one = {"1", {NULL}, 0};
    Node zero = {"0", {&one, &two, &four}, 3};
    
    Tree_Print(&zero);
}