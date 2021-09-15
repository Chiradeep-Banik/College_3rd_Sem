#include <stdio.h>

struct student{
    int regNo;
    char name[20];
    float cgpa;
    struct student *next;
};

struct student_list{
    struct student s1,s2,s3,s4,s5;
};

void take_input(struct student_list *sl){
    struct student *temp = &sl->s1;
    while(temp!=NULL){
        printf("Enter the registration number: ");
        scanf("%d",&temp->regNo);
        printf("Enter the name: ");
        scanf("%s", &(temp->name));
        printf("Enter the CGPAs: ");
        scanf("%f", &(temp->cgpa));
        temp = temp->next;
    }
}
void display_each(struct student *s){
    printf("\nRegistration number: %d\n", s->regNo);
    printf("Name: %s\n", s->name);
    printf("CGPA: %.2f\n", s->cgpa);
}
void display_all(struct student_list *sl){
    struct student* start = &(sl->s1);
    while(start != NULL){
        display_each(start);
        start = start->next;
    }
}
void main(){
    struct student_list sl;
    sl.s1.next = &(sl.s2);
    sl.s2.next = &(sl.s3);
    sl.s3.next = &(sl.s4);
    sl.s4.next = &(sl.s5);
    sl.s5.next = NULL;
    take_input(&sl);
    display_all(&sl);
}