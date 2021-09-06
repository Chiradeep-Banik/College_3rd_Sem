//Q1 Write a program of your choice to properly demonstrate the usage and differences of Local and GLobal variables.

#include<stdio.h>

int global_variable = 10;

void main(){
    int local_variable = 20;
    printf("Global variable: %d\n", global_variable);
    printf("Local variable: %d\n", local_variable);
}