// Write a program to implement following operations on the circular linked list.
// (a) Insert a node at the end of the linked list.
// (b) Insert a node before specified position.
// (c) Delete a first node of the linked list.
// (d) Delete a node after specified position.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertionAtEnd(struct node *head, int value)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    if (head == NULL)
    {
        head = new;
        new->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new->next = head;
        temp->next = new;
    }
    return head;
}

struct node *insertionBeforeValue(struct node *head, int value, int key)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    if (head == NULL)
    {
        head = new;
        new->next = head;
    }
    else if (head->data == key)
    {
        struct node *temp = head;
        new->next = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        head = new;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head && temp->next->data != key)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            printf("This value is not available in linked list.\n");
        }
        else if (temp->next->data == key)
        {
            new->next = temp->next;
            temp->next = new;
        }
    }
    return head;
}

struct node *deleteFirstNode(struct node *head)
{
    if (head == NULL)
    {
        printf("THIS LINKED LIST IS EMPTY.\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    head = insertionAtEnd(head, 54);
    head = insertionAtEnd(head, 65);
    head = insertionAtEnd(head, 75);
    head = insertionAtEnd(head, 34);
    head = insertionBeforeValue(head, 12, 90);
    display(head);
    head = deleteFirstNode(head);
    display(head);
    free(head);
    return 0;
}