/**
 * Implement DMA to accept N integer data and find the sum of the composite integers only. Also display the memory allocations along with the data.
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    int N;
    printf("Enter the value for N : ");
    scanf("%d", &N);
    int *arr = (int *)calloc(N ,sizeof(int));
    for(int i = 0 ; i < N ; i++){
        printf("Enter the value at arr[%d] : ", i);
        scanf("%d", (arr+i));
    }
    int sum = 0;
    for(int i = 0 ; i < N ; i++){
        printf("Memory location of arr[%d] -- %x\n", i, (arr+i));
        int c = 0;
        for (int j = 1; j <= *(arr+i); j++){
            if(*(arr+i)%j == 0){
                c++;
            }
        }
        if(c >2){
            sum += *(arr+i);
        }
    }
    printf("Sum of the composite integers in the array is %d\n", sum);
}