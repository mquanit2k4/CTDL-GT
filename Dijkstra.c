#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inf 100000

#define V_SIZE 6

void array_fill(int *arr, int size, int val)
{
    for (int i = 0; i < size; i++)
        arr[i] = val;
}

void dijkstra(int graph[][V_SIZE], int n, int start, int dist[])
{
    int* path = (int*)malloc(sizeof(int) * n);
    int* shortest = (int*)malloc(sizeof(int) * n);
    int* mark = (int*)malloc(sizeof(int) * n);
    int min,v,i,j;
    array_fill(mark, n, 0);
    array_fill(dist, n, inf);

    for (i = 0; i < n ; i++)
    {
        dist[i] = graph[start][i];
        if (i != start && dist[i] < inf)
            path[i] = start;
        else
            path[i] = -1;
    }

    mark[start] = 1;
    while(1)
    {
        min = inf;
        v = -1;
        for (i = 0; i < n; i++)
        {
            if (mark[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                v = i;
            }
        }
        if (v == -1)
            break;
        mark[v] = 1;
        for (i = 0; i < n; i++)
        {
            if (mark[i] == 0 && graph[v][i] < inf)
            {
                if (dist[i] > dist[v] + graph[v][i])
                {
                    dist[i] = dist[v] + graph[v][i];
                    path[i] = v;
                }
            }
        }
    } 
    printf("Start\tEnd\tShortest\tPath\n");
    for(i = 0; i < n; i++)
    {
        if (i == start)
            continue;
        array_fill(shortest, n, 0);
        printf("%d\t", start);
        printf("%d\t", i);
        printf("%d\t", dist[i]);
        int k = 0;
        shortest[k] = i;
        while(path[shortest[k]] != start)
        {
            k++;
            shortest[k] = path[shortest[k-1]];
        }
        k++;
        shortest[k] = start;
        for (j = k; j > 0; j--)
            printf("%d->", shortest[j]);
        printf("%d\n", shortest[0]);
    }
    free(path);
    free(shortest);
    free(mark);
    return;
}

int main()
{
    int graph[V_SIZE][V_SIZE] = {
        {0, 1, 12, inf, inf, inf},
        {inf, 0, 9, 3, inf, inf},
        {inf, inf, 0, inf, 5, inf},
        {inf, inf, 4, 0, 13, 15},
        {inf, inf, inf, inf, 0, 4},
        {inf, inf, inf, inf, inf, 0}
    };
    int dist[V_SIZE];
    dijkstra(graph, V_SIZE, 0, dist);
    return 0;
}