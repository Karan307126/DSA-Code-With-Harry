#include <stdio.h>

void bubblesort(int *arr, int n)
{
    int pass = 0;
    for (int i = 0; i < n - 1; i++)
    {
        pass++;
        int isSort = 1;
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSort = 0;
            }
        }
        if (isSort)
        {
            printf("This array is sorted in %d passes.\n", pass);
            return;
        }
    }
    printf("This array is sorted in %d passes.\n", pass);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}