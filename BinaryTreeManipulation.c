#include <stdio.h>
#include <stdlib.h>

struct _BNode{
	int id;
	struct _BNode* leftChild;
	struct _BNode* rightChild;
};

typedef struct _BNode* BNode;

BNode makeNode(int x)
{
	BNode newNode = (BNode)malloc(sizeof(BNode));
	newNode->id = x;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

void preOrder(BNode r) {
	if(r == NULL) return;
	printf("%d ",r->id);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

void postOrder(BNode r) {
	if(r == NULL) return;
	postOrder(r->leftChild);
	postOrder(r->rightChild);
	printf("%d ",r->id);
}

void inOrder(BNode r) {
	if(r == NULL) return;
	inOrder(r->leftChild);
	printf("%d ",r->id);
	inOrder(r->rightChild);
}

BNode find(BNode r, int x){
	if(r == NULL) return NULL;
	if(r->id == x) return r;
	
	BNode* p = find(r->leftChild,x);
	if(p!=NULL) return p;
	
	return find(r->rightChild,x);
} 

BNode addLeft(int r, int u, int v)
{
	BNode p = find(r,v);
	if (find(r,u) != NULL || p == NULL || p->leftChild != NULL)
		return r;
	BNode tmp = makeNode(u);
	p->leftChild = tmp;
	return r;
}

BNode addRight(int r, int u, int v)
{
	BNode p = find(r,v);
	if (find(r,u) != NULL || p == NULL || p->rightChild != NULL)
		return r;
	BNode tmp = makeNode(u);
	p->rightChild = tmp;
	return r;
}
int main()
{
	BNode r = NULL;
	char choice[20];
	while(1)
	{
		scanf("%s", choice);
		if (strcmp(choice,"*") == 0)
			break;
		else if (strcmp(choice,"MakeRoot") == 0)
		{
			int x;
			scanf("%d", &x);
			r = makeNode(x);
		}
		else if (strcmp(choice,"AddLeft") == 0)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			r = addLeft(r,u,v);
		}
		else if (strcmp(choice,"AddRight") == 0)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			r = addRight(r,u,v);
		}
		else if (strcmp(choice,"InOrder") == 0)
		{
			inOrder(r);
			printf("\n");
		}
		else if (strcmp(choice,"PreOrder") == 0)
		{
			preOrder(r);
			printf("\n");
		}
		else if (strcmp(choice,"PostOrder") == 0)
		{
			postOrder(r);
			printf("\n");
		}	
	}
	return 0;
}