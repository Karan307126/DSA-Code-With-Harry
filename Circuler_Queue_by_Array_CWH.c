#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct queue *ptr)
{
    int val;
    printf("Enter value you have enqueue in queue : ");
    scanf("%d", &val);
    if (((ptr->rear + 1) % (ptr->size)) == ptr->front)
    {
        printf("The queue is full.\n");
    }
    else if (ptr->front == -1 && ptr->rear == -1)
    {
        ptr->front = ptr->rear = 0;
        ptr->arr[ptr->rear] = val;
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size;
        ptr->arr[ptr->rear] = val;
    }
}

void dequeue(struct queue *ptr)
{
    if (ptr->front == -1 && ptr->rear == -1)
    {
        printf("The queue is empty.\n");
    }
    else if (ptr->front == ptr->rear)
    {
        printf("The dequeued value is %d.\n", ptr->arr[ptr->front]);
        ptr->front = ptr->rear = -1;
    }
    else
    {
        printf("The dequeued value is %d.\n", ptr->arr[ptr->front]);
        ptr->front = (ptr->front + 1) % ptr->size;
    }
}

void display(struct queue *ptr)
{
    if (ptr->front == -1 && ptr->rear == -1)
    {
        printf("Queue is empty.");
    }
    else
    {
        int i = ptr->front;
        while (i != ptr->rear)
        {
            printf("%d -> ", ptr->arr[i]);
            i = (i + 1) % ptr->size;
        }
        printf("%d", ptr->arr[ptr->rear]);
    }
}

int main()
{
    struct queue *qu;
    qu->size = 5;
    qu->rear = -1;
    qu->front = -1;
    qu->arr = (int *)malloc(qu->size * sizeof(int));
    while (1)
    {
        int n;
        printf("\n\n*****    CERCULER QUEUE MENU    *****\n");
        printf("1. Enqueue element\n");
        printf("2. Dequeue element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter number : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            enqueue(qu);
            break;
        case 2:
            dequeue(qu);
            break;
        case 3:
            display(qu);
            break;
        case 4:
            return 0;
        default:
            printf("Enter valid number.\n");
            break;
        }
    }
    return 0;
}