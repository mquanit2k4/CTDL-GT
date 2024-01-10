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

AVL rightRotate(AVL root)
{
    AVL newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    
    root->bal = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->bal = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

AVL leftRotate(AVL root)
{
    AVL newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    
    root->bal = 1 + max(getHeight(root->left), getHeight(root->right));
    newRoot->bal = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}