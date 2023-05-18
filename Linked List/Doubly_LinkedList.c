#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
void insertAtHead(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(int data){
    struct Node* temp ,*curr;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr; 
    }
}
int count(){
    struct Node* curr;
    curr = head;
    int cnt = 0;
    if(head == NULL){
        return 0;
    }
    else{
        while(curr->next!=NULL){
            cnt++;
            curr = curr->next;
        }
    }
    return cnt+1;
}
void insertAtPos(int data,int pos){
    struct Node* temp, *curr ,*pre;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(pos == 1){
        insertAtHead(data);
    }
    if(pos == count()+1){
        insertAtTail(data);
    }
    else{
        pre = head;
        for(int i = 1;i<pos-1;i++){
            pre = pre->next;
            if(pre == NULL){
                printf("Check pos\n");
                return;
            }
        }
        curr = pre->next;
        pre->next = temp;
        temp->next = curr;
        curr->prev = temp;
    }
}
void deleteFront(){
    struct Node* temp,*curr;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        temp = head;
        curr = head->next;
        curr->prev = NULL;
        head = curr;
        free(temp);
    }
}
void deleteLast(){
    struct Node* temp,*curr;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        curr = temp->next;
        temp->next = NULL;
        free(curr);
    }
}
void deletePos(int pos){
    if(pos == 1){
        deleteFront();
    }
    if(pos == count()){
        deleteLast();
    }
    struct Node* temp = head;
    if(head == NULL){
        printf("No nodes\n");
    }
    for(int i = 1;i<pos-1;i++){
        temp = temp->next;
    }
    struct Node* curr,*pre;
    pre = temp->next;
    curr = temp->next->next;
    temp->next = curr;
    pre->next = NULL;
    pre->prev = NULL;
    free(pre);
}
void display(){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main(){
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtTail(40);
    insertAtTail(50);
    display();
    printf("\n");
    // deleteFront();
    // printf("%d",head->data);
    // deleteLast();
    // deleteLast();
    // deleteLast();
    // display();
    insertAtPos(5,5);
    display();
    printf("\n");
    deletePos(3);
    deletePos(4);
    display();
    // printf("%d",count());
}