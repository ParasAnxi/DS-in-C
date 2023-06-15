#include<stdio.h>   
#include<stdlib.h>  
struct Node   {  
    int data;   
    struct Node *next;  
};  
struct Node *front;  
struct Node *rear;   
void insert()  {  
    struct Node *ptr;  
    int item;   
      
    ptr = (struct Node *) malloc (sizeof(struct Node));  
    if(ptr == NULL)  {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  {   
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL){  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void delete ()  {  
    struct Node *ptr;  
    if(front == NULL)  {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  {  
    struct Node *ptr;  
    ptr = front;      
    if(front == NULL)  {  
        printf("\nEmpty queue\n");  
    }  
    else{
        printf("\nprinting values .....\n");  
        while(ptr != NULL)   {  
            printf("\n%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  
void main ()  
{  
    int choice;   
    while(choice != 4)   {     
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",& choice);  
        switch(choice)  {  
            case 1:  
            insert();  
            break;  
            case 2:  
            delete();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
