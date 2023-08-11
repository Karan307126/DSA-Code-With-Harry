#include <stdio.h>
#define N 20

void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = i * 2 + 1;
    int rightchild = i * 2 + 2;
    if (leftchild < n && arr[leftchild] > arr[largest])
        largest = leftchild;
    if (rightchild < n && arr[rightchild] > arr[largest])
        largest = rightchild;
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
    }
    Heapify(arr, n, largest);
}

void heapify(int arr[], int i)
{
    int perent = (i - 1) / 2;
    if (arr[perent] > 0)
    {
        if (arr[i] > arr[perent])
        {
            int temp = arr[i];
            arr[i] = arr[perent];
            arr[perent] = temp;
            heapify(arr, perent);
        }
    }
}

void InsertionHeap(int arr[], int *n, int key)
{
    *n = *n + 1;
    arr[*n - 1] = key;
    heapify(arr, *n - 1);
}

void delition(int arr[], int *n)
{
    int last = arr[*n - 1];
    arr[0] = last;
    *n = *n - 1;
    Heapify(arr, *n, 0);
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[N] = {10, 8, 5, 6, 3, 2, 1};
    int n = 7;
    int key = 15;
    display(arr, n);
    // InsertionHeap(arr, &n, key);
    // display(arr, n);
    delition(arr, &n);
    display(arr, n);
    return 0;
}