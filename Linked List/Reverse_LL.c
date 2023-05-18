#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtHead(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data; 
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    } 
    else{
    temp->next = head;
    head = temp;
    }
}
void display(){
   struct Node *temp = head;
   while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
   }
}
struct Node* reverseLinkedList(){
    struct Node* prev, *forward,*curr;
    if(head==NULL || head->next==NULL){
		return head;
	}
    prev = NULL;
    forward = NULL;
    curr = head;

    while(curr!=NULL){
        forward=curr->next;
        curr->next = prev;
        prev=curr;
        curr=forward;
    }
}
// void reverse(struct Node* head,struct Node* curr,struct Node* prev){
//     if(curr==NULL){
//         head=prev;
//         return;
//     }
//     struct Node* forward = curr->next;
//     reverse(head,forward,curr);
//     curr->next = prev;
// }
struct Node* reverse(struct Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    struct Node* List = reverse(head->next);
    head->next->next = head;
    head->next= NULL;
    return List;
}
int main(){
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);
    insertAtHead(50);
    display();
    printf("\n");

    reverse(head);
    display();
}