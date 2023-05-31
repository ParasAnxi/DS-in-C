#include<stdio.h>

int linearSearch(int arr[],int size,int key){
    for(int i = 0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int ans = linearSearch(arr,5,4);
    (ans == -1) ? printf("Element not found\n")
                    : printf("Element is present at index %d",ans);
}