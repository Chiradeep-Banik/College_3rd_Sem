/**
 * Implement struct to accept the data of 3 students (without using array of structure /  pointer to structure) and display them in a proper formatted manner
        enrollmentNo
        regNo
        studName
        studSem
        studCGPA

*/
#include <stdio.h>

struct student{
    int enrollmentNo;
    int regNo;
    char studName[20];
    int studSem;
    float studCGPA;
    struct student *next;
};

struct student_list{
    struct student s1;
    struct student s2;
    struct student s3;
};

void take_input(struct student_list *sl){
    printf("Enter the enrollment numbers: ");
    scanf("%d%d%d", &(sl->s1.enrollmentNo), &(sl->s2.enrollmentNo), &(sl->s3.enrollmentNo));
    printf("Enter the registration number: ");
    scanf("%d%d%d", &(sl->s1.regNo), &(sl->s2.regNo), &(sl->s3.regNo));
    printf("Enter the name: ");
    scanf("%s%s%s", &(sl->s1.studName), &(sl->s2.studName), &(sl->s3.studName));
    printf("Enter the semester: ");
    scanf("%d%d%d", &(sl->s1.studSem), &(sl->s2.studSem), &(sl->s3.studSem));
    printf("Enter the CGPA: ");
    scanf("%f%f%f", &(sl->s1.studCGPA), &(sl->s2.studCGPA), &(sl->s3.studCGPA));
    sl->s1.next = &(sl->s2);
    sl->s2.next = &(sl->s3);
    sl->s3.next = NULL;
}
void display_each(struct student *s){
    printf("\nEnrollment number: %d\n", s->enrollmentNo);
    printf("Registration number: %d\n", s->regNo);
    printf("Name: %s\n", s->studName);
    printf("Semester: %d\n", s->studSem);
    printf("CGPA: %.2f\n", s->studCGPA);
}
void display_all(struct student_list *sl){
    struct student* start = &(sl->s1);
    while(start->next != NULL){
        display_each(start);
        start = start->next;
    }
}
void main(){
    struct student_list sl;
    take_input(&sl);
    display_all(&sl);
}