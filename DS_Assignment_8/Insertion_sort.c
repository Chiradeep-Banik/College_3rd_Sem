//Implementation of Insertion sort

#include <stdio.h>

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int* insertion_sort(int* ar,int len){
    for (int  i = 1; i < len; i++){
        int key = ar[i];
        for (int j = 0; j <= i; j++){
            if(ar[j]>ar[i]){
                swap(&ar[i],&ar[j]);
            }
        }
    }
    
    return ar;
}

void main(){
    int arr[] = {3,44,38,5,44};
    int len = sizeof(arr)/sizeof(arr[0]);
    int* sorted_ar = insertion_sort(arr,len);
    for (int i = 0; i < len; i++){
        printf(" %d", sorted_ar[i]);
    }
    printf("\n");
}