#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insert(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
        *head = newNode;
    else
    {
        struct node *ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}

void deleteNode(struct node **head, int data)
{
    if (*head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct node *temp = *head;
    if (temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    struct node *prev = NULL;
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data %d is not present in the linked list.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
    struct node *head = NULL;

    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);

    display(head);

    deleteNode(&head, 9);
    display(head);

    return 0;
}
