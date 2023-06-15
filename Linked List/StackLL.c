#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*top,*top1,*temp;

int count = 0;
void push(int data){
     if (top == NULL){
        top =(struct Node*)malloc(1*sizeof(struct Node));
        top->next = NULL;
        top->data = data;
    }
    else{
        temp =(struct Node*)malloc(1*sizeof(struct Node));
        temp->next = top;
        temp->data = data;
        top = temp;
    }
    count++;
}

int pop() {
     top1 = top;
    if (top1 == NULL){
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->next;
    int popped = top->data;
    free(top);
    top = top1;
    count--;
    return popped;
}

void display() {
    top1 = top;
    if (top1 == NULL){
        printf("\nStack Underflow\n");
        return;
    }
    printf("The stack is \n");
    while (top1 != NULL){
        printf("%d--->", top1->data);
        top1 = top1->next;
    }
    printf("NULL\n\n");
}

int main() {
    printf("paras Bhandari G1 76\n");
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}