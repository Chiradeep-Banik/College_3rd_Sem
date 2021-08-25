#include <stdio.h>

//tomorrow -- make 2 function to convert all to decimal than chane it to required num

void rev(char *s,int n){
    int i,j;
    char temp;
    for(i=0,j=n-1;i<j;i++,j--){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}

char *convert(char num[], int base, int target, char *result)
{
    int ar[1000];
    if (base == target)
        return num;
    int i = 0;
    while (num[i] != '\0')
    {
        if (num[i] >= '0' && num[i] <= '9')
            ar[i] = num[i] - '0';
        else if (num[i] >= 'A' && num[i] <= 'Z')
            ar[i] = num[i] - 'A' + 10;
        else if (num[i] >= 'a' && num[i] <= 'z')
            ar[i] = num[i] - 'a' + 10;
        i++;
    }
    int length = i, number = 0;
    for (int j = 0; j < length; j++){
        number = 10 * number + ar[j];
        if (ar[j] >= base)
            return "Invalid Input";
    }
    char temp[length*4];
    if (base > target){
        for(int i= 0 ; i < length*4 ; i++){
            temp[i] = (number % target) + '0';
            number = number / target;
        }
        rev(temp, length*4);
        result = temp;
    }

    return result;
}

void main()
{
    int base, target;
    char num[100];
    printf("Enter the base(2,8,10,16): ");
    scanf("%d", &base);
    if (base != 2 && base != 8 && base != 10 && base != 16)
        printf("Error, enter valid bases\n");
    else
    {
        printf("Enter the target base(2,8,10,16): ");
        scanf("%d", &target);
        if (target != 2 && target != 8 && target != 10 && target != 16)
            printf("Error, enter valid bases\n");
        else
        {
            printf("Enter the number: ");
            scanf("%s", num);
            char *result;
            char *res = convert(num, base, target, result);
            printf("Base: %d Traget: %d Number: %s Result: %s\n", base, target, num , res);
        }
    }
}