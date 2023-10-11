#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
ll x[1000],n,t;
void output ()
{
	rep(i,1,n)
		cout<<x[i];
	cout<<endl;
}
int check[10000],dem;
void Try (int k)
{
	rep(v,1,t)
		if(check[v]==0)
		{
			x[k]=v;
			if(k==n)
			{
				dem++;
				output();
			}
			else
				Try(k+1);
		}
}
int main()
{
	cin>>t>>n;
	cout<<pow(t,n)<<endl;
	Try(1);
	return 0;	
}
