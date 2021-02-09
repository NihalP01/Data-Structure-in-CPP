#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("-> %d", root->item);
  inorderTraversal(root->right);
}

void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("-> %d", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("-> %d", root->item);
}

struct node* RootNode(root_value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = root_value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

struct node* insertLeft(struct node* root, int left_value) {
  root->left = RootNode(left_value);
  return root->left;
}

struct node* insertRight(struct node* root, int value) {
  root->right = RootNode(value);
  return root->right;
}

int main() {
    int root_value;
    int left_value;
    int right_value;
    
printf("Enter Root node: ");
scanf("%d",&root_value);

printf("Enter Left node: ");
scanf("%d",&left_value);

printf("Enter Right node: ");
scanf("%d",&right_value);
  struct node* root = RootNode(root_value);
  insertLeft(root, left_value);
  insertRight(root, right_value);
  // insertLeft(root->left, left_value);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
  printf("\n");
}