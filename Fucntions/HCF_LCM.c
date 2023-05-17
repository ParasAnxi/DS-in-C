#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int factorial(int x){
    if (x>=1)
        return x*factorial(x-1);
    else
        return 1;
}
int hcf(int x, int y) {
    if (y != 0)
        return hcf(y, x % y);
    else
        return x;
}
int lcm(int x, int y){
    static int common = 1;
    if (common %  x == 0 && common % y == 0){
        return common;
    }
    common++;
    lcm(x,y);
}
int sum(int n) {
  if (n != 0)
    return n + sum(n - 1);
  else
    return n;
}
int main(){
    int n;
    while(1){
        printf("1 for Factorial\n2 for hcf\n3 for lcm\n4 for sum of n natural\n5 for exit\n");
        printf("Enter operation to perform : ");
        printf("\n");
        scanf("%d",&n);

        switch(n){
        case 1:
            printf("Factorial is : %d",factorial(5));
            printf("\n");
            break;
        case 2:
            printf("hcf is : %d",hcf(9,24));
            printf("\n");
            break;
        case 3:
            printf("LCM is : %d",lcm(9,24));
            printf("\n");
            break;
        case 4:
            printf("sum of n natual no is : %d",sum(5));
            printf("\n");
        case 5:
            exit(0);
            break;

        default:
        printf("Invalid choice\n");
            break;
        }
    }
}