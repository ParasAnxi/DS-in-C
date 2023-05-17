#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void mul(int m1[][3], int m2[][3], int mult[][3], int r1, int c1, int r2, int c2){
	int i, j, k;

	for(i = 0; i < r1; ++i){
		for(j = 0; j < c2; ++j){
			mult[i][j] = 0;
		}
	}

	for(i = 0; i < r1; ++i){
		for(j = 0; j < c2; ++j){
			for(k=0; k<c1; ++k){
				mult[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}
void sum(int m1[][3],int m2[][3],int sum[][3],int r1,int c1){
    for (int i = 0; i < r1; ++i){
    for (int j = 0; j < c1; ++j) {
      sum[i][j] = m1[i][j] + m2[i][j];
      }
    }
}
void transpose(int m[3][3], int t[3][3]) {
  int row, col;
  for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
      t[row][col] = m[col][row];
    }
  }
}
int sumE(int m[3][3]){
    int sum = 0;
 for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum = sum + m[i][j];
        }
    }
    return sum;
}
int isSparse(int m1[3][3]){
    int cnt = 0;
 
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (m1[i][j] == 0)
                ++cnt;
 
    return (cnt > ((3 * 3) / 2));
}
int main(){
    int m1[3][3] ={
            { 1, 0, 3 },
            { 0, 0, 4 },
            { 6, 0, 0 } };
    int m2[3][3]={
        {1,2,3},
        {4,5,6},
        {2,4,5}
    };
    int m3[3][3];
    int n;
    while(1){
        printf("1 for Multiply\n2 for Sum\n3 for transpose\n4 for sum Of elements\n5 to check sparse matrix\n6 for exit\n");
        printf("Enter operation to perform : ");
        printf("\n");
        scanf("%d",&n);

        switch(n){
        case 1:
            mul(m1,m2,m3,3,3,3,3);
            for(int i = 0; i<3 ;i++){
                for(int j = 0; j<3;j++){
                    printf("%d ",m3[i][j]);
                }
            }
            printf("\n");
            break;
        case 2:
            sum(m1,m2,m3,3,3);
            for(int i = 0; i<3 ;i++){
                for(int j = 0; j<3;j++){
                    printf("%d ",m3[i][j]);
                }
            }
            printf("\n");
            break;
        case 3:
            transpose(m1,m3);
            for(int i = 0; i<3 ;i++){
                for(int j = 0; j<3;j++){
                    printf("%d ",m3[i][j]);
                }
            }
            printf("\n");
            break;
        case 4:
            printf("%d",sumE(m2));
            printf("\n");
            break;
        case 5:
            if(isSparse(m1)){
                printf("MAtrix is Sparse\n");
            }
            else{
                printf("Matrix is not sparse\n");
            }
            break;
        case 6:
            exit(0);
        default:
        printf("Invalid choice\n");
            break;
        }
}
}