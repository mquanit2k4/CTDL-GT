#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

struct node{
	int data;
	node *next;
};
typedef struct node* Node;

Node makeNode(int x)
{
	Node newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void insertLast(Node &head , int x)
{
	Node tmp = makeNode(x);
	if (head == NULL)
	{
		head = tmp;
		return;
	}
	
	Node i = head;
	while (i->next != NULL)
		i = i->next;
	i->next = tmp;
}
void deleteHead(Node &head)
{
	Node tmp = head;
	head = head->next;
	delete(tmp);
}
Node dSort(Node a, Node b)
{
	Node res = NULL;
	while (a != NULL && b != NULL)
	{
		if (a->data >= b->data)
		{
			insertLast(res,a->data);
			deleteHead(a);	
		}	
		else
		{
			insertLast(res,b->data);
			deleteHead(b);
		}
	}
	while(a != NULL)
	{
		insertLast(res,a->data);
			deleteHead(a);
	}
	while(b != NULL)
	{
		insertLast(res,b->data);
			deleteHead(b);
	}
	return res;
}
void sortIList (Node &a)
{
	for (Node p = a; p->next != NULL ; p = p->next)
	{
		Node min = p;
		for (Node q = p->next; q != NULL; q = q->next)
		{
			if (q->data > min->data)
			{
				min = q;
			}
			int tmp = min->data;
			min->data = p->data;
			p->data = tmp;
		}
	}
}

void sortDList (Node &a)
{
	for (Node p = a; p->next != NULL ; p = p->next)
	{
		Node max = p;
		for (Node q = p->next; q != NULL; q = q->next)
		{
			if (q->data < max->data)
			{
				max = q;
			}
			int tmp = max->data;
			max->data = p->data;
			p->data = tmp;
		}
	}
}

Node iSort(Node a , Node b)
{
	Node res = NULL;
	while (a != NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			insertLast(res,a->data);
			deleteHead(a);	
		}	
		else
		{
			insertLast(res,b->data);
			deleteHead(b);
		}
	}
	while(a != NULL)
	{
		insertLast(res,a->data);
			deleteHead(a);
	}
	while(b != NULL)
	{
		insertLast(res,b->data);
			deleteHead(b);
	}
	return res;
}
void duyet(Node head)
{
	while (head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}
int main()
{
	Node head = NULL , a = NULL , b = NULL;
	int m , n , x , y ;
	string s;
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> x;
		insertLast(a,x);
	}
	cin >> m;
	for (int j = 0 ; j < m; j++)
	{
		cin >> y;
		insertLast(b,y);
	}
	cin >> s;
	if (s == "dSort")
	{
		sortIList(a);
		sortIList(b);
		duyet(dSort(a,b));
	}
	else
	{
		sortDList(a);
		sortDList(b);
		duyet(iSort(a,b));	
	}
	return 0;	
}
