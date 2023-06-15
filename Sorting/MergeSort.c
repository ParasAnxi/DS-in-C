#include <stdio.h>
#include <stdlib.h>
 
void merge(int arr[], int s, int m, int e){
    int i, j, k;
    int len1 = m - s + 1;
    int len2 = e - m;
 
    int first[len1], second[len2];
    for (i = 0; i < len1; i++)
        first[i] = arr[s + i];
    for (j = 0; j < len2; j++)
        second[j] = arr[m + 1 + j];
 
    i = 0;
 
    j = 0;
 
    k = s;
    while (i < len1 && j < len2){
        if (first[i] <= second[j]){
            arr[k++] = first[i++];
        }
        else{
            arr[k++] = second[j++];
        }
    }

    while (i < len1) {
        arr[k++] = first[i++];
    }

    while (j < len2){
        arr[k++] = second[j++]; 
    }
}
 
void mergeSort(int arr[], int s, int e){
    if (s < e){
        int m = s + (e - s) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
 
        merge(arr, s, m, e);
    }
}
 
void printArray(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main(){
    int arr[] = {10,8,4,1,3,4,2,7,9,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printf("\nAfter Merge Sort\n");
    printArray(arr, size);
    return 0;
}