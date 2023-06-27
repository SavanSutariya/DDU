/*
Enter number of vertices: 5
Enter adjacency list:
Enter number of edges adjacent to vertex 0: 2
Enter adjacent vertex and weight: 1 4
Enter adjacent vertex and weight: 2 3
Enter number of edges adjacent to vertex 1: 3
Enter adjacent vertex and weight: 0 4
Enter adjacent vertex and weight: 2 1
Enter adjacent vertex and weight: 3 2
Enter number of edges adjacent to vertex 2: 3
Enter adjacent vertex and weight: 0 3
Enter adjacent vertex and weight: 1 1
Enter adjacent vertex and weight: 4 5
Enter number of edges adjacent to vertex 3: 2
Enter adjacent vertex and weight: 1 2
Enter adjacent vertex and weight: 4 6
Enter number of edges adjacent to vertex 4: 2
Enter adjacent vertex and weight: 2 5
Enter adjacent vertex and weight: 3 6

   2       3
(1)--(2)--(3)
 |   / \   |
 |  /   \  |
6| /     \ |7
 |/       \|
(4)-------(5)
      9


*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000

typedef struct {
    int vertex;
    int weight;
} Edge;

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices;

void add_edge(int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight;
}

void prim_mst() {
    int selected[MAX_VERTICES] = {0};
    Edge edges[num_vertices-1];
    int edge_count = 0;

    selected[0] = 1;

    while (edge_count < num_vertices - 1) {
        int min_weight = INT_MAX;
        int x = 0;
        int y = 0;

        for (int i = 0; i < num_vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < num_vertices; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min_weight > graph[i][j]) {
                            min_weight = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        selected[y] = 1;
        edges[edge_count++] = (Edge){y, min_weight};
    }

    printf("Edges in MST:\n");
    int sum = 0;
    for (int i = 0; i < num_vertices - 1; i++) {
        printf("%d - %d : %d\n", edges[i].vertex, i+1, edges[i].weight);
        sum += edges[i].weight;
    }
    printf("Total weight of MST: %d\n", sum);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter adjacency list:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        int num_edges;
        printf("Enter number of edges adjacent to vertex %d: ", i);
        scanf("%d", &num_edges);

        for (int j = 0; j < num_edges; j++) {
            int vertex, weight;
            printf("Enter adjacent vertex and weight: ");
            scanf("%d %d", &vertex, &weight);

            add_edge(i, vertex, weight);
        }
    }

    prim_mst();

    return 0;
}
