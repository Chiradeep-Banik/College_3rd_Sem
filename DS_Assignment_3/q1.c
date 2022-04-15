//Q1 Write a program of your choice to properly demonstrate the usage and differences of Local and GLobal variables.

#include<stdio.h>

int global_var=10;

void print(int local_var){

    printf("Global variable = %d\n",global_var);
    printf("Local variable = %d\n",local_var); 
    // Can only be excessed if we pas the value as argument but global_var is not passed as argument
}

void main(){

    int local_var=20;
    
    print(local_var);
}