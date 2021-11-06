//Implementation of Insertion sort

#include <stdio.h>
#include <stdlib.h>

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int* insertion_sort(int* ar,int len){

    return ar;
}

void main(){
    int arr[5] = {3,44,38,5,44};
    int* sorted_ar = insertion_sort(arr,5);
    for (int i = 0; i < 5; i++){
        printf("%d\n", sorted_ar[i]);
    }
}