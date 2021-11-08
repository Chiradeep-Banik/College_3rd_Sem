//Implementation of Bubble sort

#include <stdio.h>

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int* bubble_sort(int* ar,int len){
    for(int i = 0;i<len;i++){
        int swapped = -1;
        for (int j = 0; j < len-i; j++){
            if(ar[j]>ar[j+1]){
                swap(&ar[j],&ar[j+1]);
                swapped = 1;
            }
        }
        if(swapped == -1){
            break;
        }
    }
    return ar;
}

void main(){
    int arr[] = {3,44,38,5,44};
    int len = sizeof(arr)/sizeof(arr[0]);
    int* sorted_ar = bubble_sort(arr,len);
    for (int i = 0; i < len; i++){
        printf(" %d", sorted_ar[i]);
    }
    printf("\n");
}