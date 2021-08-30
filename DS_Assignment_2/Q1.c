//Q1. Accept an integer NUM from the user and display its address and value using the pointer methodologies

#include <stdio.h>

void print_addr(int* ptr){
    printf("Enter an integer : ");
    scanf("%d", ptr);
    printf("Address : %p  Value : %d\n", ptr, *ptr);
}

void main(){
    int num;
    int* ptr = &num;
    print_addr(ptr);
}