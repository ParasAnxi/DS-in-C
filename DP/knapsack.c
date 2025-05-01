#include<stdio.h>
#include<string.h> 
#define MW 100
#define MC 100
typedef struct{
    int value;
    int weight;
}Item;

int dp[MW][MC];
int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(Item items[],int capacity,int index){
    if(index == 0){
        if(items[index].weight <= capacity){
            return items[index].value;
        }
        else{
            return 0;
        }
    }
    if(dp[index][capacity] != -1)return dp[index][capacity];
    int inc = 0;
    if(items[index].weight <= capacity){
        inc = items[index].value + solve(items, capacity - items[index].weight,index - 1);
    }
    int exc = solve(items,capacity,index - 1);
    return dp[index][capacity] = max(inc,exc);
}

int main(){
    Item items[] = {{10,2},{20,4},{40,5},{1,4},{10,8}};
    int capacity = 10;
    memset(dp, -1, sizeof(dp));
    int n = sizeof(items) / sizeof(items[0]);
    int ans = solve(items,capacity,n - 1);
    printf("Max value : %d",ans);
}