// Implementation of stack data-structure

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int top;
    unsigned int capacity;
    int* array;
};

typedef struct stack Stack;

Stack* createStack(unsigned int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack){
    return stack->top == stack->capacity - 1;
}
 
int isEmpty(Stack* stack){
    return stack->top == -1;
}
 
void push(Stack* stack, int item){
    if (isFull(stack))
        return;
    stack->top++;
    stack->array[stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(Stack* stack){
    if (isEmpty(stack)){
        printf("Stack is empty\n");
        return INT_MIN;
    }
    stack->top--;
    return stack->array[stack->top];
}

void main(){
    Stack *st = createStack(10);
    push(st, 10);
    push(st, 20);
    push(st, 30);
    printf("%d popped from stack\n", pop(st));
}