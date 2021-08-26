//Q1. Accept an integer NUM from the user and display its address and value using the pointer methodologies

#include <stdio.h>

void main(){
    int num;
    printf("Enter an integer : ");
    scanf("%d", &num);
    int* ptr = &num;
    printf("Address : %p  Value : %d\n", ptr, num);
}