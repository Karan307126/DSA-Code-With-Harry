#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *ptr, char x)
{
    if (ptr->top == ptr->size - 1)
        return;
    ptr->top++;
    ptr->arr[ptr->top] = x;
}

char pop(struct stack *ptr)
{
    if (ptr->top == -1)
        return -1;
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int Rank(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return -1;
    else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        return 1;
    else if (ch == '\0')
        return 0;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        return 3;
    else if (ch == '\0')
        return 0;
}

int Top(struct stack *ptr)
{
    if (ptr->top == -1)
        return -1;
    return ptr->arr[ptr->top];
}

char *infixToPostfix(char *infix)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 50;
    st->top = -1;
    st->arr = (char *)malloc(sizeof(char) * st->size);
    push(st, '\0');
    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));
    int rank = 0;
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        while (precedence(infix[i]) <= precedence(Top(st)))
        {
            postfix[j] = pop(st);
            rank = rank + Rank(postfix[j]);
            j++;
            if (rank < 1)
            {
                printf("Invalid Equation.\n");
                return '\0';
            }
        }
        push(st, infix[i]);
        i++;
    }
    while (Top(st) != '\0')
    {
        postfix[j] = pop(st);
        rank = rank + Rank(postfix[j]);
        j++;
        if (rank < 1)
        {
            printf("Invalid Equation.\n");
            return '\0';
        }
    }
    if (rank == 1)
        printf("Valid Equation.\n");
    else
    {
        printf("Invalid Equation.\n");
        return '\0';
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char arr[30];
    gets(arr);
    char *infix = arr;
    printf("The postfix expresion is : %s", infixToPostfix(infix));
    return 0;
}