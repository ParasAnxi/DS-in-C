#include<stdio.h>
#include<stdlib.h>
#define size 10
int top = -1;
int arr[size];

void push(){
    if(top == size-1){
        printf("Overflow\n");
    }
    else{
        int x;
        printf("Enter the element : \n");
        scanf("%d",&x);
        top++;
        arr[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Underflow\n");
    }
    else{
        top--;
    }
}

int peek(){
    if(top == -1){
        printf("Empty stack\n");
    }
    else{
        printf("%d",arr[top]);
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top == size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        for(int i = top;i>=0;i--){
            printf("%d ",arr[i]);
        }printf("\n");
    }
}
int main(){
    int choice;
    while(1){
        printf("1 for push\n2 for pop\n3 for peek\n4 for empty\n5 for full\n6 for display\n7 for exit\n");
        printf("Enter operation to perform : ");
        printf("\n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            push();
            printf("\n");
            break;
        case 2:
            pop();
            printf("\n");
            break;
        case 3:
            peek();
            printf("\n");
            break;
        case 4:
            if(isEmpty()){
                printf("Stack is empty\n");
            }
            else{
                printf("stack is not empty\n");
            }
            printf("\n");
            break;
        case 5:
            if(isFull()){
                printf("Stack is full\n");
            }
            else{
                printf("stack is not full\n");
            }
            printf("\n");
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;

        default:
        printf("Invalid choice\n");
            break;
        }
    }
}