#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-----------------------------------------------------Made the stack
struct Stack{
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack){
    return stack->top == -1 ;
}
char peek(struct Stack* stack){
    return stack->array[stack->top];
}
char pop(struct Stack* stack){
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '~';
}
void push(struct Stack* stack, char op){
    stack->array[++stack->top] = op;
}
//-----------------------------------------------------Made the stack

//-----------------------------------------------------Other Functions
int is_operand(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    else
        return 0;
}
int precedence(char c) { 
    if(c == '^') 
        return 3; 
    else if(c == '*' || c == '/') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1; 
    else
        return -1; 
} 
char* rev(char* str){
    int left = 0,right = strlen(str)-1;
    while(left<right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    return str;
}
//-----------------------------------------------------Other Functions

char* infix_to_postfix(char* infix){
    char* postfix = (char*)malloc(sizeof(char)*strlen(infix));
    int i, k;
    struct Stack* stack = createStack(strlen(infix));
    if(!stack)
        return "error";
    for(i = 0, k = -1; infix[i]; ++i){
        if (is_operand(infix[i]))
            postfix[++k] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')'){
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return "error";        
            else
                pop(stack);
        }else{
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack, infix[i]);
        }
 
    }
    while (!isEmpty(stack)){
        postfix[++k] = pop(stack);
    } 
    postfix[++k] = '\0';
    return postfix;
}
char* infix_to_prefix(char* infix){
    rev(infix);
    for (int i = 0; i < strlen(infix); i++){
        if (infix[i] == '('){
            infix[i] = ')';
        }else if (infix[i] == ')'){
            infix[i] = '(';
        }
    }
    char* prefix = infix_to_postfix(infix);
    rev(prefix);
    return prefix;
}

int main(){
    char infix[100];
    printf("Enter the infix expression : ");
    scanf("%s", infix);
    char* postfix = infix_to_postfix(infix);
    char* prefix = infix_to_prefix(infix);
    printf("The Postfix expression : %s\n", postfix);
    printf("The Prefix expression : %s\n", prefix);
    return 0;
}