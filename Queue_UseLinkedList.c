#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
struct node
{
    int data;
    struct node *next;
};

typedef struct node* Node;

Node makeNode(datatype x)
{
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(Node *queue , datatype x)
{
    Node tmp = makeNode(x);
    if (*queue == NULL)
    {
        *queue = tmp;
        return;
    }
    Node p = *queue;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
}

void pop(Node *queue)
{
    if (*queue == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    Node tmp = *queue;
    *queue = (*queue)->next;
    free(tmp);
}

int size(Node queue)
{
    int count = 0;
    Node p = queue;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int empty(Node queue)
{
    return queue == NULL;
}

void duyetQueue(Node queue)
{
    if (queue == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    Node p = queue;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Node queue = NULL;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. Empty\n");
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
            push(&queue, x);
        }
        else if(x == 2)
        {
            pop(&queue);
        }
        else if(x == 3)
        {
            printf("%d\n", size(queue));
        }
        else if(x == 4)
        {
            if(empty(queue))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
        }
        else if(x == 5)
        {
            duyetQueue(queue);
        }
        else if(x == 6)
        {
            break;
        }
    }
}