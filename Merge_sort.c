#include <stdio.h>

void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int arr2[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        arr2[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr2[i];
    }
}

void mergesort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/ 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}