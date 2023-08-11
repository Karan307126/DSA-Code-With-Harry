#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};
struct node *top = NULL;

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

void push(char val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    struct node *p = top;
    if (p == NULL)
    {
        ptr->next = NULL;
        top = ptr;
        return;
    }
    ptr->next = top;
    top = ptr;
}

int pop()
{
    struct node *ptr = top;
    if (ptr == NULL)
    {
        return 0;
    }
    top = top->next;
    free(ptr);
    return 1;
}

int main()
{
    char arr[30];
    printf("Enter your equation : ");
    scanf("%s", arr);
    for (int i = 0; i < sizeof(arr); i++)
    {
        if (arr[i] == '(')
        {
            push(arr[i]);
        }
        if (arr[i] == ')')
        {
            if (isEmpty())
            {
                printf("Parenthesis is not matching.");
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    if (isEmpty())
    {
        printf("Parenthesis is matching.");
    }
    else
    {
        printf("Parenthesis is not matching.");
    }
    return 0;
}