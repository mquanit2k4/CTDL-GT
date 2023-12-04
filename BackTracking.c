#include <stdio.h>
#include <stdlib.h>

int tong (int x[], int n)
{
    int s = 0;
    for(int i = 1 ; i <= n ; i++)
        s += x[i];
    return s;
}

void inra(int x[], int n)
{
    for (int i = 1; i <= n ; i++)   
        printf("%d ", x[i]);
    printf("\n");
}

void cogangtim(int h , int m , int x[], int n)
{
    if (h == n+1)
    {
        if (tong(x,n) == 10)
            inra(x,n);
        return;
    }
    if (x[h] != 0 )
        cogangtim(h+1,m,x,n);
    else
	{
    	for (int j = - 9 ; j <= 9 ; j++)
    	{
	    	if(j != 0)
			{
	    		x[h] = j;
	        	cogangtim(h+1,m,x,n);
			}
    	}
    	x[h] = 0;
	}
    
}
int main()
{
    int x[100];
    int m = 0; int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++)
    {
        scanf("%d", &x[i]);
        if (x[i] == 0)
            m++;
    }
    cogangtim(1,m,x,n);
    return 0;
}
//-1 2 -3 3 9
//-1 2 -2 3 8
//-1 2 -1 3 7
//-1 2 1 3 5
//-1 2 2 3 4
//-1 2 3 3 3
//-1 2 4 3 2
//-1 2 5 3 1
//-1 2 7 3 -1
//-1 2 8 3 -2
//-1 2 9 3 -3   
