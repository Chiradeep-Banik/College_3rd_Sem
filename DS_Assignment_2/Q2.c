//Q2. Implement a pointer to an array to display all the array elements alongside the addresses 

#include <stdio.h>

void print_arr(int len){
    int arr[len];
    //Takes the input 
    printf("Enter the array elements : ");
    for(int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    //implements array pointers
    int* ptr = arr;
    //displays the value and addresess using pointers
    for(int i = 0; i < len; i++){
        printf("Address : %p  Value : %d\n", ptr+i, *(ptr+i));
    }
}

void main(){
    int num;
    printf("Enter the length of the array : ");
    scanf("%d", &num);
    print_arr(num);
}