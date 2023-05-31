#include <stdio.h>
 
// Function to swap two elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition(int arr[], int s, int e){
    int pivot = arr[e];
 
    int i = (s - 1);
 
    for (int j = s; j <= e - 1; j++) {
 
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[e]);
    return (i + 1);
}
 
void quickSort(int arr[], int s, int e)
{
    if (s < e) {
        int pi = partition(arr, s, e);
        quickSort(arr, s, pi - 1);
        quickSort(arr, pi + 1, e);
    }
}

int main(){
    int arr[] = { 2,4,3,6 ,10, 7, 8, 9, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    quickSort(arr, 0, N - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}