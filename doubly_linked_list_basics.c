#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insertAtTail(struct node *head)
{
    int val;
    printf("Enter the value you have insert : ");
    scanf("%d", &val);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    struct node *ptr = head;
    if (ptr == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return head;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->prev = ptr;
    new->next = NULL;
    return head;
}

struct node *insertAtHead(struct node *head)
{
    int val;
    printf("Enter the value you have insert : ");
    scanf("%d", &val);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    if (head == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return head;
    }
    new->prev = NULL;
    new->next = head;
    head->prev = new;
    return new;
}

struct node *insertAfterValue(struct node *head)
{
    int value, key;
    printf("Enter which value after you have insert a value : ");
    scanf("%d", &key);
    printf("Enter the value you have insert : ");
    scanf("%d", &value);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    struct node *ptr = head;
    if (ptr == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return head;
    }
    while (ptr->data != key)
    {
        ptr = ptr->next;
    }
    ptr->next->prev = new;
    new->prev = ptr;
    new->next = ptr->next;
    ptr->next = new;
    return head;
}

struct node *deletionLast(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("DOUBLY LINKED LIST IS EMPTY.\n");
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return head;
}

struct node *deletionBeforeValue(struct node *head)
{
    int value;
    printf("Enter which value before you have delete a value : ");
    scanf("%d", &value);
    struct node *ptr = head->next;
    if (head == NULL)
    {
        printf("Doubly linked list is empty.");
    }
    else if (head->data == value)
    {
        printf("NO NODE TO DELETE BEFORE THE FIRST NODE IN DOUBLY LINKED LIST.\n");
    }
    else
    {
        while (ptr->next->data != value && ptr->next != NULL && ptr->data != value)
        {
            ptr = ptr->next;
        }
        if (ptr->next->data == value)
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
        else if (ptr->data == value)
        {
            head = ptr;
            free(ptr->prev);
            ptr->prev = NULL;
        }
        else
        {
            printf("\n\nThe value %d is not in this  doubly linked list.\n", value);
        }
    }
    return head;
}

void display(struct node *ptr)
{
    printf("NULL <=> ");
    while (ptr != NULL)
    {
        printf("%d <=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head;
    head = NULL;
    while (1)
    {
        printf("\n********** DOUBLY LINKED LIST MANU **********\n\n");
        printf("1. Insertion at tail.\n");
        printf("2. Insertion at head.\n");
        printf("3. Insertion between any index.\n");
        printf("4. Deletion at last.\n");
        printf("5. Deletion before value.\n");
        printf("6. Display the linked list.\n");
        printf("7. Exit.\n");
        int i;
        printf("Enter your choice : ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            head = insertAtTail(head);
            display(head);
            continue;
        case 2:
            head = insertAtHead(head);
            display(head);
            continue;
        case 3:
            head = insertAfterValue(head);
            display(head);
            continue;
        case 4:
            head = deletionLast(head);
            display(head);
            continue;
        case 5:
            head = deletionBeforeValue(head);
            display(head);
            continue;
        case 6:
            display(head);
            continue;
        case 7:
            return 0;
        default:
            printf("PLESE ENTER VALID INPUT.");
            break;
        }
    }
    return 0;
}