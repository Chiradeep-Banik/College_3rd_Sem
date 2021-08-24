#include<stdio.h>


char* convert(char num[], int base,int target){
    int ar[1000];
    if(base == target) return num;
    printf("Part_1\n");
    int i = 0;
    while (num[i] != '\0'){
        if(num[i] >= '0' && num[i] <= '9') ar[i] = num[i] - '0';
        else if(num[i] >='A' && num[i] <= 'Z') ar[i] = num[i] - 'A' + 10;
        else if(num[i] >='a' && num[i] <= 'z') ar[i] = num[i] - 'a' + 10;
        i++;
    }
    int length = i,number=0;
    char result[length];
    for(int j = 0 ; j <length;j++){
        printf("%d ",ar[j]);
        number = 10*number + ar[j];
        if(ar[j] >= base) return "Invalid Input";
    }
    printf("-- Number: %d\n",number);

    if(base > target){
        printf("Part_2\n");
        for(int k =0;k<length;k++){
            printf("%d ",result[k]);            
        }
    }

    // for(int j = 0; j < length; j++){
    //     printf("%c",result[j]);
    // }

    return &result[0];
}

void main(){
    int base,target;
    char num[100];
    printf("Enter the base(2,8,10,16): ");
    scanf("%d",&base);
    if(base != 2 && base != 8 && base != 10 && base != 16) printf("Error, enter valid bases\n");
    else{
        printf("Enter the target base(2,8,10,16): ");
        scanf("%d",&target);
        if(target != 2 && target != 8 && target != 10 && target != 16) printf("Error, enter valid bases\n");
        else{
            printf("Enter the number: ");
            scanf("%s",num);
            char* result;
            result = convert(num,base,target,result);
            printf("Base: %d Traget: %d Number: %s Result: %s\n",base,target,num);
        }
    }
}