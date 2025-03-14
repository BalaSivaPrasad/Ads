#include <stdio.h>
#include <stdlib.h>
// Node structure for AVL tree//
struct Node {
 int key;
 struct Node *left, *right;
 int height;
};
// Function to get the height of a node//
int height(struct Node *N)
{
 return (N == NULL) ? 0 : N->height;
}
// Function to get the balance factor of a node//
int getBalance(struct Node *N)
{
 return (N == NULL) ? 0 : height(N->left) - height(N->right);
}
// Function to create a new node//
struct Node* newNode(int key) {
 struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 node->key = key;
 node->left = node->right = NULL;
 node->height = 1;
 return node;
}
// Right rotation//
struct Node* rightRotate(struct Node *y) {
 struct Node *x = y->left;
 struct Node *T2 = x->right;
 x->right = y;
 y->left = T2;
 y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
 x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
 return x;
}
// Left rotation//
struct Node* leftRotate(struct Node *x) {
 struct Node *y = x->right;
 struct Node *T2 = y->left;
 y->left = x;
 x->right = T2;
 x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
 y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
 return y;
}
// Insert a node into the AVL tree//
struct Node* insert(struct Node* node, int key) {
 if (node == NULL) return newNode(key);
 if (key < node->key)
 node->left = insert(node->left, key);
 else if (key > node->key)
 node->right = insert(node->right, key);
 else
 return node; // No duplicate keys//
 node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) :
height(node->right));
 int balance = getBalance(node);
 // Left Left Case//
 if (balance > 1 && key < node->left->key)
 return rightRotate(node);
 // Right Right Case//
 if (balance < -1 && key > node->right->key)
 return leftRotate(node);
 // Left Right Case//
 if (balance > 1 && key > node->left->key) {
 node->left = leftRotate(node->left);
 return rightRotate(node);
 }
 // Right Left Case//
 if (balance < -1 && key < node->right->key) {
 node->right = rightRotate(node->right);
 return leftRotate(node);
 }
 return node;
}
// Find the node with the smallest key (used in deletion)//
struct Node* minValueNode(struct Node* node) {
 struct Node* current = node;
 while (current->left != NULL)
 current = current->left;
 return current;
}
// Delete a node from the AVL tree//
struct Node* deleteNode(struct Node* root, int key) {
 if (root == NULL) return root;
 if (key < root->key)
 root->left = deleteNode(root->left, key);
 else if (key > root->key)
 root->right = deleteNode(root->right, key);
 else {
 if ((root->left == NULL) || (root->right == NULL)) {
 struct Node *temp = root->left ? root->left : root->right;
 if (temp == NULL) {
 temp = root;
 root = NULL;
 } else
 *root = *temp;
 free(temp);
 } else {
 struct Node* temp = minValueNode(root->right);
 root->key = temp->key;
 root->right = deleteNode(root->right, temp->key);
 }
 }
 if (root == NULL) return root;
 root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) :
height(root->right));
 int balance = getBalance(root);
 // Left Left Case//
 if (balance > 1 && getBalance(root->left) >= 0)
 return rightRotate(root);
 // Left Right Case//
 if (balance > 1 && getBalance(root->left) < 0) {
 root->left = leftRotate(root->left);
 return rightRotate(root);
 }
 // Right Right Case//
 if (balance < -1 && getBalance(root->right) <= 0)
 return leftRotate(root);
 // Right Left Case//
 if (balance < -1 && getBalance(root->right) > 0) {
 root->right = rightRotate(root->right);
 return leftRotate(root);
 }
 return root;
}
// Inorder traversal of the AVL tree//
void inorder(struct Node *root) {
 if (root != NULL) {
 inorder(root->left);
 printf("%d ", root->key);
 inorder(root->right);
 }
}
// Main function//
int main() {
 struct Node *root = NULL;
 int choice, value, n, i;
 while (1) {
 printf("\n1. Insert multiple values\n2. Delete\n3. Display Inorder\n4. Exit\nEnter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter number of values to insert: ");
 scanf("%d", &n);
 printf("Enter %d values: ", n);
 for (i = 0; i < n; i++) {
 scanf("%d", &value);
 root = insert(root, value);
 }
 break;
 case 2:
 printf("Enter value to delete: ");
 scanf("%d", &value);
 root = deleteNode(root, value);
 break;
 case 3:
 printf("Inorder Traversal: ");
 inorder(root);
 printf("\n");
 break;
 case 4:
 exit(0);
 default:
 printf("Invalid choice! Try again.\n");
 }
 }
 return 0;
}
