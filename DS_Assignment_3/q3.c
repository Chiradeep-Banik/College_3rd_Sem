/**
 * Apply struct to accept the data of an employee mentioned below and also display them in a proper formatted manner:
        empId
        empName
        basic   
        da : 25% of basic
        hra : 15% of basic
        ta : 10% of basic
        gross : basic + da + hra + ta

*/
#include <stdio.h>

struct employee
{
    int empId;
    char empName[20];
    float basic;
    float da;
    float hra;
    float ta;
    float gross;
};
void emp_calc(struct employee *e)
{
    e->da = e->basic * 0.25;
    e->hra = e->basic * 0.15;
    e->ta = e->basic * 0.10;
    e->gross = e->basic + e->da + e->hra + e->ta;
}
void take_input(struct employee *e)
{
    printf("Taking the employee details\n");
    printf("Enter the empId : ");
    scanf("%d", &(e->empId));
    printf("Enter the empName : ");
    scanf("%s", &(e->empName));
    printf("Enter the basic : ");
    scanf("%f", &(e->basic));
}

void display(struct employee *e)
{
    printf("\nEmployee Id: %d", e->empId);
    printf("\nEmployee Name: %s", e->empName);
    printf("\nBasic: %.2f", e->basic);
    printf("\nDA: %.2f", e->da);
    printf("\nHRA: %.2f", e->hra);
    printf("\nTA: %.2f", e->ta);
    printf("\nGross: %.2f\n", e->gross);
}

void main()
{
    struct employee e1;
    take_input(&e1);
    emp_calc(&e1);
    display(&e1);
}