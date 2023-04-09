#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int factorial(int x){
    int fact=1;    
    for(int i=1;i<=x;i++){    
      fact=fact*i;    
  }    
  return fact;
}
int hcf(int x, int y){
    if (y == 0)
    return x;
  else
    return hcf(y, x % y);   
}
int lcm(int x,int y){
    return x*y/(hcf(x,y));
}
int sum(int x){
    int sum = 0;
    for (int i = 1; i <= x; i++) {
        sum += i;
    }
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