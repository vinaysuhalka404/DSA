#include <stdio.h>

void binary_search(int* arr, int min, int max){
    int key, mid, index=-1;
    printf("Enter a number to be searched :");
    scanf("%d", &key);
    
    while(min <= max){
        mid = min + (max-min) / 2;
        if(arr[mid] == key){
            index = mid;
            break;
        }
        if(arr[mid] > key){
            max = mid;
        }else{
            min = mid + 1;
        }
    }
    
    if(index > -1){
        printf("Element found at index :%d", index);
    }else{
        printf("Element not found");
    }
}

int main() {
   int arr[] = {2,3,4,5,6,8,9,11,15,17,21,32,44,55,61,78};
   int size = sizeof(arr) / sizeof(arr[0]);
   binary_search(arr, 0, size-1);
   return 0;
}