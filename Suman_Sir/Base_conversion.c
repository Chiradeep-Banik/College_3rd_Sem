#include <stdio.h>
#include <stdlib.h>


//function for calculating the power 
int mypow(int base, int power){
    int result = 1;
    if (power >= 0){

        while (power--){
            result = result * base;
        }

        return result;
    }
    else if (power < 0){
        while (power++){
            result = result * base;
        }
        return 1 / result;
    }
}

//function for reversing a given string
void rev(char *s,int n){
    int i,j;
    char temp;
    for(i=0,j=n-1;i<j;i++,j--){
        temp=*(s+i);
        *(s+i)=*(s+j);
        *(s+j)=temp;
    }
}

//function for converting anything to 10 base number(string)
void to_decimal(char* str,int base){
    int i = 0,ar[1000];
    while(*(str+i) != '\0'){
        if (*(str+i) >= '0' && *(str+i) <= '9'){
            ar[i] = *(str+i) - '0';
        }else if (*(str+i) >= 'A' && *(str+i) <= 'Z')
            ar[i] = *(str+i) - 'A' + 10;
        else if (*(str+i) >= 'a' && *(str+i) <= 'z')
            ar[i] = *(str+i) - 'a' + 10;
        i++;
    }
    int sum =0;
    for(int j = 0 ; j < i ; j++){
        sum += mypow(base,i-j-1) * ar[j];
    }
    int k =0; 
    while(sum>0){
        *(str+k) = sum % 10 + '0';
        sum = sum / 10;
        k++;
    }
    *(str+k) = '\0';
    rev(str,k);
}

//function for converting to anything from 10 base number(string)
void from_decimal(char *str,int target){
    int number = atoi(str);    
    int i =0;
    while(1){
        int rem = number%target;
        if(rem < 10){
            *(str + i) = rem + '0';
        }else{
            *(str + i) = rem - 10 + 'A';
        }
        number = (int)number/(int)target;
        i++;
        if(number < target){
            if(number < 10){
                *(str + i) = number + '0';
            }else{
                *(str + i) = number - 10 + 'A';
            }
            *(str+i+1) = '\0';
            break;
        }
    }
    rev(str,i+1);
}

char* convert(int base, int target,char* str){
    while(1){
        static int p = 0;
        if(base < 10){
            if((*(str+p) -'0')>(base-1)){
                return "Enter a valid number";
            }
        }else{
            if((*(str+p) -'A'+10)>(base-1)){
                return "Enter a valid number";
            }
        }
        if(*(str+p) == '\0'){
            break;
        }
        p++;
    }
    if(base == target){
        return str;
    }
    if(base == 10){
        from_decimal(str,target);
    }else{
        if(target == 10){
            to_decimal(str,base);
        }else{
            to_decimal(str,base);
            from_decimal(str,target);
        }
    }
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
            scanf("%s",num);
            char* result = (char*)num;
            printf("\nBASE : %d , TARGET : %d , RESULT : %s \n",base,target,convert(base,target,result));
        }
    }

    return 0;
}