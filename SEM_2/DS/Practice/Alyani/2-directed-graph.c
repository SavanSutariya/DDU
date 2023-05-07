/*  
    2           6
    ^---->4<----^
    |          / \
    |         /   \
    |        /     \
    1------->3---->5
Directed

1. Matrix
2. List
3. BFS
4. DFS
*/

#include <stdio.h>
#include <stdlib.h>

#define max_vert 50

int ADJMAT[max_vert][max_vert];

typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* adjList[max_vert];

int numVertices = 0, numEdges = 0;

void addEdge(int src, int dest) {

    ADJMAT[src][dest] = 1;

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    numEdges++;
}

void dfsMatrix(int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < numVertices; i++) {
        if (ADJMAT[vertex][i] && !visited[i]) {
            dfsMatrix(i, visited);
        }
    }
}

void dfsList(int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node* currNode = adjList[vertex];
    while (currNode != NULL) {
        int adjVertex = currNode->vertex;
        if (!visited[adjVertex]) {
            dfsList(adjVertex, visited);
        }
        currNode = currNode->next;
    }
}

void bfsMatrix(int startVertex) {
    int visited[max_vert] = {0};
    int queue[max_vert];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int vertex = queue[++front];
        printf("%d ", vertex);

        for (int i = 0; i < numVertices; i++) {
            if (ADJMAT[vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void bfsList(int startVertex) {
    int visited[max_vert] = {0};
    int queue[max_vert];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int vertex = queue[++front];
        printf("%d ", vertex);

        Node* currNode = adjList[vertex];
        while (currNode != NULL) {
            int adjVertex = currNode->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            currNode = currNode->next;
        }
    }
}

void printGraph() {
    printf("Adjacency Matrix:\n   ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", ADJMAT[i][j]);
        }
        printf("\n");
    }

   
    printf("Edges list:\n");
    for (int i = 0; i < numVertices; i++) {
        Node* currNode = adjList[i];
        while (currNode != NULL) {
            printf("%d -> %d\n", i, currNode->vertex);
            currNode = currNode->next;
        }
    }
     printf("Number of vertices: %d\n", numVertices);
    printf("Number of edges: %d\n", numEdges);
    
}

void createGraph() {
    numVertices = 7; 
    for (int i = 0; i < numVertices; i++) {
        adjList[i] = NULL;
    }

    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(3, 6);
    addEdge(5, 6);
    addEdge(6, 4);
}

int main() {
    createGraph();
    printGraph();

    printf("Depth First Search (DFS) using adjacency matrix:\n");
    int visited[max_vert] = {0};
    dfsMatrix(1, visited);
    printf("\n");

    printf("Depth First Search (DFS) using adjacency list:\n");
    int visitedList[max_vert] = {0};
    dfsList(1, visitedList);
    printf("\n");

    printf("Breadth First Search (BFS) using adjacency matrix:\n");
    bfsMatrix(1);
    printf("\n");

    printf("Breadth First Search (BFS) using adjacency list:\n");
    bfsList(1);
    printf("\n");


return 0;
}