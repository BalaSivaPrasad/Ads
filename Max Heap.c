#include <stdio.h>
#define MAX_SIZE 100
int maxHeap[MAX_SIZE];
int maxSize = 0;
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
void insertMaxHeap(int value) {
 int i = maxSize;
 maxHeap[maxSize++] = value;
 while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i])
{
 swap(&maxHeap[(i - 1) / 2], &maxHeap[i]);
 i = (i - 1) / 2;
 }
}
void displayHeap()
{
 for (int i = 0; i < maxSize; i++)
 printf("%d ", maxHeap[i]);
 printf("\n");
}
int main()
{
 int n, value;
 printf("Enter number of elements to insert: ");
 scanf("%d", &n);
 printf("Enter %d values: ", n);
 for (int i = 0; i < n; i++)
 {
 scanf("%d", &value);
 insertMaxHeap(value);
 }
 printf("Max Heap: ");
 displayHeap();
 return 0;
}
