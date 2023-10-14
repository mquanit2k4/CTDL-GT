#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
ll m[10000][10000];
ll C(int k, int n)
{
	if (k==0 || k==n )
		m[k][n]=1;
	else if (m[k][n]==0)
	// Nếu m[k][n]=0 nghĩa là chưa lưu phần tử kCn thì ta mới bắt đầu gán cho m[k][n]
		m[k][n]=C(k-1,n-1)+C(k,n-1);
	// Lưu ý phải gán m[k][n]=C(k-1,n-1)+C(k,n-1) chứ không phải là m[k][n]=m[k-1][n-1]+m[k][n-1]
	return m[k][n];
}
int main()
{
	int k,n;
	cin>>k>>n;
	cout<<C(k,n);
	return 0;	
}
