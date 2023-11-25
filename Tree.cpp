#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

typedef struct node* Node;
Node createNode(int data)
{
    Node newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert on the left of the node
Node insertLeft(Node root, int data)
{
    root->left = createNode(data);
    return root->left;
}

// Insert on the right of the node
Node insertRight(Node root, int data)
{
    root->right = createNode(data);
    return root->right;
}

// Inorder traversal
// Thăm theo thứ tự: trái, gốc, phải
void inorder(Node root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Preorder traversal
// Thăm theo thứ tự: gốc, trái, phải
void preorder(Node root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
// Thăm theo thứ tự: trái, phải, gốc
void postorder(Node root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);
    inorder(root);
    return 0;
}