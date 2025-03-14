#include <stdio.h>
int maxProfit = 0; // Global variable to store maximum profit//
// Backtracking function to find the maximum profit//
void knapsack(int W, int wt[], int val[], int n, int index, int currentProfit, int currentWeight)
{
 if (index == n)
 {
 if (currentWeight <= W && currentProfit > maxProfit)
 {
 maxProfit = currentProfit;
 }
 return;
 }
 // Include the current item if weight allows//
 if (currentWeight + wt[index] <= W) {
 knapsack(W, wt, val, n, index + 1, currentProfit + val[index], currentWeight +
wt[index]);
 }
 // Exclude the current item//
 knapsack(W, wt, val, n, index + 1, currentProfit, currentWeight);
}
int main() {
 int n, W;
 printf("Enter the number of items: ");
 scanf("%d", &n);
 printf("Enter the capacity of the knapsack: ");
 scanf("%d", &W);
 int val[n], wt[n];
 printf("Enter the values (profits) and weights of the items:\n");
 for (int i = 0; i < n; i++) {
 printf("Item %d - Value: ", i+1);
 scanf("%d", &val[i]);
 printf("Item %d - Weight: ", i+1);
 scanf("%d", &wt[i]);
 }
 // Call the knapsack function//
 knapsack(W, wt, val, n, 0, 0, 0);
 printf("The maximum profit that can be obtained is: %d\n", maxProfit);
 return 0;
}
