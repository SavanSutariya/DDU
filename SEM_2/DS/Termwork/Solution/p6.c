#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int n, m, isDirected, isWeighted;
int adjMatrix[MAX_NODES][MAX_NODES] = {0};
int adjList[MAX_NODES][MAX_NODES] = {0};

void dfs(int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] && !visited[i]) {
            dfs(i, visited);
        }
    }
}

void bfs(int start) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES], front = 0, rear = 0;
    visited[start] = 1;
    printf("%d ", start);
    queue[rear++] = start;
    while (front < rear) {
        int v = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}

void printAdjMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}


void generateAdjMatrix(FILE *fp) {
    int u, v, w;
    for (int i = 0; i < m; i++) {
        if (isWeighted) {
            fscanf(fp, "%d %d %d", &u, &v, &w);
        } else {
            fscanf(fp, "%d %d", &u, &v);
        }
        adjMatrix[u][v] = 1;
        if (!isDirected) {
            adjMatrix[v][u] = 1;
        }
    }
    printAdjMatrix();
}

struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    if (!isDirected) {
        newNode = createNode(src, weight);
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    }
}
void printAdjList(struct Graph *graph) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void generateAdjList(FILE *fp) {
    int u, v, w;
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        if (isWeighted) {
            fscanf(fp, "%d %d %d", &u, &v, &w);
        } else {
            fscanf(fp, "%d %d", &u, &v);
        }
        addEdge(graph, u, v, w);
    }
    printAdjList(graph);
}


int main() {
    
    FILE *fp;
    fp = fopen("tgraph.txt", "r");
    fscanf(fp, "%d %d", &isDirected, &isWeighted);
    fscanf(fp, "%d %d", &n, &m);
    if (isDirected && !isWeighted) {
        generateAdjMatrix(fp);
    }else {
        generateAdjList(fp);
    }
    fclose(fp);

    fp = fopen("fgraph.txt", "r");
    fscanf(fp, "%d %d", &isDirected, &isWeighted);
    fscanf(fp, "%d %d", &n, &m);

    if (isDirected && !isWeighted) {
        generateAdjMatrix(fp);
    } else {
        generateAdjList(fp);
    }
    
    fclose(fp);

    printf("\nDFS: ");
    int visited[MAX_NODES] = {0};
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }

    printf("\nBFS: ");
    bfs(0);
    printf("\n");
    
    return 0;
}