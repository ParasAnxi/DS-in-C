#include <stdio.h>
#define SIZE 10

int arr[SIZE], front = -1, rear = -1;

void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
    front = 0;
    rear++;
    arr[rear] = value;
    printf("\nInserted -> %d", value);
  }
}
void deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", arr[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}
void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", arr[i]);
  }
  printf("\n");
}
int main() {
  deQueue();
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  enQueue(6);

  display();

  deQueue();

  display();

  return 0;
}

