#include <stdio.h>
#include <stdlib.h>
struct Job
{
 int id; // Job Id//
 int deadline; // Deadline of job//
 int profit; // Profit from job//
};
// **Comparator function to sort jobs by profit in descending order**//
int compare(const void *a, const void *b)
{
 struct Job *job1 = (struct Job *)a;
 struct Job *job2 = (struct Job *)b;
 return job2->profit - job1->profit; // Descending order of profit//
}
//** Function to find the job sequence that gives maximum profit**//
void jobSequencing(struct Job jobs[], int n)
{
 // Sort jobs by profit in descending order//
 qsort(jobs, n, sizeof(jobs[0]), compare);
 int result[n];
 int slot[n];
 // Initialize all time slots as free//
 for (int i = 0; i < n; i++) {
 slot[i] = -1;
 }
 int totalProfit = 0;
 int jobCount = 0;
 // **Iterate through all jobs**//
 for (int i = 0; i < n; i++)
 {
 // Find a free slot for this job (starting from the latest possible slot)//
 for (int j = jobs[i].deadline - 1; j >= 0; j--)
 {
 if (slot[j] == -1) {
 // If the slot is free, assign this job to the slot//
 slot[j] = i;
 totalProfit += jobs[i].profit;
 jobCount++;
 break;
 }
 }
 }
 printf("Job Sequence: ");
 for (int i = 0; i < n; i++) {
 if (slot[i] != -1) {
 printf("%d ", jobs[slot[i]].id);
 }
 }
 printf("\n");
 printf("Total Profit: %d\n", totalProfit);
}
int main()
{
 int n;
 printf("Enter the number of jobs: ");
 scanf("%d", &n);
 struct Job jobs[n];
 printf("Enter the job details (ID, Deadline, Profit):\n");
 for (int i = 0; i < n; i++) {
 printf("Job %d:\n", i + 1);
 printf("Enter ID: ");
 scanf("%d", &jobs[i].id);
 printf("Enter Deadline: ");
 scanf("%d", &jobs[i].deadline);
 printf("Enter Profit: ");
 scanf("%d", &jobs[i].profit);
 }
 //** Call the job sequencing function**//
 jobSequencing(jobs, n);
 return 0;
}
