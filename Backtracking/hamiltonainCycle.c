#include <stdio.h>
#define V 5

int path[V];

int isSafe(int v, int graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v]){
        return 0;
    }
    for (int i = 0; i < pos; i++)
        if (path[i] == v){
            return 0;
        }
    return 1;
}

int solve(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return 1;
        else
            return 0;
    }
    for (int v = 1; v < V; v++) {  
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (solve(graph, path, pos + 1)){
                return 1;
            }
            path[pos] = -1;
        }
    }
    return 0;
}

int solveHc(int graph[V][V]) {
    for (int i = 0; i < V; i++){
        path[i] = -1;
    }
    path[0] = 0; 
    if (!solve(graph, path, 1)) {
        printf("No Cycle\n");
        return 0;
    }
    printf("Cycle exists:\n");
    for (int i = 0; i < V; i++){
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);  
    return 1;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    solveHc(graph);
    return 0;
}
