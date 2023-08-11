#include <stdio.h>

int binarySearch(int arr[], int n, int data)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == data)
            return mid;
        else if (arr[mid] < data)
            left = mid + 1;
        else
            right = mid - 1;
    }
}

int main()
{
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array element : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int data;
    printf("Enter element you have find : ");
    scanf("%d", &data);
    printf("The number is find in index = %d.", binarySearch(arr, n, data));
    return 0;
}