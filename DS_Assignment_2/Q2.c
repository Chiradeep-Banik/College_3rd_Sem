//Q2. Implement a pointer to an array to display all the array elements alongside the addresses 

#include <stdio.h>

void main(){
    int num;
    printf("Enter the length of the array : ");
    scanf("%d", &num);
    int arr[num];
    //Takes the input 
    for(int i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }
    //implements array pointers
    int* ptr = arr;
    //displays the value and addresess using pointers
    for(int i = 0; i < num; i++){
        printf("Address : %p  Value : %d\n", ptr+i, *(ptr+i));
    }
}