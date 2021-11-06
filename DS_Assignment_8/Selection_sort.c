//Implementation of Selection sort

#include <stdio.h>
#include <stdlib.h>

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
    int arr[5] = {3,44,38,5,44};
    int* sorted_ar = selection_sort(arr,5);
    for (int i = 0; i < 5; i++){
        printf("%d\n", sorted_ar[i]);
    }
}