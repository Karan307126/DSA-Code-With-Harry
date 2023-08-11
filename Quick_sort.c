#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[], int low, int high)
{
    int PartitionIndex;
    if (low < high)
    {
        PartitionIndex = partition(arr, low, high);
        quicksort(arr, low, PartitionIndex - 1);
        quicksort(arr, PartitionIndex + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quicksort(arr, 0, n - 1);
    printf("Sorted array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}