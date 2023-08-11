#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (q->rear == q->size - 1)
    {
        printf("This Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
        printf("Queue is empty.");
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main()
{
    struct queue qu;
    qu.size = 100;
    qu.rear = 0;
    qu.front = 0;
    qu.arr = (int *)malloc(qu.size * sizeof(int));

    // BFS algorithm implementation
    int node, i = 0, n;
    printf("Enter number of vertisis in graph : ");
    scanf("%d", &n);

    int visited[n]; // This is visited array initialize with 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("Is %d connected %d.(yes = 1, no = 0) : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n%d ", i);
    visited[i] = 1;
    enqueue(&qu, i);
    while (!isEmpty(&qu))
    {
        int node = dequeue(&qu);
        for (int j = 0; j < 6; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&qu, j);
            }
        }
    }
    return 0;
}