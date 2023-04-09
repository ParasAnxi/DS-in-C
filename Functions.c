#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int fibonaci(int x){
    int a=0,b=1,c;       
    for(int i=2;i<x;i++){    
    c=a+b;      
    a=b;    
    b=c;   
}
return c;
}
float sum(float x, float n){
    float i, ans = 1.0;
    for (i = 1; i <= n; i++)
        ans = ans +(pow(x, i) / i);
    return ans;
}
int FactSum(int n){
    int f = 1, Sum = 0;
    for (int i = 1; i <= n; i++) {
        f = f * i;
        Sum += f;
    }
    return Sum;
}
int factorial(int x){
    int fact=1;    
    for(int i=1;i<=x;i++){    
      fact=fact*i;    
  }    
  return fact;
}
int main(){
    int n;
    while(1){
        printf("1 for Fibonacci\n2 for Sum of series\n3 for factorial sum\n4 for factorial\n5 for exit\n");
        printf("Enter operation to perform : ");
        printf("\n");
        scanf("%d",&n);

        switch(n){
        case 1:
            printf("%d",fibonaci(5));
            printf("\n");
            break;
        case 2:
            printf("%f",sum(2,5));
            printf("\n");
            break;
        case 3:
            printf("%d",FactSum(5));
            printf("\n");
            break;
        case 4:
            printf("%d",factorial(5));
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