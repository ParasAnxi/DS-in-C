#include<stdio.h>
#define INT_MAX 1000000007
#define V 5

int adj[V][V];
void init(){
    for(int i = 0 ; i < V; i++){
        for(int j = 0 ; j < V; j++){
            adj[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    //hardcoded edges u -> v(undirected)
    adj[0][1] = 2; adj[1][0] = 2;
    adj[0][3] = 6; adj[3][0] = 6;
    adj[1][2] = 3; adj[2][1] = 3;
    adj[1][3] = 8; adj[3][1] = 8;
    adj[1][4] = 5; adj[4][1] = 5;
    adj[2][4] = 7; adj[4][2] = 7;
    adj[3][4] = 9; adj[4][3] = 9;
}
int minDis(int dist[],int visited[]){
    int mini = INT_MAX,miniIdx = -1;
    for(int i = 0 ; i < V;i++){
        if(!visited[i] && dist[i] < mini){
            mini = dist[i];
            miniIdx = i;
        }
    }
    return miniIdx;
}
void dijkstra(int src){
    int dist[V], visited[V];
    for(int i = 0 ; i < V; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for(int i = 0 ; i < V - 1;i++){
        int u = minDis(dist,visited);
        visited[u] = 1;
        for(int v = 0 ; v < V; v++){
            if(!visited[v] && adj[u][v] != INT_MAX && dist[u] + adj[u][v] < dist[v]){
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    for (int i = 0; i < V; i++) {
        printf("%d \t%d\n", i, dist[i]);
    }
}
int main(){
    init();
    dijkstra(0);
    return 0;
}