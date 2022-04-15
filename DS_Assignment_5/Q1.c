//Q1. Demonstrate the implementation of a Singly linked list. Create 4 nodes and display all the data using the first node only.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct linked_list{
    struct node *head;
    struct node *tail;
    int length;
};

void push(struct linked_list *list,int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(list->length == 0){
        list->head = new_node;
        list->tail = new_node;
    }else{
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->length++;
    printf("Success !!\n");
}

void print_list(struct node *first){
    struct node *current = first;
    for(;current != NULL; current = current->next){
        printf("%d->", current->data);
    }
    printf("NULL\n");
}

void main(){
    struct linked_list list;
    list.head = NULL;
    list.tail = NULL;
    list.length = 0;
    push(&list,1);
    push(&list,2);
    push(&list,3);
    push(&list,4);
    print_list(list.head);
}