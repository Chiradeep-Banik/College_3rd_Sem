// Queue implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue {
    int rear;
    int front;
    unsigned int capacity;
    int* array;
};

typedef struct queue Queue;

Queue* createStack(unsigned int capacity){
    Queue* que = (Queue*)malloc(sizeof(Queue));
    que->capacity = capacity;
    que->rear = -1;
    que->front = -1;
    que->array = (int*)malloc(capacity * sizeof(int));
    return que;
}

int isFull(Queue* que){
    return que->rear == que->capacity - 1;
}
 
int isEmpty(Queue* que){
    return que->rear == -1;
}
 
void enQueue(Queue* que, int item){
    if(isFull(que)){
        printf("Stack is full\n");
        return;
    }else{
        if(que->front == -1){
            que->front = 0;
        }
        que->rear++;
        que->array[que->rear] = item;
        printf("%d enqueued to queue\n", item);
    }
}
int deQueue(Queue* que){
    if (que->rear == -1){
        printf("Queue is Empty!!\n");
    }else{
        printf("Deleted : %d\n", que->array[que->front]);
        que->front++;
        if (que->front > que->rear){
            que->front = que->rear = -1;
        }
    }
}

void main(){
    Queue *que = createStack(5);
    enQueue(que, 1);
    enQueue(que, 2);
    enQueue(que, 3);
    deQueue(que);   
    deQueue(que);
    deQueue(que);
    deQueue(que);
}
