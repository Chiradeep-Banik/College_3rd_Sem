//Q3. Accept an array of integer ARR[ ] from the user to implement a call by reference and find the sum of the odd numbers and even numbers separately.

#include <stdio.h>

int odd_sum(int* ar , int ar_length){
    int odd_sum = 0;
    for(int i = 0 ; i<ar_length;i++){
        if(*(ar+i)%2!=0){
            odd_sum+=*(ar+i);
        }
    }
    return odd_sum;
}
int even_sum(int* ar , int ar_length){
    int even_sum = 0;
    for(int i = 0 ; i<ar_length;i++){
        if(*(ar+i)%2 == 0){
            even_sum+=*(ar+i);
        }
    }
    return even_sum;
}

void main(){
    int arr_length;
    printf("Enter the length of the array : ");
    scanf("%d", &arr_length);
    int arr[arr_length];
    printf("Enter the elements of the array : ");
    for(int i = 0; i < arr_length; i++){
        scanf("%d", &arr[i]);
    }
    printf("The sum of the odd numbers is %d\n", odd_sum(arr, arr_length));
    printf("The sum of the even numbers is %d\n", even_sum(arr, arr_length));
}