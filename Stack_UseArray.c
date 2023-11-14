#include <stdio.h>
#include <stdlib.h>
int n , st[10001];
void push(int x)
{
	n++;
    st[n] = x;
}

void pop()
{
    if(n == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    n--;
}

int top()
{
    if(n == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return st[n];
}

int size()
{
    return n;
}

void duyet(int n)
{
    int i;
    for(i = n ; i >=1 ; i--)
        printf("%d ",st[i]);
    printf("\n");
}
int main()
{
    int x;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Size\n");
        printf("5. Duyet\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);
        if(x == 1)
        {
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            push(x);
        }
        else if(x == 2)
        {
            pop();
        }
        else if(x == 3)
        {
            printf("Top: %d\n", top());
        }
        else if(x == 4)
        {
            printf("Size: %d\n", size());
        }
        else if( x == 5)
        	duyet(n);
        else
        {
            break;
        }
    }
    return 0;
}
