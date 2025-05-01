#include<stdio.h>
#include<stdlib.h>
#define V 5
#define E 7

typedef struct{
    int u, v, w;
}Edge;
Edge edges[E] = {
    {0, 1, 2},
    {0, 3, 6},
    {1, 2, 3},
    {1, 3, 8},
    {1, 4, 5},
    {2, 4, 7},
    {3, 4, 10},
};
//DJS
int parent[V];
int rank[V] = {0};
void init(){
    for(int i = 0 ; i < V; i++){
        parent[i] = i;
    }
};
int find(int x){
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}
void join(int x, int y){
    int pX = find(x);
    int pY = find(y);
    if(pX != pY){
        if(rank[pX] < rank[pY]){
            parent[pX] = pY;
        }
        else if(rank[pY] < rank[pX]){
            parent[pY] = pX;
        }
        else{
            parent[pX] = pY;
            rank[pY]++;
        }
    }
};
int cmp(const void* a,const void* b){
    Edge* x = (Edge*)a;
    Edge* y = (Edge*)b;
    if(x->w < y->w) return -1;
    if(x->w > y->w) return 1;
    return 0;
}
void kruskal(){
    init();
    qsort(edges,E,sizeof(Edge),cmp);
    int mini = 0;
    for(int i = 0 ; i < E; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(find(u) != find(v)){
            mini += w;
            join(u , v);
        }
    }
    printf("Min cost : %d",mini);
}

int main(){
    kruskal();
    return 0;
}