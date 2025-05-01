#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct{
    int value;
    int weight;
}Item;

int cmp(const void* a, const void* b){
    Item* x = (Item*)a;
    Item* y = (Item*)b;
    double r1 = (double)x->value / x->weight;
    double r2 = (double)y->value / y->weight;
    return (r2 > r1) - (r2 < r1);
}
double solve(Item items[],int n,int capacity){
    double profit = 0.0;
    qsort(items,n,sizeof(Item),cmp);
    for(int i = 0 ; i < n; i++){
        if(capacity == 0) break;
        if(items[i].weight <= capacity){
            profit += items[i].value;
            capacity -= items[i].weight;
        }
        else{
            profit += (double)items[i].value * capacity / items[i].weight;
            break;
        }
    }
    return profit;
};
int main(){
    Item items[N] = {
        {10,20},
        {20,30},
        {20,10},
        {5,1},
        {10,4}
    };
    double ans = solve(items,N,50);
    printf("%.2f",ans);
    return 0;
}