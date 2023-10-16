#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int n;
int x[10000];
void output ()
{
	rep(i,1,n)
		cout<<x[i];
	cout<<endl;
}
bool check (int v , int k )
{
	return 1;
}
void Try (int k)
{
	rep(v,0,1)
		if(check(v,k))
		{
			x[k]=v;
			if(k==n)
				output();
			else
				Try(k+1);
		}
}
int main()
{
	cin>>n;
	Try(1);
	return 0;	
}
