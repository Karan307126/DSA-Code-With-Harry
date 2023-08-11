#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueueAtFront(struct queue *ptr, int val)
{
    if (ptr->front == -1)
    {
        printf("Not able to enqueueing,\n");
        return;
    }
    ptr->front--;
    ptr->arr[ptr->front] = val;
}

void enqueueAtRear(struct queue *ptr, int val)
{
    if (ptr->rear == ptr->size)
    {
        printf("The queue is full.\n");
        return;
    }
    ptr->arr[ptr->rear] = val;
    ptr->rear++;
}

int dequeueAtRear(struct queue *ptr)
{
    if (ptr->rear == ptr->front)
    {
        printf("The queue is empty.\n");
        return -1;
    }
    ptr->rear--;
    int val = ptr->arr[ptr->rear];
    return val;
}

int dequeueAtFront(struct queue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        printf("The queue is empty.\n");
        return -1;
    }
    int val = ptr->arr[ptr->front];
    ptr->front++;
    return val;
}

void display(struct queue *ptr)
{
    for (int i = ptr->front; i < ptr->rear; i++)
    {
        printf("%d\t", ptr->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue *qu;
    qu->size = 100;
    qu->rear = -1;
    qu->front = -1;
    qu->arr = (int *)malloc(qu->size * sizeof(int));
    enqueueAtRear(qu, 56);
    enqueueAtRear(qu, 43);
    enqueueAtRear(qu, 21);
    enqueueAtRear(qu, 98);
    display(qu);
    printf("Dequeueing element is %d.\n", dequeueAtFront(qu));
    display(qu);
    enqueueAtFront(qu, 75);
    display(qu);
    printf("Dequeueing element is %d.\n", dequeueAtRear(qu));
    display(qu);
    return 0;
}