#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10 // Maximum number of vertices//
int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix//
bool visited[MAX_VERTICES]; // Visited array for DFS//
// Function to add an edge to the adjacency matrix//
void addEdge(int u, int v) {
 graph[u][v] = 1;
 graph[v][u] = 1; // Since the graph is undirected//
}
// BFS function//
void BFS(int start, int n) {
 bool visited[MAX_VERTICES] = {false};
 int queue[MAX_VERTICES], front = 0, rear = -1;
 visited[start] = true;
 queue[++rear] = start;
 printf("BFS Traversal: ");
 while (front <= rear) {
 int node = queue[front++];
 printf("%d ", node);
 for (int i = 0; i < n; i++) {
 if (graph[node][i] == 1 && !visited[i]) {
 visited[i] = true;
 queue[++rear] = i;
 }
 }
 }
 printf("\n");
}
// DFS function (recursive)//
void DFS(int node, int n) {
 if (visited[node]) return;
 visited[node] = true;
 printf("%d ", node);
 for (int i = 0; i < n; i++) {
 if (graph[node][i] == 1 && !visited[i]) {
 DFS(i, n);
 }
 }
}
void DFS_Wrapper(int start, int n) {
 for (int i = 0; i < n; i++) visited[i] = false; // Reset visited array
 printf("DFS Traversal: ");
 DFS(start, n);
 printf("\n");
}
int main() {
 int n, e, u, v, start;
 // Input number of vertices and edges//
 printf("Enter number of vertices: ");
 scanf("%d", &n);
 printf("Enter number of edges: ");
 scanf("%d", &e);
 // Initialize adjacency matrix with 0//
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 graph[i][j] = 0;
 }
 }
 // Input edges//
 printf("Enter edges (u v):\n");
 for (int i = 0; i < e; i++) {
 scanf("%d %d", &u, &v);
 addEdge(u, v);
 }
 // Perform BFS//
 printf("Enter starting vertex for BFS: ");
 scanf("%d", &start);
 BFS(start, n);
 // Perform DFS//
 printf("Enter starting vertex for DFS: ");
 scanf("%d", &start);
 DFS_Wrapper(start, n);
 return 0;
}
