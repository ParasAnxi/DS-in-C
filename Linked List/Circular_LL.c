#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtHead(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        temp->data = data;
        temp->next = temp;
        head = temp;
    }
    else{
        temp->data = data;
        temp->next = head->next;
        head->next = temp;
    }
}
void display(){
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        struct Node* temp;
        temp = head->next;
        do{
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp!=head->next);
    }
}

int main(){
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);
    insertAtHead(50);
    insertAtHead(60);
    display();
 
    return 0;
}