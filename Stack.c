#include<stdio.h>
#include<stdlib.h>
// stack using linked list
struct node
{
    int data;
    struct node *next;
};
typedef struct node* Node;

struct stack
{
    Node top;
};
typedef struct stack* Stack;

Node makeNode(int x) // create a new node with data x
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Stack makeStack() // create an empty stack
{
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->top = NULL;
    return s;
}

void push(Stack s, int x) // push x to the top of the stack
{
    Node temp = makeNode(x);
    if(s->top == NULL)
    {
        s->top = temp;
        return;
    }
    temp->next = s->top;
    s->top = temp;
}

int pop(Stack s) // pop the top element of the stack
{
    if(s == NULL || s->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    Node temp = s->top; // 
    s->top = s->top->next;
    int x = temp->data;
    free(temp);
    return x;
}

void duyetStack(Stack s)
{
    if(s == NULL || s->top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node temp = s->top;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int size(Stack s)
{
    if(s == NULL || s->top == NULL)
    {
        return 0;
    }
    int count = 0;
    Node temp = s->top;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    Stack s = makeStack();
    int x;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. Duyet\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int x;
        scanf("%d", &x);
        if(x == 1)
        {
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            push(s, x);
        }
        else if(x == 2)
        {
            printf("Pop: %d\n", pop(s));
        }
        else if(x == 3)
        {
            printf("Size: %d\n", size(s));
        }
        else if(x == 4)
        {
            duyetStack(s);
        }
        else if(x == 5)
        {
            break;
        }
    }
    return 0;
}