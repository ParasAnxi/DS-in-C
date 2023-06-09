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
void insertAtTail(int data){
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
        head = temp;
    }
}
void insertAtPos(int data,int pos){
    struct Node *temp,*node;
    temp = head->next;
    do{
        if(temp->data == pos){
            node = (struct Node*)malloc(sizeof(struct Node));
            node->data = data;
            node->next = temp->next;
            temp->next = node;

            if(temp == head)
                head = node;
            break;
        }
        else{
            temp = temp->next;
        }
    }while(temp!=head->next);
}
void deleteFirst(){
    struct Node* temp;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}
void deleteLast(){
    struct Node* temp, *t;
    if(head == NULL){
        printf("List is empty\n");
    }
    temp = head->next;  
    while(temp->next!=head){
        temp = temp->next;
    }
    t = head;
    temp->next = head->next;
    head = temp;
    free(t);
}
void deleteAtPos(int pos){
    int i = 1;
    struct Node* temp,*position;
    temp = head->next;

    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        position = temp->next;
        temp->next = position->next;

        free(position);
    }
}
int count(){
    int cnt = 0;
    struct Node* curr = head;

    do{
        curr = curr->next;
        cnt++;
    }while(curr!=head);
    return cnt;
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
    insertAtTail(70);
    insertAtTail(80);
    insertAtTail(90);
    insertAtPos(100,80);
    display();
    printf("\n");
    deleteFirst();
    display();
    printf("\n");
    deleteFirst();
    display();
    printf("\n");
    
    deleteLast();
    display();
    printf("\n");
    deleteLast();
    display();
    printf("\n");
    deleteAtPos(3);
    display();
    printf("\n");
    printf("%d",count());
    return 0;
}