#include <stdio.h>  
#include <stdlib.h>  
  
struct Node {  
  int data;  
  struct Node *right;  
  struct Node *left;  
};  
  
struct Node* node(int x){  
  struct Node *temp;  
  temp = malloc(sizeof(struct Node));  
  temp->data = x;  
  temp->left = NULL;  
  temp->right = NULL;  
  
  return temp;  
}  
  
struct Node* search(struct Node * root, int x){  
  if (root == NULL || root->data == x)  
    return root;  
  else if (x > root->data)  
    return search(root->right, x);  
  else  
    return search(root->left, x);  
}  
  
struct Node* insert(struct Node * root, int x){  
  if (root == NULL)  
    return node(x);  
  else if (x > root->data)  
    root->right = insert(root->right, x);  
  else   
    root -> left = insert(root->left, x);  
  return root;  
}  
struct Node* find_minimum(struct Node * root) {  
  if (root == NULL)  
    return NULL;  
  else if (root->left != NULL)  
    return find_minimum(root->left);  
  return root;  
}  
  
struct Node* delete(struct Node * root, int x) {  
  
  if (root == NULL)  
    return NULL;  
  if (x > root->data)  
    root->right = delete(root->right, x);  
  else if (x < root->data)  
    root->left = delete(root->left, x);  
  else {  
    if (root->left == NULL && root->right == NULL){  
      free(root);  
      return NULL;  
    }  
    else if (root->left == NULL || root->right == NULL){  
      struct Node *temp;  
      if (root->left == NULL)  
        temp = root->right;  
      else  
        temp = root->left;  
      free(root);  
      return temp;  
    }  
    else {  
      struct Node *temp = find_minimum(root->right);  
      root->data = temp->data;  
      root->right = delete(root->right, temp->data);  
    }  
  }  
  return root;  
}  
  
void inorder(struct Node *root){  
  if (root != NULL)   
  {  
    inorder(root->left);   
    printf("%d ", root->data);   
    inorder(root->right);   
  }  
}  
int main() {  
  struct Node *root;  
  root = node(20);  
  insert(root, 5);  
  insert(root, 1);  
  insert(root, 15);  
  insert(root, 9);  
  insert(root, 7);  
  insert(root, 12);  
  insert(root, 30);  
  insert(root, 25);  
  insert(root, 40);  
  insert(root, 45);  
  insert(root, 42);  
  
  printf("InOrder\n");
  inorder(root);  
  printf("\n"); 
  return 0;  
}  