#include <stdio.h>
#include<stdlib.h>
 
int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
void print2largest(int arr[], int arr_size){
    int i, first, second;
    if (arr_size < 2) {
        printf(" Invalid Input ");
        return;
    }
    qsort(arr, arr_size, sizeof(int), cmp);
    for (i = arr_size - 2; i >= 0; i--) {
        if (arr[i] != arr[arr_size - 1]) {
            printf("The second largest element is %d\n",arr[i]);
            return;
        }
    }
    printf("There is no second largest element\n");
}
 
int main(){    
    int arr[] = { 12, 35, 1, 10, 34, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    print2largest(arr, n);
    return 0;
}