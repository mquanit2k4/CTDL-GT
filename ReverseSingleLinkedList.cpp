#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

struct Node{
	int data;
	Node * next;
};

typedef struct Node* node;


node makeNode(int x)
{
	node ptr = new Node;
	ptr->data = x;
	ptr->next = NULL;
	return ptr;
}

void insertHead (node &head , int x)
{
	node tmp = makeNode(x);
	tmp->next = head;
	head = tmp;
}

void duyetDS (node head)
{
	while (head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}

node daoDS (node head)
{
	node tmp = NULL;
	while (head != NULL)
	{
		insertHead(tmp, head->data);
		head = head->next;
	}
	return tmp;
}

node daoDS2 (node head)
{
	if (head == NULL || head->next == NULL)
		return head;
	node p1 = NULL , p2 = head , p3 = NULL;
	while (p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return p1;
}
int main()
{
	node dao, newNode = NULL;
	for (int i = 1 ; i <= 10 ; i++)
		insertHead(newNode, i);
	duyetDS(newNode);
	cout << endl;
	dao = daoDS2(newNode);
	duyetDS(dao);

	return 0;	
}
