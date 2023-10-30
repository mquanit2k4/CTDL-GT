#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
// Danh sách liên kết (Linked List)

struct Node{
	int data;
	Node *next;
};

typedef struct Node* node;

// Cấp phát động một node mới với dữ liệu là số nguyên x
node makeNote (int x){
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL; // nullptr
	return tmp;
}

// Kiểm tra rỗng của 1 node
bool empty (node a){
	return a == NULL;
}

// Truy cập size của 1 Node
int Size (node a){
	int cnt = 0;
	while (a != NULL){
		cnt++;
		a = a->next; // Gán địa chỉ của a cho node tiếp theo cho node hiện tại
		// Cho node hiện tại nhảy sang node tiếp theo
	}
	return cnt;
}

// Thêm một phần tử vào đầu linked list
void insertFirst (node &a, int x)
{
	node tmp = makeNote(x);
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		tmp->next = a;
		a = tmp;
	}
}

// Thêm một phần tử vào cuối linked list
void insertLast (node &a, int x)
{
	node tmp = makeNote(x);
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		node p = a; // Không được dùng a để duyệt vì khi duyệt while nó sẽ thay đổi giá trị của linked list
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = tmp;
	}
}

// Thêm một phần tử vào giữa
void insertMiddle (node &a, int x , int pos)
{
	int n = Size(a);
	if (pos <= 0 || pos > n+1 )
		cout << "Vị trí chèn không hợp lệ! \n";
	if (pos == 1)
	{
		insertFirst(a, x);
		return;
	}
	if (pos == n+1 )
	{
		insertLast(a,x);
		return;
	}
	node p = a;
	node tmp = makeNote(x);
	for (int i = 1; i< pos-1 ; i++)
	{
		p = p->next;	
	}
	tmp->next = p->next;
	p->next = tmp;	
}

// Xóa phần tử đầu
void deleteFirst (node &a)
{
	if (a == NULL)
		return;
	a = a->next;
}

// Xóa phần tử cuối
void deleteLast (node &a)
{
	node truoc = NULL, sau = a;
	if (a == NULL)
		return;
	while (sau->next != NULL)
	{
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL)
	{
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}

// Xóa phần tử ở giữa
void deleteMiddle (node &a, int pos)
{
	if (pos <=0 || pos > Size(a))
		return;
	node truoc = NULL, sau = a;
	for (int i=1; i< pos ; i++)
	{
		truoc = sau;
		sau = sau->next;
	}
	if ( truoc == NULL)
		a = a->next;
	else
		truoc->next = sau->next;		
}

// Duyệt qua tất cả các node
void in (node a)
{
	cout << "-------------------\n";
	while (a != NULL)
	{
		cout << a->data << ' ';
		a = a->next;
	}
	cout<<endl;
	cout << "-------------------\n";
}

// Sắp xếp DSLK theo thứ tự tăng dần
void sortList (node &a)
{
	for (node p = a, p->next != NULL ; p = p->next)
	{
		node min = p;
		for (node q = p->next; q != NULL; q = q->next)
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
int main()
{
	node head = NULL; // Khởi tạo node đầu tiên trong linked list
	while (1){
		cout << "----------MENU---------\n";
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao giua danh sach\n";
		cout << "4. Xoa phan tu dau\n";
		cout << "5. Xoa phan tu cuoi\n";
		cout <<	"6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lien ket\n";
		cout << "8. Sap xep DSLK theo thu tu tang dan\n";
		cout << "0. Thoat \n"
		cout << "-----------------------\n";
		cout << "Nhap lua chon :";
		int lc;
		cin>>lc;
		if (lc == 1)
		{
			int x;
			cout << "Nhap gia tri can chen : ";
			cin >> x;
			insertFirst(head, x);
		}
		else if (lc == 2)
		{
			int x;
			cout << "Nhap gia tri can chen : ";
			cin >> x;
			insertLast(head, x);
		}
		else if (lc == 3)
		{
			int x,pos;
			cout << "Nhap gia tri can chen : ";
			cin >> x;
			cout << "Nhap vi tri can chen : ";
			cin >> pos;
			insertMiddle(head, x , pos);
		}
		else if (lc == 4)
		{
			deleteFirst(head);
		}
		else if (lc == 5)
		{
			deleteLast(head);
		}
		else if (lc == 6)
		{
			int pos;
			cout << "Nhap vi tri can xoa :";
			cin >> pos;
			deleteMiddle(head, pos);
		}
		else if (lc == 7)
		{
			in(head);
		}
		else if (lc == 0)
			break;
		else if (lc == 8)
		{
			
		}
	}
	return 0;	
}
