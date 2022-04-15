//Implementation of Selection sort

#include <stdio.h>

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int* selection_sort(int* ar,int len){
    for (int i = 0; i < len; i++){
        int lowest_index = i;
        for (int j = i+1; j < len; j++){
            if(ar[j]<ar[lowest_index]){
                swap(&ar[j],&ar[lowest_index]);
            }
        }
    }
    return ar;
}

void main(){
    int arr[] = {3,44,38,5,44};
    int len = sizeof(arr)/sizeof(arr[0]);
    int* sorted_ar = selection_sort(arr,len);
    for (int i = 0; i < len; i++){
        printf(" %d", sorted_ar[i]);
    }
    printf("\n");
}