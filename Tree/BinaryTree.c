#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

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

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);


  printf("\nPostorder traversal \n");
  postorderTraversal(root);

}