#include<stdio.h>
#include<stdlib.h>
int maxN = 100000;
int n, a[100000];

int size()
{
    return n;
}

int empty()
{
    return n == 0;
}
void push(int x)
{
    if (n == maxN)
    {
        printf("Queue is full\n");
        return;
    }
    n++;
    a[n] = x;
}

void pop()
{
    if (n == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 1; i <= n - 1; i++)
        a[i] = a[i + 1];
    n--;
}

void duyet()
{
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int front()
{
    return a[1];
}
int main()
{
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Front\n");
        printf("4. Size\n");
        printf("5. Duyet\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int x;
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
            printf("%d\n", front());
        }
        else if(x == 4)
        {
            printf("%d\n", size());
        }
        else if (x == 5)
        {
            duyet();
        }
        else
        {
            break;
        }
    }
}