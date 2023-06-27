/*

Enter the number of vertices in the graph: 5
Enter the adjacency matrix for the graph:
0 4 0 0 0
4 0 8 0 0
0 8 0 7 0
0 0 7 0 9
0 0 0 9 0
Enter the source vertex: 0

*/

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES];

int get_minimum_distance(int vertices)
{
    int min_distance = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v] && distance[v] <= min_distance)
        {
            min_distance = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int vertices, int source_vertex)
{
    // Initialize all distances as infinite and visited as false
    for (int v = 0; v < vertices; v++)
    {
        distance[v] = INT_MAX;
        visited[v] = 0;
    }

    // Distance of source vertex from itself is always 0
    distance[source_vertex] = 0;

    for (int count = 0; count < vertices - 1; count++)
    {
        int u = get_minimum_distance(vertices);
        visited[u] = 1;

        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX
                && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
}

int main()
{
    int vertices, source_vertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source_vertex);

    dijkstra(vertices, source_vertex);

    printf("Shortest distances from source vertex %d:\n", source_vertex);
    for (int v = 0; v < vertices; v++)
    {
        printf("%d -> %d: %d\n", source_vertex, v, distance[v]);
    }

    return 0;
}
