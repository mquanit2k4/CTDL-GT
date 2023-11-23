#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

//struct _Polynom{
//	int coeff;
//	int pow;
//	_Polynom *next = NULL;
//};
//
//typedef struct _Polynom* Polynom;
//
//Polynom makeNode(int co , int po)
//{
//	Polynom newNode = new _Polynom;
//	newNode->coeff = co;
//	newNode->pow = po;
//	newNode->next = NULL;
//	return newNode;
//}
//
//void printList (Polynom head)
//{
//	Polynom i = head;
//	while ( i != NULL)
//	{
//		cout << i->coeff << " ";
//		i = i->next;
//	}
//	cout<<endl;
//}
//
//
//void insertLast(Polynom &head, int co , int po)
//{
//	Polynom tmp = makeNode(co, po);
//	if (head == NULL)
//	{
//		head = tmp;
//		return;
//	}
//	Polynom i = head;
//	while (i->next != NULL)
//		i = i->next;
//	i->next = tmp;
//}
//
//Polynom SumTwoPol(Polynom px , Polynom qx)
//{
//	if (px == NULL && qx == NULL)
//		return NULL;
//	Polynom res = NULL;
//	Polynom p = px , q = qx , node = res , ptr = NULL;
//	while (p != NULL && q != NULL)
//	{
//		node = makeNode(0,0);
//		if (p->pow > q->pow)
//		{
//			node->coeff = q->coeff;
//			node->pow = q->pow;
//			q = q->next;
//		}
//		else
//		{
//			if (p->pow < q->pow)
//			{
//				node->coeff = p->coeff;
//				node->pow = p->pow;
//				p = p->next;	
//			}
//			else
//			{
//				if (q->pow == 0)
//				{
//					node->coeff = 0;
//					node->pow = q->pow;
//				}
//				else
//				{
//					delete node;
//					node = NULL;
//				}
//			}
//			p = p->next;
//			q = q->next;
//		}
//		
//		if (node != NULL)
//		{
//			if (ptr != NULL)
//				ptr->next = node;
//			ptr = node;
//			if (res == NULL)
//				res = node;
//		}
//	}
//	
//	while (p != NULL)
//	{
//		if (p->coeff == 0)
//			p = p->next;
//		else
//		{
//			node = makeNode(0,0);
//			ptr->next = node;
//			node->coeff = p->coeff;
//			node->pow = p->pow;
//			p = p->next;
//			ptr = node;
//		}			
//	}
//	
//	while (q != NULL)
//	{
//		if (q->coeff == 0)
//			q = q->next;
//		else
//		{
//			node = makeNode(0,0);
//			ptr->next = node;
//			node->coeff = q->coeff;
//			node->pow = q->pow;
//			q = q->next;
//			ptr = node;
//		}			
//	}
//	if(res == NULL)
//		res = makeNode(0,0);
//	return res;
//}
// 
//int main()
//{
//	Polynom px = NULL, qx = NULL ,res = NULL;
//	int n , m;
//	cin >> n;
//	for (int i = 0 ; i < n ; i++)
//	{
//		int x; cin >> x;
//		insertLast(px , x , i);
//	}
//	cin >> m;
//	for (int i = 0 ; i < m ; i++)
//	{
//		int y; cin >> y;
//		insertLast(qx , y , i);
//	}
//	string s;
//	cin >> s;
//	if (s == "plus")
//	{
//		res = SumTwoPol(px , qx);
//		printList(res);
//	}
//	return 0;	
//}


struct node{
	int coeff;
	node *next;
};

typedef struct node* Node;
Node makeNode(int x)
{
	Node newNode = new node;
	newNode->coeff = x;
	newNode->next = NULL;
	return newNode; 
}

void insertLast(Node &head, int x)
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

void deleteHead (Node &head)
{
	if (head == NULL)
		return;
	Node tmp = head;
	head = head->next;
	delete tmp;
}

Node SumTwoPol(Node fx , Node gx)
{
	Node i = fx , j = gx, res = NULL , tmp = NULL;
	while (i != NULL && j != NULL)
	{
		int ans = 0;
		ans = i->coeff + j->coeff;
		insertLast(res, ans);
		deleteHead(i);
		deleteHead(j);

	}
	while (i != NULL)
	{
		insertLast(res, i->coeff);
		deleteHead(i);
	}
	while (j != NULL)
	{
		insertLast(res, j->coeff);
		deleteHead(j);
	}
	return res;
}

Node MinusTwoPol(Node fx, Node gx)
{
	Node i = fx , j = gx, res = NULL , tmp = NULL;
	while (i != NULL && j != NULL)
	{
		int ans = 0;
		ans = i->coeff - j->coeff;
		insertLast(res, ans);
		deleteHead(i);
		deleteHead(j);
	}
	while (i != NULL)
	{
		insertLast(res, i->coeff);
		deleteHead(i);
	}
	while (j != NULL)
	{
		insertLast(res, -(j->coeff));
		deleteHead(j);
	}
	return res;
}
void duyet(Node head)
{
	Node i = head;
	while (i != NULL)
	{
		cout << i->coeff << ' ';
		i = i->next;
	}
}

int count(Node head)
{
	int dem = 0;
	while(head != NULL)
	{
		if (head->coeff != 0)
			dem++;
		head = head->next;
	}
	return dem;
}

bool check (Node head)
{
	while (head != NULL)
	{
		if (head->coeff != 0)	
			return 0;
		head = head->next;
	}
	return 1;
}
int main()
{
	Node fx = NULL , gx = NULL , res = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n ; i++)
	{
		int x;
		cin >> x;
		insertLast(fx,x);
	}
	int m;
	cin >> m;
	for (int j = 0; j < m ; j++)
	{
		int y;
		cin >> y;
		insertLast(gx,y);
	}
	string s;
	cin >> s;
	if (s == "plus")
	{	
		res = SumTwoPol(fx,gx);
		if (check(res))
		{
			cout<<"1 0";
			return 0;
		}
		cout << count(res) << ' ';
		duyet(res);
	}
	else
	{
		res = MinusTwoPol(fx,gx);
		if (check(res))
		{
			cout<<"1 0";
			return 0;
		}
		cout << count(res) << ' ';
		duyet(res);
	}
	return 0;
}