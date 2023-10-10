#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int n,x[10000];
void output()
{
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			if(x[i]==j)	
				cout<<1<<' ';
			else
				cout<<0<<' ';
		}
		cout<<endl;
	}
}

int check (int v, int k)
{
	// Kiểm tra xem v có thể gán được cho x[k] không?
	rep(j,1,k-1)
		if(x[j]==v || (abs(x[j]-v) == abs(j-k))	)
			return 0;
	return 1;
}
void putQueen (int k)
{
	rep(i,1,n)
		if(check(i,k))
		{
			x[k]=i;
			if(k==n)
				output();
			else
				putQueen(k+1);
		}
}
int main()
{
	cin>>n;
	putQueen(1);
	return 0;	
}
