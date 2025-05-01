#include<stdio.h>
#include<stdlib.h>
// #define N 100

typedef struct{
    int profit;
    int deadline;
}Job;

int cmp(const void* a,const void* b){
    return ((Job*)b)->profit - ((Job*)a)->profit;
};
int solve(Job jobs[],int n){
    int profit = 0;
    qsort(jobs,n,sizeof(Job),cmp);
    int slots[n];
    for(int i = 0 ; i < n;i++){
        slots[i] = 0;
    }
    for(int i = 0 ; i < n;i++){
        for(int j = jobs[i].deadline - 1;j >= 0;j--){
            if(slots[j] == 0){
                slots[j] = 1;
                profit += jobs[i].profit;
                break;
            }
        }
    }
    return profit;
};

int main(){
    Job jobs[]={
        {20, 2},
        {15, 2},
        {10, 1},
        {5, 3},
        {1, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    int ans = solve(jobs,n);
    printf("Max Profit : %d",ans);
    return 0;
}