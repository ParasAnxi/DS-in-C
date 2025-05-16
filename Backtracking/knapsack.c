#include <stdio.h>
int maxi = 0;  
void solve(int idx, int n, int weight[], int value[], int capacity, int currW, int currV) {
    if (currW > capacity) return;
    if (idx == n) {
        if (currV > maxi){
            maxi = currV;
        }
        return;
    }
    solve(idx + 1, n, weight, value, capacity, currW + weight[idx], currV + value[idx]);
    solve(idx + 1, n, weight, value, capacity, currW, currV);
}


int main() {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(value) / sizeof(value[0]);
    solve(0, n, weight, value, capacity, 0, 0);
    printf("%d\n", maxi);
    return 0;
}
