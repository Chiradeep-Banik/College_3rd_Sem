//Q2 Demonstrate the usage & implementation of a struct. Accept an integer and display it.

#include <stdio.h>

struct student{
    int roll;
};

void main(){
    struct student s;
    printf("Enter the roll number: ");
    scanf("%d", &s.roll);
    printf("Roll number: %d\n", s.roll);
}