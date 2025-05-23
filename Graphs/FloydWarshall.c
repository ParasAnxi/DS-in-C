#include <stdio.h>
#define INT_MAX 1000000007
#define V 4
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[V][V] = {
        {0,   5,  INT_MAX, 10},
        {INT_MAX, 0,   3,  INT_MAX},
        {INT_MAX, INT_MAX, 0,   1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };
    floydWarshall(graph);
    return 0;
}
