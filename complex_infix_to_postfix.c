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

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int Rank(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return -1;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    else if (ch == '\0' || ch == '(' || ch == ')')
        return 0;
}

int inputPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '^')
        return 6;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 7;
    else if (ch == '(')
        return 9;
    else if (ch == ')')
        return 0;
}

int stackPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/')
        return 4;
    else if (ch == '^')
        return 5;
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 8;
    else if (ch == '(')
        return 0;
    else if (ch == ')')
        return -1;
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
    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));
    int rank = 0;
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        while (inputPrecedence(infix[i]) <= stackPrecedence(Top(st)))
        {
            if (Top(st) == '(')
            {
                char val = pop(st);
            }
            else
            {
                postfix[j] = pop(st);
                rank += Rank(postfix[j]);
                j++;
            }
            if (rank < 1)
            {
                printf("Invalid Equation.\n");
                return '\0';
            }
        }
        if (infix[i] == ')')
            i++;
        else
        {
            push(st, infix[i]);
            i++;
        }
    }
    while (!isEmpty(st))
    {
        if (Top(st) == '(')
        {
            char val = pop(st);
        }
        else
        {
            postfix[j] = pop(st);
            rank += Rank(postfix[j]);
            j++;
        }
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