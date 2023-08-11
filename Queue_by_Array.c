#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct queue *q, int val)
{
    if (q->rear == q->size - 1)
    {
        printf("This Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
    if (q->front == -1)
        q->front = 0;
}

int dequeue(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty.");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

int peek(struct queue *ptr, int index)
{
    if (ptr->rear == -1 || index >= ptr->rear)
    {
        printf("Invalid index you have entered.");
        return -1;
    }
    return ptr->arr[index];
}

void display(struct queue *ptr)
{
    for (int i = ptr->front; i <= ptr->rear; i++)
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
    enqueue(qu, 56);
    enqueue(qu, 43);
    enqueue(qu, 21);
    enqueue(qu, 98);
    enqueue(qu, 75);
    display(qu);
    int index = 3;
    printf("The value of index %d is : %d\n", index, peek(qu, index));
    printf("The dequeue value is : %d\n", dequeue(qu));
    printf("The dequeue value is : %d\n", dequeue(qu));
    display(qu);
    return 0;
}