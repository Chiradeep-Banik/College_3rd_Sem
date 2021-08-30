//Q4. Design a 2D matrix of size 4x4 and display the elements using a pointer to array.

#include <stdio.h>

void make_matrix(int* ptr){
    for(int i = 0 ; i < 4 ; i++){
        printf("Enter the values of %dth row : ",i+1);
        for(int j = 0 ; j < 4 ; j++){
            scanf("%d",(ptr+i*4+j));
        }
    }
}

void display_matrix(int* ptr){
    printf("The elements of the matrix are :");
    for(int i = 0 ; i < 16 ; i++){
        if(i%4 == 0){
            printf("\n");
        }
        printf("%d ",*(ptr+i));
    }
    printf("\n");

}

void main(){
    int ar[4][4];
    int* ptr = &ar[0][0];
    make_matrix(ptr);
    display_matrix(ptr);
}