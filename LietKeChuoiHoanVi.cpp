#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
ll x[1000],n;
ll gt (ll n)
{
	if (n==1 || n==0)
		return 1;
	return n*gt(n-1);
}
void output ()
{
	rep(i,1,n)
		cout<<x[i];
	cout<<endl;
}
int check[10000],dem;
void Try (int k)
{
	rep(v,1,n)
		if(check[v]==0)
		{
			x[k]=v;
			check[v]=1;
			if(k==n)
			{
				dem++;
				output();
			}
			else
				Try(k+1);
			check[v]=0;
		}
}
int main()
{
	cin>>n;
	cout<<gt(n)<<endl;
	Try(1);
	return 0;	
}
