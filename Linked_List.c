#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
   int data;
   struct Node *next;
};
struct Node *head = NULL;
struct Node *current = NULL;

void display(){
   struct Node *temp = head;
   printf("\n[");

   while(temp != NULL) {
      printf(" %d ",temp->data);
      temp = temp->next;
   }
   printf("]");
}

void insertAtHead(int data){

   struct Node *node = (struct Node*) malloc(sizeof(struct Node));
   node->data = data;
   node->next = head;
   head = node;
}
void insertAtTail(int data){

   struct Node *node = (struct Node*) malloc(sizeof(struct Node));
   node->data = data;
   struct Node *temp = head;

   while(temp->next != NULL)
      temp = temp->next;

   temp->next = node;
}
void insertAfterNode(struct Node *list, int data){
   struct Node *node = (struct Node*) malloc(sizeof(struct Node));
   node->data = data;
   node->next = list->next;
   list->next = node;
}
void deleteatbegin(){
   head = head->next;
}
void deleteatend(){
   struct Node *temp = head;
   while (temp->next->next != NULL)
      temp = temp->next;
   temp->next = NULL;
}
void deletenode(int key){
   struct Node *temp = head, *prev;
   if (temp != NULL && temp->data == key) {
      head = temp->next;
      return;
   }
   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL) return;
   prev->next = temp->next;
}
int searchlist(int key){
   struct Node *temp = head;
   while(temp != NULL) {
      if (temp->data == key) {
         return 1;
      }
      temp=temp->next;
   }
   return 0;
}
void main(){
   int k=0;
   insertAtHead(12);
   insertAtHead(22);
   insertAtTail(30);
   insertAtTail(44);
   insertAtTail(50);
   insertAfterNode(head->next->next, 33);
   printf("Linked List: ");

   display();
   deleteatbegin();
   deleteatend();
   deletenode(12);
   printf("\nLinked List after deletion: ");

   display();
   insertAtHead(4);
   insertAtHead(16);
   printf("\nUpdated Linked List: ");
   display();
   k = searchlist(16);
   if (k == 1)
      printf("\nElement is found");
   else
      printf("\nElement is not present in the list");
}