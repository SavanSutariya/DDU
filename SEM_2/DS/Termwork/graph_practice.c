#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int weight;
    struct node *next;
} node;
node * createNode(int val, int weight){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
void addEdge(node *adj[], int u, int v, int weight){
    node *newNode = createNode(v, weight);
    newNode->next = adj[u];
    adj[u] = newNode;
}
int main()
{
    int n, m,is_directed,is_weighted;
    char filename[100];
    printf("Enter file name: ");
    scanf("%[^\n]s",filename);
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fscanf(fptr, "%d", &is_directed);
    fscanf(fptr, "%d", &is_weighted);
    fscanf(fptr, "%d", &n);
    fscanf(fptr, "%d", &m);
    if(is_directed){
        printf("Directed graph\n");
        //create adj matrix
        int adj[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            int u,v;
            fscanf(fptr,"%d",&u);
            fscanf(fptr,"%d",&v);
            if (is_weighted){
                int w;
                fscanf(fptr,"%d",&w);
                adj[u][v]=w;
            }
            else
                adj[u][v]=1;
        }
        //print adj matrix
        printf("\n |0 1 2 3 4 5 6 7");
        for (int i = 0; i < n; i++)
        {
            printf("\n%d|",i);
            for (int j = 0; j < n; j++)
            {
                printf("%d ",adj[i][j]);
            }
        }
        printf("\n");
        if(!is_weighted){
            //BFS
            int visited[n];
            for(int i=0;i<n;i++){
                visited[i]=0;
            }
            int queue[n];
            int front=-1,rear=-1;
            int start;
            printf("Enter start vertex: ");
            scanf("%d",&start);
            queue[++rear]=start;
            visited[start]=1;
            while(front!=rear){
                int u = queue[++front];
                printf("%d ",u);
                for(int i=0;i<n;i++){
                    if(adj[u][i]==1 && visited[i]==0){
                        queue[++rear]=i;
                        visited[i]=1;
                    }
                }
            }
            printf("\n");
            // DFS
            for(int i=0;i<n;i++){
                visited[i]=0;
            }
            front=-1,rear=-1;
            printf("Enter start vertex: ");
            scanf("%d",&start);
            queue[++rear]=start;
            visited[start]=1;
            while(front!=rear){
                int u = queue[++front];
                printf("%d ",u);
                for(int i=0;i<n;i++){
                    if(adj[u][i]==1 && visited[i]==0){
                        queue[++rear]=i;
                        visited[i]=1;
                    }
                }
            }
            printf("\n");
        }


    }
    else{
        printf("Undirected graph\n");
        //create adj link list
        node *adj[n];
        for(int i=0;i<n;i++){
            adj[i]=NULL;
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            fscanf(fptr,"%d",&u);
            fscanf(fptr,"%d",&v);
            if (is_weighted){
                fscanf(fptr,"%d",&w);
            }
            else{
                w=1;
            }
            addEdge(adj,u,v,w);
        }
        //print adj link list
        printf("\n");
        for(int i=0;i<n;i++){
            printf("%d: ",i);
            node *temp = adj[i];
            while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
        printf("\n");
    }
    fclose(fptr);
    
    return 0;
}