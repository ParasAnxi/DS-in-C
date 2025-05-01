#include<stdio.h>
#define INT_MAX 1000000007
#define V 10

typedef struct{
    int v;
    int adj[V][V];
}Graph;

void init(Graph* g){
    g->v = 5;
    for(int i = 0 ; i < g->v; i++){
        for(int j = 0 ; j < g->v; j++){
            g->adj[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    //hardcoded edges u -> v && v -> u (undirected)
    g->adj[0][1] = 2; g->adj[1][0] = 2; g->adj[0][3] = 6; g->adj[3][0] = 6; g->adj[1][2] = 3; 
    g->adj[2][1] = 3; g->adj[1][3] = 8; g->adj[3][1] = 8; g->adj[1][4] = 5; g->adj[4][1] = 5; 
    g->adj[2][4] = 7; g->adj[4][2] = 7; g->adj[3][4] = 10; g->adj[4][3] = 9;
}
 
void printAdjMat(Graph* g){
    for(int i = 0; i < g->v;i++){
        for(int j = 0 ; j < g->v;j++){
            if(g->adj[i][j] == INT_MAX){
                printf("INF ");
            }
            else{
                printf("%3d ",g->adj[i][j]);
            }
        }
        printf("\n");
    }
};
int findMin(int key[],int mst[],int n){
    int mini = INT_MAX;
    int miniIdx = -1;
    for(int i = 0 ; i < n;i++){
        if(!mst[i] && key[i] < mini){
            mini = key[i];
            miniIdx = i;
        }
    }
    return miniIdx;
};
void prims(Graph *g){
    int n = g->v;
    int key[n];
    int parent[n];
    int mst[n];
    for(int i = 0 ; i < n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i = 0; i < n - 1;i++){
        int u = findMin(key,mst,n);
        mst[u] = 1;
        for(int v = 0 ; v < n;v++){
            if(g->adj[u][v] && g->adj[u][v] != INT_MAX && !mst[v] && g->adj[u][v] < key[v]){
                parent[v] = u;
                key[v] = g->adj[u][v];
            }
        }
    }
    //min u -> v with w
    printf("Minimum distance u -> v\n");
    for(int i = 1 ; i < n; i++){
        printf("%d - %d\t%d\n",parent[i],i,g->adj[i][parent[i]]);
    }
    //min cost
    int mini = 0;
    for(int i = 1; i < n ; i++){
        mini += g->adj[i][parent[i]];
    }
    printf("Min Cost : %d",mini);
}
int main(){
    Graph g;
    init(&g);
    // printAdjMat(&g);
    prims(&g);
}