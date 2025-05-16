#include <stdio.h>
#define INT_MAX 1000000007
int solveSum(int vF[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++){
        s += vF[k];
    }
    return s;
}
int solve(int vK[], int vF[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++){
        dp[i][i] = vF[i];
    }
    for (int s = 2; s <= n; s++) {
        for (int i = 0; i <= n - s; i++) {
            int j = i + s - 1;
            dp[i][j] = INT_MAX;
            for (int e = i; e <= j; e++) {
                int x = ((e > i) ? dp[i][e - 1] : 0) + ((e < j) ? dp[e + 1][j] : 0) + solveSum(vF, i, j);
                if (x < dp[i][j]){
                    dp[i][j] = x;
                }
            }
        }
    }
    return dp[0][n - 1];
}
int main() {
    int vK[] = {10, 12, 20};
    int vF[] = {34, 8, 50};
    int n = sizeof(vK) / sizeof(vK[0]);
    printf("%d\n", solve(vK, vF, n));
    return 0;
}
