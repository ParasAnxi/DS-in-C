#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
int ind = 0;
void insert(){
    int x;
    printf("Enter element to inert : ");
    scanf("%d",&x);
    if(ind == size-1){
        printf("Full\n");
    }
    else{
        arr[ind++] = x;
    }
}
int del(){
    if(ind == -1){
        return -1;
    }
    else{
        --ind;
    }
}
void merge(int arr1[],int arr2[],int mArr[10]){
    int i,j;
 for (i = 0; i < 5; i++) {
        mArr[i] = arr1[i];
    }
 
    for (i = 0, j = 5;j < 10 && i < 5; i++, j++) {
        mArr[j] = arr2[i];
    }
}
int min(int arr[], int n){
    int i;
    int mini = arr[0];
    for (i = 0; i < n; i++){
        if (arr[i] < mini){
            mini = arr[i];
    }
}
return mini;
}
int max(int arr[],int n){
    int i;
    int maxi = arr[0];
    for(int i = 0 ; i<n ;i++){
    if (arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}
void dis(){
    for(int i = 0; i<ind;++i){
        printf("%d ",arr[i]);
    }printf("\n");
}
int main(){
    int n;
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};
    int a3[10];
    while(1){
        printf("1 for insert\n2 for delete\n3 for merge\n4 for fin min\n5 for find max\n6 to exit");
        printf("Enter operation to perform : ");
        printf("\n");
        scanf("%d",&n);

        switch(n){
        case 1:
            insert();
            dis();
            printf("\n");
            break;
        case 2:
            del();
            dis();
            printf("\n");
            break;
        case 3:
            merge(arr1,arr2,a3);
            for(int i = 0; i<10;i++){
                printf("%d ",a3[i]);
            }
            printf("\n");
            break;
        case 4:
            printf("%d",min(arr2,5));
            printf("\n");
            break;
        case 5:
            printf("%d",max(arr2,5));
            printf("\n");
            break;
        case 6:
            exit(0);
            break;

        default:
        printf("Invalid choice\n");
            break;
        }
    }
}
