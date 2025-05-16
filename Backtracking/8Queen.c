#include <stdio.h>
#define N 8

int board[N][N];

int isSafe(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i]){
            return 0;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return 0;
    }
    return 1;
}

int solve(int col) {
    if (col >= N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%c ", board[i][j] ? 'Q' : '.');
            }
            printf("\n");
        }
        printf("\n");
        return 1;  
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            ans = solve(col + 1) || ans;
            board[i][col] = 0; 
        }
    }
    return ans;
}

int main() {
    solve(0);
    return 0;
}
