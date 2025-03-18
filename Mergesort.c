#include <stdio.h>  
//** Merge function to merge two halves**//  
void merge(int arr[], int low, int mid, int high)  
{  
int n1 = mid - low + 1;  
int n2 = high - mid;  
int L[n1], R[n2];  
for (int i = 0; i < n1; i++)  
L[i] = arr[low + i];  
for (int j = 0; j < n2; j++)  
R[j] = arr[mid + 1 + j];  
int i = 0, j = 0, k = low;  
while (i < n1 && j < n2)  
{  
if (L[i] <= R[j]) {  
arr[k] = L[i];  
i++;  
} else  
{  
arr[k] = R[j];  
j++;  
}  
k++;  
}  
while (i < n1)  
{  
arr[k] = L[i];  
i++;  
k++;  
}  
while (j < n2)  
{  
arr[k] = R[j];  
j++;  
k++;  
}  
}  
// **Merge Sort function**//  
void mergeSort(int arr[], int low, int high) {  
if (low < high) {  
int mid = low + (high - low) / 2;  
mergeSort(arr, low, mid);  
mergeSort(arr, mid + 1, high);  
merge(arr, low, mid, high);  
}  
}  
// **Function to print the array**//  
void printArray(int arr[], int size) {  
for (int i = 0; i < size; i++)  
printf("%d ", arr[i]);  
printf("\n");  
}  
// **Main function**//  
int main()  
{  
int n;  
printf("Enter number of elements: ");  
scanf("%d", &n);  
int arr[n];  
printf("Enter %d elements: ", n);  
for (int i = 0; i < n; i++) {  
scanf("%d", &arr[i]);  
}  
mergeSort(arr, 0, n - 1);  
printf("Sorted array using Merge Sort: ");  
printArray(arr, n);  
return 0;  
} 
