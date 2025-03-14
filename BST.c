#include <stdio.h>
#include <stdlib.h>
// **Node structure for BST**//
struct Node
{
 int key;
 struct Node* left;
 struct Node* right;
};
// **Function to create a new node**//
struct Node* createNode(int key)
{
 struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 node->key = key;
 node->left = NULL;
 node->right = NULL;
 return node;
}
// **Function to insert a key into the BST**//
struct Node* insert(struct Node* root, int key)
{
 if (root == NULL)
 return createNode(key);

 if (key < root->key)
 root->left = insert(root->left, key);
 else if (key > root->key)
 root->right = insert(root->right, key);
 return root;
}
//** Function to perform in-order traversal of the BST**//
void inOrder(struct Node* root)
{
 if (root != NULL) {
 inOrder(root->left);
 printf("%d ", root->key);
 inOrder(root->right);
 }
}
// **Function to find the minimum value node in the BST**//
struct Node* findMin(struct Node* root)
{
 while (root->left != NULL)
 root = root->left;
 return root;
}
//** Function to delete a key from the BST**//
struct Node* deleteNode(struct Node* root, int key)
{
 if (root == NULL)
 return root;
 if (key < root->key)
 root->left = deleteNode(root->left, key);
 else if (key > root->key)
 root->right = deleteNode(root->right, key);
 else {
 //** Node with only one child or no child**//
 if (root->left == NULL)
 {
 struct Node* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 struct Node* temp = root->left;
 free(root);
 return temp;
 }
 // **Node with two children: Get the in-order successor**//
 struct Node* temp = findMin(root->right);
 // **Replace the current node's key with the in-order successor's key**//
 root->key = temp->key;
 //** Delete the in-order successor**//
 root->right = deleteNode(root->right, temp->key);
 }
 return root;
}
int main()
{
 struct Node* root = NULL;
 int n, key, deleteKey;
 printf("Enter the number of elements to insert: ");
 scanf("%d", &n);
 printf("Enter %d elements:\n", n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &key);
 root = insert(root, key);
 }
 // **Perform in-order traversal**//
 printf("In-order traversal of the BST: ");
 inOrder(root);
 printf("\n");
 printf("Enter the key to delete: ");
 scanf("%d", &deleteKey);
 root = deleteNode(root, deleteKey);
 // **Perform in-order traversal after deletion**//
 printf("In-order traversal of the BST after deletion: ");
 inOrder(root);
 printf("\n");
 return 0;
}
