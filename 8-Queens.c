#include <stdio.h>
#include <stdbool.h>
#define N 8 // Set the size of the board (can be changed to any N)//
int board[N][N];
// Function to print the solution board//
void printBoard() {
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < N; j++) {
 printf("%d ", board[i][j]);
 }
 printf("\n");
 }
 printf("\n");
}
// Function to check if it's safe to place a queen at board[row][col]//
bool isSafe(int row, int col)
{
 // Check the column for other queens//
 for (int i = 0; i < row; i++) {
 if (board[i][col] == 1) {
 return false;
 }
 }
 // Check the upper left diagonal//
 for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
 if (board[i][j] == 1) {
 return false;
 }
 }
 // Check the upper right diagonal//
 for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
 if (board[i][j] == 1) {
 return false;
 }
 }
 return true;
}
// Function to solve the N-Queens problem using Backtracking//
bool solveNQueens(int row)
{
 // If all queens are placed//
 if (row >= N) {
 return true;
 }
 // Try all columns for the current row//
 for (int col = 0; col < N; col++)
{
 // Check if it's safe to place the queen//
 if (isSafe(row, col))
 {
 // Place the queen//
 board[row][col] = 1;
 // Recur to place the queen in the next row//
 if (solveNQueens(row + 1)) {
 return true;
 }
 // If placing queen in current position doesn't lead to a solution,
 backtrack and remove the queen//
 board[row][col] = 0;
 }
 }
 // If no position in this row works, return false to trigger backtracking//
 return false;
}
int main() {
 // Initialize the board with 0s (empty)//
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < N; j++) {
 board[i][j] = 0;
 }
 }
 if (solveNQueens(0)) {
 printf("Solution found:\n");
 printBoard();
 } else {
 printf("No solution exists.\n");
 }
 return 0;
}
