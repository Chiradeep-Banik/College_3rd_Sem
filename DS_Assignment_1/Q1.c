//Q1.Find the number of occurrences of a given integer NUM from a pre-defined array.

#include <stdio.h>

int num_of_occerence(int ar[],int ar_length,int NUM){
    int count = 0;
    for(int i = 0; i < ar_length; i++){
        if(ar[i] == NUM){
            count++;
        }
    }
    return count;
}

void main(){
    int ar[6] ={1,1,3,13,4,12};
    int NUM;
    printf("Enter the number to search for: ");
    scanf("%d",&NUM);
    int ar_length = sizeof(ar)/sizeof(ar[0]);
    int count = num_of_occerence(ar,ar_length,NUM);
    printf("The number of occurrences of %d is %d\n",NUM,count);
}