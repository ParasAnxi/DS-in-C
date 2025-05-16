#include <stdio.h>
#define V 4  

int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++){
        if (graph[v][i] && color[i] == c){
            return 0;
        }
    }
    return 1;
}

int solve(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        for (int i = 0; i < V; i++)
        printf("V %d -> C %d\n", i, color[i]);
        return 1; 
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (solve(graph, m, color, v + 1)){
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}
int solveGc(int graph[V][V], int m) {
    int color[V] = {0};
    if (!solve(graph, m, color, 0)) {
        printf("not possible\n");
        return 0;
    }
    return 1;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3;  
    solveGc(graph, m);
    return 0;
}
