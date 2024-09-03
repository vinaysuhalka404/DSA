#include <stdio.h>

void traverse(int *arr, int size){
    int i;
    printf("\n\nCurrent Elements in Array:-\n");
    for(i=0;i<size;i++){
        printf("\t%d", arr[i]);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;
    while(i <= j){
        while(i <= high && arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i <= j){
            // Swap elements at i and j
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    temp = arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void quick_sort(int arr[], int low, int high){
    int pivot;
    if(low < high){
        pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot-1);
        quick_sort(arr, pivot+1, high);
    }
}

int main(void){
    int arr[] = {3,5,3,6,8,2,4,65,7,3,2,5,3,5,67,84,3,3,22,4,4,566,432,53};
    int size = sizeof(arr) / sizeof(arr[0]);
    traverse(arr, size);
    quick_sort(arr, 0, size-1);
    traverse(arr, size);
    return 0;
}