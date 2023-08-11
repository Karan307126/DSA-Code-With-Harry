#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deletion(int arr[], int n, int pos)
{
    if (pos <= 0 || pos > n)
    {
        printf("Invalid position.");
    }
    for (int i = pos - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    int pos;
    printf("Entre position value you have delete : ");
    scanf("%d", &pos);
    deletion(arr, n, pos);
    printArray(arr, n - 1);
    return 0;
}