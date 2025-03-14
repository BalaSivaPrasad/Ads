#include <stdio.h>
#include <stdlib.h>

#define MAX 4 // Order-5 B-Tree (Max keys = 4)
#define MIN 2 // Minimum keys required

struct BTreeNode {
    int keys[MAX];
    int count;
    struct BTreeNode *child[MAX + 1];
};

struct BTreeNode *root = NULL;

// Create new node
struct BTreeNode* createNode(int key) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->keys[0] = key;
    node->count = 1;
    for (int i = 0; i <= MAX; i++)
        node->child[i] = NULL;
    return node;
}

// Insert function (Basic insertion without splitting)
struct BTreeNode* insert(struct BTreeNode* root, int key) {
    if (root == NULL)
        return createNode(key);
    
    if (root->count == MAX) {
        printf("Node full! Splitting not implemented.\n");
        return root;
    }
    
    int i = root->count - 1;
    while (i >= 0 && key < root->keys[i]) {
        root->keys[i + 1] = root->keys[i];
        i--;
    }
    root->keys[i + 1] = key;
    root->count++;
    return root;
}

// Delete function (Basic deletion, no rebalancing)
struct BTreeNode* deleteKey(struct BTreeNode *root, int key) {
    if (!root) return NULL;
    
    int i;
    for (i = 0; i < root->count; i++) {
        if (root->keys[i] == key) {
            for (int j = i; j < root->count - 1; j++)
                root->keys[j] = root->keys[j + 1];
            root->count--;
            return root;
        }
    }
    
    printf("Key not found!\n");
    return root;
}

// Inorder Traversal
void inorder(struct BTreeNode *root) {
    if (root) {
        for (int i = 0; i < root->count; i++)
            printf("%d ", root->keys[i]);
        printf("\n");
    }
}

int main() {
    int choice, key, n, insertKeys[10];
    
    while (1) {
        printf("\n1. Insert multiple values\n2. Delete one value\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter how many values to insert: ");
                scanf("%d", &n);
                printf("Enter %d values: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &insertKeys[i]);
                    root = insert(root, insertKeys[i]);
                }
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = deleteKey(root, key);
                break;
            case 3:
                printf("B-Tree Inorder Traversal: ");
                inorder(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
