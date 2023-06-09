#include <stdio.h>
#include <stdlib.h>
#define SIZE 500

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node** Queue(int* front, int* rear){
	struct Node** queue = (struct Node**)malloc(sizeof(struct node*) * SIZE);
	*front = *rear = 0;
	return queue;
}
void enQueue(struct Node** queue, int* rear,struct Node* node){
	queue[*rear] = node;
	(*rear)++;
}
struct Node* deQueue(struct Node** queue, int* front){
	(*front)++;
	return queue[*front - 1];
}

void LevelOrder(struct Node* root){
	int rear, front;
	struct Node** queue = Queue(&front, &rear);
	struct Node* temp_node = root;

	while (temp_node) {
		printf("%d ", temp_node->data);

		if (temp_node->left)
			enQueue(queue, &rear, temp_node->left);

		if (temp_node->right)
			enQueue(queue, &rear, temp_node->right);

		temp_node = deQueue(queue, &front);
	}
}

void inorderTraversal(struct Node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
  if (root == NULL) return;
  printf("%d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->data);
}

struct Node* cons(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct Node* insertLeft(struct Node* root, int data) {
  root->left = cons(data);
  return root->left;
}

struct Node* insertRight(struct Node* root, int data) {
  root->right = cons(data);
  return root->right;
}

int main(){
  struct Node* root = cons(1);
  insertLeft(root, 4);
  insertRight(root, 6);
  insertLeft(root->left, 42);
  insertRight(root->left, 3);
  insertLeft(root->right, 2);
  insertRight(root->right, 33);

  printf("LevelOrder traversal \n");
  LevelOrder(root);

  printf("\nInorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);


  printf("\nPostorder traversal \n");
  postorderTraversal(root);

}