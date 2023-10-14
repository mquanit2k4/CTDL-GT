#include <bits/stdc++.h>
using namespace std;
int a[11];
int k,kt,dem;
void tower (int	n, int x, int y, int z)
{
	if(kt==1)
		return;
	if (n==1)
	{
		a[x]--;
		a[y]++;
		dem++;
		if (k==dem)
		{
			cout<<a[1]<<' '<<a[2]<<' '<<a[3];
			kt=1;
		}
		return;
	}
	tower(n-1,x,z,y);
	tower(1,x,y,z);
	tower(n-1,z,y,x);
}
int main()
{
	int n;
	cin>>n>>k;
	a[1]=n;
	a[2]=0;
	a[3]=0;
	tower(n,1,2,3);
	return 0;
}