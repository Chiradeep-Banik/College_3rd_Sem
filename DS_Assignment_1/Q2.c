//Q2. Reverse the array and store it in a new array REV

#include <stdio.h>

int* reverse_ar(int ar[],int ar_length,int rev[]){
    for (int i = 0; i < ar_length; i++){
        rev[i] = ar[ar_length-1-i];
    }
    return rev;
} 

void main(){
    int ar[5] = {1,2,3,4,5};
    int ar_length = sizeof(ar)/sizeof(ar[0]);
    printf("Before : ");
    for (int i = 0; i < ar_length; i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
    int REV[ar_length]; //declare array REV
    int* rev = reverse_ar(ar,ar_length,REV);
    printf("After : ");

    for (int i = 0; i < ar_length; i++){
        printf("%d ",rev[i]);
    }
    printf("\n");
}