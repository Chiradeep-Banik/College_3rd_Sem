#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#define log(x) printf("%d\n",x)

int is_negative = 0,is_positive=0;

int range_checker(){
    char ch;
    int num_ar[10],i=0;
    while((ch = getchar_unlocked()) != '\n'){
        if(i >=10){
            return 0;
        }
        if(i==0){
            if(ch == '-' && is_negative == 0){
                is_negative = 1;
                continue;
            }
            if(ch == '+' && is_positive == 0){
                is_positive = 1;
                continue;
            }

            if(ch == '0'){
                continue;
            }
        }

        if(isdigit(ch)){
            num_ar[i] = ch - '0';
        }else{
            return -1;
        }
        i++;
    }
    int length = i;
    if(length <10){
        return 1;
    }
    //range-------
    int range_digits[10],num = INT_MAX;
    for(int q = 9; q >= 0; q--){
        range_digits[q] = num % 10;
        num /= 10;
    }
    //--------------
    if(length == 10){
        printf("Length == 10 :%d\n",length);
        while(1){
            static int start = 0;
            if(num_ar[start] == range_digits[start]){
                start++;
            }else{
                if(num_ar[start] > range_digits[start]){
                    return 0;
                }else{
                    return 1;
                }
            }
        }
        return 1;
    }
}

void main(){
    printf("MAX : %d MIN :%d\n", INT_MAX, INT_MIN);
    int result = range_checker();
    if(result == 1){
        printf("With in bounds\n");
    }else{
        if(result == 0) printf("Out of bounds\n");
        else printf("Enter only digits\n");
    }
}