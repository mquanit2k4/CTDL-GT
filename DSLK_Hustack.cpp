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
	Node newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void duyetDS (Node head)
{
	while (head != NULL)
	{
		cout << head->data <<' ';
		head = head->next;	
	}	
	cout<<endl;
} 

void insertHead (Node &head, int x)
{
	Node i = head;
	int check = 0;
	while (i != NULL)
	{
		if (i->data == x)
		{
			check = 1; 
			break;
		}
		i = i->next;
	}
	if (check)
		return;
	else
	{
		Node tmp = makeNode(x);
		tmp->next = head;
		head = tmp;
	}
}

void insertLast (Node &head , int x)
{
	Node i = head;
	int check = 0;
	while (i != NULL )
	{
		if (i->data == x)
		{
			check = 1; 
			break;
		}
		i = i->next;
	}
	if (check)
		return;
	else
	{
		Node tmp = makeNode(x);
		if (head == NULL)
		{
			head = tmp;
			return;
		}
		Node i = head; // phai chay bang bien trung gian, neu chay = head sau khi chay xong head se bi thay doi, khi do se mat cac node phia truoc
		while (i->next != NULL)
			i = i->next;
		i->next = tmp;
	}
}

Node reverse (Node head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node p1 = NULL , p2 = head , p3 = NULL;
	while (p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return p1;
}


Node remove (Node head , int x)
{
	Node p = head;
	if (head == NULL)
		return NULL;
	if (head->data == x)
	{
		Node tmp = head;
		head = head->next;
		delete tmp;
		return head;
	}
	
	while (p->next != NULL)
	{
		if (p->next->data == x)
			break;
		p = p->next;
	}
	
	if (p->next != NULL)
	{
		Node q = p->next;
		p->next = q->next;
		delete q;
	}
	return head;
}

void insertBefore (Node &head , int u , int v)
{
	Node i = head;
	while (i != NULL)
	{
		if (i->data == u)
			return;
		i = i->next;
	}
	if (head->data == v)
	{
		insertHead(head, u);
		return;
	}
	Node tmp = makeNode(u);
	Node j = head;
	while (j->next->data != v)
		j = j->next;
	tmp->next = j->next;
	j->next = tmp;
}

void insertAfter (Node &head , int u , int v)
{
	Node i = head;
	while (i != NULL)
	{
		if (i->data == u)
			return;
		i = i->next;
	}
	if (head->data == v)
	{
		insertLast(head, u);
		return;
	}
	Node tmp = makeNode(u);
	Node j = head;
	while (j->data != v)
		j = j->next;
	tmp->next = j->next;
	j->next = tmp;
}
int main()
{
	Node head = NULL;
	int n; cin >> n;
	int x;
	for (int i = 0; i < n ;i++)
	{
		cin >> x;
		insertLast(head,x);
	}
	string s;
	while (cin >> s && s != "#" )
	{
		if (s == "addlast")
		{
		//	cin.ignore();
			int k;
			cin >> k;
			insertLast(head,k);
		}
		else if (s == "addfirst")
		{
			int k;
			cin >> k;
			insertHead(head,k);
		}
		else if (s == "addafter")
		{
			int u , v;
			cin >> u >> v;
			insertAfter(head,u,v);
		}
		else if (s == "addbefore")
		{
			int u , v;
			cin >> u >> v;
			insertBefore(head,u,v);
		}
		else if (s == "remove")
		{
			int k;
			cin >> k;
			head = remove(head,k);
		}
		else if (s == "reverse")
		{
			head = reverse(head);
		}
	}
	duyetDS(head);
	return 0;	
}
