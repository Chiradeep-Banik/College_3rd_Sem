#include <stdio.h>
#include <stdlib.h>

void to_decimal(char* str){
    printf("Addres : %p\n" , str);

}

void from_decimal(char *str,int target){
    printf("Addres : %p\n" , str);
    int number = atoi(str);
    printf("NUm in 'from' : %d\n",number);
    
    int i =0;
    while(1){
        int rem = number%target;
        number = (int)number/(int)target;
        printf("REM : %d  ",rem);
        printf("NUM : %d\n",number);
        // number = number/target;
        // printf("str in 'from': %s %d\n",str,i);
        // i++;
        if(number < target){
            printf("REM : %d  ",rem);
            printf("NUM : %d\n",number);
            break;
        }
    }
    *(str+i) = number;
    printf("str in 'from': %s\n",str);
}

char* convert(int base, int target,char* str){
    printf("Addres : %p\n" , str);
    from_decimal(str,target);
    return str;
}

int main(){
    int base,target;
    char* num = malloc(sizeof(char)*100);
    printf("Enter a base(2,8,10,16) : ");
    scanf("%d",&base);
    printf("Enter a target (2,8,10,16) : ");
    scanf("%d",&target);
    if(base != 2 && base != 8 && base != 10 && base != 16){
        printf("Invalid base\n");
    }else{
        if(target != 2 && target != 8 && target != 10 && target != 16){
            printf("Invalid target\n");
        }else{
            printf("Enter a number : ");
            char ch;
            int i =0;
            while((ch = getchar()) != '\n'){
                num[i] = ch;
                i++;
            }
        }
        char* result = (char*)num;
        printf("Addres : %p\n" , result);
        printf("BASE : %d TARGET : %d NUMBER : %s RESULT : %s \n",base,target,num,convert(10,12,result));
    }

    return 0;
}