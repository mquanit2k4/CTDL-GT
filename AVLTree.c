#include <stdio.h>
#include <stdlib.h>

struct node {
    int bal;
    int key;
    struct node *left;
    struct node *right;
};

typedef struct node* AVL;
int getHeight(AVL root)
{
    if (root == NULL)
        return 0;  
    return 1 + max(getHeight(root->left), getHeight(root->right));
}