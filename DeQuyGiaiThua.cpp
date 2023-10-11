#include <bits/stdc++.h>
using namespace std;
long long giaithua (long long1 n)
{
	if (n==1 || n==0)
		return 1;
	return n*giaithua(n-1);
}
int main()
{
	int n;
 	cin>>n;
 	cout<<giaithua(n);
	return 0;
}
