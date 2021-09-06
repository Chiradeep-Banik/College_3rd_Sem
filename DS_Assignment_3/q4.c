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
};

void take_input(struct student *s){
    printf("Enter the enrollment number: ");
    scanf("%d", &s->enrollmentNo);
    printf("Enter the registration number: ");
    scanf("%d", &s->regNo);
    printf("Enter the name: ");
    scanf("%s", s->studName);
    printf("Enter the semester: ");
    scanf("%d", &s->studSem);
    printf("Enter the CGPA: ");
    scanf("%f", &s->studCGPA);
}
void display(struct student *s){
    printf("\nEnrollment number: %d\n", s->enrollmentNo);
    printf("Registration number: %d\n", s->regNo);
    printf("Name: %s\n", s->studName);
    printf("Semester: %d\n", s->studSem);
    printf("CGPA: %.2f\n", s->studCGPA);
}

void main(){
    struct student s1, s2, s3;
    take_input(&s1);
    take_input(&s2);
    take_input(&s3);
    display(&s1);
    display(&s2);
    display(&s3);
}