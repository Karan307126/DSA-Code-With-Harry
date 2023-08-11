/*
    Problem stetment:-> Given linked list andd K, print the last nodes in reverse order.
            example :  1 -> 2 -> 3 -> 4 -> 5 -> 6 , K = 3
            output : 6  5  4
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insertAtTail(struct node *head, int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->prev = ptr;
    new->next = NULL;
    return head;
}

void revDisplay(struct node *ptr, int k)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->prev = NULL;
    head->next = NULL;
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);
    head = insertAtTail(head, 6);
    revDisplay(head, 3);
    return 0;
}