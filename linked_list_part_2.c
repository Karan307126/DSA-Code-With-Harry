#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertAtTail(struct node *head)
{
    int val;
    printf("Enter value you have insert : ");
    scanf("%d", &val);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    struct node *p = head;
    if (p == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        return head;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *insertAtHead(struct node *head)
{
    int val;
    printf("Enter value you have insert : ");
    scanf("%d", &val);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    struct node *p = head;
    if (p == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        return head;
    }
    ptr->next = head;
    return ptr;
}

struct node *insertAtbetween(struct node *head, int index)
{
    int val;
    printf("Enter value you have insert : ");
    scanf("%d", &val);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    struct node *p = head;
    if (p == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        return head;
    }
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *deletionFirst(struct node *head)
{
    struct node *p = head;
    if (p == NULL)
    {
        printf("Linked list is empty.\n");
        return head;
    }
    head = p->next;
    free(p);
    return head;
}

struct node *deletionBeforeValue(struct node *head)
{
    int value;
    printf("Enter value you have delete : ");
    scanf("%d", &value);
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("LINKED LIST IS EMPTY.\n");
    }
    else if (head->data == value)
    {
        printf("NO NODE TO DELETE BEFORE THE FIRST NODE.\n");
    }
    else
    {
        struct node *p = head->next;
        while (p != NULL && p->next->data != value && p->data != value)
        {
            ptr = ptr->next;
            p = p->next;
        }
        if (p->next->data == value)
        {
            ptr->next = p->next;
            free(p);
        }
        else if (p->data == value)
        {
            head = p;
            free(ptr);
        }
        else
        {
            printf("\n\nThe value %d is not in this linked list.\n", value);
        }
    }
    return head;
}

struct node *deletionAfterValue(struct node *head)
{
    int value;
    printf("Enter value you have delete : ");
    scanf("%d", &value);
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("LINKED LIST IS EMPTY.\n");
    }
    else
    {
        struct node *p = head->next;
        while (p != NULL && ptr->data != value)
        {
            ptr = ptr->next;
            p = p->next;
        }
        if (ptr->data == value && ptr->next != NULL)
        {
            ptr->next = p->next;
            free(p);
        }
        else if (ptr->next == NULL && ptr->data == value)
        {
            printf("NO NODE TO DELETE AFTER THE LAST NODE.\n");
        }
        else
        {
            printf("\n\nThe value %d is not in this linked list.\n", value);
        }
    }
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
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
    struct node *head;
    head = NULL;
    while (1)
    {
        printf("\n********** LINKED LIST MANU **********\n\n");
        printf("1. Insertion at tail.\n");
        printf("2. Insertion at head.\n");
        printf("3. Insertion between any index.\n");
        printf("4. Deletion at first.\n");
        printf("5. Deletion after value.\n");
        printf("6. Deletion before value.\n");
        printf("7. Reverse a linked list.\n");
        printf("8. Display the linked list.\n");
        printf("9. Exit.\n");
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
            head = insertAtbetween(head, 3);
            display(head);
            continue;
        case 4:
            head = deletionFirst(head);
            display(head);
            continue;
        case 5:
            head = deletionAfterValue(head);
            display(head);
            continue;
        case 6:
            head = deletionBeforeValue(head);
            display(head);
            continue;
        case 7:
            head = reverse(head);
            display(head);
            continue;
        case 8:
            display(head);
            continue;
        case 9:
            return 0;
        default:
            printf("PLESE ENTER VALID INPUT.");
            break;
        }
    }
    return 0;
}