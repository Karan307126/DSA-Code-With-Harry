#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void push(struct stack *ptr, int x)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack is Overflow.\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = x;
}

int peek(struct stack *ptr, int position)
{
    if (ptr->top < 0)
    {
        printf("Invalid position.");
        return -1;
    }
    return ptr->arr[ptr->top - position + 1];
}

int pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is Underflow.\n");
        return -1;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

void change(struct stack *ptr, int value, int position)
{
    if (ptr->top < 0)
    {
        printf("Invalid position.");
        return;
    }
    ptr->arr[ptr->top - position + 1] = value;
}

void interchange(struct stack *ptr, int pos1, int pos2)
{
    if (ptr->top < 0)
    {
        printf("Invalid position.");
        return;
    }
    int temp = ptr->arr[ptr->top - pos1 + 1];
    ptr->arr[ptr->top - pos1 + 1] = ptr->arr[ptr->top - pos2 + 1];
    ptr->arr[ptr->top - pos2 + 1] = temp;
}

void display(struct stack *ptr)
{
    for (int i = ptr->top; i > -1; i--)
    {
        printf("%d  ", ptr->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct stack *st;
    st->size = 10;
    st->top = -1;
    st->arr = (int *)calloc(st->size, sizeof(int));
    push(st, 87);
    push(st, 54);
    push(st, 61);
    push(st, 98);
    push(st, 21);
    push(st, 76);
    push(st, 13);
    display(st);
    int position;
    printf("Enter position you have peek : ");
    scanf("%d", &position);
    printf("The value before the change at index %d is %d.\n", position, peek(st, position));
    change(st, 9, position);
    printf("The value after the change at index %d is %d.\n", position, peek(st, position));
    int pos1, pos2;
    printf("Enter the positions you have interchange : ");
    scanf("%d %d", &pos1, &pos2);
    interchange(st, pos1, pos2);
    display(st);
    printf("The poped value is %d.\n", pop(st));
    printf("The poped value is %d.\n", pop(st));
    display(st);
    return 0;
}