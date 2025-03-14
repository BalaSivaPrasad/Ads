#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100 // Maximum number of vertices
// Adjacency List Node
struct Node {
 int vertex;
 struct Node* next;
};
// Function to create a new node
struct Node* createNode(int v) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->vertex = v;
 newNode->next = NULL;
 return newNode;
}
// Function to add an edge to the graph (Undirected Graph)
void addEdge(struct Node* adjList[MAX_VERTICES], int src, int dest) {
 struct Node* newNode = createNode(dest);
 newNode->next = adjList[src];
 adjList[src] = newNode;
 newNode = createNode(src);
 newNode->next = adjList[dest];
 adjList[dest] = newNode;
}
// Function to perform BFS on the given graph
void BFS(struct Node* adjList[MAX_VERTICES], int start, int n) {
 bool visited[MAX_VERTICES] = {false};
 int queue[MAX_VERTICES], front = 0, rear = -1;
 visited[start] = true;
 queue[++rear] = start;
 printf("BFS Traversal: ");
 while (front <= rear) {
 int node = queue[front++];
 printf("%d ", node);
 struct Node* temp = adjList[node];
 while (temp != NULL) {
 if (!visited[temp->vertex]) {
 visited[temp->vertex] = true;
 queue[++rear] = temp->vertex;
 }
 temp = temp->next;
 }
 }
 printf("\n");
}
// Function to perform DFS recursively
void DFS(struct Node* adjList[MAX_VERTICES], int start, bool
visited[MAX_VERTICES]) {
 visited[start] = true;
 printf("%d ", start);
 struct Node* temp = adjList[start];
 while (temp != NULL) {
 if (!visited[temp->vertex]) {
 DFS(adjList, temp->vertex, visited);
 }
 temp = temp->next;
 }
}
// Function to initiate DFS from a given start node
void DFS_Wrapper(struct Node* adjList[MAX_VERTICES], int start, int n) {
 bool visited[MAX_VERTICES] = {false};
 printf("DFS Traversal: ");
 DFS(adjList, start, visited);
 printf("\n");
}
int main() {
 int n, e, src, dest, start;
 struct Node* adjList[MAX_VERTICES] = {NULL};
 // Input: Number of vertices and edges
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the number of edges: ");
 scanf("%d", &e);
 // Input: Edges of the graph
 printf("Enter the edges (src dest):\n");
 for (int i = 0; i < e; i++) {
 scanf("%d %d", &src, &dest);
 addEdge(adjList, src, dest);
 }
 // Input: Starting node for BFS
 printf("Enter the starting vertex for BFS: ");
 scanf("%d", &start);
 BFS(adjList, start, n);
 // Input: Starting node for DFS
 printf("Enter the starting vertex for DFS: ");
 scanf("%d", &start);
 DFS_Wrapper(adjList, start, n);
 return 0;
}
