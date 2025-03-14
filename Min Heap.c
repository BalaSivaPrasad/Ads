#include <stdio.h>
#define MAX_SIZE 100
int minHeap[MAX_SIZE];
int minSize = 0;
void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}
void insertMinHeap(int value)
{
 int i = minSize;
 minHeap[minSize++] = value;
 while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i])
 {
 swap(&minHeap[(i - 1) / 2], &minHeap[i]);
 i = (i - 1) / 2;
 }
}
void displayHeap() {
 for (int i = 0; i < minSize; i++)
 printf("%d ", minHeap[i]);
 printf("\n");
}
int main() {
 int n, value;
 printf("Enter number of elements to insert: ");
 scanf("%d", &n);
 printf("Enter %d values: ", n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &value);
 insertMinHeap(value);
 }
 printf("Min Heap: ");
 displayHeap();
 return 0;
}
