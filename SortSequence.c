#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSort(int a[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = a[left + rand() % (right-left)];
	while (i <= j)
	{
		while (a[i] < pivot)
			++i;
		while (a[j] > pivot)
			--j;
		if  (i<=j)
		{
			swap(&a[i], &a[j]);
			++i;
			--j;
		}
	}
	if (left < j)
		quickSort(a, left, j);
	if (right > i)
		quickSort(a, i, right);
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	quickSort(a,0,n-1);
	for(int i = 0 ; i < n ; i++)
		printf("%d ", a[i]);
	return 0;
}
