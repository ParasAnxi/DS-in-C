#include <stdio.h>
int binarySearch(int arr[], int s, int e, int key){
    while (s <= e) {
        int mid = s+(e - s) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int main(void){
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",result);
    return 0;
}