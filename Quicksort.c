#include <stdio.h>
// **Function to perform partition** //
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // **First element as pivot** //
    int L = low;
    int R = high;
    while (L < R) {
        // **1st Condition: Move R left until finding an element smaller than pivot**
        while (arr[R] > pivot) {
            R--;
        }
        // **2nd Condition: Move L right until finding an element larger than pivot**
        while (L < R && arr[L] <= pivot) {
            L++;
        }
        // **Swap L and R elements if L < R**
        if (L < R) {
            int temp = arr[L];
            arr[L] = arr[R];
            arr[R] = temp;
        }
    }
    // **Place pivot in the correct position**
    arr[low] = arr[R];
    arr[R] = pivot;
    return R;
}
// **Quick Sort Function** //
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // **Get pivot position** //
        quickSort(arr, low, pivotIndex - 1); // **Sort left half** //
        quickSort(arr, pivotIndex + 1, high); // **Sort right half** //
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
