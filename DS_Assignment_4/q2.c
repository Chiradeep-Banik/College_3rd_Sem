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
    printf("After malloc -- %d\n", *ptr); 

    int* ptr2 = (int *)calloc(1, sizeof(int)); // Set the value of the pointer to 0
    printf("After calloc -- %d\n", *ptr2);
    
    free(ptr); // Free the memory allocated to the pointer
    free(ptr2); // Free the memory allocated to the pointer
}