//Implement DMA and create a memory location of size N. Accept the data by passing the base address of the allocation to a function and display them along with the memory locations inside the function.

#include<stdio.h>
#include<stdlib.h>

void take_and_show(int *ptr,int n){
    for (int i = 0; i < n; i++){
        printf("Enter the value at %d location: ",i);
        scanf("%d",(ptr+i));
    }
    for (int j = 0; j < n; j++){
        printf("Index - %d Memory Address -- %p Value -- %d\n",j,(ptr+j),*(ptr+j));
    }
}

void main(){
    int N;
    printf("Enter the size of the memory to be allocated: ");
    scanf("%d",&N);
    int *ptr = (int *)malloc(N*sizeof(int)); 
    take_and_show(ptr,N);
}