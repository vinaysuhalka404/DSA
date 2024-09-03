#include <stdio.h>

void insertion_sort(int *arr, int size){
  
    int i, j, key;
    for(i=1; i<size; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void traverse(int *arr, int size){
    int i;
    printf("\n\nCurrent Elements in Array:-\n");
    for(i=0;i<size;i++){
        printf("\t%d", arr[i]);
    }
}

int main(void){
    int arr[] = {3,5,3,6,8,2,4,65,7,3,2,5,3,5,67,84,3,3,22,4,4,566,432,53};
    int size = sizeof(arr) / sizeof(arr[0]);
    traverse(arr, size);
    insertion_sort(arr, size);
    traverse(arr, size);
    return 0;
}