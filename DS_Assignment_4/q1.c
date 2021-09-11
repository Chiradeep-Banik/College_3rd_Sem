/**
 * Create a structure for a company who manufactures mobile phones. Create a repository of information which consists of the following data:
            prod_name
            prod_code
            prod_price
            prod_screensize
            prod_color
Now, accept data for 5 different products and display them in a well formatted manner. Use structure and arrays.
*/

#include <stdio.h>

struct company_repo{
    char prod_name[20];
    int prod_code;
    float prod_price;
    int prod_screensize;
    char prod_color[20];
};
void take_input (struct company_repo *repo){
    for(int i = 0 ; i< 5 ; i++){
        printf("\nEnter the product name : ");
        scanf("%s",&(repo+i)->prod_name);
        printf("Enter the product code : ");
        scanf("%d",&(repo+i)->prod_code);
        printf("Enter the product price : ");
        scanf("%f",&(repo+i)->prod_price);
        printf("Enter the product screensize : ");
        scanf("%d",&(repo+i)->prod_screensize);
        printf("Enter the product color : ");
        scanf("%s",&(repo+i)->prod_color);
    }
}
void display_output (struct company_repo *repo){
    for(int i = 0 ; i< 5 ; i++){
        printf("\nProduct name : %s",(repo+i)->prod_name);
        printf("\nProduct code : %d",(repo+i)->prod_code);
        printf("\nProduct price : %f",(repo+i)->prod_price);
        printf("\nProduct screensize : %d",(repo+i)->prod_screensize);
        printf("\nProduct color : %s\n",(repo+i)->prod_color);
    }
}

void main(){
    struct company_repo c_repo[5];
    take_input(c_repo);
    display_output(c_repo);
}