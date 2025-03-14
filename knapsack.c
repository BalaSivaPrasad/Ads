#include <stdio.h>
int knapsack(int W, int wt[], int val[], int n)
{
 int dp[n+1][W+1]; //** Create a Dynamic Programming table to store the maximum profit for each subproblem**//
 for (int i = 0; i <= n; i++) {
 for (int w = 0; w <= W; w++) {
 if (i == 0 || w == 0) {
 dp[i][w] = 0; // Base case: no items or capacity is 0//
 }
 else if (wt[i-1] <= w) {
 // If including the item is possible, take the maximum of including or excluding it//
 dp[i][w] = (val[i-1] + dp[i-1][w-wt[i-1]] > dp[i-1][w]) ?
 val[i-1] + dp[i-1][w-wt[i-1]] : dp[i-1][w];
 }
 else {
 // Otherwise, just exclude the current item//
 dp[i][w] = dp[i-1][w];
 }
 }
 }
 return dp[n][W]; // The maximum profit is stored at dp[n][W]//
}
int main()
{
 int n, W;
 printf("Enter the number of items: ");
 scanf("%d", &n);
 printf("Enter the capacity of the knapsack: ");
 scanf("%d", &W);
 int val[n], wt[n];
 printf("Enter the values (profits) and weights of the items:\n");
 for (int i = 0; i < n; i++) {
 printf("Item %d - Value (Profit): ", i+1);
 scanf("%d", &val[i]); // Profit value
 printf("Item %d - Weight: ", i+1);
 scanf("%d", &wt[i]); // Weight//
 }
 // Call knapsack function to find the maximum profit that can be obtained//
 int result = knapsack(W, wt, val, n);
 printf("The maximum profit that can be obtained is: %d\n", result);
 return 0;
}
