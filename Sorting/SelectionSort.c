#include <stdio.h>
 
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void selectionSort(int arr[], int n){
    int i, j, mini;
    for (i = 0; i < n-1; i++){
        mini = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[mini])
            mini = j;
 
           if(mini != i)
            swap(&arr[mini], &arr[i]);
    }
}
 
void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main(){
    int arr[] = {3,5,7,1,2,10,9,8,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}