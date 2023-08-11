#include <stdio.h>
#include <stdlib.h>

struct Cqueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct Cqueue *cq, int val)
{
    if (cq->rear == cq->size - 1)
        cq->rear = 0;
    else
        cq->rear++;
    if (cq->front == cq->rear)
    {
        printf("Not able to enqueue element %d in this queue.\n", val);
        return;
    }
    cq->arr[cq->rear] = val;
    printf("The enqueuing element is : %d\n", cq->arr[cq->rear]);
    if (cq->front == -1)
        cq->front = 0;
}

int dequeue(struct Cqueue *cq)
{
    if (cq->front == -1)
    {
        printf("The queue is empty.\n");
        return -1;
    }
    int val = cq->arr[cq->front];
    if (cq->front == cq->rear)
    {
        cq->front = cq->rear = -1;
        return val;
    }
    if (cq->front == cq->size - 1)
        cq->front = 0;
    else
        cq->front++;
    return val;
}

int main()
{
    struct Cqueue *cq;
    cq->size = 5;
    cq->front = -1;
    cq->rear = -1;
    cq->arr = (int *)malloc(sizeof(int) * cq->size);
    enqueue(cq, 4);
    enqueue(cq, 6);
    enqueue(cq, 1);
    enqueue(cq, 9);
    printf("\nThe dequeuing element is : %d\n", dequeue(cq));
    printf("The dequeuing element is : %d\n\n", dequeue(cq));
    enqueue(cq, 13);
    enqueue(cq, 17);
    enqueue(cq, 14);
    enqueue(cq, 11);
    return 0;
}