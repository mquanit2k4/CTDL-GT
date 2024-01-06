#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int key;
	struct node* leftChild;
	struct node* rightChild;	
};

typedef struct node* Node;

Node makeNode (int x)
{
	Node p = (Node) malloc(sizeof(Node));
	p->key = x;
	p->leftChild = NULL;
	p->rightChild = NULL;
	return p;
}

void preOrder(Node r){
	if(r==NULL) return;
	printf("%d ",r->key);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

void insert_bst(Node r, int v){
	if(r->key == v)
		return;
	if(r->key > v) {
		if(r->leftChild != NULL) insert_bst(r->leftChild,v);
		else r->leftChild = makeNode(v); //dk dung
	}
	else{
		if(r->rightChild != NULL) insert_bst(r->rightChild,v);
		else r->rightChild = makeNode(v); //dk dung
	}
}

int main()
{
	Node BST = NULL;
	char choice[21];
//	int t;
//	scanf("%s %d", choice, &t);
//	BST = makeNode(t);
	while(scanf("%s", choice) != EOF && strcmp(choice, "#") != 0)
    {
    	if (strcmp(choice,"insert") == 0)
    	{
    		int x;
    		scanf("%d", &x);
    		insert_bst(BST,x);
		}
	}
	preOrder(BST);
	return 0;
}