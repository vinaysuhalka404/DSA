#include <stdio.h>
#include <stdlib.h> // For malloc and free

void traverse(int *arr, int size){
    int i;
    printf("\n\nCurrent Elements in Array:-\n");
    for(i = 0; i < size; i++){
        printf("\t%d", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high){
    int i, j, k;
    int size1 = mid - low + 1;
    int size2 = high - mid;
    
    // Create temporary arrays
    int *left = (int *)malloc(size1 * sizeof(int));
    int *right = (int *)malloc(size2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (i = 0; i < size1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < size2; j++)
        right[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[low..high]
    i = 0; // Initial index of left array
    j = 0; // Initial index of right array
    k = low; // Initial index of merged array
    while (i < size1 && j < size2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    // Copy the remaining elements of left[], if any
    while (i < size1) {
        arr[k++] = left[i++];
    }
    
    // Copy the remaining elements of right[], if any
    while (j < size2) {
        arr[k++] = right[j++];
    }
    
    // Free the temporary arrays
    free(left);
    free(right);
}

void merge_sort(int arr[], int low, int high){
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(void){
    int arr[] = {3,5,3,6,8,2,4,65,7,3,2,5,3,5,67,84,3,3,22,4,4,566,432,53};
    int size = sizeof(arr) / sizeof(arr[0]);
    traverse(arr, size);
    merge_sort(arr, 0, size - 1);
    traverse(arr, size);
    return 0;
}
