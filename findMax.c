#include <stdio.h>

int max(int a[], int n, int k)
{
	if (k == n) return a[n];
	if (a[k] > max(a, n, k + 1)) return a[k];
	else return max(a, n, k + 1);
}

int main()
{
	int n; int a[1001];
	scanf("%d", &n);
	for (int i = 1 ; i<= n; i ++)
		scanf("%d", &a[i]);
	int r = max(a, n, 1);
	printf("%d", r);
	return 0;
}