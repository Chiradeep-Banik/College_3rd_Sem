// Queue implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue {
    int* array;
    int left;
    int right;
    unsigned int capacity;
};

typedef struct queue Queue;

Queue* create_queue(unsigned int capacity){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->array = (int*) malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    q->left = 0;
    q->right = 0;
    return q;
}

void enqueue(Queue* q, int data){
    if(q->right >= q->capacity){
        printf("Queue is full\n");
        return;
    }
    q->array[q->right] = data;
    q->right++;
    printf("%d enqueued to queue\n", data);
}

int dequeue(Queue* q){
    if(q->left >= q->right){
        printf("Queue is empty\n");
        return INT_MIN;
    }
    int temp = q->array[q->left];
    for(int i =0;i<q->right-1;i++){
        q->array[i] = q->array[i+1];
    }
    q->right--;
    printf("%d dequeued from queue\n", temp);
    return temp;
}
void main(){
    Queue* q = create_queue(2);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    dequeue(q);
    dequeue(q);
    dequeue(q);
}
