// Implementation of stack data-structure

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int* array;
    unsigned int capacity;
    int top;
};

typedef struct stack Stack;

Stack* create_stack (unsigned int capacity) {
    Stack* s = (Stack*) malloc (sizeof(Stack));
    s->array = (int*) malloc(capacity * sizeof(int));
    s->capacity = capacity;
    s->top = 0;
    return s;
}

void push(Stack* s, int data){
    if(s->top == s->capacity){
        printf("Stack Overflow\n");
        return;
    }
    s->array[s->top] = data;
    s->top++;
    printf("%d pushed to stack\n",data);
}

int pop(Stack* s){
    if(s->top == 0){
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    s->top--;
    int temp = s->array[s->top];
    printf("%d popped from stack\n",temp);
    return temp;
}

void main(){ 
    Stack* s = create_stack(2);
    push(s,10);
    push(s,20);
    push(s,30);
    pop(s);
    pop(s);
    pop(s);
}