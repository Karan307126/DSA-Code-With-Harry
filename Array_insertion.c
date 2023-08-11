#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    int value, pos;
    printf("Enter value you have insert : ");
    scanf("%d", &value);
    printf("Enter position : ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > n + 1)
    {
        printf("Invalid Position.");
        return 0;
    }
    for (int i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = value;
    n++;
    printArray(arr, n);
    return 0;
}