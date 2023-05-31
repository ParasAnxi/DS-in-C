#include<stdio.h>

int linearSearch(int arr[],int size,int key){
    for(int i = 0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[5] = {1,2,3,4,5};

    if(linearSearch(arr,5,10)){
        printf("Element found\n");
    }
    else{
        printf("Element not found\n");
    }
}