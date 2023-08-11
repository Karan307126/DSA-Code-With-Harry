#include <stdio.h>

int visited[6] = {0, 0, 0, 0, 0, 0};
int a[6][6] = {
    {0, 1, 0, 1, 1, 1},
    {1, 0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0}};

int DFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 6; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(3);
    return 0;
}