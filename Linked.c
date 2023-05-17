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
 void insertAtTail(int data){
        struct Node *temp,*curr;
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next =NULL;
        
        if(head==NULL){
            head=temp;
            temp->next = NULL;
        }
        else{
                curr=head;
                while(curr->next !=NULL){
                        curr=curr->next ;
                }
                curr->next = temp;
        }
}
int count(){
    struct Node* curr;
    curr = head;
    int count = 0;
    if(head == NULL){
        return 0;
    }
    else{
        while(curr->next!=NULL){
            count++;
            curr = curr->next;
        }
    }
    return count + 1;
}
void insertAtPos(int data,int pos){
    struct Node* temp, *curr ,*prev;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(pos == 1){
        insertAtHead(data);
    }
    if(pos == count()+1){
        insertAtTail(data);
    }
    else{
        prev = head;
        for(int i = 1;i<pos-1;i++){
            prev = prev->next;
            if(prev == NULL){
                printf("Check pos \n");
                return;
            }
        }
        curr = prev->next;
        prev->next = temp;
        temp->next = curr;
    }
}
void deleteFront(){
    struct Node* temp;
    if(head == NULL){
        printf("No Nodes\n");
        return;
    }
    temp = head;   
    head = head->next;
    free(temp);
}
void deleteLast(){
    struct Node* temp,*curr;
    if(head == NULL){
        printf("No nodes\n");
        return;
    }
    temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    curr = temp->next;
    temp->next = NULL;
    free(curr);
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
    struct Node* curr ,*prev;
    prev = temp->next;
    curr = temp->next->next;
    temp->next = curr;
    prev->next = NULL;
    free(prev);
}

int searchlist(int key){
  struct Node *temp = head;
  int index = 1;
  while (temp!= NULL){
      if (temp->data == key){
	  return index;
	}
      temp = temp->next;
      index++;
    }
  return -1;
}
void display(){
   struct Node *temp = head;
   while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
   }
}
int main(){
    
    insertAtTail(60);
    insertAtHead(70);
    insertAtHead(90);
    insertAtTail(34);
    display();
    printf("\n");

    insertAtPos(100,3);
    display();
    printf("\n");

    insertAtPos(200,5);
    display();
    printf("\n");

    // deleteFront();
    // display();
    // printf("\n");

    // deleteLast();
    // display();
    // printf("\n");

    // deleteLast();
    // display();
    // printf("\n");

    deletePos(5);
    display();
    printf("\n");

    printf("found at : %d",searchlist(90));
    printf("\n");
    
    printf("no of nodes %d", count());
}
