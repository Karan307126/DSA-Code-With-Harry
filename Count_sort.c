#include <stdio.h>
#include <stdlib.h>

void countsort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int *count = (int *)malloc(sizeof(int) * (max + 1));
    for (int i = 0; i < max + 1; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]] += 1;
    int i = 0, j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    countsort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}