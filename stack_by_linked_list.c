#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *top, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    struct node *p = top;
    if (p == NULL)
    {
        ptr->next = NULL;
        top = ptr;
        return top;
    }
    ptr->next = top;
    return ptr;
}

struct node *pop(struct node *top)
{
    struct node *ptr = top;
    if (ptr == NULL)
    {
        printf("The stack is Underflow.\n");
        return top;
    }
    printf("The poped value is : %d\n", top->data);
    top = top->next;
    free(ptr);
    return top;
}

int peek(struct node *top, int index)
{
    struct node *ptr = top;
    if (ptr == NULL)
    {
        printf("The index is not found because stack is underflow.");
    }
    for (int i = 1; (i < index && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("The index is not found because stack is underflow.");
    }
    return ptr->data;
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *top = NULL;
    top = push(top, 54);
    top = push(top, 45);
    top = push(top, 87);
    top = push(top, 21);
    top = push(top, 43);
    top = push(top, 21);
    display(top);
    top = pop(top);
    display(top);
    int index = 3;
    printf("The value of index %d is : %d", index, peek(top, index));
    return 0;
}