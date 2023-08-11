#include <stdio.h>

int RecursiveBinSearch(int arr[], int l, int h, int key)
{
    if (l == h)
    {
        if (arr[l] == key)
            return l;
        else
            return -1;
    }
    else
    {
        int mid = (l + h) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return RecursiveBinSearch(arr, mid + 1, h, key);
        else
            return RecursiveBinSearch(arr, l, h - 1, key);
    }
}

int main()
{
    int n;
    printf("Enter the no of elements : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter key value : ");
    scanf("%d", &key);
    if (RecursiveBinSearch(arr, 0, n - 1, key) != -1)
        printf("The key value is found in index %d.\n", RecursiveBinSearch(arr, 0, n - 1, key));
    else
        printf("The key value is not found.");
    return 0;
}