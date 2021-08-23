//Q3. Find the largest from an array of integers.

#include<stdio.h>

int largest_num (int ar[],int ar_length){
    int max=ar[0];
    for (int  i = 1; i < ar_length; i++){
        if (max < ar[i]){
            max = ar[i];
        }
    }
    return max;
}
    

void main(){
    int ar[5] ={1,2,13,4,5};
    int ar_length = sizeof(ar)/sizeof(ar[0]);
    int max = largest_num(ar,ar_length);
    printf("MAX : %d\n",max);
}