/**
 * Implement Dynamic Memory Allocation(DMA) to demonstrate the usage and functionalities of the following:
            malloc()
            calloc()
            free()
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    int *ptr = (int *)malloc(sizeof(int)); // Do not set any default values inside the pointer
    printf("%d\n", *ptr); 

    ptr = (int *)calloc(1, sizeof(int)); // Set the value of the pointer to 0
    printf("%d\n", *ptr);
    
    free(ptr); // Free the memory allocated to the pointer
}